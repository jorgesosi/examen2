#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libros{ // se crea la estructura Libros
	char id[10];// se declaran los campos a ser cargados
	char nombre[50];
	char autor[50];
	char categoria[50];
};
struct Libros libro[3];
void ingreso();
void listar();
int main (){
	char opt;
	for(;;){
		printf("MENU\n");// muestra por pantalla el menu de ingreso d edatos
		printf("1- Ingrese Nuevo Libro\n");
		printf("2- Listado de libros\n\n");
		printf(" para salir pulse 'x'\n");
		scanf ("%c" ,&opt);
		getchar();
		switch (opt){
			case '1':
			ingreso();
			//getchar();
			break;
			case '2':
			listar();
			break;
			case 'x':
			exit(0);// sale de la apliciacion presionando x
			break;
			default:
			
			break;
		}
		
	}
	
}
void ingreso(){
	int i;
	for (i=0;i<3;i++){
		fflush(stdin);
	printf("Ingrese el Id del libro: \n");
	fgets(libro[i].id,10,stdin);
	printf ("Ingrese el Nombre del libro: \n");
	fgets(libro[i].nombre,50,stdin);
	printf ("Ingrese el Autor del libro: \n");
	fgets(libro[i].autor,50,stdin);
	printf ("Ingrese la Categoria del libro: \n");
	fgets(libro[i].categoria,50,stdin);
	}
}

void listar(){
	int i;
	for (i=0;i<3;i++){
		printf("%s",libro[i].id);
		printf("%s",libro[i].nombre);
		printf("%s",libro[i].autor);
		printf("%s",libro[i].categoria);
		
	}
}

