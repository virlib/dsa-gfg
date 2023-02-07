//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    bool comparison(vector<string>& dict, string s){
        for(int i=0; i<dict.size(); i++){
            if(!dict[i].compare(s))
                return true;
        }
        return false;
    }
    bool breaky(vector<string>& dict, string s, string sol){
        int n=s.size();
        if (n==0)   {ans.push_back(sol);
                    return true;}
        
            
        for(int i=1; i<=n; i++){
            if(comparison(dict, s.substr(0, i))){
                if(i==n){
                    sol+=s.substr(0, n);
                     breaky(dict, "", sol);
                 }
                
                else{
                    string sol2=sol;
                    sol2+=s.substr(0, i);
                    sol2+=" ";
                    breaky(dict, s.substr(i, n-i), sol2);
                }
            }
        }
        
        return false;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        breaky(dict, s, {});
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
