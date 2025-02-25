// LC_523.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
  if (nums.size() < 2) return false;
  map<int, int> rems;
  rems[0] = -1;
  int ps = 0;

  for (int i = 0; i < nums.size(); ++i) {
    ps += nums[i];
    int rem = ps % k;
    if (!rems.count(rem)) {
      rems[rem] = i;
    }
    else if (i - rems[rem] > 1) {
      return true;
    }
  }
  return false;
}


int main()
{
  vector<int> a{ 0, 0 };
  bool r = checkSubarraySum(a, 1);
  std::cout << (r ? "TRUE" : "FALSE") << endl;  // TRUE

  vector<int> b{ 1, 1};
  r = checkSubarraySum(b, 1);
  std::cout << (r ? "TRUE" : "FALSE") << endl;  // TRUE

  vector<int> c{ 1, 3, 0, 6  };
  r = checkSubarraySum(c, 6);
  std::cout << (r ? "TRUE" : "FALSE") << endl;  // TRUE

  vector<int> d{ 0,1,0,3,0,4,0,4,0 };
  r = checkSubarraySum(d, 5);
  std::cout << (r ? "TRUE" : "FALSE") << endl;  // FALSE
}

