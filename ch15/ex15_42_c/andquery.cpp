#include "andquery.h"
#include <algorithm>

QueryResult
And_Query::eval(const TextQuery& text) const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);

	auto ret_lines = std::make_shared<std::set<line_no>>();

    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(req(), ret_lines, left.get_file());
}
