#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

double calculateClockAngle(int hour, int minute, int second) {
    hour %= 12;
    double hourAngle = (hour * 30) + (minute * 0.5) + (second * (0.5 / 60));
    double minuteAngle = (minute * 6) + (second * 0.1);
    double angle = abs(hourAngle - minuteAngle);
    return min(angle, 360 - angle);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char input[10], out[] = "0:00:00";
    int hour, minute, second;
    cout << fixed << setprecision(3);
    while(cin >> input) {
        if(strcmp(input, out) == 0) break;
        if(input[1] == ':') {
            hour = input[0] - '0';
            minute = (input[2] - '0') * 10 + (input[3] - '0');
            second = (input[5] - '0') * 10 + (input[6] - '0');
        } else {
            hour = (input[0] - '0') * 10 + (input[1] - '0');
            minute = (input[3] - '0') * 10 + (input[4] - '0');
            second = (input[6] - '0') * 10 + (input[7] - '0');
        }
        cout << calculateClockAngle(hour, minute, second) << endl;
    }
    return 0;
}
