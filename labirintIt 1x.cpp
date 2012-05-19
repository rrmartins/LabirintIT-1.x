/*
#################################################################################################
#																								#
#																								#
#					RODRIGO MARTINS JORGE - rodrigomartinsjorge2007@gmail.com					#
#				       	    FELIPE MASIOLI - felipemasioli@gmail.com							#
#															                                    #
#################################################################################################
*/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27

/* Usuarios de Windows, troquem "clear" por "cls" */
#define LIMPARTELA "cls"
#define acaba "exit"
#define nome 2
int    coluna_atual = 2,
       linha_atual = 2;

int random (int min,int max)
{
	return (rand()%(max-min+1)+min);
}

FILE * f_rand (int variado)
{	
	FILE *arquivo;
	switch (variado)
	{
		case 0:
			system("color 3c");
			 arquivo  = fopen("mapa1.txt","r");
		break;
		case 1:
			 system("color 5a");
			 arquivo  = fopen("mapa2.txt","r");
		break;
		case 2:
			 system("color 2a");
			 arquivo  = fopen("mapa3.txt","r");
		break;
		case 3:
			 system("color 7c");
			 arquivo  = fopen("mapa4.txt","r");
		break;
	}
	return arquivo;
}

int _tmain(int argc, _TCHAR* argv[])
{
	system("title LABIRINTiT 1x - PRODUÇÃO - RODRIGO MARTINS ! FELIPE MASIOLI");
	int tecla,variado;
	int result;
	char mapa_a[10][40], jogador[100];
    int i, j,pont=0;
	clock_t start, end;
    double elapsed;

	FILE *arquivo;
	srand(time(NULL));
	variado = random(0,3);
	
	arquivo = f_rand(variado);	

	printf("\n\n\t\tLABIRINTiT 1x");
	printf("\n\n\tQual o seu nome jogador???\n\t\t");
	scanf("%s", jogador);


	start = clock();      
	do{
		system(LIMPARTELA);

		//printf("\t\t\tLABIRINTiT 1x\n\n");

		/* Abre o arquivo */
		if(!arquivo)
		  {
			printf("Erro ao abrir arquivo!!!");
			exit(1);
		  }	
		/* Escreve a matriz no arquivo */
		for (i=0; i<10; i++)
		{
			for (j=0; j<40; j++)
			{
				fscanf(arquivo, "%d",&mapa_a[i][j]);
			}
		}
		mapa_a[linha_atual][coluna_atual] = nome;
		for(i=0;i<10;i++)
		{
			for(j=0;j<40;j++)
				printf("%c",mapa_a[i][j]);
			puts("");
		}
/* O Mapa */
        printf("\n##################### L A B I R I N T i T - 1x ################################\n");
        printf("\n\n    ( %c )\n\n( %c ) + ( %c )\n\n    ( %c )\n",30,17,16,31); /* Imprime as direcoes */
        printf("\nPressione ESC para sair\n");
        printf("\n------------------------------------------------------------------------------\n");

        tecla = getch();
		
        if ( tecla == ACIMA ) {
	     	  printf("%c",mapa_a[linha_atual][coluna_atual]);
		      mapa_a[linha_atual][coluna_atual]=0;
		      linha_atual = linha_atual - 1;
		      printf("%c",mapa_a[linha_atual][coluna_atual]);
          /* Se não for chao ou grama ele volta pra posicao anterior */
              if ((mapa_a[linha_atual][coluna_atual] != 0) && (mapa_a[linha_atual][coluna_atual] != 176) && (mapa_a[linha_atual][coluna_atual] != 4)) 
			  {
					linha_atual = linha_atual + 1;
		      }
        }
        if ( tecla == ABAIXO ) {
		      printf("%c",mapa_a[linha_atual][coluna_atual]);
		      mapa_a[linha_atual][coluna_atual]=0;
              linha_atual = linha_atual + 1;
          /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
              if ((mapa_a[linha_atual][coluna_atual] != 0) && (mapa_a[linha_atual][coluna_atual] != 176) && (mapa_a[linha_atual][coluna_atual] != 4)) 
			  {
					linha_atual = linha_atual - 1;
			  }
        }
        if ( tecla == DIREITA ) {
              printf("%c",mapa_a[linha_atual][coluna_atual]);
              mapa_a[linha_atual][coluna_atual]=0;
              coluna_atual = coluna_atual + 1;
          /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
              if ((mapa_a[linha_atual][coluna_atual] != 0) && (mapa_a[linha_atual][coluna_atual] != 176) && (mapa_a[linha_atual][coluna_atual] != 4)) 
			  {
					coluna_atual = coluna_atual - 1;
              }
        }
        if ( tecla == ESQUERDA ) {
              printf("%c",mapa_a[linha_atual][coluna_atual]);
              mapa_a[linha_atual][coluna_atual]=0;
              coluna_atual = coluna_atual - 1;
          /* Se não for chao ou grama ou saida ele volta pra posicao anterior */
              if ((mapa_a[linha_atual][coluna_atual] != 0) && (mapa_a[linha_atual][coluna_atual] != 176) && (mapa_a[linha_atual][coluna_atual] != 4)) 
			  {
					coluna_atual = coluna_atual + 1;
              }
        }
		if (mapa_a[linha_atual][coluna_atual] !=4 )
	    {
			pont++;
	    }
       
	}while(  (tecla != ESC) && (mapa_a[linha_atual][coluna_atual] != 4) );
	
	result = pont/2;
	end = clock(); 
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
		
	if (mapa_a[linha_atual][coluna_atual] == 4)
	{	
	    printf ("%s,\n",jogador);

			if (variado == 0)
			{
				if (result == 34)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\t\tVoce foi excelente!!!\n");
					printf ("\t!!!!!!!!!!!!!!PARABENSSSSSSSSS!!!!!!!!!!!!!!\n\n");
				}
				if (result > 34)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\tVoce prescisa melhorar!!!\n");
				}
			}
			if (variado == 1)
			{
				if (result == 51)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\t\tVoce foi excelente!!!\n");
					printf ("\t!!!!!!!!!!!!!!PARABENSSSSSSSSS!!!!!!!!!!!!!!\n\n");
				}
				if (result > 51)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\tVoce prescisa melhorar!!!\n");
				}
			}
			if (variado == 2)
			{
				if (result == 68)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\t\tVoce foi excelente!!!\n");
					printf ("\t!!!!!!!!!!!!!!PARABENSSSSSSSSS!!!!!!!!!!!!!!\n\n");
				}
				if (result > 68)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\tVoce prescisa melhorar!!!\n");
				}
			}
			if (variado == 3)
			{
				if (result == 71)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\t\tVoce foi excelente!!!\n");
					printf ("\t!!!!!!!!!!!!!!PARABENSSSSSSSSS!!!!!!!!!!!!!!\n\n");
				}
				if (result > 71)
				{
					printf ("Voce andou %d vezes ...\n Gastou um tempo de %0.0f segundos...\n", result, elapsed);
					printf("\tVoce prescisa melhorar!!!\n");
				}
			}

		system("pause");
		system(acaba);
	}		

	fclose(arquivo);
	return 0;
}