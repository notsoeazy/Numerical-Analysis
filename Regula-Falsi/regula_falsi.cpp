#include<iostream>
#include<cmath>
#include<iomanip>

void RegulaFalsi(double (*f)(const double& )) {
    double a, b, c, fa, fb, fc, cprev;
    int itr = 0;
    const double accuracy = 1e-10;

    std::cout.precision(10);
    std::cout.setf(std::ios::fixed);
    
    do {
        std::cout << "Enter lower interval: ";
        std::cin >> a;
        std::cout << "Enter upper interval: ";
        std::cin >> b;
    } while(
        [](const double& n1, const double& n2) -> bool {
            if(n1 * n2 > 0) {
                std::cout << "No roots found in interval. Try again...\n";
                return true;
            } else {return false;};
        }(f(a), f(b))
    );
    
    std::cout << std::setw(5) << "itr"
    << std::setw(20) << "lower"
    << std::setw(20) << "upper"
    << std::setw(20) << "f(l)"
    << std::setw(20) << "f(u)"
    << std::setw(20) << "x"
    << std::setw(20) << "fx\n";
    
    do {
        fa = f(a);
        fb = f(b);
        cprev = c;
        c = b - ((fb * (a - b)) / (fa - fb));
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
        } else if(fc == 0) {break;}
        (fa * fc) < 0 ? b = c : a = c;
    // } while(fabs(fc) > accuracy);
    } while((itr > 1) ? fabs(cprev - c) > accuracy : true);
    std::cout << "The root is " << c << "\nFound after " << itr << " iterations.\n";
}

double f1(const double& x) {
    return x - exp(-1 * pow(x, 2));
};

double f2(const double& x) {
    return pow(x, 4) + (2 * pow(x, 3)) - (7 * pow(x, 2)) - (8 * x) + 12;
};

int main() {
    std::cout << "---- R E G U L A - F A L S I  M E T H O D ----\n"
              << "Choose function:\n"
              << "\t1. f(x) = x - e^(-x^2)\n"
              << "\t2. f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12\n"
              << "-> ";
    int c = 0;
    std::cin >> c;
    switch(c)
    {
        case 1:
            std::cout << "\n1. f(x) = x - e^(-x^2)\n";
            RegulaFalsi(f1);
            break;
        case 2:
            std::cout << "\n2. f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12\n";
            RegulaFalsi(f2);
            break;
        default:
            break;
    }
    std::cout << "Bye!\n";
    return 0;
}