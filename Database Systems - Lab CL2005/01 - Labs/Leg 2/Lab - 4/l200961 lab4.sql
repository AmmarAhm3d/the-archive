-- create the database
CREATE DATABASE WorldEvents;
go
use WorldEvents;
go
CREATE TABLE tblCategory (
	CategoryID int NOT NULL PRIMARY KEY,
	CategoryName nvarchar(255) NULL
);

CREATE TABLE tblContinent(
	ContinentID int NOT NULL PRIMARY KEY,
	ContinentName nvarchar(255) NULL
);

CREATE TABLE tblCountry(
	CountryID int NOT NULL PRIMARY KEY,
	CountryName nvarchar(255) NULL,
	ContinentID int NULL,
    FOREIGN KEY(ContinentID) REFERENCES tblContinent (ContinentID),
);

CREATE TABLE tblEvent(
	EventID int NOT NULL PRIMARY KEY,
	EventName varchar(8000) NULL,
	EventDate date NULL,
	CountryID int NULL,
	CategoryID int NULL,
    FOREIGN KEY(CategoryID) REFERENCES tblCategory (CategoryID),
    FOREIGN KEY(CountryID) REFERENCES tblCountry (CountryID),
);

INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (1, 'Politics');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (2, 'Alien life');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (3, 'Exploration');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (4, 'Natural world');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (5, 'Death and disaster');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (6, 'War and conflict');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (7, 'Sports');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (8, 'Economy');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (9, 'Entertainment and culture');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (10, 'Health and medicine');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (11, 'Love and relationships');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (12, 'Science and technology');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (13, 'Old');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (14, 'Transport');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (15, 'Energy');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (16, 'Royalty and monarchy');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (17, 'Crime and legal');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (18, 'Religion');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (19, 'Education');
INSERT INTO tblCategory (CategoryID, CategoryName) VALUES (20, 'General');

INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (1, 'Asia');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (2, 'Africa');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (3, 'Europe');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (4, 'Australasia');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (5, 'South America');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (6, 'North America');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (7, 'Antarctic');
INSERT INTO tblContinent (ContinentID, ContinentName) VALUES (8, 'Not applicable');

-- add the countries
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (1, 'Ukraine', 3);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (2, 'France', 3);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (5, 'United States', 6);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (8, 'Japan', 1);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (11,'Russia', 3);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (13,'Space', 8);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (20, 'Not set', 1);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (21, 'International', 8);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (24, 'India', 1);
INSERT INTO tblCountry (CountryID, CountryName, ContinentID) VALUES (26, 'South Africa', 2);

