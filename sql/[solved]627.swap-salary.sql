# Write your MySQL query statement below
UPDATE salary
SET sex = if(sex = 'm', 'f', 'm')

# Write your MySQL query statement below
UPDATE salary
SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END