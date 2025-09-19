class Spreadsheet {
public:
    vector<vector<int>> grid;

    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, col] = getRowCol(cell);
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        auto [row, col] = getRowCol(cell);
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        // Example formula format: "=A1+B2"
        string s = formula.substr(1); // remove '='
        int plusIdx = s.find('+');
        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx + 1);

        return solve(left) + solve(right);
    }

private:
    pair<int,int> getRowCol(const string &cell) {
        
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    int solve(string &d) {
        if (isdigit(d[0])) {
            return stoi(d); 
        }
        auto [row, col] = getRowCol(d);
        return grid[row][col];
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */