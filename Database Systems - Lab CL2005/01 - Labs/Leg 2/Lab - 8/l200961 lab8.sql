go 
CREATE TRIGGER printdelete ON logs
INSTEAD OF DELETE
AS BEGIN
PRINT 'print instead of delete'
END

use master
GO
DROP database if exists lab8
go
create DATABASE lab8
go
use lab8 -- last lab schema is used
GO

-- Task 1:
-- In this task, you will create a trigger that prevents a user from inserting a new row into a table if the value of a certain column is not within a specified range. Follow these steps:
-- 1. Create a new table called products with columns id, name, price, and quantity. 
CREATE TABLE products (
    id int,
    name varchar(50),
    price int,
    quantity int
)
GO
-- 2. Write a trigger that executes before an INSERT statement is executed on the products table. 
drop trigger if exists check_price
go
CREATE TRIGGER check_price ON products
INSTEAD OF INSERT
AS BEGIN
-- 3. In the trigger, check the value of the price column to make sure it is between 0 and 1000. If it is not, raise an error. 
    IF (SELECT price FROM inserted) < 0 OR (SELECT price FROM inserted) > 1000
        BEGIN
        RAISERROR('Price must be between 0 and 1000', 16, 1)-- errorlevel 16 is a user-defined error, 1 is the state
        END
    ELSE
        BEGIN
        INSERT INTO products SELECT * FROM inserted
        END
END
-- 4. Test the trigger by attempting to insert a row with a price outside the specified range. Confirm that the trigger prevents the insertion and raises an error. 
INSERT INTO products VALUES (1, 'test', 1001, 1)
go
INSERT INTO products VALUES (1, 'test', 500, 1)
SELECT * FROM products
go
-- Task 2:
-- In this task, you will create a trigger that maintains referential integrity between two tables. Follow these steps:
-- 1) Create two tables called orders and customers. 
CREATE TABLE customers (
    id int PRIMARY KEY,
    name varchar(50)
)
GO
Create TABLE orders(
    id int not null,
    order_no int,
    total int,
)
GO
-- 2) Add a foreign key constraint to the orders table that references the id column of the customers table. 
ALTER TABLE orders Add CONSTRAINT fk_customer FOREIGN KEY (id) REFERENCES customers(id)
-- 3) Write a trigger that executes before a row is deleted from the customers table. 
go
drop trigger if exists check_customer
go
CREATE TRIGGER check_customer ON customers
INSTEAD OF DELETE
AS BEGIN
-- 4) In the trigger, check if there are any orders associated with the customer being deleted. If there are, raise an error and prevent the deletion of the row. 
    IF EXISTS (SELECT * FROM orders WHERE id = (SELECT id FROM deleted))
        BEGIN
        RAISERROR('Cannot delete customer with orders', 16, 1) -- errorlevel 16 is a user-defined error, 1 is the state
        END
    ELSE
        BEGIN
        DELETE FROM customers WHERE id = (SELECT id FROM deleted)
        END
END
-- 5) Test the trigger by attempting to delete a customer who has orders associated with them. Confirm that the trigger prevents the deletion and raises an error. 
GO
INSERT INTO customers VALUES (1, 'test')
insert into customers values(2, 'test2')
INSERT INTO orders VALUES (1, 1, 100)
DELETE from Customers WHERE id=2

-- Task 3:
-- In this task, you will create a trigger that logs changes made to a table. Follow these steps:
-- 1. Create a new table called log with columns id, table_name, column_name, old_value, new_value, and timestamp.
CREATE TABLE log (
    id INT IDENTITY(1,1),
    table_name NVARCHAR(128),
    column_name NVARCHAR(128),
    old_value NVARCHAR(128),
    new_value NVARCHAR(128),
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);
-- 2. Write a trigger that executes after an UPDATE statement is executed on any table in the database. 
-- 3. In the trigger, insert a new row into the log table that records the name of the updated table, the name of the updated column, the old value, the new value, and the current timestamp. 
drop TRIGGER if exists log_changes
GO
CREATE TRIGGER log_changes
ON customers -- msssql supports triggers on single tables only
AFTER UPDATE
AS
BEGIN
    DECLARE @old_value NVARCHAR(128), @new_value NVARCHAR(128);
    SELECT @old_value = d.name, @new_value = i.name
    FROM deleted d, inserted i;

    INSERT INTO log (table_name, column_name, old_value, new_value) 
    VALUES ('customers', 'name', @old_value, @new_value);
END;


-- 4. Test the trigger by updating a row in a table and confirming that a new row is inserted into the log table. 
UPDATE customers SET name = 'test2' WHERE id = 1
SELECT * FROM customers
UPDATE customers SET name = 'test3' WHERE id = 1
SELECT * FROM log

-- Task 4:
-- In this task, you will create a trigger that enforces a business rule related to discounts. Follow these steps:
-- 1) Create a new table called orders with columns id, customer_id, total, and discount. 
DROP TABLE orders
CREATE TABLE orders (
    customer_id int,
    total int,
    discount int
)
-- 2) Write a trigger that executes before an INSERT or UPDATE statement is executed on the orders table. 
DROP TRIGGER if exists discount_check
GO
CREATE TRIGGER discount_check
ON orders
FOR INSERT, UPDATE
AS
BEGIN
    DECLARE @total DECIMAL(10, 2), @discount DECIMAL(10, 2);
    SELECT @total = total, @discount = discount FROM inserted;

    IF @discount > @total * 0.10
    BEGIN
        RAISERROR ('Discount cannot be more than 10%% of the total', 16, 1);
        ROLLBACK TRANSACTION -- do not accept changes
    END
END
-- 3) In the trigger, check if the value of the discount column is greater than 10% of the total column. If it is, raise an error. 
-- 4) Test the trigger by attempting to insert or update a row with a discount
-- This should succeed
INSERT INTO orders (customer_id, total, discount) VALUES (1, 100.00, 10.00);
-- This should fail and raise an error
INSERT INTO orders (customer_id, total, discount) VALUES (1, 100.00, 20.00);
SELECT * FROM orders