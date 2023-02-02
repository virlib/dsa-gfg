//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string, int> m;
    bool checkPalindrome(string str){
        string s= str;
        reverse(s.begin(), s.end());
        if(str==s)  return 1;
        return 0;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        if(m[str]!=0)   return m[str];
        int count=INT_MAX, n=str.length();
        if (n==0)   return  0;
        for(int i=n; i>0; i--){
            if(checkPalindrome(str.substr(0, i)))
                {if(i==n)    return 0;
                
                count=min(count, 1+palindromicPartition(str.substr(i, n-i)));}
                
        }
        
        return m[str]=count;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
