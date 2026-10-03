SELECT customer_id, COUNT(*) AS count_no_trans
FROM (
    SELECT 
        Visits.visit_id,
        Visits.customer_id,
        Transactions.transaction_id
    FROM Visits
    LEFT JOIN Transactions
        ON Visits.visit_id = Transactions.visit_id
) AS temp
WHERE transaction_id IS NULL
GROUP BY customer_id;