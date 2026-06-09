/*
Create cursor for employee table and extract the values from the table.
Declare the values, open the curosr and extract the values from the cursor.
Close the cursor
Table: employee(e_id, e_name, age,salary)
*/

create database exp5;
use exp5;

create table employee(e_id int primary key, e_name varchar(20) not null, age int not null, salary int not null);
insert into employee values(1,'Deepesh', 20, 50000);
insert into employee values(2,'Deepesh1',19,45000);
insert into employee values(3,'Deepesh2', 18, 40000);
insert into employee values(4,'Deepesh3',17,35000);
insert into employee values(5,'Deepesh4', 16, 30000);
select * from employee;

DELIMITER $$
create procedure fetch_employee_data()
begin
  declare emp_id int;
  declare emp_name varchar(20);
  declare emp_age int;
  declare emp_salary int;
  declare emp_cursor cursor for
    select e_id, e_name, age, salary from employee;
  declare continue handler for not found
    set @FINISH=1;
  open emp_cursor;
    set @FINISH=0;
    cursor_loop: LOOP
      fetch emp_cursor into emp_id, emp_name, emp_age, emp_salary;
      if @FINISH=1 then
        leave cursor_loop;
      end if;
  select concat("Employee ID: ",emp_id,", Name: ",emp_name,", Age: ", emp_age, ", Salary: ", emp_salary) as Employee_info;
  end loop;
  close emp_cursor;
END $$
DELIMITER ;

call fetch_employee_data();
