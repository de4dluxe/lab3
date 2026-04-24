#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, y, xn, xk, dx;

    cout << "Введите Xнач: ";
    cin >> xn;
    cout << "Введите Xкон: ";
    cin >> xk;
    cout << "Введите шаг dx: ";
    cin >> dx;

    cout << "\n----------------------\n";
    cout << "|    X    |    Y    |\n";
    cout << "----------------------\n";

    for (x = xn; x <= xk; x += dx)
    {
        if (x <= -3)
            y = -x - 6;
        else if (x <= 0)
            y = -3 + sqrt(9 - 4 * (x + 1.5) * (x + 1.5));
        else if (x <= 3)
            y = 2 * x * x * x / 9 - 3;
        else
            y = -1.5 * x + 7.5;

        cout << "|" << setw(8) << fixed << setprecision(2) << x
             << "|" << setw(8) << y << " |\n";
    }
    cout << "----------------------\n";
}