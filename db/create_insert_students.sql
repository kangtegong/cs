CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INT,
    major VARCHAR(50),
    gpa DECIMAL(3, 2),
    enrollment_date DATE
);

INSERT INTO students (first_name, last_name, age, major, gpa, enrollment_date) VALUES
    ('Alice', 'Johnson', 20, 'Computer Science', 3.8, '2022-09-01'),
    ('Bob', 'Smith', 22, 'Mathematics', 3.5, '2020-09-01'),
    ('Charlie', 'Brown', 21, 'Physics', 3.9, '2021-09-01'),
    ('David', 'Williams', 23, 'Chemistry', 3.2, '2019-09-01'),
    ('Eve', 'Davis', 19, 'Biology', 3.6, '2023-09-01');