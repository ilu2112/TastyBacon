#include <stdio.h>
#include <ncurses.h>

/*

5 x 6
+----+----+----+----+  0
|                      1
|                       2
|                       3
+----+----+----+----+   4
|                       5
|                       6
|                       7
+----+----+----+----+
*/

void printCell(int row, int col, int val) {
    move(row, col);
    printw("+----+");
    move(row+1, col);
    printw("|    |");
    move(row+2, col);
    printw("|    |");
    move(row+2, col);
    printw("| %2d |", val);
    move(row+3, col);
    printw("|    |");
    move(row+4, col);
    printw("+----+");
}


int main() {

    // init ncurses
    initscr();
    printf("INIT\n");
    int rows;
    int cols;
    int ** matrix;


    while (true) {

        // input
        FILE * storageFile = fopen("tmpFile", "r");
        if (storageFile != NULL) {
            scanf("%d %d", &rows, &cols);
            if (rows == 0 || cols == 0) {
                break;
            }
            matrix = new int*[rows];
            for (int iRow = 0; iRow < rows; iRow++) {
                matrix[iRow] = new int[cols];
                for (int iCol = 0; iCol < cols; iCol++) {
                    scanf("%d", &matrix[iRow][iCol]);
                }
            }
            fclose(storageFile);

            // output
            for (int iRow = 0; iRow < rows; iRow++) {
                for (int iCol = 0; iCol < cols; iCol++) {
                    printCell(iRow * 4, iCol * 5, matrix[iRow][iCol]);
                }
                delete [] matrix[iRow];
            }
            delete matrix;
            refresh();
        }
    }

    endwin();
    return 0;
}
