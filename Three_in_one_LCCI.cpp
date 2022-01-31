// Describe how you could use a single array to implement three stacks.

// You should implement push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum) methods. stackNum is the index of the stack. value is the value that pushed to the stack.

// The constructor requires a stackSize parameter, which represents the size of each stack.
// Input: 
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
// [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//  Output: 
// [null, null, null, 1, -1, -1, true]
// Explanation: When the stack is empty, `pop, peek` return -1. When the stack is full, `push` does nothing.


class TripleInOne {
public:
    int* stack_1;
    int* stack_2;
    int* stack_3;
    int peek_index_1 = 0;
    int peek_index_2 = 0;
    int peek_index_3 = 0;
    int stack_size;
    TripleInOne(int stackSize) {
        stack_1 = (int*)malloc(sizeof(int)*stackSize);
        stack_2 = (int*)malloc(sizeof(int)*stackSize);
        stack_3 = (int*)malloc(sizeof(int)*stackSize);
        stack_size = stackSize;
    }
    
    void push(int stackNum, int value) {
        if (stackNum == 0){
            if (peek_index_1 < stack_size){
                stack_1[peek_index_1] = value;
                peek_index_1 += 1;
            }
        }else if (stackNum == 1){
            if (peek_index_2 < stack_size){
                stack_2[peek_index_2] = value;
                peek_index_2 += 1;
            }
        }else if (stackNum == 2){
            if (peek_index_3 < stack_size){
                stack_3[peek_index_3] = value;
                peek_index_3 += 1;
            }
        }
    }
    
    int pop(int stackNum) {
        if (stackNum == 0){
            if (peek_index_1 > 0){
                peek_index_1 -= 1;
                return stack_1[peek_index_1];
            }
        }else if(stackNum == 1){
            if (peek_index_2 > 0){
                peek_index_2 -= 1;
                return stack_2[peek_index_2];
            }
        }else if(stackNum == 2){
            if (peek_index_3 > 0){
                peek_index_3 -= 1;
                return stack_3[peek_index_3];
            }
        }
        return -1;
    }
    
    int peek(int stackNum) {
        if (stackNum == 0){
            if (peek_index_1 > 0){
                return stack_1[peek_index_1-1];
            }
        }
        else if (stackNum == 1){
            if (peek_index_2 > 0){
                return stack_2[peek_index_2-1];
            }
        }
        else if (stackNum == 2){
            if (peek_index_3 > 0){
                return stack_3[peek_index_3-1];
            }
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        if (stackNum == 0 && peek_index_1 > 0){
            return false;
        }
        else if (stackNum == 1 && peek_index_2 > 0){
            return false;
        }
        else if (stackNum == 2 && peek_index_3 > 0){
            return false;
        }
        else{
            return true;
        }
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
