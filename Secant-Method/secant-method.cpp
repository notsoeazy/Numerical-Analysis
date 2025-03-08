#include<iostream>
#include<cmath>
#include<iomanip>


void SecantMethod(double (*f)(const double& )){
    const double accuracy = 1e-11;
    int itr = 0;
    double xi, xiPrev, fxi, fxiPrev, xiNew;
    
    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::right);

    do{
        std::cout << "Enter Xi-1: ";
        std::cin >> xiPrev;
        std::cout << "Enter Xi: ";
        std::cin >> xi;
    } while(
        [](const double& num1, const double& num2) -> bool{
            if(num1 == num2){
                std::cout << "Enter again...\n";
                return true;
            } else {return false;}
        }(xiPrev, xi)
    );

    std::cout << std::setw(5) << "itr"
              << std::setw(20) << "Xi-1"
              << std::setw(20) << "Xi"
              << std::setw(20) << "f(Xi)"
              << std::setw(20) << "f(Xi-1)"
              << std::setw(20) << "Xi+1"
              << std::endl;

    do{
        fxi = f(xi);
        fxiPrev = f(xiPrev);
        xiNew = xi - (fxi * (xi - xiPrev)/(fxi - fxiPrev));
        std::cout << std::setw(5) << ++itr
                  << std::setw(20) << xiPrev
                  << std::setw(20) << xi
                  << std::setw(20) << fxi
                  << std::setw(20) << fxiPrev
                  << std::setw(20) << xiNew
                  << std::endl;
        xiPrev = xi;
        xi = xiNew;
    } while(fabs(f(xiNew)) > accuracy);
    std::cout << "\nThe root is " << xiNew 
              << "\nFounf in " << itr << " iterations.\n";
}

// f(x) = x^5 -21x^2 -8x^3 -4x^4 -28x + 60
double f1(const double& x){
    return pow(x, 5) - (21 * pow(x, 2)) - (8 * pow(x, 3)) - (4 * pow(x, 4)) - (28 * x) + 60;
}
// f(x) = x^3 - x^2 + e^x
double f2(const double& x){
    return pow(x, 3) - pow(x, 2) + exp(x);
};

int main(){
    std::cout << "---- S E C A N T  M E T H O D ----\n"
              << "Choose a function:\n"
              << "\t1. f(x) = x^5 -21x^2 -8x^3 -4x^4 -28x + 60\n"
              << "\t2. f(x) = x^3 - x^2 + e^x\n"
              << "-> ";
    int c;
    std::cin >> c;

    switch(c)
    {
        case 1:
            SecantMethod(f1);
            break;
        case 2:
            SecantMethod(f2);
            break;
        dafault:
        break;
    }
    
    std::cout << "\nBye bye!\n";
    return 0;
}