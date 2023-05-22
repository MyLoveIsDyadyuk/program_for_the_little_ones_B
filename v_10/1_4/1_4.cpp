#include <time.h> // for time()
#include <fstream>
#include <iostream>
using namespace std;

// create new

void read(ifstream &infile)
{
    while (!infile.eof())
    {
        string val;
        getline(infile, val, '\n');
        cout << val << "\n";
    }
}


void find_zadrot(ifstream &fin, ofstream &fout, int n, float gpa)
{ 
    string last_name;
    string birthday;
    int course = 0;
    double subj = 0;
    char sex;
    for (int i = 0; i < n; i++)
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

        if (subj >= gpa)
        { 
            fout << last_name << " " << birthday << " " << course << " " << subj << " " << sex << "\n";
        }
    }
    
}



int main()
{
    int n;
    cout << "enter n (max = 14);\nn = ";
    cin >> n;

    ifstream infile("students.txt");
    int val;
    infile.read(&val, sizeof(val));
    ofstream fout; 
    fout.open("zadrot.txt");

    float gpa;
    cout << "Enter GPA = ";
    cin >> gpa;
    find_zadrot(infile, fout, n, gpa);

    fout.close();
    infile.close();

    return 0;
}