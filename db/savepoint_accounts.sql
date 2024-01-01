START TRANSACTION;

-- 세이브포인트 생성 ➊
SAVEPOINT sp1;
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- 세이브포인트 생성 ➋
SAVEPOINT sp2;
UPDATE accounts SET account_name = 'new_Kim' WHERE account_id = 1;
UPDATE accounts SET account_name = 'new_Lee' WHERE account_id = 2;

-- 세이브포인트 생성 ➌
SAVEPOINT sp3;
SELECT * FROM accounts;

-- 특정 세이브포인트로 롤백
ROLLBACK TO SAVEPOINT sp2;
ROLLBACK TO SAVEPOINT sp1;