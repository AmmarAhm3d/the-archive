create database inLab8Practice
use inLab8Practice
-- use master
-- drop database if exists inLab8Practice
go
create table vehicle
(
vehicle_id varchar(10) Primary key,
engine_no varchar(10),
chassis_no varchar(10),
horsepower int,
company varchar(10),
model_no varchar(10),
make varchar(10),
price int,
typevehicle int-- four wheel or two wheel drive
)
go
create table dealer
(
dccname varchar(20),
d_id varchar(10) primary key ,
d_address varchar(250),
d_cnic varchar(15) not null unique,
contact varchar(20)
)
go
--drop table dealer
create table customer
(
cccname varchar(10),
c_id varchar(10) primary key,
c_address varchar(250),
c_cnic varchar(15) not null unique,
contact varchar(20)
)
go
go
create table inventory
(
modelno varchar(10),
make varchar(10),
company varchar(10),
articles_available int
primary key(modelno, make, company)
)
go
go
--drop table inventory
create table deals
(
v_id varchar(10) foreign key references vehicle (vehicle_id),
c_id varchar(10) foreign key references customer(c_id),
d_id varchar(10) foreign key references dealer(d_id),
payment_mode varchar(4),
payment_plan varchar(10),
paid int,
left_amount int,
date_deal date
)
go
go
create table orders
(
c_id varchar(10) foreign key references customer(c_id),
d_id varchar(10) foreign key references dealer(d_id),
make varchar(10),-- foreign key references inventory(make),
company varchar(10),-- foreign key references inventory(company),
model varchar(10), --foreign key references inventory (model)
dateorder date,-- date of order
status_order int,--1 for complete 0 for pending
date_completeion date
)
go
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12X3456789','1234567890',
'xx22335588',50,'toyota', '06', 'corolla', 1600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12Y3466789','1234876090',
'xx22315598',50,'toyota', '06', 'corolla', 1600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12Y3466889','0123658974',
'xx22315593',50,'daihatsu', '06', 'lala', 600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12A3456889','0123690974',
'wa22315593',50,'suzuki', '12', 'car', 600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12A3456877','0123770974',
'wa22315598',50,'suzuki', '15', 'car', 650000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12J3456889','0123690974',
'wa22313693',50,'hyundai', '17', 'small car', 800000,2)
------------------------------------------------------

insert into dealer (dccname ,d_id ,d_address ,d_cnic ,contact ) values('asif','d123xyzbbb', 'Islamabad', '12345-1234567-1','03001234567')
insert into dealer (dccname ,d_id ,d_address ,d_cnic ,contact ) values('zahid','d224xyzbbb', 'Lahore', '13345-1234367-1','03001254567')
insert into dealer (dccname ,d_id ,d_address ,d_cnic ,contact ) values('khalid','d123xyzbab', 'Karachi', '12345-1234568-1','03001294567')
insert into dealer (dccname ,d_id ,d_address ,d_cnic ,contact ) values('khursheed','d789xyzbbb', 'Peshawar', '54321-1234567-1','03009876543')
------------------------------------------------------

insert into customer (cccname ,c_id ,c_address ,c_cnic ,contact ) values ('kashif','c123xyzlal','Islamabad','35351-8906751-0','03111234567')
insert into customer (cccname ,c_id ,c_address ,c_cnic ,contact ) values ('rehman','c123xyzjix','Karachi','35351-8906720-1','03111233767')
insert into customer (cccname ,c_id ,c_address ,c_cnic ,contact ) values ('habib','c123xyzlbl','Lahore','38351-9906751-0','03211236567')
insert into customer (cccname ,c_id ,c_address ,c_cnic ,contact ) values ('farhan','c123xyzkal','Peshawar','35351-5906951-2','03131234567')
------------------------------------------------------
insert into inventory (modelno,make ,company ,articles_available ) values (15,'car','suzuki',20)
insert into inventory (modelno,make ,company ,articles_available ) values (12,'car','suzuki',35)
insert into inventory (modelno,make ,company ,articles_available ) values (06,'lala','daihatsu',0)
insert into inventory (modelno,make ,company ,articles_available ) values (17,'small car','hyundai',3)
insert into inventory (modelno,make ,company ,articles_available ) values (06,'lala','daihatsu',0)
--update inventory set modelno=17 where make ='small car'
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12A3456877','c123xyzjix','d123xyzbab','card','immediate',650000,0 ,'01/23/2017')
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12J3456889','c123xyzlbl','d224xyzbbb','cash','install',500000,300000 ,'01/23/2017')
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12Y3466789','c123xyzkal','d789xyzbbb','cash','immediate',1600000,0 ,'05/03/2015')
--truncate  table deals
insert into orders (c_id ,d_id ,make ,company,model , dateorder,status_order ,date_completeion ) values ('c123xyzjix','d123xyzbab','car','suzuki','12','10/02/2017',1,'10/02/2017')
insert into orders (c_id ,d_id ,make ,company,model , dateorder,status_order ,date_completeion ) values ('c123xyzlbl','d224xyzbbb','lala','daihatsu','6','09/02/2017',0,'09/02/2017')
select * from vehicle
select * from customer
select * from dealer
select * from inventory
select * from deals
update vehicle set typevehicle = 4 where chassis_no='xx22315593'

