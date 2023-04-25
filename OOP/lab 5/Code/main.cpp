#include <iostream>
#include "vector"
#include "windows.h"

using namespace std;

class depositor {
  public:
  string name;
  string datetime;
  long long deposit;
  int percent;

  depositor(string name, string datetime, long long deposit, int percent) {
    this->name = name;
    this->datetime = datetime;
    this->deposit = deposit;
    this->percent = percent;
  }

  void Output() const {
    cout << "name: " << name << "  datetime: " << datetime << "  deposit: "
         << deposit << "  percent: " << percent << endl;
  }
};

class creditor {
  public:
  string name;
  string datetime;
  long long credit;
  int percent;

  creditor(string name, string datetime, long long credit, int percent) {
    this->name = name;
    this->datetime = datetime;
    this->credit = credit;
    this->percent = percent;
  }

  void Output() const {
    cout << "name: " << name << "  datetime: " << datetime << "  credit: "
         << credit << "  percent: " << percent << endl;
  }
};

class organization {
  public:
  string name;
  string datetime;
  long long amount;
  int id;

  organization(string name, string datetime, long long amount, int id) {
    this->name = name;
    this->datetime = datetime;
    this->amount = amount;
    this->id = id;
  }

  void Output() const {
    cout << "name: " << name << "  datetime: " << datetime << "  amount: "
         << amount << "  id: " << id << endl;
  }
};

class Users {
  vector<depositor> depositors;
  vector<creditor> creditors;
  vector<organization> organizations;

  public:
  void Output() {
    cout << "depositors: \n";
    for (auto &i: depositors)
      i.Output();

    cout << "creditors: \n";
    for (auto &i: creditors)
      i.Output();

    cout << "organizations: \n";
    for (auto &i: organizations)
      i.Output();
  }

  void searchByDate(string datetime) {
    for (auto &i: depositors)
      if (i.datetime == datetime)
        i.Output();
    for (auto &i: creditors)
      if (i.datetime == datetime)
        i.Output();
    for (auto &i: organizations)
      if (i.datetime == datetime)
        i.Output();
  }

  Users(
    vector<depositor> &depositors,
    vector<creditor> &creditors,
    vector<organization> &organizations
  ) {
    this->depositors = depositors;
    this->creditors = creditors;
    this->organizations = organizations;
  }
};

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
