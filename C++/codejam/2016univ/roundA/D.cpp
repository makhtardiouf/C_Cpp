#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    deque<PP> snake;
    set<PP> ate, occ;
    int dir = 0;
    int dead = 0;
    int x = 0, y = 0;
    vector<PP> op;
    snake.push_back(PP(0, 0)); occ.insert(PP(0, 0));
    int r, c, s;
    cin >> s >> r >> c;
    for (int i = 0; i < s; i ++) {
        int t; char x; cin >> t >> x;
        op.push_back(PP(t, x == 'R'));
    }
    x = 0, y = 0;
    for (int i = 1, cur = 0; i <= 2000000; i ++) {
        if (dead) {
            //cerr << "dead\n";
            cout << snake.size() << endl;  
            return;
        }
        //cerr << i << "s: " << x << ' ' << y << endl;
        int nx = (x + dx[dir] + c) % c, ny = (y + dy[dir] + r) % r;
        if ((nx + ny) % 2 == 1 && ate.count(PP(nx, ny)) == 0) {
            if (occ.count(PP(nx, ny))) {
                dead = 1;
            }
            occ.insert(PP(nx, ny));
            snake.push_front(PP(nx, ny));
            ate.insert(PP(nx, ny));
        }
        else {
            PP tail = snake.back(); 
            snake.pop_back(); occ.erase(tail);
            if (occ.count(PP(nx, ny))) {
                dead = 1;
            }
            occ.insert(PP(nx, ny));
            snake.push_front(PP(nx, ny));
        }
        x = nx; y = ny;
        if (cur < op.size() && op[cur].fr == i) {
            dir = (dir + 2 * op[cur ++].sc - 1 + 4) % 4;
        }
    }
    cout << snake.size() << endl;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif
    int Q; cin >> Q;
    for (int i = 0; i < Q; i ++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }    
    return 0;
}
