
#include"header.h"


//função para testar a validade do giro do spin (troca de sinal)
bool validaGiro(int i, int j, double T)
{

    //calcular a variação de energia
    double de = 2*energiaLocal(i,j);
    
    if(de<0)
        return true;
    else if(de==0)
    {
        if((rand()%2+1)==2)
            return true;
        else
            return false; 
    } 
    else
    {

	// gera um número aleatório entre 0 e 1 e verifica se está além de uma certa probabilidade determinada pelo fator de Boltzmann
        double prob=(double) rand()/(RAND_MAX);
        
        if(prob<=exp(-de/(k*T)))
           return true;
           
        else
           return false;
    }
}

