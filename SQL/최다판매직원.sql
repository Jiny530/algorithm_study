SELECT p.EMPLOYEE_ID, MAX(p.PRI) AS "매출액"
FROM (
    SELECT EMPLOYEE_ID, SUM(PRICE) AS PRI 
    FROM SELLINGS 
    GROUP BY EMPLOYEE_ID 
    ORDER BY PRI DESC
) as p