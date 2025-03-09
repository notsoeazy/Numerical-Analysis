#include<iostream>
#include<cmath>
#include<iomanip>


void BisectionMethod(double (*f)(const double& )){
    double a, b, c, fa, fb, fc;
    int itr = 0;
    const double accuracy = 1e-10;

    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);

    do{
        std::cout << "Enter lower interval: ";
        std::cin >> a;
        std::cout << "Enter upper interval: ";
        std::cin >> b;
    }while(
        [](const double& n1, const double& n2) -> bool{
            if(n1 * n2 > 0){
                std::cout << "No roots between. Try again...\n";
                return true;
            } else {return false;}
        }(f(a), f(b))
    );

    std::cout << std::setw(5) << "itr"
              << std::setw(20) << "lower"
              << std::setw(20) << "upper"
              << std::setw(20) << "f(l)"
              << std::setw(20) << "f(u)"
              << std::setw(20) << "x"
              << std::setw(20) << "f(x)\n";

    do{
        fa = f(a);
        fb = f(b);
        c = (a + b) / 2;
        fc = f(c);
        std::cout << std::setw(5) << ++itr
        << std::setw(20) << a
        << std::setw(20) << b
        << std::setw(20) << fa
        << std::setw(20) << fb
        << std::setw(20) << c
        << std::setw(20) << fc << "\n";
        if(fa == 0) {
            c = a;
            break;
        } else if(fb == 0) {
            c = b;
            break;
        }
        (fa * fc) < 0 ? b = c : a = c;
    } while(fabs(fc) > accuracy);
    std::cout << "\nThe root is " << c << "\nFound after " << itr << " iterations.\n";
}

double f1(const double& x){
    return x - exp(-1 * pow(x, 2));
};
double f2(const double& x){
    return pow(x, 4) + (2 * pow(x, 3)) - (7 * pow(x, 2)) - (8 * x) + 12;
};
double f3(const double& x){
    return pow(x, 3) - (0.4 * pow(x, 2)) -(8.77 * x) + 8.8;
};

int main(){
    std::cout << "---- B I S E C T I O N   M E T H O D ----\n"
              << "Choose function:\n"
              << "\t1. f(x)=x - e^(-x2)\n"    
              << "\t2. f(x)=x^4 + 2x^3 - 7x^2 -8x - 12\n"    
              << "\t3. f(x)=x^3 - 0.4x^2 - 8.77x + 8.8\n"
              << "-> ";
    int c = 0;
    std::cin >> c;
    switch(c)
    {
        case 1:
            std::cout << "\nf(x)=x - e^(-x2)\n";        
            BisectionMethod(f1);
            break;
        case 2:
            std::cout << "\nf(x)=x^4 + 2x^3 - 7x^2 -8x - 12\n";        
            BisectionMethod(f2);
            break;
        case 3:
            std::cout << "\nf(x)=x^3 - 0.4x^2 - 8.77x + 8.8\n";        
            BisectionMethod(f3);
            break;
        default:
            break;
    }
    std::cout << "Bye!\n";
    return 0;
}