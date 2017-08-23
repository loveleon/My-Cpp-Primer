#include <iostream>
#include <cstring>
using namespace std;

// int main(int argc, char *argv[]) {
//   char arra[5] = {'a', 'b', 'c', 'd', 'e'};
//   char arrb[5] = {'f', 'g', 'h'};
//   char arrc[10] = {0};
//   strcpy(arrc, arra);
//   strcpy(arrc + strlen(arra), arrb);
//   // strcat(arrc, '\0');
//   std::cout << "arrc:" << arrc << std::endl;
//   return 0;
// }
const char str1[] = "hello";
const char str2[] = "world";
int main() {
  constexpr size_t new_size = strlen(str1) + strlen(" ") + strlen(str2) + 1;
  char str3[new_size];
  strcpy(str3, str1);
  strcat(str3, " ");
  strcat(str3, str2);

  std::cout << "new str3:" << str3 << std::endl;
  return 0;
}