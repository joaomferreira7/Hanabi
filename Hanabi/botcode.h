#ifndef _BOTCODE_		//protectes from multiple including...
#define _BOTCODE_		//... needs an #endif at bottom

#include <stdio.h>
#include <stdlib.h>
#include "atualizar.h"
#include "lab.h"
#include "deck.h"
#include "Descarte.h"
void primeira_condicao_BOT ( carta J1[],int *turno,int *pistas , int vidas,char nome[], int pontuacao , carta descarte [] ,int *BOT_jogou ) 
{
	
	int i=0;
	int numero=0;
	int aux_pistas = *pistas;
	int verdade=0;

	   
	
	while(descarte[i].num !=0 )
	{
		
	i++;	
	}
	
	
if( aux_pistas == 8 && pontuacao == 0 && vidas == 3 && i == 0 )
{	
	for (i=0;i<5;i++)
	{
		if(J1[i].num == 1 ) 
		{

		J1[i].know_num = 1 ;
		numero=J1[i].num;
		showNumAt(i*5+62,24,numero);
		verdade = 1 ;							
		}
	}

	}
	if(verdade == 1)
	{
		*pistas = *pistas - 1 ;
		aux_pistas = *pistas;
		*BOT_jogou = 1;
	}
	
	atualizar_pistas_vidas(aux_pistas,vidas);
	
}
void segunda_condicao_BOT (carta J2[] ,carta J1[], int *green ,int *red ,int *blue ,int *yellow ,int *purple,char username[],carta deck[],int *pontuacao,int *BOT_jogou,int *pistas)
{
	int possivel_jogar[5];
	int numeros[5];
	int i=0,j=0;
	int cor=0;
	int coordenada =0;
	int aux_pontuacao  = *pontuacao;
	int sair = 0;
	
	int aux_BOT = *BOT_jogou;
	
	int g = *green;
	int b = *blue;
	int r = *red;
	int w = *purple;
	int y = *yellow;
	

	sair = 0;

if(aux_BOT == 0)
{
	for(i=0;i<5;i++)
	{
		if(J2[i].know_num == 1)
		{
			if(J2[i].know_color == 1)
			{
					if(J2[i].cor == 2) {cor=g ; coordenada=0; }
					if(J2[i].cor == 3) {cor=b ; coordenada=1; }
					if(J2[i].cor == 4) {cor=r ; coordenada=2; }
					if(J2[i].cor == 5){cor=w ; coordenada=3; }
					if(J2[i].cor == 6) {cor=y ; coordenada=4; }
					
						if(J2[i].num == cor+1 && sair == 0)// entrou na pilha 
						{
						cor=cor + 1 ;
						if( *pistas != 8)
						{
							if(cor==5)
								{
									*pistas=*pistas+1;
								}
							}		
						
					
						draw_card(&J2[i],deck);
						printAll_PlayerCards ( J1,  J2,  0);
						mostrarDECK_1_POS(deck);
						*pontuacao = *pontuacao + 1 ;
						aux_pontuacao = *pontuacao;
						gotoxy(30,3);printf("%d",pontuacao);
												
						if (coordenada == 0){ g=g+1; *green  = g;}
						if (coordenada == 1){ b=b+1; *blue   = b;}
						if (coordenada == 2){ r=r+1; *red    = r;}
						if (coordenada == 3){ w=w+1; *purple  = w;}
						if (coordenada == 4){ y=y+1; *yellow = y;}
						
						escrever_pilha_na_mesa(g,b,r,w,y);
						
						sair++;
						}					
			}
		}
	}
}

	if(sair != 0)
	{
		*BOT_jogou = 1;	
	}	
}
void terceira_condicao_BOT ( carta J1[] ,carta J2[], int turno, char username[],int green ,int red ,int blue ,int yellow ,int white ,int *pistas,int vidas, int *BOT_jogou)
{
srand(time(NULL));

int i,j;
int aux_pistas = *pistas;
int cores[5]={2,3,4,15,14};
int num_da_pilha[5]={green,blue,red,white,yellow};
int carta_jogavel[5];
int sair = 0;
int numero;
int cor;

int menor = J1[0].num;
int pos_menor ;

int aux_rand_cor;

int aux_BOT = *BOT_jogou;

sair = 0;



for(j=1;j<5;j++) // ve qual é o menor num 
{
	if(J1[j].num < menor)
	{
	menor = J1[j].num;
	pos_menor = j;
	}
}


if(aux_pistas > 0 && aux_BOT == 0)
{
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(J1[i].cor == cores[j] )
			{
				if(J1[i].num == num_da_pilha[j] + 1 )
				{
				carta_jogavel[i] = 1; 
				}
				else
				{
				carta_jogavel[i] = 0;
				}
			}
		}
	}
	
	for(i=0;i<5;i++)
	{	
		if(carta_jogavel[i] == 1 && sair == 0)
		{
			if (J1[i].know_num == 1 )
			{
				if(J1[i].know_color == 1) // nao da pista
				{
					
				}
				else			// da a pista de uma cor
				{
					if(J1[i].know_color == 0)
					{
						for(j=0;j<5;j++)
						{
							if (J1[j].cor == J1[i].cor)		// da pistas sobre todos as cores iguais 
							{
							J1[j].know_color = 1; 	
							cor=J1[j].cor;
							setForeColor(cor);
							showRectAt(5+j*60,22,4,4);
							resetColor();						
							sair ++;
						
						
						
							}
						}
					}			
				}
			}
			else	// vai dar a pista de um numero 
			{
				if(J1[i].know_num == 0 )	
				{
					for (j=0;j<5;j++)
					{
						if (J1[j].num == J1[i].num) // da pistas sobre todos os num iguais 
						{
						
						J1[j].know_num = 1; 	
						numero=J1[j].num;
						showNumAt(j*5+62,24,numero);
				
						sair ++ ;
					
					
						}
					} 
				}
			}		
		}
		else
		{
			if(sair != 0)
			{
				if(J1[i].know_num == 0 && carta_jogavel[i] == 0 && sair == 0) // numero nao jogavel e desconhecido para o jogador 1
				{				
					for (j=0;j<5;j++)
					{
						if (J1[j].num == menor) // da pistas sobre todos os num iguais 
						{
						J1[j].know_num = 1; 	
						showNumAt(j*5+62,24,menor);
					
						sair ++ ;
					
			
						}
					} 
				}
			}
		}
	}
}



		for (i=0;i<5;i++)// dizer cor aleatoria 
		{
			if(J1[i].know_color == 0 &&carta_jogavel[i] == 0  && sair == 0 && aux_pistas > 0 && aux_BOT == 0)
			{
				
				do
				{
					aux_rand_cor = rand () % 5;	
											
				}while(J1[aux_rand_cor].know_color == 1);
			
				
				for(j=0;j<5;j++)
				{
					if (J1[j].cor == J1[aux_rand_cor].cor)		// da pistas sobre todos as cores iguais 
					{
					J1[j].know_color = 1; 	
					cor=J1[j].cor;
					setForeColor(cor);
					showRectAt(60+j*5,22,4,4);
					resetColor();						
					sair ++;
					
					
					}
				}	
			}
		}






		if( sair != 0)				// se deu a pista vai as atualizar
		{
		aux_pistas = aux_pistas - 1; 
		atualizar_pistas_vidas(aux_pistas,vidas);
		
		*BOT_jogou = 1;	
		}








