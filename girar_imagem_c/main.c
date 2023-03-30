#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *matriz1, *matriz2;
    int i, j, coluna, linha;
    int **mat1, **mat_90graus;
    char cabecalho[300], elementos[300], tipo[5];

    matriz1 = fopen("matriz1.pgm", "rt");

    fgets(tipo, "%s", matriz1);
    //printf("%s\n", tipo);
    fgets(cabecalho, "%s", matriz1);
    //printf("%s\n", cabecalho);
    fscanf(matriz1, "%d %d\n", &coluna, &linha);
    //printf("%d %d\n", coluna, linha);
    fgets(elementos, "%s", matriz1);
    //printf("%s\n", elementos);

    mat1 = (int **)calloc(linha,sizeof(int *));
    for(i=0; i<linha; i++) {
        mat1[i]=(int *)calloc(coluna,sizeof(int));
    }

    for (i = 0; i<linha; i++) {
        for(j = 0; j <coluna; j++) {
            fscanf(matriz1, "%d\n", &mat1[i][j]);
        }
    }

    /*
    //Mostrar matriz1
    printf("MATRIZ 1\n");
    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            printf("%3d ", mat1[i][j]);
        }
        printf("\n");
    }
    */
    fclose(matriz1);


    mat_90graus = (int **)calloc(coluna,sizeof(int *));
    for(i=0; i<linha; i++) {
        mat_90graus[i]=(int *)calloc(coluna,sizeof(int));
    }

    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            mat_90graus[j][linha-1-i] = mat1[i][j];
        }
    }

    /*
    //Mostrar matriz invertida em menos 90 graus
    printf("\n\n\n\nMATRIZ GIRADA EM 90 GRAUS\n");
    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            printf("%3d ", mat_90graus[i][j]);
        }
        printf("\n");
    }
    */

    matriz2 = fopen("matriz2.pgm", "w");
    fprintf(matriz2, "%s", tipo);
    fprintf(matriz2, "%s", cabecalho);
    fprintf(matriz1, "%d %d\n", coluna, linha);
    fprintf(matriz1, "%s", elementos);
    for(i = 0; i <linha; i++) {
        for(j = 0; j<coluna; j++) {
            fprintf(matriz2, "%d ", mat_90graus[i][j]);
        }
    }
    fclose(matriz2);

}
