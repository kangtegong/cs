SELECT customers.name, orders.id AS order_id, orders.product_id, orders.quantity,
orders.amount
FROM customers
    LEFT OUTER JOIN orders ON customers.id = orders.customer_id;