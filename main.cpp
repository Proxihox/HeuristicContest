
#include <bits/stdc++.h>

#define int long long int
#define INF LONG_LONG_MAX

using namespace std;


int dist2(int x1, int y1, int x2 = 0, int y2 = 0){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int gettime(int n, int W, vector<int> &x, vector<int> &y, vector<int> &w, int m, vector<int> &route);

int ans_checker(int n, int W, vector<int> &x, vector<int> &y, vector<int> &w, int m, vector<int> &route){
    if (route.size() != m || m == 0){
        return 0;
    }
    if (route[0] != 0 or route[m - 1] != 0){
        return 0;
    }
    vector<bool> visited(n);
    for (int i = 0; i < m; i++){
        if (route[i] < 0 or route[i] > n){
            return 0;
        }
        if (route[i] != 0){
            visited[route[i] - 1] = true;
        }
    }
    for (int i = 0; i < n; i++){
        if (not visited[i]){
            return 0;
        }
    }
    
    int d2max = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            d2max = max(d2max, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    for (int i = 0; i < n; i++){
        d2max = max(d2max, x[i] * x[i] + y[i] * y[i]);
    }
    int wmax = 0;
    for (int i = 0; i < n; i++){
        wmax = max(wmax, w[i]);
    }
    int uppermax = (int)ceil(sqrtl((long double)d2max)) * (2*W + wmax) * n;
    int t = gettime(n, W, x, y, w, m, route);
    if (t >= uppermax){
        return 0;
    }
    long double factor = ((long double)t / uppermax);
    long double adjusted_factor = log2(1 + factor);  // Apply exponent less than 1 to stretch values
    int score = 1000 - (adjusted_factor * 1000);
    return score;
}

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
    route.push_back(0);
    for(int i = 1; i < n+1; i++){ // simple delivering in the reverse order of points givens
        route.push_back(n+1-i);
    }
    route.push_back(0); // We have to return to origin finally
    //route = {0,1,0,2,0,3,0,4,0,5,0};
    int m = route.size(); // m is the total number of stops in the route

    // printing the output
    cout << m << "\n";
    for(auto x:route) cout << x << " ";
    // comment the below line out while making final submission
    cout << "\nScore : " << ans_checker(n,W,x,y,w,m,route) << "\n"; 
}

