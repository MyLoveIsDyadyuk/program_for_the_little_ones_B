
#include "header.h"

BigInt::BigInt()
{
    digits = nullptr;
}

BigInt::BigInt(string &s)
{
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(const BigInt &obj)
{
}

BigInt::BigInt(BigInt &&other)
{
}

int Length(const BigInt &a)
{
    return a.digits.size();
}

BigInt &BigInt::operator=(const BigInt &a)
{
    digits = a.digits;
    return *this;
}

BigInt &BigInt::operator=(BigInt &&other)
{
    // TODO: вставьте здесь оператор return
}

int BigInt::operator[](const int inx) const
{
    return int(digits[inx]);
}

int BigInt::GetRadix()
{
    return radix;
}

int BigInt::GetSize()
{
    return digits.size();
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp = temp + b;
    return temp;
}

BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp = temp * b;
    return temp;
}

BigInt operator*(BigInt &a, const int &num)
{
    string temp;
    int len = a.GetSize();
    int t, 
        rdx = 0;
    for (int i = 0, j = len - 1; i < len; i++)
    {
        t = int(a[i]) * num + rdx;
        rdx = t / 10;
        t = t % 10;
        temp.push_back(t - '0');
    }

    return BigInt();
}

BigInt Factorial(int n)
{
    string a = "1";
    BigInt f(a);
    for (int i = 2; i <= n; i++)
    { 
        if (i <= 10)
            f = f * i;
        else
        { 
            f = f * (i % 10);
            f = f * (i / 10);
        }
    }
    return f;
}

istream &operator>>(istream &in, BigInt &a)
{
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short)a.digits[i];
    return cout;
}
