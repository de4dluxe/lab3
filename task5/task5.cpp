#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double coffee_model(double T_env, double T0, double r, double t) {
    return T_env + (T0 - T_env) * exp(-r * t);
}

void linear_regression(const vector<double>& x,
                       const vector<double>& y,
                       double& a,
                       double& b,
                       double& corr,
                       double& R2) {

    int n = x.size();

    double sum_x = 0;
    double sum_y = 0;
    double sum_xy = 0;
    double sum_x2 = 0;
    double sum_y2 = 0;

    // Подсчёт сумм
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        sum_y2 += y[i] * y[i];
    }

    // Коэффициенты прямой y = a*x + b
    a = (n * sum_xy - sum_x * sum_y) /
        (n * sum_x2 - sum_x * sum_x);

    b = (sum_y - a * sum_x) / n;

    // Коэффициент корреляции
    corr = (n * sum_xy - sum_x * sum_y) /
           sqrt((n * sum_x2 - sum_x * sum_x) *
                (n * sum_y2 - sum_y * sum_y));

    // Коэффициент детерминации
    R2 = corr * corr;
}

int main() {

    double T_env;
    double T0;
    double r;

    int n;
    double dt;

    cout << "Температура среды: ";
    cin >> T_env;

    cout << "Начальная температура кофе: ";
    cin >> T0;

    cout << "Коэффициент остывания: ";
    cin >> r;

    cout << "Количество измерений: ";
    cin >> n;

    cout << "Шаг времени: ";
    cin >> dt;

    vector<double> times(n);
    vector<double> temps(n);

    for (int i = 0; i < n; i++) {
        times[i] = i * dt;
    }

    for (int i = 0; i < n; i++) {
        temps[i] = coffee_model(T_env, T0, r, times[i]);
    }

    double a, b, corr, R2;

    linear_regression(times, temps, a, b, corr, R2);

    cout << fixed << setprecision(4);

    cout << "\nТаблица значений:\n";
    cout << "t\tT\n";

    for (int i = 0; i < n; i++) {
        cout << times[i] << "\t" << temps[i] << endl;
    }

    cout << "\nЛинейная модель:\n";
    cout << "T = " << a << " * t + " << b << endl;

    cout << "\nКоэффициент корреляции r = " << corr << endl;
    cout << "Коэффициент детерминации R^2 = " << R2 << endl;

    return 0;
}