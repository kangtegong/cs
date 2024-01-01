-- INNER 조인
SELECT customers.name, customers.age, customers.email, orders.id, orders.product_id,
orders.quantity, orders.amount
FROM customers
    INNER JOIN orders ON customers.id = orders.customer_id;

-- 만족하는 데이터만 선택해 결합(WHERE절 추가)
SELECT customers.name, customers.age, customers.email, orders.id, orders.product_id,
orders.quantity, orders.amount
FROM customers
INNER JOIN orders ON customers.id = orders.customer_id
    WHERE orders.amount >= 5000;