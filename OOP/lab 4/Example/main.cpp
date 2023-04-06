#include <iostream>

class Car {
  public:
  float speed;
  float mass;
  char name[10];

  Car(char *n) {
    for (int i = 0; i < 10; i++)
      name[i] = n[i];
    speed = 10;
  };

  void printCar() {
    std::cout << name << ' ' << speed << std::endl;
  };

  friend const Car operator+(Car &a1, const Car &a2) {
    Car a3(a1.name);
    a3.speed = a1.speed + a2.speed;
    return a3;
  }

};

int main() {
  char *name = new char[10];
  name = "nissan";
  Car almera(name);
  almera.printCar();

  name = "nissan1";
  Car almera1(name);
  almera1.printCar();

  name = "nissan2";
  Car almera2(name);
  almera2.printCar();

  almera = almera1 + almera2;
  almera.printCar();

  almera1 = "ababab";
  almera.printCar();
  return 0;
}
