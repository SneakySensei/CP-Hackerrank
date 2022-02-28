// HACKERRANK PROBLEM - https://www.hackerrank.com/challenges/fair-rations/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairRations' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY B as parameter.
 */

string fairRations(vector<int> B)
{
  int sum = 0;
  for (int i = 0; i < B.size(); i++)
  {
    sum += B[i];
  }

  if (sum % 2 != 0)
  {
    return "NO";
  }
  else
  {
    int total = 0;
    for (int i = 0; i < B.size() - 1; i++)
    {
      if (B[i] % 2 == 1)
      {
        B[i]++;
        B[i + 1]++;
        total += 2;
      }
    }
    return to_string(total);
  }
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string N_temp;
  getline(cin, N_temp);

  int N = stoi(ltrim(rtrim(N_temp)));

  string B_temp_temp;
  getline(cin, B_temp_temp);

  vector<string> B_temp = split(rtrim(B_temp_temp));

  vector<int> B(N);

  for (int i = 0; i < N; i++)
  {
    int B_item = stoi(B_temp[i]);

    B[i] = B_item;
  }

  string result = fairRations(B);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
