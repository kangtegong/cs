#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char text[] = "Hello, world!";

    // 파일을 열고 파일 디스크립터를 반환받음
    int file_descriptor1 = open("example.txt", O_WRONLY);
    printf("파일 디스크립터: %d\n", file_descriptor1);

    int file_descriptor2 = open("example2.txt", O_WRONLY);
    printf("파일 디스크립터: %d\n", file_descriptor2);

    int file_descriptor3 = open("example3.txt", O_WRONLY);
    printf("파일 디스크립터: %d\n", file_descriptor3);

    // 파일에 문자열 쓰기
    write(file_descriptor1, text, sizeof(text) - 1);
    write(file_descriptor2, text, sizeof(text) - 1);
    write(file_descriptor3, text, sizeof(text) - 1);

    // 파일 디스크립터를 통해 파일을 닫음
    close(file_descriptor1);
    close(file_descriptor2);
    close(file_descriptor3);

    return 0;
}
