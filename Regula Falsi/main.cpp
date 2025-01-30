#include<iomanip>

#include "RegulaFalsi.hpp"

double function1 (double x){
    return pow(x, 3) - (0.4 * pow(x, 2)) - (8.77 * x) + 8.8;
}

double testFunc1(double x){
    return pow(x, 3) - x - 2;
}

double testFunc2(double x){
    return cos(x) - x;
}

int main(){
    std::cout << std::setprecision(10);
    std::cout << std::fixed;
    
    RegulaFalsi solution1(testFunc2);
    solution1.SolveRoot();
    
    return 0;
}