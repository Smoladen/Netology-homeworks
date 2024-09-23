#include "sql_query_builder.h"

int main() {

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    const std::string result = query_builder.BuildQuery();
    std::cout << result << std::endl;
    return 0;
}
