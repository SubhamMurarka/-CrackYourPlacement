// Q12: Replace O with X

class Solution {
public:
    void dfs(int ro, int col, vector<vector<char>>& board, vector<vector<int>>&visited) {
        if(ro<0 || ro>=board.size()) return;
        if(col<0 || col>=board[0].size()) return;
        visited[ro][col] = 1;
        if(ro<board.size()-1 && visited[ro+1][col]!=1 && board[ro+1][col]=='O') dfs(ro+1, col, board, visited);
        if(ro > 0 && visited[ro-1][col]!=1 && board[ro-1][col]=='O') dfs(ro-1, col, board, visited);
        if(col > 0 && visited[ro][col-1]!=1 && board[ro][col-1]=='O') dfs(ro, col-1, board, visited);
        if(col < board[0].size()-1 && visited[ro][col+1]!=1 && board[ro][col+1]=='O') dfs(ro, col+1, board, visited);
    }
    void solve(vector<vector<char>>& board) {
        int n_ro = board.size();
        int n_col = board[0].size();
        vector<vector<int>>visited(n_ro, vector<int>(n_col, 0));
        for(int i=0; i<n_col; i++) {
           if (visited[0][i] == 0 && board[0][i] == 'O')dfs(0, i, board, visited); 
        }
        for(int i=0; i<n_ro; i++) {
            if (n_col > 0 && visited[i][n_col-1] == 0 && board[i][n_col-1] == 'O')dfs(i, n_col-1, board, visited); 
        }
        for(int i=0; i<n_col; i++) {
            if (n_ro > 0 && visited[n_ro-1][i] == 0 && board[n_ro-1][i] == 'O')dfs(n_ro-1, i, board, visited); 
        }
        for(int i=0; i<n_ro; i++) {
            if (visited[i][0] == 0 && board[i][0] == 'O')dfs(i, 0, board, visited); 
        }
        
        for(int i=0; i<n_ro; i++) {
            for(int j=0; j<n_col; j++) {
                if(visited[i][j]!=1 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};


//Q13: Basic Calculator

class Solution {
public:
    int calculate(string s) {
        int currentNum = 0, ans = 0;
        char lst_op = '+';
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                currentNum = currentNum*10 + (s[i]-'0');
            }
            if((s[i]!=' ' && !isdigit(s[i]))  || (i == s.size
()-1)){
                if(lst_op == '+') {
                    st.push(currentNum);
                } else if(lst_op == '-') {
                    st.push(-currentNum);
                } else if(lst_op == '*') {
                    int num = st.top();
                    st.pop();
                    st.push(currentNum*num);
                } else if (lst_op == '/') {
                    int num = st.top();
                    st.pop();
                    st.push(num/currentNum);
                }
                currentNum = 0;
                lst_op = s[i];
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

//Q14: LC contest  find winning player in coin game

class Solution {
public:
    string losingPlayer(int x, int y) {
        string winner = "Alice";
        int cnt = 0;
        while(x >= 1 && y >= 4) {
           if(x >= 1 && y>=4) {
               x-=1; y-=4;
               cnt++;
           }
        }
        if(cnt%2==0) winner = "Bob";
        return winner;
    }
};


//Q15:  min length of string after operations

class Solution {
public:
    string losingPlayer(int x, int y) {
        string winner = "Alice";
        int cnt = 0;
        while(x >= 1 && y >= 4) {
           if(x >= 1 && y>=4) {
               x-=1; y-=4;
               cnt++;
           }
        }
        if(cnt%2==0) winner = "Bob";
        return winner;
    }
};



