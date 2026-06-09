/*
Write a PL/SQL block of code using paremetrized cursor.
The cursor will merge the data available in the newly create table N_rollcall
*/

create database exp6;
use exp6;

create table o_rollcall(roll_no int, name varchar(20), address varchar(20));
create table n_rollcall(roll_no int, name varchar(20), address varchar(20));

insert into o_rollcall values(1, 'Deepesh', 'Bengaluru');
insert into o_rollcall values(2, 'Deepesh1', 'Hyderabad');

delimiter $$
create procedure p3(in r1 int)
begin
  declare r2 int;
declare exit_loop boolean;
declare c1 cursor for select roll_no from o_rollcall where roll_no > r1;
declare continue handler for not found
  set exit_loop = true;

open c1:
  e_loop: loop
    fetch c1 into r2;
    if not exists (select * from n_rollcall where roll_no = r2) then
      insert into n_rollcall
        select * from o_rollcall where roll_no = r2;
    end if;

  if exit_loop then
    close c1;
  leave e_loop;
end if;
end loop;
end $$
DELIMITER ;
