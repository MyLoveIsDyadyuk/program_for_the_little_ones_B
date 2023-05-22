#include <iostream>
#include <iterator>
#include <forward_list>
#include <list>
#include <time.h>


void filling(std::forward_list<int> &a, int n) 
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a.push_front(rand() % 10);
}

void print(std::forward_list<int> &a, int n) 
{
	srand(time(0));
	for (auto i: a)
		std::cout << i << " ";
    std::cout << "\n";
}


int find_mx(std::forward_list<int> &a, int n)
{ 
    std::forward_list<int>::iterator bg = a.begin();
    std::forward_list<int> b;
    b = a;
    b.reverse();
    std::forward_list<int>::iterator en = b.begin();
    int mx = *bg + *en;
    for (int i = 0; i < n; ++bg, ++en, i++)
    {
        if (*bg + *en > mx) 
			mx = *bg + *en;
    }
    return mx;
}


int main()
{ 
    std::forward_list<int> a;
    int n;
    std::cout << "amount numbers = ";
    std::cin >> n;
    filling(a, n * 2);
    print(a, n * 2);
    std::cout << "\nresult = " << find_mx(a, n);
}