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

//Función principal del mes de Enero:
void mostrarMesE(struct Taguas vector[], int size) {
	
	FILE*fichero;
	
	printf("\nHa seleccionado la opción 1\n");
        	
    fichero = fopen("2023_01_Lavapiés.txt", "r");
    
	if (fichero == NULL) {
       	printf("\nError al abrir el archivo\n");
        return 0;
	}
			
	printf("Fichero de datos cargado exitosamente\n");
		
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
	
	return;
}
//Función principal del més de Febrero:
void mostrarMesF(struct Taguas vector[], int size) {
	
	FILE * fichero;
	
	printf("\nHa seleccionado la opción 2\n");
            
    fichero = fopen("2023_02_Lavapiés.txt", "r");
    
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
	
	return;     
}
//Funcion principal mes de Marzo:
void mostrarMesM(struct Taguas vector[], int size) {
	 
	FILE * fichero;
	 
	printf("\nHa seleccionado la opción 3\n");
            
    fichero = fopen("2023_03_Lavapiés.txt", "r");
    
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
	
	return;
}

//Funciones secundarias:
void mostrarMenu2(struct Taguas[], int); //Función del menú.
void opcionmenu1(struct Taguas[], int); //Función 1.
void opcionmenu2(struct Taguas[], int); //Función 2.
void opcionmenu3(struct Taguas[], int); //Función 3.
void opcionmenu4(struct Taguas[], int); //Función 4.
void opcionmenu5(struct Taguas[], int); //Función 5.

