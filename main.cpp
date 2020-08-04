#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;


float **alocMatrixSuperior(int lines)
{
    float **p = (float **) malloc(sizeof(float *) * lines);
    for(int i = 0; i < lines; i++)
    {
        p[i] = (float *) malloc(sizeof(float*) *(i + 1) );
    }
    return p;
}


void freeMatrixSuperior(float **matrix, int lines)
{
    for(int i = 0; i < lines; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

}
void printMatrixSuperior(float **matrix, int lines)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void scanMatrixSuperior(float **matrix, int lines)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            cout << "Matrix [" << i <<"][" <<j <<"] = ";
            cin >> matrix[i][j];
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    int n = 3;
    float **matrix = alocMatrixSuperior(n);
    scanMatrixSuperior(matrix, n);
    printMatrixSuperior(matrix, n);
    freeMatrixSuperior(matrix, n);
    return 0;
}
