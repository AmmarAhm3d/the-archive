-- Questions: 1-15
-- Write SQL and RA to answer the following queries
-- Consider the following relational database for the Super Baseball League. It keeps track of
-- teams in the league, coaches and players on the teams, work experience of the coaches, bats
-- belonging to each team, and which players have played on which teams. Note the following
-- facts about this environment:
-- • The database keeps track of the history of all of the teams that each player has played on
-- and all of the players who have played on each team.
-- • The database only keeps track of the current team that a coach works for.
-- • Team number, team name, and player number are each unique attribute across the league.
-- • Coach name is only unique within a team (and we assume that a team cannot have two
-- coaches of the same name.)
-- • Serial number (for bats) is only unique within a team.
-- • In the Affiliation table, the Years attribute indicates that number of years that a player
-- played on a team; the batting average is for the years that a player played on a team.

CREATE DATABASE SuperBaseballLeague;
USE SuperBaseballLeague;

-- create Team table
CREATE TABLE Team
(
    TeamNumber INTEGER ,
    TeamName VARCHAR(20),
    City VARCHAR(20),
    Manager VARCHAR(20),
    PRIMARY KEY(TeamNumber)
);

-- create Coach table
CREATE TABLE Coach
(
    CoachName VARCHAR(20) NOT NULL,
    TeamNumber INTEGER,
    PRIMARY KEY(CoachName),
    FOREIGN KEY(TeamNumber) REFERENCES Team(TeamNumber)
);

-- create WORKEXPERIENCE table
CREATE TABLE WORKEXPERIENCE
(
    CoachName VARCHAR(20),
    TeamNumber INTEGER,
    YEARSEXPERIENCE INTEGER NOT NULL,
    EXPERIENCETYPE VARCHAR(20) NOT NULL,
    FOREIGN KEY(CoachName) REFERENCES Coach(CoachName),
    FOREIGN KEY (TeamNumber) REFERENCES Team(TeamNumber)
);

-- create Bat table
CREATE TABLE Bat
(
    SerialNumber INTEGER PRIMARY KEY,
    Manufacturer VARCHAR(20) NOT NULL,
    TeamNumber INTEGER NOT NULL,
    FOREIGN KEY(TeamNumber) REFERENCES Team(TeamNumber)
);

-- create Player table
CREATE TABLE Player
(
    PlayerNumber INTEGER,
    PlayerName VARCHAR(20) PRIMARY KEY,
    Age INTEGER NOT NULL
);

-- create Affiliation table
CREATE TABLE Affiliation
(
    PlayerName VARCHAR(20),
    TeamNumber INTEGER,
    Years INTEGER NOT NULL,
    BattingAverage FLOAT NOT NULL,
    COACHNAME VARCHAR(20),
    FOREIGN KEY(PlayerName) REFERENCES Player(PlayerName),
    FOREIGN KEY(TeamNumber) REFERENCES Team(TeamNumber),
    FOREIGN KEY(CoachName) REFERENCES Coach(CoachName)
);

-- drop TABLE Team;
-- drop TABLE Coach;
-- drop TABLE WORKEXPERIENCE;
-- drop TABLE Bat;
-- drop TABLE Player
-- drop table Affiliation;

