#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ret1 = 0;
    int ret2 = 0;
    int ret3= 0;
    vector <int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0 ; i < answers.size(); i++)
    {
        if(answers[i] == p1[i % 5]) ret1++;
        if(answers[i] == p2[i % 8]) ret2++;
        if(answers[i] == p3[i % 10]) ret3++;
    }
  
    int mx = max({ret1, ret2, ret3 });
    if(ret1 == mx) answer.push_back(1);
    if(ret2 == mx) answer.push_back(2);
    if(ret3 == mx) answer.push_back(3);
    return answer;
}
