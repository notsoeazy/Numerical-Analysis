#include<iostream>
#include<iomanip>
#include<cmath>

void SecantMethod(double (*ptr)(const double&)){
    int itr = 0;
    double Xi = NAN;
    double XiPrev = NAN;
    double fXi = NAN;
    double fXiPrev = NAN;
    double XiNew = NAN;
    
    double accuracy = 1e-10;
    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);

    do
    {
        std::cout << "Enter Xi-1: ";
        std::cin >> XiPrev;
        std::cout << "Enter Xi: ";
        std::cin >> Xi;

    } while ([](double Xi, double XiPrev) -> bool{
        if(Xi == XiPrev){
            std::cout << Xi << XiPrev;
            std::cout << "Enter another Interval...\n";
            return true;
        }
        else 
            return false;
        }(Xi, XiPrev));
    
    std::cout << "#itr" << std::setw(10)
              << "Xi-1" << std::setw(15)
              << "Xi" << std::setw(15)
              << "f(Xi-1)" << std::setw(15)
              << "f(Xi)" << std::setw(15)
              << "Xi+1\n";

    do
    {
        fXiPrev = ptr(XiPrev);
        fXi = ptr(Xi);
        
        XiNew = Xi - fXi * ((Xi - XiPrev)/(fXi - fXiPrev));

        std::cout << ++itr << "\t" << XiPrev << "\t" << Xi << "\t" <<  fXiPrev << "\t" <<  fXi << "\t" <<  XiNew << "\n";

        XiPrev = Xi;
        Xi = XiNew;

    } while (fabs(fXi) > accuracy);

    std::cout << "\nIrations: " << itr << std::endl;
    std::cout << "Root: " << XiNew << std::endl;
};


// f(x) = x^5 -21x^2 -8x^3 -4x^4 -28x + 60
double f1(const double& x){
    return pow(x, 5) - (21 * pow(x, 2)) - (8 * pow(x, 3)) - (4 * pow(x, 4)) - (28 * x) + 60;
}

// f(x) = x^3 - x^2 + e^x
double f2(const double& x){
    return pow(x, 3) - pow(x, 2) + exp(x);
};

int main(){
    std::cout << "----Secant Method----\n";

    std::cout << "Choose function:"
              << "\n1. f(x) = x^5 -21x^2 -8x^3 -4x^4 -28x + 60"
              << "\n2. f(x) = x^3 - x^2 + e^x"
              << "\n-> ";
    int choice;

    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "f(x) = x^5 -21x^2 -8x^3 -4x^4 -28x + 60\n";
        SecantMethod(f1);
        break;
    case 2:
        std::cout << "f(x) = x^3 - x^2 + e^x\n";
        SecantMethod(f2);
        break;
    default:
        std::cout<< "byee!!!\n";
        break;
    }

    return 0;
}