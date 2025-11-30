Create database inlab3Practice;

use inlab3Practice;

create table Students
(
StudentId int not null primary key,
StudentName varchar(50),
StudentBatch int,
CGPA float
);

create table Instructors
(
InstructorId int not null primary key,
InstructorName varchar(50)
);

create table Courses
(
CourseId int not null primary key,
CourseName varchar(100),
CourseCreditHours int,
InstructorId int foreign key references Instructors(InstructorId)
);

create table Registration
(
StudentId int foreign key references Students(StudentId),
CourseId int foreign key references Courses(CourseId),
CGPA float,
primary key (StudentId, CourseId)
);

insert into Students values 
(1, 'Ali', 2013, 3.3),
(2, 'Aysha', 2013, 4),
(3, 'Ahmed', 2013, 2.2);

insert into Instructors values 
(1, 'Zafar'),
(2, 'Sadia'),
(3, 'Saima');

insert into Courses values 
(1, 'Computer Programming', 3, 1),
(2, 'Computer Organization and Assembly', 3, 2);

insert into Courses (CourseId, CourseName, CourseCreditHours) values
(3, 'Computer Programming Lab', 1);

insert into Registration values 
(1, 1, 3),
(1, 3, 3),
(2, 2, 0);

Select * from Students;
Select * from Instructors;
Select * from Courses;
Select * from Registration;
