

#include"header.h"




//função para calcular a energia em um local específico na matriz de spins
double energiaLocal(int i, int j)
{
    int acima, abaixo, direita, esquerda;
    double e;
    
    //impondo condições de contorno periódicas
    if(i==(N-1))
        acima=0;
    else
        acima=i+1;
    
    if(i==0)
        abaixo=N-1;
    else
        abaixo=i-1;
    
    if(j==(N-1))
        direita=0;
    else
        direita=j+1;
    
    if(j==0)
        esquerda=N-1;
    else
        esquerda=j-1;
    
    e=-J * x[i][j] * (x[i][direita] + x[i][esquerda] + x[abaixo][j]+ x[acima][j]);
    
    return e;   
}



