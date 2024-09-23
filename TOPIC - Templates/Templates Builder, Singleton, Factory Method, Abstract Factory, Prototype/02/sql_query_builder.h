#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

class SqlSelectQueryBuilder {
public:

    SqlSelectQueryBuilder& AddColumn(const std::string& col) noexcept {
        if (select.empty()) {
            select += "SELECT " + col;
        } else {
            select += ", " + col;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        for (const auto& col : columns) {
            AddColumn(col);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) noexcept {
        if (from.empty()) {
            from += " FROM " + table;
        } else {
            std::cout << "Таблица уже выбрана!\n";
        }
        return *this;
    }


    SqlSelectQueryBuilder& AddWhere(const std::string& col, const std::string& condition) noexcept {
        if (where.empty()) {
            where += " WHERE " + col + "=" + condition;
        } else {
            where += " AND " + col + "=" + condition;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& pair : kv) {
            AddWhere(pair.first, pair.second);
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

