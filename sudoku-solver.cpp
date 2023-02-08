//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool checkSudoku(int grid[N][N], int i, int j, int k){
        
        for(int row=0; row<N; row++){
            if(grid[row][j]==k)
                return false;
        }
        
        for(int col=0; col<N; col++){
            if(grid[i][col]==k)
                return false;
        }
                
        int sq_row= i-i%3, sq_col= j-j%3;
        for(int row=0; row<3; row++){
            for(int col=0; col<3; col++){
                if(k==grid[row+sq_row][col+sq_col])
                    return false;
            }
        }
        return true;
        
    }
    
    bool solve(int grid[N][N], int row, int col){
        if(row==N-1 && col==N){ return true;}
        
        if(col==N){ row++; col=0;}
        
        if(grid[row][col]>0)    return solve(grid, row, col+1);
        
        
        for(int k=1; k<=9; k++){
            if(checkSudoku(grid, row, col, k)){
                grid[row][col]=k;
                if(solve(grid, row, col+1))
                    return true;
                
            }
            grid[row][col]=0;
        }
        return false;
        
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        //solve(grid, 0, 0);
        
        for(int i=0; i<N; i++){
            
            for(int j=0; j<N; j++){
                
                if(grid[i][j]==0){
                    for(int k=1; k<=9; k++){
                        
                        if(checkSudoku(grid, i, j, k)){
                            grid[i][j]=k;
                            if(SolveSudoku(grid)){
                        
                                return true;}}
                        grid[i][j]=0;
                    }
                return false;
                    
                }
            }
        }
        
        return true;
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++){
            
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
