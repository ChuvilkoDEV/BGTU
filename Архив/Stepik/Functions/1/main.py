def f(x):
    if x <= -2:
        print(1 - (x + 2) ** 2)
    elif 2 < x:
        print((x - 2) ** 2 + 1)
    else:
        print(-x / 2)

x = float(input())
f(x)