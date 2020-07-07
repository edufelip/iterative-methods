#include <stdio.h>
#include <math.h>

int main (void) {
    int k = 0, dim = 30, i, j, criterio = 1;
    double margem = pow(10, -9);
    long double A[dim][dim], b[dim], d[dim][dim], y[dim], z[dim], difer[dim], diferSup, r[dim], v[dim], aux = 0, m, s, sDen, aux1;
    long double x[dim], g[dim], alpha[dim], dHold[dim]; 

    for(i = 0; i < dim; i++){
        if(i == 0) {
            b[i] = 1;
        } else if(i == dim - 1){
            b[i] = 1;
        } else {
            b[i] = 0;
        }
        for(j = 0; j < dim; j++){
            if(i == j){
                A[i][j] = -2*(1+(0.1*0.1));
            } else if (j == i + 1){
                A[i][j] = 1;
            } else if (j == i - 1){
                A[i][j] = 1;
            } else {
                A[i][j] = 0;
            }
        }
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
                z[i] += (v[j] * A[j][i]);
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
        if(diferSup > margem){
            criterio = 1;
        }
        if(diferSup == 1) criterio = 0;
        k++;
    }

    for(i = 0; i < dim; i++){
        printf("x[%d]  %.40Lf \n", i, x[i]);
    }
    printf("\nIteraçoes: %d \n", k);
    return 0;
}