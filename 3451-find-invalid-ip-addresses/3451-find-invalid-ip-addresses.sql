# Write your MySQL query statement below
with leading_zeroes as (
    select * from logs
    where substring_index(ip,'.',1) like "0%" 
    or substring_index(ip,'.',-1) like "0%"
    or substring_index(ip,'.',-2) like "0%"
    or substring_index(ip,'.',-3) like "0%"
    or length(ip)-length(replace(ip,'.',''))+1 <> 4
),
invalid_octet as (
    select * from logs
    where cast(substring_index(ip,'.',1) as unsigned)>255
    or cast(substring_index(substring_index(ip,'.',2),'.',-1) as unsigned)>255
    or cast(substring_index(substring_index(ip,'.',3),'.',-1) as unsigned)>255
    or cast(substring_index(substring_index(ip,'.',4),'.',-1) as unsigned)>255
)
select ip, count(ip) as invalid_count from
(
    select * from invalid_octet
    union
    select * from leading_zeroes
) as temp_table
group by ip
order by 2 desc,1 desc