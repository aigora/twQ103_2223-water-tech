#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Taguas{
	char nombre[20];
	char Ph[5];
	char Conductividad[20];
	char Turbidez[20];
	char Coliformes[20];
	char nombreFuente[100];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

void mostrarMenu2(struct Taguas[], int);


int main(){
	setlocale(LC_CTYPE,("Spanish"));
	
	int mes, opcion, dim = 25, masAcida = 0, menosAcida = 0;
	struct Taguas vector[25];
	float maxpH = vector[0].ph, minpH = vector[0].ph;
	char aux;
	char numero_de_fuente[50];
	
	//Funcion 3:
	char FuenteComparacion[50], FuenteComparacion2[50];
	char nombreph[100], nombreconductividad[100], nombreturbidez[100], nombrecoliformes[100];
	float phmayor;
	int conductividadmayor, turbidezmayor, coliformesmayor, fuente31 = 0, fuente32 = 0;	
	//Funcion 3 fin.
	
	FILE*fichero;
	
	printf("--------------------------------------------------------------- WATER TECH ----------------------------------------------------------------------------\n");
	printf("\nBienvenido a Water Tech, una aplicación diseñada para ayudarte en el registro y análisis de los datos de calidad del agua en distintas fuentes de Madrid en el mes de Enero en 2023.\nCon esta herramienta, podrás cargar y almacenar ficheros de datos mensuales, realizar estadísticas y búsquedas sobre los datos, y mucho más.\nEsperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigación sobre la calidad del agua.\nSi tienes alguna pregunta o sugerencia, no dudes en contactarnos.¡Gracias por elegir Water Tech!\n");
	
	while (1) {
		
		printf ("\nIntroduzca el mes con el fichero que quiera trabajar de Lavapiés\n 1.Enero\n 2.Febrero\n 3.Marzo\n");
		scanf ("%d", &mes);
		
		if (mes < 1 || mes > 3) {
			printf ("Lo siento, pero tiene que introducir un número de los meses dados.\n");
		} else {
			break;
		}
	}
        
    switch(mes) {
        case 1:
        {
        	printf("\nHa seleccionado la opción 1\n");
        	
            fichero = fopen("2023_01_Lavapiés.txt", "r");
    
			if (fichero == NULL) {
        		printf("\nError al abrir el archivo\n");
        		return 0;
			}
			
			int y = 0;
			while(fscanf(fichero, "%s %s %s %s %s", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes) != '\n'){
				printf("%s %s %s %s %s\n", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes);
				y++;
				break;
			}
			
			int i = 0;
			while (fscanf(fichero, "%s %f %d %d %d", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				printf("%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
				i++;
			}
			fclose(fichero);
		        
           mostrarMenu2(vector, i);
           scanf ("%d", &opcion);
                
            if (opcion == 1) {
            	printf("Elija la fuente que quiera, siguiendo este  formato: Fuente_n(n=numero de la fuente):\n");
				scanf ("%s", numero_de_fuente);
				
				int encontrado = 0;
				for (int z = 0; z < i; z++) {
        			if (strcmp(vector[z].nombreFuente, numero_de_fuente) == 0) {
            			printf("Fuente: %s\t pH: %.2f\t Conductividad: %d\t Turbidez: %d\t Coliformes: %d\n", vector[z].nombreFuente, vector[z].ph, vector[z].conductividad, vector[z].turbidez, vector[z].coliformes);
            			encontrado = 1;
            			break;
    				}
    			}
				if(!encontrado){
					printf("No se encontró la fuente especificada\n");
				}	
			} else if (opcion == 2) {
				for(int z = 1; z < i; z++){
					if(vector[z].ph > maxpH) {
						maxpH = vector[z].ph;
						masAcida = z;
					}
					if(vector[z].ph < minpH) {
						minpH = vector[z].ph;
						menosAcida = z;
					}
				}
				
				printf("La fuente más ácida es la %s con un pH de %.2f\n", vector[masAcida].nombreFuente, vector[masAcida].ph);
				printf("La fuente menos ácida es la %s con un pH de %.2f\n ", vector[menosAcida].nombreFuente, vector[menosAcida].ph);
			} 
			else if (opcion == 3) {
				
			//Funcion 3:
				printf ("Elige las fuentes, siguiendo el siguiente modelo (Fuente_n, donde 'n' es el numero de fuente), que quieras comparar.\nFuente1:\n");
				scanf ("%s", FuenteComparacion);
				printf ("Fuente 2:\n");
				scanf ("%s", FuenteComparacion2);
	
				for (int u = 1; u < i; u++) {
 			       if (strcmp(vector[u].nombreFuente, FuenteComparacion) == 0) {
 			   	    	fuente31 = u;
				    }
				}
	
				for (int r = 1; r < i; r++) {
					if (strcmp(vector[r].nombreFuente, FuenteComparacion2) == 0) {
						fuente32 = r;  	
					}
				}
			
				if (vector[fuente31].ph < vector[fuente32].ph) {
           		 	phmayor = vector[fuente32].ph;
           		 	strcat(nombreph, vector[fuente32].nombreFuente);
				} else {
					phmayor = vector[fuente31].ph;
					strcat(nombreph, vector[fuente31].nombreFuente);
				}
				 
				printf ("%f %f", vector[fuente32].ph, vector[fuente31].ph);
			/*
				if (vector[fuente31].conductividad < vector[fuente32].conductividad) {
        	    	conductividadmayor = vector[fuente32].conductividad;
        	    	strcat(nombreconductividad, vector[fuente32].nombreFuente);
				} else {
					conductividadmayor = vector[fuente31].conductividad;
					strcat(nombreconductividad, vector[fuente31].nombreFuente);
				} 
			
				if (vector[fuente31].turbidez < vector[fuente32].turbidez) {
        	    	turbidezmayor = vector[fuente32].turbidez;
       		     	strcat(nombreturbidez, vector[fuente32].nombreFuente);
				} else {
					turbidezmayor = vector[fuente31].turbidez;
					strcat(nombreturbidez, vector[fuente31].nombreFuente);
				} 
			
				if (vector[fuente31].coliformes < vector[fuente32].coliformes) {
       		     	coliformesmayor = vector[fuente32].coliformes;
       		     	strcat(nombrecoliformes, vector[fuente32].nombreFuente);
				} else {
					coliformesmayor = vector[fuente31].coliformes;
					strcat(nombrecoliformes, vector[fuente31].nombreFuente);
				}
    */
   				 //printf ("Entre %s y %s: La fuente de mayor ph es la %s, con un ph de %.2f, la de mayor conductividad es la %s, con una conductividad de %d, la de mayor turbidez es la %s con una turbidez de %d, y la mas coliforme es la %s, con un valor de %d\n", FuenteComparacion, FuenteComparacion2, nombreph, phmayor, nombreconductividad, conductividadmayor, nombreturbidez, turbidezmayor, nombrecoliformes, coliformesmayor); 

			} //Fin de funcion 3.
           break;
    	}
        case 2:
        {
            printf("\nHa seleccionado la opción 2\n");
            
            fichero = fopen("2023_02_Lavapiés.txt", "r");
    
			if (fichero == NULL) {
        		printf("\nError al abrir el archivo\n");
        		return 0;
			}
			
			
			while ((aux = fgetc(fichero)) != EOF) {
				printf ("%c", aux);
			} 
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				printf("%s %.4f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
				i++;
			}
			fclose(fichero);
			
			mostrarMenu2(vector, i);
           		scanf ("%d", &opcion);
                
            
            break;
    	}
        case 3:
        {
            printf("\nHa seleccionado la opción 3\n");
            
            fichero = fopen("2023_03_Lavapiés.txt", "r");
    
			if (fichero == NULL) {
        		printf("\nError al abrir el archivo\n");
        		return 0;
			}
			
			
			while ((aux = fgetc(fichero)) != EOF) {
				printf ("%c", aux);
			} 
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				i++;
			}
			fclose(fichero);
            break;
    	}
        
        case 4:
        {
        printf("HASTA LA PRÓXIMA\n EQUIPO DE WATERTECH\n");
        return 0;
    	}
}
	return 0;
}

// FUNCIONES 


void mostrarMenu2(struct Taguas vector[], int size) {
	
	printf("\nSeleccione la opción deseada de los datos de las fuentes de elegidas:\n");
    
    printf("1. Mostrar datos de una fuente específica\n"); //Igual que la opción dos.
    printf("2. Fuente más ácida y más básica\n");  // Craer un nuevo fichero.
    printf("3. Comparar fuentes\n");
	printf("4. Comprobar la potabilidad del agua\n");
	printf("5. Añadir datos de una fuente nueva\n");
    printf("6. Salir\n");
    
    return;
}

