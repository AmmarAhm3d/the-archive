CREATE DATABASE lab5
go
USE lab5
go

CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    date_of_birth DATE
);

CREATE TABLE Courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100),
    instructor VARCHAR(100)
);

CREATE TABLE Enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

INSERT INTO Students (student_id, first_name, last_name, date_of_birth)
VALUES
    (1, 'John', 'Doe', '1995-05-15'),
    (2, 'Jane', 'Smith', '1998-09-20'),
    (3, 'Alice', 'Johnson', '1997-03-13'),
    (4, 'Ella', 'Johnson', '1996-07-12'),
    (5, 'Liam', 'Brown', '1999-02-25'),
    (6, 'Ava', 'Miller', '1998-11-18'),
    (7, 'Noah', 'Garcia', '1997-09-03'),
    (8, 'Olivia', 'Martinez', '1996-04-29'),
    (9, 'Emma', 'Lopez', '1998-06-21'),
    (10, 'William', 'Davis', '1997-03-14'),
    (11, 'Sophia', 'Rodriguez', '1999-08-05'),
    (12, 'James', 'Hernandez', '1995-12-08'),
    (13, 'Charlotte', 'Young', '1996-10-17'),
    (14, 'Benjamin', 'Lee', '1998-05-20'),
    (15, 'Amelia', 'Walker', '1997-01-23');

INSERT INTO Courses (course_id, course_name, instructor)
VALUES
    (101, 'Introduction to Database', 'Professor Smith'),
    (102, 'Web Development Basics', 'Professor Johnson'),
    (103, 'Data Analysis Techniques', 'Professor Brown'),
    (104, 'Advanced Database Management', 'Professor Johnson'),
    (105, 'Data Mining Techniques', 'Professor Lee'),
    (106, 'Web Application Development', 'Professor Martinez'),
    (107, 'Software Engineering Principles', 'Professor Davis'),
    (108, 'Network Security Fundamentals', 'Professor Rodriguez'),
    (109, 'Artificial Intelligence Fundamentals', 'Professor Hernandez'),
    (110, 'Database Design and Optimization', 'Professor Young'),
    (111, 'Mobile App Development', 'Professor Walker'),
    (112, 'Cloud Computing Technologies', 'Professor Moore'),
    (113, 'Human-Computer Interaction', 'Professor Turner'),
    (114, 'Business Analytics', 'Professor Perez'),
    (115, 'Computer Graphics and Visualization', 'Professor Foster');


INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_date)
VALUES
    (1, 1, 101, '2023-01-15'),
    (2, 1, 102, '2023-02-20'),
    (3, 2, 101, '2023-01-15'),
    (4, 3, 103, '2023-03-05'),
    (5, 4, 104, '2023-02-10'),
    (6, 5, 105, '2023-03-15'),
    (7, 6, 106, '2023-01-22'),
    (8, 7, 107, '2023-04-05'),
    (9, 8, 108, '2023-02-28'),
    (10, 10, 109, '2023-01-10'),
    (11, 10, 110, '2023-03-18'),
    (12, 11, 112, '2023-02-08'),
    (13, 12, 112, '2023-03-02'),
    (14, 13, 113, '2023-04-12'),
    (15, 14, 114, '2023-01-29'),
    (16, 15, 115, '2023-03-21');


-- 1) Create a simple view called StudentList that displays the full names of all
-- students along with their date of birth. 
DROP VIEW IF EXISTS StudentList;
go
CREATE VIEW [StudentList] AS
SELECT student_id,first_name + ' ' +last_name AS full_name, date_of_birth FROM Students;
go
SELECT * FROM StudentList;
-- 2) Write a SQL query to retrieve the top 5 students (based on their
-- student_id) from the StudentList view. 
SELECT TOP 5 * FROM StudentList ORDER BY student_id;
-- 3) Add a new column to the StudentList view called age that calculates the
-- age of each student based on their date of birth. 
ALTER VIEW [StudentList] AS
SELECT student_id, first_name + ' ' +last_name AS full_name, date_of_birth, DATEDIFF(YEAR,date_of_birth,GETDATE()) AS age FROM Students;
go
SELECT * FROM StudentList;

-- <for this lab sir said use normal views not materialized views>

-- 4) Create a materialized view called CourseEnrollments that shows the
-- number of students enrolled in each course. 
DROP VIEW IF EXISTS CourseEnrollments;
go
CREATE View [CourseEnrollments] AS
SELECT course_id, COUNT(student_id) AS number_of_students FROM Enrollments GROUP BY course_id;
go
SELECT * FROM CourseEnrollments;
-- 5) Write a SQL query to retrieve the courses with the highest number of
-- enrollments from the CourseEnrollments materialized view.  
SELECT number_of_students, course_name FROM CourseEnrollments 
WHERE number_of_students = (SELECT MAX(number_of_students) FROM CourseEnrollments);
-- 6) Modify the CourseEnrollments materialized view to include the course
-- name and instructor's name. Refresh the materialized view to update the
-- information. 
ALTER VIEW [CourseEnrollments] AS
SELECT e.course_id, COUNT(e.student_id) AS number_of_students , c.course_name, c.instructor 
FROM Courses c
JOIN Enrollments e
ON c.course_id = e.course_id 
GROUP BY e.course_id, c.course_name, c.instructor;
go
SELECT * FROM CourseEnrollments;

