#include <iostream>
#include <Windows.h>
#include <mutex>
#include <string>

using namespace std;
mutex mtx;

DWORD WINAPI vowelCount(LPVOID lpParam){
  string str = "aeiouAEIOU";
  auto s = *(string*)lpParam;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    //mtx.lock();
    Sleep(10);
    if (str.find(s[i]) != string::npos)
      count++;
    cout << "func: vowelCount. Count = " << count << endl;
    //mtx.unlock();
  }
}

DWORD WINAPI deleteVowel(LPVOID lpParam) {
  auto s = *(string*)lpParam;
  string str = "aeiouAEIOU";
  const std::string empty;
  for (int i = 0; i < s.size(); i++) {
    //mtx.lock();
    if (str.find(s[i]) != string::npos && rand() & 1)
      s.replace(i, 1, empty);
    cout << "func: deleteVowel. string = " << s << endl;
    //mtx.unlock();
  }
}

int main()
{
  string str = "abbbabbbaaaaa";
// Создаем два потока
  HANDLE hThread1 = CreateThread(NULL, 0, deleteVowel, &str, 0, NULL);
  HANDLE hThread2 = CreateThread(NULL, 0, vowelCount, &str, 0, NULL);
// Ждем, пока оба потока завершат свою работу
  WaitForSingleObject(hThread1, INFINITE);
  WaitForSingleObject(hThread2, INFINITE);
// Закрываем дескрипторы потоков
  CloseHandle(hThread1);
  CloseHandle(hThread2);
  return 0;
}