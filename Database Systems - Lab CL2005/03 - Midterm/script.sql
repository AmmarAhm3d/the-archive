---------------------------------------------------
---------------DATABASE SYSTEMS--------------------
--------------------MIDTERM------------------------
---------------------------------------------------
--create database psl_db;
--use psl_db;

-- Team table
CREATE TABLE Team (
    team_id INT PRIMARY KEY,
    team_name VARCHAR(100),
    team_logo VARCHAR(100),
    home_city VARCHAR(100)
);

-- Player table
CREATE TABLE Player (
    player_id INT PRIMARY KEY,
    player_name VARCHAR(100),
    nationality VARCHAR(100),
    date_of_birth DATE,
    team_id INT FOREIGN KEY REFERENCES Team(team_id)
);

-- Venue table
CREATE TABLE Venue (
    venue_id INT PRIMARY KEY,
    venue_name VARCHAR(100),
    city VARCHAR(100),
    capacity INT
);

-- Match table
CREATE TABLE Match (
    match_id INT PRIMARY KEY,
    team1_id INT FOREIGN KEY REFERENCES Team(team_id),
    team2_id INT FOREIGN KEY REFERENCES Team(team_id),
    match_date DATE,
    venue_id INT FOREIGN KEY REFERENCES Venue(venue_id),
    result VARCHAR(100)
);

-- Score table
CREATE TABLE Score (
    score_id INT PRIMARY KEY,
    match_id INT FOREIGN KEY REFERENCES Match(match_id),
    team_id INT FOREIGN KEY REFERENCES Team(team_id),
    runs INT,
    wickets INT,
    overs DECIMAL(4, 2)
);

-- Inserting entries into the Team table
INSERT INTO Team (team_id, team_name, team_logo, home_city)
VALUES (1, 'Islamabad United', 'islamabad_logo.png', 'Islamabad'),
       (2, 'Karachi Kings', 'karachi_logo.png', 'Karachi'),
       (3, 'Lahore Qalandars', 'lahore_logo.png', 'Lahore'),
       (4, 'Multan Sultans', 'multan_logo.png', 'Multan'),
       (5, 'Peshawar Zalmi', 'peshawar_logo.png', 'Peshawar'),
       (6, 'Quetta Gladiators', 'quetta_logo.png', 'Quetta');

-- Inserting entries into the Player table
INSERT INTO Player (player_id, player_name, nationality, date_of_birth, team_id)
VALUES (1, 'Shadab Khan', 'Pakistan', '1998-10-29', 1),
       (2, 'Babar Azam', 'Pakistan', '1994-10-15', 2),
       (3, 'Fakhar Zaman', 'Pakistan', '1990-04-10', 3),
       (4, 'Shahid Afridi', 'Pakistan', '1980-03-01', 4),
       (5, 'Kamran Akmal', 'Pakistan', '1982-01-13', 5),
       (6, 'Sarfaraz Ahmed', 'Pakistan', '1987-05-22', 6),
	   (8, 'Shaheen Afridi', 'Pakistan', '2000-04-06', 1),
       (9, 'Mohammad Rizwan', 'Pakistan', '1992-06-01', 2),
       (12, 'Hasan Ali', 'Pakistan', '1994-07-07', 3)

-- Inserting entries into the Venue table
INSERT INTO Venue (venue_id, venue_name, city, capacity)
VALUES (1, 'National Stadium', 'Karachi', 35000),
       (2, 'Gaddafi Stadium', 'Lahore', 27000),
       (3, 'Multan Cricket Stadium', 'Multan', 25000),
       (4, 'Rawalpindi Cricket Stadium', 'Rawalpindi', 28000),
       (5, 'Bugti Stadium', 'Quetta', 20000)

-- Inserting entries into the Match table
INSERT INTO Match (match_id, team1_id, team2_id, match_date, venue_id, result)
VALUES (1, 1, 2, '2023-02-10', 1, 'Karachi Kings won by 5 wickets'),
       (2, 2, 3, '2023-02-12', 2, 'Lahore Qalandars won by 8 runs'),
       (3, 3, 4, '2023-02-15', 3, 'Lahore Qalandars won by 4 wickets'),
       (4, 4, 5, '2023-02-18', 4, 'Match abandoned due to rain'),
       (5, 5, 6, '2023-02-20', 5, 'Peshawar Zalmi won by 7 wickets')

-- Inserting entries into the Score table
INSERT INTO Score (score_id, match_id, team_id, runs, wickets, overs)
VALUES (1, 1, 1, 170, 5, 19.2),
       (2, 1, 2, 165, 6, 20),
       (3, 2, 2, 180, 7, 20),
       (4, 2, 3, 172, 9, 20),
       (5, 3, 3, 155, 6, 18.3),
       (6, 3, 4, 151, 8, 20)