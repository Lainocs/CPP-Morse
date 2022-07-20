#include <letters.h>

void createLetter(bool tab[8][8], int decal){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
        if(tab[j][i]){
            matrix.pixels->setPixelColor(matrix.Convert(i-decal, j), matrix.pixels->Color(255, 0, 0));
        }
        }
    }
}

void PrintMSG(char c, int decal){
    if(c=='A')createLetter(letter_a, decal);
    if(c=='B')createLetter(letter_b, decal);
    if(c=='C')createLetter(letter_c, decal);
    if(c=='D')createLetter(letter_d, decal);
    if(c=='E')createLetter(letter_e, decal);
    if(c=='F')createLetter(letter_f, decal);
    if(c=='G')createLetter(letter_g, decal);
    if(c=='H')createLetter(letter_h, decal);
    if(c=='I')createLetter(letter_i, decal);
    if(c=='J')createLetter(letter_j, decal);
    if(c=='K')createLetter(letter_k, decal);
    if(c=='L')createLetter(letter_l, decal);
    if(c=='M')createLetter(letter_m, decal);
    if(c=='N')createLetter(letter_n, decal);
    if(c=='O')createLetter(letter_o, decal);
    if(c=='P')createLetter(letter_p, decal);
    if(c=='Q')createLetter(letter_q, decal);
    if(c=='R')createLetter(letter_r, decal);
    if(c=='S')createLetter(letter_s, decal);
    if(c=='T')createLetter(letter_t, decal);
    if(c=='U')createLetter(letter_u, decal);
    if(c=='V')createLetter(letter_v, decal);
    if(c=='W')createLetter(letter_w, decal);
    if(c=='X')createLetter(letter_x, decal);
    if(c=='Y')createLetter(letter_y, decal);
    if(c=='Z')createLetter(letter_z, decal);
}