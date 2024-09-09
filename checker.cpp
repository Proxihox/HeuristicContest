#include "testlib.h"
#include <bits/stdc++.h>

#define int long long int
#define f first
#define s second
#define INF LONG_LONG_MAX

using namespace std;

int dist2(int x1, int y1, int x2 = 0, int y2 = 0){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int getTime(int n, int W, vector<int> &x, vector<int> &y, vector<int> &w, int m, vector<int> &route){
    int wt = 0, i = 1, prev = i, time = 0;
    while (i < m) {
        for (; i < m; i++) {
            if (route[i] == 0) {
                break;
            }
            wt += w[route[i] - 1];
        }
        time += (int)ceil(sqrt(dist2(x[route[prev] - 1], y[route[prev] - 1]))) * (wt + W);
        wt -= w[route[prev] - 1];
        for (int j = prev; j < i - 1; j++) {
            time += (int)ceil(sqrt(dist2(x[route[j] - 1], y[route[j] - 1], x[route[j + 1] - 1], y[route[j + 1] - 1])))
                    * (wt + W);
            wt -= w[route[j + 1] - 1];
        }
        time += (int) ceil(sqrt(dist2(x[route[i - 1] - 1], y[route[i - 1] - 1]))) * (wt + W);
        wt = 0;
        i++;
        prev = i;
    }
    return time;
}

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
    
    int d2max = 0, d2min = INF;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            d2max = max(d2max, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            d2min = min(d2min, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    for (int i = 0; i < n; i++){
        d2max = max(d2max, x[i] * x[i] + y[i] * y[i]);
        d2min = min(d2min, x[i] * x[i] + y[i] * y[i]);
    }
    int wsum = 0;
    for (int i = 0; i < n; i++){
        wsum = wsum + w[i];
    }
    int uppermax = (int)ceil(sqrtl((long double)d2max)) * n * 2 * (W + wsum);
    vector<int> dumb_route;
    for (int i = 0; i <= n + 1; i++){
        dumb_route.push_back(i % (n + 1));
    }
    int uppermin = getTime(n, W, x, y, w, n + 2, dumb_route);
    
    int t = getTime(n, W, x, y, w, m, route);
    
    if (t >= uppermin){
        return 0;
    }
    long double factor = ((long double)t / uppermin);
    long double adjusted_factor = pow(factor, 0.6);  // Apply exponent less than 1 to stretch values
    int score = 1000 - (adjusted_factor * 1000);
    return score;
}
