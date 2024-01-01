# MySQL 환경 구축

## (권장) 도커 기반 설치

> 다음 안내는 도커(docker)가 설치되어 있다고 전제합니다. 도커가 설치되어 있지 않을 경우 도커 설치 후 진행 바랍니다. 도커 설치 관련한 다양한 웹 자료가 공개되어 있으니 [공식 문서](https://docs.docker.com/engine/install/) 또는 [웹 검색](https://www.google.com/search?q=%EB%8F%84%EC%BB%A4+%EC%84%A4%EC%B9%98)을 참고 바랍니다.


1. 다음 명령어로 MySQL (버전 8) 이미지를 다운로드합니다.

```
$ docker pull mysql:8
```

> 윈도우 사용자는 PowerShell, 명령 프롬프트에서, 맥OS 사용자는 터미널에서 위 명령어를 실행하면 됩니다. 

2. 다운로드한 Docker 이미지를 확인합니다.

```
$ docker images
REPOSITORY                    TAG       IMAGE ID       CREATED        SIZE
mysql                         8         68663cf1d597   11 days ago    591MB
```

3. 다음 명령어로 MySQL 컨테이너를 실행합니다. 

이때, "<비밀번호>"에는 root 계정으로 MySQL에 접속하기 위한 비밀번호 (루트 비밀번호)를 입력합니다. 

```
$ docker run --name mysql-container -e MYSQL_ROOT_PASSWORD=<비밀번호> -d -p 3306:3306 mysql:8
```

4. 다음 명령어로 MySQL 컨테이너를 시작합니다.

```
$ docker start mysql-container
```

5. 다음 명령어로 컨테이너 내부에 접속합니다.

```
$ docker exec -it mysql-container bash
```

6. 다음과 같이 명령어를 입력할 공간이 나온다면, `mysql -u root -p`라고 입력합니다. 

이는 "비밀번호가 설정된 root 계정으로 mysql에 접속하겠다"는 의미입니다.

```
bash-5.1# 
bash-5.1# mysql -u root -p
```

7. "Enter password:"가 나온다면 4번에서 입력한 비밀번호를 입력합니다. 

```
bash-5.1# 
bash-5.1# mysql -u root -p
Enter password:
```

8. 다음과 같은 화면이 나온다면 성공입니다.

```
bash-5.1# mysql -u root -p
Enter password:
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 8
Server version: 8.4.2 MySQL Community Server - GPL

Copyright (c) 2000, 2024, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql>
```

9. 테스트 삼아 `SHOW DATABASES` 명령으로 현재 데이터베이스를 조회할 수도 있습니다. 

```
mysql> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.01 sec)

```


10. 실습이 끝났다면 exit을 두 번 입력하세요. 컨테이너 밖으로 빠져 나올 수 있습니다. 

```
mysql> exit # 한 번 입력
Bye
bash-5.1# exit # 두 번 입력
exit
$ 
```

---

## MySQL 로컬 설치

컨테이너를 사용하지 않고 MySQL을 설치하고 싶다면 다음 링크를 참고하세요.

[MySQL 다운로드 및 설치하기](https://hongong.hanbit.co.kr/mysql-%EB%8B%A4%EC%9A%B4%EB%A1%9C%EB%93%9C-%EB%B0%8F-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0mysql-community-8-0/) 

