use master;
go
drop database if exists psl_db;
go
use master;
go
create database psl_db;
go
use psl_db;
go
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
       (6, 'Sarfaraz Ahmed', 'Pakistan', '1987-05-22', 4),
       (8, 'Shaheen Afridi', 'Pakistan', '2000-04-06', 1),
       (9, 'Mohammad Rizwan', 'Pakistan', '1992-06-01', 2),
       (12, 'Hasan Ali', 'Pakistan', '1994-07-07', 4)

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

-- Question#1

-- i. Create the “MatchResult" table with the appropriate column names and data types.
CREATE TABLE MatchResult (
    match_id INT PRIMARY KEY,
    team1_id INT FOREIGN KEY REFERENCES Team(team_id),
    team2_id INT FOREIGN KEY REFERENCES Team(team_id),
    match_date DATE,
    result VARCHAR(100)
);

-- ii. Add a unique constraint on the combination of match_date, team1_id, and team2_id to ensure no duplicate match records.
ALTER TABLE MatchResult
ADD CONSTRAINT UC_MatchResult UNIQUE (match_date,team1_id,team2_id);

-- iii. Insert a new match result into the "MatchResult" table for a match between team1_id 1, team2_id 2, match_date on '2023-11-03', and result 'Team 1 won by 10 runs'.
INSERT INTO MatchResult(match_id, team1_id, team2_id, match_date, result)
VALUES (1, 1, 2, '2023-11-03', 'Team 1 won by 10 runs');

-- iv. Update the result of the match with match_id 1 to 'Team 1 won by 5 wickets'.
UPDATE MatchResult
SET result = 'Team 1 won by 5 wickets'
WHERE match_id = 1;

-- v. Delete the match with match_id 1 from the "MatchResult" table and then drop the table.
DELETE FROM MatchResult WHERE match_id = 1;
DROP TABLE MatchResult;

-- Question#2

-- i. Retrieve the player names and the total number of runs scored by each player for matches where they played. Display the player names in descending order of the total runs.
SELECT P.player_name, SUM(S.runs) AS total_runs
FROM Player P
JOIN Score S ON P.team_id = S.team_id
GROUP BY P.player_name
ORDER BY total_runs DESC;
-- player_name	total_runs
-- Babar Azam	    345
-- Mohammad Rizwan	345
-- Fakhar Zaman	    327
-- Shadab Khan	    170
-- Shaheen Afridi	170
-- Shahid Afridi	151
-- Hasan Ali	    151
-- Sarfaraz Ahmed	151

-- ii. Retrieve the team names and the total number of matches won by each team. Display the team names in alphabetical order.
SELECT T.team_name, COUNT(M.match_id) AS total_wins
FROM Team T
JOIN Match M ON T.team_id = M.team1_id AND M.result LIKE T.team_name + '%'
GROUP BY T.team_name
ORDER BY T.team_name;
-- team_name	total_wins
-- Lahore Qalandars	1
-- Peshaawar Zalmi	1

-- iii. Retrieve the team names and the average age of players for each team. Display the team names in descending order of average age.
SELECT T.team_name, AVG(DATEDIFF(YEAR, P.date_of_birth, GETDATE())) AS avg_age
FROM Team T
JOIN Player P ON T.team_id = P.team_id
GROUP BY T.team_name
ORDER BY avg_age DESC;
-- team_name	avg_age
-- Peshawar Zalmi	42
-- Multan Sultans	37
-- Lahore Qalandars	34
-- Karachi Kings	31
-- Islamabad United	25

-- Question#3

-- i. Retrieve the names of players who have a total runs scored greater than the average runs scored by all players.
SELECT P.player_name
FROM Player P
JOIN Score S ON P.team_id = S.team_id
GROUP BY P.player_name
HAVING SUM(S.runs) > (SELECT AVG(runs) FROM Score);
-- player_name
-- Babar Azam
-- Fakhar Zaman
-- Mohammad Rizwan
-- Shadab Khan
-- Shaheen Afridi

-- ii. Retrieve the team names and the number of players for each team that have at least one player older than 30 years. Display the team names in alphabetical order.
SELECT T.team_name, COUNT(P.player_id) AS num_players
FROM Team T
JOIN Player P ON T.team_id = P.team_id
WHERE DATEDIFF(YEAR, P.date_of_birth, GETDATE()) > 30
GROUP BY T.team_name
ORDER BY T.team_name;
-- team_name	num_players
-- Karachi Kings	1
-- Lahore Qalandars	1
-- Multan Sultans	2
-- Peshawar Zalmi	1

-- Question#4

-- Create a VIEW named "TopScorers" that provides information about players who have scored 100 or more runs in a single match. The view should display the columns: "Player Name," "Match ID," "Runs Scored".
CREATE VIEW TopScorers AS
SELECT P.player_name AS 'Player Name', S.match_id AS 'Match ID', S.runs AS 'Runs Scored'
FROM Player P
JOIN Score S ON P.team_id = S.team_id
WHERE S.runs >= 100;
go

