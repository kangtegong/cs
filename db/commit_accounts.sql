START TRANSACTION;

-- 시점 ➊: 2개의 레코드 확인
SELECT * FROM accounts;
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- 시점 ➋: 두 UPDATE문이 실행되었음을 확인
SELECT * FROM accounts;
COMMIT;

-- 시점 ➌
SELECT * FROM accounts;