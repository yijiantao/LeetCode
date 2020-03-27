/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 车的可用捕获量
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0, find_R_flag = 0;
        for (int _i = 0; _i < board.size(); ++_i){
            if (find_R_flag != 0) break;
            for (int _j = 0; _j < board[0].size(); ++_j){
                if (board[_i][_j] == 'R'){
                    find_R_flag = 1;
                    // 上
                    int check_i = _i , check_j = _j;
                    while (1){
                        if (check_i < 0) break;
                        else if (board[check_i][check_j] == 'p'){
                            res += 1;
                            break;
                        }
                        else if (board[check_i][check_j] == 'B') break;
                        else check_i -= 1;
                    }
                    // 下
                    check_i = _i, check_j = _j;
                    while (1){
                        if (check_i > 7) break;
                        else if (board[check_i][check_j] == 'p'){
                            res += 1;
                            break;
                        }
                        else if (board[check_i][check_j] == 'B') break;
                        else check_i += 1;
                    }
                    // 左
                    check_i = _i, check_j = _j;
                    while (1){
                        if (check_j < 0) break;
                        else if (board[_i][check_j] == 'p'){
                            res += 1;
                            break;
                        }
                        else if (board[check_i][check_j] == 'B') break;
                        else check_j -= 1;
                    }
                    
                    // 右
                    check_i = _i, check_j = _j;
                    while (1){
                        if (check_j > 7) break;
                        else if (board[_i][check_j] == 'p'){
                            res += 1;
                            break;
                        }
                        else if (board[check_i][check_j] == 'B') break;
                        else check_j += 1;
                    }
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

