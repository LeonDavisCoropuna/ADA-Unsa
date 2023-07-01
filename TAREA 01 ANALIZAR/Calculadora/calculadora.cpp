#include <iostream>

using namespace std;

double Addition(double a, double b)
{
    return a + b;
}
double Subtraction(double a, double b)
{
    return a - b;
}
double Multiplication(double a, double b)
{
    return a * b;
}
double Division(double a, double b)
{
    return a / b;
}
int main()
{
    // Code B
    // User type to simplify the declaration
    typedef double (*lpfnOperation)(double, double);
    // CVector of pointer to functions
    lpfnOperation vpf[4] = {&::Addition, &::Subtraction,
                            &::Multiplication, &::Division};
    float a, b, c;
    int opt;
    // enter the operands
    cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    cout << "Res: " << c << endl;
}
