#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


int cardToI(string s){
    map<char, int> cardTranslate;
    cardTranslate['D'] = -2; cardTranslate['C'] = 11; cardTranslate['H'] = 24; 
    cardTranslate['S'] = 37; cardTranslate['T'] = 10; cardTranslate['J'] = 11;
    cardTranslate['Q'] = 12; cardTranslate['K'] = 13; cardTranslate['A'] = 14;
    for(int i = 2; i <= 9; i++) cardTranslate['0'+i] = i;
    return (cardTranslate[s[0]] + cardTranslate[s[1]]);
}

string cardToS(int n){
    string card;
    card.resize(2);
    if (n<=12){
        card[1] = 'D';
        n+=2;
    }else if (n <= 25){
        card[1] = 'C';
        n-=11;
    }else if (n <= 38){
        card[1] = 'H';
        n-=24;
    }else if (n <= 51){
        card[1] = 'S';
        n-=37;
    }
    if (n < 10) card[0] = '0'+n;
    else if (n == 10) card[0] = 'T';
    else if (n == 11) card[0] = 'J';
    else if (n == 12) card[0] = 'Q';
    else if (n == 13) card[0] = 'K';
    else if (n == 14) card[0] = 'A';
    return card;
}

int main(){
    int t; cin >> t;

    for(int caseN = 1; caseN <= t; caseN++){
        vector<string> cards(52);
        for(int i = 0; i < 52; i++) {
            cin >> cards[i];
        }
        int x = 0, y = 0, remain = 26;
        string hand = "";
        for(int i = 0; i < 3; i++){
            string card = cards[remain];
            if (card[0] <= '9') x = card[0]-'0';
            else x = 10;
            remain--;
            remain = remain - (10-x);
            y += x;
        }
        for(int i = 0; i < 25; i++) hand += cards[51-i];
        for(int i = 0; i < remain; i++) hand+=cards[i];
        reverse(hand.begin(), hand.end());
        // printf("Case %d: %c%c\n", caseN, hand[(y-1)*2-1], hand[(y-1)*2-2]);
        cout << "Case " << caseN << ": " << hand[(y-1)*2-1] << hand[(y-1)*2-2] << endl;
    }
}