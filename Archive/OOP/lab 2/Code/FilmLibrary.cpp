#include "FilmLibrary.h"

#include <utility>

void Movie::outputTitle() const {
  cout << "Title: " << title << "\t";
}

void Movie::outputGenres() {
  cout << "Genres: ";
  for (auto &i: genres)
    cout << i << ", ";
}

void Movie::outputReviews() {
  cout << "Reviews: ";
  for (auto &i: reviews)
    cout << i << ", ";
}

void Movie::output() {
  outputTitle();
  outputGenres();
  outputReviews();
  cout << endl;
}

Movie::Movie(string title, int duration, vector<string> genres) {
  this->title = std::move(title);
  this->durationSec = duration;
  this->genres = std::move(genres);
}

Movie::Movie() {
  this->title = "";
  this->durationSec = 0;
  this->genres = {};
}

void Explorer::outputMovies() {
  for (auto &i: movies)
    i.output();
}

Movie Finder::findByTitle() {
  string title;
  cout << "Введите название фильма: ";
  cin >> title;
  for (auto &i: movies)
    if (i.title == title)
      return i;

  Movie error("Not Find", 0, {});
  cout << "Не найдено фильма с веденным названием";
  return error;
}

void Finder::findByGenres() {
  string genre;
  cout << "Введите ваш любимый жанр: ";
  cin >> genre;
  vector<Movie> res(0);
  for (auto &i: movies)
    for (auto &j: i.genres)
      if (genre == j) {
        res.push_back(i);
        break;
      }

  if (!res.empty())
    for (auto &i: res)
      i.output();
  else
    cout << "Фильмов с вашим любимым жанром не обнаружено :(";
  cout << "\n\n";
}


void Player::play() {
  Movie m = findByTitle();
  if (m.title != "Not Find") {
    cout << "Приятного просмотра!\n";
    Sleep(m.durationSec * 1000);
    cout << "Поздравляем!!! Вы посмотрели фильм: " << m.title
         << ". Оставьте отзыв:\n";
    string review;
    cin >> review;
    m.reviews.push_back(review);
  }
}

void Upload::upload() {
  Movie movie;
  cout << "Введите название вашего ролика: ";
  cin >> movie.title;
  cout << "Ну и названице... Хорошо, сколько длиться этот ваш фильм: ";
  cin >> movie.durationSec;
  cout
    << "С длительностью определились. К каким жанрам вы отнесете свою киноленту (Если вы закончили ввод, напишите \"Все\"):";
  while (true) {
    string genre;
    cin >> genre;
    if (genre == "\"Все\"" || genre == "Все") {
      cout
        << "Ну вот и все. Вы добавили свой... Шедевр! Мы благодарны вам.\n\n";
      break;
    }
    movie.genres.push_back(genre);
  }
  movies.push_back(movie);
}

