// 2017-09-22
// 原题：https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	/*
    	第一个想法就是两个for()循环，时间复杂度是O(n*n)
    	*/
    	vector<int> iVec;
        for(int i  =0;i<nums.size();i++)
        	for(int j = i+1;j<nums.size();j++)
        		if(nums[i] +nums[j] == target)
        		{
        			iVec.push_back(i);
        			iVec.push_back(j);
        		}
        		return iVec;
    }
};