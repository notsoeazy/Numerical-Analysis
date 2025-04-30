#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double ACCURACY = 1e-10;
    const int PRECISION = 10;
    std::cout.precision(PRECISION);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::right);

    int itr = 0;

    // Define the arranged matrix
    double matrix[5][6]=
    {
        {8, -2, -1, 0, 0, 5},
        {-2, 9, -4, -1, 0, 2},
        {-1, -3, 7, -1, -2, 1},
        {0, -4, 2, 12, -5, 1},
        {0, 0, -7, -3, 15, 5}
    };
    // Set the variables
    double x1, x2, x3, x4, x5;
    double tmp[5];
    x1 = 0;
    x2 = 0;
    x3 = 0;
    x4 = 0;
    x5 = 0;
    // Print header
    std::cout << std::setw(4) << "itr"
              << std::setw(15) << "x1"
              << std::setw(15) << "x2"
              << std::setw(15) << "x3"
              << std::setw(15) << "x4"
              << std::setw(15) << "x5;

    // Solve for the values
    do
    {
        tmp[0] = ((matrix[0][5]) - (matrix[0][1] * x2) - (matrix[0][2] * x3) - (matrix[0][3] * x4) - (matrix[0][4] * x5)) / matrix[0][0];
        tmp[1] = ((matrix[1][5]) - (matrix[1][0] * x1) - (matrix[1][2] * x3) - (matrix[1][3] * x4) - (matrix[1][4] * x5)) / matrix[1][1];
        tmp[2] = ((matrix[2][5]) - (matrix[2][0] * x1) - (matrix[2][1] * x2) - (matrix[2][3] * x4) - (matrix[2][4] * x5)) / matrix[2][2];
        tmp[3] = ((matrix[3][5]) - (matrix[3][0] * x1) - (matrix[3][1] * x2) - (matrix[3][2] * x3) - (matrix[3][4] * x5)) / matrix[3][3];
        tmp[4] = ((matrix[4][5]) - (matrix[4][0] * x1) - (matrix[4][1] * x2) - (matrix[4][2] * x3) - (matrix[4][3] * x4)) / matrix[4][4];

        x1 = tmp[0];
        x2 = tmp[1];
        x3 = tmp[2];
        x4 = tmp[3];
        x5 = tmp[4];

        std::cout << std::setw(4) << ++itr
                  << std::setw(15) << x1
                  << std::setw(15) << x2
                  << std::setw(15) << x3
                  << std::setw(15) << x4
                  << std::setw(15) << x5;
    } while ()
    return 0;
}
