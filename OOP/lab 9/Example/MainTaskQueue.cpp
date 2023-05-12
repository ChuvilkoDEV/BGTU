#include "MainTaskQueue.h"
#include "limits"

MainTaskQueue::MainTaskQueue() {
  queue = std::queue<Task>();
  taskQueues = std::vector<TaskQueue *>();
  queueBuffer = std::vector<Task *>();
}

void MainTaskQueue::addQueue(TaskQueue *newQueue) {
  taskQueues.push_back(newQueue);
  queueBuffer.resize(queueBuffer.size() + 1);
  newQueue->outputPlace = &queueBuffer[queueBuffer.size() - 1];
}

bool MainTaskQueue::getTaskFromBuffer(int index, Task &task) {
  if (queueBuffer[index] == nullptr)
    return false;
  else {
    task = *queueBuffer[index];
    queueBuffer[index] = nullptr;
    return true;
  }
}

bool MainTaskQueue::getNextTask(Task &task) {
  Task *earliestTask = queueBuffer[0];
  int earliestTaskIndex = 0;
  for (int i = 1; i < queueBuffer.size(); i++) {
    if ((earliestTask == nullptr && queueBuffer[i] != nullptr) ||
        ((earliestTask != nullptr && queueBuffer[i] != nullptr) &&
         queueBuffer[i]->getCreationTime() < earliestTask->getCreationTime())) {
      earliestTask = queueBuffer[i];
      earliestTaskIndex = i;
    }
  }
  queueBuffer[earliestTaskIndex] = nullptr;
  task = *earliestTask;
  if (earliestTask == nullptr)
    return false;
  else
    return true;
}