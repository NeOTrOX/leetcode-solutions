class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        int count1 = 0, count2 = 0;
        int element1 = 0, element2 = 0;

        for (int num : arr) {
            if (element1 == num) count1++;
            else if (element2 == num) count2++;
            else if (count1 == 0) { 
                element1 = num;
                count1 = 1;
                }
            else if (count2 == 0) { 
                element2 = num;
                count2 = 1;
                }
            else { 
                count1--;
                count2--;
                }
        }

        count1 = count2 = 0;
        for (int num : arr) {
            if (num == element1) count1++;
            else if (num == element2) count2++;
        }

        if (count1 > n / 3) res.push_back(element1);
        if (count2 > n / 3) res.push_back(element2);
        return res;
    }
};