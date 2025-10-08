class Solution {
public:
    
    int firstOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                res = mid;
                high = mid - 1; 
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return res;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                res = mid;
                low = mid + 1;  
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstOccurrence(nums, target), lastOccurrence(nums, target) };
    }
};