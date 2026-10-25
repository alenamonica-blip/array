#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv []) {
    char *nama1 = "papa";
    char *nama2 = "mama";
    if ( argc < 3) {
        printf("argumen program kurang\n");
        printf("tambahkan argumen seperti: %s %s\n", argv[0], nama1, nama2);
        return -1;
    }
        printf("halo %s\n", argv[1]);
        printf("halo %s\n", argv[2]);
        return 0;
}