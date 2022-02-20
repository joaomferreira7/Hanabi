#ifndef _ONLYPRINTF_		//protectes from multiple including...
#define _ONLYPRINTF_		//... needs an #endif at bottom

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "global.h"
void printf_Hannabi  ()
{
	system ("CLS");	
	printf("\n\n");
    	printf("\t##     ##    ###    ##    ##    ###    ########  ####\n");                             
		printf("\t##     ##   ## ##   ###   ##   ## ##   ##     ##  ## \n");
		printf("\t##     ##  ##   ##  ####  ##  ##   ##  ##     ##  ## \n");
		printf("\t######### ##     ## ## ## ## ##     ## ########   ## \n");
		printf("\t##     ## ######### ##  #### ######### ##     ##  ## \n");
		printf("\t##     ## ##     ## ##   ### ##     ## ##     ##  ## \n");
		printf("\t##     ## ##     ## ##    ## ##     ## ########  ####\n");
}
void printf_Progamers ()
{
		gotoxy(5,10);
		printf("Realizado por Joao Monteiro Ferreira 70580, Simao Pedro da Silva Lopes 70623, Felipe Torres Barbosa 70815\n");
		gotoxy(5,11);
		printf("Turma 7 de Engenharia Informatica\n");
}
void printf_menu_Inicial ()
{
	printf_Hannabi();
	printf_Progamers();
		system("pause");
}
void printf_opcoes_de_incio()
{
		gotoxy(50,10);
		printf("\n\t\t Menu:\n\t\t 1-Iniciar;\n\t\t 2-Save;\n\t\t 3-Informacoes;\n\t\t 4-Sair;\n");		
}
void printf_menu_Inicial_2 ()
{
	printf_Hannabi();
	printf_opcoes_de_incio();
	
}
void printOPCOES ()                                                         // imprime as opcoes de jogo
{
    setForeColor(11);
    showRectAt( 5, 15 , 17,  5);
    setForeColor(15);
    gotoxy(7,16);    printf("Dar Pista - 1  ");
    gotoxy(7,17);    printf("Descartar - 2  ");
    gotoxy(7,18);    printf("Jogar     - 3  ");
    gotoxy(7,19);    printf("SAIR      - 4  ");
    gotoxy(7,21);    printf("       ");                                        // limpa enventuais numeros pre existentes
    gotoxy(7,21);                                                            // move o cursos para a posicao ( 7 , 20 )
}
void clearOPCOES ()                                                         // limpa o quadro das opcoes
{
    gotoxy(7,16);    printf("              ");
    gotoxy(7,17);    printf("              ");
    gotoxy(7,18);    printf("              ");
    gotoxy(7,19);    printf("              ");
}
void ask_name (char username [])
{
	int tamanho_do_nome=0;
	
			printf("Insira o seu nome\n");
			do{
                gets(username);
                tamanho_do_nome=strlen(username);
                
                if (tamanho_do_nome > 16)
                    printf("Muito Grande - Maximo 16 caracteres \n\n");
							
              }while(tamanho_do_nome > 16);
            system("cls");
}
void printTopicos (char nome[])
{
	
			gotoxy(100,1);
			printf("Play history");
			
			gotoxy(1,1);
			printf("Discard");
			
			gotoxy(35,2);
			printf("Lives");
			
			gotoxy(35,6);
			printf("Clues");
			
			gotoxy(71,1);
			printf("BOT");
			
			gotoxy(35,14);
			printf("Deck");
			
			gotoxy(71,27);
			printf("%s", nome);
			
			gotoxy(1,10);
			resetColor();
}
void print_grelha_base_discard()
{
	int j=0,i=0;

    setForeColor(2);gotoxy(7,3);    printf("VERDE");                    // CORES
    setForeColor(3);gotoxy(7,4);    printf("AZUL");
    setForeColor(4);gotoxy(7,5);    printf("VERMELHO");
    setForeColor(5);gotoxy(7,6);    printf("ROXO");
    setForeColor(14);gotoxy(7,7);    printf("AMARELO");
    resetColor();

    gotoxy(0,9);    printf("12345");                                            // NUMEROS


    for (j=0;j<5;j++)                                                        // coloca zeros em todas as posicoes da grelha
    {
        for(i=0;i<5;i++)
        {
            gotoxy(i,3+j);
            printf("0");
        }
    }
    
}
void print_instrucoes ()
{
	system("cls");
printf("\t\t\t\t\t\t\tSobre o jogo\n\n");
printf("\t\t\tHistória\n\n")	;
printf("\tHanabi é a palavra japonesa para fogo-de-artificio e é também o nome de um jogo de cartas cooperativo no qual os jogadores\n");
printf("ajudam-se uns aos outros para criar um espectáculo de fogo-de-artifício, em que para tal se joga cartas da mão para a mesa numa \n");
printf("determinada ordem de forma a criar sequências de cor.\n");
printf("\tCoube ao Hanabi a honra de vencer a edição de 2013 do Spiel des Jahres. Os outros dois nomeados desta edicao foram o Qwixx de\n");
printf("Steffen Benndorf e o Augustus de Paolo Mori.\n\n");
printf("\t\t\tComposição\n\n");
printf("\tBaralho 50 cartas\n");
printf("\t10 cartas de cada uma das 5 cores (verde, azul, roxo, amarelo, vermelho)\n");
printf("\tCada conjunto de uma cor existem as cartas, três números 1, dois números 2,dois números 3, dois números 4 e apenas um número 5\n");
printf("\t8 pistas\n");
printf("\t3 vidas\n\n");
printf("\t\t\tRegras\n");
printf ("\tOs jogadores entao fazem sua jogada e o jogo sempre segue no sentido horario. Em seu turno\n");
printf ("\tum jogador deve realizar uma, e somente uma das tres acoes abaixo\n");
printf ("\t1 - Dar uma pista em relaçao à cor ou ao número\n");
printf ("\t2 - Descartar uma carta\n");
printf ("\t3 - Jogar uma carta\n");
printf ("\tO jogador joga uma carta da mao e a coloca a na mesa de jogo.\n");
printf ("\tSe a carta nao se encaixa em nenhuma sequencia de fogos é descartada para o descarte\n");
printf ("\tO jogo termina quando a pontuaçao chega a 25 ou quando acabam as 3 vidas ou quando acabam as cartas\n\n\n");
system("pause");
system("cls");
}

