//房屋打劫2-考察点：dp
//思路：因为是圆形场地，所以要分从第一个房屋开始和从第二个房屋开始两种情况，其他的和房屋打劫1相同；

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 ) return 0;
        if (len == 1 ) return nums[0];
        if (len == 2 ) return nums[0]>nums[1]?nums[0]:nums[1];
        if (len == 3) {
            int temp = nums[0];
            if (nums[1] > temp)
                temp = nums[1];
            if (nums[2] > temp)
                temp = nums[2];
            return temp;
        }
        int temp1,temp2,temp3;
        int tempt1,tempt2,tempt3;
        temp1 = nums[0];
        temp3 = temp2 = nums[1]>nums[0]?nums[1]:nums[0];
        tempt1 = nums[1];
        tempt3 = tempt2 = nums[2]>nums[1]?nums[2]:nums[1];
        for (int i=2; i<len-1; i++){
            if (nums[i] + temp1 > temp2)
                temp3 = nums[i] + temp1;
            else
                temp3 = temp2;
            temp1 = temp2;
            temp2 = temp3;
        }
        for (int i = 3; i<len; i++) {
            if (nums[i] + tempt1 > tempt2)
                tempt3 = nums[i] + tempt1;
            else
                tempt3 = tempt2;
            tempt1 = tempt2;
            tempt2 = tempt3;
        }
        return tempt3>temp3 ? tempt3 : temp3;
    }
};
