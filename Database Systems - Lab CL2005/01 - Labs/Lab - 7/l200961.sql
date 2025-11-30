use master
go
drop  database ATM
go 
Create database ATM
go 
use ATM
go

create table [User](
[userId] int primary key,
[name] varchar(20) not null,
[phoneNum] varchar(15) not null,
[city] varchar(20) not null
)
go

create table CardType(
[cardTypeID] int primary key,
[name] varchar(15),
[description] varchar(40) null
)
go
create Table [Card](
cardNum Varchar(20) primary key,
cardTypeID int foreign key references  CardType([cardTypeID]),
PIN varchar(4) not null,
[expireDate] date not null,
balance float not null
)
go


Create table UserCard(
userID int foreign key references [User]([userId]),
cardNum varchar(20) foreign key references [Card](cardNum),
primary key(cardNum)
)
go
create table [Transaction](
transId int primary key,
transDate date not null,
cardNum varchar(20) foreign key references [Card](cardNum),
amount int not null
)

CREATE TABLE [UserType](
    [userTypeID] INT NOT NULL REFERENCES [User]([userId]),
    [name] VARCHAR(20) NOT NULL REFERENCES [User]([name])
)

GO

INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')
GO


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
GO
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')
GO

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)
GO

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
GO
Insert  [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)
GO


Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]
SELECT * FROM [UserType] 

-- lab tasks
-- 1- Create a view to display all the details of each user.
CREATE VIEW [part1] AS 
SELECT * FROM [User];

-- 2- Create a view that displays the name, phone number, city, and cardNum of each user who owns
-- ATM card.
CREATE VIEW [Part2] AS
SELECT [User].name, [User].phoneNum, [User].city, UserCard.cardNum
FROM [User]
INNER JOIN UserCard ON [User].userId = UserCard.userID;

-- 3- Create a procedure that takes the user's name and displays his details.
CREATE PROCEDURE dbo.[displayDetails] @name varchar(20)
AS
SELECT * FROM [User] WHERE name = @name;

EXEC dbo.[displayDetails] 'Ali';

-- 4- Create a procedure that returns minimum balance in an output parameter.
CREATE PROCEDURE dbo.[minBalance] @minBalance int OUTPUT
AS
SELECT @minBalance = MIN(balance) FROM [Card];

DECLARE @minBalance int;
EXEC dbo.[minBalance] @minBalance OUTPUT;
SELECT @minBalance;
GO

-- 5- Create a procedure that takes user name, id and returns no. of cards of that user in an output
-- parameter.
CREATE PROCEDURE dbo.[noOfCards] @username varchar(20), @id int, @noOfCards int OUTPUT
AS
SELECT @noOfCards = COUNT(cardNum) FROM UserCard
INNER JOIN [User] ON UserCard.userID = [User].userId
WHERE [User].name = @username AND [User].userId = @id;

DECLARE @noOfCards int, @username varchar(20), @id int;
SET @username = 'Ali';
SET @id = 1;
EXEC dbo.[noOfCards] @username, @id, @noOfCards OUTPUT;
SELECT @noOfCards;
GO

-- 6- Create a procedure Login that takes card number, PIN, and returns the status in an output
-- parameter. If card number and PIN are valid then @status =1 else @status=0.
-- (Hint: IF/ELSE).
CREATE PROCEDURE dbo.[Login] @cardNum varchar(20), @PIN varchar(20), @status int OUTPUT
AS
IF EXISTS (SELECT * FROM [Card] WHERE cardNum = @cardNum AND PIN = @PIN)
BEGIN
    SET @status = 1;
END
ELSE
BEGIN
    SET @status = 0;
END;

DECLARE @status int, @cardNum varchar(20), @PIN varchar(20);
SET @cardNum = '1234';
SET @PIN = '1770';
EXEC dbo.[Login] @cardNum, @PIN, @status OUTPUT;
SELECT @status;
GO

-- 7- Create a procedure to update the PIN. The procedure takes Card Number, old PIN, and new Valid
-- PIN (Length 4) and prints ‘Updated PIN’ if PIN gets updated or ‘Error’ otherwise.
-- (Google it if you don’t know how to compare the Length).
CREATE PROCEDURE dbo.[updatePIN] @cardNum varchar(20), @oldPIN varchar(20), @newvalPIN varchar(20)
AS
IF EXISTS (SELECT * FROM [Card] WHERE cardNum = @cardNum AND PIN = @oldPIN)
BEGIN
    IF LEN(@newvalPIN) = 4
    BEGIN
        UPDATE [Card] SET PIN = @newvalPIN WHERE cardNum = @cardNum;
        PRINT 'Updated PIN';
    END
    ELSE
    BEGIN
        PRINT 'Error';
    END
END
ELSE
BEGIN
    PRINT 'Error';
END;

EXEC dbo.[updatePIN] '1234', '1770', '1234';
GO

-- 8- Create a procedure WithDraw using Login Procedure (Question#6), the procedure will take the
-- Card Number, PIN, and amount for the transaction. Now insert detail of the transaction in
-- Transaction Table if the transaction is successful with TransType =1(successful Transaction) and
-- next transID (calculate the max transID and increment transID, then insert in table). If the
-- transaction fails insert TransType=4 (Failed Transaction). Update the balance against the card
-- number accordingly.
CREATE PROCEDURE dbo.[WithDraw] @cardNum varchar(20), @PIN varchar(20), @amount int
AS
DECLARE @status int;
EXEC dbo.[Login] @cardNum, @PIN, @status OUTPUT;
IF @status = 1
BEGIN
    DECLARE @balance int;
    SELECT @balance = balance FROM [Card] WHERE cardNum = @cardNum;
    IF @balance >= @amount
    BEGIN
        DECLARE @trans1ID int;
        SELECT @trans1ID = MAX(transId) FROM [Transaction];
        SET @trans1ID = @trans1ID + 1;
        INSERT INTO [Transaction] (transId, transDate, cardNum, amount) VALUES (@trans1ID, GETDATE(), @cardNum, @amount);
        UPDATE [Card] SET balance = balance - @amount WHERE cardNum = @cardNum;
        PRINT 'Transaction Successful';
    END
    ELSE
    BEGIN
        DECLARE @transID int;
        SELECT @transID = MAX(transId) FROM [Transaction];
        SET @transID = @transID + 1;
        INSERT INTO [Transaction] (transId, transDate, cardNum, amount) VALUES (@transID, GETDATE(), @cardNum, @amount);
        PRINT 'Transaction Failed';
    END
END
ELSE
BEGIN
    PRINT 'Transaction Failed';
END;

EXEC dbo.[WithDraw] '1234', '1770', 1000;
GO