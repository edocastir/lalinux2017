#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<ctype.h>


int m=12, i, j, k, min,max,fila,columna,filam,columnam,sumacostos,prombebi;
int matriz[12][12];


char val_caracter;
int anio;

const char mes[][12]={"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
const char meses[][12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
const char rubro[][12]={"Dulces","Bebidas","Conservas"};


	int valida_n()
	{
		while (getchar()!='\n');
		printf("INGRESE SOLO NUMEROS \n");
		return 1;
	}


	void inicio(){
		system("clear");
		anio = 2015;
		printf("\t\t Taller final: Programa para calcular datos en una matriz\n");
		printf("\n");
		do
			{
			printf("\n Ingrese el anio para calcular el costo de produccion \n");
			if (anio < 1900 || anio > 2015){
				system("clear");
				printf("\t\t Taller final: Programa para calcular datos en una matriz\n");
				printf("\n");
				printf("La fecha debe ser menor o igual al año actual y mayor a 1900 \n");
			}
			} while (((scanf("%d%c", &anio, &val_caracter)!=2 || val_caracter!='\n') && valida_n()) || anio< 1900 || anio > 2015 );
		return;
	}




	void  llena_matriz_dulce(){

		system("clear");
		printf("\t\t Taller final: Programa para calcular datos en una matriz\n");
		printf("\n Ingrese los costos de producción de Dulces para el anio %d \n", anio);
		printf("\n");



		for ( i = 0; i < m ; i++ ){
		do
			{
				printf("%s ",meses[i]);
			} while (((scanf("%d%c", &matriz[i][0], &val_caracter)!=2 || val_caracter!='\n') && valida_n()) || matriz[i][0]<0);
				}
		return;

	}



	void  llena_matriz_bebida(){
		printf("\t\t Taller final: Programa para calcular datos en una matriz\n");
		printf("\n Ingrese los costos de producción de Bebidas para el anio %d \n", anio);
		printf("\n");

		for ( i = 0; i < m ; i++ ){
		do
			{
				printf("%s ",meses[i]);
			} while (((scanf("%d%c", &matriz[i][1], &val_caracter)!=2 || val_caracter!='\n') && valida_n()) || matriz[i][1]<0);
		}
		return;
	}


	void  llena_matriz_conserva(){
		printf("\t\t Taller final: Programa para calcular datos en una matriz\n");
		printf("\n Ingrese los costos de producción de Conservas para el anio %d \n", anio);
		printf("\n");

		for ( i = 0; i < m ; i++ ){
		do
			{
				printf("%s ",meses[i]);
			} while (((scanf("%d%c", &matriz[i][2], &val_caracter)!=2 || val_caracter!='\n') && valida_n()) || matriz[i][2]<0);
		}
		return;
	}


	void maximo_costo_dulce(){
		max=0;
		fila=0;
		k = 0;
		int i;
		int j;
		int p;

		for(i=0;i<m;i++){
			if(max<matriz[i][0]){
				max=matriz[i][0];
				fila=i;
			}
		}

		printf("El mayor costo de produccion para Dulces se registro en el mes de ");

		for(i=0;i<m;i++){
			p = matriz[i][0];
			if(p == max){
				printf(" %s, ", meses[i]);
			}
		}
		printf("\n");

		return;
	}


	void maximo_costo_bebida(){
		max=0;
		fila=0;
		int i;
		int j;
		int p;
		for(i=0;i<m;i++){
			if(max<matriz[i][1]){
				max=matriz[i][1];
				fila=i;
			}
		}
		printf("El mayor costo de produccion para Bebidas se registro en el mes de ");

		for(i=0;i<m;i++){
			p = matriz[i][1];
			if(p == max){
				printf(" %s, ", meses[i]);
			}
		}
		printf("\n");


		return;
	}

	void minimo_costo_bebidas(){
		min=999999;
		fila=0;
		int i,j,p;
		for(i=0;i<m;i++){
			if(min>matriz[i][1]){
				min=matriz[i][1];
				fila=i;
		  	}
		}
		printf("El menor costo de produccion para Bebidas se registro en el mes");

		for(i=0;i<m;i++){
			p = matriz[i][1];
			if(p == min){
				printf(" %s, ", meses[i]);
			}
		}
		printf("\n");

		return;
	}



	void minimo_costo_diciembre(){
		min=999999;
		columna=0;
		int i,j,p;
		for(j=0;j<3;j++){
			if(min>matriz[11][j]){
				min=matriz[11][j];
				columna=j;
			}
		}
		printf("El menor costo de produccion en el mes de Diciembre fue el de ");

		for(j=0;j<3;j++){
			p = matriz[11][j];
			if(p == min){
				printf(" %s, ", rubro[j]);
			}
		}
		printf("\n");

		return;

		return;
	}


	void promedio_costo_bebida(){
		sumacostos=0;
		prombebi=0;
		for(i=0;i<m;i++){
			sumacostos=sumacostos+matriz[i][1];
			fila=i;
		}
		prombebi=sumacostos/m;
		return ;
	}


	void imprime(){
		int k;
		for (k=0;k<3;k++){
			printf("\t%s\t", rubro[k]);
		}
		printf("\n");

		for ( i = 0 ; i < m ; i++ ){
			printf("%s\t",mes[i]);
			for ( j = 0 ; j < 3; j++ )
			printf("%d\t\t", matriz[i][j]);
			printf("\n");
		}

		return;
	}



	int main(){
		int val;
		inicio();
		llena_matriz_dulce();
		system("clear");
		llena_matriz_bebida();
		system("clear");
		llena_matriz_conserva();
		system("clear");
		printf("\t\t Taller final: Programa para calcular datos en una matriz");
		printf("\n\n \t\tPara la matriz \n\n");
		imprime();
		printf("\nLos resultados son los siguientes:\n");
		promedio_costo_bebida();
		printf("\n\nEl promedio anual para los costos de produccion de bebidas es %d\n",prombebi);
		maximo_costo_dulce();
		maximo_costo_bebida();
		minimo_costo_bebidas();
		minimo_costo_diciembre();
		printf("\n");
		printf("\n\n \t\tGracias por Preferirnos\n\n");
		return 0;
	}
