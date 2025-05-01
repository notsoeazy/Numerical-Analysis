#include <algorithm> // std::remove
#include <iomanip> // std::iomanip
#include <iostream>
#include <string>
#include <sstream> // std::stringstream
#include <vector>

void printMatrix(const std::vector<std::vector<double>>& matrix);
double getDeterminant(const std::vector<std::vector<double>>& matrix, const int& matrix_size);

int main()
{
    // Get the size of the matrix
    int matrix_size;
    std::cout << "Enter number of equations: ";
    std::cin >> matrix_size;
    std::cin.ignore();

    // Create matrix vector with dimensions matrix_size X matrix_size + 1 for the constants
    std::vector<std::vector<double>> matrix(matrix_size, std::vector<double>(matrix_size + 1));

    // Get the equations in this format [a b c d ... constant]
    for (int row = 0; row < matrix_size; row++)
    {
        std::cout << "Enter parameters of Eq." << row + 1 << ": ";
        std::string input;
        std::getline(std::cin, input);
        
        // Parse the input string and remove brackets
        input.erase(std::remove(input.begin(), input.end(), '['), input.end());
        input.erase(std::remove(input.begin(), input.end(), ']'), input.end());

        std::stringstream ss(input);

        // Extract the numbers in the stringstream
        std::vector<double> row_data;
        double value;
        for (int column = 0; column <= matrix_size; column++)
        {
            // Parse space separated numbers (skips whitespaces)
            if (ss >> value)
            {
                row_data.push_back(value);
            } else {
                row_data.push_back(0.0);
            }
        }
        matrix[row] = row_data;
    }
    printMatrix(matrix);

    double determinant = getDeterminant(matrix, matrix_size);

    std::cout << "\nResult:\t Rank of the Matrix = " 
              << "\tSystem consistency = "
              << "\tSystem Determinant = " << determinant << "\n"
              << std::endl;
    return 0;
}

void printMatrix(const std::vector<std::vector<double>>& matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    
    for (int i = 0; i < row; i++)
    {
        std::cout << "|";
        for (int j = 0; j < column; j++)
        {
            std::cout << std::setw(3) <<matrix[i][j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

double getDeterminant(const std::vector<std::vector<double>>& matrix, const int& matrix_size)
{
    if (matrix_size == 1)
    {
        return matrix[0][0];
    }
    if (matrix_size == 2)
    {
        return (matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]));
    }

    double determinant = 0.0;
    // Cofactor expansion on 1st column
    for (int source_row = 0; source_row < matrix_size; source_row++)
    {
        // Create submatrix for cofactor expansion
        std::vector<std::vector<double>> sub_matrix(matrix_size - 1, std::vector<double>(matrix_size - 1));
        // Extract submatrix from original matrix
        int sub_row = 0;
        for (int current_row = 0; current_row < matrix_size; current_row++)
        {
            if (current_row == source_row) // Skip the current row
                continue;
            int sub_col = 0;
            for (int current_col = 0; current_col < matrix_size; current_col++)
            {
                if (current_col == 0) // Skip 1st column
                    continue;
                sub_matrix[sub_row][sub_col] = matrix[current_row][current_col];
                sub_col++;
            }
            sub_row++;
        }
        printMatrix(sub_matrix);
        // Recursive call the getDeterminant() for the sub matrices
        double sub_matrix_determinant = getDeterminant(sub_matrix, matrix_size - 1);
        // Sum the cofactor
        determinant += (source_row % 2 ? 1 : -1) * matrix[source_row][0] * sub_matrix_determinant;
    }
    return determinant;
}