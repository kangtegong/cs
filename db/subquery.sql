SELECT
    users.username,
    (SELECT COUNT(*)
    FROM posts
    WHERE posts.user_id = users.user_id) AS post_count
    FROM users;