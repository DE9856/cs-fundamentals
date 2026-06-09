/*
Create a Table called Employee and execute the following
Employee(EMPNOm EMPNAME, JOB, MANAGER_NO, SAL, COMMISSION)
1.Create a user and grant all permissions to the user
2,Insert any 3 records into the Employee Table containing the attriubutes and use rollback.
3.Add primary key constrain and not null constraint to the employee table
4. Insert null values to the employee table and verify the result
*/

--1
select host,user from mysql.user;
create user 'DeepeshDBMS'@localhost identified by 'password';
grant all on *.* to 'DeepeshDBMS'@localhost with grant option;

--2
create database company1;
show databases;
use company1;

create table Employee(Empno int, Empname varchar(30), job varchar(30), manager_no int, sal int, commission int);
desc Employee;

insert into Employee values(101,"Deepesh", "VP", 501, 250000, 15);
insert into Employee values(201, "Deepesh1", "Manager", 101, 175000, 12);
insert into Employee values(202, "Deepesh2", "Manager", 101, 170000, 12);
select * from Employee;

commit;
set autocommit=0;
delete from Employee where empno=202;
select * from Employee;

rollback;
select * from Employee;

--3
alter table Employee add primary key(Empno);
alter table Employee modify column Empname varchar(20) not null;
alter table Employee modify column job varchar(20) not null;
alter table Employee modify column manager_no int not null;
alter table Employee modify column sal int not null;
alter table Employee modify column commission int not null;
desc employee;

--4
insert into Employee values(205, "Random", null, 101,175000,12);
