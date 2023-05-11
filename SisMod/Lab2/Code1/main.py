from matplotlib import pyplot as plt
import math
from const import *

def func_Vy(t, x, y, V, w):
  c1 = ((n1 + abs(x)) ** 2 + y ** 2) ** (1 / 2)
  c2 = ((n2 + abs(y)) ** 2 + x ** 2) ** (1 / 2)
  c3 = ((n3 + abs(y)) ** 2 + x ** 2) ** (1 / 2)
  p2 = -1 if (y > 2 * n2 or 0 < y < n2) else 1
  r2 = abs(c2 - 3 * n2) if y > n2 else c2 - n2
  p3 = -1 if (y > 0 or -n3 > y > -2 * n3) else 1
  r3 = abs(c3 - 3 * n3) if y < -n3 else c3 - n3
  return (m * g
          - k1 * (c1 - n1) * y / c1
          + k2 * p2 * r2
          + k3 * p3 * r3
   ) / m


def func_Vx(t, x, y, V, w):
  c1 = (pow(n1 + abs(x), 2) + y * y) ** (1 / 2)
  c2 = (pow(n2 + abs(y), 2) + x * x) ** (1 / 2)
  c3 = (pow(n3 + abs(y), 2) + x * x) ** (1 / 2)
  p1 = -1 if (x > 0 or -n1 > x > -2 * n1) else 1
  r1 = abs(c1 - 3 * n1) if x < -n1 else c1 - n1
  return (k1 * p1 * r1
          - k2 * (c2 - n2) * x / c2
          - k3 * (c3 - n3) * x / c3
          ) / m

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

  for i in range(int(time / step)):
    runge_kutt_step(runge_kutt_table, step)
    # if (i % 100 == 0):
    #   print(runge_kutt_table[i], '  ', func_Vx(*runge_kutt_table[i]), '  ', func_Vy(*runge_kutt_table[i]))

  t_axis = [j[0] for j in runge_kutt_table]
  x_axis = [j[1] * 100 for j in runge_kutt_table]
  y_axis = [j[2] * 100 for j in runge_kutt_table]
  V_axis = [j[3] for j in runge_kutt_table]
  w_axis = [j[4] for j in runge_kutt_table]

  plt.plot(t_axis, x_axis)
  plt.show()

  plt.plot(t_axis, y_axis)
  plt.show()
