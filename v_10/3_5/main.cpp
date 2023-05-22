#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string filename = "program.cpp";
    ifstream input(filename);
    ofstream output("function_names.txt");

    vector<string> function_names;
    string line;
    int line_number = 0;

    while (getline(input, line))
    {
        line_number++;
        if (line.find("int ") == 0 || line.find("void ") == 0 || line.find("bool ") == 0)
        {
            size_t start_pos = line.find(" ");
            size_t end_pos = line.find("(");
            if (start_pos != string::npos && end_pos != string::npos)
            {
                string function_name = line.substr(start_pos + 1, end_pos - start_pos - 1);
                function_names.push_back(function_name + " at line " + to_string(line_number));
            }
        }
    }

    sort(function_names.begin(), function_names.end());

    for (auto function_name : function_names)
    {
        output << function_name << "\n";
    }

    input.close();
    output.close();
}
