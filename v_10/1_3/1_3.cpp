#include <time.h> // for time()
#include <fstream>
#include <iostream>
#define column 5
using namespace std;

// create new
void create(ofstream &outfile, int n)
{
    string last_name;
    string birthday;
    int course = 0;
    float subj = 0;
    char sex;
    ifstream fin("students.txt");
    for (int i = 0; i < n * column; i++)
    {
        fin.eof();
        fin >> last_name;

        fin.eof();
        fin >> birthday;

        fin.eof();
        fin >> course;

        fin.eof();
        fin >> subj;

        fin.eof();
        fin >> sex;

        outfile.write(reinterpret_cast<char *>(&last_name), sizeof(string));
        outfile.write(reinterpret_cast<char *>(&birthday), sizeof(string));
        outfile.write(reinterpret_cast<char *>(&course), sizeof(int));
        outfile.write(reinterpret_cast<char *>(&subj), sizeof(float));
        outfile.write(reinterpret_cast<char *>(&sex), sizeof(char));
    }
    cout << "\n";
    fin.close();
}

void find_zadrot(ofstream &fout, ifstream &fin, int n, float gpa, int &counter)
{
    string last_name;
    string birthday;
    int course = 0;
    float subj = 0;
    char sex;
    for (int i = 0; i < n; i++)
    {
        fin.read(reinterpret_cast<char *>(&last_name), sizeof(string));
        fin.read(reinterpret_cast<char *>(&birthday), sizeof(string));
        fin.read(reinterpret_cast<char *>(&course), sizeof(int));
        fin.read(reinterpret_cast<char *>(&subj), sizeof(float));
        fin.read(reinterpret_cast<char *>(&sex), sizeof(char));

        if (subj >= gpa)
        {
            fout.write(reinterpret_cast<char *>(&last_name), sizeof(string));
            fout.write(reinterpret_cast<char *>(&birthday), sizeof(string));
            fout.write(reinterpret_cast<char *>(&course), sizeof(int));
            fout.write(reinterpret_cast<char *>(&subj), sizeof(float));
            fout.write(reinterpret_cast<char *>(&sex), sizeof(char));
            counter++;
        }
    }
}

void read(ifstream &fin, int counter)
{
    string last_name;
    string birthday;
    int course = 0;
    float subj = 0;
    char sex;
    for (int i = 0; i < counter; i++)
    {
        fin.read(reinterpret_cast<char *>(&last_name), sizeof(string));
        fin.read(reinterpret_cast<char *>(&birthday), sizeof(string));
        fin.read(reinterpret_cast<char *>(&course), sizeof(int));
        fin.read(reinterpret_cast<char *>(&subj), sizeof(float));
        fin.read(reinterpret_cast<char *>(&sex), sizeof(char));

        cout << last_name  << "\t\t"
        << birthday  << "\t"
        << course << "\t"
        << subj  << "\t"
        << sex << '\n';
    }
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "enter n (max = 14);\nn = ";
    cin >> n;

    ofstream outfile("1_3_inp.bin", ios::binary);
    create(outfile, n);

    outfile.close();

    ofstream fout("1_3_out.bin", ios::binary);
    ifstream fin("1_3_inp.bin", ios::binary);

    float gpa;
    cout << "Enter GPA = ";
    cin >> gpa;

    int counter = 0;
    find_zadrot(fout, fin, n, gpa, counter);

    fout.close();
    fin.close();

    ifstream infile("1_3_out.bin", ios::binary);
    read(infile, counter);

    return 0;
}