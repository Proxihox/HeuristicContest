#include "testlib.h"
#include <bits/stdc++.h>
#include "checker.cpp"
#define int long long int
#define f first
#define s second
#define INF LONG_LONG_MAX

using namespace std;

int dist2(int x1, int y1, int x2 = 0, int y2 = 0){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int32_t main(int32_t argc, char *argv[]){
    registerTestlibCmd(argc, argv);
    // Reading inputs
    int n,W;
    cin >> n >> W;
    vector<int> x(n), y(n), w(n);
    int _x,_y,_w;
    for (int i = 0; i < n; i++){
        cin >> _x >> _y >> _w;
        x.push_back(_x);
        y.push_back(_y);
        w.push_back(_w);
    }
    vector<int> route; // list of order of destination points
    for(int i = 0; i < n+1; i++){ // simple delivering in the order the points are given
        route.push_back(i);
    }
    route.push_back(0); // We have to return to origin finally
    int m = route.size(); // m is the total number of stops in the route
    cout << "Score : " << ans_checker(n,W,x,y,w,m,route) << "\n";
}