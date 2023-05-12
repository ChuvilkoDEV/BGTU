#ifndef INC_11_TASK_H
#define INC_11_TASK_H

#include <string>
#include <vector>

using namespace std;

std::vector<std::string> customSplit(std::string str, char separator);

enum TaskType {
  CreateFile,
  DeleteFile,
  RenameFile,
  OutputFile,
  AddRecordToFile,
  DeleteRecordFromFile,
};

class Task {
private:
  TaskType type;
  std::vector<std::string> arguments;
  time_t timeCreated;
public:
  Task();

  Task(TaskType inputType, std::string inputArguments);

  Task(TaskType inputType, std::vector<std::string> arguments);

  TaskType getTaskType() {
    return type;
  }

  vector<string> getArguments();

  time_t getCreationTime();
};

#endif //INC_11_TASK_H