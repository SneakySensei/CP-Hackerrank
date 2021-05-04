// HACKERRANK PROBLEM - https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    bool isPM = s[8] == 'P';
    
    int hr = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,5));
    int sec = stoi(s.substr(6,8));
    
    if(hr!=12){
        if(isPM){
            hr+=12;
        }
    }else {
        if(!isPM){
            hr-=12;
        }
    }
    
    string res = (hr<10 ? "0" : "") + to_string(hr) + ':' + (min<10 ? "0" : "") + to_string(min) + ':' + (sec<10 ? "0" : "") + to_string(sec);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
