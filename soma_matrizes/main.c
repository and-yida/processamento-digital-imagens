#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *matriz1, *matriz2;
    int i, j, coluna, linha;
    int **mat1, **mat2, **mat3;
    char cabecalho[300], elementos[300];

    matriz1 = fopen("matriz1.txt", "rt");

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

    //Mostrar matriz1
    printf("MATRIZ 1\n");
    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            printf("%3d ", mat1[i][j]);
        }
        printf("\n");
    }

    fclose(matriz1);


    matriz2 = fopen("matriz2.txt", "rt");

    fgets(cabecalho, "%s", matriz2);
    //printf("\n%s\n", cabecalho);
    fscanf(matriz2, "%d %d\n", &coluna, &linha);
    //printf("%d %d\n", coluna, linha);
    fgets(elementos, "%s", matriz2);
    //printf("%s\n", elementos);

    mat2 = (int **)calloc(linha,sizeof(int *));
    for(i=0; i<linha; i++) {
        mat2[i]=(int *)calloc(coluna,sizeof(int));
    }

    for (i = 0; i<linha; i++) {
        for(j = 0; j <coluna; j++) {
            fscanf(matriz2, "%d\n", &mat2[i][j]);
        }
    }

    //Mostrar matriz2
    printf("\nMATRIZ 2\n");
    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            printf("%3d ", mat2[i][j]);
        }
        printf("\n");
    }

    fclose(matriz2);

    mat3 = (int **)calloc(linha,sizeof(int *));
    for(i=0; i<linha; i++) {
        mat3[i]=(int *)calloc(coluna,sizeof(int));
    }

    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    //Mostrar matriz3
    printf("\nMATRIZ SOMA\n");
    for (i = 0; i<linha; i++) {
        for(j = 0; j<coluna; j++) {
            printf("%3d ", mat3[i][j]);
        }
        printf("\n");
    }

}
