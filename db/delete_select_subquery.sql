DELETE FROM posts
WHERE user_id = (
    SELECT user_id
    FROM users
    WHERE email = 'kim@example.com'
);