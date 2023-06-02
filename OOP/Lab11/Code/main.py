# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    data = []
    tmp = []
    while True:
        s = input()
        if s == '.':
            data.insert(tmp)
            break
        if s == '':
            data.insert(tmp)
            tmp.clear()
            continue
        s = s.split(' ')
        for i in range(len(s)):
            s[i] = int(s[i])
        tmp.append(s)


    sums = [[]]
    for i in range(len(data)):
        sums.append([])
        for j in range(len(data[i])):
            sum = 0
            for k in range(len(data[i][j])):
                sum += data[i][j][k]
            sums[i].append(sum)

    print(sums)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
