//Q7 : longest common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string chkStr = strs[0];
        int ind = chkStr.size()-1; //5
        string ans = "";
        int k = -1;
        for(int i=1; i<strs.size(); i++) {
            string s = strs[i];
            for(int j=0; j<s.size(); j++) {
                if(j <= ind && chkStr[j] == s[j]) k = j; 
                else break;
            }
            ind = k;
            k = -1;
        }
        if(ind != -1) {
            for(int i=0; i<=ind; i++) ans += chkStr[i];
        }
        return ans;
    }
};


//Q8 : Grouping Anagrams // to check time and space complexity

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str = strs;
        unordered_map<string, vector<string>> mp;
        
        for(int i=0; i<str.size(); i++) {
            sort(str[i].begin(), str[i].end());
            mp[str[i]].push_back(strs[i]);
        }
        
        // s(eat) -- eat, tea, ate
        
        vector<vector<string>>ans;
        
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

//Q9 : Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ro = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<ro; i++) {
            for(int j=0; j<=i; j++) {
                int k = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = k;
            }
        }
        for(int i=0; i<ro; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};