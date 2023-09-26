#include <stdio.h>
#include <windows.h>
#include "Table/Table.h"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  // сохранение элементов для таблицы из файла
  element arrayOfElements[256];
  unsigned amountElementsForTable = 0;
  char filename[] = "Keys_and_values_for_Table.txt";
  FILE *f = fopen(filename, "r"); // открытие файла
  // запись из файла в массив элементов
  while (fscanf(f, "%s %u",
                arrayOfElements[amountElementsForTable].data.key,
                &arrayOfElements[amountElementsForTable].data.s) != EOF) {
    amountElementsForTable++;
  }
  fclose(f);
  // инициализация таблицы
  Table table;
  initTable(&table);
  // заполнение таблицы элементами
  for (int i = 0; i < amountElementsForTable; i++) {
    putTable(&table, &arrayOfElements[i]);
  }
  // проходим по тексту для задания
  char exerciseFile[] = "Text_for_exercise_ASD.txt";
  FILE *exercise = fopen(exerciseFile, "r");
  char s[256];
  BaseType convertNumbersArray[30];
  unsigned i = 0;
  unsigned counter = 0;
  // проходимся до конца файла
  while (!feof(exercise)) {
    // считываем по одному слову
    fscanf(exercise, "%s", s);
    // если нашли число, берём его из таблицы по ключу
    if (readTable(table, &convertNumbersArray[i], s)) {
      // необходимо сложить найденные числа в одно число
      counter += convertNumbersArray[i]->data.s; // складываем и запоминаем
      i++;
    } else { // если слово не число
      if (counter != 0) { // если что-то насчитали
        printf("%d ", counter); // выводим сумму найденных чисел в цифровом эквиваленте
        counter = 0;
      }
      printf("%s ", s); // выводим слово
    }
  }
  return 0;
}
