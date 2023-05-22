
#include <iostream>
#include <memory>
#include <string>
using namespace std;


using namespace std;

class BigInt{
	string digits;
    const int radix = 10;

public:

	//Constructors:
	BigInt();
	BigInt(string &);
   
    BigInt(const BigInt &obj);
    BigInt(BigInt &&other);

    BigInt &operator=(const BigInt &obj);
    BigInt &operator=(BigInt &&other);


	friend int Length(const BigInt &);
	int operator[](const int)const;


	//Addition and Subtraction
	friend BigInt operator+(const BigInt &, const BigInt &);



	friend BigInt operator*(const BigInt &, const BigInt &);
	friend BigInt operator*(const BigInt &, const int &);



	//Read and Write
	friend ostream &operator<<(ostream &,const BigInt &);
	friend istream &operator>>(istream &, BigInt &);

	//friend 


    int GetRadix();
    int GetSize();
};

BigInt Factorial(int n);