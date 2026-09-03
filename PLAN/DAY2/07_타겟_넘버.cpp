#include <string>
#include <vector>

using namespace std;

int ret;

void go(int cnt, int sum, int target, const vector<int>& v)
{
    if(cnt == v.size())
    {
        if(sum == target)
            ret++;

        return;
    }

    go(cnt + 1, sum + v[cnt], target, v);
    go(cnt + 1, sum - v[cnt], target, v);
}

int solution(vector<int> numbers, int target)
{
    ret = 0;

    go(0, 0, target, numbers);

    return ret;
}
