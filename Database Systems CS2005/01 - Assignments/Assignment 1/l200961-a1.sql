use master
DROP DATABASE IF EXISTS HospitalManagementSystem;
-- || Hospital Management System ||
CREATE DATABASE HospitalManagementSystem;
USE HospitalManagementSystem;

CREATE TABLE Patients (
    PatientID INT PRIMARY KEY,
    Name VARCHAR(100),
    DOB DATE,
    Gender CHAR(1),
    Contact VARCHAR(15),
    Address VARCHAR(255),
    Email VARCHAR(100) UNIQUE,
    CHECK (Gender IN ('M', 'F'))
);


CREATE TABLE Departments (
    DepartmentID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE MedicalStaff (
    StaffID INT PRIMARY KEY,
    Name VARCHAR(100),
    DOB DATE,
    Gender CHAR(1),
    Contact VARCHAR(15),
    Address VARCHAR(255),
    Role VARCHAR(50),
    DepartmentID INT FOREIGN KEY REFERENCES Departments(DepartmentID),
);


CREATE TABLE Appointments (
    AppointmentID INT PRIMARY KEY,
    PatientID INT foreign key references Patients(PatientID),
    StaffID INT foreign key references MedicalStaff(StaffID),
    AppointmentDateTime DATETIME,
    Status VARCHAR(50),
);

CREATE TABLE MedicalRecords (
    RecordID INT PRIMARY KEY,
    PatientID INT foreign key references Patients(PatientID),
    StaffID INT foreign key references MedicalStaff(StaffID),
    DateOfService DATE,
    Diagnosis TEXT,
    Treatment TEXT,
    Prescription TEXT,
    TestResults TEXT,
    Notes TEXT,
);

CREATE TABLE Billing (
    BillingID INT PRIMARY KEY,
    PatientID INT foreign key references Patients(PatientID),
    StaffID INT foreign key references MedicalStaff(StaffID),
    BillingDate DATE,
    TotalAmount DECIMAL(10, 2),
    PaymentStatus VARCHAR(50),
);

CREATE TABLE Medications (
   MedicationID INT PRIMARY KEY,
   Name VARCHAR(100),
   Dosage VARCHAR(50),
   Instructions TEXT
);

CREATE TABLE Tests (
   TestID INT PRIMARY KEY,
   Name VARCHAR(100),
   Description TEXT,
   Cost DECIMAL(10, 2)
);

-- Insert data into the tables
INSERT INTO Patients
    (PatientID, Name, DOB, Gender, Contact, Address, Email)
VALUES
    (1, 'John Doe', '1980-01-01', 'M', '1234567890', '123 Main St', 'johndoe@example.com'),
    (2, 'Jane Doe', '1985-02-02', 'F', '1234567895', '124 Main St', 'janedoe@example.com'),
    (3, 'Alice Smith', '1992-03-03', 'F', '1234567896', '125 Main St', 'alicesmith@example.com'),
    (4, 'Bob Johnson', '1993-04-04', 'M', '1234567897', '126 Main St', 'bobjohnson@example.com'),
    (5, 'Charlie Brown', '1994-05-05', 'M', '1234567898', '127 Main St', 'charliebrown@example.com'),
    (6, 'Daisy Johnson', '1995-06-06', 'F', '1234567899', '128 Main St', 'daisyjohnson@example.com');



INSERT INTO Departments
    (DepartmentID, Name)
VALUES
    (1, 'Cardiology'),
    (2, 'Neurology'),
    (3, 'Radiology'),
    (4, 'Orthopedics');


INSERT INTO MedicalStaff
    (StaffID, Name, DOB, Gender, Contact, Address, Role, DepartmentID)
VALUES
    (1, 'Dr. Smith', '1970-01-01', 'M', '0987654321', '456 Main St', 'Cardiologist', 1),
    (2, 'Dr. Sarah', '1980-01-01', 'F', '0987654321', '456 Main St', 'Nurse', 1),
    (3, 'Dr. Lisa Wang', '1990-01-01', 'F', '0987654321', '456 Main St', 'Cardiologist', 1),
    (4, 'Dr. John Doe', '1990-01-01', 'M', '0987654321', '456 Main St', 'Nurse', 1),
    (5, 'Dr. Jane', '1995-02-02', 'F', '0987654325', '457 Main St', 'Nurse', 2),
    (6, 'Dr. Alice', '1996-03-03', 'F', '0987654326', '458 Main St', 'Radiologist', 3),
    (7, 'Dr. Bob', '1997-04-04', 'M', '0987654327', '459 Main St', 'Radiologist', 3),
    (8, 'Dr. Charlie', '1998-05-05', 'M', '0987654328', '460 Main St', 'Orthopedist', 4),
    (9, 'Dr. Daisy', '1999-06-06', 'F', '0987654329', '461 Main St', 'Orthopedist', 4);



INSERT INTO Appointments
    (AppointmentID, PatientID, StaffID, AppointmentDateTime, Status)
VALUES
    (1, 1, 1, '2023-12-01 10:00:00', 'Scheduled') ,
    (2, 2, 5, '2023-12-02 11:00:00', 'Scheduled'),
    (3, 3, 6, '2023-12-03 12:00:00', 'Scheduled'),
    (4, 4, 7, '2023-12-04 13:00:00', 'Scheduled'),
    (5, 5, 8, '2023-12-05 14:00:00', 'Scheduled'),
    (6, 6, 9, '2023-12-06 15:00:00', 'Scheduled');


INSERT INTO MedicalRecords
    (RecordID, PatientID, StaffID, DateOfService, Diagnosis, Treatment)
VALUES
    (1, 1, 1, '2023-11-01', 'High blood pressure', 'Prescribed medication') ,
    (2, 2, 5, '2023-11-02', 'Migraine', 'Prescribed medication'),
    (3, 3, 6, '2023-11-03', 'Broken arm', 'Prescribed medication'),
    (4, 4, 7, '2023-11-04', 'Sprained ankle', 'Prescribed medication'),
    (5, 5, 8, '2023-11-05', 'Broken leg', 'Prescribed medication'),
    (6, 6, 9, '2023-11-06', 'Broken arm', 'Prescribed medication');


INSERT INTO Billing
    (BillingID, PatientID, StaffID, BillingDate, TotalAmount, PaymentStatus)
VALUES
    (1, 1, 1, '2023-11-01', 200.00, 'Paid'),
    (2, 2, 5, '2023-11-02', 300.00, 'Unpaid'),
    (3, 3, 6, '2023-11-03', 400.00, 'Paid'),
    (4, 4, 7, '2023-11-04', 500.00, 'Unpaid');

INSERT INTO Medications
    (MedicationID , Name , Dosage , Instructions )
VALUES
    (1, 'Aspirin', '81 mg', 'Take one tablet daily') ,
    (2, 'Paracetamol', '500 mg', 'Take one tablet every 6 hours'),
    (3, 'Ibuprofen', '200 mg', 'Take one tablet every 4 to 6 hours'),
    (4, 'Acetaminophen', '500 mg', 'Take one tablet every 4 to 6 hours');


INSERT INTO Tests
    (TestID , Name , Description , Cost )
VALUES
    (1, 'Blood Pressure Test', 'A test to measure the pressure in the blood vessels.', '50.00'),
    (2, 'MRI Scan', 'A test to create detailed images of the organs and tissues within the body.', '200.00'),
    (3, 'X-ray', 'A test to create images of the inside of the body.', '100.00'),
    (4, 'Bone Density Test', 'A test to determine the strength of the bones.', '150.00');

-- 1. List all patients
SELECT *
FROM Patients;
-- 2. List all departments
SELECT *
FROM Departments;
-- 3. List all medical staff
SELECT *
FROM MedicalStaff;
-- 4. List all appointments
SELECT *
FROM Appointments;
-- 5. List all medical records
SELECT *
FROM MedicalRecords;
-- 6. List all billing records
SELECT *
FROM Billing;
-- 7. List all medications
SELECT *
FROM Medications;
-- 8. List all tests
SELECT *
FROM Tests;




-- Write sql queries for the following:
-- 1. List female patients whose contact number ends with 5 or 6 and were treated by
-- “dr.sarah”
π Patients.Name, Patients.Contact (
    σ Patients.Gender = 'F' ∧ (Patients.Contact LIKE '%5' OR Patients.Contact LIKE '%6') (
        Patients ⨝ MedicalRecords
    )
)
SELECT *
FROM MedicalStaff
WHERE Role = 'Nurse' AND DATEDIFF(YEAR, DOB, GETDATE()) < 30;
-- 3. Retrieve appointments with a 'Scheduled' status for male patients (ordered by
-- appointment date)
SELECT *
FROM Appointments
INNER JOIN Patients ON Appointments.PatientID = Patients.PatientID
WHERE Patients.Gender = 'M' AND Status = 'Scheduled'
ORDER BY AppointmentDateTime;
-- 4. Retrieve the top 3 most expensive tests along with their descriptions
SELECT TOP 3 Name, Description, Cost
FROM Tests
ORDER BY Cost DESC;
-- 5. Find all appointments scheduled for the future
SELECT *
FROM Appointments
WHERE AppointmentDateTime > GETDATE();
-- 6. List patients who have the same last name as any medical staff (ordered by last
-- name)
SELECT *
FROM Patients
-- here we are using substring to get the last name of the patient and medical staff and charindex to get the index of the space
WHERE SUBSTRING(Patients.Name, CHARINDEX(' ', Patients.Name) + 1, LEN(Patients.Name)) IN (SELECT SUBSTRING(MedicalStaff.Name, CHARINDEX(' ', MedicalStaff.Name) + 1, LEN(MedicalStaff.Name)) FROM MedicalStaff)
ORDER BY SUBSTRING(Patients.Name, CHARINDEX(' ', Patients.Name) + 1, LEN(Patients.Name));

-- 7. Identify Patients Who Haven't Received a Bill
SELECT *
FROM Patients
WHERE PatientID NOT IN (SELECT PatientID FROM Billing);
-- 8. List All Medications and Their Usage Instructions
SELECT *
FROM Medications;
-- 9. Identify Patients Who Haven't Received a Bill
SELECT *
FROM Patients
WHERE PatientID NOT IN (SELECT PatientID FROM Billing);
-- 10. Find Patients Who Have Appointments But No Medical Records
SELECT *
FROM Patients
WHERE PatientID IN (SELECT PatientID FROM Appointments) AND PatientID NOT IN (SELECT PatientID FROM MedicalRecords);
-- 11. Find Patients Who Have Appointments, Medical Records, or Bills
SELECT *
FROM Patients
WHERE PatientID IN (SELECT PatientID FROM Appointments) OR PatientID IN (SELECT PatientID FROM MedicalRecords) OR PatientID IN (SELECT PatientID FROM Billing);
-- 12. Find all patients who have had appointments with doctors in the 'Cardiology'
-- department.
SELECT DISTINCT Patients.*
FROM Patients
INNER JOIN Appointments ON Patients.PatientID = Appointments.PatientID
INNER JOIN MedicalStaff ON Appointments.StaffID = MedicalStaff.StaffID
INNER JOIN Departments ON MedicalStaff.DepartmentID = Departments.DepartmentID
WHERE Departments.Name = 'Cardiology';
-- 13. Find the doctors (medical staff) who have treated patients born after 1990 and
-- have 'Paid' billing status.
SELECT DISTINCT MedicalStaff.*
FROM MedicalStaff
INNER JOIN MedicalRecords ON MedicalStaff.StaffID = MedicalRecords.StaffID
INNER JOIN Patients ON MedicalRecords.PatientID = Patients.PatientID
INNER JOIN Billing ON Patients.PatientID = Billing.PatientID
WHERE Patients.DOB > '1990-01-01' AND Billing.PaymentStatus = 'Paid';
-- 14. List all patients who have either 'Scheduled' or 'Completed' appointments.
SELECT DISTINCT Patients.*
FROM Patients
INNER JOIN Appointments ON Patients.PatientID = Appointments.PatientID
WHERE Appointments.Status IN ('Scheduled', 'Completed');
-- 15. Find all patients who have both a medical record and a billing record.
SELECT *
FROM Patients
WHERE PatientID IN (SELECT PatientID FROM MedicalRecords) AND PatientID IN (SELECT PatientID FROM Billing);
-- 16. Get a list of patients who have undergone the 'X-ray' test or have been treated by
-- 'Dr. Lisa Wang'.
SELECT DISTINCT P.*
FROM Patients P
JOIN Appointments A ON P.PatientID = A.PatientID
LEFT JOIN MedicalStaff MS ON A.StaffID = MS.StaffID
LEFT JOIN MedicalRecords MR ON P.PatientID = MR.PatientID
-- cast the diagnosis as varchar(max) to avoid the error "The data types text and varchar are incompatible in the equal to operator."
LEFT JOIN Tests T ON CAST(MR.Diagnosis AS varchar(max)) = T.Name
WHERE T.Name = 'X-ray' OR MS.Name = 'Dr. Lisa Wang';
-- 17. Find all patients who have had appointments with doctors in every department.
SELECT P.*
FROM Patients P
WHERE P.PatientID IN (
    SELECT DISTINCT A.PatientID
    FROM Appointments A
    JOIN MedicalStaff MS ON A.StaffID = MS.StaffID
    JOIN Departments D ON MS.DepartmentID = D.DepartmentID
    GROUP BY A.PatientID
    HAVING COUNT(DISTINCT D.DepartmentID) = (
        SELECT COUNT(*) FROM Departments
    )
);
-- 18. Find patients who have received at least two different medications, along with the
-- list of medications they have received.
SELECT Patients.Name, Medications.Name AS MedicationName
FROM Patients
INNER JOIN MedicalRecords ON Patients.PatientID = MedicalRecords.PatientID
INNER JOIN Medications ON MedicalRecords.Prescription LIKE '%' + Medications.Name + '%'
GROUP BY Patients.Name, Medications.Name
HAVING COUNT(DISTINCT Medications.Name) >= 2;
-- 19. List the names of patients who have scheduled appointments along with the
-- department they are associated with
SELECT Patients.Name, Departments.Name AS DepartmentName
FROM Patients
INNER JOIN Appointments ON Patients.PatientID = Appointments.PatientID
INNER JOIN MedicalStaff ON Appointments.StaffID = MedicalStaff.StaffID
INNER JOIN Departments ON MedicalStaff.DepartmentID = Departments.DepartmentID
WHERE Appointments.Status = 'Scheduled';
-- 20. Retrieve the names of patients along with their medical records, including
-- diagnosis and treatment, and the names of the doctors who treated them
SELECT Patients.Name AS PatientName, MedicalStaff.Name AS DoctorName, MedicalRecords.Diagnosis, MedicalRecords.Treatment
FROM Patients
INNER JOIN MedicalRecords ON Patients.PatientID = MedicalRecords.PatientID
INNER JOIN MedicalStaff ON MedicalRecords.StaffID = MedicalStaff.StaffID;