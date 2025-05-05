#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double ACCURACY = 1e-11;
    const int PRECISION = 10;
    std::cout.precision(PRECISION);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::right);
    int ROW = 5;
    int COLUMN = 6;
    double matrix[ROW][COLUMN] =
    {
        {8, -2, -1, 0, 0, 5},
        {-2, 9, -4, -1, 0, 2},
        {-1, -3, 7, -1, -2, 1},
        {0, -4, -2, 12, -5, 1},
        {0, 0, -7, -3, 15, 5}
    };
    // Print header
    std::cout << std::setw(4) << "itr"
              << std::setw(15) << "x1"
              << std::setw(15) << "x2"
              << std::setw(15) << "x3"
              << std::setw(15) << "x4"
              << std::setw(15) << "x5"
              << std::endl;
    int itr = 0;
    bool foundRoot = false;
    double x[ROW];
    double prevValue[ROW];
    // Initial guess
    for (int i = 0; i < ROW; i++)
    {
        x[i] = 0;
    }
    // Solve for the values
    do
    {
        // Store the previous values
        for (int i = 0; i < ROW; i++)
        {
            prevValue[i] = x[i];
        }
        x[0] = ((matrix[0][5]) - (matrix[0][1] * x[1]) - (matrix[0][2] * x[2]) - (matrix[0][3] * x[3]) - (matrix[0][4] * x[4])) / matrix[0][0];
        x[1] = ((matrix[1][5]) - (matrix[1][0] * x[0]) - (matrix[1][2] * x[2]) - (matrix[1][3] * x[3]) - (matrix[1][4] * x[4])) / matrix[1][1];
        x[2] = ((matrix[2][5]) - (matrix[2][0] * x[0]) - (matrix[2][1] * x[1]) - (matrix[2][3] * x[3]) - (matrix[2][4] * x[4])) / matrix[2][2];
        x[3] = ((matrix[3][5]) - (matrix[3][0] * x[0]) - (matrix[3][1] * x[1]) - (matrix[3][2] * x[2]) - (matrix[3][4] * x[4])) / matrix[3][3];
        x[4] = ((matrix[4][5]) - (matrix[4][0] * x[0]) - (matrix[4][1] * x[1]) - (matrix[4][2] * x[2]) - (matrix[4][3] * x[3])) / matrix[4][4];
        std::cout << std::setw(4) << ++itr
                  << std::setw(15) << x[0]
                  << std::setw(15) << x[1]
                  << std::setw(15) << x[2]
                  << std::setw(15) << x[3]
                  << std::setw(15) << x[4]
                  << std::endl;
        if ((fabs(x[0] - prevValue[0]) < ACCURACY) &&
            (fabs(x[1] - prevValue[1]) < ACCURACY) &&
            (fabs(x[2] - prevValue[2]) < ACCURACY) &&
            (fabs(x[3] - prevValue[3]) < ACCURACY) &&
            (fabs(x[4] - prevValue[4]) < ACCURACY))
        {
            foundRoot = true;
        }
    } while (!foundRoot);
    std::cout << "\nSolution: \n"
              << "x1 = " << x[0] << std::endl
              << "x2 = " << x[1] << std::endl
              << "x3 = " << x[2] << std::endl
              << "x4 = " << x[3] << std::endl
              << "x5 = " << x[4] << std::endl
              << std::endl;
    return 0;
}
