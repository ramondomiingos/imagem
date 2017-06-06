#include <stdio.h>

typedef struct
{
	int r;
	int g;
	int b;
}pixel;

int main()
{

	char vet[2];
	int dim,dime;
	int max;
	FILE  *arquivo = fopen("lena.txt","r");

	fscanf(arquivo,"%c%c",&vet[0],&vet[1]);
	fscanf(arquivo,"%d%d",&dim,&dime);
	fscanf(arquivo,"%d",&max);

	pixel imagem[dime][dim];

	for(int i=0; i < dime;i++)
	{
		for(int j = 0;j<dim;j++)
		{
			fscanf(arquivo,"%d%d%d",&imagem[i][j].r, &imagem[i][j].g,& imagem[i][j].b);
		}
	}



	if(vet[1]=='3')
	{
		FILE  *arquivop3 = fopen("lena2.ppm","w"); //p3

		fprintf(arquivop3,"%c%c\n",vet[0],vet[1]);
		fprintf(arquivop3,"%d %d\n",dim ,dime );
		fprintf(arquivop3,"%d\n",max);

		for(int i=0; i < dime;i++)
		{
			for(int j = 0;j<dim;j++)
			{
				fprintf(arquivop3,"%d %d %d \n",imagem[i][j].r,imagem[i][j].g,imagem[i][j].b);
			}
		}	

		fclose(arquivop3);
	}

	else if(vet[1]=='2')
	{
		FILE  *arquivop2 = fopen("lena2.pgm","w"); 

		fprintf(arquivop2,"%c%c\n",vet[0],vet[1]);
		fprintf(arquivop2,"%d %d\n",dim ,dime );
		fprintf(arquivop2,"%d\n",max);

		for(int i=0; i < dime;i++)
		{
			for(int j = 0;j<dim;j++)
			{
				fprintf(arquivop2,"%d \n",(imagem[i][j].r+imagem[i][j].g+imagem[i][j].b)/3);
			}
		}

		fclose(arquivop2);
	}

	else if(vet[1]=='1')
	{
		FILE  *arquivop1 = fopen("lena2.ppm","w"); 

		fprintf(arquivop1,"%c%c\n",vet[0],vet[1]);
		fprintf(arquivop1,"%d %d\n",dim ,dime );
		fprintf(arquivop1,"%d\n",max);

		for(int i=0; i < dime;i++)
		{	
			for(int j = 0;j<dim;j++)
			{
				fprintf(arquivop1,"%d %d %d \n",imagem[i][j].r,imagem[i][j].g,imagem[i][j].b);
			}
		}

		fclose(arquivop1);
	}


	fclose(arquivo);
	return 0;

}
