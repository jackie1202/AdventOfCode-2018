
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

#define PLAYER 403
#define BALL   71920*100
struct node{
    long long int val;
    node *left;
    node *right;
    node(long long int x):val(x),left(NULL),right(NULL){}
};

vector<long long int> scores(PLAYER,0);
int main(){

    node *cur = new node(0);
    node *p1 = new node(1);
    node *p2 = new node(2);
    cur->right = p2;
    cur->left = p1;
    p1->right = cur;
    p1->left = p2;
    p2->right = p1;
    p2->left = cur;
    cur = p2;


    long long int p = 3, b = 3;
    while(b < BALL){
        if(b % 23) {
            node *suc = new node(b);
            suc->left = cur->right;
            suc->right = cur->right->right;
            cur->right->right = suc;
            suc->right->left = suc;
            cur = suc;
        }
        else{

            scores[p] += b;
            for(int i = 0; i < 6; ++i){
                p1 = cur->left;
                cur = p1;
            }
            node *del = p1->left;
            scores[p] += del->val;
            p2 = p1->left->left;
            p1->left = p2;
            p2->right = p1;
            delete del;
            cur = p1;

        }
        ++b;
        p = (p + 1) % PLAYER;
    }

    long long int max = INT_MIN;
    for(int i = 0; i < PLAYER; ++i)
    {
        if(scores[i] > max) max = scores[i];
    }
    cout << max << endl;




    return 0;
}
