/*
Write a PL/SQL block of code using paremetrized cursor.
The cursor will merge the data available in the newly create table N_rollcall
*/

create database exp6;
use exp6;

create table o_rollcall(id int, name varchar(20), address varchar(20));
create table n_rollcall(id int, name varchar(20), address varchar(20));

insert into o_rollcall values(1,'Deepesh', 'Bengaluru');
insert into o_rollcall values(2,'Deepesh1', 'Hyderabad');

DELIMITER $$
create procedure p3 (in r1 int)
begin
	declare r2 int;
    declare c1 cursor for 
		select id from o_rollcall where id > r1;
	declare continue handler for not found
		set @FINISH=1;
	
    open c1;
		set @FINISH=0;
        cursor_loop: LOOP
			fetch c1 into r2;
            if @FINISH=1 then
				leave cursor_loop;
			end if;
			if not exists( select * from n_rollcall where id = r2) then
				insert into n_rollcall
					select * from o_rollcall where id = r2;
			end if;
		end loop;
	close c1;
	end $$
DELIMITER ;


call p3(0);
select * from n_rollcall;


