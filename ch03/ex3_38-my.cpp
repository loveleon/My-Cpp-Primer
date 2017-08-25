#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1("im string one");
  string str2("im string two");
  if (str1 == str2)
    std::cout << "str1 == str2" << std::endl;
  else
    std::cout << "str1 != str2" << std::endl;

  int i = 0;
  bool cequal = false;
  char cstr1[10] = {'i', 'm', 's', 't', '1'};
  char cstr2[10] = {'i', 'm', 's', 't', '1'};
  while (cstr1[i] && cstr2[i]) {
    if (cstr1[i] == cstr2[i])
      cequal = true;
    else {
      cequal = false;
      break;
    }
    i++;
  }
  std::cout << "cstr1 == cstr2 is " << boolalpha << (true == cequal)
            << std::endl;
  return 0;
}