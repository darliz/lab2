#pragma once
#include <string>
#include <vector>
#include "SolvePoly.h"

class Student {
public:
    Student(std::string name) : name_(name) {}
    virtual std::vector<double> solve(double a, double b, double c) const = 0;
    std::string getName() const { return name_; }
private:
    std::string name_;
};

class BadStudent : public Student {
public:
    BadStudent(std::string name) : Student(name) {}
    std::vector<double> solve(double a, double b, double c) const override {
        return { 0.0, 0.0 };
    }
};

class NormStudent : public Student {
public:
    NormStudent(std::string name) : Student(name) {}
    std::vector<double> solve(double a, double b, double c) const override {
        if (rand() % 2) {
            return { 0.0, 0.0 };
        }
        else {
            return SolvePoly(a, b, c);
        }
    }
};

class GoodStudent : public Student {
public:
    GoodStudent(std::string name) : Student(name) {}
    std::vector<double> solve(double a, double b, double c) const override {
        return SolvePoly(a, b, c);
    }
};
