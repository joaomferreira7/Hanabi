#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "lab.h"
#include "Deck.h"
#include "onlyPrintF.h"
#include "atualizar.h"
#include "Pistas.h"
#include "Descarte.h"
#include "jogarcarta.h"
#include "botcode.h"

#define HANDSIZE 5


void SaveAllVariables (const char *filename,int pistas,int vidas,int pontuacao,int turno)
{
   FILE *fp = fopen(filename, "w");
   
   if(fp==NULL)
   {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
   }
   
   fprintf(fp,"%d,%d,%d,%d",pistas,vidas,pontuacao,turno);
   fclose(fp);
}
void SaveP1Cards (const char *filename,carta J1[])
{
	FILE *fp = fopen(filename, "w");
     int i=0;
   if(fp==NULL)
   {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
   }
   
   for(i=0;i<5;i++)
   {
   fprintf(fp,"%d,%d,%d,%d\n",J1[i].num,J1[i].know_num,J1[i].cor,J1[i].know_color);
   }
   fclose(fp);
}
void SaveP2Cards (const char *filename,carta J2[])
{
	FILE *fp = fopen(filename, "w");
   int i=0;
   if(fp==NULL)
   {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
   }
   
   for(i=0;i<5;i++)
   {
   fprintf(fp,"%d,%d,%d,%d\n",J2[i].num,J2[i].know_num,J2[i].cor,J2[i].know_color);
   }
   fclose(fp);
}
void SaveDiscard (const char *filename, carta descarte[])
{
	int i=0;
	FILE *fp = fopen(filename, "w");
    if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
   
    for(i=0;i<50;i++)
    {
    fprintf(fp,"%d,%d\n",descarte[i].num,descarte[i].cor);
    }
    fclose(fp);
}
void SaveDeck (const char *filename, carta deck[])
{
	int i=0;
	FILE *fp = fopen(filename, "w");
    if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
   
    for(i=0;i<50;i++)
    {
    fprintf(fp,"%d,%d\n",deck[i].num,deck[i].cor);
    }
    fclose(fp);
}
void LoadVariables (const char *filename,int *pistas,int *vidas,int *pontuacao,int *turno)
{
	FILE *fp = fopen(filename, "r");
	
	int pis;
	int vid;
	int pon;
	int turn;
	char *commas;
    if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
    
    
    fscanf(fp,"%d%c%d%c%d%c%d",&pis,&commas,&vid,&commas,&pon,&commas,&turn);


	*pistas=pis;
	*vidas=vid;
	*pontuacao=pon;
	*turno=turn;
	fclose(fp);
}
void LoadPlayer (const char *filename,carta J1[])
{
	int i=0;
	FILE *fp = fopen(filename, "r+");
	char *commas;
	char ch;
    char line[512];
	if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
    int cur_line = 0;
    
    while(fgets(line, 512, fp) != NULL) {
/* get a line, up to 512 chars from in.  done if NULL */
     sscanf (line,"%d%c%d%c%d%c%d\n",&J1[cur_line].num,&commas,&J1[cur_line].know_num,&commas,&J1[cur_line].cor,&commas,&J1[cur_line].know_color);
     cur_line++;	
} 

}
void LoadPlayer_2 (const char *filename,carta J2[])
{
	int i=0;
	FILE *fp = fopen(filename, "r+");
	char *commas;
	char ch;
    char line[512];
	if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
    int cur_line = 0;
    
    while(fgets(line, 512, fp) != NULL) {
/* get a line, up to 512 chars from in.  done if NULL */
     sscanf (line,"%d%c%d%c%d%c%d\n",&J2[cur_line].num,&commas,&J2[cur_line].know_num,&commas,&J2[cur_line].cor,&commas,&J2[cur_line].know_color);
     cur_line++;	
} 

}
void LoadDiscard (const char *filename,carta descarte[])
{
	int i=0;
	FILE *fp = fopen(filename, "rt");
	char *commas;
	char ch;
    char line[512];
	if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
    int cur_line = 0;
    
    while(fgets(line, 512, fp) != NULL) {
/* get a line, up to 512 chars from in.  done if NULL */
     sscanf (line,"%d%c%d\n",&descarte[cur_line].num,&commas,&descarte[cur_line].cor);
     cur_line++;	
     } 
	     
}
void LoadDeck (const char *filename,carta deck[])
{
		int i=0;
	FILE *fp = fopen(filename, "rt");
	char *commas;
	char ch;
    char line[512];
	if(fp==NULL)
    {
   	system("cls");
   	printf("File not open");
	system("pause");
   	exit(0);
    }
    int cur_line = 0;
    
    while(fgets(line, 512, fp) != NULL) {
/* get a line, up to 512 chars from in.  done if NULL */
     sscanf (line,"%d%c%d\n",&deck[cur_line].num,&commas,&deck[cur_line].cor);
     cur_line++;	
     } 
}




