/*
*
*
*
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // for(int *p = begin(ia);p != end(ia);++p)
  // 	cout << *p << " ";
  for (int(&p)[4] : ia)
    for (int &q : p) cout << q << " ";
  cout << endl;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++) cout << ia[i][j] << " ";
  cout << endl;
  for (int m = 0; m < 3; m++)
    for (int n = 0; n < 4; n++) cout << *(*(ia + m) + n) << " ";
  cout << endl;
  // for(const int (&w)[4] = ia[0]; w != ia+3;w++)
  // 	// for(const int *h =w[0];h !=)
  // 	for(const int *h = *w; h != *w+3;++h)
  // 		cout << *h << " ";
  // 	cout << endl;
  // for( int(&row)[4] = ia; row != ia+3; row++)
  // for(const int *h =w[0];h !=)
  for (int(*row)[4] = ia; row != ia + 3; row++)
    for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
  cout << endl;
  return 0;
}