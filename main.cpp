#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> day_one_parse_file() {
    std::vector<int> expense_report;
    std::fstream fileStream;
    fileStream.open("..\\aoc_2020\\input.txt");

    assert(fileStream.is_open());

    int entry{0};
    while(fileStream >> entry) {
        expense_report.push_back(entry);
    }

    fileStream.close();

    return expense_report;
}

int day_one_part_one(const std::vector<int>& expense_report) {
    for (const auto& entry: expense_report) {
        const auto diff = 2020 - entry;
        if (std::find(expense_report.cbegin(), expense_report.cend(), diff) != expense_report.cend()) {
            assert(entry + diff == 2020);
            return entry * diff;
        }
    }

    return -1;
}

int day_one_part_two(const std::vector<int>& expense_report) {
    for (const auto& entry: expense_report) {
        const auto diff = 2020 - entry;
        for (const auto& entry2: expense_report) {
            const auto diff2 = diff - entry2;
            if (std::find(expense_report.cbegin(), expense_report.cend(), diff2) != expense_report.cend()) {
                    assert(entry + entry2 + diff2 == 2020);
                    return entry * entry2 * diff2;
            }
        }
    }

    return -1;
}

int main()
{
    const auto& expense_report = day_one_parse_file();
    std::cout << "Day One Part One: " << day_one_part_one(expense_report) << "\n"; // 290784 is the right answer ;)
    std::cout << "Day One Part Two: " << day_one_part_two(expense_report) << "\n"; // 177337980 is the right answer ;)
}