create trigger the_trigger
after insert
as begin
print 'your data has been inserted '
end

insert Into customer (cccname, c_id, c_address, c_cnic, contact) values('talha', 'c168fghjas', 'Lalamusa','35676-0957654-2' , '03213221234 ')

create trigger the_del_trig
on customer
instead of delete
as begin
print 'you can not deletethis data'
end

delete from customer where c_id='c168fghjas'

-- Example: Whenever a customer is inserted in, it should automatically convert that cccname of that
-- instructor in Upper Case.
-- For example: customer with cccname "ali ahmed" should be inserted as "ALI AHMED"
CREATE TRIGGER tr_customer
AFTER INSERT
AS
BEGIN
UPDATE customer SET cccname = UPPER(cccname)
END

INSERT INTO customer (cccname, c_id, c_address, c_cnic, contact) VALUES ('ali ahmed', 'abcdefg', 'Lalamusa','465465464646' , '03213221234 ')

Create Trigger ForTriggerForInsertCustomer
On customer
For Insert
AS
Begin
declare @c_id varchar(2),
@cccname varchar(30),
@c_address varchar(3),
@contact varchar(11),
@c_cnic varchar(15)
Select @c_id= Inserted.c_id, @cccname=Inserted.cccname, @c_address=Inserted.c_address,
@contact= Inserted.contact, @c_cnic=Inserted.c_cnic
From Inserted
print ('New Customer Inserted whose c_id is '+@c_id+'. cccname is '+@cccname+'. c_address is
'+@c_address+'. contact is '+@contact+'.')
End
-- Inserting a new row into the table
Insert into customer(c_id, cccname, c_address,c_cnic , contact)
 values('C0', 'Ali', 'Lhr','12345', '12345')

Create Trigger ForTriggerForDeleteCustomer
On customer
For Delete
AS
Begin
declare @c_id varchar(2),
@cccname varchar(30),
@c_address varchar(3),
@contact varchar(11)
Select @c_id= Deleted.c_id,
@cccname=Deleted.cccname,
@c_address=Deleted.c_address,
@contact= Deleted.contact
From Deleted
print ('A Customer deleted whose c_id is '+@c_id+'. cccname is '+@cccname+'. c_address
is '+@c_address+'. contact is '+@contact+'.
')
End

DROP TRIGGER the_del_trig
-- Deleting a row from the table
Delete From customer
where c_id='C0'

Create Trigger ForTriggerForUpdateCustomer
On customer
For Update
AS
Begin
declare @oldCustomerNo varchar(2),
@oldName varchar(30),
@oldCity varchar(3),
@oldPhone varchar(11),
@newCustomerNo varchar(2),
@newName varchar(30),
@newCity varchar(3),
@newPhone varchar(11)
Select @oldCustomerNo= Deleted.c_id,
@oldName=Deleted.cccname,
@oldCity=Deleted.c_address,
@oldPhone= Deleted.contact
From Deleted
Select @newCustomerNo= Inserted.c_id,
@newName=Inserted.cccname,
@newCity=Inserted.c_address,
@newPhone= Inserted.contact
From Inserted
declare @messageString varchar(100)
set @messageString='The record of a customer updated. The fields that have been updated
are: '
if @oldCustomerNo!=@newCustomerNo
Begin
set @messageString=@messageString+'Customer No,'
End
if @oldName!= @newName
Begin
set @messageString= @messageString+'cccname, '
End
if @oldPhone!= @newPhone
Begin
set @messageString= @messageString+'contact, '
End
if @oldCity!= @newCity
Begin
set @messageString= @messageString+'c_address'
End
print (@messageString)
END

Update customer
set cccname='Imran', c_address='Khr'
where c_id='C2'

Create Trigger InsteadTriggerForInsertCustomer
On customer
Instead of Insert
AS
Begin
declare @c_id varchar(2),
@cccname varchar(30),
@c_address varchar(3),
@contact varchar(11),
@c_cnic varchar(15)
Select @c_id= Inserted.c_id, @cccname=Inserted.cccname, @c_address=Inserted.c_address,
@contact= Inserted.contact --get the inserted customer values
From Inserted
Insert into customer values (@c_id, @cccname, @c_address,@c_cnic ,@contact) --insert the customer into the customer table
print ('New Customer Inserted (by the trigger) whose c_id is '+@c_id+'. cccname
is '+@cccname+'. c_address is '+@c_address+'. contact is '+@contact+'.') --print a message to the screen
End

Insert into customer(c_id, cccname, c_address,c_cnic , contact)
 values ('C0', 'Ali', 'Khr','123456', '01234')

create Trigger InsteadTriggerForDeleteCustomer
On customer
Instead of Delete
AS
Begin
declare @c_id varchar(2),
@cccname varchar(30),
@c_address varchar(3),
@contact varchar(11)
Select @c_id= Deleted.c_id,
@cccname=Deleted.cccname,
@c_address=Deleted.c_address,
@contact= Deleted.contact
From Deleted
delete from customer
where c_id=@c_id
print('Customer whose customer id is '+@c_id+' deleted by trigger sucessfully')
End

Delete From Customer
where c_id='C0'

Create Trigger InsteadTriggerForUpdateCustomer
On customer
Instead of Update
AS
Begin
declare @oldCustomerNo varchar(2),
@oldName varchar(30),
@oldCity varchar(3),
@oldPhone varchar(11),
@newCustomerNo varchar(2),
@newName varchar(30),
@newCity varchar(3),
@newPhone varchar(11)
Select @oldCustomerNo= Deleted.c_id,
@oldName=Deleted.cccname,
@oldCity=Deleted.c_address,
@oldPhone= Deleted.contact
From Deleted
Select @newCustomerNo= Inserted.c_id,
@newName=Inserted.cccname,
@newCity=Inserted.c_address,
@newPhone= Inserted.contact
From Inserted
update customer
set c_id=@newCustomerNo, cccname=@newName, c_address= @newCity, contact= @newPhone
where c_id= @oldCustomerNo
declare @messageString varchar(100)
set @messageString='The record of a customer updated by the trigger. The fields that have
been updated are: '
if @oldCustomerNo!=@newCustomerNo
Begin
set @messageString=@messageString+'Customer No,'
End
if @oldName!= @newName
Begin
set @messageString= @messageString+'cccname, '
End
if @oldPhone!= @newPhone
Begin
set @messageString= @messageString+'contact, '
End
if @oldCity!= @newCity
Begin
set @messageString= @messageString+'c_address'
End
print (@messageString)
End

Update Customer
set cccname='Imran', c_address='Khr'
where c_id='C0'

Create Trigger ForTriggerOnInsertCustomer
on customer
For Insert
AS
Begin
declare @cccname varchar(10)
Select @cccname=cccname from Inserted
if @cccname is NULL
Begin
rollback
End
End

insert into Customer(c_id, cccname, c_address,c_cnic , contact)
 values('C0', NULL, 'Lhr','13215465', '123')

DROP TRIGGER InsteadTriggerForInsertCustomer
drop trigger InsteadTriggerForInsertCustomer
drop trigger the_del_trig
drop trigger InsteadTriggerForDeleteCustomer
drop trigger InsteadTriggerForUpdateCustomer
Create Trigger DisallowChangeOnCustomers
On customer
Instead of Insert, Update, Delete
As
Begin
print ('Customer table is not allowed to be modified')
End

insert into Customer(c_id, cccname, c_address,c_cnic , contact)
 values('C0', 'Ali', 'Lhr','13215465', '123')


create trigger ddl_trig
on database
for
drop_table
as begin
print 'you are not allowed to drop the table in question'
end

drop TABLE deals