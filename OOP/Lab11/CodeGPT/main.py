def find_matrices(data):
    matrices = data.strip().split('\n\n')  # Разделяем данные на матрицы
    matching_matrices = []

    for matrix_str in matrices:
        matrix_rows = matrix_str.strip().split('\n')  # Разделяем матрицу на строки
        matrix = []
        for row in matrix_rows:
            row_values = list(map(int, row.split()))  # Преобразуем элементы строки в числа
            matrix.append(row_values)

        row_sums = [sum(row) for row in matrix]  # Вычисляем суммы элементов в каждой строке

    return matching_matrices


# Пример входных данных
input_data = '''
1 2 3
4 5 6
7 8 9

1 2 3
4 5 6
7 8 10

2 2
2 2

1 2 3
4 5 6
'''

matching_matrices = find_matching_matrices(input_data)

# Вывод результатов
print("Matching Matrices:")
for matrix in matching_matrices:
    print(matrix)
    print()