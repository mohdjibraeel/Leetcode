# Write your MySQL query statement below
select S.user_id,
ROUND(COALESCE(confirmed / total, 0),2) AS confirmation_rate
from Signups S
LEFT JOIN (select user_id, 
COUNT(*) AS total,
COUNT(CASE WHEN action = 'confirmed' THEN 1 END) AS 'confirmed'
from Confirmations 
group by user_id) C ON S.user_id=C.user_id