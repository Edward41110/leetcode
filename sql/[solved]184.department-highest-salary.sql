# Write your MySQL query statement below
SELECT Department.Name AS Department, E1.Name AS Employee, Salary
FROM Employee E1, Department
WHERE E1.DepartmentId = Department.Id AND (E1.Salary, E1.DepartmentId) IN 
(SELECT MAX(Salary), DepartmentId FROM Employee E2 GROUP BY DepartmentId)