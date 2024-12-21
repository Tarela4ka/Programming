#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include <array>

using namespace std;

int ans;
vector<vector<char>> field;
vector<vector<int>> occ;

void diagonals(pair<int, int> pos){
    auto [y, x] = pos;
    for(int i = 1; y+i < 8 && x+i < 8; i++){
        if (field[y+i][x+i] != '*') break;
        occ[y+i][x+i] = 1;
    }
    for(int i = 1; y-i >= 0 && x-i >= 0; i++){
        if (field[y-i][x-i] != '*') break;
        occ[y-i][x-i] = 1;
    }
    for(int i = 1; y+i < 8 && x-i >= 0; i++){
        if (field[y+i][x-i] != '*') break;
        occ[y+i][x-i] = 1;
    }
    for(int i = 1; y-i >= 0 && x+i < 8; i++){
        if (field[y-i][x+i] != '*') break;
        occ[y-i][x+i] = 1;
    }
}

void horsNverts(pair<int, int> pos){
    auto [y,x] = pos;
    for(int i = 1; y+i < 8; i++){
        if (field[y+i][x] != '*') break;
        occ[y+i][x] = 1;
    }
    for(int i = 1; y-i >= 0; i++){
        if (field[y-i][x] != '*') break;
        occ[y-i][x] = 1;
    }
    for(int i = 1; x-i >= 0; i++){
        if (field[y][x-i] != '*') break;
        occ[y][x-i] = 1;
    }
    for(int i = 1; x+i < 8; i++){
        if (field[y][x+i] != '*') break;
        occ[y][x+i] = 1;
    }
}

void bishop(pair<int, int> pos){
    auto [y, x] = pos;
    vector<int> dy = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dx = {1, -1, 1, -1, 2, -2, 2, -2};
    for(int i = 0; i < dy.size(); i++){
        int ty = dy[i] + y, tx = dx[i] + x;
        if (ty >= 0 && ty < 8 && tx >= 0 && ty < 8){
            occ[ty][tx] = 1;
        }
    }
}
void pawns(pair<int, int> pos, char color){
    auto [y, x] = pos;
    if (color == 'W'){
        y--;
        if (y >= 0){
            if (x+1 < 8) occ[y][x+1] = 1;
            if (x-1 >= 0) occ[y][x-1] = 1;
        }
    } else{
        y++;
        if (y < 8){
            if (x+1 < 8) occ[y][x+1] = 1;
            if (x-1 >= 0) occ[y][x-1] = 1;
        }
    }

}
void kings(pair<int, int> pos){
    auto [y, x] = pos;
    vector<int> dy = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dx = {0, 1, -1, 0, 1, -1, 1, -1};
    for(int i = 0; i < dy.size(); i++){
        int ty = dy[i] + y, tx = dx[i] + x;
        if (ty >= 0 && ty < 8 && tx >= 0 && ty < 8){
            occ[ty][tx] = 1;
        }
    }
}

int main(){
    string s;
    while(cin >> s){
        field.assign(8, vector<char>(8, '*'));
        occ.assign(8, vector<int>(8, 0));
        int yp = 0, xp = 0; 
        for(int i = 0; i < s.length(); i++){
            if (s[i] == '/') yp++, xp = -1;
            else if (s[i] <= '9' && s[i] >= '0') xp += (s[i]-'0')-1;
            else {
                field[yp][xp] = s[i];
            }
            xp++;
        }
        // for(auto c : field){
        //     for(auto v : c){
        //         cout << v << "";
        //     }
        //     cout << endl;
        // }cout << endl;
        for(int y = 0; y < 8; y++){
            for(int x = 0; x < 8; x++){
                if (field[y][x] != '*') occ[y][x] = 1;
                else continue;
                if (field[y][x] == 'Q' || field[y][x] == 'q'){
                    diagonals({y, x});
                    horsNverts({y, x});
                }
                else if (field[y][x] == 'R' || field[y][x] == 'r'){
                    horsNverts({y, x});
                }
                else if (field[y][x] == 'B' || field[y][x] == 'b'){
                    diagonals({y,x});
                }
                else if (field[y][x] == 'N' || field[y][x] == 'n'){
                    bishop({y,x});
                }
                else if (field[y][x] == 'K' || field[y][x] == 'k'){
                    kings({y, x});
                }
                else if (field[y][x] == 'p'){
                    pawns({y, x}, 'B');
                }
                else if (field[y][x] == 'P'){
                    pawns({y, x}, 'W');
                }
            }
        }
        // for(auto c : occ){
        //     for(auto v : c){
        //         cout << v << "";
        //     }
        //     cout << endl;
        // }cout << endl;

        ans = 0;
        for(auto c : occ){
            for(auto v : c){
                ans += !v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}