*pistas = aux_pistas;

}
void quarta_condicao_BOT (carta J1[] , carta J2[] ,carta descarte[], int * BOT_jogou, int *pistas, int vidas  , carta deck[],int green ,int red ,int blue ,int yellow ,int roxo , int turno )
{
	int aux_BOT = *BOT_jogou;
	int aux_pistas = *pistas;
	int i=0,j=0;
	int sair = 0;
	int menor = J1[0].num;
	int pos_menor; 

	int cores[5]={2,3,4,15,14};
	int num_da_pilha[5]={green,blue,red,roxo,yellow};
	int carta_descartavel[5];
	int *aux_rand;
	
	
	for (i=0;i<5;i++)
	{
		if(J2[i].know_color == 1 && J2[i].know_num == 1)
		{
			for(j=0;j<5;j++)
			{
				if(J2[i].cor == cores[j] )
				{
					if(J2[i].num <= num_da_pilha[j]  ) // averigua se a carta é conhecida e pode ser descartavel
					{
					carta_descartavel[i] = 1; 
					}
					else
					{
					carta_descartavel[i] = 0;
					}
				}
			}
		}
		else
		{
			carta_descartavel[i] = 0;	
		}
	}
	
	
	
	
		sair = 0;
	
	if( aux_BOT == 0 )
	{
		for(i=0;i<5;i++)
		{
			if(J2[i].know_num == 0 && J2[i].know_color == 0 && sair == 0) // descarta carta desconhecida || num e cor ||
			{
				
				do
				{
				*aux_rand = rand() % 5 ;	
				}while(J2[i].know_num != 0 && J2[i].know_color != 0);
				
				addDiscard( J1 , J2 , descarte,  turno , aux_rand +1  , deck , pistas, vidas, 3 );
		
				sair++ ;
			}
		}
		
		for(i=0;i<5;i++)
		{
				if( sair == 0 && J2[i].know_num == 1 && carta_descartavel[i] == 1) // descarta carta desnecesaria
				{
					*aux_rand = i;
					addDiscard( J1 , J2 , descarte,  turno , aux_rand +1  , deck , pistas, vidas, 3 );
			
					sair++;
				}
		}
	
		for(i=0;i<5;i++)
			{
					if(( J2[i].know_num == 1 ||  J2[i].know_color == 1) && sair == 0 )
					{
						do
						{
						*aux_rand = rand() % 5 ;
						}while(J2[i].know_num == 0 && J2[i].know_color == 0);
						addDiscard( J1 , J2 , descarte,  turno , aux_rand +1  , deck , pistas, vidas, 3 );
				
						sair++;
					}
			}
	}


}
	




#endif
