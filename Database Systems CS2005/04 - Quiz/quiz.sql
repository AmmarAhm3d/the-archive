use MASter
go
drop DATABASE if exists quiz
go
CREATE DATABASE quiz
go
use quiz
go
-- CREATE TABLE Tb1_Employee(
--     EMP_ID INT,
--     EMP_NAME VARCHAR(50),
--     EMP_NO VARCHAR(50),
-- )
-- go
-- CREATE TABLE Tb2_Employment(
--     EMP_ID INT,
--     EMP_Profile VARCHAR(50),
--     EMP_Country VARCHAR(50),
--     EMP_JoinDate DATE,
-- )
-- go

-- INSERT INTO Tb1_Employee VALUES
-- (101, 'Ashish Kaktan', '9450425345'),
-- (102, 'Raj Choudhary', '8462309621'),
-- (103, 'Vivek Oberoi', '7512309034'),
-- (104, 'Shantanu Khandelwal', '9020330023'),
-- (105, 'Khanak Desai', '8451004522');

-- insert into Tb2_Employment VALUES
-- (101, 'Content Writer', 'Germany', '2021-04-20'),
-- (104, 'Data Analyst', 'India', '2022-12-11'),
-- (105, 'Software Engineer', 'India', '2022-01-03'),
-- (108, 'Development Executive', 'Europe', '2023-02-15'),
-- (109, 'Marketing Manager', 'Mexico', '2020-05-23');

-- SELECT a.EMP_ID, a.EMP_NAME, b.EMP_Profile, b.EMP_Country, b.EMP_JoinDate 
-- FROM Tb1_Employee a
-- JOIN Tb2_Employment b
-- ON a.EMP_ID = b.EMP_ID

-- SELECT a.EMP_ID, a.EMP_NAME,  b.EMP_Profile, b.EMP_Country, b.EMP_JoinDate 
-- FROM Tb1_Employee a
-- INNER JOIN Tb2_Employment b
-- ON a.EMP_ID = b.EMP_ID

-- SELECT a.EMP_ID, a.EMP_NAME,  b.EMP_Profile, b.EMP_Country, b.EMP_JoinDate 
-- FROM Tb1_Employee a
-- LEFT JOIN Tb2_Employment b
-- ON a.EMP_ID = b.EMP_ID

-- CREATE TABLE employment(
--     EMP_ID INT,
--     EMP_Profile VARCHAR(50),
--     EMP_Email VARCHAR(50),
-- );

-- CREATE table employment_detail(
--     EMP_Country VARCHAR(50),
--     EMP_Email VARCHAR(50),
--     EMP_JoinDate DATE,
-- );

-- INSERT INTO employment VALUES
-- (101, 'Content Writer', 'ashish@scaler.com'),
-- (104, 'Data Analyst', 'shantau@scaler.com'),
-- (105, 'Software Engineer', 'khanak@scaler.com'),
-- (109, 'Development Executive', 'akshay@scaler.com'),
-- (108, 'Marketing Manager', 'nikita@scaler.com');

-- INSERT into employment_detail VALUES
-- ('Germany', 'ashish@scaler.com', '2021-04-20'),
-- ('India', 'shanatanu@scaler.com', '2022-12-11'),
-- ('India', 'khanak@scaler.com', '2022-01-03'),
-- ('Europe', 'akshay@scaler.com', '2023-02-15'),
-- ('Mexico', 'nikita@scaler.com', '2020-05-23');

-- SELECT a.EMP_ID, a.EMP_NAME, b.EMP_Profile, c.EMP_Country, c.EMP_JoinDate 
-- FROM Tb1_Employee a
-- JOIN employment b
-- ON a.EMP_ID = b.EMP_ID
-- JOIN employment_detail c
-- ON b.EMP_Email = c.EMP_Email

-- CREATE TABLE employees(
--     EMP_ID INT,
--     EMP_NAME VARCHAR(50),
--     EMP_PROFILE VARCHAR(50),
--     EMP_COUNTRY VARCHAR(50),
--     MANAGERID INT,
-- )

-- INSERT INTO employees VALUES
-- (101, 'Ashish Kaktan', 'Content Writer', 'Germany', 104),
-- (104, 'Raj Choudhary', 'Data Analyst', 'India', 108),
-- (105, 'Vivek Oberoi', 'Software Engineer', 'India', 101),
-- (108, 'Shantanu Khandelwal', 'Development Executive', 'Europe', 101),
-- (109, 'Khanak Desai', 'Marketing Manager', 'Mexico', null);

-- get employee id, his name and the manager name next to it



CREATE TABLE users(
userid INT primary key,
name VARCHAR(50),
city VARCHAR(50),
);
CREATE TABLE cardtype(
    cardTypeId VARCHAR(50) PRIMARY KEY,
    name VARCHAR(50),
) ;

CREATE TABLE cards(
    cardNum VARCHAR(10) PRIMARY KEY,
    cardTypeId VARCHAR(50) FOREIGN KEY REFERENCES cardtype(cardTypeId) ON DELETE SET NULL,
    pin VARCHAR(4),
    balance float,
);

