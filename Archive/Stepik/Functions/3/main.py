with open('1.txt', 'r') as f:
    inf = f.readline()
    out = ''

    for i in range(0, len(inf) - 1, 2):
        a, b = str(inf[i]), int(inf[i + 1])
        print(a, b)
        out += str(a * b)
        print(out)
    print(out)
    with open('1out.txt', 'w') as f_out:
        f_out.write(out)
