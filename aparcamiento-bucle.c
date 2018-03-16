#include<stdio.h>//Aparcamiento2
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 4
#define _CRT_SECURE_NO_WARNINGS
struct plazas{
    int estado;//0 si esta libre y 1 si esta ocupado
    int tipo; //1 para moto y 2 para coche
    char matricula[8]; //NNNNLLL
    time_t s_t_aparc,e_t_aparc;
};
int main(){
    time_t ahora;
    struct plazas plaza[N]={{0,1},{0,1},{0,2},{0,2}};
    int r,a,e,j,b,opcion_tipo,opcion_matricula,opcion_princ,importe;
    char matricula_aux[8];
    system("COLOR B1 ");
    while(1){
        time(&ahora);
        printf("Tiempo: %s",ctime(&ahora));
        printf("******************************************************\n");
        printf("**                                                  **\n");
        printf("**                      *MENU*                      **\n");
        printf("**                                                  **\n");
        printf("**           [1]  Reservar una plaza                **\n");
        printf("**                                                  **\n");
        printf("**           [2]  Abandonar plaza                   **\n");
        printf("**                                                  **\n");
        printf("**           [3]  Estado de aparcamiento            **\n");
        printf("**                                                  **\n");
        printf("**           [4]  Buscar vehiculo por matricula     **\n");
        printf("**                                                  **\n");
        printf("**           [5]  Salir                             **\n");
        printf("**                                                  **\n");
        printf("******************************************************\n");
        scanf("%d", &opcion_princ);
        system("cls");
        switch(opcion_princ){
            case 1:
                printf("Introduce el tipo del vehiculo. Moto(1) o coche(2).\n");
                scanf("%d",&opcion_tipo);
                if(opcion_tipo<1||opcion_tipo>2){
                    printf("Opcion no valida.\n");
                    system("pause");
                    continue;
                }
                for(r=0;r<=N-1;r++){
                    if(plaza[r].tipo==opcion_tipo&&plaza[r].estado==0){
                        printf("Plaza %d libre.\n",r+1);
                        opcion_matricula=0;
                        printf("Introduce la matricula.\n");
                        scanf("%s",matricula_aux);
                        for(j=0;j<=3;j++){
                            if(matricula_aux[j]<58&&matricula_aux[j]>47)
                                opcion_matricula++;
                        }
                        for(j=4;j<=6;j++){
                            if((matricula_aux[j]>64&&matricula_aux[j]<91)||(matricula_aux[j]>96&&matricula_aux[j]<123))
                                opcion_matricula++;
                        }
                        if(opcion_matricula==7){
                            for(j=0;j<7;j++){
                                plaza[r].matricula[j]=matricula_aux[j];
                            }
                            plaza[r].estado=1;
                            time(&plaza[r].s_t_aparc);
                            printf("Se ha reservado la plaza %d con exito.\n",r+1);
                            break;
                        }
                        else{
                            printf("Matricula no valida.\n");
                            break;
                        }
                    }else if(r==N-1){
                        printf("Lo sentimos, todas las plazas de %s estan ocupadas.\n",opcion_tipo==1?"Moto":"Coche");
                    }
                }
                break;
            case 2:
                printf("Elige la plaza que quieres abandonar.\n");
                scanf("%d",&a);
                switch(plaza[a-1].estado){
                case 0:
                        printf("Plaza %d esta libre.\n",a);
                        break;
                case 1:
                        plaza[a-1].estado=0;
                        printf("Se ha abandonado la plaza %d con exito.\n",a);
                        time(&plaza[a-1].e_t_aparc);
                        importe=((difftime(plaza[a-1].e_t_aparc, plaza[a-1].s_t_aparc)/3600)+1)*plaza[a-1].tipo;
                        printf("Tiene que pagar %d euros.\n",importe);
                default:
                        printf("Opcion no valida.\n");
                        break;
                }
                break;
            case 3:
                for(e=0;e<=N-1;e++){
                    printf("plaza %d - ",e+1);
                    if(plaza[e].estado==0){
                        printf("Libre.\n");
                    }
                    else {
                        if(plaza[e].tipo==1){
                            printf("Moto - ");
                        }else{
                            printf("Coche - ");
                        }
                        printf("%s.\n",plaza[e].matricula);
                    }
                }
                break;
            case 4:
                printf("Introduce la matricula del vehiculo que quieres buscar.\n");
                scanf("%s",matricula_aux);
                for(b=0;b<=N-1;b++){
                    if(strcmp(matricula_aux, plaza[b].matricula)==0){
                        printf("Su vehiculo esta en la plaza %d.\n",b+1);
                        break;
                    }else if(b==N-1)
                        printf("No se ha encontrado su vehiculo.\n");
                }
                break;
            case 5:
                return 0;
            default:
            printf("Opcion no valida.\n");
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
