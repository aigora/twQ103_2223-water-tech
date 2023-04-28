#include <stdio.h>
#include <string.h>

struct Taguas{
	char nombreFuente [100];
	float ph;
	float conductividad;
	float turbidez;
	float coliformes;
};

int main(){
	int opcion;
	char nombreArchivo [50];
	FILE*fichero;
	
	printf("-----------WATER TECH------------\n");
	printf("Bienvenido a Water Tech, una aplicacion disenada para ayudarte en el registro y analisis de los datos de calidad del agua en distintas fuentes de Madrid. Con esta herramienta, podras cargar y almacenar ficheros de datos mensuales, realizar estadisticas y busquedas sobre los datos, y mucho mas.Esperamos que disfrutes utilizando Water Tech y que te sea de gran ayuda en tu investigacion sobre la calidad del agua. Si tienes alguna pregunta o sugerencia, no dudes en contactarnos.¡Gracias por elegir Water Tech!\n");
	
	 do {
    	printf("\nSeleccione una opción:\n");
        printf("1. Cargar fichero de datos\n");
        printf("2. Mostrar datos de una fuente\n");
        printf("3. Buscar fuentes por parámetro\n");
        printf("4. Añadir datos de una fuente\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);

	switch(opcion) {
            case '1': 
            	// PASO 1: ABRIR EL ARCHIVO:
            	
            	printf("\nIntroduce el nombre del archivo:\n");
            	scanf("%s", nombreArchivo);
            
            	fichero=fopen ("nombreArchivo.txt",'r'); 
            	
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
                printf("\nOpción inválida, por favor seleccione una opción válida.\n");
        }
    } while(opcion != '5');

    return 0;
};

