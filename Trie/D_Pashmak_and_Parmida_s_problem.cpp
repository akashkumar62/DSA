// #include <algorithm>
// #include <bitset>
// #include <cassert>
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <climits>
// #include <cmath>
// #include <complex>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct segTree{

 int n;
 vector<int>seg;

 public:


 segTree(int x){
   n = x;
   seg.resize(4*n,0);
 }


 int query(int ind, int low, int high, int l, int r)
 {
	if(r < low || l > high) return 0;

	if(low >= l && high<=r) return seg[ind];

	int mid = low + (high-low) / 2;

	int left = query(2*ind+1, low, mid, l, r);
	int right= query(2*ind+2,mid+1, high,l,r);

	return left + right; 
 }

 void update(int ind, int low, int high, int i, int val)
 {
	if(low == high)
	{
		if(low == i)
		seg[ind] += val;

		return;
	}

	int mid = low + (high-low) / 2;
    
	if(i<=mid)
	update(2*ind+1, low, mid, i, val);
	else
	update(2*ind+2,mid+1,high, i,val);

	seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 

 }

};

int main()
{
    int n;
	cin>>n;

	vector<int>nums(n);

	for(auto & x: nums)
	cin>>x;

	vector<int>f1(n,0),f2(n,0);

	map<int,int>mp;

	for(int i=0;i<n;i++)
	{
		mp[nums[i]]++;
		f1[i] = mp[nums[i]];
	} 
	mp.clear();

	for(int i=n-1;i>=0;i--)
	{
		mp[nums[i]]++;
		f2[i] = mp[nums[i]];
	}

	// for(auto x: f1)
	// cout<<x<<" ";

	// cout<<"\n";

	// for(auto x:f2)
	// cout<<x<<" ";

	vector<pair<int,int>>v(n);

	for(int i=0;i<n;i++)
	{
		v[i] = {f1[i],i};
	}
    
	sort(begin(v), end(v));
	map<pair<int,int>, int> mp1;

	for(int i=0;i<n;i++)
	{
		mp1[v[i]] = i;
	}

	segTree st(n);

	ll cnt = 0;

	for(int i=0;i<n;i++)
	{
		int pos1 = mp1[{f1[i],i}];
		int pos2 = upper_bound(v.begin(), v.end() , make_pair(f2[i], INT_MAX)) - v.begin();
        
		if(pos2<n)
		cnt += st.query(0,0,n-1,pos2,n-1);

		st.update(0, 0, n-1, pos1, 1);
	}

    cout<<cnt<<" ";


	return 0;
}
