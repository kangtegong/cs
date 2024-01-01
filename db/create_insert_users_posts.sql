CREATE TABLE users (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    birthdate DATE,
    registration_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE posts (
    post_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    title VARCHAR(50) NOT NULL,
    content VARCHAR(50),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

INSERT INTO users (username, email, birthdate) VALUES
    ('kim', 'kim@example.com', '1990-01-01'),
    ('lee', 'lee@example.com', '1985-05-15'),
    ('park', 'park@example.com', '1992-08-22');

INSERT INTO posts (user_id, title, content) VALUES
    (1, 'One', 'This is the content of the first post.'),
    (1, 'Two', 'This is the content of the second post.'),
    (2, 'Three', 'This is a post by lee.'),
    (3, 'Four', 'This is a post by park.');