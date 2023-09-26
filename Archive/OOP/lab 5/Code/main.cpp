#include <iostream>
#include "vector"
#include "windows.h"

using namespace std;

class Client {
  protected:
  string name;
  int percent;
  long long id;
  public:
  virtual void outputInfo() {
    cout << "Имя: " << name;
    cout << "\nДата открытия счета: " << datetime;
    cout << "\nПроцентная ставка: " << percent;
    cout << "\nУникальный идентификатор: " << id;
  }

  string datetime;
};

class entrepreneur : public Client {
  private:
  long long amount;
  public:
  entrepreneur(string name, string datetime, int percent, long long id,
               long long amount) {
    this->name = name;
    this->datetime = datetime;
    this->percent = percent;
    this->id = id;
    this->datetime = datetime;
    this->amount = amount;
  }
  void outputInfo() override {
    Client::outputInfo();
    cout << "\nСостояние счета: " << amount<< "\n\n";
  }
};

class depositor : public Client {
  private:
  unsigned long long deposit;
  public:
  depositor(string name, string datetime, int percent, long long id,
            long long deposit) {
    this->name = name;
    this->datetime = datetime;
    this->percent = percent;
    this->id = id;
    this->deposit = deposit;
  }
  void outputInfo() override {
    Client::outputInfo();
    cout << "\nДепозит: " << deposit << "\n\n";
  }
};

class creditor : public Client {
  private:
  unsigned long long debt;
  public:
  creditor(string name, string datetime, int percent, long long id,
            long long debt) {
    this->name = name;
    this->datetime = datetime;
    this->percent = percent;
    this->id = id;
    this->debt = debt;
  }
  void outputInfo() override {
    Client::outputInfo();
    cout << "\nЗадолженность: " << debt << "\n\n";
  }
};

class Terminal : public Client {
  private:
  vector<Client> data;
  public:
  vector<Client> *getClientList() {
    return &data;
  }
  void addClient(Client c) {
    data.push_back(c);
  }
  void searchByDate(string date) {
    for (auto &i: data)
      if (i.datetime == date)
        i.outputInfo();
  }
};


int main() {
  SetConsoleOutputCP(CP_UTF8);
  depositor vladimir = {"Владимир", "20.10.1999", 5, 0, 5000};
  depositor daniil = {"Даниил",   "01.01.2007", 8, 1, 312341};
  creditor luda = {"Людмила", "08.07.2022", 10,  2, 10000};
  creditor dima = {"Дмитрий", "01.03.2023", 11,  3, 312341};
  entrepreneur bistro = {"Бистро", "01.03.2023", 3,  4, 1231231};
  entrepreneur babula = {"ООО \"Как у бабушки\"", "01.03.2023", 3,  5, 58378645734};
  Terminal t;
  t.addClient(vladimir);
  t.addClient(daniil);
  t.addClient(luda);
  t.addClient(dima);
  t.addClient(bistro);
  t.addClient(babula);

  cout << "\n\n Поиск по дате: 01.03.2023\n";
  t.searchByDate("01.03.2023");
  return 0;
}
