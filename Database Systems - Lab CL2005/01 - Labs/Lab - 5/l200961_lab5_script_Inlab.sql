create database lab5E
use lab5E

go
create table hotel(
hotelno varchar(10) primary key,
hotelname varchar(20),
city varchar(20),
)

insert into hotel values('fb01', 'Grosvenor', 'London');
insert into hotel values('fb02', 'Watergate', 'Paris');
insert into hotel values('ch01', 'Omni Shoreham', 'London');
insert into hotel values('ch02', 'Phoenix Park', 'London');
insert into hotel values('dc01', 'Latham', 'Berlin');

 -- create a table named hotel

 create table room(

roomno numeric(5),
hotelno varchar(10),
type varchar(10),
price decimal(5,2),
primary key (roomno, hotelno),
foreign key (hotelno) REFERENCES hotel(hotelno)
)

insert into room values(501, 'fb01', 'single', 19);
insert into room values(601, 'fb01', 'double', 29);
insert into room values(701, 'fb01', 'family', 39);
insert into room values(1001, 'fb02', 'single', 58);
insert into room values(1101, 'fb02', 'double', 86);
insert into room values(1001, 'ch01', 'single', 29.99);
insert into room values(1101, 'ch01', 'family', 59.99);
insert into room values(701, 'ch02', 'single', 10);
insert into room values(801, 'ch02', 'double', 15);
insert into room values(901, 'dc01', 'single', 18);
insert into room values(1001, 'dc01', 'double', 30);
insert into room values(1101, 'dc01', 'family', 35);

create table guest(
guestno numeric(5),
guestname varchar(20),
guestaddress varchar(50),
primary key (guestno)
)

insert into guest values(10001, 'John Kay', '56 High St, London');
insert into guest values(10002, 'Mike Ritchie', '18 Tain St, London');
insert into guest values(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
insert into guest values(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
insert into guest values(10005, 'Carol Farrel', '6 Achray St, Glasgow');
insert into guest values(10006, 'Tina Murphy', '63 Well St, Glasgow');
insert into guest values(10007, 'Tony Shaw', '12 Park Pl, Glasgow');


create table booking(
hotelno varchar(10),
guestno numeric(5),
datefrom datetime,
dateto datetime,
roomno numeric(5),
primary key (hotelno, guestno, datefrom),
foreign key (roomno, hotelno) REFERENCES room(roomno, hotelno),
foreign key (guestno) REFERENCES guest(guestno)
)

 

insert into booking values('fb01', 10001, '04-04-01', '04-04-08', 501);
insert into booking values('fb01', 10004, '04-04-15', '04-05-15', 601);
insert into booking values('fb01', 10005, '04-05-02', '04-05-07', 501);
insert into booking values('fb01', 10001, '04-05-01', null, 701);
insert into booking values('fb02', 10003, '04-04-05', '10-04-04', 1001);
insert into booking values('ch01', 10006, '04-04-21', null, 1101);
insert into booking values('ch02', 10002, '04-04-25', '04-05-06', 801);
insert into booking values('dc01', 10007, '04-05-13', '04-05-15', 1001);
insert into booking values('dc01', 10003, '04-05-20', null, 1001);



select * from booking
select * from guest
select * from hotel
select * from room

-- 1. List the names and addresses of all guests in London, alphabetically ordered by name.
select guestname, guestaddress from guest where guestaddress like '%London%' order by guestname
-- 2. Display the names of all the hotels along with the number of rooms present in each of them.
select hotelname, count(roomno) as [counthotel] from hotel left join room on hotel.hotelno = room.hotelno group by hotelname
-- 3. Display the average price of each hotel situated in London.
select hotelname, avg(price) as [avgprice] from hotel join room on hotel.hotelno = room.hotelno where city = '%London%' group by hotelname
-- 4. Display the most expensive double, single and family room respectively.
SELECT type, MAX(price)
FROM room
GROUP BY type;
-- 5. Display hotelname, cityname along with distinct number of room types available in each of
-- them.
SELECT h.hotelname, h.city, COUNT(DISTINCT r.type) AS count_room_types
FROM hotel h
JOIN room r ON h.hotelno = r.hotelno
GROUP BY h.hotelname, h.city;
-- 6. Display the name and city of the hotels where guest’s from London are staying. The list
-- should not contain any hotel more than once.
SELECT DISTINCT h.hotelname, h.city
FROM hotel h
JOIN room r ON h.hotelno = r.hotelno
JOIN booking b ON (r.roomno = b.roomno AND r.hotelno = b.hotelno)
JOIN guest g ON b.guestno = g.guestno
WHERE g.guestaddress LIKE '%London%'
-- 7. Display the name, city of all the hotels along with the number of reservations it has, in
-- descending order.
SELECT h.hotelname, h.city, COUNT(*) AS count_reservations
FROM hotel h
JOIN room r ON h.hotelno = r.hotelno
JOIN booking b ON (r.roomno = b.roomno AND r.hotelno = b.hotelno)
GROUP BY h.hotelname, h.city
ORDER BY count_reservations DESC;
-- 8. Display the names of all the guests who have not provided any end date for their
-- reservations.
SELECT g.guestname
FROM guest g
JOIN booking b ON g.guestno = b.guestno
WHERE b.dateto IS NULL;
-- 9. Display the HotelName and RoomNo which was reserved in the year 2001 and 2002, also
-- display the Guest No who reserved the room at the time.
SELECT h.hotelname, r.roomno, b.guestno
FROM hotel h
JOIN room r ON h.hotelno = r.hotelno
JOIN booking b ON (r.roomno = b.roomno AND r.hotelno = b.hotelno)
WHERE YEAR(b.datefrom) IN (2001, 2002);
-- 10. Display the name of the hotel and city which has not been reserved yet. .
SELECT h.hotelname, h.city
FROM hotel h
LEFT JOIN room r ON h.hotelno = r.hotelno
WHERE r.roomno IS NULL;
-- 11. Display the price of the “Family” type room in all hotels along with the HotelNames,
-- HotelNo, RoomNo. NULL should be shown if a hotel doesn’t have a “Family” type room.
SELECT h.HotelName, h.HotelNo, 
    CASE 
    -- list null if roomno is null, else list roomno
    WHEN r.RoomNo IS NULL THEN NULL 
    ELSE r.RoomNo 
    END AS RoomNo,

    CASE 
    -- list null if price is null, else list price
    WHEN r.Price IS NULL THEN NULL
    ELSE r.Price 
    END AS Price
FROM Hotel h
LEFT JOIN Room r ON (h.HotelNo = r.HotelNo AND r.[type] = 'Family');
-- 12. How many different guests have made bookings till May, 2015?
SELECT COUNT(DISTINCT booking.guestno) AS NumGuests
FROM booking
WHERE booking.dateto <= '2015-05-31';
