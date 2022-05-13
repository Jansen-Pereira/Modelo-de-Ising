#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<time.h>


using namespace std;

//Variáveis Globais
int x[180][180];

int J=1, k=1, h=0, N=180, iter=10000;
double minT=1, maxT=6, deltaT=0.01; //parâmetros de temperatura 

void geraSpins();
double energiaLocal(int i, int j);
double energiaTotal();
double magnetizacaoTotal();
bool validaGiro(int i, int j, double T);



#endif
