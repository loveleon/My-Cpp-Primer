#include <fstream>
#include <iostream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "queryhistory.h"
/*
int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    return 0;
}
*/
int main()
{
//    Query q = Query("fiery") & Query("bird") | Query("wind");
//*
    std::ifstream fin("../ex15_42_b/test.txt");
	TextQuery text(fin);
	Query_History history;
	Query q0("Alice");
	Query q1("hair");
	Query q2("Daddy");

	history.add_query(q0);
	history.add_query(q1);
	history[0] = history[0] | q2;

	auto result = history[0].eval(text);
	print(std::cout, result);
//*/
    return 0;
}
