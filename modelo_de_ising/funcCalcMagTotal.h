
#include"header.h"


//função para calcular a magnetização total
double magnetizacaoTotal()
{
    double m=0;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
           m+=x[i][j];
        } 
    }
    
    return m;
}   


