-- STUDENT MANAGEMENT SYSTEM DATABASE SCRIPTS
-- Group Members:
-- 20L-1342	Waseef Khalid Khan	C2
-- 20L-0961	Ammar Ahmed	        C1
-- 20L-1299	M Mahd kashif	    C1
-- 20L-0980	Abdul Rafey	        C2
CREATE DATABASE [Student_Management_System]

-- DROP DATABASE IF EXISTS [Student_Management_System]

USE [Student_Management_System]

-- TABLES

-- Table: Faculty
-- Attributes: faculty_id, name, email, phone, address, qualification, department_id, password, designation

-- --------------------------------------------------------

CREATE TABLE Faculty ( 
    faculty_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(15) NOT NULL,
    email VARCHAR(20) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    address VARCHAR(50) NOT NULL,
    qualification VARCHAR(20) NOT NULL CHECK(qualification IN ('PhD', 'MPhil', 'MS', 'BS', 'BSc', 'BBA', 'BCom', 'BA', 'Matric', 'FSC')),
    designation VARCHAR(50) NOT NULL CHECK(designation IN ('Professor', 'Associate Professor', 'Assistant Professor', 'Lecturer', 'Lab Assistant', 'Non Teaching Staff')),
    );

-- --------------------------------------------------------

-- Table: Department
-- Attributes: department_id, name, head_id (foreign key referencing faculty_id)

-- --------------------------------------------------------

CREATE TABLE Department ( 
    department_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(15) NOT NULL CHECK(name IN ('Computer Science', 'Electrical Engineering', 'Civil Engineering', 'Computer Engineering',  'Metallurgical Engineering')),
    head_id INT NOT NULL REFERENCES Faculty(faculty_id),
    );

-- --------------------------------------------------------

-- Table: Course
-- Attributes: course_id, name, description, credits, department_id (foreign key referencing department_id)

-- --------------------------------------------------------

CREATE TABLE Course ( 
    course_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(15) NOT NULL UNIQUE,
    description VARCHAR(100) NOT NULL,
    credits INT NOT NULL CHECK(credits > 0),
    department_id INT REFERENCES Department(department_id),
    );

-- --------------------------------------------------------

-- Table: Class
-- Attributes: class_id, course_id (foreign key referencing course_id), class_name

CREATE TABLE Class ( 
    class_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    course_id INT NOT NULL REFERENCES Course(course_id),
    class_name VARCHAR(15) NOT NULL,
    );

-- --------------------------------------------------------

-- Table: Student
-- Attributes: student_id, name, gender, enrollment_date, department_id, semester_no, section_id
CREATE TABLE Student ( 
    student_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    gender VARCHAR NOT NULL CHECK(gender IN ('M', 'F')),
    enrollment_date DATE NOT NULL,
    department_id INT REFERENCES Department(department_id),
    class_id INT REFERENCES Class(class_id),
    semester_no INT CHECK(semester_no in (1, 2, 3, 4, 5, 6, 7, 8)),
    section_id INT CHECK(section_id in (1, 2, 3, 4, 5, 6, 7, 8)),
    );

-- Table: Enrollment
-- Attributes: enrollment_id, student_id (foreign key referencing student_id), course_id (foreign key referencing course_id), 
-- semester, year, grade, status

-- --------------------------------------------------------

CREATE TABLE Enrollment ( 
    enrollment_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    student_id INT REFERENCES Student(student_id),
    course_id INT REFERENCES Course(course_id),
    semester VARCHAR(15) NOT NULL CHECK(semester IN ('Fall', 'Spring', 'Summer')),
    year INT CHECK(year > 2020),
    grade VARCHAR NOT NULL CHECK(grade IN ('A', 'B', 'C', 'D', 'F')),
    status VARCHAR(15) NOT NULL CHECK(status IN ('Enrolled', 'Dropped'))
    );

-- --------------------------------------------------------


-- --------------------------------------------------------

-- Table: Attendance
-- Attributes: attendance_id, enrollment_id (foreign key referencing enrollment_id), date, status (present/absent)

CREATE TABLE Attendance ( 
    attendance_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    enrollment_id INT NOT NULL REFERENCES Enrollment(enrollment_id),
    date DATE NOT NULL CHECK(date < CONVERT(DATE, GETDATE())),
    status VARCHAR(50) NOT NULL CHECK(status IN ('Present', 'Absent')),
    );

-- --------------------------------------------------------

-- Table: Exam
-- Attributes: exam_id, course_id (foreign key referencing course_id), date, duration, status

-- --------------------------------------------------------

CREATE TABLE Exam ( 
    exam_id INT PRIMARY KEY,
    course_id INT NOT NULL REFERENCES Course(course_id),
    date DATE NOT NULL CHECK(date < CONVERT(DATE, GETDATE())),
    duration FLOAT NOT NULL CHECK(duration > 0),
    status VARCHAR(15) NOT NULL CHECK(status IN ('Scheduled', 'Completed', 'Cancelled')),
    );

-- --------------------------------------------------------

-- Table: Marks
-- Attributes: mark_id, enrollment_id (foreign key referencing enrollment_id), exam_id (foreign key referencing exam_id), obtained_marks

-- --------------------------------------------------------

CREATE TABLE Marks ( 
    mark_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    enrollment_id INT NOT NULL REFERENCES Enrollment(enrollment_id),
    exam_id INT NOT NULL REFERENCES Exam(exam_id),
    passing_marks FLOAT NOT NULL CHECK(passing_marks > 0),
    obtained_marks FLOAT NOT NULL,
    total_marks FLOAT NOT NULL,
    );

ALTER TABLE Marks ADD CHECK(obtained_marks <= total_marks);

-- --------------------------------------------------------

-- Table: Alumni
-- Attributes:  alumni_id, name, email, phone, address, graduation_year, department_id (foreign key referencing department_id), current_occupation

-- --------------------------------------------------------

CREATE TABLE Alumni ( 
    alumni_id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    name VARCHAR(15) NOT NULL,
    email VARCHAR(20) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    address VARCHAR(50) NOT NULL,
    graduation_year INT NOT NULL CHECK(graduation_year < GETDATE()),
    department_id INT NOT NULL REFERENCES Department(department_id),
    current_occupation VARCHAR(20) NOT NULL CHECK(current_occupation IN ('Employed', 'Unemployed')),
    );

-- --------------------------------------------------------

-- END OF SCRIPTS