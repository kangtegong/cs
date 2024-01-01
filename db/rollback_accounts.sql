START TRANSACTION;

-- 시점 ➊: 2개의 레코드 확인
SELECT * FROM accounts;
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;

-- 시점 ➋: account_id가 1인 레코드의 balance가 100 감소되었음을 확인
SELECT * FROM accounts;
ROLLBACK;

-- 시점 ➌
SELECT * FROM accounts;