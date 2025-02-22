// LC_953.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
  map<char, int> m;
  for (int i = 0; i < order.size(); ++i) {
    m[order[i]] = i;
  }

  if (words.size() <= 1) return true;
  for (int i = 0; i < words.size() - 1; ++i) {
    for (int j = 0; j < words[i].size(); ++j) {
      if (j > words[i + 1].size() - 1)
        return false;
      if (m[words[i][j]] > m[words[i + 1][j]])
        return false;
      else if (m[words[i][j]] < m[words[i + 1][j]])
        break;
    }
  }
  return true;
}

int main()
{
  //vector<string> a{"my", "f"};
  //string s = "gelyriwxzdupkjctbfnqmsavho";
  //bool r = isAlienSorted(a, s);
  //std::cout << "Result: " << r << "!\n";

  vector<string> a{ "word","world","row" };
  string s = "worldabcefghijkmnpqstuvxyz";
  bool r = isAlienSorted(a, s);
  std::cout << "Result: " << (r ? "true" : "false") << "!\n";
}


