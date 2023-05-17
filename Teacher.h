#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "SolvePoly.h"

class Teacher {
public:
    Teacher(std::vector<std::string> const& students) : students_(students), progress_(students.size(), { 0, 0 }) {}
    void getAnswer(std::string name, std::vector<double> const& poly, std::vector<double> const& ans) {
        std::vector<double> answer = SolvePoly(poly[0], poly[1], poly[2]);
        size_t id = (find(students_.begin(), students_.end(), name) - students_.begin());

        progress_[id][1]++;
        if (ans == answer)
            progress_[id][0]++;
    }
    void printTable(std::ostream& file) {
        for (size_t i = 0; i < students_.size(); i++)
            file << students_[i] << "\t" << progress_[i][0] << "\t" << progress_[i][1] << std::endl;
    }
private:
    std::vector<std::vector<size_t>> progress_;
    std::vector<std::string> students_;
};