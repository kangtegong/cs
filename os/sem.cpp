#include <semaphore.h>
#include <iostream>
#include <thread>

int sharedData = 0;  // 공유 데이터
sem_t semaphore;     // 세마포어 선언

void increment() {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&semaphore);  // 세마포어 획득
        sharedData++;          // 공유 데이터 증가
        sem_post(&semaphore);  // 세마포어 해제
    }
}

void decrement() {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&semaphore);  // 세마포어 획득
        sharedData--;          // 공유 데이터 감소
        sem_post(&semaphore);  // 세마포어 해제
    }
}

int main() {
    sem_init(&semaphore, 0, 1);  // 세마포어 초기화, 공유 자원 1개
    std::thread thread1(increment);
    std::thread thread2(decrement);
    thread1.join();
    thread2.join();
    std::cout << "Final value of sharedData: " << sharedData << std::endl;

    // 세마포어 제거
    sem_destroy(&semaphore);
    return 0;
}
