#include<iostream>
#include<cmath>
#include<iomanip>
#include<complex>

void MullerMethod(std::complex<double> (*f)(const std::complex<double>&)){
    std::complex<double> x0, x1, x2, x3, fx0, fx1, fx2, fx3, h0, h1, d0, d1, a, b, c;
    
    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);

    //temporary
    x0 = 1;
    x1 = 2;
    x2 = 3;

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

    if (b.real() > 0){
        x3 = x2 + (-2.0 * c)/(b + (sqrt(std::pow(b, 2) - 4.0 * a * c))); 
    } else {
        x3 = x2 + (-2.0 * c)/(b - (sqrt(std::pow(b, 2) - 4.0 * a * c))); 
    }

    std::cout << "x0: " << x0 << "\n"
              << "x1: " << x1 << "\n"
              << "x2: " << x2 << "\n"
              << "fx0: " << fx0 << "\n"
              << "fx1: " << fx1 << "\n"
              << "fx2: " << fx2 << "\n"
              << "h0: " << h0 << "\n"
              << "h1: " << h1 << "\n"
              << "d0: " << d0 << "\n"
              << "d1: " << d1 << "\n"
              << "a: " << a << "\n"
              << "b: " << b << "\n"
              << "c: " << c << "\n"
              << "x3: " << x3 << "\n";
};

//x^3 - 2x^2 - 5
std::complex<double> f1(const std::complex<double>& x){
    return std::pow(x, 3) - (2.0 * std::pow(x, 2)) - 5.0;
};

int main(){
    //std::cout << "hi" << std::endl;
    MullerMethod(f1);
    return 0;
}