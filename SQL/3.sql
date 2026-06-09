/*
Queries using aggregate function (COUNT, AVG, MIN, MAX, SUM), Group by, Order by
Table: Employee(e_id, e_name, age, salary)
1. Create Employee Tablew containing all records
2. Count number of employee names from employee table
3. Find the maximum age from employee table
4. Find the mnimum age from employee table
5. Find salaries of employee in ascending order
6. Find grouped salaries of employees
*/

create databse exp3;
use exp3;

--1
create table Employee(e_id int, e_name varchar(20), age int, salary int);
insert into Employee values(101,"Deepesh",20,200000);
insert into Employee values(102,"Deepesh1",21,150000);
insert into Employee values(103,"Deepesh2",22,100000);
insert into Employee values(104,"Deepesh3",23,50000);
insert into Employee values(105,"Deepesh4",24,100000);

--2
select count(e_name) from Employee;

--3
select max(age) from Employee;

--4
select min(age) from Employee;

--5
select e_name, salary from Employee order by salary asc;

--6
select salary, e_name, age from Employee group by salary, e_name, age;
