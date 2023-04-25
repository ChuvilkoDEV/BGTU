#include <iostream>
#include "vector"
#include "cmath"

using namespace std;

typedef double diff_equation(double x, double y);

typedef double methodOfSolution(diff_equation func, double x0, double y0, double target, double step);

class KoshiSolver {
public:
    static double euler(diff_equation func, double x0, double y0, double target, double step) {
        //x, y
        vector<vector<double>> table{{x0, y0}};

        while (table[table.size() - 1][0] < target) {
            vector<double> previous_row = table[table.size() - 1];
            double next_x = previous_row[0] + step;
            double next_y = previous_row[1] + step * func(previous_row[0], previous_row[1]);
            table.push_back({next_x, next_y});
        }

        return table[table.size() - 1][1];
    }

    static double eulerKoshi(diff_equation func, double x0, double y0, double target, double step) {
        //x, y
        vector<vector<double>> table{{x0, y0}};

        while (table[table.size() - 1][0] < target) {
            vector<double> previous_row = table[table.size() - 1];
            double next_x = previous_row[0] + step;

            double intermediate_value = func(previous_row[0], previous_row[1]);
            double next_y = previous_row[1] + step / 2 *
                    (intermediate_value + func(next_x, previous_row[1] + step * intermediate_value));
            table.push_back({next_x, next_y});
        }

        return table[table.size() - 1][1];
    }

    static double modifiedEuler(diff_equation func, double x0, double y0, double target, double step) {
        //x, y
        vector<vector<double>> table{{x0, y0}};

        while (table[table.size() - 1][0] < target) {
            vector<double> previous_row = table[table.size() - 1];
            double next_x = previous_row[0] + step;

            double intermediate_value = func(previous_row[0], previous_row[1]);
            double next_y = previous_row[1] + step * func(previous_row[0] + step / 2,
                                                          previous_row[1] + step / 2 * intermediate_value);
            table.push_back({next_x, next_y});
        }

        return table[table.size() - 1][1];
    }

    static double rungeKutta(diff_equation func, double x0, double y0, double target, double step) {
        //x, y
        vector<vector<double>> table{{x0, y0}};

        while (table[table.size() - 1][0] < target) {
            vector<double> previous_row = table[table.size() - 1];
            double next_x = previous_row[0] + step;

            double m1 = func(previous_row[0], previous_row[1]);
            double m2 = func(previous_row[0] + step / 2, previous_row[1] + step / 2 * m1);
            double m3 = func(previous_row[0] + step / 2, previous_row[1] + step / 2 * m2);
            double m4 = func(previous_row[0] + step, previous_row[1] + step * m3);
            double next_y = previous_row[1] + step / 6 * (m1 + 2 * m2 + 2 * m3 + m4);

            table.push_back({next_x, next_y});
        }

        return table[table.size() - 1][1];
    }

    static double findError(diff_equation func, double x0, double y0, double target, double step,
                     methodOfSolution method, double method_p) {
        double valueStep = method(func, x0, y0, target, step);
        double valueStepDividedBy2 = method(func, x0, y0, target, step / 2);

        return (valueStepDividedBy2 - valueStep) / (std::pow(2, method_p) - 1);
    }

    double solveKoshiWithPrecision(diff_equation func, double x0, double y0, double target, double step,
                                   const string& method, double precision) {
        if (method == "Euler") {
            double currentError = findError(func, x0, y0, target, step, euler, 1);
            while (currentError > precision) {
                step /= 2;
                currentError = findError(func, x0, y0, target, step, euler, 1);
            }
            return euler(func, x0, y0, target, step);

        } else if (method == "Euler Koshi") {
            double currentError = findError(func, x0, y0, target, step, eulerKoshi, 2);
            while (currentError > precision) {
                step /= 2;
                currentError = findError(func, x0, y0, target, step, eulerKoshi, 2);
            }
            return eulerKoshi(func, x0, y0, target, step);

        } else if (method == "Modified Euler") {
            double currentError = findError(func, x0, y0, target, step, modifiedEuler, 2);
            while (currentError > precision) {
                step /= 2;
                currentError = findError(func, x0, y0, target, step, modifiedEuler, 2);
            }
            return modifiedEuler(func, x0, y0, target, step);

        } else if (method == "Runge Kutta") {
            double currentError = findError(func, x0, y0, target, step, rungeKutta, 4);
            while (currentError > precision) {
                step /= 2;
                currentError = findError(func, x0, y0, target, step, rungeKutta, 4);
            }
            return rungeKutta(func, x0, y0, target, step);

        } else {
            return 0;
        }
    }
};

double target_function(double x, double y) {
    return sin(x) - y / x;
}

int main() {
    system("chcp 65001");
    KoshiSolver solver;
    double x0 = M_PI;
    double y0 = 1 / M_PI;

    cout << "Точность для пятого знака"
    << "\nМетод Коши: " << solver.solveKoshiWithPrecision(target_function, x0, y0, M_PI + 1, 1, "Euler", 0.00001)
    << "\nМетод Эйлера Коши: " << solver.solveKoshiWithPrecision(target_function, x0, y0, M_PI + 1, 1, "Euler Koshi", 0.00001)
    << "\nМетод модифицированный Эйлера: " << solver.solveKoshiWithPrecision(target_function, x0, y0, M_PI + 1, 1, "Modified Euler", 0.00001)
    << "\nМетод Рунге Кутта: " << solver.solveKoshiWithPrecision(target_function, x0, y0, M_PI + 1, 1, "Runge Kutta", 0.00001);
}


