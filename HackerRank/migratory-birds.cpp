#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// void display(vector<int> arr)
// {
//   for (int i = 0; i < arr.size(); i++)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }

// vector<int> mergeSort(vector<int> arr)
// {
//   if (arr.size() == 1)
//   {
//     return arr;
//   }
//   vector<int> L;
//   vector<int> R;
//   int midIndex = arr.size() / 2;
//   for (int i = 0; i < midIndex; i++)
//   {
//     L.push_back(arr[i]);
//   }
//   for (int i = midIndex; i < arr.size(); i++)
//   {
//     R.push_back(arr[i]);
//   }

//   L = mergeSort(L);
//   R = mergeSort(R);

//   display(L);
//   display(R);

//   vector<int> merged;
//   int i = 0;
//   int j = 0;
//   while (i < L.size() && j < R.size())
//   {
//     if (L[i] < R[j])
//     {
//       merged.push_back(L[i]);
//       i++;
//     }
//     else
//     {
//       merged.push_back(R[j]);
//       j++;
//     }
//   }

//   while (i < L.size())
//   {
//     merged.push_back(L[i]);
//     i++;
//   }
//   while (j < R.size())
//   {
//     merged.push_back(R[j]);
//     j++;
//   }

//   return merged;
// }

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr)
{
  vector<int> counts(arr.size(), 0);
  for (int i = 0; i < arr.size(); i++)
  {
    counts[arr[i]]++;
  }
  int max = 0;
  int maxIndex = 0;
  for (int i = 0; i < counts.size(); i++)
  {
    if (counts[i] > max)
    {
      max = counts[i];
      maxIndex = i;
    }
  }

  return maxIndex;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string arr_count_temp;
  getline(cin, arr_count_temp);

  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++)
  {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = migratoryBirds(arr);

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
