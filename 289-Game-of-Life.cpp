class Solution {
    int countLiveNeighbors(int x, int y,vector<vector<int>>& board) {
    int m= board.size();
    int n= board[0].size();
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        int count = 0;
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            //we are checking for both 1 and 3 because they are living rightnow not 
            //because 3 is living in the future no no no, we are only considering the current state
                (board[nx][ny] & 1)) { // Check current state (LSB)
                count++;
            }
        }
        return count;
    };

public:
    void gameOfLife(vector<vector<int>>& board) {
        //         For each cell, determine its next state based on its current
        //         state and the number of live neighbors it has.
        // Instead of directly updating the cell to its next state, use
        // intermediate values to mark what the next state will be. This way,
        // you don't overwrite the current state, which is still needed to
        // determine the next state of other
        //  cells.

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int livecurrent = countLiveNeighbors(i, j, board);
                if (board[i][j] == 0 && livecurrent == 3) {
                    board[i][j] += 2;
                } else if (board[i][j] == 1) {

                    if (livecurrent == 2 || livecurrent == 3) {
                        board[i][j] += 2;
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j]>=2){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }

        }
    }
};