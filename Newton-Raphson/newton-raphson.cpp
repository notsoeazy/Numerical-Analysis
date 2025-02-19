#include<iostream>
#include<cmath>
#include<iomanip>

void NewtonRaphson(double (*function)(const double&), double (*Dxfunction)(const double&)){
    int itr = 0;
    double Xi = NAN, fXi = NAN, fDXi = NAN, XiPrev = NAN;
    double marginOfError = 1e-10;

    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);

    do {
        std::cout << "Enter initial guess: ";
        std::cin >> Xi;

        fDXi = Dxfunction(Xi);
    } while([](const double& value) -> bool { //lambda function eyy
        if (value == 0){
            std::cout << "Initial guess will result in divide by 0...\n";
            return true;
        }
        else
            return false;
    }(fDXi));

    std::cout << "#itr" << std::setw(10)
              << "Xi" << std::setw(20)
              << "f(Xi)" << std::setw(15)
              << "f'(Xi)\n";

    do {

        fXi = function(Xi);
        fDXi = Dxfunction(Xi);

        std::cout << ++itr << "\t" << Xi << "\t" << fXi << "\t" <<  fDXi << "\n";

        XiPrev = Xi;

        Xi = XiPrev - (fXi/fDXi);

    } while (fabs(Xi - XiPrev) > marginOfError);
    
    std::cout << "Number of iterations: " << itr << std::endl;
    std::cout << "The root is: " << Xi << std::endl;

};

//FUNCTIONS

// f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12
double f1(const double& x){
    return pow(x, 4) + (2 * pow(x, 3)) - (7 * pow(x, 2)) - (8 * x) + 12;
};
double Dxf1(const double& x){
    return (4 * pow(x, 3)) + (6 * pow(x, 2)) - (14 * x) - 8;
};

// f(x) = x^3 - x^2 + e^-x
double f2(const double& x){
    return pow(x, 3) - pow(x, 2) + exp(-1 * x);
};
double Dxf2(const double& x){
    return (3 * pow(x, 2)) - (2 * x) - exp(-1 * x);
};


int  main(){
    std::cout << "----Newton Raphson Method----\n";

    std::cout << "Choose function:"
              << "\n1. f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12"
              << "\n2. f(x) = x^3 - x^2 + e^-x"
              << "\n-> ";
    int choice;

    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12\n";
        NewtonRaphson(f1, Dxf1);
        break;
    case 2:
        std::cout << "f(x) = x^3 - x^2 + e^-x\n";
        NewtonRaphson(f2, Dxf2);
        break;
    default:
        std::cout<< "byee!!!\n";
        break;
    }

    return 0;
};