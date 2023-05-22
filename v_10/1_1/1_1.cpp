#include <iostream>
#include <fstream>

using namespace std;


int main() 
{
    ifstream fin;
    fin.open("1_1_input.txt");

    ofstream fout;
    fout.open("1_1_out.txt");
    
    //lt one
    double num;
    while (!fin.eof())
    {
        fin >> num;
        if (num < 1)
            fout << num << " ";
    }
    fin.close();
    fin.open("1_1_input.txt");

    fout << "\n";
    //gt one
    while (!fin.eof())
    {
        fin >> num;
        if (num >= 1)
            fout << num << " ";
    }
    fin.close();
    fout.close();
}



    // srand(time(NULL));
    // ofstream fout;
    // fout.open("1_1_input.txt");

    // for (int i = 0; i < 100; i++)
    //     fout << double(rand()) / 10000 << " ";
    // fout.close();

