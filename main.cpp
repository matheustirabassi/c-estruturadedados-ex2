#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;


float **alocMatrixSuperior(int lines)
{
    float **p = (float **) malloc(sizeof(float *) * lines);
    for(int i = lines; i >= 0; i--)
    {
        p[i] = (float *) malloc(sizeof(float*) * (i + 1) );
    }
    int aux = lines;
    for(int i = 0; i < lines; i++)
    {
        for(int j = aux - 1 ; j >= 0; j--)
        {
            p[i][j] = 0;
        }
        aux--;
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
   int aux = lines;
    for(int i = 0; i < lines; i++)
    {
        for(int j = aux - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
        aux --;
        cout << endl;
    }
}
void scanMatrixSuperior(float **matrix, int lines)
{
    int aux = lines;
    for(int i = 0; i < lines; i++)
    {
        for(int j = aux - 1; j >= 0; j--)
        {
            cout << "Matrix [" << i <<"][" <<j <<"] = ";
            cin >> matrix[i][j];
        }
         aux --;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    int n = 5;
    float **matrix = alocMatrixSuperior(n);
    printMatrixSuperior(matrix, n);
    scanMatrixSuperior(matrix, n);
    printMatrixSuperior(matrix, n);
    freeMatrixSuperior(matrix, n);
    return 0;
}
