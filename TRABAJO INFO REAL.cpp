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
	
	FILE*fichero;
	
	printf("--------------------------------------------------------------- WATER TECH ----------------------------------------------------------------------------\n");
	printf("\nBienvenido a Water Tech, una aplicaci�n dise�ada para ayudarte en el registro y an�lisis de los datos de calidad del agua en distintas fuentes de Madrid en el mes de Enero en 2023.\nCon esta herramienta, podr�s cargar y almacenar ficheros de datos mensuales, realizar estad�sticas y b�squedas sobre los datos, y mucho m�s.\nEsperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigaci�n sobre la calidad del agua.\nSi tienes alguna pregunta o sugerencia, no dudes en contactarnos.�Gracias por elegir Water Tech!\n");
	
	while (1) {
		
		printf ("\nIntroduzca el mes con el fichero que quiera trabajar de Lavapi�s\n 1.Enero\n 2.Febrero\n 3.Marzo\n");
		scanf ("%d", &mes);
		
		if (mes < 1 || mes > 3) {
			printf ("Lo siento, pero tiene que introducir un n�mero de los meses dados.\n");
		} else {
			break;
		}
	}
        
    switch(mes) {
        case 1:
        {
        	printf("\nHa seleccionado la opci�n 1\n");
        	
            fichero = fopen("2023_01_Lavapi�s.txt", "r");
    
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
					printf("No se encontr� la fuente especificada\n");
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
				
				printf("La fuente m�s �cida es la %s con un pH de %.2f\n", vector[masAcida].nombreFuente, vector[masAcida].ph);
				printf("La fuente menos �cida es la %s con un pH de %.2f\n ", vector[menosAcida].nombreFuente, vector[menosAcida].ph);
			} else if (opcion == 3) {
				printf("Elija la fuente de la que quiera saber su potabilidad, siguiendo este formato: Fuente_n (n=numero de la fuente):\n");
				scanf ("%s", numero_de_fuente);
				float potable;
				int h;
				for (h=0; h<25; h++) {
					if (strcmp(vector[h].nombreFuente, numero_de_fuente) == 0) {
            			potable = vector[h].ph/vector[h].conductividad + vector[h].turbidez;
						printf("La potabilidad de la fuente %d = %.2f ", h+1, potable); 
            			break;
    				} 
					}
				} 
				break;
		}
        case 2:
        {
            printf("\nHa seleccionado la opci�n 2\n");
            
            fichero = fopen("2023_02_Lavapi�s.txt", "r");
    
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
            printf("\nHa seleccionado la opci�n 3\n");
            
            fichero = fopen("2023_03_Lavapi�s.txt", "r");
    
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
        printf("HASTA LA PR�XIMA\n EQUIPO DE WATERTECH\n");
        return 0;
    	}
}
	return 0;
}

// FUNCIONES 


void mostrarMenu2(struct Taguas vector[], int size) {
	
	printf("\nSeleccione la opci�n deseada de los datos de las fuentes de elegidas:\n");
    
    printf("1. Mostrar datos de una fuente espec�fica\n"); //Igual que la opci�n dos.
    printf("2. Fuente m�s �cida y m�s b�sica\n");  // Craer un nuevo fichero.
    printf("3. Comprobar la potabilidad del agua\n");
	printf("4. Comparar fuentes\n");
	printf("5. A�adir datos de una fuente nueva\n");
    printf("6. Salir\n");
    
    return;
}

