CREATE DATABASE DBLab
go
USE DBLab

-- ## QUESTION 1 ## --
-- Following Schema:
-- ● Table: Books
-- ○ Columns:
-- 1. BookID (Primary Key)
-- 2. Title (Title of the book)
-- 3. Author (Author of the book)
-- 4. PublicationYear (Year the book was published)
-- 5. ISBN (International Standard Book Number)
-- INSERT INTO Books (BookID, Title, Author, PublicationYear, ISBN)
-- VALUES
-- (1, 'To Kill a Mockingbird', 'Harper Lee', 1960, '9780061120084'),
-- (2, '1984', 'George Orwell', 1949, '9780451524935'),
-- (3, 'The Great Gatsby', 'F. Scott Fitzgerald', 1925, '9780743273565'),
-- (4, 'Pride and Prejudice', 'Jane Austen', 1813, '9780141439518'),

CREATE TABLE Books
(
    BookID int PRIMARY KEY,
    Title varchar(255),
    Author varchar(255),
    PublicationYear int,
    ISBN varchar(255)
)
go

INSERT INTO Books (BookID, Title, Author, PublicationYear, ISBN)
VALUES
(1, 'To Kill a Mockingbird', 'Harper Lee', 1960, '9780061120084'),
(2, '1984', 'George Orwell', 1949, '9780451524935'),
(3, 'The Great Gatsby', 'F. Scott Fitzgerald', 1925, '9780743273565'),
(4, 'Pride and Prejudice', 'Jane Austen', 1813, '9780141439518')

-- crud operations (create, read, update, delete)
-- ##create
-- Insert a new book into the Books table with the following details:
-- ○ Title: "The Catcher in the Rye"
-- ○ Author: "J.D. Salinger"
-- ○ Publication Year: 1951
-- ○ ISBN: 9780316769174
INSERT INTO Books VALUES (5, 'The Catcher in the Rye', 'J.D. Salinger', 1951, '9780316769174')

-- ##Read:
-- Retrieve the details (Title, Author, Publication Year, ISBN) of all books in the
-- database
SELECT Title, Author, PublicationYear, ISBN FROM Books

-- ##Update: 
-- Update the book with the ISBN "9780316769174" to change its title to "Catcher in
-- the Rye."
UPDATE Books SET Title = 'Catcher in the Rye' WHERE ISBN = '9780316769174'

-- ##Delete: 
-- Delete the book with the ISBN "9780316769174" from the database.
DELETE FROM Books WHERE ISBN = '9780316769174'

-- ## QUESTION 2 ## --
-- Table: Products
-- ○ Columns:
-- 1. ProductID (Primary Key)
-- 2. ProductName (Name of the product)
-- 3. Category (Category to which the product belongs)
-- 4. Price (Price of the product)
-- Below are some sample values in the Products table:
-- ProductID ProductName Category Price
-- 1 Laptop Electronics 800.00
-- 2 Desk Chair Furniture 120.00
-- 3 Smartphone Electronics 500.00
-- 4 Office Desk Furniture 250.00
-- 5 Wireless Mouse Electronics 20.00
-- 6 Bookshelf Furniture 150.00
-- 7 Headphones Electronics 100.00

CREATE TABLE Products
(
    ProductID int PRIMARY KEY,
    ProductName varchar(255),
    Category varchar(255),
    Price float
)
go

INSERT INTO Products VALUES (1, 'Laptop', 'Electronics', 800.00),
(2, 'Desk Chair', 'Furniture', 120.00),
(3, 'Smartphone', 'Electronics', 500.00),
(4, 'Office Desk', 'Furniture', 250.00),
(5, 'Wireless Mouse', 'Electronics', 20.00),
(6, 'Bookshelf', 'Furniture', 150.00),
(7, 'Headphones', 'Electronics', 100.00)

-- write SQL queries using the LIKE operator to retrieve specific information about
-- products based on the provided sample values

-- Query 1: Retrieve the names of all products that contain the word "Chair" anywhere in their
-- name.
SELECT ProductName FROM Products WHERE ProductName LIKE '%Chair%'
-- Query 2: Retrieve the names and prices of all products in the "Electronics" category.
SELECT ProductName, Price FROM Products WHERE Category = 'Electronics'
-- Query 3: Retrieve the names and prices of all products with a price less than $200.
SELECT ProductName, Price FROM Products WHERE Price < 200
-- Query 4: Retrieve the names and categories of products that contain the word "Desk" anywhere
-- in their name.
SELECT ProductName, Category FROM Products WHERE ProductName LIKE '%Desk%'

-- -- ## QUESTION 3 ## --
-- Table Name: orders
-- Columns: order_id (INT), customer_id (INT), order_date (DATE), total_amount
-- (DECIMAL)
-- Order_id Customer_id Order_date Total_amount
-- 1 101 2023-09-01 150.50
-- 2 102 2022-09-02 750.20
-- 3 103 2023-09-03 200.00
-- 4 104 2023-09-04 800.75
-- 5 105 2021-09-05 300.30

CREATE TABLE orders
(
    order_id int PRIMARY KEY,
    customer_id int,
    order_date date,
    total_amount decimal(10,2)
)
go

INSERT INTO orders VALUES (1, 101, '2023-09-01', 150.50),
(2, 102, '2022-09-02', 750.20),
(3, 103, '2023-09-03', 200.00),
(4, 104, '2023-09-04', 800.75),
(5, 105, '2021-09-05', 300.30)

