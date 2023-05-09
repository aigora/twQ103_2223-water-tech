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
	printf("Bienvenido a Water Tech, una aplicaci�n dise�ada para ayudarte en el registro y an�lisis de los datos de calidad del agua en distintas fuentes de Madrid. Con esta herramienta, podr�s cargar y almacenar ficheros de datos mensuales, realizar estad�sticas y b�squedas sobre los datos, y mucho m�s. Esperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigaci�n sobre la calidad del agua. Si tienes alguna pregunta o sugerencia, no dudes en contactarnos. �Gracias por elegir Water Tech!\n");
	
	while (1) {
		
		printf ("Introduzca n�mero el barrio/Municipio que quiera:\n1.Arroyomolinos.\n2.Usera.\n3.Legan�s.\n4.Lavapi�s.\n");
		scanf ("%d", &Municipio);
		
		if (Municipio < 1 || Municipio > 4) {
			printf ("Lo siento, pero tiene que introducir un n�mero de los municipios dados.\n");
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
			//Opci�n 1: Ver las fuentes del barrio seg�n el m�s.
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
			//F�n de la opci�n 1.

		case 2:
			//Opcion 2: Buscar fuentes por par�metros.		
			mostrarMenu(opcion);
			scanf ("%d", &opcion);
			
			//Opci�n 1: Ver las fuentes del barrio seg�n el m�s.
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
			//F�n de la opci�n 1.
			//Opcion 2: Buscar fuentes por par�metros.
			
		
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
	
	printf("\nSeleccione una opci�n:\n");
    printf("1. Mostrar datos de una fuente\n"); //El fichero hay que pasarlo a una estructura.
    printf("2. Buscar fuentes por par�metro\n"); //Igual que la opci�n dos.
    printf("3. A�adir datos de una fuente\n");  // Craer un nuevo fichero.
    printf("4. Ver la ubicaci�n y el nombre de la fuente introducida.\n");
	printf("5. Comprobar la potabilidad del agua.\n");
	printf("6. Fuente m�s �cida y m�s b�sica\n");
    printf("7. Salir\n");
    
    return;
};

