#ifndef INC_11_TASKQUEUE_H
#define INC_11_TASKQUEUE_H
#include "Task.h"
#include <utility>
#include <queue>
#include <time.h>
#include "mutex"
class TaskQueue
{
public:
  Task **outputPlace;
  TaskQueue();
  std::mutex mtx;
  std::vector<TaskQueue*> queues;
  std::queue<Task*> queue;
  void addTask(Task task);
  bool getNextTask(Task& Task);
  void mainLoop();
};
#endif //INC_11_TASKQUEUE_H