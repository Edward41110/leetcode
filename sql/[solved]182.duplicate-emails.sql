# Write your MySQL query statement below
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1

# Write your MySQL query statement below
SELECT DISTINCT P1.Email
FROM Person P1, Person P2
WHERE P1.Email = P2.Email AND P1.Id != P2.Id