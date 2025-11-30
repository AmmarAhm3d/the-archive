-------------------------------------------------------
-------------------STORED PROCEDURES-------------------
-------------------------LAB06-------------------------
-------------------------------------------------------
CREATE DATABASE lab6
GO
use lab6
GO
CREATE TABLE Students (
  studentID INT IDENTITY(1,1) PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  rollNo VARCHAR(50),
  major VARCHAR(50)
);

-- Create the Courses table
CREATE TABLE Courses (
  courseID INT IDENTITY(1,1) PRIMARY KEY ,
  courseName VARCHAR(50),
  instructor VARCHAR(50),
  department VARCHAR(50),
  creditHour INT
);

-- Create the Enrollments table
CREATE TABLE Enrollments (
  enrollmentID INT IDENTITY(1,1) PRIMARY KEY ,
  studentID INT,
  courseID INT,
  FOREIGN KEY (studentID) REFERENCES Students(studentID),
  FOREIGN KEY (courseID) REFERENCES Courses(courseID)
);

-- Create the Grades table
CREATE TABLE Grades (
  gradeID INT IDENTITY(1,1) PRIMARY KEY ,
  enrollmentID INT,
  grade DECIMAL(4,2),
  FOREIGN KEY (enrollmentID) REFERENCES Enrollments(enrollmentID)
);

-- Inserting records into the Students table
INSERT INTO Students (name, age, rollNo, major) VALUES ('Giselle Collette', 20, 'l201234', 'Computer Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Emily Davis', 22, 'l212342', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Kaeya Alberich', 21, 'l203451', 'Mathematics');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Florence Nightingale', 23, 'l203452', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Waver Velvet', 21, 'l224324', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Benedict Blue', 21, 'l214984', 'Computer Science');

-- Inserting records into the Courses table
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Database Systems', 'Prof. Smith', 'CS', 4);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Web Development', 'Prof. Jonathan', 'CS', 4);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Theory of Automata', 'Prof. Williams', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Machine Learning', 'Prof. Williams', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Discrete Structures', 'Prof. Horace', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Numeric Computing', 'Prof. Sarah', 'MTH', 3);

-- Inserting records into the Enrollments table
INSERT INTO Enrollments (studentID, courseID) VALUES (1, 1); 
INSERT INTO Enrollments (studentID, courseID) VALUES (2, 1); 
INSERT INTO Enrollments (studentID, courseID) VALUES (2, 2); 
INSERT INTO Enrollments (studentID, courseID) VALUES (3, 3); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 4); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 3); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 6); 
INSERT INTO Enrollments (studentID, courseID) VALUES (6, 1); 

