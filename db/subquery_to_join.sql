SELECT users.username, COUNT(posts.post_id) AS post_count
FROM users
    LEFT JOIN posts ON users.user_id = posts.user_id
    GROUP BY users.username;