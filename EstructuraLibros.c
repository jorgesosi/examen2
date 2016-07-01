#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libros{ // se crea la estructura Libros
	char id[10];// se declaran los campos a ser cargados
	char nombre[50];
	char autor[50];
	char categoria[50];
};
struct Libros libro;//antes se usaba  struct Libros libro[3]   para cargar el aray d ela estructura
void ingreso();
void listar();
FILE *archivo;
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
			//system("clear");
			ingreso();
			//getchar();
			
			break;
			case '2':
			//system("clear");
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
	archivo = fopen("/home/jorge/Documentos/sistemas 2016/examen2/libreria.txt", "a+");
	/*int i;// se declara el entero para usarlo en el bucle for de 3 datos
	for (i=0;i<3;i++){
		fflush(stdin);*/
	printf("Ingrese el Id del libro: \n");
	fgets(libro.id,10,stdin);
	printf ("Ingrese el Nombre del libro: \n");
	fgets(libro.nombre,50,stdin);//se usan libro[i].nombre para cargar los datos de la matriz, se borran para los archivos
	printf ("Ingrese el Autor del libro: \n");
	fgets(libro.autor,50,stdin);
	printf ("Ingrese la Categoria del libro: \n");
	fgets(libro.categoria,50,stdin);
	//}// cierre del bucle for
	system("clear");
	fwrite(&libro,sizeof(libro),1,archivo); 
	/*fprintf(archivo,"%s",libro.id);
	fprintf(archivo,"%s",libro.nombre);
	fprintf(archivo,"%s",libro.autor);
	fprintf(archivo,"%s",libro.categoria);*/
	fclose(archivo);
}

void listar(){
	/*int i;
	for (i=0;i<3;i++){// se declara el entero para usarlo en el bucle for para mostrar 3 datos*/
		printf("%s",libro.id);
		printf("%s",libro.nombre);
		printf("%s",libro.autor);
		printf("%s",libro.categoria);
		
	//}//cierro del for
}

