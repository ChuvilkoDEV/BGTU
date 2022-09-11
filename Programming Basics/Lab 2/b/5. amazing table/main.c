#include <stdio.h>

int main() {
    int f;
    scanf("%d", &f);

    for (int i = 0; i < f; ++i) {
        long long line;
        long long column;
        long long x;
        scanf("%lld %lld %lld", &line, &column, &x);

        if (x == 1 || line == 1 || column == 1 || x == line * column)
            printf("%lld\n", x);
        else {
            long long outColumn = x / line + 1;
            long long outLine = x % line - 1;
            if (outLine < 0)
                outLine = line - 1;

            long long out = outLine * column + outColumn;
            if (out / column + (out % column != 0) == line)
                out -= 1;

            printf("%lld\n", out);
        }
    }

    return 0;
}