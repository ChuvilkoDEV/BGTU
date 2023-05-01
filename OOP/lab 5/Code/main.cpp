#include <iostream>
#include "vector"
#include "windows.h"

using namespace std;



int main() {
  SetConsoleOutputCP(CP_UTF8);
  vector<depositor> dep = {{"Владимир", "20.10.1999", 10000,  5},
                           {"Даниил",   "01.01.2007", 312341, 7}};
  vector<creditor> cred = {{"Людмила", "08.07.2022", 10000,  5},
                           {"Даниил",  "01.03.2023", 312341, 7}};
  vector<organization> org = {{"Бистро", "15.05.2020", 1231231, 1},
                              {"ООО \"Как у бабушки\"", "01.03.2023", 58378645734, 2},};
  Users users(dep, cred, org);

  users.Output();
  cout << "\n\n Поиск по дате: 01.03.2023\n";
  users.searchByDate("01.03.2023");
  return 0;
}