CREATE TABLE usercard(
userid INT FOREIGN KEY REFERENCES users(userid) ON DELETE SET NULL,
cardNum VARCHAR(10) FOREIGN KEY REFERENCES cards(cardNum)ON DELETE SET NULL,
);



insert INTO users VALUES
(1 ,'William','Paris')  , 
(2 ,'Henry','London'  ),
(3, 'John', 'Dublin'),
(4, 'Maria', 'Moscow'),
(5, 'James', 'Valencia'),
(6, 'William', 'Venice');

INSERT INTO cardtype VALUES
(1, 'Debit'),
(2, 'Credit');
INSERT INTO cards VALUES
('1234', 1, '2281', '248162'),
('2851', 1, '4159', '319875'),
('3948', 2, '3478', '215734'),
('4236', 2, '4159', '198521'),
('5725', 2, '1955', '106780');


INSERT  INTO usercard VALUES
(1, '1234'),
(2, '2851'),
(3, '3948'),
(5, '4236'),
(1, '5725');

Delete from Users where Name='William' 
 

-- 1.write a sql query that uses a subquery to find the users who have cards with a balance greater than the     balance of all users.
SELECT name FROM users WHERE userid IN
                            (SELECT userid FROM usercard WHERE cardNum IN 
                                (SELECT cardNum FROM cards WHERE balance > (SELECT AVG(balance) FROM cards)));
-- 2.Write a SQL query that uses a subquery to find the card type of Member_ID = 1.
SELECT name FROM cardtype WHERE cardTypeId IN
                            (SELECT cardTypeId FROM cards WHERE cardNum IN 
                                (SELECT cardNum FROM usercard WHERE userid = 1));
-- 3.Write a SQL query that uses a subquery to find the card type of members from the city 'Dublin.'
SELECT name FROM cardtype WHERE cardTypeId IN
                            (SELECT cardTypeId FROM cards WHERE cardNum IN 
                                (SELECT cardNum FROM usercard WHERE userid IN
                                    (SELECT userid FROM users WHERE city = 'Dublin')));
-- 4. Write a SQL subquery to find the total balance across all cards for the user with the highest balance among the users in Mosscow
SELECT SUM(balance) FROM cards WHERE cardNum IN
                            (SELECT cardNum FROM usercard WHERE userid IN
                                (SELECT userid FROM users WHERE city = 'Moscow'));
-- 5. Write a SQL subquery to find the names of users who have Debit card and a card balance greater
-- than  average card balance of all users.
SELECT name FROM users WHERE userid IN
                            (SELECT userid FROM usercard WHERE cardNum IN 
                                (SELECT cardNum FROM cards WHERE cardTypeId = 1 
                                AND balance >
                                 (SELECT AVG(balance) FROM cards)));
-- 6. Write a SQL subquery to find the names of the users who have both Debit and credit cards.
SELECT name FROM users WHERE userid IN
                            (SELECT userid FROM usercard WHERE cardNum IN 
                                (SELECT cardNum FROM cards WHERE cardTypeId = 1)) 
                                AND userid IN
                            (SELECT userid FROM usercard WHERE cardNum IN 
                                (SELECT cardNum FROM cards WHERE cardTypeId = 2));
-- 7. Write a SQL subquery to find the avg balance  of the users who have  Debit  card and live in 
-- cities  starting  with letter V.
SELECT AVG(balance) FROM cards WHERE cardNum IN
                            (SELECT cardNum FROM usercard WHERE userid IN
                                (SELECT userid FROM users WHERE city LIKE 'V%')) AND cardTypeId = 1;

-- final I
SELECT u.Name AS Member_Name, c.cardNum AS Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum
WHERE u.Name LIKE 'William%';

--  first join
SELECT u.Name AS Member_Name
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId

-- second join
SELECT u.Name AS Member_Name, c.cardNum AS Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum

-- final II
SELECT u.Name AS Member_Name, ct.Name AS Card_Type
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum
JOIN CardType ct ON c.cardTypeId = ct.cardTypeId
WHERE ct.Name = 'Credit';

-- first join
SELECT u.Name AS Member_Name
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId

-- second join
SELECT c.cardNum AS Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum

-- third join
SELECT c.cardNum as Card_Number ,ct.name AS Card_Type
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum
JOIN CardType ct ON c.cardTypeId = ct.cardTypeId

-- final III
SELECT u.Name AS Member_Name, uc.cardNum AS Debit_Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum
JOIN CardType ct ON c.cardTypeId = ct.cardTypeId
WHERE ct.Name = 'Debit';

-- first join
SELECT u.Name AS Member_Name
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId

-- second join
SELECT uc.cardNum AS Debit_Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum

-- third join
SELECT uc.cardNum AS Debit_Card_Number
FROM Users u
JOIN UserCard uc ON u.UserId = uc.UserId
JOIN Cards c ON uc.cardNum = c.cardNum
JOIN CardType ct ON c.cardTypeId = ct.cardTypeId

-- 

