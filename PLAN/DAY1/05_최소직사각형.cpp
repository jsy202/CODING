#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<int> mx;
    vector<int> mn;
    for(int i = 0 ; i < sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            mn.push_back(sizes[i][1]);
            mx.push_back(sizes[i][0]);
        }
        else if(sizes[i][0] <= sizes[i][1])
        {
            mn.push_back(sizes[i][0]);
            mx.push_back(sizes[i][1]);
        }
        
    }
    int a = *max_element(mn.begin(), mn.end());
        int b = *max_element(mx.begin(), mx.end());
        answer += a*b;
    return answer;
}
