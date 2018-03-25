
bool search(int* nums, int numsSize, int target) {
    
    if(!nums || numsSize == 0)
        return false;
    
    for(int i = 0; i< numsSize; i++)
        if(nums[i] == target)
            return true;
    
    return false;
}
