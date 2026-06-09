/*
Create a row level trigger for the customers table that would fir for INSERT or UPDATE or DELETE operations performed on the customers table.
This trigger will display the salary difference between the old and new salary.
Table: Customers(id, name, age, address, salary)
*/

create database exp4;
use exp4;

create table customers(id int primary key, name varchar(20) not null, age int not null, address varchar(50) not null, salary int not null);
insert into customers values(101,"Deepesh",20,"Bengaluru",250000);
select * from customers;

DELIMITER $$
create trigger t1 after update on customers for each row
begin
declare sal_diff int;
if OLD.id=NEW.id THEN
  if NEW.salary<OLD.salary then
    set sal_diff = OLD.salary - NEW.salary;
  else
    set sal_diff = NEW.salary - OLD.salary;
  end if;
set @sal_diff_message = concat('Salary Difference: ',sal_diff);
end if;
end $$
DELIMITER ;

update customers set salary = 275000 where salary = 250000;
select @sal_diff_message;
