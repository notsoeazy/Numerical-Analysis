#include<iostream>
#include<cmath>
#include<iomanip>

void NewtonRaphson(double (*function)(double), double (*Dxfunction)(double)){
    int itr = 0;
    double Xi = NAN, fXi = NAN, fDXi = NAN;
    double XiPrev = NAN;

    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);

    do {
        std::cout << "Enter initial guess: ";
        std::cin >> Xi;

        fDXi = Dxfunction(Xi);
    } while(fDXi == 0);//lambda??

    do (
        std::cout << "#itr" << std::setw(10) << "Xi" << std::setw(20) << "f(Xi)" << std::setw(15) << "f'(Xi)\n";

        fXi = function(Xi);

        std::cout << itr << "\t" << Xi << "\t" << fXi << "\t" <<  fDXi << "\n";
    ) while(Xi != XiPrev);


};

// f(x) = x - e^(-x^2)
double f1(double x){
    return x - exp(-1 * pow(x, 2));
};
double Dxf1(double x){
    return 1 + (2 * x) * exp(-1 * pow(x, 2));
};

// f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12

int  main(){
    // std::cout << "Pogi ako\n";
    NewtonRaphson(f1, Dxf1);
    return 0;
};