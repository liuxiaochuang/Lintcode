这道题见鬼了，为什么我的代码中，dfs（）函数里，注释掉的代码可以AC，但是现在的代码跑就是Runtime Error呢？
class Solution {
public:
    void dfs(vector<vector<char>> &board, int row, int clo) {
        int m=board.size(), n = board[0].size();
        /*if (board[row][clo]=='O'){


        board[row][clo] = 'a';
        if (row > 1) {
            dfs(board, row-1, clo);
        }
        if (clo > 1)
            dfs(board, row, clo-1);
        if (row <m-1)
            dfs(board, row+1, clo);
        if (clo < n-1)
            dfs(board, row, clo+1);
        }*/
        if (row<0||row>=m || clo<0||clo>=n || board[row][clo]=='a')
            return;

        if (board[row][clo]=='O') {
            board[row][clo] = 'a';
            dfs(board, row-1, clo);
            dfs(board, row, clo-1);
            dfs(board, row, clo+1);
            dfs(board, row+1, clo);
        }
    }
    void dfs_1(vector<vector<char>> &board, int row, int clo) {
        int m=board.size(), n = board[0].size();
        if (row<1||row>=m-1 || clo<1||clo>=n-1)
            return;
        if (board[row][clo] == 'O'){
            board[row][clo] = 'X';


        }
    }
    void dfs_2(vector<vector<char>> &board, int row, int clo) {
        int m=board.size(), n = board[0].size();
        if (board[row][clo]=='a'){


        board[row][clo] = 'O';
        if (row > 1) {
            dfs(board, row-1, clo);
        }
        if (clo > 1)
            dfs(board, row, clo-1);
        if (row <m-1)
            dfs(board, row+1, clo);
        if (clo < n-1)
            dfs(board, row, clo+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size()==0 || board[0].size()==0||board.size()==1 || board[0].size()==1
        ||board.size()==2 || board[0].size()==2)
            return;
        int m=board.size(), n = board[0].size();
        //cout<<0<<endl;
        for (int i=0; i<m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        //cout<<"?"<<endl;
        for (int i=0; i<n; i++) {
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }
        //cout<<1<<endl;
        for (int i=1; i<m-1; i++) {
            for (int j=1; j<n-1; j++) {
                if (board[i][j] == 'O'){
                     board[i][j] = 'X';
                }
                //cout<<3<<endl;
            }
            //cout<<2<<endl;
        }
        /*
        cout<<1<<endl;
        for (int i=0; i<m; i++) {
            dfs_2(board, i, 0);
            dfs_2(board, i, n-1);
        }
        for (int i=0; i<n; i++) {
            dfs_2(board, 0, i);
            dfs_2(board, m-1, i);
        }*/
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'a'){
                     board[i][j] = 'O';
                }
                //cout<<3<<endl;
            }
            //cout<<2<<endl;
        }
        return;
    }
};