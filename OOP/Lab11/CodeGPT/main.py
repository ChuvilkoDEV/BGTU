def find_matrices(data):
    matrices = data.strip().split('\n\n')  # Разделяем данные на матрицы
    matching_matrices = []

    for matrix_str in matrices:
        matrix_rows = matrix_str.strip().split('\n')  # Разделяем матрицу на строки
        matrix = []
        for row in matrix_rows:
            row_values = list(map(int, row.split()))  # Преобразуем элементы строки в числа
            matrix.append(row_values)
        matching_matrices.insert(matrix)
    return matching_matrices


# Пример входных данных
input_data = '''
1 1 1 2
3 1 1 4
2 1 5 3

1 1 1 2
3 1 3 4
2 1 5 3

1 2 1 1
1 2 1 5
1 1 5 4
'''

matching_matrices = find_matrices(input_data)

# Вывод результатов
print("Matching Matrices:")
matrixSums = []
for matrix in matching_matrices:
    row_sums = [sum(row) for row in matrix]  # Вычисляем суммы элементов в каждой строке
    matrixSums.append(row_sums)

print(matrixSums)