
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>
#include <cstdlib>
#include <set>
#include <cctype>
#include <iomanip>
#include <climits>
#include <cstdio>
using namespace std;


vector<int> num;
int idx = 0;

int cal(){

    int child = num[idx], data = num[idx+1];


    vector<int> val(child+1,0);

    idx += 2;
    for(int i = 0; i < child; ++i){
        int tmp = cal();
        val[i+1] = tmp;
    }

    int sum = 0;
    for(int j = 0; j < data; ++j){
        int idn = idx++;
        if(child == 0)
        sum += num[idn];
        else if (num[idn] > child || num[idn] < 0) continue;
        else sum += val[num[idn]];
    }
    return sum;
}
int main(){

    ifstream in("../input.txt");
    int tmp;
    while(in >> tmp){
        num.push_back(tmp);
    }
    cout << "ok" << endl;
    int sum = cal();
    cout << sum << endl;
    return 0;
}