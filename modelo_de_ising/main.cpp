/* Modelo de Ising - Algoritmo Metropolis*/

#include"header.h"



#include"funcGeraSpins.h"
#include"funcCalcEnergiaLocal.h"
#include"funcCalcEnergiaTotal.h"
#include"funcCalcMagTotal.h"
#include"funcValidaGiro.h"






int main()
{ 
    

    clock_t t1, t2; // duas variáveis para guardar o registro clock

    t1 = clock(); //gravando a hora de início do programa



    int i, j, l, m, r, it;
    double T=maxT;
    double energia, totalEnergia, medEnergia, de;                          //variáveis para os cálculos de energia
    double mag, totalMag, medMag;  //variáveis para os cálculos de magnetização
    double C, medEnergia2, totalEnergia2;                                          //variáveis para os cálculos do calor específico
    double X, medMag2, totalMag2;                                     //variáveis para os cálculos da suscetibilidade

    double normConstant=1.0/(iter*N*N); // constante de normalização 
    
    geraSpins(); //inicializando uma configuração aleatória dos spins
    
  
    
    //abrindo um arquivo de texto para escrever os dados	
    ofstream output;
    output.open("saida.txt");
    
    while(T>=minT) // loop da temperatura
    {
        energia=0.5*energiaTotal(); //o algoritmo conta todas as interações dos vizinhos mais próximos duas vezes

        mag=magnetizacaoTotal();

	//inicializando as variáveis de soma
        totalEnergia=0;
	totalEnergia2=0;
        totalMag=0;
        totalMag2=0;

        
        for(it=1; it<iter; it++) // passos de Monte Carlo
        {
            for(l=0; l<N*N; l++) //loop do Algoritmo Metropolis
            {
		//escolhendo um spin aleatório na matriz
                i=(rand()%N+1)-1;
                j=(rand()%N+1)-1;
                
		// girando o spin da posição (i,j)
                x[i][j]*=-1;
                
		//calculando a variação de energia local
                de=2*energiaLocal(i,j);
                
                if(validaGiro(i,j,T))
                {//aceitando o giro do spin (traca de sinal)
                    energia+=de;
                    mag+=2*x[i][j];
                }
                else
	        //recusando o giro do spin (traca de sinal)
                    x[i][j]*=-1;  
                
            }
	    

            totalEnergia+=energia*normConstant;
	    totalEnergia2+=(energia*normConstant)*(energia*normConstant);	
            totalMag+= fabs(mag*normConstant);
            totalMag2+=(mag*normConstant)*(mag*normConstant);
        }

	medEnergia=totalEnergia;
	medMag=totalMag;


	// Cálculo final das médias e médias quadráticas
			
	totalEnergia = (totalEnergia/it);
	totalEnergia *=  totalEnergia;

	totalEnergia2 /= it;

	totalMag = (totalMag/it);			
	totalMag *= totalMag;
					
	totalMag2 /= it;							

        
	//calculando a Suscetibilidade magnética
        X = pow(N,2)*(totalMag2 - totalMag)/T;

	//calculando o Calor Específico
	C = pow(N,2)*(totalEnergia2 - totalEnergia)/pow(T,2); 

        //imprimindo os dados no arquivo dados.txt
        output<<T<<"\t"<<medEnergia<<"\t"<<medMag<<"\t"<<C<<"\t"<<X<<endl;
        
        T-=deltaT;
        
    }
    
    
    
    t2 = clock(); //gravando a hora do fim do programa
    double diff = (((double)t2 - (double)t1) / (double)CLOCKS_PER_SEC); // calculando o tempo levado pelo programa para compilar
    cout<<"\nO tempo gasto foi de "<<diff<<" segundos"<<endl;
}
