#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib> // Для генерации случайных чисел
#include <ctime> // Для инициализации генератора случайных чисел
#include <map>
#include <cstdlib>


// Класс Генератор случайных чисел
class RandomNumberGenerator {
public:
  static int generateRandomNumber(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
      std::srand(static_cast<unsigned int>(std::time(nullptr)));
      initialized = true;
    }

    return min + std::rand() % (max - min + 1);
  }
};

// Класс Игрок
class Player {
private:
  std::string name;
  int speed;
  int shootingAccuracy;
  int stamina;
  int price;

public:
  Player(std::string playerName, int playerSpeed,
         int playerShootingAccuracy, int playerStamina)
          : name(std::move(playerName)), speed(playerSpeed),
            shootingAccuracy(playerShootingAccuracy), stamina(playerStamina) {
    price = (speed * 10 + shootingAccuracy * 10 + stamina * 10) *
            RandomNumberGenerator::generateRandomNumber(50, 150) / 100;
  }

  // Геттеры и сеттеры для атрибутов игрока

  std::string getName() const {
    return name;
  }

  int getPrice() const {
    return price;
  }

  int getSpeed() const {
    return speed;
  }

  int getShootingAccuracy() const {
    return shootingAccuracy;
  }

  int getStamina() const {
    return stamina;
  }

  static Player generateRandomPlayer() {
    std::string playerName = "Player";
    int speed = RandomNumberGenerator::generateRandomNumber(50, 100);
    int shootingAccuracy = RandomNumberGenerator::generateRandomNumber(60, 100);
    int stamina = RandomNumberGenerator::generateRandomNumber(70, 100);

    return Player(playerName, speed, shootingAccuracy, stamina);
  }

  static Player generateRandomPlayer(std::pair<int, int> Stats) {
    std::string playerName = "Player";
    int speed = RandomNumberGenerator::generateRandomNumber(Stats.first, Stats.second);
    int shootingAccuracy = RandomNumberGenerator::generateRandomNumber(Stats.first, Stats.second);
    int stamina = RandomNumberGenerator::generateRandomNumber(Stats.first, Stats.second);

    return {playerName, speed, shootingAccuracy, stamina};
  }
};

// Класс Команда
class Team {
private:
  std::string name;
  std::vector<Player> players;
  std::vector<std::string> matchResults;

public:
  Team(std::string teamName)
          : name(std::move(teamName)) {}

  // Метод для добавления игрока в команду
  void addPlayer(const Player &player) {
    players.push_back(player);
  }

  // Методы для получения информации о команде и игроках

  std::string getName() const {
    return name;
  }

  std::vector<Player> getPlayers() const {
    return players;
  }

  void generateRandomTeam(int numPlayers) {
    players.clear();
    // Генерация случайных характеристик для каждого игрока
    for (int i = 0; i < numPlayers; i++)
      players.push_back(Player::generateRandomPlayer());
  }

  void generateRandomTeam(int numPlayers,
                          std::pair<int, int> Stats) {
    players.clear();
    // Генерация случайных характеристик для каждого игрока
    for (int i = 0; i < numPlayers; i++)
      players.push_back(Player::generateRandomPlayer(Stats));
  }

  // Метод для вывода средних показателей игроков
  void printAveragePlayerStats() const {
    std::cout << "Average Player Stats for Team " << name << ":" << std::endl;
    int totalSpeed = 0;
    int totalShootingAccuracy = 0;
    int totalStamina = 0;

    for (const Player &player: players) {
      totalSpeed += player.getSpeed();
      totalShootingAccuracy += player.getShootingAccuracy();
      totalStamina += player.getStamina();
    }

    int numPlayers = players.size();
    double averageSpeed = static_cast<double>(totalSpeed) / numPlayers;
    double averageShootingAccuracy = static_cast<double>(totalShootingAccuracy) / numPlayers;
    double averageStamina = static_cast<double>(totalStamina) / numPlayers;

    std::cout << "Average Speed: " << averageSpeed << std::endl;
    std::cout << "Average Shooting Accuracy: " << averageShootingAccuracy << std::endl;
    std::cout << "Average Stamina: " << averageStamina << std::endl;
  }
};

// Класс Матч
class Match {
private:
  Team homeTeam;
  Team awayTeam;
  int homeScore;
  int awayScore;
  std::string result;

public:
  Match(Team team1, Team team2)
          : homeTeam(std::move(team1)), awayTeam(std::move(team2)), homeScore(0),
            awayScore(0) {}

  // Геттеры и сеттеры для атрибутов матча
  [[nodiscard]] Team getHomeTeam() const {
    return homeTeam;
  }

