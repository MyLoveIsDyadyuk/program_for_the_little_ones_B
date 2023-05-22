#include <iostream>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;


void print(list<string> &L)
{
    for (auto i : L) cout << i;
    cout << "\n";
}

list<string> replace(list<string> &L, list<string> &L1, list<string> &L2, int size)
{
    list<string> res;
    string l1_begin = *L1.begin();
    if (L1.size() == 0)
    {
        cout << "replacement is not possible\n";
        return res;
    }
    for (list<string>::iterator i = L.begin(); i != L.end(); ++i)
    {
        if (*i == l1_begin)
        {
            bool intersec = 1;
            list<string>::iterator it = i;            
            for (auto j: L1)
            {
                if (j != *it) intersec = 0;
                ++it;
            }
            if (intersec)
            {
                for (auto p: L)
                {
                    if (p == *i) break;
                    res.push_back(p);
                }
                for (auto p: L2)
                {
                    res.push_back(p);
                }
                for (int j = 0; j < L1.size(); j++) ++i;
                while (i != L.end())
                {
                    res.push_back(*i);
                    ++i;
                }
                return res;

            }

        }
    }

}



void filling(list<string> &L, string str)
{
    string temp;
    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        temp = str[i];
        L.push_back(temp);
    }
}

int main()
{
    list<string> lst1, lst2, lst3;

    ifstream fin;
    fin.open("2_3.txt");

    string buf1,
        buf2,
        buf3;

    getline(fin, buf1, '\n');
    filling(lst1, buf1);

    getline(fin, buf2, '\n');
    filling(lst2, buf2);

    getline(fin, buf3, '\n');
    filling(lst3, buf3);

    list<string> res;

    res = replace(lst1, lst2, lst3, lst1.size());

    print(res);
}
