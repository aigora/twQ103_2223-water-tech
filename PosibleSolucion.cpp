#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Taguas{
	char nombreFuente[100];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

void mostrarMenu2(struct Taguas[], int);


int main(){
	setlocale(LC_CTYPE,("Spanish"));
	
	int municipio, opcion, dim = 25, masAcida = 0, menosAcida = 0;
	struct Taguas vector[25];
	float maxpH = vector[0].ph, minpH = vector[0].ph;
	char aux;
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
			
			
			while ((aux = fgetc(fichero)) != EOF) {
				printf ("%c", aux);
			} 
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
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
            			printf("Fuente: %s\n", vector[z].nombreFuente);
            			printf("pH: %.2f\n", vector[z].ph);
            			printf("Conductividad: %d\n", vector[z].conductividad);
            			printf("Turbidez: %d\n", vector[z].turbidez);
            			printf("Coliformes: %d\n", vector[z].coliformes);
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
            break;
    	}
        case 2:
        {
            printf("\nHa seleccionado la opción 2\n");
            
            fichero = fopen("2023_Usera.txt", "r");
    
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
        case 3:
        {
            printf("\nHa seleccionado la opción 3\n");
            
            fichero = fopen("2023_Leganés.txt", "r");
    
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
            printf("\nHa seleccionado la opción 4\n");
            
            fichero = fopen("2023_Lavapiés.txt", "r");
    
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
        case 5:
        {
        printf("\nHa seleccionado la opción 5\n");
        
        fichero = fopen("2023_Vicálvaro.txt", "r");
    
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

