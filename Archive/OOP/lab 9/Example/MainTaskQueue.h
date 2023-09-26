#ifndef INC_11_MAINTASKQUEUE_H
#define INC_11_MAINTASKQUEUE_H
#include <queue>
#include <thread>
#include <mutex>
#include "Task.h"
#include "TaskQueue.h"
class MainTaskQueue
{
public:
 std::mutex mtx;
 std::queue<Task> queue;
 std::vector<TaskQueue*> taskQueues;
 std::vector<Task*> queueBuffer;
 MainTaskQueue();
 void addQueue(TaskQueue *newQueue);
 bool getTaskFromBuffer(int index, Task &task);
 bool getNextTask(Task &task);
};
#endif //INC_11_MAINTASKQUEUE_H