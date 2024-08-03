# MongoDB 환경 구축

## (권장) 도커 기반 설치

> 다음 안내는 도커(docker)가 설치되어 있다고 전제합니다. 도커가 설치되어 있지 않을 경우 도커 설치 후 진행 바랍니다. 도커 설치 관련한 다양한 웹 자료가 공개되어 있으니 [공식 문서](https://docs.docker.com/engine/install/) 또는 [웹 검색](https://www.google.com/search?q=%EB%8F%84%EC%BB%A4+%EC%84%A4%EC%B9%98)을 참고 바랍니다.


1. 다음 명령어로 MongoDB 이미지를 다운로드합니다.

```
$ docker pull mongo
혹은 
$ docker pull mongo:8.0-rc
```

> 윈도우 사용자는 PowerShell, 명령 프롬프트에서, 맥OS 사용자는 터미널에서 위 명령어를 실행하면 됩니다. 

2. 다운로드한 Docker 이미지를 확인합니다.

```
$ docker images
REPOSITORY                    TAG       IMAGE ID       CREATED        SIZE
mongo                         8.0-rc    d7d2dce53977   40 hours ago   808MB
```

3. 다음 명령어로 MySQL 컨테이너를 실행합니다. 

```
$ docker run --name mongodb-container -v ~/data:/data/db -d -p 27017:27017 mongo
```

4. 다음 명령어로 MongoDB 컨테이너를 시작합니다.

```
$ docker start mongodb-container
```

5. 다음 명령어로 MongoDB 컨테이너 내부에 접속합니다.

```
$ docker exec -it mongodb-container bash
```

6. 다음과 같이 명령어를 입력할 공간이 나온다면, `mongosh`라고 입력합니다. 


```
root@6130fda7f276:/#
root@6130fda7f276:/# mongosh
```

7. 다음과 같은 명령과 함께 `test>` 프롬프트가 나오면 성공입니다.

``` 
Current Mongosh Log ID:	66adfa27ed0df9bbad8db5fa
Connecting to:		mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+2.2.6
Using MongoDB:		7.0.11
Using Mongosh:		2.2.6

For mongosh info see: https://docs.mongodb.com/mongodb-shell/

------
   The server generated these startup warnings when booting
   2024-08-03T09:35:08.047+00:00: Access control is not enabled for the database. Read and write access to data and configuration is unrestricted
   2024-08-03T09:35:08.047+00:00: vm.max_map_count is too low
------

test>
```

8. 테스트 삼아 `use mydb` 명령으로 현재 데이터베이스 생성, 변경할 수 있습니다.

```
test> use mydb
switched to db mydb
```

9. 실습이 끝났다면 exit을 두 번 입력하세요. 컨테이너 밖으로 빠져 나올 수 있습니다. 

```
mydb> exit  # 한 번 입력
root@6130fda7f276:/# exit  # 두 번 입력
exit
$ 
```

---

## MongoDB 로컬 설치

컨테이너를 사용하지 않고 MongoDB을 설치하고 싶다면 다음 링크를 참고하세요.

[MongoDB 다운로드 및 설치하기](https://www.mongodb.com/ko-kr/docs/manual/installation/) 

