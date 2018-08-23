#include "orquery.h"
QueryResult
OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(req(), ret_lines, left.get_file());
}
