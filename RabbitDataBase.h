#include "Rabbit.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


class RabbitDataBase{
  private:
    enum {MAX_RABBITS = 50};
    Rabbit rabbitArray[MAX_RABBITS];
    int numRabbits;
  public:
    RabbitDataBase();
    void read();
    void save();
    void print(ostream &out, bool printIndex);
    void remove();
    void add();
};