-- 7) Write a complex SQL query that uses both the StudentList simple view
-- and the CourseEnrollments materialized view to find the course with the
-- most enrollments and display the names of the students enrolled in that
-- course. 
SELECT CE.course_name, SL.full_name
FROM StudentList SL
JOIN Enrollments E 
ON SL.student_id = E.student_id
JOIN CourseEnrollments CE 
ON E.course_id = CE.course_id
WHERE CE.number_of_students = (SELECT MAX(number_of_students) FROM CourseEnrollments);
-- 8) Drop both the StudentList view and the CourseEnrollments materialized
-- view.
DROP VIEW IF EXISTS StudentList;
go
DROP VIEW IF EXISTS CourseEnrollments;
go
-- 9) Create a simple view named StudentCourseCount that displays the
-- student's full name and the count of courses they are enrolled in. 
CREATE VIEW [StudentCourseCount] AS
SELECT s.student_id, s.first_name + ' ' + s.last_name AS full_name, COUNT(e.course_id) AS number_of_courses
FROM Students s
JOIN Enrollments e 
ON s.student_id = e.student_id
GROUP BY s.student_id, s.first_name, s.last_name;
go
SELECT * FROM StudentCourseCount;
-- 10) Write a SQL query to find the student(s) with the highest number of
-- courses enrolled from the StudentCourseCount view. 
SELECT * FROM StudentCourseCount WHERE number_of_courses = (SELECT MAX(number_of_courses) FROM StudentCourseCount);
-- 11) Create a materialized view called InstructorCourseCount that shows the
-- instructor's name and the count of courses they are teaching. 
DROP VIEW IF EXISTS InstructorCourseCount;
go
CREATE VIEW [InstructorCourseCount] AS
SELECT c.instructor, COUNT(c.course_id) AS number_of_courses
FROM Courses c
GROUP BY c.instructor;
go
SELECT * FROM InstructorCourseCount;
-- 12) Write a SQL query to find the instructor(s) with the highest number of
-- courses they are teaching from the InstructorCourseCount view. 
SELECT * FROM InstructorCourseCount WHERE number_of_courses = (SELECT MAX(number_of_courses) FROM InstructorCourseCount);
-- 13) Create a materialized view called StudentEnrollments that displays the
-- student's full name and a list of courses they are enrolled in, separated by
-- commas. 
-- 
-- i will be using STRING_AGG() function here syntax of STRING_AGG is as follows:
-- ```STRING_AGG ( expression, separator ) [ WITHIN GROUP ( ORDER BY <order_by_expression_list> [ ASC | DESC ] ) ]```
-- 
DROP VIEW IF EXISTS StudentEnrollments;
go
CREATE VIEW [StudentEnrollments] AS
SELECT s.first_name + ' ' + s.last_name + ' ' + -- the name will be lsted once
STRING_AGG(c.course_name, ', ') WITHIN GROUP (ORDER BY c.course_name) as courses -- the courses will be listed, seperated by space
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
GROUP BY s.first_name, s.last_name; -- and since these are the only two non-aggregate columns  we need to group them
go
SELECT * FROM StudentEnrollments;
-- 14) Write a SQL query that uses the StudentCourseCount, InstructorCourseCount, and StudentEnrollments views to find the student
-- who is enrolled in the most courses and display the instructor(s) teaching
-- those courses. 
WITH 
most_enrolled_student AS (
    SELECT * FROM StudentCourseCount WHERE number_of_courses = (SELECT MAX(number_of_courses) FROM StudentCourseCount)
),
most_enrolled_courses AS (
    SELECT * FROM StudentEnrollments WHERE courses LIKE (SELECT '%' + (SELECT full_name FROM most_enrolled_student) + '%')
)
SELECT * 
FROM InstructorCourseCount 
WHERE instructor IN (
    SELECT courses 
    FROM most_enrolled_courses
);
-- 15) Create a materialized view called StudentCourseInfo that displays the
-- student's full name, course name, and instructor for all enrollments
DROP VIEW IF EXISTS StudentCourseInfo;
go
CREATE VIEW [StudentCourseInfo] AS
SELECT s.first_name + ' ' + s.last_name AS full_name, c.course_name, c.instructor
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id -- for all enrollments
JOIN Courses c ON e.course_id = c.course_id;
go
SELECT * FROM StudentCourseInfo;