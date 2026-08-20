#include <string>
#include <vector>
#include <map> 
using namespace std;

int solution(vector<vector<string>> clothes) {
  
    map <string , int > mp;
    for(int i = 0 ; i < clothes.size(); i++)
    {
        mp[clothes[i][1]]++;
    }
    int answer = 1;
    for(auto p  : mp)
    {
        answer *= (p.second + 1);
    }
    return answer - 1;
}
