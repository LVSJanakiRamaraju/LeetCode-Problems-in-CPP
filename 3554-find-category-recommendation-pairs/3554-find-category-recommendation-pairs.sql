# Write your MySQL query statement below
WITH product_category AS (
    SELECT pi.category, pp.user_id
    FROM ProductPurchases pp
    INNER JOIN ProductInfo pi
    ON pp.product_id = pi.product_id
)
SELECT p1.category AS category1,
    p2.category AS category2,
    COUNT(DISTINCT p1.user_id) AS customer_count
FROM product_category p1
INNER JOIN product_category p2
ON p1.category < p2.category AND p1.user_id = p2.user_id
GROUP BY p1.category, p2.category
HAVING customer_count >= 3
ORDER BY customer_count DESC, category1,category2
