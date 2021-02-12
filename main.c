#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 20
#define NMESES 12

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	int num_miembros, i, j, k, pos_mayor_donante, bandera_busqueda = 0, pos_miembro_busqueda, flag_donacion = 1;
	char **nombre_miembros, **paises, ver_temp_miembro[20];
	float **donaciones_mes, total_recaudado_mes[NMESES], mayor_donacion = -99, donacion_miembro, primer_semestre = 0, segundo_semestre = 0, total_recaudado_global = 0;
	
	printf("===============\n");
	printf("| BIENVENIDO |\n");
	printf("===============\n");

	printf("\nCuantos miembros desea ingresar?: ");
	scanf("%d", &num_miembros);

	for(i = 0; i < NMESES; i++){
		
		total_recaudado_mes[i] = 0;
		
	}
	
	nombre_miembros = (char **) malloc(sizeof(char *) * num_miembros);
	
	for(i = 0; i < num_miembros; i++){
		
		nombre_miembros[i] = (char *) malloc(sizeof(char) * MAXCHAR);
		
	}
	
	
	paises = (char **) malloc(sizeof(char *) * num_miembros);
	
	for(i = 0; i < num_miembros; i++){
		
		paises[i] = (char *) malloc(sizeof(char) * MAXCHAR);
		
	}
	
	donaciones_mes = (float **) malloc(sizeof(float *) * num_miembros);
	
	for(i = 0; i < num_miembros; i++){
		
		donaciones_mes[i] = (float *) malloc(sizeof(float) * NMESES);
		
	}
	
	//CARGA DE DATOS
	
	printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");
	
	for(i = 0; i < num_miembros; i++){
		
		printf("\nInserte el nombre del miembro: ");
		scanf("%s", nombre_miembros[i]);

		printf("\nInserte el nombre del pais: ");
		scanf("%s", paises[i]);

		
		
		for(j = 0; j < NMESES; j++){
			
			printf("\nInserte la donacion para el mes %d: ", j + 1);
			scanf("%f", &donaciones_mes[i][j]);
			
		}
		
		/*for(j = 0; j < num_miembros; j++){
			for(k = 0; k < NMESES; k++){
				
				printf("La donacion del mes %d es %.2f \n", k + 1, donaciones_mes[j][k]);
				
			}
			
		}*/
		
	}
	
	printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
	
	//TOTAL RECAUDADO DE CADA MES
	
	for(i = 0; i < num_miembros; i++){
		for(j = 0; j < NMESES; j++){
			
			total_recaudado_mes[j] += donaciones_mes[i][j];
			
		}
		
		
	}
	
	printf("\n");
		
	for(i = 0; i < NMESES; i++){
		
		printf("\nEl total recaudado del mes %d es: %.2f\n", i + 1, total_recaudado_mes[i]);
		
	}
	
	printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");
	
	//MAYOR DONACION DEL A�O
	
	for(i = 0; i < num_miembros; i++){
		donacion_miembro = 0;
		for(j = 0; j < NMESES; j++){
			
			donacion_miembro += donaciones_mes[i][j]; 
			
		}
		
		if(donacion_miembro > mayor_donacion){
			
			mayor_donacion = donacion_miembro;
			pos_mayor_donante = i;
			
		}
		
	}
	
	printf("\nEl mayor donante fue %s del pais %s con %.2f\n", nombre_miembros[pos_mayor_donante], paises[pos_mayor_donante], mayor_donacion);
	
	//VERIFICACION DE DONACIONES
	
	printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
	
	do{
		
		printf("\nIngrese el nombre del miembro a verificar: ");
		scanf("%s", ver_temp_miembro);
		
		
		for(i = 0; i < num_miembros; i++){

			if(strcmp(ver_temp_miembro, nombre_miembros[i]) == 0){
				
				pos_miembro_busqueda = i; 
				bandera_busqueda = 1;
				break;
			}
				
		}
		
		if(bandera_busqueda == 0){
			
			printf("\nX====================================X\n");
			printf("\nMiembro invalido. Por favor ingrese el nombre correcto\n");
			printf("\nX====================================X\n");			
			
		}
		
	}while(bandera_busqueda == 0);
	
	for(i = 0; i < NMESES; i++){
		
		if(donaciones_mes[pos_miembro_busqueda][i] <= 0 ){
			
			flag_donacion = 0;
			break;
		}
		
	}

	if(flag_donacion == 0){
		
		printf("\nX====================================X\n");			
		printf("\nEl miembro no dono durante todos los meses\n");	
		printf("\nX====================================X\n");			
			
	}else{
		
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");			
		printf("\nEl miembro dono durante todos los meses\n");	
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");		
		
	}
	
	//MENOR SEMESTRE DE RECAUDACION
	
	for(i = 0; i < num_miembros; i++){
		for(j = 0; j < 6; j++){
			
			primer_semestre += donaciones_mes[i][j];	
			
		}
				
		
	}
	
	for(i = 0; i < num_miembros; i++){
		for(j = 6; j < 12; j++){
			
			segundo_semestre += donaciones_mes[i][j];
			
		}
		
		
	}
	
	if(primer_semestre == segundo_semestre){
		
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
		printf("\nAmbos semestres recaudaron la misma cantidad de dinero\n");
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
				
	}else if(primer_semestre < segundo_semestre){
		
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");		
		printf("\nEn el primer semestre se recaudo menos dinero\n");
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
			
	}else{
		
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");	
		printf("\nEn el segundo semestre se recaudo menos dinero\n");
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");		
		
	}
	
	//VERIFICACION MES DE MARZO
	
	for(i = 0; i < NMESES; i++){
		
		total_recaudado_global += total_recaudado_mes[i];
			
	}
	
	if(total_recaudado_global * 0.15 <= total_recaudado_mes[2]){
		
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");			
		printf("\nEn el mes de marzo hubo al menos el 15%% de la recaudacion del a%co\n", 164);
		printf("\n[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]\n");		
		
	}else{

		printf("\nX===============================================================X\n");		
		printf("\nEn el mes de marzo no hubo al menos el 15%% de la recaudacion del a%co\n", 164);
		printf("\nX===============================================================X\n");
				
	}
	
	return 0;
}
