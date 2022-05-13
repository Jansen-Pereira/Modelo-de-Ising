
#include"header.h"


//função para inicializar os spins aleatoriamente com 90% up e 10% down
void geraSpins()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            x[i][j]= 1;
        }
    }

    

    for(int cont=0; cont<((N*N)*0.1); cont++)
    {
	
        
	//escolhendo um spin aleatório na matriz
       int i=(rand()%N+1)-1;
       int j=(rand()%N+1)-1;
                
	if(x[i][j]==1){
		// girando o spin da posição (i,j)
		x[i][j]=-1;
	}
	else{
		int i=(rand()%N+1)-1;
      		int j=(rand()%N+1)-1;

		x[i][j]=-1;
	
	}
       
    }


}


