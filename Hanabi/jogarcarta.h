#ifndef _JOGARCARTA_
#define _JOGARCARTA_

#include "Deck.h"

#include "Descarte.h"

void playCARD (carta J1[],carta J2[],carta deck[],carta discard[],int turno,int  pos,int *green, int *blue ,int *purple , int *red, int *yellow,int *pistas,int *vidas,int *pontuacao)
{
	int aux_pos;
	int aux_pistas;
	int aux_pontuacao;
	int g=*green;
	int r=*red;
	int b=*blue;
	int p=*purple;
	int y=*yellow;
	int cores[5]={2,3,4,5,6};
	int num_da_pilha[5]={g,b,r,p,y};
	int i,j;
	int aux_vidas;
	int tamanho;
	int verdade;
	aux_pos= pos - 1;
	
	do
	{
		tamanho++;
		i++;
	}while(discard[i].num != 0);
	
			verdade = 0;
			
			i=0;
if(turno == 0)
{
	for(i=0;i<5;i++)
	{
		if(J1[aux_pos].cor == cores[i])
		{
			if(J1[aux_pos].num == num_da_pilha[i] + 1)
			{
			num_da_pilha[i]=num_da_pilha[i]+1;
			
				if(J1[aux_pos].num == 5)
				{
					*pistas=*pistas+1;
				}
			verdade = 1;
			
			*pontuacao=*pontuacao+1;		
			aux_pontuacao=*pontuacao;
					
			draw_card(&J1[aux_pos],deck);
			
			printAll_PlayerCards ( J1,J2, turno);
			
			atualizarPontuacao(aux_pontuacao);
			escrever_pilha_na_mesa(num_da_pilha[1],num_da_pilha[2],num_da_pilha[3],num_da_pilha[4],num_da_pilha[5]);
			}	
			else
			{
				if(	verdade == 1)
				{
				*vidas=*vidas-1;
				aux_vidas=*vidas;
				
				discard[tamanho].num=J1[aux_pos].num;
				discard[tamanho].cor=J1[aux_pos].cor;	
				printALL_Discard(discard);
				draw_card(&J1[aux_pos],deck);
				printAll_PlayerCards (J1,J2 , 0);
				atualizar_pistas_vidas(aux_pistas,aux_vidas);
				}
			}
		}
	}
}

if(turno == 1)
{
	for(i=0;i<5;i++)
	{
		if(J2[aux_pos].cor == cores[i])
		{
			if(J2[aux_pos].num == num_da_pilha[i] + 1)
			{
			num_da_pilha[i] = num_da_pilha[i]+1;
			
				if(num_da_pilha[i]== 5)
				{
					*pistas=*pistas+1;
				}
			verdade = 1;	
			*pontuacao=*pontuacao+1;		
			aux_pontuacao=*pontuacao;		
			draw_card(&J2[aux_pos],deck);
			printAll_PlayerCards (J1, J2, turno);
			atualizarPontuacao(aux_pontuacao);
			escrever_pilha_na_mesa(num_da_pilha[1],num_da_pilha[2],num_da_pilha[3],num_da_pilha[4],num_da_pilha[5]);
			}	
			else
			{
				if(	verdade == 1)
				{
				*vidas=*vidas-1;
				aux_vidas=*vidas;
				
				discard[tamanho].num=J2[aux_pos].num;
				discard[tamanho].cor=J2[aux_pos].cor;	
				printALL_Discard(discard);
				draw_card(&J2[aux_pos],deck);
				printAll_PlayerCards (J1 , J2 , 1 );
				atualizar_pistas_vidas(aux_pistas,aux_vidas);
				}
			}
		}
	}
}

*green =num_da_pilha[1];
*red   =num_da_pilha[2];
*blue  =num_da_pilha[3];
*purple=num_da_pilha[4];
*yellow=num_da_pilha[5];

	
}
#endif
