#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int h, n;
        cin >> h >> n;
        vector<int> A(n);
        for(auto &a : A) cin >> a;
        vector<int> C(n);
        for(auto &c : C) cin >> c;
        priority_queue<pair<long long,int>> q;
        for(int i = 0; i<n; i++){
            q.push({-1, i});
        }
        while(h>0 && !q.empty()){
            auto x = q.top().first;
            auto y = q.top().second;
            h -= A[y];
            if(h <= 0){
                cout << (-1)*x << "\n";
                break;
            } 
            q.pop();
            q.push({x-C[y], y});
        }   
    }
}