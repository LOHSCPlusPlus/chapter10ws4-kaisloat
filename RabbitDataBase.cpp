#include "RabbitDataBase.h"
#include <iostream>
#include <fstream>
#include "ReadUtils.h"

void RabbitDataBase::read(){
  ifstream rabbitFile("rabbits.txt");
  numRabbits = 0;
  while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
    rabbitArray[numRabbits].readFromFile(rabbitFile);
    numRabbits++;
  }
}

RabbitDataBase::RabbitDataBase(){
  numRabbits = 0;
  read();
}

void RabbitDataBase::print(ostream &out, bool printIndex){
  for (int index = 0; index < MAX_RABBITS; ++index) {
    if (rabbitArray[index].validity()) {
       if (printIndex) {
          out << "Index " << index << ": ";
        }
        rabbitArray[index].print(out);
      } 
  }
}

void RabbitDataBase::save(){
  ofstream out("rabbits.txt");
  print(out, false);
}

void RabbitDataBase::remove(){
  int index = 0;
  do {
    index = readInt("Enter an index to remove between 0 and 50: ");
  }while (index < 0 || index > MAX_RABBITS);
  rabbitArray[index].remove();
}

void RabbitDataBase::add(){
  ifstream inFile("rabbits.txt");
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].validity() == false) {
            rabbitArray[index].readFromFile(inFile);
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
}