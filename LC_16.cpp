// LC_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int twoSum(vector<int>& a, int s, int t) {
  int result = 0;
  bool init = false;
  for (int i = s, j = a.size()-1; i < j;)
  {
    if (!init) {
      result = a[i] + a[j]; // init
      init = true;
    }
      
    result = abs (t - ( a[i] + a[j] ) ) < abs(t - result) 
      ? a[i] + a[j] 
      : result;
    if (result == t)
      break;
    int oldJ = j, oldI = i;
    
    if    ((t - a[i] < a[j])
      &&  (j - 1 > i)) {
      j--;
    }
    if ((t - a[j] > a[i])
      && (i + 1 < j)) {
      i++;
    }

    if (oldJ == j && i == oldI) {
      return result;
    }
  }

  return result;
}

int threeSumClosest(vector<int>& nums, int target) {
  int r;
  bool init = false;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; ++i) {
    int u = twoSum(nums, i + 1, target - nums[i]);
    r = !init
      ? nums[i] + u
      : (abs(target - (nums[i] + u)) < abs(target - r)) ? nums[i] + u : r;
    init = true;
  }

  return r;
}

int main()
{
  vector<int> a{ -1,2,1,-4 };
  vector<int> b{ 0,0,0 };
  vector<int> c{ -4,2,2,3,3,3 }; // t : 
  vector<int> d{ 1,2,7,13 };
  vector<int> e{-2,-1, 1, 4}; // t : 0 , e : 1
  vector<int> f{ 4,0,5,-5,3,3,0,-4,-5 };

  // t : -2805 , e : -2805
  vector<int> g{ 13,252,-87,-431,-148,387,-290,572,-311,-721,222,673,538,919,483,-128,-518,7,-36,-840,233,-184,-541,522,-162,127,-935,-397,761,903,-217,543,906,-503,-826,-342,599,-726,960,-235,436,-91,-511,-793,-658,-143,-524,-609,-728,-734,273,-19,-10,630,-294,-453,149,-581,-405,984,154,-968,623,-631,384,-825,308,779,-7,617,221,394,151,-282,472,332,-5,-509,611,-116,113,672,-497,-182,307,-592,925,766,-62,237,-8,789,318,-314,-792,-632,-781,375,939,-304,-149,544,-742,663,484,802,616,501,-269,-458,-763,-950,-390,-816,683,-219,381,478,-129,602,-931,128,502,508,-565,-243,-695,-943,-987,-692,346,-13,-225,-740,-441,-112,658,855,-531,542,839,795,-664,404,-844,-164,-709,167,953,-941,-848,211,-75,792,-208,569,-647,-714,-76,-603,-852,-665,-897,-627,123,-177,-35,-519,-241,-711,-74,420,-2,-101,715,708,256,-307,466,-602,-636,990,857,70,590,-4,610,-151,196,-981,385,-689,-617,827,360,-959,-289,620,933,-522,597,-667,-882,524,181,-854,275,-600,453,-942,134 };


  //sort(f.begin(), f.end());
  //int r = twoSum(f, 1, -2);

  int r;
  r = threeSumClosest(a, 1);        // t: 1, e: 1
  cout << "Result : " << r << endl;  
  r = threeSumClosest(g, -2805);    // t: -2805, e: -2805
  cout << "Result : " << r << endl;  
  r = threeSumClosest(b, 0);        // t: 0, e: 0
  cout << "Result : " << r << endl;
  r = threeSumClosest(c, -2);       // t: -2, e: 0
  cout << "Result : " << r << endl;
  r = threeSumClosest(f, -2);       // t: -2, e: -2
  cout << "Result : " << r << endl;
  r = threeSumClosest(d, 12);       // t: 12, e: 10
  cout << "Result : " << r << endl;
  r = threeSumClosest(e, 0);        // t: 0 , e: 1
  cout << "Result: " << r << endl;


  std::cout << "End of Program!\n";
}


