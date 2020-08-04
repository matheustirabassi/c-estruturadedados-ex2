#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

class IOException
{
public:
    IOException(int n)
    {
        line = n;
    }
    string getMsg(string msg)
    {
        return "Error in line: " + std::to_string(line) + " " + msg;
    };
private:
    int line;
};



float **alocMatrixSuperior(int lines)
{
    if(lines <= 0)
    {
        throw (IOException(__LINE__));
    }
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

float getElementMatrixSuperior(float **matrix, int line, int column)
{
    return matrix[line][column];
}
void setElementMatrixSuperior(float **matrix, const int line, const int column, float value)
{
    matrix[line][column] = value;
}
int main()
{
    cout << "Enter the number of lines: ";
    int n;
    cin >> n;
    try
    {
        float **matrix = alocMatrixSuperior(n);
        printMatrixSuperior(matrix, n);
        scanMatrixSuperior(matrix, n);
        printMatrixSuperior(matrix, n);
        float a = getElementMatrixSuperior(matrix, 0,0);
        cout << "the valor of line 0 and column 0 is " + std::to_string(a) << endl;
        setElementMatrixSuperior(matrix,0, 0, 10);
        a = getElementMatrixSuperior(matrix, 0,0);
        cout << "the valor of line 0 and column 0 is " + std::to_string(a);
        freeMatrixSuperior(matrix, n);

    }
    catch(IOException e)
    {
        cout << e.getMsg("the numbers no can be less and equal that 0");
    }


    return 0;
}
