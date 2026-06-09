/*
Create a table called Employee that contain attributes Empno, Ename, job, mgr, sal, and execute the following:
1.Add a column commission with domain into the table
2. Insert any 5 records into the table
3. Update the column details of job
4. Rename the column of Employee Table using alter command
5. Delete the employee whose empno is 203
*/

create database company;
use company;

create table Employee(empno int, ename varchar(20), job varchar(20), mgr int, sal int);

--1
alter table Employee add column commission int;

--2
insert into Employee values(101,'Deepesh','VP', 501,250000,15);
insert into Employee values(201,'Deepesh1','Manager', 101,150000,12);
insert into Employee values(202,'Deepesh2','Manager', 101,250000,11);
insert into Employee values(301,'Deepesh3','HR', 501,100000,0);
insert into Employee values(302,'Deepesh4','HR', 501,90000,0);

--3
update Employee set job="Senior HR" where Empno=301;

--04
alter table Employee rename column mgr to manager_no;

--5
delete from Employee where Empno=302;

