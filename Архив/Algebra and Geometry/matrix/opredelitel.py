def second_p(m):
    a, b, c, d = m[0][0], m[0][1], m[1][0], m[1][1]
    A = a*d - b*c
    return A

def third_p(m):
    a, b, c, d, e, f, g, h, i = m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]
    A = a*second_p( [[e,f],[h,i]] ) - b*second_p( [[d,f],[g,i]] ) + c*second_p( [[d,e],[g,h]] )
    return A

def fourth_p(m, stroka=True, number=0):
    if stroka==True:
        for i in range(4):
            if i == number:
                continue
            else:
                for j in range(4):
                    if j != 0:
                        A1v=0


print(third_p( [[2,3,4],[2,1,2],[2,3,-5]] ))