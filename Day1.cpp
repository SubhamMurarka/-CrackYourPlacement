// Q1 : Balanced Paranthesis

class Solution {
public:
    bool isValid(string s) {
        // ([)
        int n = s.size();
        unordered_map<char,int> mp;
        mp['{'] = 1;
        mp['}'] = -1;
        mp['('] = 2;
        mp[')'] = -2;
        mp['['] = 3;
        mp[']'] = -3;
        stack<char>st;
        st.push(s[0]);
        int i = 1;
        while(!st.empty()) {
            while(i < n && mp[s[i]]<0) {
                if(st.empty()) return false;
                char a = st.top();
                st.pop();
                if(mp[s[i]] + mp[a] == 0) i++;
                else return false;
            }

            if(i >= n && st.empty() == false) return false;

            while(i < n && mp[s[i]]>0) {
                st.push(s[i]); i++;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};


//wrting it in better way

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int>st;
        int i = 0;
        while(i<n) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char a = st.top();
                st.pop();
                if(!((a == '[' && s[i] == ']') || (a == '(' && s[i] == ')') || (a == '{' && s[i] == '}'))) {
                    return false;
                }
            }
            i++;
        }
        if(st.empty()) return true;
        return false;
    }
};

//Q2 : Index of first occurence

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        int j = 0;
        string s;
        int ans = -1;
        while(j<n) {
            s.push_back(haystack[j]);
            if(j-i+1 < m) {
                j++;
            }
            else {
                if(s == needle) {
                    ans = i;
                    break;
                } else {
                    s.erase(s.begin());
                    i++; j++;
                }
            }
        }
        return ans;
    }
};

