class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0;
        int col=cols-1;
        while(row<rows && col>=0){
            int value=matrix[row][col];
            if(value==target){
                return true;
            }else if (value>target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};