void main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	int azul,vermelho,amarelo,roxo,verde;
	int linha,coluna;
	char nome[16];
	int turno=rand () % 2;						// 1 -> jogador joga  |||  0 -> BOT joga
	int j, i, c[50], hand[5];
	int menu,menu2,menu3,vidas=3,pistas=8;
	carta discard[50];
	carta my_deck[50];
	carta player1HAND[HANDSIZE];
	carta player2HAND[HANDSIZE];
	int pos;
	int verdade;
	int pontuacao=0;
	int BOT_jogou=0;
	
	ask_name(nome);	

	printf_menu_Inicial();
	
	while(1){
		
		printf_menu_Inicial_2();		
		
		scanf("%d", &menu);
		switch(menu){
			
			case 1:{
			system("cls");
			resetarVariaveis(&pistas,&vidas,discard,&azul,&vermelho,&amarelo,&roxo,&verde,&pontuacao);
			initBaralho_(my_deck, 5, 10);
			BaralharDeck_(my_deck, 50);			
			Player1Hand_(my_deck, player1HAND, HANDSIZE);
			Player2Hand_(my_deck, player2HAND, HANDSIZE);
			print_grelha_base_discard();
		
			turno = 0;
			
			escolher_opcao :
			
			SaveAllVariables ("variaveis.txt", pistas, vidas, pontuacao, turno);
			SaveP1Cards ("J1Hand.txt",player1HAND);
			SaveP2Cards ("jogador2.txt",player2HAND);
			SaveDiscard ("descarte.txt ",  discard);
			SaveDeck("deck.txt",my_deck);
			
			printNext ( nome ,  turno );
			verdade = 1;
			mostrarDECK_1_POS(my_deck);
			escrever_pilha_na_mesa ( verde, azul , vermelho , roxo, amarelo);
			printTopicos(nome);
			atualizar_pistas_vidas(pistas,vidas);
			atualizarPontuacao(pontuacao);
			printOPCOES();
			
			BOT_jogou = 0;
			
			if ( turno == 0)
			{
			primeira_condicao_BOT ( player2HAND , &turno, &pistas ,  vidas,  nome ,  pontuacao ,  discard  , &BOT_jogou );
			segunda_condicao_BOT (	player1HAND , player2HAND , &verde , &vermelho , &azul , &roxo, &amarelo, nome , my_deck, &pontuacao, &BOT_jogou, &pistas);
			terceira_condicao_BOT ( player2HAND , player1HAND,  turno,  nome, verde , vermelho , azul , amarelo , roxo , &pistas, vidas, &BOT_jogou);
			quarta_condicao_BOT ( player2HAND , player1HAND  , discard  , &BOT_jogou, &pistas,  vidas  , my_deck ,verde , vermelho , azul , amarelo , roxo  , turno );
			delay(1);
			swap(&turno);
			goto escolher_opcao;
			}

			do
			{
			scanf("%d",&menu2);
			switch (menu2){
				case 1:
				{
				clearOPCOES();
				DarPista_OP();
				scanf("%d",&menu3);
				
				switch(menu3){
					case 1:{
						if(pistas != 0)
						{
						printMENU_pos();
						scanf("%d",&pos);
						if(pos == 0)
						{
						verdade = 0;
						goto escolher_opcao;
						}
						else
						{
						showCLUE( menu3,  player1HAND , player2HAND , turno, &pos, &pistas,vidas);
						swap(&turno);
						goto escolher_opcao; 
						break;
						}
						}
						else
						{
						verdade = 0;
						goto escolher_opcao;
						}
					}
					case 2:{
						printMENU_pos();
						scanf("%d",&pos);
						if(pos == 0)
						{
						verdade = 0;
						goto escolher_opcao;
						}
						else
						{
						showCLUE( menu3,  player1HAND , player2HAND , turno, &pos, &pistas,vidas);
						swap(&turno);
						goto escolher_opcao ;
						break;
						}
					}
						
					case 3:	
					{
					verdade = 0;
					goto escolher_opcao; break;
					}
				}
				}
				case 2:{
				if(pistas != 8)
				{
				printMENU_pos();
				scanf("%d",&pos);
				if(pos == 0)
				{
				verdade = 0;
				goto escolher_opcao;
				}
				else
				{
				addDiscard( player1HAND , player2HAND , discard , turno , &pos, my_deck, &pistas,vidas, 2); 
				swap(&turno);
				goto escolher_opcao ;
				break;
				}
				}
				else
				{
				verdade = 0;
				goto escolher_opcao;	
				}
				}
				case 3:{
				printMENU_pos();
				scanf("%d",&pos);
				if(pos == 0)
				{
				verdade = 0;
				goto escolher_opcao;
				}
				else
				{
				playCARD ( player1HAND, player2HAND , my_deck ,  discard , turno, pos, &verde, &azul , &roxo , &vermelho , &amarelo ,  &pistas, &vidas,&pontuacao);
				swap(&turno);
				goto escolher_opcao ;
				break;
				}
			}
				case 4:{
					break;
				}
			}
			}while( menu2 != 4 || pontuacao == 25 || vidas == 0);
		
			break;
		}
			case 2:
			{
			LoadVariables ("variaveis.txt", &pistas, &vidas, &pontuacao, &turno);
			LoadPlayer("J1Hand.txt",player1HAND);
			LoadPlayer_2 ("jogador2.txt", player2HAND);
			LoadDiscard ("descarte.txt ",discard);
			LoadDeck("deck.txt",my_deck);
				
				
			system("cls");
			escrever_pilha_na_mesa ( verde,azul,vermelho,roxo,vermelho);
			printALL_Discard(discard);
			printAll_PlayerCards (player1HAND , player2HAND , turno);
			goto escolher_opcao ;	
			break;
			} 
			case 3:{
				
				print_instrucoes();				
			break;
		}
			case 4: 
				system ("CLS"); 
				exit(0);
			break;
		}
	}
}


	