-- Inserting records into the Grades table
INSERT INTO Grades (enrollmentID, grade) VALUES (1, 3.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (2, 2.7); 
INSERT INTO Grades (enrollmentID, grade) VALUES (3, 2.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (4, 4); 
INSERT INTO Grades (enrollmentID, grade) VALUES (5, 3.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (6, 3.7); 
INSERT INTO Grades (enrollmentID, grade) VALUES (7, 3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (8, 3.7); 


-- 1. Write a procedure named "getUnenrolledStudents" that takes in no parameters. The procedure should retrieve all the students who are not enrolled in any course and display their information.
CREATE PROCEDURE getUnenrolledStudents
AS
BEGIN
  SELECT * FROM Students WHERE studentID NOT IN (SELECT studentID FROM Enrollments)
END
GO

exec getUnenrolledStudents
-- 2. Write a procedure named "updateStudentAge" that takes in parameters for "studentID" and "newAge." The procedure should update the age of the student with the given ID in the "Students" table.
CREATE PROCEDURE updateStudentAge
  @studentID INT,
  @newAge INT
AS
BEGIN
  UPDATE Students SET age = @newAge WHERE studentID = @studentID
END
GO

DECLARE @studentID INT = 1
DECLARE @newAge INT = 21
exec updateStudentAge
  @studentID,
  @newAge
GO
-- get the updated record
SELECT age FROM Students WHERE studentID = 1
-- 3. Create a procedure named "deleteStudent" that takes in a parameter for "studentID." The procedure should delete the student record with the given ID from the "Students" table and all his enrollment information.
DROP PROCEDURE deleteStudent
CREATE PROCEDURE deleteStudent @studentID INT
AS
BEGIN
  -- Delete grade information of the student
  DELETE FROM Grades WHERE enrollmentID IN (SELECT enrollmentID FROM Enrollments WHERE studentID = @studentID);

  -- Delete enrollment information of the student
  DELETE FROM Enrollments WHERE studentID = @studentID;

  -- Delete the student record
  DELETE FROM Students WHERE studentID = @studentID;
END;

exec deleteStudent @studentID = 1
GO
-- find changes
SELECT * FROM Students WHERE studentID = 1
SELECT * FROM Enrollments WHERE studentID = 1
-- 4. Write a procedure named "getCourseStudents" that takes in a parameter for "courseID." The procedure should retrieve all the students enrolled in the course with the specified courseID and display their names and majors.
CREATE PROCEDURE getCourseStudents
  @courseID INT
AS
BEGIN
  SELECT name, major FROM Students WHERE studentID IN (SELECT studentID FROM Enrollments WHERE courseID = @courseID)
END
GO

exec getCourseStudents @courseID = 1
-- 5. Create a procedure named "getStudentInfo" that takes in a parameter for "studentID." The procedure should retrieve the student's information, including their name, age, rollNo, major, and the courses they are enrolled in, with their respective departments, and display them.
CREATE PROCEDURE getStudentInfo
  @studentID INT
AS
BEGIN
  SELECT name, age, rollNo, major FROM Students WHERE studentID = @studentID;
  SELECT courseName, department FROM Courses WHERE courseID IN (SELECT courseID FROM Enrollments WHERE studentID = @studentID);
END
GO

exec getStudentInfo @studentID = 2
-- 6. Write a procedure named "getMostPopularCourse" that takes in an optional parameter for "department." The procedure should retrieve the course with the most enrollments in the specified department and display the course's information, including the course name, instructor, and the number of students enrolled in the course, and display them. If no department is specified, ‘CS’ should be taken as default value.
DROP PROCEDURE getMostPopularCourse
CREATE PROCEDURE getMostPopularCourse
  @department VARCHAR(50) = 'CS'
AS
BEGIN
  SELECT TOP 1 courseName, instructor, COUNT(*) AS nostudentenrolled FROM Courses
  INNER JOIN Enrollments ON Courses.courseID = Enrollments.courseID
  WHERE department = @department
  GROUP BY courseName, instructor, Courses.courseID
  ORDER BY nostudentenrolled DESC
END;

EXEC getMostPopularCourse
-- 7. Create a procedure named "calculateCourseGPA" that takes an input parameter for "courseID" and an output parameter for "averageGPA." The procedure should calculate the average GPA of all the students enrolled in the specified course and store the result in the output parameter.
CREATE PROCEDURE calculateCourseGPA
  @courseID INT,
  @averageGPA DECIMAL(4,2) OUTPUT
AS
BEGIN
  SELECT @averageGPA = AVG(grade) FROM Grades WHERE enrollmentID IN (SELECT enrollmentID FROM Enrollments WHERE courseID = @courseID)
END

DECLARE @averageGPA DECIMAL(4,2)
EXEC calculateCourseGPA @courseID = 3, @averageGPA = @averageGPA OUTPUT
SELECT @averageGPA
-- 8. ALTER the above procedure and display the average GPA of all the students in the "Students" table.
ALTER PROCEDURE calculateCourseGPA
  @averageGPA DECIMAL(4,2) OUTPUT
AS
BEGIN
  SELECT @averageGPA = AVG(grade) FROM Grades WHERE enrollmentID IN (SELECT enrollmentID FROM Enrollments WHERE studentID IN (SELECT studentID FROM Students))
END

DECLARE @averageGPA DECIMAL(4,2)
EXEC calculateCourseGPA @averageGPA = @averageGPA OUTPUT
SELECT @averageGPA
-- 9. Write a procedure named "getCourseEnrollmentCount" that takes in a parameter for "courseID." The procedure should retrieve the total number of students enrolled in the course with the specified courseID and display the count.
CREATE PROCEDURE getCourseEnrollmentCount
  @courseID INT
AS
BEGIN
  SELECT COUNT(*) AS nostudentenrolled FROM Enrollments WHERE courseID = @courseID
END

EXEC getCourseEnrollmentCount @courseID = 3
-- 10. Create a procedure named "getCourseWithoutGrades" that retrieves all the courses that have no grades recorded in the "Grades" table and displays their details.
CREATE PROCEDURE getCourseWithoutGrades
AS
BEGIN
  SELECT * FROM Courses WHERE courseID NOT IN (SELECT courseID FROM Enrollments WHERE enrollmentID IN (SELECT enrollmentID FROM Grades))
END

EXEC getCourseWithoutGrades