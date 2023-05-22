#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *pNext;
};

template <class T>
class List
{
private:    
    Node<T> *begin;
    Node<T> *end;
    int size;

    Node<T> *get(int index)
    {
        if (size > 0)
        {
            Node<T> *t = begin;
            for (int i = 0; i < index; i++)
                t = t->pNext;
            return t;
        }
        return 0;
    }

    void copy(const List &obj)
    {
        clear();
        Node<T> *t = obj.begin;

        for (int i = 0; i < obj.size; i++)
        {
            push_back(t->data);
            t = t->pNext;
        }

        size = obj.size;
    }

public:
    friend ostream &operator<<(ostream &os, const List<string> &val);

    List()
    {
        begin = end = nullptr;
        size = 0;
    }
    // operator and constructor to copy
    List(const List &obj)
    {
        copy(obj);
    }

    List<T> &operator=(const List &obj)
    {
        copy(obj);
        return *this;
    }
    // operator moving and constructor moving
    List(List &&other)
    {
        begin = other.begin;
        end = other.end;
        size = other.size;

        other.begin = 0;
        other.end = 0;
        other.size = 0;
    }
    List &operator=(List &&other)
    {
        this->~List();

        begin = other.begin;
        end = other.end;
        size = other.size;

        other.begin = 0;
        other.end = 0;
        other.size = 0;

        return *this;
    }
    void push_back(T _data)
    {
        Node<T> *elem = new Node<T>;
        elem->data = _data;
        elem->pNext = nullptr;

        if (begin == nullptr)
        {
            begin = end = elem;
        }
        else
        {
            end->pNext = elem;
            end = elem;
        }
        size++;
    }

    void remove(int index)
    {
        if (size == 0)
            return;
        if ((index < 0) || (index >= size))
            return;
        if (index == 0)
        {
            Node<T> *temp = begin;
            begin = begin->pNext;
            delete[] temp;
        }
        else
        {
            Node<T> *temp = get(index - 1);
            Node<T> *temp1 = temp->pNext;
            temp->pNext = temp1->pNext;
            delete[] temp1;
        }
        size--;
    }
    void clear()
    {
        int i = 0;
        while (begin != nullptr)
        {
            remove(i);
            i++;
        }
    }
    int GetSize() { return size; }
    T &operator[](int index)
    {
        if ((index < 0) || (index >= size))
        {
            throw out_of_range("Incorrect index.");
        }

        Node<T> *temp = get(index);

        return temp->data;
    }
};

void replace(List<string> &L, List<string> &L1, List<string> &L2, int size)
{
    if (L1.GetSize() == 0)
    {
        cout << "replacement is not possible\n";
        return;
    }
    for (int i = 1, len, j, k; i < size; ++i)
    {
        if (L[i] == L1[0])
        {
            bool intersec = 1;
            len = L1.GetSize();
            for (int j = i + 1, k = 1; k < len; j++, k++)
            {
                if (L[j] != L1[k]) intersec = 0;
            }
            if (intersec)
            {
                len = L2.GetSize();
                for (int j = i, k = 0; k < len; j++, k++)
                    L[j] = L2[k];
            }
            return;
        }
    }
}

void print(List<string> &L, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << L[i];
    }
}

void filling(List<string> &L, string str)
{
    string temp;
    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        temp = str[i];
        L.push_back(temp);
    }
}
ostream &operator<<(ostream &os, const List<string> &val)
{
    Node<string> *temp_b = val.begin;
    for (int i = 0; i < val.size; i++)
    {
        os << temp_b->data;
        temp_b = temp_b->pNext;
    }
    
    
    return os;
}

int main()
{
    List<string> lst1, lst2, lst3;

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

    replace(lst1, lst2, lst3, lst1.GetSize());
    cout << lst1;
}