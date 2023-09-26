from matplotlib import pyplot as plt
import math

m1 = 10
m2 = 5
g = 9.8
k = 10000
L = 1

t0 = 0
x0 = -0.1
phi0 = 30 / 180 * 3.14
V0 = 0
w0 = 0


def func_dV(t, x, phi, V, w):
    return (m2 * g * math.cos(phi) - k * x + m2 * (w ** 2) * (L + x)) / (m2 + m1)


def func_dw(t, x, phi, V, w):
    return (g * math.sin(phi) - 2 * V * w) / ((L + x) ** 2)


def runge_kutt_step(runge_kutt_table: list, step: float):
    current_row = runge_kutt_table[-1]
    next_row = [None] * 5
    runge_kutt_table.append(next_row)

    next_row[0] = current_row[0] + step
    next_row[1] = current_row[1] + current_row[3] * step
    next_row[2] = current_row[2] + current_row[4] * step

    k1dV = func_dV(current_row[0], current_row[1], current_row[2], current_row[3], current_row[4])
    k2dV = func_dV(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3] + step * k1dV / 2,
                   current_row[4])
    k3dV = func_dV(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3] + step * k2dV / 2,
                   current_row[4])
    k4dV = func_dV(current_row[0] + step, current_row[1], current_row[2], current_row[3] + step * k3dV, current_row[4])

    next_row[3] = current_row[3] + step / 6 * (k1dV + 2 * k2dV + 2 * k3dV + k4dV)

    k1dw = func_dw(current_row[0], current_row[1], current_row[2], current_row[3], current_row[4])
    k2dw = func_dw(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3],
                   current_row[4] + step * k1dw / 2)
    k3dw = func_dw(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3],
                   current_row[4] + step * k2dw / 2)
    k4dw = func_dw(current_row[0] + step, current_row[1], current_row[2], current_row[3], current_row[4] + step * k3dw)

    next_row[4] = current_row[4] + step / 6 * (k1dw + 2 * k2dw + 2 * k3dw + k4dw)


if __name__ == '__main__':
    # t, x, phi, V, w
    runge_kutt_table = [
        [t0, x0, phi0, V0, w0]
    ]

    for i in range(300000):
        runge_kutt_step(runge_kutt_table, 0.0001)
        # if (i % 25 == 0):
        #     print(runge_kutt_table[i])

    t_axis = [j[0] for j in runge_kutt_table]
    x_axis = [j[1] * 100 for j in runge_kutt_table]
    phi_axis = [j[2] / 3.14 * 180 for j in runge_kutt_table]
    V_axis = [j[3] for j in runge_kutt_table]
    w_axis = [j[4] for j in runge_kutt_table]

    plt.plot(t_axis, x_axis)
    plt.show()

    plt.plot(t_axis, phi_axis)
    plt.show()