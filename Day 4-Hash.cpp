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

// sort by time

void pre(string txt, map<string,string> &sorted)
{
    regex pattern("(\\d+)-(\\d+) (\\d+):(\\d+)");
    // [1518-11-02 00:00]
    smatch val;
    string time;
    if(regex_search(txt, val, pattern))
    {
        for(int i = 1; i <= 4; ++i)
            time += val[i];
    }
    string others;
    if(txt.find("Guard") != string::npos)
    {
        auto it = txt.find("#");
        for(auto it2 = it+1;  it2 < txt.size(); ++it2)
        {

            if(!isdigit(txt[it2])) break;
            else others.push_back(txt[it2]);
        }
    }
    if(txt.find("wake") != string::npos)
        others += "wake";
    if(txt.find("asleep") != string::npos)
        others += "asleep";

    sorted[time] = others;
}



void fun(map<string,string> &sorted, map<string, vector<string>> &item)
{
    string state, time, ID;
    
    for(auto it = sorted.begin(); it != sorted.end(); ++it)
    {
        time = it->first;
        if(isdigit((it->second)[0])){
            ID = it->second;
            continue;
        } // ID
        else if((it->second).find("asleep") != string::npos) state = "a";
        else if((it->second).find("wake") != string::npos) state = "w";

        auto id = item.find(ID);
        // current ID exists
        if(id != item.end())
        {
            vector<string> sub = id->second;
            sub.push_back(state+time);
            item.erase(id);
            item.insert(make_pair(ID,sub));
        }

        else{
            vector<string> sub;
            sub.push_back(state+time);
            item.insert(make_pair(ID,sub));
        }

    }

    int all_max = 0;
    int id, point, point_all;
    int a, w;
    string sub;


    for(auto it = item.begin(); it != item.end(); ++it)
    {

        vector<int> cnt(59,0);
        int a = -1, w = -1, id_max = 0;
        for(int i = 0; i < (it->second).size(); ++i)
        {
            if(it->second[i][0] == 'a')
            {
                sub = it->second[i].substr(7);
                a = atoi(sub.c_str());
            }
            else if(it->second[i][0] == 'w')
            {
                sub = it->second[i].substr(7);
                w = atoi(sub.c_str());
            }
            if(a >= 0 && w >= 0) {

                for(int j = a; j < w; ++j)
                {
                    ++cnt[j];
                }
                w = -1;

            }

        }

        for(int i = 0; i < 59; ++i)
        {
            if(cnt[i] > id_max)
            {
                id_max = cnt[i];
                point = i;
            }

        }

        if(id_max > all_max) {
            all_max = id_max;
            point_all = point;
            id = atoi(it->first.c_str());
        }



    }

    cout << id * point_all << endl;

}






int main() {
    ifstream readFile("../input.txt");
    if(readFile.is_open()) cout << "ok" << endl;
    char str[50];

    map<string, vector<string>> item;
    map<string,string> sorted;


    while(!readFile.eof())
    {
        readFile.getline(str,50);
        string txt;
        for(int i = 0; i < 50 && str[i] != '\0'; ++i)
            txt.push_back(str[i]);
        pre(txt, sorted); // sort by time

    }

    fun(sorted, item);

    return 0;
}
