#include <stdio.h>
#include <math.h>

int main (void) {
    int k = 0, dim, i, j, criterio = 1;
    double margin;

    printf("INSERT THE MATRIX'S DIMENSION\n");
    scanf("%d", &dim);
    printf("INSERT THE ERROR MARGIN BETWEEN ITERATIONS?\n");
    scanf("%lf", &margin);

    double a[dim][dim], b[dim], d[dim][dim], y[dim], z[dim], difer[dim], diferSup, r[dim], v[dim], aux = 0, m, s, sDen, aux1;
    double x[dim], g[dim], alpha[dim], dHold[dim]; 

    printf("INSERT THE MATRIX A (SYMMETRIC SEMIDEFINITE POSITIVE)\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    printf("INSERT THE MATRIX B\n");
    for(i = 0; i < dim; i++){
        scanf("%lf", &b[i]);
    }

    for(i = 0; i < dim; i++){
        r[i] = b[i];
        v[i] = b[i];
    }
    aux = 0;
    for(i = 0; i < dim; i++){
        aux += r[i] * r[i];
    }

    while(criterio) {
        for(i = 0; i < dim; i++){
            z[i] = 0;
            for(j = 0; j < dim; j++){
                z[i] += (v[j] * a[j][i]);
            }
        }
        sDen = 0;
        for(i = 0; i < dim; i++){
            sDen += v[i] * z[i];
        }
        s = aux / sDen;
        for(i = 0; i < dim; i++){
            y[i] = x[i];
            x[i] = x[i] + v[i] * s;
        }
        for(i = 0; i < dim; i++){
            r[i] = r[i] - s * z[i];
        }
        aux1 = 0;
        for(i = 0; i < dim; i++){
            aux1 += r[i] * r[i];
        }
        m = aux1/aux;
        aux = aux1;
        for(i = 0; i < dim; i++){
            v[i] = r[i] + m * v[i];
        }
        criterio = 0;
        for(i = 0; i < dim; i++){
            difer[i] = x[i] - y[i];
        }
        diferSup = 0;
        for(i = 0; i < dim; i++){
            diferSup += (difer[i]*difer[i]);
        }
        diferSup = sqrt(diferSup);
        if(diferSup > margin){
            criterio = 1;
        }
        if(diferSup == 1) criterio = 0;
        k++;
    }

    printf("\n RESULTS: \n");
    for(i = 0; i < dim; i++){
        printf("x[%d]  %.6F \n", i, x[i]);
    }
    printf("\nITERATIONS: %d \n", k);
    return 0;
}