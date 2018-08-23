#include <fstream>
#include <iostream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"
using std::cout;
using std::endl;

int main()
{
    std::ifstream fin("../ex15_42_c/test.txt");
	TextQuery text(fin);
	auto q = ~Query("Alice");

	auto result = q.eval(text);
    std::cout << "#1";
	print(cout, result);
	cout << endl;
    std::cout << "#2";
	print(cout, result, -3, 5);
	cout << endl;
    std::cout << "#3";
	print(cout, result, 3, 5);
	cout << endl;
    std::cout << "#4";
	print(cout, result, 3, 20);
	cout << endl;

    return 0;
}
