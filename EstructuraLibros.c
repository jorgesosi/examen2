#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libros{ // se crea la estructura Libros
	char id[10];// se declaran los campos a ser cargados
	char nombre[50];
	char autor[50];
	char categoria[50];
};
struct Libros libro;

int main (){
	char opt;
	for(;;){
		printf("MENU\n");
		printf("1- Ingrese Nuevo Libro\n");
		printf("2- Listado de libros\n\n");
		printf(" para salir pulse 'x'\n");
		scanf ("%c" ,&opt);
		switch (opt){
			case '1':
			break;
			case '2':
			break;
			case 'x':
			exit(0);
			break;
			default:
			
			break;
		}
		
	}
	
}
