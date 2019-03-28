#include <iostream>
#include "Soundex.h"

using namespace std;

int main(int argc, char** argv)
{
    string str;
    Soundex soundex;
    cout<< "Enter the string" << endl;
    cin >> str;
    str = soundex.encoded(str);
    cout<< str << endl;

    return 0;
}