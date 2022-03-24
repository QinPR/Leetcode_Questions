// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> copy = matrix;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (copy[i][j] == 0){
                    // first, it checks its left element whether if it is 0
                    if (j == 0 || i == 0){
                        for (int k = 0; k < matrix[0].size(); k++){
                            matrix[i][k] = 0;
                        }
                        for (int k = 0; k < matrix.size(); k++){
                            matrix[k][j] = 0;
                        }
                    }else{
                        if (copy[i][j-1] != 0){
                            for (int k = 0; k < matrix[0].size(); k++){
                                matrix[i][k] = 0;
                            } 
                        }
                        if (copy[i-1][j] != 0){
                            for (int k = 0; k < matrix.size(); k++){
                                matrix[k][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
};