INSERT INTO Team (TeamNumber, TeamName, City, Manager) VALUES
(1, 'Lakers', 'Los Angeles', 'Frank Vogel'),
(2, 'Warriors', 'San Francisco', 'Steve Kerr'),
(3, 'Nets', 'Brooklyn', 'Steve Nash'),
(4,'Royals', 'Kansas City', 'Mike Matheny'),
(5, 'Rangers', 'Texas', 'Chris Woodward'),
(6, 'Red Sox', 'Boston', 'Alex Cora'),
(7, 'Yankees', 'New York', 'Aaron Boone'),
(8, 'Blue Jays', 'Toronto', 'Charlie Montoyo'),
(9, 'Orioles', 'Baltimore', 'Brandon Hyde'),
(10, 'Twins', 'Minnesota', 'Rocco Baldelli'),
(11, 'White Sox', 'Chicago', 'Rick Renteria'),
(12, 'Indians', 'Cleveland', 'Terry Francona'),
(13, 'Tigers', 'Detroit', 'Ron Gardenhire'),
(14, 'Astros', 'Houston', 'A.J. Hinch'),
(15, 'Rays', 'Tampa Bay', 'Kevin Cash'),
(16, 'Mariners', 'Seattle', 'Scott Servais'),
(17, 'Angels', 'Anaheim', 'Joe Maddon'),
(18, 'Athletics', 'Oakland', 'Bob Melvin'),
(19, 'Braves', 'Atlanta', 'Brian Snitker'),
(20, 'Cubs', 'Chicago', 'David Ross'),
(21, 'Reds', 'Cincinnati', 'David Bell'),
(22, 'Mets', 'New York', 'Carlo Espinosa'),
(23, 'Phillies', 'Philadelphia', 'Joe Girardi'),
(24, 'Pirates', 'Pittsburgh', 'Derek Shelton'),
(25, 'Cardinals', 'St. Louis', 'Mike Shildt'),
(26, 'Brewers', 'Milwaukee', 'Craig Counsell'),
(27, 'Marlins', 'Miami', 'Don Mattingly'),
(28, 'Nationals', 'Washington', 'Dave Martinez'),
(29, 'Diamondbacks', 'Arizona', 'Torey Lovullo'),
(30, 'Rockies', 'Colorado', 'Bud Black'),
(31, 'Padres', 'San Diego', 'Jayce Tingler'),
(32, 'Giants', 'San Francisco', 'Gabe Kapler');

INSERT INTO Coach (CoachName, TeamNumber) VALUES
('Waqar', 10),
('Frank Vogel', 1),
('Steve Kerr', 2),
('Mike Brown', 2),
('Jacque Vaughn', 3),
('Mike D`Antoni', 4),
('Billy Donovan', 5),
('John Farrell', 6),
('Aaron Boone', 7),
('Charlie Montoyo', 8),
('Brandon Hyde', 9),
('Rocco Baldelli', 10),
('Rick Renteria', 11),
('Terry Francona', 12),
('Ron Gardenhire', 13),
('A.J. Hinch', 14),
('Kevin Cash', 15),
('Scott Servais', 16),
('Joe Maddon', 17),
('Bob Melvin', 18),
('Brian Snitker', 19),
('David Ross', 20),
('David Bell', 21),
('Carlo Espinosa', 22),
('Joe Girardi', 23),
('Derek Shelton', 24),
('Mike Shildt', 25),
('Craig Counsell', 26),
('Don Mattingly', 27),
('Dave Martinez', 28),
('Torey Lovullo', 29),
('Bud Black', 30),
('Jayce Tingler', 31),
('Gabe Kapler', 32);

INSERT INTO WORKEXPERIENCE (CoachName, TeamNumber, YEARSEXPERIENCE, EXPERIENCETYPE) VALUES
('Frank Vogel', 1, 10, 'Univeristy'),
('Steve Kerr', 2, 7, 'Univeristy'),
('Mike Brown', 2, 15, 'College'),
('Jacque Vaughn', 3, 8, 'College'),
('Mike D`Antoni', 4, 10, 'College'),
('Billy Donovan', 5, 10, 'College'),
('John Farrell', 6, 10, 'College'),
('Aaron Boone', 7, 10, 'College'),
('Charlie Montoyo', 8, 10, 'College'),
('Brandon Hyde', 9, 10, 'College'),
('Rocco Baldelli', 10, 10, 'College'),
('Rick Renteria', 11, 10, 'College'),
('Terry Francona', 12, 10, 'College'),
('Ron Gardenhire', 13, 10, 'College'),
('A.J. Hinch', 14, 10, 'College'),
('Kevin Cash', 15, 10, 'College'),
('Scott Servais', 16, 10, 'College'),
('Joe Maddon', 17, 10, 'College'),
('Bob Melvin', 18, 10, 'College'),
('Brian Snitker', 19, 10, 'College'),
('David Ross', 20, 10, 'College'),
('David Bell', 21, 10, 'College'),
('Carlo Espinosa', 22, 10, 'College'),
('Joe Girardi', 23, 10, 'College'),
('Derek Shelton', 24, 10, 'College'),
('Mike Shildt', 25, 10, 'College'),
('Craig Counsell', 26, 10, 'College'),
('Don Mattingly', 27, 10, 'College'),
('Dave Martinez', 28, 10, 'College'),
('Torey Lovullo', 29, 10, 'College'),
('Bud Black', 30, 10, 'College'),
('Jayce Tingler', 31, 10, 'College'),
('Gabe Kapler', 32, 10, 'College');

