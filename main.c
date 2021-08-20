#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
  int cod, tel, sw=0;
  char nom[20],resp;
  FILE *X;
  X=fopen("agenda.dat", "r+");
  if(X==NULL){
        printf("\n\n\tError de Apertura del archivo..");
        getch();
        exit(0);
  }else{
      printf("\n\n\tApertura del Gestor Exitosa!!\n");

  }
  printf("\n\t\t----------------------");
  printf("\n\t\tAGENDA DE CONTACTOS");
  printf("\n\t\t----------------------");
  printf("\n\tC%cdigo\t\tNombre\t\tTel%cfono",162,130);
  printf("\n\t-----------------------------------------");

  while(!feof(X)){
    fscanf(X, "%d", &cod);
    fscanf(X, "%s", &nom);
    fscanf(X, "%d", &tel);
    printf("\n\t %d\t\t%s\t\t%d",cod,nom,tel);
  }
  printf("\n\n\tFIN DEL RECORRIDO DE SU AGENDA...");
  printf("\n\n\tUsted desea agregar m%cs contactos a su agenda?",160);
  printf("\n\tSi->s  No->n\t");
  scanf("%s",&resp);
  while((resp=='s')||(resp=='S')){
        printf("\n\n\tC%cdigo:\t",162);
        scanf("%d",&cod);
        printf("\n\tNombre:\t");
        scanf("%s",&nom);
        printf("\n\tTel%cfono:\t",130);
        scanf("%d",&tel);
        fprintf(X,"\n%d %s %d",cod,nom,tel);
        printf("\n\n\tRegistro Guardado!");
        printf("\n\n\tDesea agregar otro contacto a su agenda?",160);
        printf("\n\tSi->s  No->n\t");
        scanf("%s",&resp);
        sw=1;
  }

  if (sw==1){
  system("cls");
  rewind(X);
  printf("\n\t\t------------------------------------");
  printf("\n\t\tSU AGENDA DE CONTACTOS ACTUALIZADA: ");
  printf("\n\t\t----------------------");
  printf("\n\tC%cdigo\t\tNombre\t\tTel%cfono",162,130);
  printf("\n\t---------------------------------------");

  while(!feof(X)){
    fscanf(X, "%d", &cod);
    fscanf(X, "%s", &nom);
    fscanf(X, "%d", &tel);
    printf("\n\t %d\t\t%s\t\t%d",cod,nom,tel);
  }
}
  fclose(X);
  printf("\n\n\tFIN DEL PROGRAMA...");


  getch();



    return 0;
}
