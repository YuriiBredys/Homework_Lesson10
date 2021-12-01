#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class pupil_details
{
public:
    pupil_details(const vector<wstring>& input_name, const vector<int>& input_marks);

    void make_record(const vector<wstring>& input_name, const vector<int>& input_marks);

    friend wostream& operator<<(wostream& out, const pupil_details& temp);
private:
    double average_marks_;
    wstring name_;
};
