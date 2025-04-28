#include <algorithm> // std::remove
#include <iomanip> // std::iomanip
#include <iostream>
#include <string>
#include <sstream> // std::stringstream

void printMatrix(double** matrix, int row, int column);

int main()
{
    // Get the size of the matrix
    int matrix_size;
    std::cout << "Enter number of equations: ";
    std::cin >> matrix_size;
    std::cin.ignore();

    // Create MATRIX[row][column] with an extra column for the constants 
    // Using pointer pointer
    double** MATRIX = new double* [matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        MATRIX[i] = new double[matrix_size + 1];
    }

    // Get the equations in this format [a b c d ... constant]
    for (int row = 0; row < matrix_size; row++)
    {
        std::cout << "Enter parameters of Eq." << row + 1 << ": ";
        std::string input;
        std::getline(std::cin, input);
        
        // Remove the brackets
        input.erase(std::remove(input.begin(), input.end(), '['), input.end());
        input.erase(std::remove(input.begin(), input.end(), ']'), input.end());

        std::stringstream ss(input);

        // Extract the numbers in the stringstream
        for (int column = 0; column <= matrix_size; column++)
        {
            // Parse space separated numbers (skips whitespaces)
            ss >> MATRIX[row][column];
        }
    }
    printMatrix(MATRIX, matrix_size, matrix_size);

    
    return 0;
}

void printMatrix(double** matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        std::cout << "|";
        for (int j = 0; j <= column; j++)
        {
            std::cout << std::setw(3) <<matrix[i][j] << " ";
        }
        std::cout << "|\n";
    }
}
