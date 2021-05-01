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
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
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
const ll N = 18;




void c_p_p()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\KIIT\\input", "r", stdin);
    freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif
}












void dfs_1(ll u, ll par, vector<vector<ll>>& graph, vector<ll>& level, ll lvl,
           vector<vector<ll>>& parent) {
    level[u] = lvl;
    parent[u][0] = par;
    for (auto to : graph[u]) {
        if (to == par) continue;
        dfs_1(to, u, graph, level, lvl + 1, parent);
    }
}

void dfs_2(ll u, ll par, vector<vector<ll>>& graph, vector<ll>& fine, set<ll>& spec) {
    for (auto to : graph[u]) {
        if (to == par)
            continue;
        dfs_2(to, u, graph, fine, spec);
        if (fine[to] != -1) {
            fine[u] = fine[to];
        }
    }
    if (fine[u] == -1) {
        if (spec.count(u)) {
            fine[u] = u;
        }
    }
}
void answer() {
    ll n, k, a;
    cin >> n >> k >> a;
    a--;
    vector<vector<ll>> graph(n);
    set<ll> spec;
    for (ll i = 0; i < k; i++) {
        ll temp;
        cin >> temp;
        temp--;
        spec.insert(temp);
    }
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<vector<ll>> par(n, vector<ll>(N, -1));
    vector<ll> lvl(n);
    dfs_1(a, -1, graph, lvl, 0, par);
    for (ll level = 1; level < N; level++) {
        for (ll i = 0; i < n; i++) {
            if (par[i][level - 1] != -1) {
                par[i][level] = par[par[i][level - 1]][level - 1];
            }
        }
    }
    vector<ll> fine(n, -1);
    dfs_2(a, -1, graph, fine, spec);
    vector<ll> ans1(n), ans2(n);
    for (ll node = 0; node < n; node++) {
        if (fine[node] != -1) {
            ans1[node] = lvl[node];
            ans2[node] = fine[node];
            continue;
        }
        ll curr = node;
        ll last = N - 1;
        while (1) {
            ll flag = 0;
            ll temp_last;
            for (ll lvl = last; lvl >= 0; lvl--) {
                ll u = par[curr][lvl];
                temp_last = lvl;
                if (u == -1) continue;
                if (fine[u] == -1) {
                    curr = u;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                curr = par[curr][0];
                last = temp_last;
                break;
            }
        }
        ll d1 = lvl[curr];
        ll d2 = lvl[node] - lvl[curr];
        ans1[node] = d1 - d2;
        ans2[node] = fine[curr];
    }
    for (ll i = 0; i < n; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (ll i = 0; i < n; i++) {
        cout << ans2[i] + 1 << " ";
    }
    cout << endl;
}

main() {
    c_p_p();
    ll t;
    cin >> t;
    while (t--) {
        answer();
    }



    /* **************** Your main function Code Above ****************** */

    return 0;
}
