//Q16 : Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
       vector<int>cnt_one(31, 0);
       int ans = 0;
        
    for(int i=0; i<=30; i++) {
        int cnt = 0;
        for(int j=1; j<nums.size(); j++) {
            if(j & (1<<i))cnt++;
        }
        cnt_one[i] = cnt;
    }
        
       for(int i=0; i<=30; i++) {
           int cnt = 0;
           for(int j=0; j<n; j++) {
               if(nums[j] & (1<<i)) cnt++;
           }
           if(cnt_one[i] < cnt) ans = ans | (1<<i);
       }
        
        return ans;
    }
};

//Q17 : Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0  = 0, cnt_1 = 0, cnt_2 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) cnt_0++;
            if(nums[i]==1) cnt_1++;
            if(nums[i]==2) cnt_2++;
        }
        nums.erase(nums.begin(), nums.end());
        while(cnt_0!=0) {
            nums.push_back(0);
            cnt_0--;
        }
        while(cnt_1!=0) {
            nums.push_back(1);
            cnt_1--;
        }
        while(cnt_2!=0) {
            nums.push_back(2);
            cnt_2--;
        }
    }
};


//using dutch national flag algorithm
// 0 -> lo-1 = 0
//lo -> mid-1 = 1
//mid -> hi = unsorted
//hi+1 -> n-1 = 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0, hi = nums.size()-1, lo=0;
        while(mid <= hi) {
            if(nums[mid] == 0) {
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};


//Q18 : Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i = 1;
        while(i < nums.size()) {
            if(nums[i]==nums[i-1]) nums.erase(nums.begin()+i);
            else i++;
        }
        // cout<<nums.size();
        // for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
        return nums.size();
    }
};

//Q19 : move 0 to end


class Solution {
public:

    // [0 0 1 3 12]
    void moveZeroes(vector<int>& nums) {
        //[0 1 0 3 12]
        //[1 0 0 3 12] [1  0 0 3 12] [1 0 3 0 12] [1 0 3 12 0]
        vector<int>nums1 = nums;
        nums.erase(nums.begin(), nums.end());
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]!=0) nums.push_back(nums1[i]);
        }
        int diff = nums1.size() - nums.size();
        for(int i=0; i<diff; i++) nums.push_back(0);
    }
};

// optimal

class Solution {
public:

    // [0 0 1 3 12]
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=1;
        while(i<n && j<n) {
            if(nums[i]==0 && nums[j]!=0) {
                swap(nums[i], nums[j]);
            } else if(nums[i] == 0 && nums[j] == 0) {
                while(j<n && nums[j]==0) j++;
                if(j < n) swap(nums[i], nums[j]);
            }
            i++; j++;
        }
    }
};

//Q20 : 2 sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end()) {
                ans.push_back(mp[diff]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        
        return ans;
    }
};
