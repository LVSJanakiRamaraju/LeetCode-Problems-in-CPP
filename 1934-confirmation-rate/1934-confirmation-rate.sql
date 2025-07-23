# Write your MySQL query statement below
select s.user_id as user_id, round(
    Avg(
        case  
            when c.action = 'confirmed' then 1.00
            else 0.0
        end
    ), 2
)
 as confirmation_rate

 from Signups s left join confirmations c on
 s.user_id = c.user_id
 group by s.user_id
 order by confirmation_rate;
