#include <math.h>
#include "pav_analysis.h"




float compute_power(const float *x, unsigned int N) {
    float pot=1e-14;
    for(int n=0;n<N;n++){
        pot+=x[n]*x[n];
    }
    return 10*log10((1./N)*pot);
}


float compute_am(const float *x, unsigned int N) {
    float A=0;
    for(int n=0;n<N;n++){
        A+=fabs(x[n]);
    }
    return (1/N)*A;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
        int contador=0;
        float zcr = 0;
    for(unsigned int n=1; n < N; n++){
        if ((x[n]*x[n-1])<0){
          contador++;
        }
    }
    zcr=fm/(2.0*(N-1.0))*contador;
   return zcr;

}