void DarPista_OP ()                                                         // Menu das pistas
{
    gotoxy(7,16);    printf("    Número   1");
    gotoxy(7,17);    printf("     Cor     2");
    gotoxy(7,18);    printf("              ");
    gotoxy(7,19);    printf("    Voltar   3");
    gotoxy(7,21);  printf("       ");                                        // limpa enventuais numeros pre existentes
    gotoxy(7,21);                                                            // move o cursos para a posicao ( 7 , 20 )
}

void printMENU_pos ()                                                         // perguntar Posicao
{
    gotoxy(7,16);    printf("   Posição    ");                                // pede uma posicao a utilizador
    gotoxy(7,17);    printf("     da       ");
    gotoxy(7,18);    printf("    Carta     ");
    gotoxy(7,19);    printf("  0 - Voltar  ");
    gotoxy(7,21);  printf("       ");                                        // limpa enventuais numeros pre existentes
    gotoxy(7,21);                                                            // move o cursos para a posicao ( 7 , 20 )
}
void printfErroPistas (int p)
{
	if(p==0)
	{
	gotoxy(7,21);printf("Não é possivel dar uma pista");
	delay(1);
	gotoxy(7,21);printf("                            ");
	gotoxy(7,21);
	}
}
void printAll_PlayerCards (carta P[], carta P2[], int turno)
{
	int pos;
	int i=0;



	for (i=0;i<5;i++)
	{
		setForeColor(P[i].cor);
		showRectAt(60+i*5, 2 ,4,4);
		gotoxy(62+i*5,4);
		printf("%d", P[i].num);
		
		setForeColor(8);
		showRectAt(60+i*5, 22 ,4,4);
		gotoxy(62+i*5,24);
		printf("%c", 167 );
		
			resetColor();
		if (P2[i].know_num == 1)
		{
			showNumAt (62+i*5,24,P[i].num);
		}
			
		if(P2[i].know_color == 1)
		{
			setForeColor(P2[i].cor);
			showRectAt(60+i*5,22,4,4);
			setForeColor(15);
		}
		
	}	


	resetColor();
}

/*	
		turno == 1 || humano joga
		
		if (P[i].know_num == 1)
		{
			showNumAt (62+i*5,24,P[i].num);
		}
			
		if(P[i].know_color == 1)
		{
			setForeColor(P[i].cor);
			showRectAt(60+i*5,22,4,4);
			setForeColor(15);
		}
 */
#endif
