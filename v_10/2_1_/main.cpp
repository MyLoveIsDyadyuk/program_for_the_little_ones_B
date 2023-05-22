#include <iostream>
#include <time.h>
#include <memory>
using namespace std;

template <typename T>
class vector
{
public:
    friend ostream &operator<<(ostream &os, const vector<double> &val);
    void resize(int max_size)
    {
        if (max_size <= capacity_)
            size_ = max_size;
        else
        {
            capacity_ = max_size;
            size_ = max_size;
            delete[] arr_;
            arr_ = new T[capacity_];
        }
    }
    vector()
    {
        arr_ = new T[1];
        capacity_ = 1;
        size_ = 0;
    }


    // operator copy and construktor copy
    vector &operator=(const vector &vec)
    {
        size_ = vec.size_;
        capacity_ = vec.capacity_;

        delete[] arr_;
        arr_ = new T[capacity_];

        for (unsigned int i = 0; i < size_; ++i)
            arr_[i] = vec[i];
    }
    vector(const vector &vec)
    {
        size_ = vec.size_;
        capacity_ = vec.capacity_;
        arr_ = new T[capacity_];
        for (unsigned int i = 0; i < size_; ++i)
            arr_[i] = vec[i];
    }
    // operator moving and constructor moving
    vector(vector &&other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;

        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = 0;
    }
    vector &operator=(vector &&other)
    {
        this->~vector;
        
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;

        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = 0;

        return *this;
    }

    ~vector()
    {
        delete[] arr_;
    };
    void push_back(const T &);
    void filling_rand()
    {
        srand(time(NULL));
        for (int i = 0; i < size_; i++)
        {
            arr_[i] = rand() % 10;
        }
    };
    int GetSize() { return size_; }
    int GetCapacity()
    {
        return capacity_;
    }

    T &operator[](size_t index)
    {
        if (size_ < index)
            throw out_of_range("Index out of range");

        return arr_[index];
    }
    const T &operator[](size_t index) const
    {
        if (size_ < index)
            throw out_of_range("Index out of range");

        return arr_[index];
    }

private:
    void AddMemory();

    T *arr_;
    int size_;
    int capacity_{};
};

template <typename T>
void vector<T>::push_back(const T &value)
{
    if (size_ >= capacity_)
        AddMemory();
    arr_[size_++] = value;
}

template <typename T>
void vector<T>::AddMemory()
{
    capacity_ *= 2;
    unique_ptr<T[]> temp(arr_);
    for (unsigned int i = 0; i < size_; ++i)
        arr_[i] = temp[i];
}

ostream &operator<<(ostream &os, const vector<double> &val)
{
    for (int i = 0; i < val.size_; i++)
    {
        os << val[i] << " ";
    }
    
    return os;
}

// int main()
// {
//     int amount;
//     cout << "amount numbers = ";
//     cin >> amount;


//     vector<int> arr;
//     arr.resize(amount);
//     arr.filling_rand();
//     cout << arr << "\n";

    
//     vector<int> new_arr;
//     new_arr.resize(10001);
    
    
//     for (int i = 0; i < 10001; i++)
//     {
//         new_arr[i] = 0;
//     }

//     for (int i = 0; i < amount; i++)
//     {
//         new_arr[arr[i]]++;
//     }
//     cout << "number\n";
//     for (int i = 0; i < 10001; i++)
//     {
//         if (new_arr[i] == 1)
//             cout << i << "\t";
//     }
// }
