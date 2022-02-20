#ifndef _DESCARTEH_		//protectes from multiple including...
#define _DESCARTEH_			//... needs an #endif at bottom

#include "Deck.h"
#include "onlyPrintF.h"
#include "atualizar.h"
void printALL_Discard(carta discard[])
{
	
	int i=0,j=0;
	int soma[50];
	int cor;
	int num;
	int aux;
	int tamanho;
	
	print_grelha_base_discard();
	
	do
	{
		tamanho++;
	}while(discard[tamanho].num != 0 && discard[tamanho].cor != 0);
	
	for(i=0;i<tamanho +1 ;i++)
	{
		soma[i]=0;
	}
	
		
	for (i=0;i<tamanho+1;i++)
	{
		for(j=0;j<tamanho+1;j++)
		{
			if(discard[i].num == discard[j].num && discard[i].cor == discard[j].cor)
			{
				soma[i]=soma[i]+1;
			}
		}
	}
	
	
	for(i=0;i<tamanho + 1;i++)
	{
		cor = discard[i].cor;
		num = discard[i].num;
		if(cor==2)aux=0;
		if(cor==3)aux=1;
		if(cor==4)aux=2;
		if(cor==5)aux=3;
		if(cor==6)aux=4;
		
		gotoxy(-1+num,3+aux);
		printf("%d",soma[i]);
	}
	
}
void addDiscard(carta J1[],carta J2[],carta discard[],int turn,int *pos,carta deck[],int *pistas,int vidas,int op)
{
	int i,j;
	int tamanho;
	int aux_pos;
	int aux_pistas=*pistas;
	*pos=*pos-1;
	aux_pos=*pos;
	

	do
	{
		tamanho++;
	}while(discard[tamanho].num != 0);
	

if(aux_pistas != 8 || op == 3)
{
	switch (turn)	
	{
		case 0:{ // Jogador -> J2
			discard[tamanho].num=J2[aux_pos].num;
			discard[tamanho].cor=J2[aux_pos].cor;
			
			printALL_Discard(discard);
			
			draw_card(&J2[aux_pos],deck);
			
			printAll_PlayerCards ( J1,J2 , 1);
			break;
		}
		
		case 1 :{ // BOT -> J1
			discard[tamanho].num=J1[aux_pos].num;
			discard[tamanho].cor=J1[aux_pos].cor;	
			printALL_Discard(discard);
			draw_card(&J1[aux_pos],deck);
			
			printAll_PlayerCards (J1 ,J2, 0);
			break;
		}
		
	}
	


}


aux_pistas+1;

*pistas = aux_pistas;

	atualizar_pistas_vidas(aux_pistas, vidas);
	
	
	
}



#endif 
