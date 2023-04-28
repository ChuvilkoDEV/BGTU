#include <mutex>
#include <thread>
#include <iostream>
#include <windows.h>

void add(int a[10], std::mutex &m){
  while (1)
  {
    m.lock();
    for (int i = 0; i < 10; i++)
      a[i] = a[i] + 1;
    Sleep(1000);
    m.unlock();
  }
}

void minus(int a[10], std::mutex &m){
  while (1){
    m.lock();
    for (int i = 0; i < 10; i++)
      a[i] = a[i] - 1;
    Sleep(1000);
    m.unlock();
  }
}

void output(int a[10], std::mutex &m){
  int p = 0;
  while (1)
  {
    m.lock();
    for (int i = 0; i < 10; i++)
    {
      std::cout << a[i] << " ";
      std::cout << std::endl;
      std::cout << char(8);
      if (p == 0) { std::cout << "-"; p = 1; }
      else
      if (p == 1) { std::cout << "+"; p =0; }
      Sleep(500);
    }
    std::cout << std::endl;
    m.unlock();
  }
}

int main(){
  int a[10];
  std::mutex m;
  setlocale(0, "RUS");
  for (int i = 0; i < 10; i++)
    a[i] = i;

  std::thread th2(minus, a, ref(m));  //1 поток
  std::thread th1(add, a, ref(m));    //2 поток

  std::thread th3(output, a, ref(m)); //поток вывода

  th1.detach();
  th2.detach();
  th3.detach();

  std::cout << "finish";
  system("pause");
  return 0;
}
