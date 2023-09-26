#ifndef CODE_FILMLIBRARY_H
#define CODE_FILMLIBRARY_H

#include <iostream>
#include <utility>
#include <vector>
#include <windows.h>

using namespace std;

struct Movie {
  public:
  Movie();
  Movie(string title, int duration, vector<string> genres);

  string title;
  int durationSec;
  vector<string> genres;
  vector<string> reviews;

  void outputTitle() const;

  void outputGenres();

  void outputReviews();

  void output();
};

class Explorer {
  public:
  static vector<Movie> movies;

  static void outputMovies();
};

class Finder : public Explorer {
  public:
  static Movie findByTitle();
  static void findByGenres();
};

class Player : public Finder {
  public:
  static void play();
};

class Upload : public Explorer {
  public:
  static void upload();
};


#endif //CODE_FILMLIBRARY_H
