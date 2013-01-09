#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const double MIN_GRADE = 4.5;

struct Student {
  int id;
  string name;
  string faculty;
  double grade;
};

bool Accept(Student& s) {
  if ((s.faculty == "B" || s.faculty == "K") 
      && s.grade >= MIN_GRADE) {
    return true;
  } else {
    return false;
  }
}

int main() {
  Student x;
  x.id = 1;
  x.name = "Dima";
  x.faculty = "B";
  x.grade = 4.7;
  
  if (Accept(x))
    cout << "Yahooo!" << endl;
    
  return 0;
}


