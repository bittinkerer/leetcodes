double median( vector<int>& a, int as, int ae, vector<int>& b, int bs, int be ) {
  int totalSize = a.size() + b.size();
  bool isOdd = totalSize % 2 != 0;

  int half  = totalSize / 2;
  int am    = as + (ae - as) / 2;
  int bm    = bs + (be - bs) / 2;
  int amv   = ae - as < 0 ? INT_MAX : a[am];
  int bmv   = be - bs < 0 ? INT_MAX : b[bm];
  
  if (amv <= bmv) {
    as = am;
    if (half - (bs + as) > 0) {
      as = min(am + 1, (int)a.size());
      as = max(0, as);
      int left = max(0, half - (as + bs));
      ae = min(am + 1 + left, (int)a.size() - 1);
      be = max(0, min(bs + left - 1, (int)b.size() - 1));
    }

    if (as + bs < half) {
      return median(a, as, ae, b, bs, be);
    }
    else {
      int af = as < a.size() ? a[as] : INT_MAX;
      int bf = bs < b.size() ? b[bs] : INT_MAX;
      int al = as > 0 ? a[as - 1] : INT_MIN;
      int bl = bs > 0 ? b[bs - 1] : INT_MIN;
      return isOdd ? min(af, bf) : (max(al, bl) + min(af, bf)) / 2.0;
    }
  }
  else {
    bs = bm;
    if (half - (bs + as) > 0) {
      bs = min(bm + 1, (int)b.size());
      bs = max(0, bs);
      int left = max(0,half - (bs + as));
      be = min(bm + 1 + left, (int)b.size() - 1);
      ae = max(0, min(as + left - 1, (int)a.size() - 1));
    }

    if (as + bs < half) {
      return median(a, as, ae, b, bs, be);
    }
    else {
      int af = as < a.size() ? a[as] : INT_MAX;
      int bf = bs < b.size() ? b[bs] : INT_MAX;
      int al = as > 0 ? a[as - 1] : INT_MIN;
      int bl = bs > 0 ? b[bs - 1] : INT_MIN;
      return isOdd ? min(af, bf) : (max(al, bl) + min(af, bf)) / 2.0;
    }
  }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  vector<int> m;
  return median(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
}



int main()
{
  vector<int> a{ 2,2,4,4 };
  vector<int> b{ 2,2,2,4,4 };
  //vector<int> a{ 1, 3 };
  //vector<int> b{ 2, 7 };
  //vector<int> a{ 1, 3 };
  //vector<int> b{ 2 };
  //vector<int> a{1,2};
  //vector<int> b{-1,3};
  //vector<int> b{ 1 };
  //vector<int> a;
  //vector<int> b{ 1,2,3 };
  //vector<int> b{ 1, 2 };
  //vector<int> a{ 1,2,3 };
  //vector<int> b{ 6,7,8,9,10,11 };
  //vector<int> a{ 2,4,5 };
  //vector<int> b{ 1,3 };
  //vector<int> a{ 1,7,8,9 };
  //vector<int> b{ 2,3,4,5,6,10 };
  double result = findMedianSortedArrays(a, b);
  

  cout << "Result: " << result << endl;
  return 0;
}