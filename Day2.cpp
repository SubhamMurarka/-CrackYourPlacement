//Q3. Valid palindrome

class Solution {    // deee
public:
    bool sol(int i, int j, string &s) {
        while(i <= j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
      int i = 0;
      int j = s.size()-1;
      while(i <= j) {
          if(s[i]!=s[j]) {
             return sol(i+1, j, s) || sol(i, j-1, s);
          }
          i++;
          j--;
      }
        return true;
    }
};

// ["((((((","((((()","(((()(","(((())","((()((","((()()","((())(","((()))","(()(((","(()(()","(()()(","(()())","(())((","(())()","(()))(","(())))","()((((","()((()","()(()(","()(())","()()((","()()()","()())(","()()))","())(((","())(()","())()(","())())","()))((","()))()","())))(","()))))",")(((((",")(((()",")((()(",")((())",")(()((",")(()()",")(())(",")(()))",")()(((",")()(()",")()()(",")()())",")())((",")())()",")()))(",")())))","))((((","))((()","))(()(","))(())","))()((","))()()","))())(","))()))",")))(((",")))(()",")))()(",")))())","))))((","))))()",")))))(","))))))"]


//Q4. generating valid paranthesis

class Solution {
public:
    void solution(int n, string &s, vector<string>&ans, int o, int c) {
        if(s.size() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(o < n) {
            s.push_back('(');
            solution(n, s, ans, o+1, c);
            s.pop_back();
        }
        if(c < n && o > c) {
             s.push_back(')');
            solution(n, s, ans, o, c+1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        // unordered_map<char,int> mp;
        solution(n, s, ans, 0, 0);
        // for(int i=0; i<ans.size(); i++) cout<<ans[i];
        return ans;
    }
};

// Q5. simplify path

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string ans;
        vector<string>s;
        //custom split function
        for(int i=0; i<n; i++) {
            
             if(path[i] == '/' and path[i+1] == '/') {
                path.erase(path.begin()+1+i);
                n = n-1;
            }
            
            if(path[i]!='/') {
                ans.push_back(path[i]);
            } else {
                if(ans.size() > 0){
                      s.push_back(ans);
                      ans.erase();
                }
            }
        }
        if(ans.size() > 0) s.push_back(ans);
        // considering cases for .. 
        stack<string>st;
        string simPath;
        int  i = 0;
        while(i<s.size()) {
            if(s[i]=="..") {
                if(st.empty() == false) st.pop();
            } else if(s[i] != ".") {
                st.push(s[i]);
            }
            i++;
        }
        if(st.empty()) simPath += '/';
        else{
            // generating string
            while(!st.empty()) {
                string s = st.top();
                st.pop();
                reverse(s.begin(), s.end());
                simPath += s;
                simPath += '/';
            }
        }
        reverse(simPath.begin(), simPath.end());
        return simPath;
    }
};

// ... a .. b c .. d .   /.../b/d/./

//Q6: Reverse words

class Solution {
public:
    string reverseWords(string s) {
        string str;
        vector<string>words;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ') {
                str.push_back(s[i]);
            } else {
                if (str.size() > 0){
                    words.push_back(str);
                    str.erase();
                }
            }
        }
       if (str.size()>0) words.push_back(str);
        string answer;
        for(int i=words.size()-1; i>=0; i--) {
            answer += words[i];
            answer += " ";
        }
        answer.pop_back();
        return answer;
    }
};