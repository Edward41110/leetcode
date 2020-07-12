# Write your MySQL query statement below
SELECT DISTINCT l1.Num AS ConsecutiveNums FROM Logs l1, Logs l2, Logs l3 WHERE l1.Id + 1 = l2.Id AND l2.Id + 1 = l3.Id AND l1.Num = l2.Num AND l2.Num = l3.Num

# Write your MySQL query statement below
SELECT DISTINCT Num AS ConsecutiveNums
FROM (
    SELECT Num,
    CASE
        WHEN @prev = Num THEN @count := @count + 1
        WHEN (@prev := Num) IS NOT NULL THEN @count := 1
    END AS CNT
    FROM Logs, (SELECT @prev := NULL, @count := NULL) AS t
)AS temp
WHERE temp.CNT >= 3