/*
 * Author Chaudhary Hamdan
 * C++ Template for Competitive Programming
 * Github link : https://github.com/hamdan-codes
 */

/*
 * Template available at my Github
 * Repository Link :-
 * https://github.com/hamdan-codes/templates-for-CP/
 */




#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define vs              vector<string>
#define gi              greater<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define all(x)          x.begin(),x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define gcd             __gcd
#define mod             1000000007
#define pi              3.14159265358979323846264338327950288419716939937510
#define inf             LONG_LONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            '\n'
#define mk(type,arr,n)  type *arr=new type[n]
#define w(x)            int x; cin >> x; while(x--)
#define f(i,x,y)        for(int i = x; i < y; i++)
#define rf(i,x,y)       for(int i = x; i >= y; i--)
#define test(x)         int zyx; cin >> zyx; for(int x=1;x<=zyx;x++)



using namespace std;

using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif
}

/* ********************* Your Functions and Classes Below ********************** */





void answer() {
	int n, m, b; cin >> n >> m >> b;
	int ans = 0;
	vvi arry(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arry[i][j];
	for (int i = 1; i <= ((1 << n) - 1); i++) { // 001, 010...
		vi x_coor;
		for (int k = 0; k <= n - 1; k++) {
			if ((i & (1 << k)) != 0)
				x_coor.pb(k);
		}
		for (int j = 1; j <= ((1 << m) - 1); j++) {
			vi y_coor;
			int subans = 0;
			for (int kd = 0; kd <= m - 1; kd++) {
				if ((j & (1 << kd)) != 0)
					y_coor.pb(kd);
			}
			for (auto idx : x_coor) {
				for (auto idy : y_coor)
					subans += arry[idx][idy];
			}
			if (subans == b)
				ans = (ans + 1) % mod;
		}
	}
	cout << ans % mod << endl;
}



















/* ********************* Your Functions and Classes Above ********************** */

main()
{
	c_p_p();

	/* ******************* Your main function Code Below ******************* */


	w(t)
	{
		answer();
	}























	/* **************** Your main function Code Above ****************** */

	return 0;
}


