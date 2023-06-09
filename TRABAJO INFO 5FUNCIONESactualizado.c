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
	
	int mes, opcion, dim = 25;
	struct Taguas vector[25];
	char aux;
	
	//Funcionalidad 1:
	char numero_de_fuente[50];
	
	//Funcionalidad 2:
	float maxpH = vector[0].ph, minpH = vector[0].ph;
	int masAcida = 0, menosAcida = 0;
	
	//Funcionalidad 3:
	char FuenteComparacion[50], FuenteComparacion2[50];
	char nombreph[100], nombreconductividad[100], nombreturbidez[100], nombrecoliformes[100];
	float phmayor, phigual;
	int conductividadmayor, turbidezmayor, coliformesmayor, fuente31 = 0, fuente32 = 0, conductividadigual, turbidezigual, coliformesigual;	
	
	//Funcionalidad 4:
	float potabilidad;
	
	//Funcionalidad 5:
	float mediaph, mediaconductividad, mediaturbidez, mediacoliformes;
	
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
				
				int z, encontrado = 0;
				for (z = 0; z < i; z++) {
        			if (strcmp(vector[z].nombreFuente, numero_de_fuente) == 0) {
            			printf("Fuente: %s\t pH: %.2f\t Conductividad: %d\t Turbidez: %d\t Coliformes: %d\n", vector[z].nombreFuente, vector[z].ph, vector[z].conductividad, vector[z].turbidez, vector[z].coliformes);
            			encontrado = 1;
            			break;
    				}
    			}
				if(!encontrado){
					printf("No se encontr� la fuente especificada\n");
				}		
			} 
			else if (opcion == 2) {
				int t;
				for(t = 1; t < i; t++){
					if(vector[t].ph > maxpH) {
						maxpH = vector[t].ph;
						masAcida = t;
					}
					if(vector[t].ph < minpH) {
						minpH = vector[t].ph;
						menosAcida = t;
					}
				}
				
				printf("La fuente m�s �cida es la %s con un pH de %.2f\n", vector[masAcida].nombreFuente, vector[masAcida].ph);
				printf("La fuente menos �cida es la %s con un pH de %.2f\n ", vector[menosAcida].nombreFuente, vector[menosAcida].ph);
			} 
			else if (opcion == 3) {
				
			//Funcion 3:
				printf ("Elige las fuentes, siguiendo el siguiente modelo (Fuente_n, donde 'n' es el numero de fuente), que quieras comparar.\nPrimera Fuente:\n");
				scanf ("%s", FuenteComparacion);
				printf ("Segunda Fuente:\n");
				scanf ("%s", FuenteComparacion2);
	
				int u;	
				for (u = 0; u < i; u++) {
 			       if (strcmp(vector[u].nombreFuente, FuenteComparacion) == 0) {
 			   	    	fuente31 = u;
				    }
				}
				
				int r;
				for (r = 0; r < i; r++) {
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

				if(vector[fuente31].ph == vector[fuente32].ph){
					phigual = vector[fuente31].ph; 
					printf("Ambas fuentes tienen el mismo ph con un valor de %.2f\n", phigual);
				} else {
					printf("ph ---->  La fuente de mayor ph es la %s con un valor de %.2f\n", nombreph, phmayor);
				} 
				
				if(vector[fuente31].conductividad == vector[fuente32].conductividad){
					conductividadigual = vector[fuente31].conductividad;
					printf("Ambas fuentes tienen la misma conductividad con un valor de %d\n", conductividadigual);
				} else {
					printf("Conductividad ----> La fuente con mayor conductividad es la %s con  un valor de %d\n", nombreconductividad, conductividadmayor);
				}
				
				if(vector[fuente31].turbidez == vector[fuente32].turbidez){
					turbidezigual = vector[fuente31].turbidez; 
					printf("Ambas fuentes tienen la misma turbidez con un valor de %d\n", turbidezigual);
				} else {
					printf("Turbidez ----> La fuente con mayor turbidez es la %s con valor de %d\n", nombreturbidez, turbidezmayor);
				}
				
				if(vector[fuente31].coliformes == vector[fuente32].coliformes){
					coliformesigual = vector[fuente31].coliformes;
					printf("Ambas fuentes tienen los mismos coliformes con un valor de %d\n", coliformesigual);
				} else {
					printf("Coliformes ----> La fuente con m�s coliformes es la %s con un valor de %d\n", nombrecoliformes, coliformesmayor);
				}
				//Fin de funcion 3
    		}
    		else if(opcion == 4){
    			printf("Elija la fuente de la que quiera saber su potabilidad, siguiendo este formato: Fuente_n (n=numero de la fuente):\n");
    			scanf ("%s", numero_de_fuente);
    			
    			int h;
    			for(h = 0; h < i; h++){
    				if (strcmp(vector[h].nombreFuente, numero_de_fuente) == 0) {
    					potabilidad = vector[h].ph/vector[h].conductividad + vector[h].turbidez;
						printf("La potabilidad de la fuente %d = %.4f\n", h+1, potabilidad);
						
						if(potabilidad <= 3){
							printf("La fuente %d es potable", h+1);
						} else {
							printf("La fuente %d no es potable", h+1);
						}
						break;
					}
				}
			}
			else if(opcion == 5){
				int m;
				for (m = 0; m < i; m++) {
					mediaph += vector[m].ph;
					mediaconductividad += vector[m].conductividad;
					mediaturbidez += vector[m].turbidez;
					mediacoliformes += vector[m].coliformes;
				}
				mediaph /= i;
				mediaconductividad /= i;
				mediaturbidez /= i;
				mediacoliformes /= i;
				
				printf("Media del ph de las fuentes de Lavapi�s: %.3f\n", mediaph);
				printf("Media de la conductividad de las fuentes de Lavapi�s: %.3f\n", mediaconductividad);
				printf("Media de la turbidez de las fuentes de Lavapi�s: %.3f\n", mediaturbidez);
				printf("Media de los coliformes de las fuentes de Lavapi�s: %.3f\n", mediacoliformes);
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
			
			
			int y = 0;
			while(fscanf(fichero, "%s %s %s %s %s", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes) != '\n'){
				printf("%s %s %s %s %s\n", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes);
				y++;
				break;
			}
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				printf("%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
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
			
			
			int y = 0;
			while(fscanf(fichero, "%s %s %s %s %s", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes) != '\n'){
				printf("%s %s %s %s %s\n", vector[y].nombre, vector[y].Ph, vector[y].Conductividad, vector[y].Turbidez, vector[y].Coliformes);
				y++;
				break;
			}
			
		
			int i = 0;
			while (fscanf(fichero, "\n%s %f %d %d %d\n", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
				printf("%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
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
    printf("3. Comparar fuentes\n");
	printf("4. Comprobar la potabilidad del agua\n");
	printf("5. Comprobar medias de cada par�metro\n");
	printf("6. A�adir datos de una fuente nueva\n");
    printf("6. Salir\n");
    
    return;
}

