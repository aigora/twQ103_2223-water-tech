#include <stdio.h>
#include <string.h>
#include <locale.h>


struct Taguas{
	char nombreFuente [50];
	float ph;
	float conductividad;
	float turbidez;
	float coliformes;
};

void mostrarMenu(int);

int main () {
	setlocale(LC_CTYPE,("Spanish"));

	
	FILE * pfichero;

	int Municipio, opcion, Mes;
	char aux;
	
	printf("-----------WATER TECH------------\n");
	printf("Bienvenido a Water Tech, una aplicación diseñada para ayudarte en el registro y análisis de los datos de calidad del agua en distintas fuentes de Madrid. Con esta herramienta, podrás cargar y almacenar ficheros de datos mensuales, realizar estadísticas y búsquedas sobre los datos, y mucho más. Esperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigación sobre la calidad del agua. Si tienes alguna pregunta o sugerencia, no dudes en contactarnos. ¡Gracias por elegir Water Tech!\n");
	
	while (1) {
		
		printf ("Introduzca número el barrio/Municipio que quiera:\n1.Arroyomolinos.\n2.Usera.\n3.Leganés.\n4.Lavapiés.\n");
		scanf ("%d", &Municipio);
		
		if (Municipio < 1 || Municipio > 4) {
			printf ("Lo siento, pero tiene que introducir un número de los municipios dados.\n");
		} else {
			break;
		}
	}
	
	switch (Municipio) {
		case 1:
			mostrarMenu(opcion);
			scanf ("%d", &opcion);
			
			switch (opcion) {
				case 1:	 
			//Opción 1: Ver las fuentes del barrio según el més.
				while (1) {
					printf ("De que mes desea sacar los datos de la fuentes de %s, siguiendo el formato 01,02,03...\n", Municipio);
					scanf ("%d", Mes);
				
					if (Mes != 1 && Mes != 2) {
						printf ("Solo disponemos de los dos primeros meses.\n");
					} else {
						break;
					}
				}	
			
				if (Mes == 01) {
			
				pfichero = fopen ("202301_Arroyomolinos.txt","r"); //Abrir el fichero.
					if (pfichero == NULL) {
						printf ("No se ha podido abrir el fichero.\n");
						return 0;
					}
		
					while (aux != EOF) {
						aux = fgetc(pfichero);
						printf ("%c", aux);
					}
				fclose(pfichero);
				}
				if (Mes == 02) {
			
				pfichero = fopen ("202302_Arroyomolinos.txt","r"); //Abrir el fichero.
					if (pfichero == NULL) {
						printf ("No se ha podido abrir el fichero.\n");
						return 0;
					}
		
					while (aux != EOF) {
						aux = fgetc(pfichero);
						printf ("%c", aux);
					}
				fclose(pfichero);	
				}
			//Fín de la opción 1.

		case 2:
			//Opcion 2: Buscar fuentes por parámetros.		
			mostrarMenu(opcion);
			scanf ("%d", &opcion);
			
			//Opción 1: Ver las fuentes del barrio según el més.
			while (1) {
				printf ("De que mes desea sacar los datos de la fuentes de %s, siguiendo el formato 01,02,03...\n", Municipio);
				scanf ("%d", Mes);
				
				if (Mes != 1 && Mes != 2) {
					printf ("Solo disponemos de los dos primeros meses.\n");
				} else {
					break;
				}
			}
			
			if (Mes == 01) {
			
			pfichero = fopen ("202301_Usera.txt","r"); //Abrir el fichero.
				if (pfichero == NULL) {
					printf ("No se ha podido abrir el fichero.\n");
					return 0;
				}
		
				while (aux != EOF) {
					aux = fgetc(pfichero);
					printf ("%c", aux);
				}
			fclose(pfichero);
			}
			if (Mes == 02) {
			
			pfichero = fopen ("202302_Usera.txt","r"); //Abrir el fichero.
				if (pfichero == NULL) {
					printf ("No se ha podido abrir el fichero.\n");
					return 0;
					}
		
				while (aux != EOF) {
					aux = fgetc(pfichero);
					printf ("%c", aux);
				}
			fclose(pfichero);	
			}
			//Fín de la opción 1.
			//Opcion 2: Buscar fuentes por parámetros.
			
		
			break;
		case 3:
			mostrarMenu(opcion);
			scanf ("%d", &opcion);
			break;
		case 4:
			mostrarMenu(opcion);
			scanf ("%d", &opcion);
			break;
	}

}

	

	
	


void mostrarMenu(int opcion) {
	
	printf("\nSeleccione una opción:\n");
    printf("1. Mostrar datos de una fuente\n"); //El fichero hay que pasarlo a una estructura.
    printf("2. Buscar fuentes por parámetro\n"); //Igual que la opción dos.
    printf("3. Añadir datos de una fuente\n");  // Craer un nuevo fichero.
    printf("4. Ver la ubicación y el nombre de la fuente introducida.\n");
	printf("5. Comprobar la potabilidad del agua.\n");
	printf("6. Fuente más ácida y más básica\n");
    printf("7. Salir\n");
    
    return;
};

