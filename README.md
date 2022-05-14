# Modelo-de-Ising

O modelo de Ising é muito empregado na física do estado sólido e consiste em um modelo teórico que descreve de forma clara as propriedades magnéticas, bem como, busca simular a estrutura de uma substância ferromagnética. Obtido através de uma simplificação do modelo de Heisenberg, este é tido como um modelo dinâmico de transição de fase que incorpora interações de curto alcance numa rede d-dimensional.

O programa utiliza o algoritmo Metropolis que é o algoritmo mais conhecido para se gerar uma cadeia de Markov em sistemas de spins. Este algoritmo é do tipo Monte Carlo, são uma classe de algoritmos que utilizam amostragem aleatória repetida para encontrar resultados.

O objetivo do projeto é criar um programa serial em C/C++ do modelo de Ising, fazer varias simulações e depois validar os resultados obtidos com os resultados esperados, encontrados nas literaturas de Física.

Os gráficos foram feitos no gnuplot. As simulações foram realizados com a seguinte condição inicial:

• Interação entre os spins vizinhos (J = 1);
• Constante de Boltzmann (k = 1);
• Sem campo magnético externo (h = 0);
• Número de passos de Monte Carlo (iter = 10000);
• Intervalo de temperatura escolhido, T ∈ [1,6] com gap de 0.01;
• Temperatura de Curie ou temperatura crítica Tc ≈ 2.269.

Começamos as simulações de T = 6 com todas as malhas, onde 90% dos sites tem o valor
do spin igual +1 e 10% dos sites com o valor do spin igual −1.

Para analisarmos os resultados obtidos pelo programa serial base, realizamos diversas
medidas (Energia, Magnetização, Calor específico e Suscetibilidade magnética) em sistemas
com dimensões 2×2, 10×10, 50×50, 100×100, 155×155 e 180×180.

Este código serial, com a condição inicial descrita a cima e com uma malha de tamanho 180x180, demora 3 horas e 20 minutos para rodar. Então o próximo objetivo do projeto é paralelizar este código serial e ver o quanto podemos ganhar de desempenho.
