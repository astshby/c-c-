 #include <stdio.h>


void generateSnakeMatrix(int matrix[][100], int n) {
    int num = 1;
    int row = 0, col = 0;
    int direction = 0;

    while (num <= n * n) {
        matrix[row][col] = num;
        num++;


        if (direction == 1) {
            if (col + 1 < n && row - 1 >= 0 && matrix[row - 1][col + 1] == 0) {
                row--;
                col++;
            } else {
                if (col + 1 < n) {
                    col++;
                } else {
                    row++;
                }
                direction = 0;
            }
        } else {
            if (row + 1 < n && col - 1 >= 0 && matrix[row + 1][col - 1] == 0) {
                row++;
                col--;
            } else {
                if (row + 1 < n) {
                    row++;
                } else {
                    col++;
                }
                direction = 1;
            }
        }
    }
}

void printSnakeMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	if(j==n-1) printf("%d", matrix[i][j]);
            else printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int snakeMatrix[100][100] = {0};

    generateSnakeMatrix(snakeMatrix, n);
    printSnakeMatrix(snakeMatrix, n);

    return 0;
}
