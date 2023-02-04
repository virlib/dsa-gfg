//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> sol;
    bool valid(vector<vector<int>> &m, int x, int y, int n){
        if(x>=n || x<0 || y<0 || y>=n || m[x][y]==0)    return false;
        return true;
    }
    void findPath(vector<vector<int>> &m, int x, int y, int n, string s){
        if(!valid(m, x, y, n)) {   return;}
        
        if(x==n-1 && y==n-1){    sol.push_back(s);return;}
        
        
        m[x][y]=0;
        
        if(valid(m, x, y+1, n)){
        findPath(m, x, y+1, n, s+'R');}
        
        if(valid(m, x, y-1, n))
        findPath(m, x, y-1, n, s+'L');
        
        if(valid(m, x+1, y, n))
        findPath(m, x+1, y, n, s+'D');
        
        if(valid(m, x-1, y, n))
        findPath(m, x-1, y, n, s+'U');
        
        m[x][y]=1;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        findPath(m, 0, 0, n, "");
        return sol;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
