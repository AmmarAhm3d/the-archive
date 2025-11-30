-------------------------------------------------------
-------------------STORED PROCEDURES-------------------
-------------------------LAB06-------------------------
-------------------------------------------------------
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