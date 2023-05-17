#include "Students.h"
#include "Teacher.h"


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

vector<string> ReadStudents(ifstream& file) {
    vector<string> students;
    string name;

    while (file >> name)
        students.push_back(name);

    return students;
}

vector<vector<double>> ReadPoly(ifstream& file) {
    vector<vector<double>> polys;
    double a, b, c;

    while (file >> a >> b >> c)
        polys.push_back({ a, b, c });

    return polys;
}

vector<Student*> CreateStudents(vector<string> const& studentsNames) {
    vector<Student*> students(studentsNames.size());
    for (size_t i = 0; i < studentsNames.size(); i++) {
        int stType = rand() % 3;

        switch (stType)
        {
        case 0:
            students[i] = new BadStudent(studentsNames[i]);
            break;
        case 1:
            students[i] = new NormStudent(studentsNames[i]);
            break;
        case 2:
            students[i] = new GoodStudent(studentsNames[i]);
            break;
        }
    }

    return students;
}

void DeleteStudents(vector<Student*>& students) {
    for (auto& st : students)
        delete st;
}

void StartExam(Teacher& teacher, vector<Student*> const& students, vector<vector<double>> const& polys) {
    for (auto poly : polys)
        for (auto st : students)
            teacher.getAnswer(st->getName(), poly, st->solve(poly[0], poly[1], poly[2]));
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    ifstream stfile("students.txt"), polyfile("poly.txt");
    ofstream outfile("output.txt");

    vector<string> studentsList = ReadStudents(stfile);
    vector<vector<double>> polys = ReadPoly(polyfile);

    vector<Student*> students = CreateStudents(studentsList);
    Teacher teacher(studentsList);

    StartExam(teacher, students, polys);
    teacher.printTable(outfile);

    stfile.close();
    polyfile.close();
    outfile.close();

    return 0;
}