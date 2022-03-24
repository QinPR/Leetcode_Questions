// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Input: n = 3
// Output: 5

int numTrees(int n) {
    if (n == 1 || n == 0){
        return 1;
    }
    int number = 0;
    for (int i = 0; i <= n-1; i++){
        number += numTrees(i) * numTrees(n-i-1);
    }
    return number;
}
