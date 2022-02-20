#ifndef _ATUALIZARH_		//protectes from multiple including...
#define _ATUALIZARH_		//... needs an #endif at bottom


void print_pistas_vidas ()
{
	int i,j;
	
			for(i=0;i<3;i++){
			setForeColor(0);
			showRectAt(i*4+35,3,3,1.5);
			}
			
			for(i=0;i<2;i++){
			for(j=0;j<4;j++){
			setForeColor(7);
			showRectAt(j*4+35,i*2+7,3,1.5);
		//		showCharAt(j*2+35,i*2+7,17);
			}
			setForeColor(15);
}
}
void atualizarPontuacao(int p)
{
	gotoxy(18,3);printf("Pontuacao:");
	printf("%2d",p);
}
void atualizar_pistas_vidas (int p, int v)    // limpa e atualiza vidas 
{
	
	int i,j;
	
			print_pistas_vidas();
			for(i=0;i<v;i++){
			setForeColor(4);
			showRectAt(i*4+35,3,3,1.5);
			}
			
			
			if(p<=4)
			{
			for(j=0;j<p;j++)
			{
			setForeColor(10);
			showRectAt(j*4+35,7,3,1.5);
			}
			}
			else
			{
			if(p>5)
			{
			for(j=0;j<4;j++)
			{
			setForeColor(10);
			showRectAt(j*4+35,7,3,1.5);
			}
			for(i=0;i<p-4;i++)
			{
			setForeColor(10);
			showRectAt(i*4+35,2+7,3,1.5);	
			}
			}
			}
				setForeColor(15);
}
void resetarVariaveis (int *pistas,int *vidas,carta discard[],int *azul,int *vermelho,int *amarelo,int *roxo,int *verde,int *pontuacao)
{
	int i;
	*pistas=8;
	*vidas=3;
	
	for(i=0;i<50;i++)
	{
		discard[i].num = 0;
		discard[i].cor = 0;
	}
	
	*azul=0;
	*vermelho=0;
	*amarelo=0;
	*roxo=0;
	*verde=0;
	*pontuacao = 0;
	
	
}
void swap (int * turno )
{
	int aux=*turno;
	
	switch(aux)
	{
		case 1 : {aux=0;
			break;
		}
		case 0:{
			aux=1;
			break;
		}
	}
	
	*turno = aux;
}
void atualizar_jogador (int turno,char nome[])
{
	int aux_turno;
	
	delay(1);
	aux_turno = turno;
	printNext (nome , aux_turno);

	
}
void escrever_pilha_na_mesa (int g,int b,int r,int p,int y)            // escreve as pilhas e o num da pilha na mesa
{

setForeColor(2);showRectAt(60,12,4,4);setForeColor(15); showNumAt(62,14,0);
setForeColor(3);showRectAt(60+1*5,12,4,4);setForeColor(15);showNumAt(67,14,0);
setForeColor(4);showRectAt(60+2*5,12,4,4);setForeColor(15);showNumAt(72,14,0);
setForeColor(5);showRectAt(60+3*5,12,4,4);setForeColor(15);showNumAt(77,14,0);
setForeColor(6);showRectAt(60+4*5,12,4,4);setForeColor(15);showNumAt(82,14,0);
setForeColor(15);	
	
setForeColor(2);showRectAt(60,12,4,4);setForeColor(15); showNumAt(62,14,g);
setForeColor(3);showRectAt(60+1*5,12,4,4);setForeColor(15);showNumAt(67,14,b);
setForeColor(4);showRectAt(60+2*5,12,4,4);setForeColor(15);showNumAt(72,14,r);
setForeColor(5);showRectAt(60+3*5,12,4,4);setForeColor(15);showNumAt(77,14,p);
setForeColor(6);showRectAt(60+4*5,12,4,4);setForeColor(15);showNumAt(82,14,y);
setForeColor(15);
    
////    		showRectAt(60+i*5,22,4,4);
////		gotoxy(62+i*5,24);
}






#endif
