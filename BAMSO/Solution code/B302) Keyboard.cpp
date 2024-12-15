#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

unordered_map<char, char> dvorakToQwertyMap = {
    {'`', '`'}, {'1', '1'}, {'2', '2'}, {'3', '3'}, {'q', '4'}, {'j', '5'}, {'l', '6'}, {'m', '7'}, {'f', '8'}, {'p', '9'}, {'/', '0'}, {'[', '-'}, {']', '='},
    {'4', 'q'}, {'5', 'w'}, {'6', 'e'}, {'.', 'r'}, {'o', 't'}, {'r', 'y'}, {'s', 'u'}, {'u', 'i'}, {'y', 'o'}, {'b', 'p'}, {';', '['}, {'=', ']'}, {'\\', '\\'},
    {'7', 'a'}, {'8', 's'}, {'9', 'd'}, {'a', 'f'}, {'e', 'g'}, {'h', 'h'}, {'t', 'j'}, {'d', 'k'}, {'c', 'l'}, {'k', ';'}, {'-', '\''},
    {'0', 'z'}, {'z', 'x'}, {'x', 'c'}, {',', 'v'}, {'i', 'b'}, {'n', 'n'}, {'w', 'm'}, {'v', ','}, {'g', '.'}, {'\'', '/'}, {' ', ' '},
    {'~', '~'}, {'!', '!'}, {'@', '@'}, {'#', '#'}, {'Q', '$'}, {'J', '%'}, {'L', '^'}, {'M', '&'}, {'F', '*'}, {'P', '('}, {'?', ')'}, {'{', '_'}, {'}', '+'},
    {'$', 'Q'}, {'%', 'W'}, {'^', 'E'}, {'>', 'R'}, {'O', 'T'}, {'R', 'Y'}, {'S', 'U'}, {'U', 'I'}, {'Y', 'O'}, {'B', 'P'}, {':', '{'}, {'+', '}'}, {'|', '|'},
    {'&', 'A'}, {'*', 'S'}, {'(', 'D'}, {'A', 'F'}, {'E', 'G'}, {'H', 'H'}, {'T', 'J'}, {'D', 'K'}, {'C', 'L'}, {'K', ':'}, {'_', '"'},
    {')', 'Z'}, {'Z', 'X'}, {'X', 'C'}, {'<', 'V'}, {'I', 'B'}, {'N', 'N'}, {'W', 'M'}, {'V', '<'}, {'G', '>'}, {'"', '?'}
};

string DvorakToQwerty(const string &input) {
    string result;
    for (char ch : input) {
        if (dvorakToQwertyMap.count(ch)) result += dvorakToQwertyMap[ch]; else result += ch;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string DvorakText; getline(cin, DvorakText);
    cout << DvorakToQwerty(DvorakText) << endl;
    return 0;
}
