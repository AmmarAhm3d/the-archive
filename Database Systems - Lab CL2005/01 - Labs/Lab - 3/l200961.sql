CREATE DATABASE inlab3Practice;

USE inlab3Practice;

-- create salesman table
CREATE TABLE salesman (
  salesman_id INT NOT NULL PRIMARY KEY,
  name VARCHAR(255),
  city VARCHAR(255),
  commission DECIMAL(4,2)
);

-- insert data into salesman table
INSERT INTO salesman (salesman_id, name, city, commission) VALUES
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14),
(5007, 'Paul Adam', 'San Jose', 0.13),
(5003, 'Lauson Hen', 'San Jose', 0.12);

CREATE TABLE customers (
  customer_id INT NOT NULL PRIMARY KEY,
  cust_name VARCHAR(255),
  city VARCHAR(255),
  grade INT,
  salesman_id INT,
  FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

-- insert data into customers table
INSERT INTO customers (customer_id, cust_name, city, grade, salesman_id) VALUES
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3007, 'John Brad Davis', 'New York', 200, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3008 ,'Julian Green', 'London', 300, 5002),
(3004 ,'Fabian Johnson', 'Paris', 300, 5006),
(3009 ,'Geoff Cameron' ,'Berlin', 100, 5003),
(3003 ,'Jozy Altidor' ,'Moscow' ,200, 5007),
(3001 ,'John Brad Guzan' ,'London', Null ,5005);


-- create orders table
CREATE TABLE orders (
  ord_no INT NOT NULL PRIMARY KEY,
  purch_amt DECIMAL(8,2),
  ord_date DATE,
  customer_id INT,
  salesman_id INT,
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id),
  FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

-- insert data into orders table
INSERT INTO orders (ord_no, purch_amt, ord_date, customer_id, salesman_id) VALUES
(70001, 150.5, '2012-10-05', 3005, 5002),
(70009, 270.65, '2011-09-10', 3001, 5005),
(70002, 65.26, '2014-10-05', 3002, 5001),
(70004, 110.5, '2011-08-17', 3009, 5003),
(70007, 948.5, '2012-09-10', 3005, 5002),
(70005, 2400.6, '2010-07-27', 3007, 5001),
(70008, 5760, '2013-09-10', 3002, 5001),
(70010, 1983.43, '2010-10-10', 3004, 5006),
(70003, 2480.4, '2013-10-10', 3009, 5003),
(70012, 250.45, '2010-06-27', 3008, 5002),
(70011, 75.29, '2014-08-17', 3003, 5007),
(70013, 3045.6, '2010-04-25', 3002, 5001);

SELECT * FROM customers WHERE city = 'New York' ORDER BY cust_name ASC;
SELECT * FROM customers WHERE cust_name LIKE '%John%' and (city='London' or city='Paris' or city='New York');
SELECT * FROM customers where (city = 'London' or city='New York');
SELECT * FROM orders where purch_amt > 500;
SELECT * FROM salesman WHERE name like '_a%';
SELECT commission+0.5 AS [commissionforsanjose] FROM salesman WHERE city='San Jose';
SELECT * FROM orders ORDER BY ord_date DESC;
SELECT (name)AS firstname FROM salesman;
SELECT * FROM orders WHERE MONTH(ord_date) = 1;
SELECT YEAR(ord_date) AS year,
       DATEPART(wk, ord_date) AS week,
       DATEPART(dy, ord_date) AS dayofyear,
       MONTH(ord_date) AS month,
       DAY(ord_date) AS day,
       DATENAME(dw, ord_date) AS weekday
FROM orders
WHERE MONTH(ord_date) = 10;
SELECT purch_amt*3 FROM orders WHERE MONTH(ord_date) = 10;
SELECT c.customer_id,c.cust_name,c.city,c.grade,c.salesman_id
from [customers] c JOIN orders o ON c.customer_id=o.customer_id
WHERE YEAR(o.ord_date) IN (2011,2013)

SELECT TOP(1) salesman.salesman_id,salesman.name,salesman.city,salesman.commission FROM salesman ORDER BY commission DESC

-- create customers table
-- operations
-- SELECT CGPA/2 FROM Students 

-- -- contains
-- SELECT CourseName, CourseCreditHours
-- FROM Courses
-- WHERE CourseName LIKE '%Programming%' AND CourseCreditHours >=1

-- -- contains r as 2nd letter
-- SELECT CourseName, CourseCreditHours
-- FROM Courses
-- WHERE CourseName LIKE '%_r%' AND CourseCreditHours >=1

-- -- starts with c ends at r, and conains said word
-- SELECT CourseName, CourseCreditHours
-- FROM Courses
-- WHERE CourseName LIKE 'C%r%'

-- -- aliases and desc sort
-- SELECT StudentName AS fname, CGPA as [cumgpa]
-- FROM Students
-- ORDER BY CGPA DESC