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

int main(){
	setlocale(LC_CTYPE,("Spanish"));
	int opcion;
	char nombreArchivo [50];
	FILE*fichero;
	
	printf("-----------WATER TECH------------\n");
	printf("Bienvenido a Water Tech, una aplicaci�n dise�ada para ayudarte en el registro y an�lisis de los datos de calidad del agua en distintas fuentes de Madrid. Con esta herramienta, podr�s cargar y almacenar ficheros de datos mensuales, realizar estad�sticas y b�squedas sobre los datos, y mucho m�s.Esperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigaci�n sobre la calidad del agua. Si tienes alguna pregunta o sugerencia, no dudes en contactarnos.�Gracias por elegir Water Tech!\n");
}
	 /*do {
    	printf("\nSeleccione una opci�n:\n");
        printf("1. Cargar fichero de datos\n");
        printf("2. Mostrar datos de una fuente\n");
        printf("3. Buscar fuentes por par�metro\n");
        printf("4. A�adir datos de una fuente\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);

	switch(opcion) {
            case '1': 
            	// PASO 1: ABRIR EL ARCHIVO:
            	
            	printf("\nIntroduce el nombre del archivo:\n");
            	scanf("%s", nombreArchivo);
            
            	fichero=fopen ("fichero de trabajo.txt",'r'); 
            	
            	if (fichero==NULL){
            		printf ("ERROR, no se puede abrir el archivo: %s\n", nombreArchivo);
            		return 0;
				}
				
				//PASO 2: LEER EL ARCHIVO 
				
				while(fscanf(fichero, "%s %f %f %f %f", nombreFuente, &ph, &conductividad, &turbidez, &coliformes)!=EOF){
					printf("%s %f %f %f %f\n", nombreFuente, ph, conductividad, turbidez, coliformes);
				}
				
				// PASO 3: CERRAR EL ARCHIVO:
				fclose (fichero);
            
            	break;
            case '2':
                break;
            case '3':
            	 break;
            case '4':
                break;
            case '5':
                break;
            default:
                printf("\nOpci�n inv�lida, por favor seleccione una opci�n v�lida.\n");
        }
    } while(opcion != '5');

    return 0;
}; */

