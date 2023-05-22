#include <iostream>
#include <stack>
#include <fstream>
#include <cmath>

using namespace std;

bool isOperator(char c)
{
    return (
        c == '+' ||
        c == '-' ||
        c == '+' ||
        c == '*' ||
        c == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

double applyOperation(char op, double b, double a)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    else
        return NAN;
}

void push_result(stack<double> &values,
                 stack<char> &operators)
{
    double b = values.top();
    values.pop();
    double a = values.top();
    values.pop();
    char op = operators.top();
    operators.pop();

    values.push(applyOperation(op, b, a));
}

double calculator(string expr)
{
    stack<double> values;
    stack<char> operators;

    int len = expr.length();
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == ' ')
            continue;

        else if (expr[i] == '(')
        {
            operators.push(expr[i]);
        }

        else if (isdigit(expr[i]) || expr[i] == '.')
        {
            string num_str;
            while (i < len && (isdigit(expr[i]) || expr[i] == '.'))
            {
                num_str += expr[i];
                i++;
            }   
            i--;

            double num = stod(num_str);
            values.push(num);
        }

        else if (isOperator(expr[i]))
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i]))
            {
                push_result(values, operators);
            }

            operators.push(expr[i]);
        }

        else if (expr[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                push_result(values, operators);
            }

            operators.pop();
        }
    }

    while (!operators.empty())
    {
        push_result(values, operators);
    }

    return values.top();
}

void read(int mode)
{
    if (mode == 2 || mode == 1)
    {
        ifstream fin;
        string expr,
               file_name = "test_";
        file_name.push_back(('0' + mode));
        file_name += ".txt";
        fin.open(file_name);
        for (int i = 0; i < 3; i++)
        {
            getline(fin, expr, '\n');
            cout << expr << " = " << calculator(expr) << "\n";
        }
        fin.close();
    }
    else
        cout << "no such test\n";
}

int main()
{
    cout << "Select test number 1 or 2 (enter 1 or 2): ";
    int mode;
    cin >> mode;
    read(mode);
}