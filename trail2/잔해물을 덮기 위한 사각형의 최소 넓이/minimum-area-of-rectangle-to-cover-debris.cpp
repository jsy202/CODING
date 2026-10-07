#include <bits/stdc++.h>

using namespace std;

// 일단 오프셋 

int offset = 1000;
int x1[2], y[2];
int x2[2], y2[2];

// 1로 되어있는곳중에 최대 xy , 최소 xy 구하면 되나
int arr[2005][2005];

int main() {
    cin >> x1[0] >> y[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y[1] >> x2[1] >> y2[1];

    x1[0] = x1[0] + offset;
    x2[0] = x2[0] + offset;
    y[0] = y[0] + offset;
    y2[0] = y2[0] + offset;
    x1[1] = x1[1] + offset;
    x2[1] = x2[1] + offset;
    y[1] = y[1] + offset;
    y2[1] = y2[1] + offset;
   
    for(int i = x1[0]; i < x2[0]; i++)
    {
        for(int j = y[0]; j < y2[0]; j++)
        {
            arr[i][j] = 1;
        }
    }

    for(int i = x1[1]; i < x2[1]; i++)
    {
        for(int j = y[1]; j < y2[1]; j++)
        {
            arr[i][j] = 0;
        }
    }

    bool h = false;

    int minx = 10000 , miny = 10000, maxx = 0, maxy = 0 ;
    for(int i = 0; i <= 2000; i++)
    {
        for(int j = 0; j <= 2000; j++)
        {
               if(arr[i][j] == 1)
            {
                h = true;
                minx = min(minx, i);
                miny = min(miny, j);
                maxx = max(maxx, i);
                maxy = max(maxy, j);
            }
        }
    }

    if(h == false) cout << 0;

    else{cout << (maxx- minx + 1) * (maxy- miny + 1);}
    
    return 0;
}