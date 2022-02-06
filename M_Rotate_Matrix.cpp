// Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
// Given matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// Rotate the matrix in place. It becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix_copy = matrix;
        int size = matrix.size();
        for (int i = 0; i < matrix.size(); i++){   // copy all the element from the matrix
            for (int j = 0; j < matrix.size(); j++){
                matrix_copy[j][size-i-1] = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix.size(); j++){
                matrix[i][j] = matrix_copy[i][j];
            }
        }
    }
};
