# Redis 환경 구축

## (권장) 도커 기반 설치

> 다음 안내는 도커(docker)가 설치되어 있다고 전제합니다. 도커가 설치되어 있지 않을 경우 도커 설치 후 진행 바랍니다. 도커 설치 관련한 다양한 웹 자료가 공개되어 있으니 [공식 문서](https://docs.docker.com/engine/install/) 또는 [웹 검색](https://www.google.com/search?q=%EB%8F%84%EC%BB%A4+%EC%84%A4%EC%B9%98)을 참고 바랍니다.


1. 다음 명령어로 Redis (버전 7.4.0) 이미지를 다운로드합니다.

```
$ docker pull redis
$ docker pull redis:7.4.0
```

> 윈도우 사용자는 PowerShell, 명령 프롬프트에서, 맥OS 사용자는 터미널에서 위 명령어를 실행하면 됩니다. 

2. 다운로드한 Docker 이미지를 확인합니다.

```
$ docker images
REPOSITORY   TAG       IMAGE ID       CREATED        SIZE
redis        7.4.0     5217e747d92c   5 days ago     140MB
```

3. 다음 명령어로 Redis 컨테이너를 실행합니다. 

```
$ docker run -d --name redis-container -p 6379:6379 redis:7.4.0
```

4. 다음 명령어로 Redis 컨테이너를 시작합니다.

```
$ docker start redis-container
```

5. 다음 명령어로 컨테이너 내부에 접속합니다.

```
$ docker exec -it redis-container bash
```

6. 다음과 같이 명령어를 입력할 공간이 나온다면, `redis-cli`라고 입력합니다. 


```
root@13306fbb3236:/data#
root@13306fbb3236:/data# redis-cli
```

7. 다음과 같이 `127.0.0.1:6379>` 라는 입력 공간이 나온다면 성공입니다.

```
root@13306fbb3236:/data#
root@13306fbb3236:/data# redis-cli
127.0.0.1:6379>
```

8. 접속 테스트를 수행합니다. `ping`이라고 입력했을 때 `PONG`이라고 출력되면 올바르게 설치된 것입니다.

```
127.0.0.1:6379> ping
PONG
127.0.0.1:6379>
```


9. 실습이 끝났다면 exit을 두 번 입력하세요. 컨테이너 밖으로 빠져 나올 수 있습니다. 

```
127.0.0.1:6379> exit
root@13306fbb3236:/data# exit
exit
$
```

---

## Redis 로컬 설치

컨테이너를 사용하지 않고 Redis를 설치하고 싶다면 다음 링크를 참고하세요.

[Redis 다운로드 및 설치하기](https://redis.io/docs/latest/operate/oss_and_stack/install/install-redis/) 