-- 1. Calculate the total revenue generated from all orders in the orders table.
SELECT SUM(total_amount) FROM orders
-- 2. Find the average order amount in the orders table.
SELECT AVG(total_amount) FROM orders
-- 3. Update the total_amount column to increase all order amounts by 10%.
UPDATE orders SET total_amount = total_amount * 1.1
-- 4. Select orders where the total amount is greater than $500.
SELECT * FROM orders WHERE total_amount > 500
-- 5. Calculate the sum of total amounts for orders placed in 2023
SELECT SUM(total_amount) FROM orders WHERE order_date LIKE '2023%'

-- -- Table Name: employees
-- Columns: employee_id (INT), first_name (VARCHAR), last_name (VARCHAR),
-- department_id (INT)
-- Employee_id First_name Last_name Department_id
-- 1 John Smith 101
-- 2 Sarah Johnson 102
-- 3 Michael Williams 103
-- 4 Emily Davis 104
-- 5 David Lee 105
CREATE TABLE employees
(
    employee_id int PRIMARY KEY,
    first_name varchar(255),
    last_name varchar(255),
    department_id int
)
GO

INSERT INTO employees VALUES (1, 'John', 'Smith', 101),
(2, 'Sarah', 'Johnson', 102),
(3, 'Michael', 'Williams', 103),
(4, 'Emily', 'Davis', 104),
(5, 'David', 'Lee', 105)

-- Table Name: departments
-- columns: department_id (INT), department_name (VARCHAR)
-- Department_id Department_name
-- 101 Sales
-- 102 Marketing
-- 103 Finance
-- 104 Human Resources
-- 105 Research and Development

CREATE TABLE departments
(
    department_id int PRIMARY KEY,
    department_name varchar(255)
)
GO

INSERT INTO departments VALUES (101, 'Sales'),
(102, 'Marketing'),
(103, 'Finance'),
(104, 'Human Resources'),
(105, 'Research and Development')

-- Perform a union operation between the employees and departments tables to get a
-- combined list of employees and department names.
SELECT employee_id, first_name, last_name, NULL AS department_name
FROM employees
UNION ALL
SELECT NULL AS employee_id, NULL AS first_name, NULL AS last_name, department_name
FROM departments
ORDER BY employee_id

-- 2. List all departments and the number of employees in each department using a join and
-- grouping.

SELECT d.department_name, COUNT(e.employee_id) AS num_employees
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
GROUP BY d.department_name
ORDER BY num_employees DESC

-- 3. Find the departments that have no employees assigned to them.

SELECT d.department_name
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
WHERE e.employee_id IS NULL

-- Table Name: products
-- Columns: product_id (INT), product_name (VARCHAR), description (TEXT), price
-- (DECIMAL), manufacture_date (DATE)
-- Product_id Product_name Description Price Manufacture_dat
-- e
-- 1 Laptop High-
-- performance
-- laptop
-- 900 2023-05-15
-- 2 Smartphone Latest
-- smartphone
-- model
-- 699 2023-06-20
-- 3 Headphones Noise-canceling
-- headphones
-- 949 2023-07-10
-- 4 Tablet 10-inch
-- touchscreen
-- tablet
-- 299 2023-06-05
-- 5 Camera DSLR camera
-- with zoom lens
-- 799 2023-08-12
drop table products
CREATE TABLE products
(
    product_id int PRIMARY KEY,
    product_name varchar(255),
    description text,
    price decimal(10,2),
    manufacture_date date
)
GO

INSERT into Products VALUES (1, 'Laptop', 'High-performance laptop', 900, '2023-05-15'),
(2, 'Smartphone', 'Latest smartphone model', 699, '2023-06-20'),
(3, 'Headphones', 'Noise-canceling headphones', 949, '2023-07-10'),
(4, 'Tablet', '10-inch touchscreen tablet', 299, '2023-06-05'),
(5, 'Camera', 'DSLR camera with zoom lens', 799, '2023-08-12')

-- Retrieve the first 3 characters of each product name in the products table using the
-- SUBSTRING function.
SELECT SUBSTRING(product_name, 1, 3) FROM products
-- 2. Calculate the age of each product in days (from the manufacture_date column to the
-- current date) using the DATEDIFF function and GETDATE.
SELECT product_name, DATEDIFF(day, manufacture_date, GETDATE()) AS age_in_days
FROM products

-- 3. Display the product names and their descriptions where the descriptions contain the word
-- "premium" using the LIKE operator.
SELECT product_name, description FROM products WHERE description LIKE '%premium%'

-- 4. Create a new column called discounted_price in the products table, which is 10% less
-- than the original price, and then display the updated table.
ALTER TABLE products ADD discounted_price decimal(10,2)
UPDATE products SET discounted_price = price * 0.9
SELECT * FROM products

-- 5. Find the product with the earliest manufacture date using the MIN function and display
-- its details.
SELECT * FROM products WHERE manufacture_date = (SELECT MIN(manufacture_date) FROM products)
-- 6. Calculate the total price of all products in the products table using the SUM function.
SELECT SUM(price) FROM products
-- 7. Retrieve a list of products sorted by their prices in descending order using the ORDER
-- BY clause.
SELECT * FROM products ORDER BY price DESC

-- 8. Count the number of products that have a price greater than 900 using the COUNT
-- function.
SELECT COUNT(*) FROM products WHERE price > 900
-- 9. Find the product with the longest description (maximum number of characters) using the
-- LEN function.
-- The LEN function does not work on text columns, only on char, nchar, varchar, nvarchar, binary, or varbinary columns.
SELECT TOP 1 * FROM products ORDER BY DATALENGTH(description) DESC

-- 10. Update the description of products that have a price less than 799 to "Budget Product.
UPDATE products SET description = 'Budget Product' WHERE price < 799