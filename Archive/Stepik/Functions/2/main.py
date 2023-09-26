def modify_list(l):
    for i in range(len(l)-1, -1, -1):
        if l[i] % 2:
            l.remove(l[i])
        else:
            l.append(l[i] // 2)
            l.remove(l[i])
    print(l)
l = [1, 2, 3, 4, 5, 6]
modify_list(l)