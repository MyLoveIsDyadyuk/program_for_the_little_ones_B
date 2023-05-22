#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// 4.1 Определить является ли введенный текст: идентификатором, записью целого числа
// 4.3 Записать в новую строку слова исходной строки, в которых нет одинаковых символов.

bool is_digits(const std::string &str)
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}
void removeDupWord(char *str, string &only_word)
{

  const char sep[] = " ,?!;-.()";
  char *context = nullptr;

  cout << "\n\n4.3\nEnter a string: ";
  cin.getline(str, 80);

  char *Ptr = strtok_s(str, sep, &context);

  while (Ptr != nullptr)
  {
    for (int i = 0; i < strlen(Ptr); i++)
      only_word.push_back(Ptr[i]);

    Ptr = strtok_s(nullptr, sep, &context);
  }
}
void unique(string &only_word)
{
  int len = only_word.size();
  for (int i = 0; i < len; i++)
  {
    if (count(only_word.begin(), only_word.end(), only_word[i]) == 1)
    {
      cout << only_word[i];
    }
  }
}
void hex(int num)
{
  int i, temp = 0, hexa[20], rem;
  cout << "Hexadecimal eqivalent ";
  for (i = 0; num > 0; i++)
  {
    for (int y = 0; y < 4; y++)
    {
      rem = num % 10;
      num /= 10;
      temp += rem * pow(2, y);
    }
    hexa[i] = temp;
    temp = 0;
  }
  while (i > 0)
  {
    i--;
    if (hexa[i] > 9)
      cout << char(55 + hexa[i]);
    else
      cout << hexa[i];
  }
}
void oct(int n)
{
  int a[20], i;
  for (i = 0; n != 0; i++)
  {
    a[i] = n % 8;
    n = n / 8;
  }
  for (int y = i - 1; y >= 0; y--)
    cout << a[y];
}
void hexn(int num)
{
  int hexa[20], i;
  for (i = 0; num > 0; i++)
  {
    hexa[i] = num % 16;
    num /= 16;
  }
  while (i > 0)
  {
    i--;
    if (hexa[i] > 9)
      cout << char(55 + hexa[i]);
    else
      cout << hexa[i];
  }
}
void bin(int num)
{
  int binary = 0, rem, temp = 1, z = 1;
  cout << "Binary equivalent = ";
  while (num > 0)
  {
    temp = num % 10;
    num /= 10;
    for (int y = 0; y < 3; y++)
    {
      rem = temp % 2;
      temp /= 2;
      binary += rem * z;
      z *= 10;
    }
  }
  cout << binary;
}

int main()
{
  // 4.1
  cout << "\n4.1\nenter digit?: ";
  string s;
  cin >> s;
  string res = (is_digits(s)) ? "id" : "not an id";
  cout << "this word is " << res << "\n";

  // 4.2
  cout << "\n4.2\n";
  bin(5);

  // 4.3
  char str[80];
  cin.clear();
  cin.ignore(10000, '\n');
  string only_word;
  removeDupWord(str, only_word);
  unique(only_word);
}