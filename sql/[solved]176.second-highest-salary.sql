# Write your MySQL query statement below
SELECT MAX(Salary) SecondHighestSalary FROM Employee WHERE Salary != (SELECT MAX(Salary) FROM Employee)

# Write your MySQL query statement below
SELECT (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1,1) AS SecondHighestSalary