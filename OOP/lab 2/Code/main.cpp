#include "FilmLibrary.h"

int main() {
  vector<Movie> m = {
    {"Первый",    10, {"a", "b"}},
    {"Второй",    23, {"b", "c"}},
    {"Третий",    1,  {"a", "c"}},
    {"Четвертый", 2,  {"c", "d"}}
  };
  Explorer::movies = m;

  while (true) {
    Explorer::outputMovies();
    cout << "Введите:\n "
            "ft - поиск фильма по названию\n"
            "fg - поиск фильма по вашему любимому жанру\n"
            "play - воспроизведение фильма по названию\n"
            "u - загрузка своего фильма\n"
            "q - выход из программы\n"
            "Так что же вы собираетесь делать? ";
    string input;
    cin >> input;
    if (input == "ft")
      Finder::findByTitle();
    else if (input == "fg")
      Finder::findByGenres();
    else if (input == "play")
      Player::play();
    else if (input == "u")
      Upload::upload();
    else if (input == "q")
      break;
  }

  return 0;
}
