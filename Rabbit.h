#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Rabbit{
  private:
    enum {MAX_CHAR_LEN = 100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
  public:
    Rabbit();
    void remove();
    void print(ostream &out);
    void readFromUser();
    void readFromFile(ifstream &inFile);
    bool validity();
};