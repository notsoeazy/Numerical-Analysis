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

    } while ([](bool Xi, bool XiPrev) -> bool{
        if(Xi == XiPrev){
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

    std::cout << "\nerations: " << itr << std::endl;
    std::cout << "Root: " << XiNew << std::endl;
};

// f(x) = x^3 - x^2 + e^-x
double f2(const double& x){
    return pow(x, 3) - pow(x, 2) + exp(-1 * x);
};

int main(){
    SecantMethod(f2);
    return 0;
}