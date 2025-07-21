# Write your MySQL query statement below
select d.name AS Department, e.name AS Employee, e.salary as Salary
FROM Employee e join Department d on e.departmentId = d.id
where Salary = (
    SELECT MAX(salary) from Employee where departmentId = e.departmentId
) ;