#include <iostream>
#include <vector>

#define DAYS_IN_WEEK 7

struct kitty {
  long long fish;
  long long rabbit;
  long long chicken;
};

enum catEatingToday {
  fish,
  rabbit,
  chicken
};

#define CALENDAR {fish, rabbit, chicken, fish, \
chicken, rabbit, fish}

void operator>>(std::istream &in, kitty &k) {
  in >> k.fish >> k.rabbit >> k.chicken;
}

void operator<<(std::ostream &out, kitty &k) {
  out << k.fish << ' ' << k.rabbit << ' ' << k.chicken << '\n';
}

void createFoodCalendar(kitty *foodCalendar) {
  foodCalendar->fish = 0;
  foodCalendar->rabbit = 0;
  foodCalendar->chicken = 0;
  catEatingToday calendar[] = CALENDAR;
  for (int i = 0; i < DAYS_IN_WEEK; i++) {
    foodCalendar[i + 1] = foodCalendar[i];
    if (calendar[i] == fish)
      foodCalendar[i + 1].fish += 1;
    else if (calendar[i] == rabbit)
      foodCalendar[i + 1].rabbit += 1;
    else
      foodCalendar[i + 1].chicken += 1;
  }
}

long long min(long long a, long long b) {
  return a < b ? a : b;
}

long long min(long long a, long long b, long long c) {
  return min(min(a, b), c);
}

long long max(long long a, long long b) {
  return a > b ? a : b;
}

long long max(long long a, long long b, long long c) {
  return min(min(a, b), c);
}

kitty initializingStructKitty(
  long long fishFood, long long rabbitStew, long long chickenChops
) {
  return (kitty) {fishFood, rabbitStew, chickenChops};
}

bool isEnoughFood(kitty foodRemained, kitty needFood) {
  if (
    foodRemained.fish >= needFood.fish &&
    foodRemained.rabbit >= needFood.rabbit &&
      foodRemained.chicken >= needFood.chicken
    )
    return true;
  else
    return false;
}

long long countDays(kitty *foodCalendar, kitty nFoods) {
  kitty foodInWeek = foodCalendar[DAYS_IN_WEEK];
  long long minWeeksFood = min(
    nFoods.fish / foodInWeek.fish,
    nFoods.rabbit / foodInWeek.rabbit,
    nFoods.chicken / foodInWeek.chicken
  );

  kitty foodRemained = initializingStructKitty(
    nFoods.fish - foodInWeek.fish * minWeeksFood,
    nFoods.rabbit - foodInWeek.rabbit * minWeeksFood,
    nFoods.chicken - foodInWeek.chicken * minWeeksFood
  );

  long long maxOverflowDays = 0;
  for (int i = 0; i <= DAYS_IN_WEEK; i++) {
    for (int j = 0; j <= DAYS_IN_WEEK; j++) {
      if (i < j) {
        kitty needFood = initializingStructKitty(
          foodCalendar[j].fish - foodCalendar[i].fish,
          foodCalendar[j].rabbit - foodCalendar[i].rabbit,
          foodCalendar[j].chicken - foodCalendar[i].chicken
        );

        if (isEnoughFood(foodRemained, needFood))
          maxOverflowDays = max(maxOverflowDays, (long long) (j - i));
      }
      else if (j < i) {
        kitty needFood = initializingStructKitty(
          foodInWeek.fish + foodCalendar[j].fish - foodCalendar[i].fish,
          foodInWeek.rabbit + foodCalendar[j].rabbit - foodCalendar[i].rabbit,
          foodInWeek.chicken + foodCalendar[j].chicken - foodCalendar[i].chicken
        );
        if (isEnoughFood(foodRemained, needFood))
          maxOverflowDays = max(maxOverflowDays, (long long) (j + DAYS_IN_WEEK - i));
      }
    }
  }
  return DAYS_IN_WEEK * minWeeksFood + maxOverflowDays;
}

int main() {
  kitty foodCalendar[DAYS_IN_WEEK + 1];
  createFoodCalendar(foodCalendar);
  kitty nFoods;
  std::cin >> nFoods;

  std::cout << countDays(foodCalendar, nFoods);

  return 0;
}