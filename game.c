#include <stdio.h>
#include <stdlib.h>

char c[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

int main() {
    int baris, kolom, menang = 0, langkah = 0;
    char pemain = 'X';

    while(langkah < 9 && menang == 0) {

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++)
                printf(" %c ", c[i][j]);
            printf("\n");
        }

        printf("\nPemain %c\n", pemain);
        printf("Masukkan baris (1-3): ");
        scanf("%d", &baris);
        printf("Masukkan kolom (1-3): ");
        scanf("%d", &kolom);

        if(baris < 1 || baris > 3 ||
           kolom < 1 || kolom > 3) {
            printf("Posisi tidak valid!\n");
            continue;
        }

        baris--;
        kolom--;

        if(c[baris][kolom] == 'X' ||
           c[baris][kolom] == 'O') {
            printf("Kotak sudah terisi!\n");
            continue;
        }

        c[baris][kolom] = pemain;
        langkah++;

        for(int i=0; i<3; i++) {
            if(c[i][0] == pemain && c[i][1] == pemain && c[i][2] == pemain)
                menang = 1;

            if(c[0][i] == pemain && c[1][i] == pemain && c[2][i] == pemain)
                menang = 1;
        }

        if(c[0][0] == pemain && c[1][1] == pemain && c[2][2] == pemain)
            menang = 1;

        if(c[0][2] == pemain && c[1][1] == pemain && c[2][0] == pemain)
            menang = 1;

        if(menang == 0)
            pemain = (pemain == 'X') ? 'O' : 'X';
    }

    printf("\n");

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            printf(" %c ", c[i][j]);
        printf("\n");
    }

    if(menang)
        printf("\nYEAAAY! PEMAIN %c MENANG! CONGRATULATIONS! \n", pemain);
    else
        printf("\nIT'S A DRAW! KALIAN SAMA KUAT!\n");

    printf("\nTerima kasih sudah bermain!\n");

    return 0;
}