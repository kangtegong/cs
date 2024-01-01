CREATE TABLE tests (
    post_id INT AUTO_INCREMENT,
    user_id INT,
    title VARCHAR(50) NOT NULL,
    content VARCHAR(50),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (post_id),
    CONSTRAINT FK_user_id FOREIGN KEY (user_id) REFERENCES users(user_id),
    CONSTRAINT UQ_title UNIQUE (title)
);