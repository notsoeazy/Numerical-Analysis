#include "RegulaFalsi.hpp"

RegulaFalsi::RegulaFalsi(double (*funcPtr)(double)){
    f = funcPtr;
    itr = 0;
    accuracy = 1e-10;
    Xr = NAN;
};

void RegulaFalsi::SetInterval(){
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

void RegulaFalsi::SolveRoot(){
    SetInterval();

    std::cout << "#itr" << "\t" << "Xa" << "\t\t\t" << "Xb" << "\t\t\t" << "fXa" << "\t\t\t" << "fXb" << "\t\t\t" << "Xc" << "\t\t\t" << "fXc" << std::endl;

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
        //check if met desired accuracy
        else if(itr > 1 && fabs(XrPrev - Xr) < accuracy){
            // std::cout << "MetAccuracy\n";
            break;
        }

        if(fXr * fXa < 0){
            Xb = Xr;
        }
        else if(fXr * fXa > 0){
            Xa = Xr;
        }

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
    }while(fabs(fXr) > accuracy);


    std::cout << "\nStarting interval: [" << lowerInterval << ", " << upperInterval << "]" << std::endl;
    std::cout << "Number of Iterations: " << itr << std::endl;
    std::cout << "The root is " << Xr << std::endl;
};