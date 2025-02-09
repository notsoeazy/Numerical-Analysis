#include<iostream>
#include<cmath>
#include<iomanip>

class RegulaFalsi{
public:
    RegulaFalsi();
    void SolveRoot(double (*f)(double));

private:
    void SetInterval(double (*f)(double));

    double lowerInterval, upperInterval;
    double Xa, Xb, Xr, XrPrev;
    double fXa, fXb, fXr;
    int itr;
    double accuracy;
};


double function1 (double x){
    return x - exp(-1 * pow(x, 2));
};

double function2 (double x){
    return pow(x, 4) + (2 * pow(x, 3)) - (7 * pow(x, 2)) - (8 * x) + 12;
};

int main(){
    std::cout << std::setprecision(10);
    std::cout << std::fixed;

    std::cout << "--- REGULA FALSI METHOD ---\n";

    std::cout << "Choose function:"
              << "\n1. f(x) = x - e^(-x^2)"
              << "\n2. f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12"
              << "\n-> ";

    RegulaFalsi solution;
    int choice = 0;
    std::cin >> choice;

    if(choice == 1){
        std::cout << "f(x) = x - e^(-x^2)" << std::endl;
        solution.SolveRoot(function1);
    }
    else if(choice == 2){
        std::cout << "f(x) = x^4 + 2x^3 - 7x^2 - 8x + 12" << std::endl;
        solution.SolveRoot(function2);
    }
    else {
        std::cout << "\nExiting Program...";
    }
    std::cout << "\n---------------------------------------------------------------------------\n";
};

//FUNCTION DEFINITION

RegulaFalsi::RegulaFalsi(){
    itr = 0;
    accuracy = 1e-10;
    Xa = NAN;
    Xb = NAN;
    Xr = NAN;
};

void RegulaFalsi::SetInterval(double (*f)(double)){
    while (true) {
        std::cout << "Enter initial guess...\n";
        std::cout << "Enter lower interval: ";
        std::cin >> lowerInterval;
        std::cout << "Enter upper interval: ";
        std::cin >> upperInterval;

        if(f(lowerInterval) * f(upperInterval) <= 0){
            Xa = lowerInterval;
            Xb = upperInterval;

            break;
        }
        else{
            std::cout << "Root does not fall into the interval, guess again...\n";
        }
    };
};

void RegulaFalsi::SolveRoot(double (*f)(double)){
    SetInterval(f);

    std::cout << "\n#itr" << "\t" << "Xa" << "\t\t\t" << "Xb" << "\t\t\t" << "fXa" << "\t\t\t" << "fXb" << "\t\t\t" << "Xr" << "\t\t\t" << "fXr" << std::endl;

    do{
        fXa = f(Xa);
        fXb = f(Xb);

        XrPrev = Xr;
        Xr = (Xb - ((fXb * (Xa - Xb)) / (fXa - fXb)));
        fXr = f(Xr);

        std::cout << ++itr << "\t" << Xa << "\t\t" << Xb << "\t\t" << fXa << "\t\t" << fXb << "\t\t" << Xr << "\t\t" << fXr << std::endl;

        // check if root
        if(fXr == 0){
            // std::cout << "Reached 0\n";
            break;
        }
        // check if intervals are roots
        if(fXa == 0){
            Xr = Xa;
            // std::cout << "fXa=0\n";
            break;
        }
        if(fXb == 0){
            Xr = Xb;
            // std::cout << "fXb=0\n";
            break;
        }

        //Swap intervals
        if(fXr * fXa < 0){
            Xb = Xr;
        }
        else if(fXr * fXa > 0){
            Xa = Xr;
        }

    }while((itr > 1) ? fabs(XrPrev - Xr) > accuracy : true);

    std::cout << "\nStarting interval: [" << lowerInterval << ", " << upperInterval << "]" << std::endl;
    std::cout << "Number of Iterations: " << itr << std::endl;
    std::cout << "The root is " << Xr << std::endl;
};
