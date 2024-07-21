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

//Q19 : 