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
#include <limits.h>
using namespace std;



int main() {
    ifstream readFile("../input.txt");
    if(readFile.is_open()) cout << "ok" << endl;


    vector<pair<int,int>> point;
    char str[50];
    int p1,p2;

    while(!readFile.eof())
    {
        readFile.getline(str,50);
        sscanf(str,"%d, %d",&p1,&p2);
        point.push_back(make_pair(p2,p1));

    }
    int mn = INT_MAX, dist = 0;
    vector<vector<int>> m(1000,vector<int>(1000,0));
    for(int i = 0;i < 1000; ++i)
    {
        for(int j = 0;j < 1000; ++j)
        {
            mn = INT_MAX;
            for(int k = 0; k < point.size(); ++k)
            {
                dist = abs(i-point[k].first)+abs(j-point[k].second);
                if(dist < mn) {
                    mn = dist;
                    m[i][j] = k+1;
                }
                else if(dist == mn) m[i][j] = -1;

            }
        }
    }


    vector<int> cnt(point.size(),0);
    for(int i = 0; i < 1000; ++i)
    {
        cnt[m[i][0]] = -1;
        cnt[m[i][999]] = -1;
        cnt[m[0][i]] = -1;
        cnt[m[999][i]] = -1;
    }



    for(int i = 0; i < 1000; ++i)
    {
        for(int j = 0; j < 1000; ++j)
        {
            if(cnt[m[i][j]] != -1 && m[i][j] != -1){

                ++cnt[m[i][j]];

            }
        }
    }

    mn = INT_MIN;
    for(int i = 0; i < cnt.size(); ++i)
    {
        if(cnt[i] > 0 && cnt[i] > mn) mn = cnt[i];
    }




cout << mn << endl;

    return 0;
}