int main(){
	setlocale(LC_CTYPE, "Spanish");
	
	FILE * fichero;
	
	int mes, opcion, TAM = 25;
	struct Taguas vector[TAM];
	char aux;
	
	//Funcionalidad 6:
	int nfuentesnuevas, TAM_NUEVO;
	char nombre[] = "Parametros";
	char Ph[] = "pH";
	char Conductividad[] = "Conductividad";
	char Turbidez[] = "Turbidez";
	char Coliformes[] = "Coliformes";
	
	

	
	printf("--------------------------------------------------------------- WATER TECH ---------------------------------------------------------------\n");
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
    	
    	//Mes de Enero.
        case 1:
        {
        	int i;
        	mostrarMesE(vector, i); //Función principal del mes de Enero.
        	
        	do{ 				
					mostrarMenu2(vector, TAM);
        			scanf ("%d", &opcion);
            		
            		//Función 1:
            		if (opcion == 1) {
	            		opcionmenu1(vector, TAM);
					} //Fín de la función 1. 
						
					//Función 2:
					else if (opcion == 2) {
						opcionmenu2(vector, TAM);
					} //Fin de la función 2.
					
					//Función 3:
					else if (opcion == 3) {
						opcionmenu3(vector,TAM);	
	    			} //Fin de la función 3.
	    			
					//Función 4:
	    			else if(opcion == 4){
	    				opcionmenu4(vector, TAM);
					} //Fin de la funcion 4.
						
					//Funcion 5.
					else if(opcion == 5){
						opcionmenu5(vector, TAM);
					} //Fin de la función 5.
					
					//Funcion 6.
					else if(opcion == 6){
						printf("Introduzca el número de fuentes nuevas que quieras añadir al fichero\n");
						scanf("%d", &nfuentesnuevas);
						TAM_NUEVO = TAM + nfuentesnuevas;
					
						int i;
						for(i = TAM; i<TAM_NUEVO; i++){
							printf("Nombre de la fuente --->\t");
							scanf("%s", vector[i].nombreFuente);
							printf("pH --->\t");
							scanf("%f", &vector[i].ph);
							printf("Conductividad --->\t");
							scanf("%d", &vector[i].conductividad);
							printf("Turbidez --->\t");
							scanf("%d", &vector[i].turbidez);
							printf("Coliformes --->\t");
							scanf("%d", &vector[i].coliformes);
						}
						TAM = TAM_NUEVO;
					
						printf("Número de fuentes añadidas al fichero: %d\n", nfuentesnuevas);
						printf("Fichero actualizado exitosamente\n");
					
						FILE*fnuevo;
						fnuevo = fopen("2023_01_Lavapiés.txt", "w");
					
						if (fichero == NULL) {
	        				printf("\nError al abrir el archivo\n");
	        				return 0;
						}
					
						fprintf(fnuevo, "%s %s %s %s %s\n", nombre, Ph, Conductividad, Turbidez, Coliformes);
						for(i = 0; i < TAM; i++){
							fprintf(fnuevo, "%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
	        			}
						fclose(fnuevo);
	    			}
	    			} while(opcion <=6);
					
					if (opcion == 7){
						printf("HASTA LA PRÓXIMA -EQUIPO DE WATERTECH-\n");
	        			return 0;
					}
			break;
	    	}
	    //Mes de Febrero.
        case 2:
        {
        	int i;
        	mostrarMesE(vector, i); //Función principal del mes de Febrero.
        	
        	do{ 				
					mostrarMenu2(vector, TAM);
        			scanf ("%d", &opcion);
            		
            		//Función 1:
            		if (opcion == 1) {
	            		opcionmenu1(vector, TAM);
					} //Fín de la función 1. 
						
					//Función 2:
					else if (opcion == 2) {
						opcionmenu2(vector, TAM);
					} //Fin de la función 2.
					
					//Función 3:
					else if (opcion == 3) {
						opcionmenu3(vector,TAM);	
	    			} //Fin de la función 3.
	    			
					//Función 4:
	    			else if(opcion == 4){
	    				opcionmenu4(vector, TAM);
					} //Fin de la funcion 4.
						
					//Funcion 5.
					else if(opcion == 5){
						opcionmenu5(vector, TAM);
					} //Fin de la función 5.
					
					//Funcion 6.
					else if(opcion == 6){
						printf("Introduzca el número de fuentes nuevas que quieras añadir al fichero\n");
						scanf("%d", &nfuentesnuevas);
						TAM_NUEVO = TAM + nfuentesnuevas;
					
						int i;
						for(i = TAM; i<TAM_NUEVO; i++){
							printf("Nombre de la fuente --->\t");
							scanf("%s", vector[i].nombreFuente);
							printf("pH --->\t");
							scanf("%f", &vector[i].ph);
							printf("Conductividad --->\t");
							scanf("%d", &vector[i].conductividad);
							printf("Turbidez --->\t");
							scanf("%d", &vector[i].turbidez);
							printf("Coliformes --->\t");
							scanf("%d", &vector[i].coliformes);
						}
						TAM = TAM_NUEVO;
					
						printf("Número de fuentes añadidas al fichero: %d\n", nfuentesnuevas);
						printf("Fichero actualizado exitosamente\n");
					
						FILE*fnuevo;
						fnuevo = fopen("2023_01_Lavapiés.txt", "w");
					
						if (fichero == NULL) {
	        				printf("\nError al abrir el archivo\n");
	        				return 0;
						}
					
						fprintf(fnuevo, "%s %s %s %s %s\n", nombre, Ph, Conductividad, Turbidez, Coliformes);
						for(i = 0; i < TAM; i++){
							fprintf(fnuevo, "%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
	        			}
						fclose(fnuevo);
	    			}
	    			} while(opcion <=6);
					
					if (opcion == 7){
						printf("HASTA LA PRÓXIMA -EQUIPO DE WATERTECH-\n");
	        			return 0;
					}
            
        break;
    	}
    	//Mes de Marzo.
        case 3:
        {
        	int i;
        	mostrarMesE(vector, i); //Función principal del mes de Febrero.
        	
        	do{ 				
					mostrarMenu2(vector, TAM);
        			scanf ("%d", &opcion);
            		
            		//Función 1:
            		if (opcion == 1) {
	            		opcionmenu1(vector, TAM);
					} //Fín de la función 1. 
						
					//Función 2:
					else if (opcion == 2) {
						opcionmenu2(vector, TAM);
					} //Fin de la función 2.
					
					//Función 3:
					else if (opcion == 3) {
						opcionmenu3(vector,TAM);	
	    			} //Fin de la función 3.
	    			
					//Función 4:
	    			else if(opcion == 4){
	    				opcionmenu4(vector, TAM);
					} //Fin de la funcion 4.
						
					//Funcion 5.
					else if(opcion == 5){
						opcionmenu5(vector, TAM);
					} //Fin de la función 5.
					
					//Funcion 6.
					else if(opcion == 6){
						printf("Introduzca el número de fuentes nuevas que quieras añadir al fichero\n");
						scanf("%d", &nfuentesnuevas);
						TAM_NUEVO = TAM + nfuentesnuevas;
					
						int i;
						for(i = TAM; i<TAM_NUEVO; i++){
							printf("Nombre de la fuente --->\t");
							scanf("%s", vector[i].nombreFuente);
							printf("pH --->\t");
							scanf("%f", &vector[i].ph);
							printf("Conductividad --->\t");
							scanf("%d", &vector[i].conductividad);
							printf("Turbidez --->\t");
							scanf("%d", &vector[i].turbidez);
							printf("Coliformes --->\t");
							scanf("%d", &vector[i].coliformes);
						}
						TAM = TAM_NUEVO;
					
						printf("Número de fuentes añadidas al fichero: %d\n", nfuentesnuevas);
						printf("Fichero actualizado exitosamente\n");
					
						FILE*fnuevo;
						fnuevo = fopen("2023_01_Lavapiés.txt", "w");
					
						if (fichero == NULL) {
	        				printf("\nError al abrir el archivo\n");
	        				return 0;
						}
					
						fprintf(fnuevo, "%s %s %s %s %s\n", nombre, Ph, Conductividad, Turbidez, Coliformes);
						for(i = 0; i < TAM; i++){
							fprintf(fnuevo, "%s %.2f %d %d %d\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
	        			}
						fclose(fnuevo);
	    			}
	    			} while(opcion <=6);
					
					if (opcion == 7){
						printf("HASTA LA PRÓXIMA -EQUIPO DE WATERTECH-\n");
	        			return 0;
					}
           
        break;
    	}
	}
	return 0;
}

// FUNCIONES:
//Función del menú:
void mostrarMenu2(struct Taguas vector[], int size) {
	
	printf("\nSeleccione la opción deseada de los datos de las fuentes de elegidas:\n");
    printf("1. Mostrar datos de una fuente específica\n"); 
    printf("2. Comprobar valores máximos y mínimos de los parámetros\n");  
    printf("3. Comparar fuentes\n");
	printf("4. Comprobar la potabilidad del agua\n");
	printf("5. Comprobar medias de cada parámetro\n");
	printf("6. Añadir datos de una fuente nueva\n");
    printf("7. Salir\n");
    
    return;
}

//Función 1:
void opcionmenu1(struct Taguas vector[], int i) {
	char numero_de_fuente[50];
	

	printf("Elija la fuente que quiera, siguiendo este  formato: Fuente_n(n=numero de la fuente):\n");
	scanf ("%s", numero_de_fuente);
				
	int z, encontrado = 0;
	for (z = 0; z < i; z++) {
							
		encontrado = 0;
							
	    if (strcmp(vector[z].nombreFuente, numero_de_fuente) == 0) {
	        printf("Fuente: %s\t pH: %.2f\t Conductividad: %d\t Turbidez: %d\t Coliformes: %d\n", vector[z].nombreFuente, vector[z].ph, vector[z].conductividad, vector[z].turbidez, vector[z].coliformes);
	    	encontrado = 1;
	    	break;
	    }
	}
						
	if(!encontrado){
		printf("No se encontró la fuente especificada\n");
	}
	
	return;
}

//Función 2:
void opcionmenu2(struct Taguas vector[], int i) {

	float maxpH = vector[0].ph, minpH = vector[0].ph;
	int masAcida = 0, menosAcida = 0, masCon = 0, menosCon = 0, masTur = 0, menosTur = 0, masColi = 0, menosColi = 0;
	int maxCon = vector[0].conductividad, minCon = vector[0].conductividad, maxTur = vector[0].conductividad, minTur = vector[0].turbidez, maxColi = vector[0].coliformes, minColi = vector[0].coliformes;
	
						
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
						
	int p;
	for(p = 1; p < i; p++) {
		if(vector[p].conductividad > maxCon) {
			maxCon = vector[p].conductividad;
			masCon = p;
		}
		if(vector[p].conductividad < minCon) {
			minCon = vector[p].conductividad;
			menosCon = p;
		}
	}
						
	int w;
	for(w = 1; w < i; w++) {
		if(vector[w].turbidez > maxTur) {
			maxTur = vector[w].turbidez;
			masTur = w;
		}
		if(vector[w].turbidez < minTur) {
			minTur = vector[w].turbidez;
			menosTur = w;
		}
	}
						
	int q;
	for(q = 1; q < i; q++) {
		if(vector[q].coliformes > maxColi) {
			maxColi = vector[q].coliformes;
			masColi = q;
		}
		if(vector[q].coliformes < minColi) {
			minColi = vector[q].coliformes;
			menosColi = q;
		}
	}
					
	printf("La fuente más ácida es la %s con un pH de %.2f\n", vector[masAcida].nombreFuente, vector[masAcida].ph);
	printf("La fuente menos ácida es la %s con un pH de %.2f\n1", vector[menosAcida].nombreFuente, vector[menosAcida].ph);
	printf("La fuente con más conductividad es la %s con un valor de %d\n", vector[masCon].nombreFuente, vector[masCon].conductividad);
	printf("La fuente con menos condutividad es la %s con un valor de %d\n", vector[menosCon].nombreFuente, vector[menosCon].conductividad);
	printf("La fuente con más turbidez es la %s con un valor de %d\n", vector[masTur].nombreFuente, vector[masTur].turbidez);
	printf("La fuente con menos turbidez es la %s con un valor de %d\n", vector[menosTur].nombreFuente, vector[menosTur].turbidez);
	printf("La fuente con mas coliformes es la %s con un valor de %d\n", vector[masColi].nombreFuente, vector[masColi].coliformes);
	printf("La fuente con menos coliformes es la %s con un valor de %d\n", vector[menosColi].nombreFuente, vector[menosColi].coliformes);
	
	return;	
}

//Función 3:
void opcionmenu3(struct Taguas vector[], int i) {
	char FuenteComparacion[50], FuenteComparacion2[50];
	char nombreph[100], nombreconductividad[100], nombreturbidez[100], nombrecoliformes[100];
	float phmayor, phigual;
	int conductividadmayor, turbidezmayor, coliformesmayor, fuente31 = 0, fuente32 = 0, conductividadigual, turbidezigual, coliformesigual;	
	
	
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
		printf("Coliformes ----> La fuente con más coliformes es la %s con un valor de %d\n", nombrecoliformes, coliformesmayor);
	}
	return;
}

//Función 4:
void opcionmenu4(struct Taguas vector[], int i) {
	float potabilidad;
	char numero_de_fuente2[50];
	
	printf("Elija la fuente de la que quiera saber su potabilidad, siguiendo este formato: Fuente_n (n=numero de la fuente):\n");
	scanf ("%s", numero_de_fuente2);
	    			
	int h;
	for(h = 0; h < i; h++){
		if (strcmp(vector[h].nombreFuente, numero_de_fuente2) == 0) {
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
	return;
}

//Funcion 5:
void opcionmenu5(struct Taguas vector[], int i) {
	float mediaph, mediaconductividad, mediaturbidez, mediacoliformes;
	
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
					
	printf("Media del ph de las fuentes de Lavapiés: %.3f\n", mediaph);
	printf("Media de la conductividad de las fuentes de Lavapiés: %.3f\n", mediaconductividad);
	printf("Media de la turbidez de las fuentes de Lavapiés: %.3f\n", mediaturbidez);
	printf("Media de los coliformes de las fuentes de Lavapiés: %.3f\n", mediacoliformes);
	
	return;
}
