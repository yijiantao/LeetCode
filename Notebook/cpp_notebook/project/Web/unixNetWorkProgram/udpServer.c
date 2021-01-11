#include "lib/common.h"

static int count;

static void recvfrom_int(int signo) {
    printf("\nrecvived %d datagrams\n", count);
    exit(0);
}

int main(int argc, char **argv) {
    int socket_fd;
    string res;
    return 0;
}