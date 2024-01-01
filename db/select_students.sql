-- 삽입된 레코드 조회(1): 정확하게 일치하는 레코드 조회
SELECT first_name, last_name, major
    FROM students
    WHERE major = 'Computer Science';

-- 삽입된 레코드 조회(2)
SELECT first_name, last_name, age
    FROM students
    WHERE age >= 21;

-- LIKE를 활용한 레코드 조회(1)
SELECT first_name, last_name, major
    FROM students
    WHERE major LIKE '%Science%';

-- LIKE를 활용한 레코드 조회(2)
SELECT first_name, last_name, major
    FROM students
    WHERE major LIKE '_a%';

-- 연산/집계를 활용한 레코드 조회
SELECT COUNT(*), AVG(gpa), MAX(gpa), MIN(gpa) FROM students;

-- 그룹화된 데이터에서의 레코드 조회(1)
SELECT major, COUNT(*) AS student_count
    FROM students
    GROUP BY major;

-- 그룹화된 데이터에서의 레코드 조회(2)
SELECT age, COUNT(*) AS student_count
    FROM students
    GROUP BY age;

-- 그룹화된 데이터에서의 레코드 조회(3)
SELECT major, AVG(gpa)
    FROM students
    GROUP BY major;

-- 그룹화된 결과에 대한 조건 적용(1)
SELECT major, AVG(gpa)
    FROM students
    GROUP BY major
    HAVING AVG(gpa) >= 3.6;

-- 그룹화된 데이터에서의 레코드 조회(4)
SELECT major, AVG(age)
    FROM students
    GROUP BY major;

-- 그룹화된 결과에 대한 조건 적용(2)
SELECT major, AVG(age)
    FROM students
    GROUP BY major
    HAVING AVG(age) >= 21;

-- 정렬된 레코드 조회
SELECT first_name, last_name, gpa
    FROM students
    ORDER BY gpa DESC;

SELECT first_name, last_name, major
    FROM students
    ORDER BY last_name ASC;

SELECT first_name, last_name, enrollment_date
    FROM students
    ORDER BY enrollment_date ASC;

