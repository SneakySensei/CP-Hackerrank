#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    bool isPM = s[8] == 'P';
    string rest = s.substr(2, 6);
    if (isPM) {
        if (hour != 12) {
            hour += 12;
        }

    } else {
        if (hour == 12) {
            hour = 0;
        }
    }

    return (hour < 10 ? "0" : "") + to_string(hour) + rest;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
