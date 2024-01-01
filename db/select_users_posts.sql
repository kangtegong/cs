SELECT users.username, users.email, posts.title
    FROM users, posts
    WHERE users.user_id = posts.user_id;