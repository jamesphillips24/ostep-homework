#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int pipe_input_fd = argv[1][0] - '0';
    char* message = "Hello parent!";

    write(pipe_input_fd, message, strlen(message) + 1);
    close(pipe_input_fd);
    return 0;
}