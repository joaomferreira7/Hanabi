#ifndef _PISTASH_		//protectes from multiple including...
#define _PISTASH_		//... needs an #endif at bottom

#include "Deck.h"
void ajuda_evidenciarPISTA()
{
	int i=0;
	for (i=0;i<5;i++)
	{

		setForeColor(8);
		showRectAt(60+i*5, 22 ,4,4);
		gotoxy(62+i*5,24);
		printf("%c", 167 );
		
		setForeColor(8);
		showRectAt(60+i*5, 2 ,4,4);
		gotoxy(62+i*5,4);
		printf("%c", 167 );
			}
			setForeColor(15);
}
void showCLUE(int op_num_cor, carta J1[],carta J2[], int turno,int *pos,int *pistas,int vidas)
{
	int i=0;
	int aux_pos;
	int aux_pistas = *pistas ;
	*pos=*pos-1;
	aux_pos = *pos;
	int verdade=0;
	
printfErroPistas ( aux_pistas );
if(aux_pistas != 0)
{
	if(turno == 0 ) // jogador = J2
	{
		if(op_num_cor == 1)// numero
		{
			for(i=0;i<5;i++)
			{
				if(  J2[aux_pos].num== J2[i].num)
				{
					//ajuda_evidenciarPISTA();
					showNumAt(i*5+62,24,J2[i].num);
					verdade=1;
					J2[i].know_num = 1;
					
				}
			}
		}
		
		if(op_num_cor == 2)// cor
		{
			for(i=0;i<5;i++)
			{
				if(  J2[aux_pos].cor == J2[i].cor)
				{
				//	ajuda_evidenciarPISTA();
					setForeColor(J2[i].cor);
					showRectAt(60+i*5,22,4,4);
					verdade=1;
					J2[i].know_color = 1;
					setForeColor(15);
					
				}
			}	
		}
		
	
	}
	
	
	if(turno == 1 ) // BOT  = J1
	{
		if(op_num_cor == 1)// numero
		{
			for(i=0;i<5;i++)
			{
				if( J1[aux_pos].num == J1[i].num)
				{
				//ajuda_evidenciarPISTA();
				showNumAt(i*5+62,4,J1[i].num);
				verdade=1;
				J1[i].know_num = 1;
				}
			}
		}
		if(op_num_cor == 2)// cor
		{
			for(i=0;i<6;i++)
			{
				if(  J1[aux_pos].cor == J1[i].cor)
				{
					
				//	ajuda_evidenciarPISTA();
					setForeColor(J1[i].cor);
					showRectAt(60+i*5,2,4,4);
					verdade=1;
					J1[i].know_color = 1;
					setForeColor(15);
				}
			}	
		}
		
	}
}	
	if(verdade == 1)
	{
		*pistas=*pistas-1;
	}
 	atualizar_pistas_vidas(aux_pistas,vidas);	
}














#endif
