#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    const double ACCURACY = 1e-11;
    const int PRECISION = 10;
    std::cout.precision(PRECISION);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::right);

    // Declare the  matrix
    const int ROW = 5;
    const int COLUMN = 6;
    // --------- COMMENT PROBLEM 1 MATRIX--------
    // Problem 1
    // double matrix[ROW][COLUMN] =
    // {
        //     {8, -2, -1, 0, 0, 5},
        //     {-2, 9, -4, -1, 0, 2},
        //     {-1, -3, 7, -1, -2, 1},
        //     {0, -4, 2, 12, -5, 1},
        //     {0, 0, -7, -3, 15, 5}
        // };
    // --------- COMMENT PROBLEM 2 MATRIX--------
    // Problem 2
    double matrix[ROW][COLUMN] =
    {
        {-9, 2, 2, 0, 0, -4},
        {2, -10, 4, 1, 1, -6},
        {2, 4, -9, 0, 0, 6},
        {0, 1, 0, -8, 3, 0},
        {0, 1, 0, 3, -4, 6}
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
              << std::setw(15) << "x5"
              << std::endl;
    // Start the iteration
    int itr = 0;
    bool foundRoot = false;
    do
    {
        tmp[0] = ((matrix[0][5]) - (matrix[0][1] * x2) - (matrix[0][2] * x3) - (matrix[0][3] * x4) - (matrix[0][4] * x5)) / matrix[0][0];
        tmp[1] = ((matrix[1][5]) - (matrix[1][0] * x1) - (matrix[1][2] * x3) - (matrix[1][3] * x4) - (matrix[1][4] * x5)) / matrix[1][1];
        tmp[2] = ((matrix[2][5]) - (matrix[2][0] * x1) - (matrix[2][1] * x2) - (matrix[2][3] * x4) - (matrix[2][4] * x5)) / matrix[2][2];
        tmp[3] = ((matrix[3][5]) - (matrix[3][0] * x1) - (matrix[3][1] * x2) - (matrix[3][2] * x3) - (matrix[3][4] * x5)) / matrix[3][3];
        tmp[4] = ((matrix[4][5]) - (matrix[4][0] * x1) - (matrix[4][1] * x2) - (matrix[4][2] * x3) - (matrix[4][3] * x4)) / matrix[4][4];
        // Print the values
        std::cout << std::setw(4) << ++itr
                  << std::setw(15) << tmp[0]
                  << std::setw(15) << tmp[1]
                  << std::setw(15) << tmp[2]
                  << std::setw(15) << tmp[3]
                  << std::setw(15) << tmp[4]
                  << std::endl;
        // Check if there are no changes, then root found
        if ((fabs(tmp[0] - x1) < ACCURACY) &&
            (fabs(tmp[1] - x2) < ACCURACY) &&
            (fabs(tmp[2] - x3) < ACCURACY) &&
            (fabs(tmp[3] - x4) < ACCURACY) &&
            (fabs(tmp[4] - x5) < ACCURACY))
        {
            foundRoot = true;
        }    
        // Store the values in x1, x2, ...
        x1 = tmp[0];
        x2 = tmp[1];
        x3 = tmp[2];
        x4 = tmp[3];
        x5 = tmp[4];
    } while (!foundRoot);

    std::cout << "The values are the following: " << std::endl
              << "x1 = " << x1 << std::endl
              << "x2 = " << x2 << std::endl
              << "x3 = " << x3 << std::endl
              << "x4 = " << x4 << std::endl
              << "x5 = " << x5 << std::endl;
    return 0;
}