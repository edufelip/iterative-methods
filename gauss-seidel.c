#include <stdio.h>
#include <math.h>

int main (void) {
    int k = 0, dim, i, j, criterion = 1;
    double margin;
    printf("INSERT THE MATRIX'S DIMENSION\n");
    scanf("%d", &dim);
    printf("INSERT THE ERROR MARGIN BETWEEN ITERATIONS?\n");
    scanf("%lf", &margin);
    double a[dim][dim], b[dim], c[dim], y[dim], sup, difer[dim], diferSup;
    printf("INSERT THE MATRIX A\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    printf("INSERT THE MATRIX B\n");
    for(i = 0; i < dim; i++){
        scanf("%lf", &b[i]);
    }
    printf("INSERT THE MATRIX X\n");
    for(i = 0; i < dim; i++){
        scanf("%lf", &c[i]);
    }
    while(criterion) {
        for(i = 0; i < dim; i++){
            y[i] = b[i];
            for(j = 0; j < dim; j++){
                if(i != j){
                    y[i] = y[i] - (a[i][j] * c[j]);
                }
            }
            y[i] = y[i]/a[i][i];
            sup = c[i];
            c[i] = y[i];
            y[i] = sup;
        }
        for(i = 0; i < dim; i++){
            difer[i] = c[i] - y[i];
        }
        diferSup = 0;
        for(i = 0; i < dim; i++){
            diferSup += (difer[i]*difer[i]);
        }
        diferSup = sqrt(diferSup);
        if(diferSup < margin){
            criterion = 0;
        }
        k++;
        printf("ITERATION NUMBER %d\n", k);
        for(i = 0; i < dim; i++){
            printf("x[%d] = %.6lf\n", i+1, c[i]);
        }
    }

    printf("\n RESULT: \n");
    for(i = 0; i < dim; i++){
        printf("%.15lf \n", c[i]);
    }
        printf("\nITERATIONS: %d \n", k);
    return 0;
}