#include<iostream>
#include<cmath>
#include<iomanip>
#include<complex>


void MullerMethod(std::complex<double> (*f)(const std::complex<double>&)){
    std::complex<double> x0, x1, x2, x3, fx0, fx1, fx2, fx3, h0, h1, d0, d1, a, b, c;
    int itr = 0;
    double accuracy = 1e-11;

    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);
    
    do {
        // std::cout << "Enter x0: ";
        // std::cin >> x0;
        // std::cout << "Enter x1: ";
        // std::cin >> x1;
        // std::cout << "Enter x2: ";
        // std::cin >> x2;
        std::cout << "Enter x0 x1 x2: ";
        std::cin >> x0 >> x1 >> x2;
    } while (x0 == x1 || x0 == x2 || x1 == x2);

    std::cout << "itr#" << std::setw(15)
              << "x0" << std::setw(40)
              << "x1" << std::setw(40) 
              << "x2" << std::setw(40) 
              << "x3" <<std::endl;
    do {
        fx0 = f(x0);
        fx1 = f(x1);
        fx2 = f(x2);
        
        h0 = x1 - x0;
        h1 = x2 - x1;
        
        d0 = (fx1 - fx0)/(x1 - x0);
        d1 = (fx2 - fx1)/(x2 - x1);
        
        a = (d1 - d0)/(h1 + h0);
        b = (a * h1) + d1;
        c = fx2;

        std::complex<double> discriminant = sqrt(std::pow(b, 2) - (4.0 * a * c));

        if(abs(b + discriminant) > abs(b - discriminant)){
            x3 = x2 + (-2.0 * c)/(b + discriminant); 
        } else {
            x3 = x2 + (-2.0 * c)/(b - discriminant); 
        }
        //compare kung alin masmalapit sa x2, yun gagamitin na x3
        // if (fabs(b + sqrt(std::pow(b, 2) - (4.0 * a * c)) > abs(b - sqrt(std::pow(b, 2) - (4.0 * a * c))){
        //     x3 = x2 + (-2.0 * c)/(b + (sqrt(std::pow(b, 2) - (4.0 * a * c)))); 
        // } else {
        //     x3 = x2 + (-2.0 * c)/(b - (sqrt(std::pow(b, 2) - (4.0 * a * c)))); 
        // }
        
        std::cout << ++itr << "\t"
                  << x0 << "\t\t"
                  << x1 << "\t\t"
                  << x2 << "\t\t"
                  << x3 << "\n";

        x0 = x1;
        x1 = x2;
        x2 = x3;

        fx3 = f(x3);
        
    } while(fabs(fx3) >= accuracy);

    //show root (x3)
    if(x3.imag() == 0.0){
        std::cout << "The Real root is: " << x3.real() << std::endl;
    }
    else if(x3.imag() < 0.0){
        std::cout << "The roots are: " << x3.real() << "+" << fabs(x3.imag()) << "i" << std::endl
                  << "               " << x3.real() << "-" << fabs(x3.imag()) << "i" << std::endl;
    }
    else if(x3.imag() > 0.0){
        std::cout << "The roots are: " << x3.real() << "+" << fabs(x3.imag()) << "i" << std::endl
                  << "               " << x3.real() << "-" << fabs(x3.imag()) << "i" << std::endl;
    }

    std::cout << "Number of Iteration: " << itr << std::endl;      
};

//10.44x^2 + x^4 + 12.96
std::complex<double> f1(const std::complex<double>& x){
    return (10.44 * std::pow(x, 2)) + std::pow(x, 4) + 12.96;
};
//x^4 + 2x^3 -7x^2 -8x + 12
std::complex<double> f2(const std::complex<double>& x){
    return std::pow(x, 4) + (2.0 * std::pow(x, 3)) - (7.0 * std::pow(x, 2)) - (8.0 * x) + 12.0; 
};
//x^3 - 4.5x^2 + 0.86x + 9.24
std::complex<double> f3(const std::complex<double>& x){
    return std::pow(x, 3) - (4.5 * std::pow(x, 2)) + (0.86 * x) + 9.24;
}

int main(){
    std::cout << "----Muller Method----\n";

    // std::cout << "Choose function:"
    //           << "\n1. f(x) = 10.44x^2 + x^4 + 12.96"
    //           << "\n2. f(x) = x^4 + 2x^3 -7x^2 -8x + 12"
    //           << "\n3. f(x) = x^3 - 4.5x^2 + 0.86x + 9.24"
    //           << "\n-> ";
    // int choice;

    // std::cin >> choice;

    // switch (choice)
    // {
    // case 1:
    //     std::cout << "f(x) = 10.44x^2 + x^4 + 12.96\n";
    //     MullerMethod(f1);
    //     break;
    // case 2:
    //     std::cout << "f(x) = x^4 + 2x^3 -7x^2 -8x + 12\n";
    //     MullerMethod(f2);
    //     break;
    // case 3:
    //     std::cout << "f(x) = x^3 - 4.5x^2 + 0.86x + 9.24\n";
    //     MullerMethod(f3);
    //     break;
    // default:
    //     std::cout<< "byee!!!\n";
    //     break;
    // }
    
     std::cout << "f(x) = x^3 - 4.5x^2 + 0.86x + 9.24\n";
    MullerMethod(f3);
    
    return 0;
}