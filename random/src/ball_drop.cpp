#include <iostream>
#include <vector>

using namespace std;

class DropBoard{
public:
    DropBoard(const vector<vector<int>> &board):board(board){}
    
    int drop_ball(const int &start_pos);

    vector<vector<int>> board;
};


int DropBoard::drop_ball(const int &start_pos){
    int k = start_pos;
    for(auto row : this->board){
        if(k < 0 || k >= this->board[0].size()){
            return -1;
        }

        if(row[k] == -1){
            // Look left
            if(k == 0 || row[k-1] != -1){
                return -1;
            } else {
                k--;
            }
        }

        if(row[k] == 1){
            // Look right
            if(k >= this->board[0].size() - 1 || row[k + 1] != 1){
                return -1;
            } else {
                k++;
            }
        }

    }
    return k;
}

int main(){
    vector<vector<int>> board = {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {1,1,1,-1}, {-1,1,1,-1}};

    DropBoard game_board(board);
    int soln;

    for(int n = 0; n < 4; n++){
        cout << "Drop at idx: " << n << endl;
        soln = game_board.drop_ball(n);
        cout << "Lands at idx: " << soln << endl << endl;
    }
}