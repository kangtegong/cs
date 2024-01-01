CREATE TABLE customers (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    age INT,
    email VARCHAR(100) UNIQUE
);

INSERT INTO customers (name, age, email) VALUES
    ('kim', 30, 'kim@example.com'),
    ('lee', 25, 'lee@example.com'),
    ('park', 40, 'park@example.com'),
    ('kang', 20, 'kang@example.com'),
    ('kwon', 18, 'kwon@example.com'),
    ('gwak', 21, 'gwak@example.com'),
    ('na', 45, 'na@example.com'),
    ('jo', 22, 'jo@example.com'),
    ('yang', 50, 'yang@example.com');

CREATE TABLE orders (
    id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    product_id INT,
    quantity INT,
    amount INT
);

INSERT INTO orders (customer_id, product_id, quantity, amount) VALUES
    (1, 1, 10, 1000),
    (2, 2, 20, 2000),
    (2, 3, 30, 3000),
    (3, 4, 40, 4000),
    (3, 5, 50, 5000),
    (4, 6, 60, 6000),
    (4, 7, 70, 7000),
    (5, 8, 80, 8000),
    (5, 9, 90, 9000),
    (10, 9, 90, 9000);