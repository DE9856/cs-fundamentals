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

DELIMITER $$
CREATE PROCEDURE p3(IN r1 INT)
BEGIN
    DECLARE r2 INT;
    DECLARE c1 CURSOR FOR
        SELECT roll_no
        FROM o_rollcall
        WHERE roll_no > r1;
    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET @FINISH = 1;
    OPEN c1;
    SET @FINISH = 0;
    cursor_loop: LOOP
        FETCH c1 INTO r2;
        IF @FINISH = 1 THEN
            LEAVE cursor_loop;
        END IF;
        IF NOT EXISTS
        (
            SELECT *
            FROM n_rollcall
            WHERE roll_no = r2
        )
        THEN
            INSERT INTO n_rollcall
            SELECT *
            FROM o_rollcall
            WHERE roll_no = r2;
        END IF;
    END LOOP;
    CLOSE c1;
END $$ 
DELIMITER ;
