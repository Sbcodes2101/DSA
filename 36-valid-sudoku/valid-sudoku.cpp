class Solution {
public:
    bool isValid(vector<vector<char>>& board,int idx){
        if (idx>8) return true;
        unordered_set<char> st;

        for(int i=0;i<9;i++){
            if(st.find(board[idx][i])!=st.end()) return false;
            else if(st.find(board[idx][i])==st.end() && board[idx][i]!= '.'){
                st.insert(board[idx][i]);
            } 
        }

        st.clear();

        for(int i=0;i<9;i++){
            if(st.find(board[i][idx])!=st.end()) return false;
            else if(st.find(board[i][idx])==st.end() && board[i][idx]!= '.'){
                st.insert(board[i][idx]);
            } 
        }

        st.clear();

        int startRow = (idx/3)*3;
        int startCol = (idx%3)*3;

        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
            if(st.find(board[i][j])!=st.end()) return false;
            else if(st.find(board[i][j])==st.end() && board[i][j]!= '.'){
                st.insert(board[i][j]);
            } 
            }
        }

        bool ans = isValid(board,idx+1);
        return ans;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return isValid(board,0);
    }
};