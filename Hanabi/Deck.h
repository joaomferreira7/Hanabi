#ifndef _labh_		
#define _labh_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lab.h"

#define DECKSIZE 50
#define VISIBLE 1
#define NONVISIBLE 0

#define CARTA_A 4
#define CARTA_L 4


typedef struct carta_{
	int cor , num , vis , know_num , know_color ;
}carta;

int initBaralho_(carta deck[], int numCores, int numNums)
{ 
	
	int i=0, j=0;
	
	for(j=0;j<numCores;j++){
		for(i=0;i<numNums;i++){
			deck[i+j*numNums].cor = j+MY_COLOR_SOFT_GREEN;
			deck[i+j*numNums].num = i/2+1;
			deck[i+j*numNums].vis = 0; //rand()%2;
		}
	}
	
	
	for(j=0;j<numCores;j++){						//visibilidade
			deck[i+j*numNums-1].num = 1;	
		}
		return 0; //No Error
}
int BaralharDeck_(carta deck[], int size)
{
	
	//Baralhar as cartas	
	int j=0;
	int r=0; 
	carta aux={0,0,0};     //Fazer inicialização
	
	
	for(j=0;j<size;j++){
		r= rand()%50;
		aux=deck[j];
		deck[j]=deck[r];
		deck[r]=aux;
		
	}
	return 0; //No Error
}
int ShowDeck_(carta deck[], int numCores, int numNums)
{ 
	
	int j=0,i=0;
	
	for(j=0;j<numCores;j++){	
		for(i=0;i<numNums;i++){
				if(deck[i+j*numNums].vis !=0){
					setForeColor(deck[i+j*numNums].cor);
					printf("%d  ",deck[i+j*numNums].num);
				}
				else {	printf(" %c ",176);
				}
		
			resetColor();
		}
		printf("\n");
	}
	
}
void mostrarDECK_1_POS(carta deck[]) //     numero de cartas disponiveis para jogar
{
    int i=0;
    int contador=0;

    setForeColor(8);
    showRectAt(35,15,4,4);
    gotoxy(37,17);printf("%c",169);        //  Imprime o simbolo da parte traseira das cartas
    resetColor();

    while(deck[i].num != 0 && deck[i].cor != 0)
    {
        i++;
        contador++;
    }

 
    gotoxy(36,20);printf("%d",contador); // Digita o numero de cartas

}
int setPlayer1Hand (carta deck[], carta hand[], int quant)
{
	
	int i=0;
	
	for(i=0;i<quant;i++){
		hand[i] = deck[i];
	}
	
	for(i=quant;i<DECKSIZE-1;i++){
		deck[i]=deck[i+1];
		deck[i+1].vis=0;
	}
	//FALTA LIMPAR O VETOR NO FIM
	return 0;
}
int initBaralho(int cartaCor[], int numCores, int cartaNum[], int numNums)
{
	
	int i=0, j=0;
	
	for(j=0;j<numCores;j++){
		for(i=0;i<numNums;i++){
			cartaCor[i+j*numNums] = j+MY_COLOR_SOFT_GREEN;
		}
	}
	
	for(j=0;j<numCores;j++){
		for(i=0;i<numNums-1;i++){
			cartaNum[i+j*numNums] = j/2+1;
		}
	}
	
	/*for(j=0;j<numCores;j++){
			[i+j*10].num = 1;
		}*/
		return 0; //No Error
}
int BaralharDeck(int cartaCor[], int size, int cartaNum[]){
	
	//Baralhar as cartas	
	int j=0;
	int r=0, aux=0;
	
	
	for(j=0;j<size;j++){
		r= rand()%size;
		aux=cartaCor[j];
		cartaCor[j]=cartaCor[r];
		
		cartaCor[r]=aux;
		
		aux=cartaNum[j];
		cartaNum[j]=cartaNum[r];
		cartaNum[r]=aux;
		
	}
	return 0; //No Error
}

int ShowDeck(int cartaCor[], int numCores, int cartaNum[], int numNums){
	
	int j=0,i=0;
	
	for(j=0;j<numNums;j++){	
		setForeColor(cartaCor[i+j*numNums]);
		printf("\n");
		for(i=0;i<numCores;i++){
			printf("%d   ",cartaNum[i+j*numNums]);
		}
		printf("\n");
	}
	resetColor();
}

int ShowCartaAt(int x, int y, carta c){
	
//	if(c.vis==VISIBLE){
		setForeColor(c.cor);
		showRectAt(x,y,4,4);
		gotoxy(x+2,y+2);
		printf("%d", c.num);
//	}
//	else{
//		setForeColor(MY_COLOR_GRAY);
//		showRectAt(x,y, CARTA_A, CARTA_L);
//	}
	resetColor();
}

void destroy_card (carta *deck)                        // o num e a cor da ultima carta sao colocados a 0 ( associada à funcao darCarta) 
{
    deck[49].num=0;
    deck[49].cor=0;
}

void draw_card (carta *c,carta deck[])                    // o vetor das cartas anda 1 posicao para a esquerda e a posicao 49 é colocada a 0
{
    int aux_num;
    int aux_cor;
    int i=0;

    (*c).num=deck[0].num;                                // a primeira carta do deck vai pertence á 1 entrada da funcao
    (*c).cor=deck[0].cor;
    (*c).know_num=0;
    (*c).know_color=0;
    for (i=0;i<49;i++)                                    // roda as cartas todas 1 posicao
    {
        deck[i].num=deck[i+1].num;
        deck[i].cor=deck[i+1].cor;
    }
    destroy_card(deck);                                // ultima carta fica com o NUM !! e a COR !! a 0 !!
}

int Player1Hand_(carta deck[],carta hand[],int HANDSIZE){ // bot
	
	int i=0, aux=0;
	
	for(i=0;i<HANDSIZE;i++){
		draw_card (&hand[i],deck);
		ShowCartaAt(i*5+60,2,hand[i]);	
	}
	
	mostrarDECK_1_POS(deck);
	
}

int Player2Hand_(carta deck[],carta hand[],int HANDSIZE){ // jogador 1
	
	int i=0, aux=0;
	
	for(i=0;i<HANDSIZE;i++){
		draw_card (&hand[i],deck);	
		
		setForeColor(8);
		showRectAt(60+i*5, 22 ,4,4);
		gotoxy(62+i*5,24);
		printf("%c", 167 );
		
	}
	
	mostrarDECK_1_POS(deck);
}

void printNext (char username[],int turno ){
int aux=0;


setForeColor (11);
gotoxy(35,1);printf("                      ");
gotoxy(35,1);
	if(turno == 1 )
	{
		printf("O %s joga",username);
	}
	else
	{
		printf("O BOT joga");
	}
	
resetColor();
}



#endif
