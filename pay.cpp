#include "person.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int readData(Person employees[],int size);
void writeData(Person employees[],int size);
int main(){
  int size =0; //array size
  Person employees[20];
  size = readData(employees,20);
  writeData(employees,size);
  return 0;
}

int readData(Person employees[],int size){
  ifstream readFile;
  readFile.open("input.txt");
  string fname;
  string lname;
  float hours;
  float rate;
  int i =0;
  if(!readFile){
    cerr << "Error: File can't be open"<< endl;
    exit(1);
  }
  while (!readFile.eof()) {
    readFile >> fname;
    readFile >> lname;
    readFile >> hours;
    readFile >> rate;
    employees[i].setFirstName(fname);
    employees[i].setLastName(lname);
    employees[i].setHoursWorked(hours);
    employees[i].setPayRate(rate);
    i++;
    readFile >> ws; 
  }
  readFile.close();
}

void writeData(Person employees[],int size){
  ofstream writeFile;
  writeFile.open("output2.txt");
  int i =0;
  while (i < (size)) {
    writeFile << employees[i].fullName() << " ";
    writeFile << employees[i].totalPay()<< " ";
    writeFile << endl;
    i++;
    
  }
  writeFile.close();

} 
/* how to compile the program in terminal
g++ -o Pay Pay.cpp
./Pay
*/
