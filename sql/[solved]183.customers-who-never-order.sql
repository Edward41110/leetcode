# Write your MySQL query statement below
SELECT Customers.Name Customers
FROM Customers LEFT JOIN Orders ON (Customers.Id = Orders.CustomerId)
WHERE CustomerId IS NULL