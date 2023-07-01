#include <iostream>
using namespace std;

// Class CVector definition
class CArithmetic
{
private:
    // Some attributes go here
public:
    static double Addition(double a, double b)
    {
        return a + b;
    }
    static double Substraction(double a, double b)
    {
        return a - b;
    }
    static double Multiplication(double a, double b)
    {
        return a * b;
    }
    static double Division(double a, double b)
    {
        return a / b;
    }
    // More methods go here
};
/*
double fOpera(double x, double y, double (*f)(double, double)){
    // El puntero f recibe la dirección de inicio de una función
    // no se sabe qué función será la recibida
    return f(x, y);  // Ejecutamos la función a trav6eacute;s del puntero
}
*/
int main()
{
    CArithmetic A;
    float a, b, c;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    double (*fOpera[4])(double a, double b) = {&A.Addition, &A.Substraction, &A.Multiplication, &A.Division};
    char op[] = "+-*/";
    // c = fOpera(a, b, A.Addition);
    for (size_t i = 0; i < 4; i++)
    {
        c = fOpera[i](a, b);
        cout << a << " " << op[i] << " " << b << " = " << c << endl;
    }
}
