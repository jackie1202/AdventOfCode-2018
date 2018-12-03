#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>
#include <stdlib.h>
#include <set>
using namespace std;

void fun(string txt, vector<int>&pa)
{
    regex pattern("(\\d+),(\\d+): (\\d+)x(\\d+)");
    //regex pattern(".(\d+)().()(\d+).(\d+).()(\d+).(\d+)");
    // #31 @ 851,79: 16x24
    smatch val;
    if(regex_search(txt, val, pattern))
    {

       for(int i = 1; i < 5; ++i)
       {
           string a = val[i];
           pa.push_back(atoi(a.c_str()));
       }


    }
}




int main() {
    ifstream readFile("../input.txt");
    if(readFile.is_open()) cout << "ok" << endl;
    char str[50];
    vector<vector<int>> map(1000,vector<int>(1000,0));
    set<int> m;
    int idx = 1;
    while(!readFile.eof())
    {
        readFile.getline(str,50);
        string txt;
        for(int i = 0; i < 50 && str[i] != '\0'; ++i)
            txt.push_back(str[i]);
        vector<int> pa;
        fun(txt, pa);
        m.insert(idx);
        bool flg = true;
        int pre;
        if(pa.size() < 4) break;
        for(int i = pa[1]; i < pa[1] + pa[3]; ++i)
        {
            for(int j = pa[0]; j < pa[0] + pa[2]; ++j)
            {
                if(map[i][j] == 0) map[i][j] = idx;
                else if(map[i][j] > 0){
                    flg = false;
                    pre = map[i][j];
                    auto it = m.find(pre);
                    if(it != m.end()) m.erase(pre);
                    map[i][j] = idx;
                }
               //if(map[i][j]) cout << i << " " << j << endl;
            }
        }
        if(!flg) m.erase(idx);
        ++idx;
    }

    if(m.size() > 1) cout << "error" << endl;
    cout << *m.begin() << endl;
    /*
        int cnt = 0;
        bool Flg = true;
    for(int i = 0; i < 1000 && Flg; ++i)
    {
        for(int j = 0; j < 1000; ++j)
        {
            if(map[i][j] > 0)
            {

               cout << map[i][j] << endl;
               Flg = false;
               break;
            }

        }
    }
     */




    return 0;
}