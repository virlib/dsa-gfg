//User function Template for C++



int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    int dp[n];
    if(n<=1)    return 0;
    int profit[n];
    
    int maxele=price[n-1], maxdiff=0;
    for(int x=n-1; x>=0; x--){
        maxdiff=max(maxdiff, maxele-price[x]);
        profit[x]= maxdiff;
        
        maxele=max(maxele, price[x]);
    }
    int minele= price[0];
    maxdiff=0;
    for(int i=1; i<n; i++){
        maxdiff=max(maxdiff, price[i]-minele);
        profit[i]= max(profit[i-1], profit[i]+maxdiff);
        
        minele= min(minele, price[i]);
    }
    
    return profit[n-1];
}
