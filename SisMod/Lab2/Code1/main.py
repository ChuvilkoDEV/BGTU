from matplotlib import pyplot as plt
import math

k1 = 20000
k2 = 10000
k3 = 40000
n1 = 1
n2 = 0.5
n3 = 0.7
m = 10
g = 9.8

t0 = 0
x0 = 1
y0 = -1
Vx = 0
Vy = 0


def func_Vy(t, x, y, V, w):
  c1 = (pow(n1 + abs(x), 2) + y * y) ** (1 / 2)
  c2 = (pow(n2 + abs(y), 2) + x * x) ** (1 / 2)
  c3 = (pow(n3 + abs(y), 2) + x * x) ** (1 / 2)

  return (m * g
          + k1 * (c1 - n1) * y / c1
          - k2 * (c2 - n2) * (n2 + y) / c2
          - k3 * (c3 - n3) * (n3 + y) / c3) / m

print(func_Vy(0, 0, -2, 0, 0))

def func_Vx(t, x, y, V, w):
  c1 = (pow(n1 + abs(x), 2) + y * y) ** (1 / 2)
  c2 = (pow(n2 + abs(y), 2) + x * x) ** (1 / 2)
  c3 = (pow(n3 + abs(y), 2) + x * x) ** (1 / 2)

  return (- k1 * (c1 - n1) * (n1 + x) / c1
          - k2 * (c2 - n2) * x / c2
          - k3 * (c3 - n3) * x / c3) / m

func_Vx(0, 442.32014600796293, -443.42502025331765, 0, 0)

def runge_kutt_step(runge_kutt_table: list, step: float):
  current_row = runge_kutt_table[-1]
  next_row = [None] * 5
  runge_kutt_table.append(next_row)

  next_row[0] = current_row[0] + step
  next_row[1] = current_row[1] + current_row[3] * step
  next_row[2] = current_row[2] + current_row[4] * step

  k1dV = func_Vx(current_row[0], current_row[1], current_row[2], current_row[3], current_row[4])
  k2dV = func_Vx(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3] + step * k1dV / 2,
                 current_row[4])
  k3dV = func_Vx(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3] + step * k2dV / 2,
                 current_row[4])
  k4dV = func_Vx(current_row[0] + step, current_row[1], current_row[2], current_row[3] + step * k3dV, current_row[4])

  next_row[3] = current_row[3] + step / 6 * (k1dV + 2 * k2dV + 2 * k3dV + k4dV)

  k1dw = func_Vy(current_row[0], current_row[1], current_row[2], current_row[3], current_row[4])
  k2dw = func_Vy(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3],
                 current_row[4] + step * k1dw / 2)
  k3dw = func_Vy(current_row[0] + step / 2, current_row[1], current_row[2], current_row[3],
                 current_row[4] + step * k2dw / 2)
  k4dw = func_Vy(current_row[0] + step, current_row[1], current_row[2], current_row[3], current_row[4] + step * k3dw)

  next_row[4] = current_row[4] + step / 6 * (k1dw + 2 * k2dw + 2 * k3dw + k4dw)


if __name__ == '__main__':
  # t, x, y, Vx, Vy
  runge_kutt_table = [
    [t0, x0, y0, Vx, Vy]
  ]

  for i in range(50000):
    runge_kutt_step(runge_kutt_table, 0.0001)
    if (i % 100 == 0):
       print(runge_kutt_table[i], '  ', func_Vx(*runge_kutt_table[i]), '  ', func_Vy(*runge_kutt_table[i]))

  t_axis = [j[0] for j in runge_kutt_table]
  x_axis = [j[1] * 100 for j in runge_kutt_table]
  y_axis = [j[2] * 100 for j in runge_kutt_table]
  V_axis = [j[3] for j in runge_kutt_table]
  w_axis = [j[4] for j in runge_kutt_table]

  plt.plot(t_axis, x_axis)
  plt.show()

  plt.plot(t_axis, y_axis)
  plt.show()