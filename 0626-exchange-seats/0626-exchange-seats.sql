# Write your MySQL query statement below
select id, 
    case
        when id%2 = 0 then (select student from Seat where id = s.id -1)
        when id%2 = 1 and id != (select count(*) from Seat) then (select student from Seat where id = s.id+1)
        else student
    end as student

from Seat s
order by id;