  Team getAwayTeam() const {
    return awayTeam;
  }

  int getHomeScore() const {
    return homeScore;
  }

  int getAwayScore() const {
    return awayScore;
  }

  std::string getResult() const {
    return result;
  }

  void setHomeScore(int score) {
    homeScore = score;
  }

  void setAwayScore(int score) {
    awayScore = score;
  }

  void setResult(const std::string &matchResult) {
    result = matchResult;
  }

  void calculateMatchResult() {
    // Получение игроков из команд
    std::vector<Player> homePlayers = homeTeam.getPlayers();
    std::vector<Player> awayPlayers = awayTeam.getPlayers();

    homeScore = 0;
    for (const Player &homePlayer: homePlayers) {
      // Расчет способности игрока влиять на результаты матча
      int playerAbility =
              (homePlayer.getSpeed() + homePlayer.getShootingAccuracy() +
               homePlayer.getStamina()) / 3;

      // Генерация случайного числа для определения результата действия игрока
      int randomNumber = RandomNumberGenerator::generateRandomNumber(0, 100);

      if (randomNumber <= playerAbility) {
        // Действие игрока успешно - гол для домашней команды
        homeScore++;
      }
    }

    awayScore = 0;
    for (const Player &awayPlayer: awayPlayers) {
      // Расчет способности игрока влиять на результаты матча
      int playerAbility =
              (awayPlayer.getSpeed() + awayPlayer.getShootingAccuracy() +
               awayPlayer.getStamina()) / 3;

      // Генерация случайного числа для определения результата действия игрока
      int randomNumber = RandomNumberGenerator::generateRandomNumber(0, 110);

      if (randomNumber <= playerAbility) {
        // Действие игрока успешно - гол для домашней команды
        awayScore++;
      }
    }

    // Обновление счета и результата матча
    if (homeScore > awayScore) {
      result = homeTeam.getName();
    } else if (homeScore < awayScore) {
      result = awayTeam.getName();
    } else {
      result = "Draw";
    }
  }
};

// Класс Турнир
class Tournament {
private:
  std::string name;
  std::vector<Team> teams;
  std::vector<Match> matches;
  std::vector<std::string> results;
  std::pair<int, int> stats;


public:
  Tournament(std::string &difficult,
             std::pair<int, int> stats) : name(difficult), stats(std::move(stats)) {}

  // Метод для добавления команды в турнир
  void addTeam(const Team &team) {
    teams.push_back(team);
  }

  std::string getName() {
    return name;
  }

  std::pair<int, int> getAverageStats() {
    return stats;
  }

  std::vector<std::string> getResults() const {
    return results;
  }

  // Метод для создания расписания матчей
  void createSchedule() {
    int numTeams = teams.size();
    int numMatches = numTeams * (numTeams -
                                 1); // Общее количество матчей без учета домашней/гостевой команды

    for (int i = 0; i < numTeams - 1; i++) {
      for (int j = i + 1; j < numTeams; j++) {
        // Создание матча между командами i и j
        Match match(teams[i], teams[j]);
        matches.push_back(match);
      }
    }
  }

  // Метод для проведения матчей в турнире
  void playMatches() {
    results.clear();
    for (Match &match: matches) {
      match.calculateMatchResult();
      results.push_back(match.getResult());
    }
  }

  // Метод для генерации заданного количества команд со случайными характеристиками
  void generateRandomTeams(int numTeams) {
    teams.clear();
    for (int i = 0; i < numTeams; i++) {
      Team team("Team " + std::to_string(i + 1));
      team.generateRandomTeam(10, stats);
      teams.push_back(team);
    }
  }
};

// Класс Стадион
class Stadium {
private:
  int capacity;
  std::vector<Tournament> tournaments;

public:
  Stadium() {
    Tournament noobs((std::string &) "Низшая лига", (std::pair<int, int>) {10, 25});
    Tournament medium((std::string &) "Средняя лига", (std::pair<int, int>) {25, 50});
    Tournament pro((std::string &) "Высшая лига", (std::pair<int, int>) {50, 85});
    tournaments = {noobs, medium, pro};
  }

  // Геттеры и сеттеры для атрибутов стадиона
  int getCapacity() const {
    return capacity;
  }

  std::vector<Tournament> getTournaments() const {
    return tournaments;
  }

  void outputTournaments() {
    std::cout << "Available Tournaments:\n" << std::endl;
    for (Tournament &tournament : tournaments) {
      std::cout << tournament.getName() << ": " <<
      tournament.getAverageStats().first << " - " <<
      tournament.getAverageStats().second <<std::endl;
    }
  }
  // Другие методы стадиона
};

