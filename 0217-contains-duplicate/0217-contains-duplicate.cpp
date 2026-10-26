class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int x : nums) {
            if (s.count(x))
                return true;
            s.insert(x);
        }

        return false;
    }
};




/* class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0 ;i < size(nums) ; i ++){
           for(int j = i + 1 ; j < size(nums) ; j ++){
                  if (nums[i] == nums[j]) return true;
           } 
        }
        return false;
    }
}; */