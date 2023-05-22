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

    void copy(const List<T> &obj)
    {
        Node<T> *t = obj.begin;

        for (int i = 0; i < obj.size; i++)
        {
            push_back(t->data);
            t = t->pNext;
        }

        size = obj.size;
    }

public:
    friend ostream &operator<<(ostream &os, const List<int> &val);

    List(/* args */);
    ~List();
    List(const List &obj)
    {
        this->~List();
        copy(obj);
    }
    List &operator=(const List &obj)
    { 
        this->~List();
        copy(obj);
        return *this;
    }
    // List(List &&other);
    List(List &&other)
    {
        begin = other.begin;
        end = other.end;
        size = other.size;

        other.begin = 0;
        other.end = 0;
        other.size = 0;
    }
    List &operator=(List<T> &&other)
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
int List<T>::find_mx()
{
    Node<T> *temp_b = begin;
    Node<T> *temp_e = end;

    T mx = temp_b->data + temp_e->data,
      temp = 0;

    while (temp_b != nullptr and temp_e != nullptr)
    {
        temp = temp_b->data + temp_e->data;

        temp_b = temp_b->pNext;
        temp_e = temp_e->pPrev;

        if (mx < temp)
            mx = temp;
    }
    return mx;
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
int List<T>::find(T value)
{
    int inx = 0;
    Node<T> *temp = new Node<T>;
    while (begin != nullptr)
    {
        if (value = begin)
            break;
        inx++;
    }
    delete[] temp;

    return inx;
}

template <typename T>
void List<T>::push_back(T value)
{
    Node<T> *temp = new Node<T>;

    temp->data = value;
    temp->pNext = nullptr;
    temp->pPrev = end;

    if (begin == nullptr)
    {
        begin = temp;
        end = temp;
    }
    else
    {
        end->pNext = temp;
        end = temp;
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

int find_mx(List<int> &lst)
{
    int mx = lst[0];
    for (int i = 0, j = lst.GetSize() - 1, temp; i < lst.GetSize() / 2; i++, j--)
    {
        temp = lst[i] + lst[j];
        if (mx < temp)
            mx = temp;
    }

    return mx;
}

ostream &operator<<(ostream &os, const List<int> &val)
{
    Node<int> *temp_b = val.begin;
    for (int i = 0; i < val.size; i++)
    {
        os << temp_b->data << ' ';
        temp_b = temp_b->pNext;
    }
    
    
    return os;
}


int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;

    List<int> lst;
    rand_fill(lst, 2 * n);

    cout << lst << "\n";

    //cout << "mx: " << find_mx(lst) << "\n";
    cout << "mx: " << lst.find_mx() << "\n";
}