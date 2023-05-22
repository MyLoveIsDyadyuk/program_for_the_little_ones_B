#include <time.h> // for time()
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void create(ofstream &outfile, int n)
{
    for (int i = 1; i <= n; i++)
    {
        double val = rand() / 10000.0;
        outfile.write(reinterpret_cast<char *>(&val), sizeof(double));
    }
}
    
void lt_one(ifstream &infile)
{
    double v;
    infile.read(reinterpret_cast<char *>(&v), sizeof(double));
    while (!infile.eof())
    {
        if (v < 1)
            cout << v << "\t";
        infile.read(reinterpret_cast<char *>(&v), sizeof(double));
    }
}

void ge_one(ifstream &infile)
{
    double v;
    infile.read(reinterpret_cast<char *>(&v), sizeof(double));
    while (!infile.eof())
    {
        if (v >= 1)
            cout << v << "\t";
        infile.read(reinterpret_cast<char *>(&v), sizeof(double));
    }
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "enter n;\nn = ";
    cin >> n;
    
    ofstream outfile("file.bin", ios::binary);
    create(outfile, n);
    outfile.close();

    ifstream infile("file.bin", ios::binary);

    cout << "number < 1:\n";
    lt_one(infile);
    infile.close();

    cout << "\n\nnumber >= 1:\n ";

    infile.open("file.bin", ios::binary);
    ge_one(infile);
    infile.close();

    return 0;
}