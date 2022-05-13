
#include"header.h"



//função para calcular a energia total
double energiaTotal()
{
    double E=0, e;
    int i, j;
    
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            e=energiaLocal(i,j);
            E+=e;
	    //E-= h * x[i][j];   linha comentada pois escolhemos um modelo onde h=0! 
        } 
    }
    
    return E;
}


