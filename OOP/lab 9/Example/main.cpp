#include <iostream>
#include "MainTaskQueue.h"
#include "Executor.h"
#include "Task.h"
#include "TaskQueue.h"
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int main() {
  MainTaskQueue mainTaskQueue = MainTaskQueue();
  TaskQueue taskQueue1;
  TaskQueue taskQueue2;
  vector<string> arguments1 = {"File1"};
  Task newTask1 = {TaskType::CreateFile, arguments1};
  taskQueue1.addTask(newTask1);
  vector<string> arguments2 = {"File1", "Some Record"};
  Task newTask2 = {TaskType::AddRecordToFile, arguments2};
  taskQueue2.addTask(newTask2);
  vector<string> arguments3 = {"File2"};
  Task newTask3 = {TaskType::CreateFile, arguments3};
  taskQueue2.addTask(newTask3);
  vector<string> arguments4 = {"File1"};
  Task newTask4 = {TaskType::DeleteRecordFromFile, arguments4};
  taskQueue1.addTask(newTask4);
  vector<string> arguments5 = {"File1"};
  Task newTask5 = {TaskType::DeleteFile, arguments5};
  taskQueue2.addTask(newTask4);
  mainTaskQueue.addQueue(&taskQueue1);
  mainTaskQueue.addQueue(&taskQueue2);
  Executor executor(&mainTaskQueue);
  thread input1([&taskQueue1]() { taskQueue1.mainLoop(); });
  thread input2([&taskQueue2]() { taskQueue2.mainLoop(); });
  thread executorThread([&executor]() { executor.mainLoop(); });
  input1.join();
  input2.join();
  executorThread.join();
}
