# Write your MySQL query statement below
SELECT W1.Id
FROM Weather W1, Weather W2
WHERE dateDiff(W1.RecordDate, W2.RecordDate) = 1 AND W1.Temperature > W2.Temperature