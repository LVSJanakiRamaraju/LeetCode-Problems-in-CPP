# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e join Department d on e.departmentId = d.id
where 3 > (
    select count(distinct q.salary)
    from Employee q
    where q.salary > e.salary
    and e.DepartmentId = q.DepartmentId
);