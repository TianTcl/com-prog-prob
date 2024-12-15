#include <bits/stdc++.h>
using namespace std;

bool isDivisibleBy(const string& N, int divisor) {
    int remainder = 0;
    for (char digit : N) {
        int current = digit - '0';
        remainder = (remainder * 10 + current) % divisor;
    }
    return remainder == 0;
}


int main() {
    string str; char ans; bool ansVal = 0; int N, point = 0; cin >> N;
    while(N--) {
        cin >> str >> ans; if(ans == 'Y') ansVal = 1; else ansVal = 0;
        if( (bool)(isDivisibleBy(str, 19) || isDivisibleBy(str, 91)) == ansVal)
            point += 5;
        else point -= 10;
    }
    if(point <= 0) cout << 1;
    else cout << point*10;
    return 0;
}
