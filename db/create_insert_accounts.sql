CREATE TABLE accounts (
    account_id INT PRIMARY KEY,
    account_name VARCHAR(50),
    balance INT
);

INSERT INTO accounts (account_id, account_name, balance) VALUES (1, 'Kim', 1000);
INSERT INTO accounts (account_id, account_name, balance) VALUES (2, 'Lee', 500);