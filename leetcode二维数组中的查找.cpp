class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return false;
        int row=0;
        int col=matrix[0].size()-1;
        while(row <= (matrix.size()-1) && col >= 0)
        {
            if(matrix[row][col]==target)        return true;
            if(matrix[row][col]<target)         row++;
            else                                col--;
        }
        return false;
    }
};
