#include <stdio.h>
#include <string.h>
#include <ctype.h>

// teste

int main()
{
    char x = 'X';
    char o = 'O';
    char jogadaComputador;                  //Declarando variáveis.
    char jogadaUsuario;

    printf("\n==== VAMOS JOGAR JOGO DA VELHA? ====\n\n");

    printf("  J | O | G  \n");
    printf("-------------\n");
    printf("  O | V | E  \n");                       //ILustração do jogo da velha.
    printf("-------------\n");
    printf("  L | H | A  \n\n");

    printf("\n=====================================\n\n");

    printf("     ESCOLHA 'X' ou 'O'     \n\n");      //Pedindo ao usuário para escolher X ou O.

    printf("'X' ou 'O': ");
    scanf("%c", & jogadaUsuario);  //Armazenando o que o usuário digitar.

    jogadaUsuario = toupper(jogadaUsuario);  //Mudando a letra para maiúscula caso o usuário digite minúscula.

    if (jogadaUsuario == x){
        jogadaComputador = o;
    }                              //Definindo o caractere para o usuário e o computador.
    else {
        jogadaComputador = x;
    }

    printf("\n- VOCE SERA: '%c'\n- E EU SEREI: '%c'\n", jogadaUsuario, jogadaComputador);
    printf("\n=====================================\n\n");

    //Altomatizando o jogo.

    int i, j;
    int jogadas = 0;
    int round = 2;
    int controle1;
    int controle2;                           //Declarando variáveis.
    int controle3;
    int vencedor = 0;
    char jogo[3][3];

    for (i = 0; i < 3; i += 1){
        for (j = 0; j < 3; j += 1){     //Preenchendo a matriz com espaços vazios.
            jogo[i][j] = ' ';
        }
    }

    printf("==== OK, AGORA VAMOS COMECAR, IREI INICIAR COM UMA JOGADA... ====\n\n");
    printf("==== ESSAS SAO AS COORDENADAS PARA JOGARMOS ====\n");

    do{
        jogo[0][0] = jogadaComputador;         //Iniciando o jogo com uma jogada.

        printf("\n 0   1   2\n");
        for (i = 0; i < 3; i += 1){
            for (j = 0; j < 3; j += 1){
                printf(" %c ", jogo[i][j]);
                if (j < 2){
                    printf("|");                  //Desenhando o jogo da velha com as coordenadas.
                }
                if (j == 2){
                    printf("  %i", i);
                }
            }
            if (i < 2){
                printf("\n-----------\n");
            }
        }

        printf("\n\n");

        int linha;
        int coluna;

        do{
            printf("==== SUA VEZ, ESCOLHA UMA DAS COORDENADAS ====\n");
            printf("= LINHA: ");
            scanf("%i", & linha);                          //Pedindo do usuário a posição que ele deseja jogar.
            printf("= COLUNA: ");
            scanf("%i", & coluna);
        }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
        //Verificando se linha e coluna são validos.

        jogadas += 1;   //Iniciando as jogadas.

        round += 1;     //Somando o round com 1.

        jogo[linha][coluna] = jogadaUsuario;       //Armazenando na matriz a linha e coluna digitado pelo usuário.

        //Realizando todas as possibilidades de jogadas do usuário.
        if (round == 3){
            if (linha == 0 && coluna == 1){
                jogo[1][1] = jogadaComputador;
                controle1 = 1;
            }
            else if (linha == 0 && coluna == 2){
                jogo[2][2] = jogadaComputador;
                controle1 = 2;
            }
            else if (linha == 1 && coluna == 0){
                jogo[0][2] = jogadaComputador;
                controle1 = 3;
            }
            else if (linha == 1 && coluna == 1){
                jogo[0][2] = jogadaComputador;
                controle1 = 4;
            }
            else if (linha == 1 && coluna == 2){
                jogo[2][0] = jogadaComputador;
                controle1 = 5;
            }
            else if (linha == 2 && coluna == 0){
                jogo[2][2] = jogadaComputador;
                controle1 = 6;
            }
            else if (linha == 2 && coluna == 1){
                jogo[0][2] = jogadaComputador;
                controle1 = 7;
            }
            else if (linha == 2 && coluna == 2){
                jogo[2][0] = jogadaComputador;
                controle1 = 8;
            }
        }

        else if (round == 5){
            if (controle1 == 1){
                if (linha == 0 && coluna == 2){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                    controle2 = 1;
                }
            }
            else if (controle1 == 2){
                if (linha == 0 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[2][0] = jogadaComputador;
                    controle2 = 2;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
            }
            else if (controle1 == 3){
                if (linha == 0 && coluna == 1){
                    jogo[2][2] = jogadaComputador;
                    controle2 = 3;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
            }
            else if (controle1 == 4){
                if (linha == 0 && coluna == 1){
                    jogo[2][1] = jogadaComputador;
                    controle2 = 4;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
            }
            else if (controle1 == 5){
                if (linha == 0 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 0 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[1][1] = jogadaComputador;
                    controle2 = 5;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
            }
            else if (controle1 == 6){
                if (linha == 0 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 0 && coluna == 2){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[0][2] = jogadaComputador;
                    controle2 = 6;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
            }
            else if (controle1 == 7){
                if (linha == 0 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                    controle2 = 7;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
            }
            else if (controle1 == 8){
                if (linha == 0 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 0 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[0][2] = jogadaComputador;
                    controle2 = 8;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
            }
        }
        else if (round == 7){
            if ((controle2 == 1)){
                if (linha == 0 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[0][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[0][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
            }
            else if (controle2 == 2){
                if (linha == 0 && coluna == 1){
                    jogo[2][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[2][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][0] = jogadaComputador;
                }
            }
            else if (controle2 == 3){
                if (linha == 1 && coluna == 1){
                    jogo[1][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
            }
            else if (controle2 == 4){
                if (linha == 1 && coluna == 0){
                    jogo[1][2] = jogadaComputador;
                    controle3 = 1;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                    controle3 = 2;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                    controle3 = 3;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                    controle3 = 4;
                }
            }
            else if (controle2 == 5){
                if (linha == 0 && coluna == 1){
                    jogo[0][2] = jogadaComputador;
                }
                else if (linha == 0 && coluna == 2){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[0][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[0][2] = jogadaComputador;
                }
            }
            else if (controle2 == 6){
                if (linha == 0 && coluna == 1){
                    jogo[1][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 0){
                    jogo[1][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
            }
            else if (controle2 == 7){
                if (linha == 1 && coluna == 0){
                    jogo[2][0] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                }
            }
            else if (controle2 == 8){
                if (linha == 0 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 1){
                    jogo[0][1] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][1] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 1){
                    jogo[1][1] = jogadaComputador;
                }
            }
        }
        else if (round == 9){
            if (controle3 == 1){
                if (linha == 2 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                }
                else if (linha == 2 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                    //empate
                }
            }
            else if (controle3 == 2){
                if (linha == 2 && coluna == 0){
                    jogo[2][2] = jogadaComputador;
                    //empate
                }
                else if (linha == 2 && coluna == 2){
                    jogo[2][0] = jogadaComputador;
                }
            }
            else if (controle3 == 3){
                if (linha == 1 && coluna == 0){
                    jogo[1][2] = jogadaComputador;
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                    //empate
                }
            }
            else if (controle3 == 4){
                if (linha == 1 && coluna == 0){
                    jogo[1][2] = jogadaComputador;
                    //empate
                }
                else if (linha == 1 && coluna == 2){
                    jogo[1][0] = jogadaComputador;
                }
            }
        }

        //Verificando se à vencedor.

        if ((jogo[0][0] == jogadaComputador && jogo[0][1] == jogadaComputador && jogo[0][2] == jogadaComputador) ||
            (jogo[1][0] == jogadaComputador && jogo[1][1] == jogadaComputador && jogo[1][2] == jogadaComputador) ||
            (jogo[2][0] == jogadaComputador && jogo[2][1] == jogadaComputador && jogo[2][2] == jogadaComputador)){
                printf("\n 0   1   2\n");
                for (i = 0; i < 3; i += 1){
                    for (j = 0; j < 3; j += 1){
                        printf(" %c ", jogo[i][j]);
                        if (j < 2){
                            printf("|");
                        }                                    //Imprimindo na tela a jogada vencedora.
                        if (j == 2){
                            printf("  %i", i);
                        }
                    }
                    if (i < 2){
                        printf("\n-----------\n");
                    }
                }
                printf("\n");

                printf("\n= GANHEI NA LINHA!!! VOCE PERDEU :(, OBRIGADO POR JOGAR\n\n");
                vencedor = 1;               //Atribuindo valor 1 caso tenha vencedor.
            }

        if ((jogo[0][0] == jogadaComputador && jogo[1][0] == jogadaComputador && jogo[2][0] == jogadaComputador) ||
            (jogo[0][1] == jogadaComputador && jogo[1][1] == jogadaComputador && jogo[2][1] == jogadaComputador) ||
            (jogo[0][2] == jogadaComputador && jogo[1][2] == jogadaComputador && jogo[2][2] == jogadaComputador)){
                printf("\n 0   1   2\n");
                for (i = 0; i < 3; i += 1){
                    for (j = 0; j < 3; j += 1){
                        printf(" %c ", jogo[i][j]);
                        if (j < 2){
                            printf("|");
                        }                                     //Imprimindo na tela a jogada vencedora.
                        if (j == 2){
                            printf("  %i", i);
                        }
                    }
                    if (i < 2){
                        printf("\n-----------\n");
                    }
                }
                printf("\n");

                printf("\n= GANHEI NA COLUNA!!! VOCE PERDEU :(, OBRIGADO POR JOGAR\n\n");
                vencedor = 1;              //Atribuindo valor 1 caso tenha vencedor.
            }

        if (jogo[0][0] == jogadaComputador && jogo[1][1] == jogadaComputador && jogo[2][2] == jogadaComputador){
            printf("\n 0   1   2\n");
            for (i = 0; i < 3; i += 1){
                for (j = 0; j < 3; j += 1){
                    printf(" %c ", jogo[i][j]);
                    if (j < 2){
                        printf("|");
                    }                                         //Imprimindo na tela a jogada vencedora.
                    if (j == 2){
                        printf("  %i", i);
                    }
                }
                if (i < 2){
                    printf("\n-----------\n");
                }
            }
            printf("\n");

            printf("\n= GANHEI NA DIAGONAL PRINCIPAL!!! VOCE PERDEU :(, OBRIGADO POR JOGAR\n\n");
            vencedor = 1;                   //Atribuindo valor 1 caso tenha vencedor.
        }

        if (jogo[0][2] == jogadaComputador && jogo[1][1] == jogadaComputador && jogo[2][0] == jogadaComputador){
            printf("\n 0   1   2\n");
            for (i = 0; i < 3; i += 1){
                for (j = 0; j < 3; j += 1){
                    printf(" %c ", jogo[i][j]);
                    if (j < 2){
                        printf("|");
                    }                                         //Imprimindo na tela a jogada vencedora.
                    if (j == 2){ 
                        printf("  %i", i);
                    }
                }
                if (i < 2){
                    printf("\n-----------\n");
                }
            }
            printf("\n");

            printf("\n= GANHEI NA DIAGONAL SECUNDARIA!!! VOCE PERDEU :(, OBRIGADO POR JOGAR\n\n");
            vencedor = 1;                   //Atribuindo valor 1 caso tenha vencedor.
        }

        round += 1;
    }while (vencedor == 0 && jogadas < 4);  //Caso não haja vencedor o loop continua.

    if (vencedor == 0){             //Condição para impressão de empate.
        printf("\n 0   1   2\n");
        for (i = 0; i < 3; i += 1){
            for (j = 0; j < 3; j += 1){
            printf(" %c ", jogo[i][j]);
                if (j < 2){
                printf("|");
                }
                if (j == 2){
                printf("  %i", i);
                }
            }
            if (i < 2){
            printf("\n-----------\n");
            }
        }
    printf("\n");

        printf("\nEMPATAMOS 'DEU VELHA', NAO HOUVE VENCEDOR :)\n\n");
    }

    return 0;
}