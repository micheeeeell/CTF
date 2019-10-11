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

string rot13(string s, int it){
    string res;
    int n = s.size();
    for(auto i : s){
        if(isalpha(i)){
            int now = tolower(i) - 'a';
            now = (now < (26 - it) ? it : -(26-it));
            res += i + now;
        }
        else res += i;
        
    } 
    return res;
}

// string reverse_rot13(string s){
//     string res;
//     int n = s.size();
//     for(auto i : s){
//         int now = i - 'a';
//         if(isalpha(i))now -= 13;
//         res += 'a' + now;
//     } 
//     return res;
// }

int main(){
    // string s;cin >> s;
    string s;
    getline(cin, s);
    int n; cin >> n;
    // rep(i,26){
    //     cout << i+1 << endl;
    //     cout << rot13(s, i+1) << endl;
    // }
    cout << rot13(s, n) << endl;
}