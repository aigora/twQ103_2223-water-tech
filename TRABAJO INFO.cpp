#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Taguas{
	char nombreFuente [100];
	float ph;
	float conductividad;
	float turbidez;
	float coliformes;
};

void mostrarMenu(int);
void abrirFichero(struct [], int, char[]);

int main(){
	setlocale(LC_CTYPE,("Spanish"));
	int opcion;
	struct Taguas vector;
	char nombreFichero [50];
	FILE*fichero;
	char fichero01[] = "202301_Arroyomolinos.txt";
    char fichero02[] = "202301_Lavapiés.txt";
    char fichero03[] = "202301_Leganés.txt";
    char fichero04[] = "202301_Usera.txt";
    char fichero05[] = "202301_Vicálvaro.txt";
	
	printf("--------------------------------------------------------------- WATER TECH ----------------------------------------------------------------------------\n");
	printf("\nBienvenido a Water Tech, una aplicación diseñada para ayudarte en el registro y análisis de los datos de calidad del agua en distintas fuentes de Madrid en el mes de Enero en 2023.\nCon esta herramienta, podrás cargar y almacenar ficheros de datos mensuales, realizar estadísticas y búsquedas sobre los datos, y mucho más.\nEsperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigación sobre la calidad del agua.\nSi tienes alguna pregunta o sugerencia, no dudes en contactarnos.¡Gracias por elegir Water Tech!\n");
	
	do {
        mostrarMenu(opcion);
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nHa seleccionado la opción 1\n");
                abrirFichero(Taguas vector,25,fichero01);
                break;
            case 2:
                printf("\nHa seleccionado la opción 2\n");
                abrirFichero(Taguas vector,25, fichero02);
                break;
            case 3:
                printf("\nHa seleccionado la opción 3\n");
                abrirFichero(Taguas vector,25, fichero03);
                break;
            case 4:
                printf("\nHa seleccionado la opción 4\n");
                abrirFichero(Taguas vector,25, fichero04);
                break;
            case 5:
                printf("\nHa seleccionado la opción 5\n");
                abrirFichero(Taguas vector,25, fichero05);
                break;
            case 6: 
            	printf("\nHa seleccionado la opción 6. Saliendo del programa...\n");
            	return 0;
            default:
                printf("\nOpción no válida. Por favor, seleccione una opción válida.\n");
                break;
        }
    } while(opcion < 1 || opcion > 5);

    return 0;
		
};

// FUNCIONES 

void mostrarMenu(int opcion) {
    printf("\nSeleccione fichero de datos desea cargar:\n");
    printf("1: Datos fuentes de Arroyomolinos en 01/2023\n");
    printf("2: Datos fuentes de Lavapiés en 01/2023 \n");
    printf("3: Datos fuentes de Leganés en 01/2023\n");
    printf("4: Datos fuentes de Usera en 01/2023\n");
    printf("5: Datos fuentes de Vicálvaro en 01/2023\n");
    printf("6: Salir de Water Tech\n");
    
    return;
};

void abrirFichero(struct Taguas vector[], int tam, char nombreFichero[]) {
    FILE *fichero;
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        printf("\nError al abrir el archivo\n");
	}else {
        printf("\nArchivo abierto correctamente.\n");
        printf("Parametros\tpH\tConductividad\tTurbidez\tColiformes\n");

        int i = 0;
        while (fscanf(fichero, "%s %f %f %f %f", vector[i].nombreFuente, &vector[i].ph, &vector[i].conductividad, &vector[i].turbidez, &vector[i].coliformes) != EOF) {
            printf("%s\t%.2f\t%.0f\t%.0f\t%.0f\n", vector[i].nombreFuente, vector[i].ph, vector[i].conductividad, vector[i].turbidez, vector[i].coliformes);
            i++;
            if (i >= tam) { // verificar que no se exceda el tamaño del vector
                break;
            }
        }
        fclose(fichero);
    }
    return;
};


	
	
	
	
	
	
	
	
	
	
	
	


