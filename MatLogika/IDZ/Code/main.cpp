#include <iostream>
#include <vector>

using namespace std;

void BrainFuckInterpreter(vector<char> &acc, char *cpu) {
  unsigned int j = 0;
  int brc = 0;
  for (int i = 0; i < acc.size(); ++i) {
    if(acc[i] == '>') j++;
    if(acc[i] == '<') j--;
    if(acc[i] == '+') cpu[j]++;
    if(acc[i] == '-') cpu[j]--;
    if(acc[i] == '.') cout << cpu[j];
    if(acc[i] == ',') cin >> cpu[j];
    if(acc[i] == '[')
    {
      if(!cpu[j])
      {
        ++brc;
        while(brc)
        {
          ++i;
          if (acc[i] == '[') ++brc;
          if (acc[i] == ']') --brc;
        }
      }else continue;
    }
    else if(acc[i] == ']')
    {
      if(!cpu[j])
      {
        continue;
      }
      else
      {
        if(acc[i] == ']') brc++;
        while(brc)
        {
          --i;
          if(acc[i] == '[') brc--;
          if(acc[i] == ']') brc++;
        }
        --i;
      }
    }
  }
}

int main() {
  std::cout << "Input Brainfuck code: \n";
  char cpu[30000];
  std::vector<char> acc;
  char ch = getchar();
  while (ch != '\n') {
    acc.push_back(ch);
    ch = getchar();
  }
  cout << "\n";
  BrainFuckInterpreter(acc, cpu);
  return 0;
}
