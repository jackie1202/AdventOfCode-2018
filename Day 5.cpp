#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>
#include <stdlib.h>
#include <set>
#include <cctype>
#include <iomanip>
using namespace std;

int remove(string &txt, char &c)
{
    for(auto it = txt.begin(); it != txt.end(); )
    {
        if(*it == c || *it == c-32)
        {
            auto it2 = txt.erase(it);
            it = it2;
        }
        else ++it;

    }
    return  txt.size();
}

int remove2(string &txt)
{
    // 32
    bool Flg = false;
while(!Flg)
{
    Flg = true;
    for(auto it = txt.begin(); it != txt.end(); )
    {
        auto next = ++it;
        --it;
        if(abs(*next-*it)== 32)
        {
            auto it2 = txt.erase(it,++next);
            it = it2;
            Flg = false;
        }
        else ++it;
    }
    //cout << txt.size() << endl;
}


    return txt.size();

}


int main() {
    ifstream readFile("../input.txt");
    if(readFile.is_open()) cout << "ok" << endl;

    string txt, tmp;
    bool Flg = false;
    readFile >> txt;

    char c;

    int min = INT_MAX, len = 0, len2;
    for(c = 'a'; c <= 'z'; ++c)
    {
        tmp = txt;
        len = remove(tmp,c);
        len2 = remove2(tmp);
        if(len2 < min) min = len2;
        cout << len2 << " "<< min << endl;
    }

    cout << min << endl;




    return 0;
}
