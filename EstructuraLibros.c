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
void editar();
FILE *archivo;
int main (){
	char opt;
	for(;;){
		printf("MENU\n");// muestra por pantalla el menu de ingreso d edatos
		printf("1- Ingrese Nuevo Libro\n");
		printf("2- Listado de libros\n\n");
		printf("3- editar libro\n");
		printf(" para salir pulse 'x'\n");
		scanf ("%c" ,&opt);
		switch (opt){
			case '1':
			ingreso();
			break;
			case '2':
			listar();
			break;
			case '3':
			editar();
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
	archivo = fopen("/home/jorge/Documentos/sistemas 2016/examen2/libreria.dat", "ab+");
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
	fwrite(&libro,sizeof(libro),1,archivo); // fwrite escribe en archivo la estructura completa
	/*fprintf(archivo,"%s",libro.id);// fprintf imprime los valores en el archivo pero trabaja sobre valores individuales, no con la estructura
	fprintf(archivo,"%s",libro.nombre);// guarda los valores en el orden, pero no deja constancia a que variable se les asigna, por lo que si se invierte
	fprintf(archivo,"%s",libro.autor);// el de las variables esto producira un error
	fprintf(archivo,"%s",libro.categoria);*/
	fclose(archivo);//cerramos el archivo para evitar conflictos de futuras apertura
}

void listar(){
	system("clear");
	//int i;
	/*for (i=0;i<3;i++){// se declara el entero para usarlo en el bucle for para mostrar 3 datos*/
	archivo = fopen("/home/jorge/Documentos/sistemas 2016/examen2/libreria.dat", "rb");
	while (!feof (archivo)){
		fread(&libro,sizeof(libro),1,archivo);// lee la estructura del archivo 
		if (strlen(libro.id)!=1 && !feof(archivo)){//verifica que exista el registro y que no se encuentre al final de l archivo
			printf("ID: %s",libro.id);// muestra por pantalla la estructura
			printf("NOMBRE: %s",libro.nombre);
			printf("AUTOR: %s",libro.autor);
			printf("CATEGORIA: %s",libro.categoria);
			fflush(stdout);
			getchar();
			system("clear");
			
		}
	}
	fclose(archivo);// cerramos el archivo 	
	//}//cierro del for
}
void editar(){
	char id[10];
	char opt1;
	int tama;
	system("clear");
	tama=sizeof(libro);//verifica el tamaño de la estructura y se la asigna a la variable
	archivo = fopen("/home/jorge/Documentos/sistemas 2016/examen2/libreria.dat", "rb+");
		printf("Ingrese el id del libro a editar: ");
		fgets(id,10,stdin);// se carga el conjunto de datos a buscar en la estructura, pueden ser varios 
		getchar();
		tama=sizeof(libro);//verifica el tamaño de la estructura y se la asigna a la variable
		printf("%d", tama);
		system("clear");
		while(!feof(archivo)){
			fread(&libro,sizeof(libro),1,archivo);// lee la estructura del archivo 
			 if (strcmp(id,libro.id)==0){
				printf("introduzca el campo a modificar\n");
				printf("1- ID: %s",libro.id);// muestra por pantalla la estructura
				printf("2- NOMBRE: %s",libro.nombre);
				printf("3- AUTOR: %s",libro.autor);
				printf("4- CATEGORIA: %s",libro.categoria);
				printf("t- 't' para terminar\n");
				while(opt1!='t'|| opt1!= 'T'){
					printf("ingrese el campo a modificar: ");
					opt1=getchar();
					getchar();
					switch (opt1){
						case '1':
						printf("ingrese el nuevo  ID: ");
						fgets(libro.id,10,stdin);
						break;
						case '2':
						printf("ingrese el nuevo NOMBRE: ");
						fgets(libro.nombre,50,stdin);
						break;
						case '3':
						printf("ingrese el nuevo AUTOR: ");
						fgets(libro.autor,50,stdin);
						break;
						case '4':
						printf("ingrese la nueva CATEGORIA: ");
						fgets(libro.categoria,50,stdin);
						break;
						case 't':
						fseek(archivo,-tama, SEEK_CUR);
						/* el uso del fseek se toma de un ejemplo de agenda 
						 * y se analiza el uso buscando informacion el libro 
						 * turboc/c++ manual de referencia de schildt
						 * seek_cur ubica el posicion actual del archivo*/
						fwrite(&libro,sizeof(libro),1,archivo);
						break;
						default:
						break;
					}
					
				}
				
			}
			
		}
		
		fclose(archivo);
	}
			
