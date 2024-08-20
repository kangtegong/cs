# 로드 밸런싱을 위한 Nginx 환경 구축

## (권장) 도커 기반 설치

> 다음 안내는 도커(docker)가 설치되어 있다고 전제합니다. 도커가 설치되어 있지 않을 경우 도커 설치 후 진행 바랍니다. 도커 설치 관련한 다양한 웹 자료가 공개되어 있으니 [공식 문서](https://docs.docker.com/engine/install/) 또는 [웹 검색](https://www.google.com/search?q=%EB%8F%84%EC%BB%A4+%EC%84%A4%EC%B9%98)을 참고 바랍니다.

1. Docker Network 생성

먼저, 모든 컨테이너가 서로 통신할 수 있도록 Docker 네트워크를 생성합니다.

```
$ docker network create my_network
```

2. 백엔드 서버 생성

서로 다른 포트에서 동작하는 두 개의 간단한 웹 서버 컨테이너를 생성합니다. 여기서는 nginx 이미지를 사용하여 웹 서버를 실행합니다.

```
$ docker run -d --name web1 --network my_network -p 8081:80 nginx
$ docker run -d --name web2 --network my_network -p 8082:80 nginx
```

3. 각 서버의 HTML 콘텐츠 수정

web1과 web2 컨테이너 내부에 접속하여 각각의 HTML 콘텐츠를 수정합니다.

3-1. web1의 HTML 수정을 위해 web1 컨테이너에 접속합니다.

```
$ docker exec -it web1 /bin/bash
```

3-2. 컨테이너 내부에서 다음 명령어를 실행하여 기본 HTML 파일을 수정합니다.

```
$ echo '<html><body><h1>Hello from web1</h1></body></html>' > /usr/share/nginx/html/index.html
$ exit
```

3-3. web2의 HTML 수정을 위해 web2 컨테이너에 접속합니다.

```
$ docker exec -it web2 /bin/bash
```

3-4. 컨테이너 내부에서 다음 명령어를 실행하여 기본 HTML 파일을 수정합니다.

```
$ echo '<html><body><h1>Hello from web2</h1></body></html>' > /usr/share/nginx/html/index.html
$ exit
```

4. 로드 밸런싱을 수행할 컨테이너를 생성하고 내부로 접속합니다.

```
$ docker run -d --name nginx --network my_network -p 8080:80 nginx
$ docker exec -it nginx /bin/bash
```

5. NGINX 컨테이너 내부에서 설정 파일을 작성합니다.

```
upstream myapp {
    server web1:80;
    server web2:80;
}

server {
    listen 80;

    location / {
        proxy_pass http://myapp;
    }
}
```

6. NGINX 재시작
NGINX를 재시작하여 새로운 설정을 적용합니다.

```
$ nginx -s reload
```

7. 컨테이너에서 빠져나옵니다

```
$ exit
```

8. 로드 밸런싱 테스트

호스트 머신에서 브라우저를 사용하거나 curl 명령어를 사용하여 로드 밸런싱을 테스트합니다.

```
$ curl http://localhost:8080
```

9. 작업이 끝나면 다음과 같은 명령으로 컨테이너와 네트워크를 정리합니다.

```
$ docker rm -f nginx web1 web2
$ docker network rm my_network
```
