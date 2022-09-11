# include <stdio.h>
# include <string.h>

# define MAX_RECIPE_LENGTH 100

int getRecipe(char *recipe, int *nBread, int *nSausage, int *
nCheese) {
  int nIngredients = strlen(recipe);
  *nBread = 0;
  *nSausage = 0;
  *nCheese = 0;
  for (int ingredientIndex = 0; ingredientIndex < nIngredients;
       ingredientIndex++) {
    switch (recipe[ingredientIndex]) {
      case 'B':
        (*nBread)++;
        break;
      case 'S':
        (*nSausage)++;
        break;
      case 'C':
        (*nCheese)++;
        break;
    }
  }
  return 0;
}

long long isEnoughMoney_(int n, int count, int price, long long i) {
  long long cost = (i * n - count) * price;
  if (cost > 0)
    return cost;
  return 0;
}

int isEnoughMoney(int nBread, int nSausage, int nCheese,
                  int countBread, int countSausage, int countCheese,
                  int priceBread, int priceSausage, int priceCheese,
                  long long countMoney, long long i) {
  return (isEnoughMoney_(nBread, countBread, priceBread, i) +
          isEnoughMoney_(nSausage, countSausage, priceSausage, i) +
          isEnoughMoney_(nCheese, countCheese, priceCheese, i)) <= countMoney;
}

long long binCountBurger(int nBread, int nSausage, int nCheese,
                         int countBread, int countSausage, int countCheese,
                         int priceBread, int priceSausage, int priceCheese,
                         long long countMoney) {
  long long left = 0;
  long long right = (long long) 1e13;
  while (left + 1 < right) {
    long long middle = left + (right - left) / 2;
    int f = isEnoughMoney(nBread, nSausage, nCheese, countBread, countSausage,
                          countCheese, priceBread, priceSausage, priceCheese,
                          countMoney, middle);
    if (f)
      left = middle;
    else
      right = middle;
  }
  return left;
}


int main() {
  char recipe[MAX_RECIPE_LENGTH + 1];

  int nBread, nSausage, nCheese;
  gets(recipe);
  getRecipe(recipe, &nBread, &nSausage, &nCheese);
  int countBread, countSausage, countCheese,
    priceBread, priceSausage, priceCheese;
  long long countMoney;
  scanf("%d %d %d %d %d %d %lld", &countBread, &countSausage,
        &countCheese, &priceBread, &priceSausage, &priceCheese, &countMoney);

  printf("%lld",
         binCountBurger(nBread, nSausage, nCheese, countBread, countSausage,
                        countCheese, priceBread, priceSausage, priceCheese,
                        countMoney));

  return 0;
}
