#include <iostream>
#include "cmath"
#include "vector"

using namespace std;

typedef float func(float x);

struct Segment {
    float l;
    float r;
};

float taskFunction(float x) {
    return 2 * (x*x+2)*x*x;
}

float findMinFunctionValue(func f, Segment segment, float eps, float &xMinValue) {
    float minValueArgument = segment.l;
    float minFunctionValue = f(segment.l);

    for (float x = segment.l; x <= segment.r; x += eps) {
        if (f(x) < minFunctionValue) {
            minFunctionValue = f(x);
            minValueArgument = x;
        }
    }

    xMinValue = minValueArgument;

    return minFunctionValue;
}

float findMinFunctionValueDivisionByTwo(func f, Segment segment, float eps, float &xMinValue) {

    float precision = abs(segment.r - segment.l);

    while (precision > eps) {
        float alpha = (segment.l + segment.r) / 2 - (segment.r - segment.l) / 4;
        float betta = (segment.l + segment.r) / 2 + (segment.r - segment.l) / 4;

        if (f(alpha) >= f(betta)) {
            segment.l = alpha;
        } else {
            segment.r = betta;
        }

        precision = abs(segment.r - segment.l);
    }

    xMinValue = segment.l;
    return f(segment.l);
}

float findMinFunctionValueFibonacci(func f, Segment segment, float eps, float &xMinValue) {
    int N = 100;

    vector<float> fibonacciValues{1, 1};
    for (int i = 2; i <= N; i++) {
        fibonacciValues.push_back(fibonacciValues[fibonacciValues.size() - 2] +
                                  fibonacciValues[fibonacciValues.size() - 1]);
    }

    float precision = abs(segment.r - segment.l);

    int step = 1;
    while (precision > eps && step < N - 1) {
        float delta = segment.r - segment.l;
        int fibonacciMainIndex = N - step;
        float alpha = segment.l + fibonacciValues[fibonacciMainIndex - 1] /
                                  fibonacciValues[fibonacciMainIndex + 1] * delta;
        float betta = segment.l + fibonacciValues[fibonacciMainIndex] /
                                  fibonacciValues[fibonacciMainIndex + 1] * delta;

        if (f(alpha) >= f(betta)) {
            segment.l = alpha;
        } else {
            segment.r = betta;
        }

        precision = abs(segment.r - segment.l);
        step++;
    }

    xMinValue = segment.l;
    return f(segment.l);
}

int main() {
    float xMinValue;
    cout << findMinFunctionValueFibonacci(taskFunction, {-1, 1}, 0.00001, xMinValue) << " " << xMinValue << "\n";
}
