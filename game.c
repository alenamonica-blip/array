#include <stdio.h>
#include <stdlib.h>

char c[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

int main (int argc, char *argv[]) {
    int pilihan, baris, kolom;
    char pemain = 'X';
    int menang = 0, langkah = 0;

    printf("\n");
    printf(" TIC TAC TOE GAME\n");
    printf(" Pemain X vs Pemain O\n");
    printf(" Pilih kotak bedasarkan angka!\n");

    while(langkah < 9 && menang == 0) {

        printf("\n");

        for(int baris=0; baris<3; baris++) {
            for(int kolom=0; kolom<3; kolom++) {
                printf("%c", c[baris][kolom]);

                if(kolom < 2)
                printf("|");
            }
            printf("\n");

            if(baris < 2)
            printf("-----\n");
        }

        printf("\nGiliran Pemain %c\n", pemain);
        printf("Pilih kotak (1-9): ");

        if(scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka!\n");
            return 1;
        }

        if(pilihan < 1 || pilihan > 9) {
            printf("Pilihan tidak valid! Coba lagi.\n");
            continue;
        }
        baris = (pilihan -1) / 3;
        kolom = (pilihan -1) % 3;

        if(c[baris][kolom] =='X' || c[baris][kolom] =='O'){
            printf("Kotak sudah terisi! Pilih kotak lain.\n");
            continue;
        }

        c[baris][kolom] = pemain;
        langkah++;

        for(int i=0; i<3; i++) {

            if(c[i][0] == pemain && c[i][1] == pemain && c[i][2] == pemain) menang = 1;
            if(c[0][i] == pemain && c[1][i] == pemain && c[2][i] == pemain) menang = 1;
        }

        if(c[0][0] == pemain && c[1][1] == pemain && c [2][2] == pemain) menang = 1;
        if(c[0][2] == pemain && c[1][1] == pemain && c [2][0] == pemain) menang = 1;

        if(menang == 0 && langkah < 9) {
            if(pemain == 'X')
            pemain = 'O';
            else
            pemain = 'X';
        }
    }

    printf("\n");
    printf("Hasil permainan\n");

for(int baris=0; baris<3; baris++) {
    for(int kolom=0; kolom<3; kolom++) {
        printf("%c",c[baris][kolom]);

        if(kolom < 2)
        printf("|");
    }
    printf("\n");

    if (baris < 2)
    printf("-----\n");
}
    
if(menang == 1) {
    printf("\n");
    printf("CONGRATULATION, CHAMPION!\n");
}
else {
    printf("\n");
    printf("IT'S A DRAW!\n");
}

printf("Terima kasih sudah bermain!\n");

return 0;
}