-- add the events
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (1, 'Chernobyl', '1986-04-26', 1, 5);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (2, 'Pearl Harbour', '1941-12-07' , 5, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (4, 'World War 1 ends', '1918-11-11' , 2, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (7, 'World War II ends', '1945-09-02' , 8, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (8, 'Hiroshima', '1945-08-06' , 8, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (9, 'Asian tsunami', '2004-12-26' , 21, 5);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (11, '9/11 attacks', '2001-09-11' , 5, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (14, 'Lehman Brothers collapses', '2008-09-15' , 5, 8);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (19, 'Channel Tunnel opens', '1994-05-06' , 2, 14);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (22, 'Coup attempt in Russia', '1991-08-19' , 11, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (23, 'Google launched', '1998-09-04' , 5, 12);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (328, 'First men land on the moon', '1969-07-20' , 13, 3);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (204, 'Sputnik I launched by Soviet Union', '1957-10-04' , 13, 12);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (136, 'NHS founded', '1948-07-05' , 20, 10);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (133, 'Gandhi assassinated in Delhi', '1948-01-30' , 24, 6);
INSERT INTO tblEvent (EventID, EventName, EventDate, CountryID, CategoryID) VALUES (128, 'India gains independence', '1947-08-14', 21, 1);

-- add a column to the continent table
ALTER TABLE tblContinent ADD Summary varchar(100) NULL;

-- set some (but not all) values
UPDATE tblContinent SET Summary = 'Big' WHERE ContinentID = 1;
UPDATE tblContinent SET Summary = 'Biggish' WHERE ContinentID = 2;
UPDATE tblContinent SET Summary = 'Home' WHERE ContinentID = 3;
UPDATE tblContinent SET Summary = 'Lots of trees' WHERE ContinentID = 5;
UPDATE tblContinent SET Summary = 'Full of penguins' WHERE ContinentID = 7;

-- list all tables
SELECT * FROM tblCategory;
SELECT * FROM tblContinent;
SELECT * FROM tblCountry;
SELECT * FROM tblEvent;


-- USE SUBQURIES TO ANSWER THE FOLLOWING QUESTIONS
-- 1. List of all the events which happened after the last one for country 21 (International)
-- took place.
SELECT * FROM tblEvent WHERE EventDate > 
(SELECT MAX(EventDate) FROM tblEvent WHERE CountryID = 21);

-- 2. List all the countries which have more than 2 events.
SELECT * FROM tblCountry WHERE CountryID IN
(SELECT CountryID FROM tblEvent GROUP BY CountryID HAVING COUNT(EventID) > 2);

-- 3. List the categories which have no events.
SELECT * FROM tblCategory WHERE CategoryID NOT IN
(SELECT CategoryID FROM tblEvent);

-- 4. List all the continents having an event in 1948.
SELECT * FROM tblContinent WHERE ContinentID IN
(SELECT ContinentID FROM tblCountry WHERE CountryID IN
    (SELECT CountryID FROM tblEvent WHERE DATEDIFF(YEAR, '1948-01-01', EventDate) = 0));

-- 5. List all the countries which have continent summary starting with “Big”.
SELECT * FROM tblCountry WHERE ContinentID IN
(SELECT ContinentID FROM tblContinent WHERE Summary LIKE 'Big%');

-- 6. List out all of those events whose Country is not in the list of the last 5 country names
-- in alphabetical order and Category is not in the list of the first 3 categories in
-- alphabetical order.
SELECT * FROM tblEvent WHERE CountryID NOT IN
(SELECT TOP 5 CountryID FROM tblCountry ORDER BY CountryName DESC) --alphabetical decending to get last 5 alphabetically
AND CategoryID NOT IN
(SELECT TOP 3 CategoryID FROM tblCategory ORDER BY CategoryName); --alphabetical ascending to get first 3 alphabetically

-- 7. List no of events for each continent between 1900-1999.
SELECT tblC.ContinentName, 
(SELECT COUNT(EventID) FROM tblEvent tblE WHERE tblE.CountryID IN -- nested correlated subquery in select clause
    (SELECT CountryID FROM tblCountry tblC2 WHERE tblC2.ContinentID = tblC.ContinentID) AND -- instead of using join
                                                                        tblE.EventDate BETWEEN '1900-01-01' AND '1999-12-31'
                                                                        ) AS 'No of Events'
FROM tblContinent tblC 

-- 8. No of events in which Continent does not have any Summary.
SELECT tblC.ContinentName,
(SELECT COUNT(EventID) FROM tblEvent tblE WHERE tblE.CountryID IN -- nested correlated subquery in select clause
    (SELECT CountryID FROM tblCountry tblC2 WHERE tblC2.ContinentID = tblC.ContinentID) AND 
                                                                        tblC.Summary IS NULL
                                                                        ) AS 'No of Events'
FROM tblContinent tblC

-- 9. List of Countries that are ‘Not Applicable’.
SELECT * FROM tblCountry WHERE
ContinentID IN (SELECT ContinentID FROM tblContinent WHERE ContinentName = 'Not applicable');

-- 10. In which country did “Hiroshima” event occur along with the date of happening.
SELECT 
    (SELECT CountryName FROM tblCountry WHERE CountryID = tblEvent.CountryID) AS CountryName
    ,EventDate 
FROM tblEvent 
WHERE EventName = 'Hiroshima';
