#include "Executor.h"
#include "fstream"
#include "cstdio"
#include "iostream"
#include "MainTaskQueue.h"

Executor::Executor(MainTaskQueue *newMainTaskQueue) {
  mainTaskQueue = newMainTaskQueue;
}

void Executor::executeTask(Task task) {
  switch (task.getTaskType()) {
    case TaskType::CreateFile: {
      createFile(task.getArguments());
      break;
    }
    case TaskType::DeleteFile: {
      deleteFile(task.getArguments());
      break;
    }
    case TaskType::RenameFile: {
      renameFile(task.getArguments());
      break;
    }
    case TaskType::OutputFile: {
      outputFile(task.getArguments());
      break;
    }
    case TaskType::AddRecordToFile: {
      addRecordToFile(task.getArguments());
      break;
    }
    case TaskType::DeleteRecordFromFile: {
      deleteRecordFromFile(task.getArguments());
      break;
    }
    default:
      break;
  }
}

void Executor::createFile(vector<string> arguments) {
  ofstream newFile(arguments[0]);
  newFile.close();
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::deleteFile(vector<string> arguments) {
  const char *name = arguments[0].c_str();
  remove(name);
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::renameFile(vector<string> arguments) {
  const char *oldName = arguments[0].c_str();
  const char *newName = arguments[1].c_str();
  ::rename(oldName, newName);
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::outputFile(vector<string> arguments) {
  const char *name = arguments[0].c_str();
  string line;
  ifstream file(name);
  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  } else {
    cout << "Файл не существует\n";
  }
  file.close();
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::addRecordToFile(vector<string> arguments) {
  const char *name = arguments[0].c_str();
  ofstream file(name);
  if (file.is_open()) {
    file << arguments[1];
    file.close();
  } else {
    cout << "Файл не существует\n";
  }
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::deleteRecordFromFile(vector<string> arguments) {
  const char *name = arguments[0].c_str();
  ofstream file;
  file.open(name, ofstream::out | ofstream::trunc);
  file.close();
  this_thread::sleep_for(chrono::seconds(5));
}

void Executor::mainLoop() {
  while (true) {
    Task nextTask;
    bool hasNextTask = mainTaskQueue->getNextTask(nextTask);
    if (hasNextTask) {
      executeTask(nextTask);
    }
  }
}