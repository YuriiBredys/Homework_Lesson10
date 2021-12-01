#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "pupil_details.h"
using namespace std;

bool is_number(wstring s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(static_cast<unsigned char>(s[i])) == false && s[i] != '-')
            return false;

    return true;
}

int main()
{
    string path_in = "marks.txt";
    string path_out = "averageMarks.txt";
    wstring save_string;
    wfstream input, output;
    vector<pupil_details> pupil;

    input.open(path_in, fstream::in);

    if(!input.is_open())
    {
        cout << "Error with input file" << endl;
    }
    else
    {
        while (getline(input, save_string, static_cast<wchar_t>('\n')))
        {
            wstringstream stream(save_string);
            wstring word;
            vector<wstring> names;
            vector<int> marks;

            while (getline(stream, word, static_cast<wchar_t>(' ')))
            {
                if(is_number(word))
                {
                    marks.push_back(stoi(word));
                }
                else
                {
                    names.push_back(word);
                }
            }

            pupil_details item(names, marks);
            pupil.push_back(item);
        }
    }

    input.close();

    output.open(path_out, fstream::out);

    if(!output.is_open())
    {
        cout << "Error with output file"<< endl;
    }
    else
    {
        for (auto item : pupil)
        {
            output << item << endl;
        }
    }

    output.close();

    return 0;
}
