typedef struct nd{
    int index;
    int min_steps;
    struct nd * right;
} Node;

void getMinimumNumOfJumps( Node *min_jumps, int i, int steps_i, int length){
    if(i == length-1) {
        min_jumps[i].min_steps = 0;
        return;
    }
    int j = i+1;
    while(j < length){
        if( j <= i + steps_i){
            min_jumps[i].min_steps = min_jumps[j].min_steps + 1;
            min_jumps[i].right = &min_jumps[j];
        }else{
            if(min_jumps[i].right == NULL){
                if(min_jumps[j].min_steps < min_jumps[i].min_steps)
                    min_jumps[i].right =  &min_jumps[j];
            }else{
                break;
            }
        }
        if(min_jumps[j].right != NULL)  j = min_jumps[j].right->index;
        else break;
    }
    
}

int jump(int* nums, int numsSize) {
    Node * min_jumps = (Node *) calloc(numsSize, sizeof(Node));
    int min_steps=0;
    for(int i=numsSize-1; i>=0;i--){
        min_jumps[i].index = i; min_jumps[i].min_steps = INT_MAX;
        getMinimumNumOfJumps(min_jumps, i, nums[i], numsSize);
    }
    return min_jumps[0].min_steps;
}
