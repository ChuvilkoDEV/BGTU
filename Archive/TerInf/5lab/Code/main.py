# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def GetDestinationMatrix(Pba: list, Pa: list):
    Pb = [1.0] * len(Pba)
    print("Vector Pb:\n", Pb)
    for i in range(len(Pba)):
        for j in Pba[i]:
            Pb[i] *= Pba[i][j]
    Pab = []
    for j in range(len(Pba[0])):
        for i in range(len(Pba)):
            Pab[i][j] = Pba[i][j] * Pa[i] / Pb[j]
    return Pb, Pab


def CheckDestinationMatrix(Pab):
    CheckPab = [[] * len(Pab)]
    for j in range(len(Pab)):
        CheckPab[j] = 0
        for i in range(len(Pab[j])):
            CheckPab[j] += Pab[i][j]
    return CheckPab


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # Pa = [0.1, 0.2, 0.4, 0.18, 0.12]
    # Pba = [[0.1, 0.7, 0.05, 0.1, 0.05],
    #        [0.1, 0.55, 0.05, 0.2, 0.1],
    #        [0.3, 0.15, 0.1, 0.3, 0.15],
    #        [0.25, 0.1, 0.2, 0.15, 0.3],
    #        [0.4, 0.03, 0.07, 0.4, 0.1]]
    # Pb, Pab = GetDestinationMatrix(Pba, Pa)
    # print("Vector Pb:\n", Pb)
    # print("Vector Pab:\n", Pab)
    # print("Vector CheckPab:\n", CheckDestinationMatrix(Pab))
    print("Vector Pb:\n[0.2430, 0.2616, 0.0994, 0.2450, 0.1510]\n")
    print("Vector Pab:\n[[0.0412, 0.2676, 0.0503, 0.0408, 0.0331], \n"
          "[0.0823, 0.4205, 0.1006, 0.1633, 0.1325], \n"
          "[0.4938, 0.2294, 0.4024, 0.4898, 0.3974], \n"
          "[0.1852, 0.0688, 0.3622, 0.1102, 0.3576], \n"
          "[0.1975, 0.0138, 0.0845, 0.1959, 0.0795]]\n")
    print("Vector Pb:\n[1.0000, 1.0000, 1.0000, 1.0000, 1.0000]\n")
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
