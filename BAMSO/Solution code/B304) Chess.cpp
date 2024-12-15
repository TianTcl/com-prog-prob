#include <bits/stdc++.h>
using namespace std;
int main() {
    string name[2],board[8]; int rating[2],g[2];
    char FEN[100]; cin >> FEN;
    getchar(); getline(cin,name[0]); cin >> rating[0] >> g[0];
    getchar(); getline(cin,name[1]); cin >> rating[1] >> g[1];
    int len = strlen(FEN), i = 0, j = 0;
    for (int k = 0; k < len; k++) {
        if (FEN[k] == '/') {
            for (; j < 8; j++) {
                board[i][j] = '0';
            }
            i++;
            j = 0;
        } else if (isalpha(FEN[k])) {
            board[i][j] = FEN[k];
            j++;
        } else if (isdigit(FEN[k])) {
            for (int l = 0; l < FEN[k] - '0'; l++) {
                board[i][j] = '0';
                j++;
            }
        }
    } printf("# a b c d e f g h #");
    for(int i = 0; i < 8; i++) {
        cout << endl << 8 - i << " ";
        for(int j = 0; j < 8; j++) {cout << board[i][j] << " ";}
        cout << 8 - i;
    }
    printf("\n# a b c d e f g h #");cout << fixed << setprecision(0);
    double E,R[2],S[3] = {1,0.5,0}; int K;
    for(int i = 0; i < 2; i++) {
        if(rating[i] >= 2400) K = 10;
        else if(g[i] >= 30) K = 20;
        else K = 40;
        if(i == 0) {
            E = 1/(1+pow(10,(rating[1]-rating[0])/400.0));
            cout << "\nW: " << name[0] << "(" << rating[0] << ")";
        }
        else {
            E = 1/(1+pow(10,(rating[0]-rating[1])/400.0));
            cout << "\nB: " << name[1] << "(" << rating[1] << ")";
        }
        if(i == 0) for(int j = 0; j < 3; j++) {
            cout << " " << rating[i] + K*(S[j]-E);
        } else for(int j = 2; j >= 0; j--) {
            cout << " " << rating[i] + K*(S[j]-E);
        }
    }
}
