#include <iostream>
#include <string>
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

  public:
  Player(std::string playerName, int playerSpeed,
         int playerShootingAccuracy, int playerStamina)
    : name(playerName), speed(playerSpeed),
      shootingAccuracy(playerShootingAccuracy), stamina(playerStamina) {}

  // Геттеры и сеттеры для атрибутов игрока

  std::string getName() const {
    return name;
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
      result = "Home Team Win";
    } else if (homeScore < awayScore) {
      result = "Away Team Win";
    } else {
      result = "Draw";
    }
  }

  // Другие методы матча
};

// Класс Турнир
class Tournament {
  private:
  std::vector<Team> teams;
  std::vector<Match> matches;
  std::vector<std::string> results;

  public:
  // Метод для добавления команды в турнир
  void addTeam(const Team &team) {
    teams.push_back(team);
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

  // Другие методы турнира
};

// Класс Стадион
class Stadium {
  private:
  std::string name;
  int capacity;
  std::string weather;
  std::vector<Match> upcomingMatches;

  public:
  Stadium(std::string stadiumName, int stadiumCapacity,
          std::string stadiumWeather)
    : name(stadiumName), capacity(stadiumCapacity), weather(stadiumWeather) {}

  // Геттеры и сеттеры для атрибутов стадиона

  std::string getName() const {
    return name;
  }

  int getCapacity() const {
    return capacity;
  }

  std::string getWeather() const {
    return weather;
  }

  // Методы для работы со списком предстоящих матчей

  void addUpcomingMatch(const Match &match) {
    upcomingMatches.push_back(match);
  }

  void removeUpcomingMatch(const Match &match) {
    // Логика удаления матча из списка предстоящих матчей
    // ...
  }

  std::vector<Match> getUpcomingMatches() const {
    return upcomingMatches;
  }

  // Другие методы стадиона
};

class PlayerMarket {
  private:
  std::vector<Player> availablePlayers;

  public:
  PlayerMarket() {
    generateAvailablePlayers();
  }

  void generateAvailablePlayers() {
    availablePlayers.clear();
    for (int i = 0; i < 10; i++)
      availablePlayers.push_back(Player::generateRandomPlayer());
  }

  void displayAvailablePlayers() const {
    for (const Player &player: availablePlayers) {
      std::cout << "Name: " << player.getName() << ", Speed: "
                << player.getSpeed()
                << ", Shooting Accuracy: " << player.getShootingAccuracy()
                << ", Stamina: " << player.getStamina() << std::endl;
    }
  }

  void purchasePlayer(int playerIndex, Team &team) {
    if (playerIndex >= 0 && playerIndex < availablePlayers.size()) {
      Player purchasedPlayer = availablePlayers[playerIndex];
      team.addPlayer(purchasedPlayer);

      // Удаление приобретенного игрока из доступных игроков на рынке
      availablePlayers.erase(availablePlayers.begin() + playerIndex);
      std::cout << "Player " << purchasedPlayer.getName()
                << " purchased successfully!" << std::endl;
    } else {
      std::cout << "Invalid player index." << std::endl;
    }
  }
};

class PlayerTeam : public Team {
  private:
  int money;
  int gamesWon;
  int gamesLost;

  public:
  PlayerTeam(const std::string &teamName)
    : Team(teamName), money(100000), gamesWon(0), gamesLost(0) {}

  int getMoney() const {
    return money;
  }

  int getGamesWon() const {
    return gamesWon;
  }

  int getGamesLost() const {
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

  // ...
};


void clearConsole()
{
  std::system("cls");
}

int main() {
  PlayerMarket market;  // Создание объекта рынка игроков
  std::cout << "Введите название вашей команды: ";
  std::string teamName;
  std::cin >> teamName;
  PlayerTeam myTeam(teamName);    // Создание объекта команды игрока

  std::string menuName = "main";
  while (true) {
    std::cout << "Доступные команды:\n";
    std::cout << "1. Посмотреть список доступных игроков\n";
    std::cout << "2. Купить игрока\n";
    std::cout << "3. Продать игрока\n";
    std::cout << "4. Записаться на турнир\n";
    std::cout << "5. Выйти из программы\n";
    std::cout << "Введите команду: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
      // Показать список доступных игроков
      market.displayAvailablePlayers();
    } else if (choice == 2) {
      // Покупка игрока
      std::cout << "Введите имя игрока, которого хотите купить: ";
      std::string playerName;
      std::cin >> playerName;

      if (market.buyPlayer(playerName, myTeam)) {
        std::cout << "Игрок " << playerName << " успешно куплен!\n";
      } else {
        std::cout << "Ошибка: Игрок " << playerName << " не найден или недостаточно денег.\n";
      }
    } else if (choice == 3) {
      // Продажа игрока
      std::cout << "Введите имя игрока, которого хотите продать: ";
      std::string playerName;
      std::cin >> playerName;

      if (myTeam.sellPlayer(playerName, market)) {
        std::cout << "Игрок " << playerName << " успешно продан!\n";
      } else {
        std::cout << "Ошибка: Игрок " << playerName << " не найден в вашей команде.\n";
      }
    } else if (choice == 4) {
      // Запись на турнир
      Tournament tournament;  // Создание объекта турнира
      tournament.addTeam(myTeam);  // Добавление команды игрока в турнир

      std::cout << "Вы успешно записались на турнир!\n";
      // Дополнительная логика для проведения турнира и отображения результатов
      break;  // Выход из цикла
    } else if (choice == 5) {
      // Выход из программы
      std::cout << "Программа завершена.\n";
      break;  // Выход из цикла
    } else {
      std::cout << "Неверный выбор команды. Попробуйте снова.\n";
    }

    std::cout << "\n";
  }

  return 0;
}