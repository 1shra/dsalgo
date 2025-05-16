#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int x, int y, int rows, int cols) {
    return x >= 0 && y >= 0 && x < rows && y < cols;
}

bool searchWordInMatrix(const vector<vector<char>>& matrix, const string& word, int x, int y, int index) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (index == word.length()) {
        return true;  // Word has been found
    }

    if (!isSafe(x, y, rows, cols) || matrix[x][y] != word[index]) {
        return false;
    }
    
    // Temporarily mark the cell as visited by changing its character
    char temp = matrix[x][y];
    matrix[x][y] = '#'; // Mark as visited

    // Explore all 8 possible directions
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                             {0, -1},           {0, 1},
                             {1, -1}, {1, 0}, {1, 1}};

    bool found = false;
    for (auto dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        found = found || searchWordInMatrix(matrix, word, newX, newY, index + 1);
    }
}
bool findWord(vector<vector<int>> & vec,string word){
    int row= vec.size();
    int col = vec[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(searchWordInMatrix(vec,word,i,j,0)){
                return true;
            }
        }
    }
}

int main() {
    vector<vector<char>> matrix = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    string word = "ABCCED";
    
    if (findWord(matrix, word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found!" << endl;
    }
    
    return 0;
}