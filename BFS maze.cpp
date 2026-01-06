#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;


bool seen(pair<int, int> x,vector<pair<int, int>> vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == x){
            return true;
        }
    }
    return false;
}

pair<int,int> Location(vector<string> grid,char token){
    for(int row = 0;row < grid.size();row++){
        for(int col = 0;col < grid[0].size();col++){
            if(grid[row][col] == token){
                return make_pair(row,col);
            }
        }
    }
    return make_pair(-1,-1);
}

int main()
{  
    int Row,Col,e;
    string x;
    cin >> Row;
    cin >> Col;
    cin.ignore();
    pair<int, int> end;
    pair<int, int> begin;
    vector<pair<int, int>> vec;
    vector<string> grid(Row);
    for (int i = 0; i < Row; i++){
        getline(cin, grid[i]);
    }
    
	begin = Location(grid, 'S');
    end = Location(grid, 'G');


    int distance[Row][Col];
    queue<pair<int, int>> q;
    for(int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
        	e=-3;
            distance[i][j] = e;
        }
    }
    pair<int, int> parent[Row][Col];
    for(int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            parent[i][j] = std::make_pair(-2, -2);
        }
    }
    q.push({begin.first, begin.second});
    vec.push_back({begin.first, begin.second});
    while (q.size() != 0 && (seen(end, vec) == false)){
        pair<int, int> curr;
        curr = q.front();
        q.pop();
        bool safe = true;
        if ((curr.first + 1 > (Row - 1)) || ((curr.first < 0) && (curr.first > Row)) ||(grid[curr.first + 1][curr.second] == 'x')){
            safe = false;
        }

        if (safe == true && seen({curr.first + 1, curr.second}, vec) == false){
            distance[curr.first + 1][curr.second] = distance[curr.first][curr.second] + 1;
            parent[curr.first + 1][curr.second] = curr;
            q.push({curr.first + 1, curr.second});
            vec.push_back({curr.first + 1, curr.second});
        }
        safe = true;
        if ((curr.second - 1 < 0) || (grid[curr.first][curr.second - 1] == 'x') || (curr.second < 0) || (curr.second > Col)){
            safe = false;
        }
        if (safe == true && seen({curr.first, curr.second - 1}, vec) == false){
            distance[curr.first][curr.second - 1] = distance[curr.first][curr.second] + 1;
            parent[curr.first][curr.second - 1] = curr;
            q.push({curr.first, curr.second - 1});
            vec.push_back({curr.first, curr.second - 1});
        }
        safe = true;
        if ((curr.first - 1 < 0) || ((curr.first < 0) && (curr.first > Row)) || (grid[curr.first - 1][curr.second] == 'x')){
            safe = false;
        }
        if (safe == true && seen({curr.first - 1, curr.second}, vec) == false){
            distance[curr.first - 1][curr.second] = distance[curr.first][curr.second] + 1;
            parent[curr.first - 1][curr.second] = curr;
            q.push({curr.first - 1, curr.second});
            vec.push_back({curr.first - 1, curr.second});
        }
        safe = true;
        if ((curr.second + 1 > (Col - 1)) || (grid[curr.first][curr.second + 1] == 'x') || (curr.second < 0) || (curr.second > Col)){
            safe = false;
        }
        if (safe == true && seen({curr.first, curr.second + 1}, vec) == false){
            distance[curr.first][curr.second + 1] = distance[curr.first][curr.second] + 1;
            parent[curr.first][curr.second + 1] = curr;
            q.push({curr.first, curr.second + 1});
            vec.push_back({curr.first, curr.second + 1});
        }
    }
    if (q.size() == 0 && seen(end, vec) == false){
        cout << "No Path" << endl;
    }
    else{
        vector<std::pair<int, int>> outputList;
    	pair<int,int> curr;
        curr = end;
        while (curr != begin){
            outputList.push_back(curr);

            curr = parent[curr.first][curr.second];

        }
        for (int i = 0; i < outputList.size(); i++){
            int k = (outputList[i]).first;
            int l = (outputList[i]).second;
            if (i > 0){
            grid[k][l] = '*';
            }
        }
        for(auto line : grid){
            cout << line << endl;
        }

    }

    return 0;
}

