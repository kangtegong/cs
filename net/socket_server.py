import socket

# 서버 주소, 포트 번호 정의
SERVER_HOST = "127.0.0.1"  # 주소(로컬 호스트)
SERVER_PORT = 8000  # 사용할 포트 번호

# 소켓 생성(소켓 열기)
    # - socket.AF_INET: IPv4 주소 체계 사용
    # - socket.SOCK_STREAM: TCP 사용 (참고: socket.SOCK_DGRAM은 UDP)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 소켓 옵션 설정
    # - socket.SOL_SOCKET : 소켓 수준의 옵션 설정
    # - socket.SO_REUSEADDR : 이전 소켓이 사용한 주소가 TIME_WAIT 상태일 경우
    # 해당 주소를 재사용 가능하도록 설정
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# 소켓 바인딩(소켓을 ‘IP 주소:포트’에 연결한다는 의미)
server_socket.bind((SERVER_HOST, SERVER_PORT))

# LISTEN 상태로 연결 대기 (인자1: 대기할 수 있는 최대 연결 수, 즉 한 연결만 대기)
server_socket.listen(1)
print("Listening on port %s ..." % SERVER_PORT)

# 연결 수립 시 소켓 객체(client_connection)와 클라이언트 주소(client_address) 반환
client_connection, client_address = server_socket.accept()

# 클라이언트로부터 HTTP 요청 메시지 수신
    # 최대 1024바이트 수신 후 디코딩
request = client_connection.recv(1024).decode()
print(request)  # 수신한 요청 메시지 출력

# 인코딩된 응답 메시지 클라이언트에 전송
response = "HTTP/1.0 200 OK\n\nThis is CS!"
client_connection.sendall(response.encode())

# 클라이언트와의 연결 종료, 소켓 닫기
client_connection.close()
server_socket.close()
