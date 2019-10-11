#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    string cry;cin >> cry;
    string key;cin >> key;
    string table[26];
    string s;
    rep(i,26){
        s += 'A' + i;
    }
    s += s;
    rep(i,26){
        table[i] = s.substr(i, 26);
    }
    // cout << table[1] << endl;
    string res_1, res_2;
    rep(i,cry.size()){
        int cry_it = cry[i] - 'A';
        int key_it = key[i] - 'A';
        res_1 += table[cry_it][key_it];
        res_2 += table[key_it][cry_it];
    }
    cout << res_1 << endl;
    cout << res_2 << endl;

    string res;
    rep(i,cry.size()){
        int cry_it = cry[i] - 'A';
        int key_it = key[i] - 'A';
        int pos = table[key_it].find(cry[i]);
        res += 'A' + pos;
    }
    cout << res << endl;
}