#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void codifica_hex(char caracter, char cifra[]){
    int cod1 = caracter/16;
    if (cod1 > 9)
        cod1+=55;
    else cod1+=48;

    int cod2 = caracter%16;
    if(cod2 > 9)
        cod2+=55;
    else cod2+=48;

    char cod[]={(char)cod1, (char)cod2};
    strncat(cifra, cod, sizeof(cod));
}

void descodifica_hex(char caracter1, char caracter2, char cifra[]){
    if (caracter2 >= 'A')
        caracter2-=55;
    else caracter2 -=48;

    if (caracter1 >= 'A')
        caracter1 -=55;
    else caracter1 -=48;

    char caracter[] = {(int)caracter1*16 + (int)caracter2};
    strncat(cifra, caracter, sizeof(caracter));
}

char cripto = 'a';
char *texto, *cifra;

int main(){
    texto = (char *)malloc(1000 * sizeof(char));
    cifra = (char *)malloc(1000 * sizeof(char));
    cifra[0] = '\0';

    printf("-_-_-_-_-  Codificador Hexadecimal (C)  -_-_-_-_-\n");

    printf("(1) Codificar\n(2) Decodificar\n");
    while (cripto != '1' && cripto != '2'){
        printf("-> ");
        scanf(" %c", &cripto);
    }

    printf("Texto: ");
    scanf(" %[^\n]s", texto);

    switch (cripto){
        case '1':
            for(unsigned int i = 0; i < strlen(texto); i++){
                codifica_hex(texto[i], cifra);
            }
            break;
        case '2':
            for(unsigned int i = 0; i < strlen(texto); i+=2){
                descodifica_hex(texto[i], texto[i+1], cifra);
            }
            break;
    }

    printf(cifra);
}