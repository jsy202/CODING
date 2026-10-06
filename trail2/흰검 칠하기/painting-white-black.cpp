#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000];
char dir[1000];
string visited[200005];
int offset = 100000;
string answer[200005];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    int cur = 0;

    for (int i = 0; i < n; i++) {

        if (dir[i] == 'L') {
            for (int j = 0; j < x[i]; j++) {

                visited[cur + offset] += 'W';

                if (j != x[i] - 1)
                    cur--;
            }
        }

        if (dir[i] == 'R') {
            for (int j = 0; j < x[i]; j++) {

                visited[cur + offset] += 'B';

                if (j != x[i] - 1)
                    cur++;
            }
        }
    }

    for (int i = 0; i < 200005; i++) {

        int black = 0;
        int white = 0;

        for (char c : visited[i]) {
            if (c == 'B')
                black++;
            else if (c == 'W')
                white++;
        }

        // 전부 센 다음 판정
        if (white >= 2 && black >= 2) {
            answer[i] = "grey";
        }
        else if (!visited[i].empty()) {

            if (visited[i].back() == 'B')
                answer[i] = "black";
            else
                answer[i] = "white";
        }
    }

    int bl = 0;
    int wh = 0;
    int gr = 0;

    for (int i = 0; i < 200005; i++) {
        if (answer[i] == "black")
            bl++;
        else if (answer[i] == "white")
            wh++;
        else if (answer[i] == "grey")
            gr++;
    }

    cout << wh << ' ' << bl << ' ' << gr;

    return 0;
}