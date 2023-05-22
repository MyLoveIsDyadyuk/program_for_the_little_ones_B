#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node 
{
    string last_name;
    string birthday;
    int course;
    double subj; 
    Node* pNext; 

};

void find_gt(Node* pTop, string key, Node*& ppv) 
{
    Node* pv = pTop;
    ppv = pTop;

    while (pv && pv->last_name <= key)
    {
        ppv = pv;   
        pv = pv->pNext;
    }
}
// int a = func();

void add(Node*& pTop, string last_name, string birthday, int course, double subj) //Добавление нового элемента с сортировкой по алфавиту
{
    Node* new_value, * ppv = NULL;
    new_value = new Node; 
    
    new_value->last_name = last_name;
    new_value->birthday = birthday;
    new_value->course = course;
    new_value->subj = subj;
    new_value->pNext = NULL;
    if (!pTop)             
        pTop = new_value;           
    else
    {
        if (pTop->last_name >= last_name)                  
        {
            new_value->pNext = pTop;
            pTop = new_value;
        }
        else
        {
            find_gt(pTop, last_name, ppv);
            new_value->pNext = ppv->pNext;
            ppv->pNext = new_value;
        }
    }
}

void print(Node *pTop)
{ 
    ofstream fout;
    fout.open("zadrot.txt");

    
    while (pTop)  
    { 
        fout << pTop->last_name << "\t" << pTop->birthday << "\t" << pTop->course << "\t" << pTop->subj << "\n";
        pTop = pTop->pNext;
    }
    fout.close();
}

void print_list(Node* pTop)
{
    while (pTop)
    {
        cout << pTop->last_name << "  " << pTop->birthday << " " << pTop->course << "   " << pTop->subj << endl;
        pTop = pTop->pNext;
    }
}

void find_eq(Node* pTop, double key, Node*& ppv) {
    Node* pv = pTop;
    ppv = pv;
    do {
        if (pv->subj < key) {
            return; 
        }
        ppv = pv;
        pv = pv->pNext;
    } while (pv);
    ppv = NULL; 
}


void del(Node*& pTop, double key, Node*& bad_pTop)
{
    Node* pv, * ppv;
    do {
        find_eq(pTop, key, ppv);
        if (ppv) 
        {
            if (ppv == pTop) 
            { 
                add(bad_pTop, pTop->last_name, pTop->birthday, pTop->course, pTop->subj);
                pTop = pTop->pNext;
            }
            else 
            {
                pv = ppv->pNext;
                add(bad_pTop, pv->last_name, pv->birthday, pv->course, pv->subj);
                ppv->pNext = pv->pNext;
            }
        }
    } while (ppv && pTop);
}

// int main() {
//     ifstream fin;
//     fin.open("students.txt");


//     Node* pTop = NULL;

//     cout << "Enter quantity of students (max = 14): ";
//     int quantity;
//     cin >> quantity;

//     string last_name = "";
//     string birthday = "";
//     int course;
//     double subj;

//     for (int i = 0; i < quantity; i++) {

//         fin.eof();
//         fin >> last_name;

//         fin.eof();
//         fin >> birthday;


//         fin.eof();
//         fin >> course;

//         fin.eof();
//         fin >> subj;

//         add(pTop, last_name, birthday, course, subj);
//     }

//     print_list(pTop);

//     cout << "Enter GPA: ";
//     double middle_subj;
//     cin >> middle_subj;

//     Node* bad_pTop = NULL;

//     del(pTop, middle_subj, bad_pTop);
//     print(pTop);



//     fin.close();
//     return 0;
// }