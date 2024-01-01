import threading
import os


def foo():
    pid = os.getpid()  # 현재 프로세스의 pid를 반환
    tid = threading.get_native_id()  # 현재 스레드의 id를 반환
    print(f"foo: PID={pid}, Thread ID={tid}")  # pid와 tid 값을 출력


def bar():
    pid = os.getpid()
    tid = threading.get_native_id()
    print(f"bar: PID={pid}, Thread ID={tid}")


def baz():
    pid = os.getpid()
    tid = threading.get_native_id()
    print(f"baz: PID={pid}, Thread ID={tid}")


if __name__ == "__main__":
    thread1 = threading.Thread(target=foo)  # 첫 번째 스레드 생성, 실행할 함수는 foo
    thread2 = threading.Thread(target=bar)  # 두 번째 스레드 생성, 실행할 함수는 bar
    thread3 = threading.Thread(target=baz)  # 세 번째 스레드 생성, 실행할 함수는 baz
    thread1.start()  # 첫 번째 스레드 실행
    thread2.start()  # 두 번째 스레드 실행
    thread3.start()  # 세 번째 스레드 실행
