# Write your MySQL query statement below
-- select (
--     SELECT DISTINCT salary 
--     from employee
--     order by salary desc 
--     limit 1 offset 1) as SecondHighestSalary;

-- selecting maximum salary and then finding salary that are less than maxximum salary and applying the maximum fn again to find the highest

-- SELECT max(salary) as SecondHighestSalary from employee 
-- WHERE salary<(SELECT max(salary)FROM employee)


--
SELECT max(salary) as SecondHighestSalary from employee 
WHERE salary not in (select max(salary) from employee)