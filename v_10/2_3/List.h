#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    int data;
    Node *pNext;
    Node *pPrev;
};

template <typename T>
class List
{
private:
    Node<T> *begin;
    Node<T> *end;
    int size = 0;

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

public:
    friend ostream &operator<<(ostream &os, const List<T> &val);

    List(/* args */);
    ~List();
    List(const List &obj);
    List &operator=(const List &obj);
    List(List &&other);
    List operator=(List &&other);
    void push_back(T value);
    void pop_back();
    int find_mx();
    
    int find(T value);

    int GetSize() { return size; }

    // create protothype
    T &operator[](int index)
    {
        if ((index < 0) || (index > size - 1))
            throw out_of_range("Incorrect index.");

        Node<T> *temp = get(index);

        return temp->data;
    }
};

template <typename T>
ostream &operator<<(ostream &os, const List<T> &val)
{
    for (int i = 0; i < val.GetSize(); i++)
        os << val[i] << " ";

    return os;
}

template <typename T>
void List<T>::pop_back()
{
    size--;
    Node<T> *temp = end;
    end = end->pPrev;
    delete[] temp;

}

template <typename T>
int List<T>::find_mx()
{
    T mx = 99,
    temp = 0;
    Node<T> *temp_b = begin;
    Node<T> *temp_e = end;

    while(temp_b != nullptr && temp_e != nullptr)
    {
        temp = temp_b->data + temp_e->data;
        if (mx < temp) mx = temp;
        temp_b = temp_b->pNext;
        temp_e = temp_e->pPrev;
    }
    return mx;
}

template <typename T>
int List<T>::find(T value)
{
    int inx = 0;
    Node<T> *temp = new Node<T>;
    while (begin != nullptr)
    {
        if (value = begin) break;
        inx++;
    }
    delete[] temp;

    return inx;
}

template <typename T>
void List<T>::push_back(T value)
{
    Node<T> *elem = new Node<T>;
    elem->data = value;

    elem->pNext = nullptr;
    elem->pPrev = elem->pPrev;
    if (begin == nullptr)
    { 
        begin = elem;
        end = elem;
    }
    else 
    { 
        end->pNext = elem;
        end = elem;
    }
    size++;
}
template <typename T>
List<T>::List()
{
    begin = nullptr;
    end = nullptr;
    size = 0;
}
template <typename T>
List<T>::~List()
{
    while (end != nullptr)
    {
        pop_back();
    }
    
}
void rand_fill(List<int> &lst, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        lst.push_back(rand() % 10);
    }
    
}

// int find_mx(List<int> lst)
// { 
    
    

// }