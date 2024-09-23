#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder query_builder;


    query_builder.AddColumns({"name", "phone", "email"});

    query_builder.AddFrom("students");

    std::map<std::string, std::string> conditions = {{"id", "42"}, {"name", "John"}, {"age", "18"}};
    query_builder.AddWhere(conditions);

    const std::string result = query_builder.BuildQuery();
    std::cout << result << std::endl;

    return 0;
}
