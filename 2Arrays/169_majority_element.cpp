class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;       // Tracks balance between candidate and others
        int candidate = 0;   // Stores the potential majority element
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;   // Pick new candidate
            }
            
            if (num == candidate) {
                count++;           // Same as candidate → increase balance
            } else {
                count--;           // Different from candidate → decrease balance
            }
        }
        
        return candidate;   // Candidate is guaranteed majority (problem statement ensures it)
    }
};
