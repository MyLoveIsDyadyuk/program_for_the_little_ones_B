#include "matrix.h"

int main()
{
    Matrix a(2);
    a.random();


    cout << "\n" <<"^1" << "\n"<< a;
    for (int i = 2; i < 5; ++i) 
    {
        a ^= i;
        cout << "\n" <<"^" << i << "\n"<< a;
    }


    Matrix c(4);
    c.random();
    cout << "\n" << c;
}