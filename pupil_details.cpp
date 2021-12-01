#include "pupil_details.h"

pupil_details::pupil_details(const vector<wstring>& input_name, const vector<int>& input_marks)
{
    make_record(input_name, input_marks);
}

void pupil_details::make_record(const vector<wstring>& input_name, const vector<int>& input_marks)
{
    wstring temp;

    for(auto item : input_name)
    {
        temp += item + static_cast<wchar_t>(' ');
    }

    this->name_ = temp;

    auto sum = 0;
    auto count = input_marks.size();
    double average;

    for (auto item : input_marks)
    {
        sum += item;
    }

    average = static_cast<double>(sum) / count;

    this->average_marks_ = average;
}

wostream& operator<<(wostream& out, const pupil_details& temp)
{
    return  out << temp.name_ << " " << temp.average_marks_;
}
