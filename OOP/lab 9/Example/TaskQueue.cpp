#include "TaskQueue.h"
#include <chrono>
#include <thread>
#include <mutex>

TaskQueue::TaskQueue() {
  queue = std::queue<Task *>();
}

void TaskQueue::addTask(Task task) {
  mtx.lock();
  queue.emplace(&task);
  mtx.unlock();
}

bool TaskQueue::getNextTask(Task &Task) {
  mtx.lock();
  if (queue.empty()) {
    mtx.unlock();
    return false;
  } else {
    Task = *queue.front();
    queue.pop();
    mtx.unlock();
    return true;
  }
}

void TaskQueue::mainLoop() {
  while (true) {
    mtx.lock();
    if (*outputPlace == nullptr && !queue.empty()) {
      *outputPlace = queue.front();
      queue.pop();
    }
    mtx.unlock();
    this_thread::sleep_for(chrono::milliseconds(10));
  }
}