SELECT * FROM TopScorers;
-- Player Name	Match ID	Runs Scored
-- Shadab Khan	        1	170
-- Shaheen Afridi	    1	170
-- Babar Azam	        1	165
-- Mohammad Rizwan	    1	165
-- Babar Azam	        2	180
-- Mohammad Rizwan	    2	180
-- Fakhar Zaman	        2	172
-- Fakhar Zaman	        3	155
-- Shahid Afridi	    3	151
-- Sarfaraz Ahmed	    3	151
-- Hasan Ali	        3	151
-- Question#5

drop PROCEDURE if exists GetTeamPerformance;
-- Create a STORED PROCEDURE named "GetTeamPerformance" that takes a player name as input and returns the following information in separate output parameters.
CREATE PROCEDURE GetTeamPerformance
    @player_name VARCHAR(100),
    @total_matches INT OUTPUT,
    @matches_won INT OUTPUT,
    @matches_lost INT OUTPUT,
    @total_runs INT OUTPUT,
    @avg_runs DECIMAL(10,2) OUTPUT
AS
BEGIN
    SELECT @total_matches = COUNT(M.match_id)
    FROM Match M
    JOIN Player P ON M.team1_id = P.team_id OR M.team2_id = P.team_id
    WHERE P.player_name = @player_name;

    SELECT @matches_won = COUNT(M.match_id)
    FROM Match M
    JOIN Player P ON M.team1_id = P.team_id
    JOIN Team T ON M.team1_id = T.team_id
    WHERE P.player_name = @player_name AND M.result LIKE T.team_name + '%';

    SELECT @matches_lost = @total_matches - @matches_won;

    SELECT @total_runs = SUM(S.runs)
    FROM Score S
    JOIN Player P ON S.team_id = P.team_id
    WHERE P.player_name = @player_name;

    SET @avg_runs = @total_runs / CAST(@total_matches AS DECIMAL(10,2));
END;
GO

-- Write the execution statement for it as well and show the result.
DECLARE @total_matches INT, @matches_won INT, @matches_lost INT, @total_runs INT, @avg_runs DECIMAL(10,2);
EXEC GetTeamPerformance 'Babar Azam', @total_matches OUTPUT, @matches_won OUTPUT, @matches_lost OUTPUT, @total_runs OUTPUT, @avg_runs OUTPUT;
SELECT @total_matches AS Total_Matches, @matches_won AS Matches_Won, @matches_lost AS Matches_Lost, @total_runs AS Total_Runs, @avg_runs AS Average_Runs;
-- TOTAL_MATCHES	MATCHES_WON	MATCHES_LOST	TOTAL_RUNS	AVERAGE_RUNS
-- 2	            0	        2	            345	        172.50

-- Scenario:
-- Let's say we want to update the Score table with the runs scored by a player in a match. However, we want to ensure that the total runs scored by a team in a match do not exceed a certain limit (say 500 runs). We also want to keep a log of all updates made to the Score table.
-- Transactions:
-- We can use transactions to ensure that the total runs scored by a team in a match do not exceed 500. If an update operation causes the total runs to exceed 500, we can rollback the transaction.

BEGIN TRANSACTION;
UPDATE Score
SET runs = runs + 50
WHERE match_id = 1 AND team_id = 1;

IF (SELECT SUM(runs) FROM Score WHERE match_id = 1 AND team_id = 1) > 500
    ROLLBACK TRANSACTION;
ELSE
    COMMIT TRANSACTION;

-- -- Triggers:
-- We can use triggers to keep a log of all updates made to the Score table. We can create a new table ScoreUpdateLog to store this log.

CREATE TABLE ScoreUpdateLog (
    log_id INT PRIMARY KEY IDENTITY,
    score_id INT,
    old_runs INT,
    new_runs INT,
    update_date DATETIME
);
GO

CREATE TRIGGER trg_UpdateScore
ON Score
AFTER UPDATE
AS
BEGIN
    INSERT INTO ScoreUpdateLog(score_id, old_runs, new_runs, update_date)
    SELECT d.score_id, d.runs, i.runs, GETDATE()
    FROM deleted d
    INNER JOIN inserted i ON d.score_id = i.score_id;
END;
go

SELECT * FROM ScoreUpdateLog;
-- log_id	score_id	old_runs	new_runs	update_date
-- 1	    1	        220	        270	        2024-01-06 17:46:56.033
-- 2	    1	        270	        320	        2024-01-06 17:46:57.957
-- 3	    1	        320	        370	        2024-01-06 17:46:58.397
-- 4	    1	        370	        420	        2024-01-06 17:46:58.747
-- 5	    1	        420	        470	        2024-01-06 17:46:59.167