INSERT INTO Bat (SerialNumber, Manufacturer, TeamNumber) VALUES
(101, 'Rawlings', 1),
(102, 'Wilson', 2),
(103, 'Easton', 3),
(104, 'Louisville Slugger', 4),
(105, 'DeMarini', 5),
(106, 'Mizuno', 6),
(107, 'Marucci', 7),
(108, 'Rawlings', 8),
(109, 'Wilson', 9),
(110, 'Easton', 10),
(111, 'Louisville Slugger', 11),
(112, 'DeMarini', 12),
(113, 'Mizuno', 13),
(114, 'Marucci', 14),
(115, 'Rawlings', 15),
(116, 'Wilson', 16),
(117, 'Easton', 17),
(118, 'Louisville Slugger', 18),
(119, 'DeMarini', 19),
(120, 'Mizuno', 20),
(121, 'Marucci', 21),
(122, 'Rawlings', 22),
(123, 'Wilson', 23),
(124, 'Easton', 24),
(125, 'Louisville Slugger', 25),
(126, 'DeMarini', 26),
(127, 'Mizuno', 27),
(128, 'Marucci', 28),
(129, 'Rawlings', 29),
(130, 'Wilson', 30),
(131, 'Easton', 31),
(132, 'Louisville Slugger', 32);

INSERT INTO Player (PlayerNumber, PlayerName, Age) VALUES
(1, 'LeBron James', 37),
(2, 'Stephen Curry', 33),
(3, 'Kevin Durant', 32),
(4, 'Yasir Riaz', 16),
(5, 'Kevin Cash', 69);

INSERT INTO Affiliation (PlayerName, TeamNumber, Years, BattingAverage, COACHNAME) VALUES
('LeBron James', 1, 10, 0.5, 'Frank Vogel'),
('Stephen Curry', 2, 10, 0.5, 'Steve Kerr'),
('Kevin Durant', 3, 10, 0.5, 'Mike Brown'),
('Yasir Riaz', 4, 10, 0.5, 'Jacque Vaughn'),
('Kevin Cash', 5, 10, 0.5, 'Mike D`Antoni');

-- 1. Find the names and city of all the team with team number greater than 15. List the
-- results alphabetically by team name.
 
SELECT TeamName, City
FROM Team
WHERE TeamNumber > 15
ORDER BY TeamName;
 

-- 2. Display the name of player who are under 18.(5 points)
 
SELECT PlayerName
FROM Player
WHERE Age < 18;

-- 3. List all of the coaches whose last names begin with 'R' and who have between 5 and
-- 10 years of experience as college coaches (see YEARSEXPERIENCE and
-- EXPERIENCETYPE). (5 points)
 
SELECT Coach.CoachName
FROM Coach
JOIN WORKEXPERIENCE ON Coach.CoachName = WORKEXPERIENCE.CoachName
WHERE Coach.CoachName LIKE '%R%' AND WORKEXPERIENCE.YEARSEXPERIENCE BETWEEN 5 AND 10 AND
WORKEXPERIENCE.EXPERIENCETYPE = 'College';

