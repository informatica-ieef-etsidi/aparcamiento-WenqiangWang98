
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
	int opcion_0, opcion_1, i, importe;
	char plaza_1[10]="000000000", plaza_2[10] = "000000000", plaza_null[10]= "000000000";
	time_t curtime=time(NULL);
	time_t s_t_aparc1,e_t_aparc1,s_t_aparc2, e_t_aparc2,t_1,t_2;
	char str[26];
	system("COLOR B1 ");
	while (1) {
		ctime_s(str,sizeof str,&curtime);
		system("cls");
		printf("Time: %s\n", str);
		printf("********************************************\n");
		printf("**                                        **\n");
		printf("**                *MENU*                  **\n");
		printf("**                                        **\n");
		printf("**        [1]  Reservar una plaza         **\n");
		printf("**                                        **\n");
		printf("**        [2]  Abandonar plaza            **\n");
		printf("**                                        **\n");
		printf("**        [3]  Estado de aparcamiento     **\n");
		printf("**                                        **\n");
		printf("**        [4]  Salir                      **\n");
		printf("**                                        **\n");
		printf("********************************************\n");
		scanf_s("%d", &opcion_0);
		system("cls");
		switch (opcion_0)
		{
		case 1:
			if (strcmp(plaza_1,plaza_null)==0) {
				printf("Plaza 1 libre.\n");
				printf("Introduce la matricula del coche: \n");
				scanf_s("%s",plaza_1,10);
				time(&s_t_aparc1);
				break;
			}
			else if (strcmp(plaza_2, plaza_null) == 0) {
				printf("Plaza 2 libre.\n");
				printf("Introduce la matricula del coche: \n");
				scanf_s("%s", plaza_2,10);
				time(&s_t_aparc2);
				break;
			}
			else {
				printf("No queda plazas libres, lo sentimos. \n");
				system("pause");
				break;
			}
		case 2:
			printf("Introduce la plaza que quieres abandonar(1 o 2): \n");
			scanf_s("%d", &opcion_1);
			switch (opcion_1) {
			case 1:
				if (strcmp(plaza_1, plaza_null) == 0) {
					printf("Plaza 1 ya estaba libre.\n");
					system("pause");
					break;
				}
				else {
					for (i = 0;i < 10;i++) {
						plaza_1[i] = plaza_null[i];
					}
					time(&e_t_aparc1);
					t_1 = difftime(e_t_aparc1, s_t_aparc1);
					importe = t_1 / 3600 + 1;
					printf("Hecho, ahora la plaza 1 esta libre.\n");
					printf("El importe total es de %d euros por un tiempo total de %d horas.\n",importe*2,importe);
					system("pause");
					break;
				}
			case 2:
				if (strcmp(plaza_2, plaza_null) == 0) {
					printf("Plaza 2 ya estaba libre.\n");
					system("pause");
					break;
				}
				else {
					for (i = 0;i < 10;i++) {
						plaza_2[i] = plaza_null[i];
					}
					time(&e_t_aparc2);
					t_2 = difftime(e_t_aparc2, s_t_aparc2);
					importe = t_2 / 3600 + 1;
					printf("Hecho, ahora la plaza 2 esta libre.\n");
					printf("El importe total es de %d euros por un tiempo total de %d horas.\n", importe * 2, importe);
					system("pause");
					break;
				}
			default:
				printf("Opcion no valida.\n");
				system("pause");
				break;
			}
			break;
		case 3:
			printf("Estado de aparcamiento\n");
			if (strcmp(plaza_1,plaza_null)==0) {
				printf("Plaza 1 - libre.\n");
			}
			else {
				printf("Plaza 1 - Ocupada - Matricula: %s\n", plaza_1);
			}
			if (strcmp(plaza_2, plaza_null) == 0) {
				printf("Plaza 2 - libre.\n");
			}
			else {
				printf("Plaza 2 - Ocupada - Matricula: %s\n", plaza_2);
			}
			system("pause");
			break;
		case 4:
			return 0;
		default:
			printf("Opcion no valida. \n");
			break;
		}
	}
}
