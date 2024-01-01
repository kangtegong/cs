-- 뷰 생성
CREATE VIEW myview AS
    SELECT users.username, users.email, posts.title
    FROM users, posts
    WHERE users.user_id = posts.user_id;

-- 뷰 조회
SELECT username, email, title
FROM myview
WHERE username = 'kim';