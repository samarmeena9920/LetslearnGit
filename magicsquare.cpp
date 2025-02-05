#include <iostream>
#include <vector>

bool isMagicSquare(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int magicSum = n * (n * n + 1) / 2;

    // Check rows and columns
    for (int i = 0; i < n; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            return false;
        }
    }

    // Check main diagonal
    int mainDiagSum = 0;
    for (int i = 0; i < n; ++i) {
        mainDiagSum += matrix[i][i];
    }
    if (mainDiagSum != magicSum) {
        return false;
    }

    // Check anti-diagonal
    int antiDiagSum = 0;
    for (int i = 0; i < n; ++i) {
        antiDiagSum += matrix[i][n - i - 1];
    }
    if (antiDiagSum != magicSum) {
        return false;
    }

    return true;
}

int main() {
    // Example usage:
    std::vector<std::vector<int>> matrix = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    if (isMagicSquare(matrix)) {
        std::cout << "The given matrix is a Magic Square." << std::endl;
    } else {
        std::cout << "The given matrix is not a Magic Square." << std::endl;
    }

    return 0;
}