class PlayerTeam : public Team {
private:
  int money;
  int gamesWon;
  int gamesLost;

public:
  PlayerTeam(int teamMoney)
          : Team(""), money(teamMoney), gamesWon(0), gamesLost(0) {}

  [[nodiscard]] int getMoney() {
    return money;
  }

  [[nodiscard]] int getGamesWon() {
    return gamesWon;
  }

  [[nodiscard]] int getGamesLost() {
    return gamesLost;
  }

  void increaseMoney(int amount) {
    money += amount;
  }

  void decreaseMoney(int amount) {
    money -= amount;
  }

  void increaseGamesWon() {
    gamesWon++;
  }

  void increaseGamesLost() {
    gamesLost++;
  }
};

PlayerTeam player(10000);    // Создание объекта команды игрока
Stadium stadium();

class PlayerMarket {
private:
  static std::vector<Player> availablePlayers;

public:
  PlayerMarket() {
    generateAvailablePlayers();
  }

  void generateAvailablePlayers() {
    availablePlayers.clear();
    for (int i = 0; i < 10; i++)
      availablePlayers.push_back(Player::generateRandomPlayer());
  }

  static void displayAvailablePlayers() {
    for (const Player &availablePlayer: availablePlayers) {
      std::cout << "Name: " << availablePlayer.getName()
                << ", Speed: " << availablePlayer.getSpeed()
                << ", Accuracy: " << availablePlayer.getShootingAccuracy()
                << ", Stamina: " << availablePlayer.getStamina()
                << ", Price: " << availablePlayer.getPrice() << std::endl;
    }
  }

  static void purchasePlayer(int playerIndex, Team &team) {
    if (playerIndex >= 0 && playerIndex < availablePlayers.size()) {
      Player purchasedPlayer = availablePlayers[playerIndex];
      if (purchasedPlayer.getPrice() <= player.getMoney()) {
        team.addPlayer(purchasedPlayer);

        // Удаление приобретенного игрока из доступных игроков на рынке
        availablePlayers.erase(availablePlayers.begin() + playerIndex);
        std::cout << "Player " << purchasedPlayer.getName()
                  << " purchased successfully!" << std::endl;
      } else {
        std::cout << "Недостаточно денег.\n" << std::endl;
      }
    } else {
      std::cout << "Invalid player index.\n" << std::endl;
    }
  }
};

//void clearConsole() {
//  std::system("cls");
//}

void menuMain(std::string &menuName) {
  std::cout << "Доступные команды:\n";
  std::cout << "1. Рынок игроков\n";
  std::cout << "2. Посмотреть турниры\n";
  std::cout << "0. Выйти из программы\n";
  std::cout << "Введите команду: ";

  int choice;
  std::cin >> choice;
  clearConsole();
  if (choice == 1) {
    // Показать список доступных игроков
    PlayerMarket::displayAvailablePlayers();
    menuName = "market";
  } else if (choice == 2) {
    stadium().outputTournaments();
    menuName = "tournaments";
  } else if (choice == 0) {
    // Выход из программы
    std::cout << "Программа завершена.\n";
    exit(0);
  } else {
    std::cout << "Неверный выбор команды. Попробуйте снова.\n";
  }

  std::cout << "\n";
}

//void menuMarket() {
//  if (choice == 2) {
//    // Покупка игрока
//    std::cout << "Введите имя игрока, которого хотите купить: ";
//    std::string playerName;
//    std::cin >> playerName;
//
//    if (market.buyPlayer(playerName, myTeam)) {
//      std::cout << "Игрок " << playerName << " успешно куплен!\n";
//    } else {
//      std::cout << "Ошибка: Игрок " << playerName << " не найден или недостаточно денег.\n";
//    }
//  } else if (choice == 3) {
//    // Продажа игрока
//    std::cout << "Введите имя игрока, которого хотите продать: ";
//    std::string playerName;
//    std::cin >> playerName;
//
//    if (myTeam.sellPlayer(playerName, market)) {
//      std::cout << "Игрок " << playerName << " успешно продан!\n";
//    } else {
//      std::cout << "Ошибка: Игрок " << playerName << " не найден в вашей команде.\n";
//    }
//  }
//}


int main() {
  PlayerMarket market;  // Создание объекта рынка игроков
  std::cout << "Введите название вашей команды: ";
  std::string teamName;
  std::cin >> teamName;

  std::string menuName = "main";
  while (true) {
    if (menuName == "main")
      menuMain(menuName);
  }

  return 0;
}