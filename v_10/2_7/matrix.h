#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "memory"
#include <iomanip>
using namespace std;

template <typename T>
class vector
{
public:
    void clear()
    {
        delete[] arr_;
    }
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

        return *this;
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
        this->~vector();

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
    arr_ = new T[capacity_];
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

class Matrix
{
private:
    static inline unsigned count_{};
    int id_;

    vector<vector<double>> data;
    int ord;

public:
    friend ostream &operator<<(ostream &, const Matrix &);

    Matrix();
    Matrix(int order);

    Matrix(const Matrix &mat);
    Matrix(Matrix &&other);


    ~Matrix();
    void random();
    double matrix_trace();

    const int get_id() const { return id_; }
    const int get_ord() const { return ord; }

    Matrix &operator=(const Matrix &);
    Matrix &operator=(Matrix &&);

    double &operator()(int x, int y) { return data[x][y]; }
    const double &operator()(int x, int y) const { return data[x][y]; }

    Matrix &operator^=(int);
};

Matrix::Matrix()
{
    count_++;
    id_ = count_;
}

Matrix::Matrix(int order)
{
    this->ord = order;
    count_++;
    id_ = count_;
}

Matrix::Matrix(const Matrix &m)
{
    id_ = m.get_id();
    for (int i = 0; i < m.ord; ++i)
    {
        vector<double> temp_vec;
        for (int j = 0; j < m.ord; ++j)
        {
            temp_vec.push_back(m(i, j));
        }
        data.push_back(temp_vec);
    }
}

Matrix::Matrix(Matrix &&other)
{
    id_ = other.get_id();
    for (int i = 0; i < other.ord; ++i)
    {
        vector<double> temp_vec;
        for (int j = 0; j < other.ord; ++j)
        {
            temp_vec.push_back(other(i, j));
        }
        data.push_back(temp_vec);
    }

    other.id_ = -1;
}

Matrix::~Matrix()
{
}

void Matrix::random()
{
    srand(time(nullptr));
    for (int i = 0; i < ord; ++i)
    {
        vector<double> temp_vec;
        for (int j = 0; j < ord; ++j)
        {
            temp_vec.push_back(rand() / 10000.0);
        }
        data.push_back(temp_vec);
    }
}

double Matrix::matrix_trace()
{
    double trace = 0.0;
    for (int i = 0; i < ord; ++i)
        trace += data[i][i];

    return trace;
}

Matrix &Matrix::operator=(const Matrix &m)
{
    // if (this == &m)
    // {
    //     return *this;
    // }

    // else
    {
    }
    id_ = m.get_id();
    data.clear();
    for (int i = 0; i < m.ord; ++i)
    {
        vector<double> temp_vec;
        for (int j = 0; j < m.ord; ++j)
        {
            temp_vec.push_back(m(i, j));
        }
        data.push_back(temp_vec);
    }

    return *this;
}

Matrix &Matrix::operator=(Matrix &&other)
{
    if (this == &other)
        return *this;

    data = std::move(other.data);
    ord = other.ord;
    id_ = other.id_;
    other.id_ = -1;
    // for (int i = 0; i < other.ord; ++i)
    // {
    //     vector<double> temp_vec;
    //     for (int j = 0; j < other.ord; ++j)
    //     {
    //         temp_vec.push_back(other(i, j));
    //     }
    //     data.push_back(temp_vec);
    // }
    // other.id_ = -1;

    return *this;
}

ostream &operator<<(ostream &os, const Matrix &mat)
{
    os << "Matrix #" << mat.get_id() << ":"
       << "\n";
    int ord = mat.get_ord();
    for (int i = 0; i < ord; i++)
    {
        for (int j = 0; j < ord; j++)
        {
            os << setw(12) << mat(i, j) << setw(12) << " " << setw(12);
        }
        os << "\n";
    }
}

Matrix &Matrix::operator^=(int degree)
{
    while (degree != 1)
    {
        double **product = new double *[ord];
        for (int i = 0; i < ord; ++i)
            product[i] = new double[ord];

        for (int i = 0; i < ord; ++i)
        {
            for (int j = 0; j < ord; ++j)
            {
                product[i][j] = 0;
            }
        }

        for (int row = 0; row < ord; ++row)
        {
            for (int col = 0; col < ord; ++col)
            {
                for (int k = 0; k < ord; ++k)
                {
                    product[row][col] += data[row][k] * data[k][col];
                }
            }
        }
        for (int i = 0; i < ord; ++i)
        {
            vector<double> temp_vec;
            for (int j = 0; j < ord; ++j)
            {
                data[i][j] = product[i][j];
            }
        }
        degree--;
    }

    return *this;
}
