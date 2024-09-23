#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& col) {
        if (select.empty()) {
            select += "SELECT " + col;
        } else {
            select += ", " + col;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        if (from.empty()) {
            from += " FROM " + table;
        } else {
            std::cout << "Table is chosen\n";
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& col, const std::string& condition) {
        if (where.empty()) {
            where += " WHERE " + col + "=" + condition;
        } else {
            where += " AND " + col + "=" + condition;
        }
        return *this;
    }

    std::string BuildQuery() {
        if (select.empty()) {
            select = "SELECT *";
        }

        std::ostringstream query;
        query << select << from << where << ";";
        return query.str();
    }

private:
    std::string select = "";
    std::string from = "";
    std::string where = "";
};


