
#include <bits/stdc++.h>
#include "checker.cpp"


using namespace std;


int32_t main(int32_t argc, char *argv[]){
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
    // route.push_back(0);
    // for(int i = 1; i < n+1; i++){ // simple delivering in the reverse order of points givens
    //     route.push_back(n+1-i);
    // }
    // route.push_back(0); // We have to return to origin finally
    route = {0,2,1,0,3,0,4,5,0};
    int m = route.size(); // m is the total number of stops in the route
    cout << "Score : " << ans_checker(n,W,x,y,w,m,route) << "\n";
}