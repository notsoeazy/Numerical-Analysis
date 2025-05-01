#include <algorithm> // std::remove , std::swap
#include <cmath> // std::fabs
#include <iomanip> // std::iomanip
#include <iostream>
#include <string>
#include <sstream> // std::stringstream
#include <vector>

const double ACCURACY = 1e-9;

void printMatrix(const std::vector<std::vector<double>>& matrix);
double getDeterminant(const std::vector<std::vector<double>>& matrix);
int getRank(std::vector<std::vector<double>> matrix);
bool isRowZero(const std::vector<double>& row);
std::string getConsistency(std::vector<std::vector<double>> matrix);

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
        
        // Parse the input string and remove brackets if contains any
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
    // Check if matrix is empty
    if (matrix.empty() || matrix[0].empty()) {
        throw std::invalid_argument("Empty matrix");
    }
    // printMatrix(matrix);
    // Get the values
    int rank = getRank(matrix);
    std::string consistency = getConsistency(matrix);
    double determinant = getDeterminant(matrix);
    // Print the values
    std::cout << "\nResult: Rank of the Matrix = " << rank << "\n"
              << "\tSystem consistency = " << consistency << "\n"
              << "\tSystem Determinant = " << determinant << "\n"
              << std::endl;
    return 0;
}
// For debugging purposes
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

double getDeterminant(const std::vector<std::vector<double>>& matrix)
{
    int matrix_size = matrix.size(); 
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
        // Recursive call the getDeterminant() for the sub matrices
        double sub_matrix_determinant = getDeterminant(sub_matrix);
        // Sum the cofactor
        determinant += (source_row % 2 == 0 ? 1 : -1) * matrix[source_row][0] * sub_matrix_determinant;
    }
    return determinant;
}

bool isRowZero(const std::vector<double>& row)
{
    int col_size = row.size();
    for (int col = 0; col < col_size; col++)
    {
        if (std::fabs(row[col]) >= ACCURACY)
        {
            return false;
        }
    }
    return true;
}

int getRank(std::vector<std::vector<double>> matrix) 
{
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    int rank = row_size;

    // Convert matrix to row echelon form
    for (int pivot_row = 0; pivot_row < row_size; pivot_row++) 
    {
        // Find and establish pivot
        if (std::fabs(matrix[pivot_row][pivot_row]) < ACCURACY) 
        {
            bool found_nonzero_pivot = false;
            for (int candidate_row = pivot_row + 1; candidate_row < row_size; candidate_row++)
            {
                if (std::fabs(matrix[candidate_row][pivot_row]) >= ACCURACY)
                {
                    std::swap(matrix[pivot_row], matrix[candidate_row]);
                    found_nonzero_pivot = true;
                    break;
                }
            }
            if (!found_nonzero_pivot) continue;
        }
        // Eliminate entries below pivot
        for (int next_row = pivot_row + 1; next_row < row_size; next_row++)
        {
            if (std::fabs(matrix[pivot_row][pivot_row]) < ACCURACY)
                continue;
            double multiplier = matrix[next_row][pivot_row] / matrix[pivot_row][pivot_row];
            for (int col = 0; col < col_size; col++) 
            {
                matrix[next_row][col] -= multiplier * matrix[pivot_row][col];
            }
        }   
    }
    // Count non-zero rows to determine rank
    for (int row = 0; row < row_size; row++) 
    {
        if (isRowZero(matrix[row])) 
        {
            rank--;
        }
    }
    return rank;
}

std::string getConsistency(std::vector<std::vector<double>> matrix)
{
    int row_size = matrix.size();
    int coef_matrix_col_size = matrix[0].size() - 1;
    int n = row_size;
    std::vector<std::vector<double>> coefficient_matrix(row_size, std::vector<double>(coef_matrix_col_size));
    // Copy the coefficients from augmented matrix
    for (int row = 0; row < row_size; row++)
    {
        for (int col = 0; col < coef_matrix_col_size; col++)
        {
            coefficient_matrix[row][col] = matrix[row][col];
        }
    }
    int augmented_rank = getRank(matrix);
    int coefficient_rank = getRank(coefficient_matrix);
    // Check for consistency
    if ((augmented_rank == coefficient_rank) && (augmented_rank == n))
    {
        return "has unique solution";
    }
    else if ((augmented_rank == coefficient_rank) && (augmented_rank < n))
    {
        return "has infinite solution";
    }
    else
    {
        return "has no solution";
    }
}