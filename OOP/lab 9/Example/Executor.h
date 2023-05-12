#ifndef INC_11_EXECUTOR_H
#define INC_11_EXECUTOR_H
#include "Task.h"
#include "fstream"
#include "cstdio"
#include "iostream"
#include "MainTaskQueue.h"
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
class Executor
{
public:
  MainTaskQueue *mainTaskQueue;
  Executor(MainTaskQueue *newMainTaskQueue);
  void executeTask(Task task);
  void createFile(vector<string> arguments);
  void deleteFile(vector<string> arguments);
  void renameFile(vector<string> arguments);
  void outputFile(vector<string> arguments);
  void addRecordToFile(vector<string> arguments);
  void deleteRecordFromFile(vector<string> arguments);
  void mainLoop();
};
#endif //INC_11_EXECUTOR_H