-- 4. Find the total number of years of experience of Coach Waqar on team number 25. (5
-- points)
 
SELECT SUM(WORKEXPERIENCE.YEARSEXPERIENCE)
FROM Coach, Affiliation, WORKEXPERIENCE
WHERE (Coach.CoachName = Affiliation.CoachName AND Coach.TeamNumber = 25 AND
    Coach.CoachName = 'Waqar');

-- 5. Find the number of different types of experience that Coach Waqar on team number 3
-- has. (5 points)
 
SELECT COUNT(DISTINCT WORKEXPERIENCE.EXPERIENCETYPE)
FROM Coach, Affiliation, WORKEXPERIENCE
WHERE (Coach.CoachName = Affiliation.CoachName AND Coach.TeamNumber = 3 AND
    Coach.CoachName = 'Waqar');

-- 6. Find the total number of years of experience of each coach on team number 3. (5
-- points)
 
SELECT Coach.CoachName, SUM(WORKEXPERIENCE.YEARSEXPERIENCE) AS TotalExperience
FROM Coach, Affiliation, WORKEXPERIENCE
WHERE (Coach.CoachName = Affiliation.CoachName AND Coach.TeamNumber = 3 AND
    Coach.CoachName = WORKEXPERIENCE.CoachName)
GROUP BY Coach.CoachName;

-- 7. How many different manufacturers make bats for the league's teams'(5 points)
 
SELECT COUNT(DISTINCT Manufacturer)
FROM Bat;

-- 8. Assume that team names are unique. Find the names of the players who have played
-- for the Yankees for at least five years (see YEARS in the AFFILIATION Table.) (10
-- points)
 
SELECT Player.PlayerName
FROM Player
    JOIN Affiliation
    ON Player.PlayerName = Affiliation.PlayerName
WHERE Affiliation.TeamNumber = (SELECT TeamNumber FROM Team WHERE TeamName = 'Yankees')

-- 9. Assume that team names are unique. Find the total number of years of work
-- experience of each coach on the Royals, but only include in the result those coaches
-- who have more than eight years of experience. (5 points)
 
SELECT Coach.CoachName, SUM(WORKEXPERIENCE.YEARSEXPERIENCE) AS TotalExperience
FROM Coach, Affiliation, WORKEXPERIENCE
WHERE (Coach.CoachName = Affiliation.CoachName AND Coach.TeamNumber = (SELECT
    TeamNumber FROM Team WHERE TeamName = 'Royals') AND Coach.CoachName =
    WORKEXPERIENCE.CoachName AND WORKEXPERIENCE.YEARSEXPERIENCE > 8)
GROUP BY Coach.CoachName

-- 10. Find the names of the league's youngest players. (5 points)
 
SELECT PlayerName
FROM Player
WHERE Age = (SELECT MIN(Age) FROM Player);

-- 11. Find the names of the league's youngest players whose last names begin with the
-- letter 'M'. (5 points)
 
SELECT PlayerName
FROM Player
WHERE Age = (SELECT MIN(Age) FROM Player) AND PlayerName LIKE 'M%';

-- 12. Find the name of player who have been affiliated with more than two teams. (5
-- points)

SELECT PlayerName 
FROM Affiliation
GROUP BY PlayerName
HAVING COUNT(DISTINCT TeamNumber) > 2;


-- 13. Find the player who are not affiliated with any team. (5 points)

SELECT PlayerName
FROM Player
WHERE PlayerName NOT IN (SELECT PlayerName FROM Affiliation);

-- 14. For each player find the number of team they have been affiliated with in the career.
-- (5 points)

SELECT PlayerName, COUNT(DISTINCT TeamNumber) AS AffiliatedTeams
FROM Affiliation
GROUP BY PlayerName;

-- 15. For each team list every batting average(5 points)
 
SELECT TeamName, BattingAverage
FROM Affiliation
INNER JOIN Team ON Affiliation.TeamNumber = Team.TeamNumber;