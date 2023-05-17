#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Taguas{
	char nombreFuente [100];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

void mostrarMenu(int);
void mostrarMenu2(int);

/*
void fuenteespecifica(struct Taguas vector[], int dim) {
	
	char numero_de_fuente[50];
	
	printf("Elija la fuente que quiera, siguiendo este  formato: Fuente_n(n=numero de la fuente):\n");
	gets(numero_de_fuente);
	
	for (int i=0; i<25; i++) {
		if(strcmp(vector[i].nombreFuente, numero_de_fuente) == 0) {
			printf("ph %f - conductividad %f - turbidez %d  - coliformes %d\n", vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
		}
	}
	return;
}
*/

int main(){
	setlocale(LC_CTYPE,("Spanish"));
	
	int municipio, opcion, dim = 25, z;
	struct Taguas vector[25];
	char aux, nombreFuente, ph, conductividad, turbidez, coliformes;
	
	char numero_de_fuente[50];
	
	FILE*fichero;
	
	printf("--------------------------------------------------------------- WATER TECH ----------------------------------------------------------------------------\n");
	printf("\nBienvenido a Water Tech, una aplicación diseñada para ayudarte en el registro y análisis de los datos de calidad del agua en distintas fuentes de Madrid en el mes de Enero en 2023.\nCon esta herramienta, podrás cargar y almacenar ficheros de datos mensuales, realizar estadísticas y búsquedas sobre los datos, y mucho más.\nEsperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigación sobre la calidad del agua.\nSi tienes alguna pregunta o sugerencia, no dudes en contactarnos.¡Gracias por elegir Water Tech!\n");
	
	while (1) {
		
		printf ("\nIntroduzca número el barrio/Municipio que quiera:\n1.Arroyomolinos.\n2.Usera.\n3.Leganés.\n4.Lavapiés.\n5.Vicalvaro.\n");
		scanf ("%d", &municipio);
		
		if (municipio < 1 || municipio > 5) {
			printf ("Lo siento, pero tiene que introducir un número de los municipios dados.\n");
		} else {
			break;
		}
	}
        
    switch(municipio) {
        case 1:
        {
        	printf("\nHa seleccionado la opción 1\n");
        	
            fichero = fopen("2023_Arroyomolinos.txt", "r");
    
			if (fichero == NULL) {
        		printf("\nError al abrir el archivo\n");
        		return 0;
			}
			
			
			while (aux != EOF) {
				aux = fgetc(fichero);
			printf ("%c", aux);
			}
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %f %f %f\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				//printf ("\n%s %.2 %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes);
			}
			fclose(fichero);
		        
           mostrarMenu2(opcion);
           scanf ("%d", &opcion);
                
            if (opcion == 1) {
            	printf("Elija la fuente que quiera, siguiendo este  formato: Fuente_n(n=numero de la fuente):\n");
				scanf ("%s", numero_de_fuente);
	
				for ( z = 0; z < 25; z++) {
        			if (strcmp(vector[z].nombreFuente, numero_de_fuente) == 0) {
            			printf ("Ph: %f.\tConductividad: %d.\tTurbidez: %d.\tColiformes: %d.\n", vector[z].ph, vector[z].conductividad, vector[z].turbidez, vector[z].coliformes);
    				}
    			}	
			}
            break;
    	}
        case 2:
        {
            printf("\nHa seleccionado la opción 2\n");
            //abrirFichero(vector,dim);
            break;
    	}
        case 3:
        {
            printf("\nHa seleccionado la opción 3\n");
            //abrirFichero(vector, dim);
            break;
    	}
        case 4:
        {
            printf("\nHa seleccionado la opción 4\n");
            //abrirFichero(vector, dim);
            break;
		}
        case 5:
        {
        printf("\nHa seleccionado la opción 5\n");
        //abrirFichero(vector, dim);
        break;
    	}
}
}

// FUNCIONES 

void mostrarMenu(int opcion) {
    
	printf("\nSeleccione el barrio o municipio con el que quiera trabajar, para ver su fichero de datos de las fuentes:\n");
    
	printf("1: Datos fuentes de Arroyomolinos en 01/2023\n");
    printf("2: Datos fuentes de Lavapiés en 01/2023 \n");
    printf("3: Datos fuentes de Leganés en 01/2023\n");
    printf("4: Datos fuentes de Usera en 01/2023\n");
    printf("5: Datos fuentes de Vicálvaro en 01/2023\n");
    printf("6: Salir de Water Tech\n");
	
    return;
}

void mostrarMenu2(int opcion) {
	
	printf("\nSeleccione la opción deseada de los datos de las fuentes de elegidas:\n");
    
    printf("1. Mostrar datos de una fuente específica.\n"); //Igual que la opción dos.
    printf("2. Añadir datos de una fuente nueva.\n");  // Crear un nuevo fichero.
    printf("3. Comparar fuentes.\n");
	printf("4. Comprobar la potabilidad del agua.\n");
	printf("5. Fuente más ácida y más básica\n");
    printf("6. Salir\n");
    
    return;
}
