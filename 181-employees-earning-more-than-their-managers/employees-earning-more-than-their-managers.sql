# Write your MySQL query statement below

-- select * from Employee as E join on e.id = m.managerId where e.salary < m.salary;

SELECT b.name as Employee FROM Employee as a
JOIN Employee as B
ON a.id = b.managerId
WHERE a.salary < b.salary;

