#include "Task.h"

std::vector<std::string> customSplit(std::string str, char separator) {
  std::vector<std::string> strings;
  int startIndex = 0, endIndex = 0;
  for (int i = 0; i <= str.size(); i++) {
    // If we reached the end of the word or the end of the input.
    if (str[i] == separator || i == str.size()) {
      endIndex = i;
      std::string temp;
      temp.append(str, startIndex, endIndex - startIndex);
      strings.push_back(temp);
      startIndex = endIndex + 1;
    }
  }
  return strings;
}

Task::Task(TaskType inputType, std::string inputArguments) {
  timeCreated = time(NULL);
  type = inputType;
  arguments = customSplit(inputArguments, ' ');
}

Task::Task(TaskType inputType, std::vector<std::string> inputArguments) {
  type = inputType;
  arguments = inputArguments;
}

vector<string> Task::getArguments() {
  return arguments;
}

time_t Task::getCreationTime() {
  return timeCreated;
}

Task::Task() {
  type = TaskType::CreateFile;
  arguments = {};
}