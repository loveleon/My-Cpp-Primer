
#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"

int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    return 0;
}
