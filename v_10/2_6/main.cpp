#include "header.h"

/*Объявить класс «многоразрядное целое число». Количество разрядов числа хра-
нить в поле класса, значения разрядов числа хранить в динамической памяти, ос-
нование системы счисления задавать константой.
Реализовать:
• конструктор без параметров
• конструктор с параметрами,
• деструктор,
• другие методы согласно «правилу пяти»,
• перегрузить операции ввода/вывода данных.
• перегрузить оператор индексирования [ ] для доступа к разрядам числа,
• операции в задании реализовать посредством перегрузки.
Объявление класса разместить в заголовочном файле, определения методов –
во втором файле, определение главной функций программы – в третьем файле.
При переполнении старшего разряда лишние биты теряются.
Примечание.
Оператор умножения многоразрядных чисел удобно реализовать через более
простые перегруженные операторы: умножение многоразрядного числа на одно-
разрядное число, сдвиг многоразрядного числа на целое число разрядов, сложение
многоразрядных чисел.
Оператор деления многоразрядных чисел удобно реализовать через более про-
стые перегруженные операторы: сдвиг многоразрядного числа на целое число раз-
рядов, сравнение и вычитание многоразрядных чисел.
Выполнить задание, используя объекты этого класса.
 Объявить класс «n-разрядное целое положительное число в 10-ричной с/с».
Реализовать операции: сложения, умножения. Вычислить 100!.
*/


int main()
{ 
    string a = "12";
    BigInt num(a);
    BigInt num1(a);
    
    BigInt temp;
    temp = num1 * num1;

    // cout << temp << "\n";

    string hundred = "100";

    BigInt num2(hundred);
    cout << Factorial(5);
    
}

