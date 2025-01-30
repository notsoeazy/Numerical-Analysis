#ifndef REGULAFALSI_HPP
#define REGULAFALSI_HPP

#include<cmath>
#include<iostream>

class RegulaFalsi{
    
public:
    RegulaFalsi(double (*funcPtr)(double));
    void SetInterval();
    void SolveRoot();

private:
    double (*f)(double);
    double lowerInterval, upperInterval;
    double Xa, Xb, Xr, XrPrev;
    double fXa, fXb, fXr;
    int itr;
    double accuracy;
};


#endif