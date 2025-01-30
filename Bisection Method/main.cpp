#include<iostream>
#include<cmath>
#include<iomanip>

class BisectionMethod
{
public:
    BisectionMethod(double (*func)(double)){
        numOfItr = 0;
        accuracy = 0.0000000001;
        f = func;
    };
    void SetInterval(){
        while(true){
            std::cout << "Enter guess interval:\n";
            std::cout << "Lower interval: ";
            std::cin >> Xa;
            std::cout << "Upper interval: ";
            std::cin >> Xb;
            if ((f(Xa) * f(Xb)) <= 0){
                origLowInterval = Xa;
                origUpInterval = Xb;
                break;
            }
            else{
                std::cout << "No roots in the interval, enter another interval...\n";
            }
        }
    };
    void Bisection(){
        SetInterval();

        std::cout << "#itr" << "\t" << "Xa" << "\t\t\t" << "f(Xa)" << "\t\t\t" << "Xb" << "\t\t\t" << "f(Xb)" << "\t\t\t" << "Xc" << "\t\t\t" << "f(Xc)" << std::endl;

        while(fabs(Xa - Xb) > accuracy){
            numOfItr++;

            Xc = (Xa + Xb)/2;
            fXa = f(Xa);
            fXb = f(Xb);
            fXc = f(Xc);

            std::cout << numOfItr << "\t" << Xa << "\t\t" << fXa << "\t\t" << Xb << "\t\t" << fXb << "\t\t" << Xc << "\t\t" << fXc << std::endl;

            //check if mayroon zero, matic root siya
            if(fXa == 0){
                Xc = Xa;
                break;
            }
            if(fXb == 0){
                Xc = Xb;
                break;
            }
            if(fXc == 0){
                break;
            }

            //swap intervals
            if(fXa * fXc < 0){
                Xb = Xc;
            }
            else{
                Xa = Xc;
            }
        }
        std::cout << "---------------------------------------------------------------------------\n";
        std::cout << "Starting Interval: [" << origLowInterval << ", " << origUpInterval << "]" << std::endl;
        std::cout << "Ending Interval: [" << Xa << ", " << Xb << "]" << std::endl;
        std::cout << "Number of Iterations: " << numOfItr << std::endl;
        std::cout << "Root is " << Xc << std::endl;
    }
private:
    int numOfItr;
    double Xa, Xb, Xc, fXa, fXb, fXc;
    double accuracy;
    double origLowInterval;
    double origUpInterval;
    double (*f)(double);
};

double function1(double x){
    return x - exp(-1 * pow(x, 2));
}
double function2(double x){
    return pow(x, 4) + (2 * pow(x, 3)) - (7 * pow(x, 2)) - (8 * x) + 12;
}
double function3(double x){
    return pow(x, 3) - (0.4 * pow(x, 2)) -(8.77 * x) + 8.8;
}

int main(){
    std::cout << std::setprecision(10) << std::fixed;

    std::cout << "Choose function:"
              << "\n1. f(x) = x - e^(-x^2)"
              << "\n2. f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12"
              << "\n3. f(x) = x^3 - 0.4x^2 - 8.77x + 8.8"
              << "\n-> ";
    int choice;
    std::cin >> choice;

    if(choice == 1){
        std::cout << "f(x) = x - e^(-x^2)" << std::endl;
        BisectionMethod solution1(function1);
        solution1.Bisection();
    } else if(choice == 2){
        std::cout << "f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12" << std::endl;
        BisectionMethod solution2(function2);
        solution2.Bisection();
    } else if(choice == 3){
        std::cout << "f(x) = x^3 - 0.4x^2 - 8.77x + 8.8" << std::endl;
        BisectionMethod solution3(function3);
        solution3.Bisection();
    } else {
        std::cout << "\nExiting Program...";
    }
    std::cout << "\n---------------------------------------------------------------------------\n";

    return 0;
}
