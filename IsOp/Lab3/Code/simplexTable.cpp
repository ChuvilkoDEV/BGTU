#include "simplexTable.h"

SimplexTable SimplexTable::findArtificialBasis() {
  SimplexTable processedTable;
  this->copy(processedTable);
  //Делаем свободные члены положительными
  for (int row = 0; row < processedTable.matrix.getRows() - 1; row++) {
    if (processedTable.matrix.getData(row, processedTable.matrix.getColumns() - 1)
        < 0) {
      processedTable.matrix.multiplyRowBy(row, -1);
    }
  }
  //Определяем значения коэффициентов целевой ф-ции подзадачи
  for (int column = 0; column < processedTable.matrix.getColumns(); column++) {
    float sum = 0;
    for (int row = 0; row < processedTable.matrix.getRows() - 1; row++) {
      sum += processedTable.matrix.getData(row, column);
    }
    processedTable.matrix.setData(processedTable.matrix.getRows() - 1, column, -
      sum);
  }
  //Вводим искусственные переменные
  for (int row = 0; row < processedTable.matrix.getRows() - 1; row++) {
    processedTable.matrix.pushBackZeroColumn();
    processedTable.matrix.setData(row, processedTable.matrix.getColumns() - 1, 1);
  }
  //Применяем симплекс метод
  bool hasSolution = true;
  bool isSolution = false;
  while (hasSolution && !isSolution) {
    processedTable = processedTable.simplexMethodStep(hasSolution, isSolution);
  }
  //Приводим к подходящему для решения исходной задачи виду
  processedTable.matrix.deleteRow(processedTable.matrix.getRows() - 1);
  for (int i = 0; i < processedTable.matrix.getRows(); i++) {
    processedTable.matrix.deleteColumn(processedTable.matrix.getColumns() - 1);
  }
  vector<float> targetRow(this->matrix.getRow(this->matrix.getRows() - 1));
  processedTable.matrix.addNewRow(targetRow);
  return processedTable;
}