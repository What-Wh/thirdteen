#include <iostream>

using namespace std;

//int** addColumn(int** a, int r, int c, int cg[], int p) {
//    int** a2 = new int* [r];
//    for (int i = 0; i < r; i++) {
//        a2[i] = new int[c + 1];
//        for (int j = 0; j < p; j++) {
//            a2[i][j] = a[i][j];
//        }
//        a2[i][p] = cg[i];
//        for (int j = p; j < c; j++) {
//            a2[i][j+1] = a[i][j];
//        }
//    }
//    for (int i = 0; i < r; i++) {
//        delete[] a[i];
//    }
//    delete[] a;
//
//    return a2;
//}

//int** delColumn(int** a, int r, int c,int p) {
//    int** a2 = new int* [r];
//    for (int i = 0; i < r; i++) {
//        a2[i] = new int[c - 1];
//        for (int j = 0; j < p; j++) {
//            a2[i][j] = a[i][j];
//        }
//        for (int j = p + 1; j < c; j++) {
//            a2[i][j - 1] = a[i][j];
//        }
//    }
//    for (int i = 0; i < r; i++) {
//        delete[] a[i];
//    }
//    delete[] a;
//
//    return a2;
//}

void fillMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void shiftRows(int** matrix, int M, int N, int shifts, bool toRight) {
    shifts = shifts % N;
    if (shifts == 0) return;

    int* temp = new int[N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int newJ = toRight ? (j + shifts) % N : (j - shifts + N) % N;
            temp[newJ] = matrix[i][j];
        }

        for (int j = 0; j < N; j++) {
            matrix[i][j] = temp[j];
        }
    }

    delete[] temp;
}

void shiftColumns(int** matrix, int M, int N, int shifts, bool toDown) {
    shifts = shifts % M;
    if (shifts == 0) return;

    int* temp = new int[M]; 

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            int newI = toDown ? (i + shifts) % M : (i - shifts + M) % M;
            temp[newI] = matrix[i][j];
        }

        for (int i = 0; i < M; i++) {
            matrix[i][j] = temp[i];
        }
    }

    delete[] temp;
}

int main()
{
    //1 task
    /*int r = 3, c = 3;
    int** a = new int* [r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        for (int j = 0; j < c; j++) {
            a[i][j] = rand()%10;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int cg[] = { 10, 20, 30 };
    int p = 1;
    a = addColumn(a, r, c, cg, p);
    c++;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; i++) {
        delete[] a[i];
    }
    delete[] a;*/

    //2 task
    /*int r = 3, c = 3;
    int** a = new int* [r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        for (int j = 0; j < c; j++) {
            a[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int p = 1;
    a = delColumn(a, r, c, p);
    c--;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; i++) {
        delete[] a[i];
    }
    delete[] a;*/

    //3 task
    int M = 4, N = 5;

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }

    fillMatrix(matrix, M, N);

    printMatrix(matrix, M, N);

    int rowShifts = 1;
    int colShifts = 2;
    bool shiftRight = true;
    bool shiftDown = false;

    shiftRows(matrix, M, N, rowShifts, shiftRight);
    printMatrix(matrix, M, N);

    shiftColumns(matrix, M, N, colShifts, shiftDown);
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}