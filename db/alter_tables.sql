-- 새로운 필드 추가
-- ALTER TABLE 테이블_이름 ADD COLUMN 필드_이름 필드_타입 [제약 조건]
ALTER TABLE posts ADD COLUMN new_field VARCHAR(50) NOT NULL;

-- 기존 필드 수정
-- ALTER TABLE 테이블_이름 CHANGE COLUMN 기존_필드_이름 새_필드_이름 필드_타입 [제약 조건]
ALTER TABLE posts CHANGE COLUMN new_field old_field VARCHAR(30) NOT NULL;

-- 기존 필드 삭제
-- ALTER TABLE 테이블_이름 DROP COLUMN 필드_이름
ALTER TABLE posts DROP COLUMN old_field;

-- 외래 키 제약 조건 추가
-- ALTER TABLE 테이블_이름 [ADD CONSTRAINT 제약_조건_이름]
-- ADD FOREIGN KEY (필드_이름) REFERENCES 참조_테이블_이름(참조_필드)
ALTER TABLE posts ADD FOREIGN KEY (user_id) REFERENCES users(user_id);

-- UNIQUE 제약 조건 추가
-- ALTER TABLE 테이블_이름 [ADD CONSTRAINT 제약_조건_이름] UNIQUE (필드_이름)
ALTER TABLE posts ADD UNIQUE (title);

-- NOT NULL 제약 조건 추가
-- ALTER TABLE 테이블_이름 MODIFY 필드_이름 필드_타입 NOT NULL
ALTER TABLE users MODIFY email VARCHAR(100) NOT NULL;

-- 기본 키 설정(PRIMARY KEY로 사용 중인 필드가 있을 경우, 다른 필드로 변경 후 적용 가능)
-- ALTER TABLE 테이블_이름 ADD PRIMARY KEY (필드_이름)
ALTER TABLE posts ADD PRIMARY KEY (post_id);