#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod1 = 1000000007, mod2 = 1000000009;
ll mul = 31;
ll dp1[5000001],dp2[5000001];
string DNA;

int main(){
    int k,l,t;
    cin >> DNA >> k >> l >> t;
    dp1[0] = dp2[0] = 1;
    for(int i = 1; i < 5000001;++i){
        dp1[i] = dp1[i-1]*mul;
        dp2[i] = dp2[i-1]*mul;
        if(dp1[i] >= mod1) dp1[i] = dp1[i] % mod1;
        if(dp2[i] >= mod2) dp2[i] = dp2[i] % mod2;
    }
    unordered_set<string> answer;
    unordered_map<ll,string> reverse;
    unordered_map<ll,int> count;
    vector<ll> ids(DNA.size(),-1);
    ll val1 = 0,val2 = 0;
    for(int i = 0,j = 0,q = 0; j < DNA.size();++j){
        val1 *= mul;
        val2 *= mul;
        if(val1 >= mod1) val1 %= mod1;
        if(val2 >= mod2) val2 %= mod2;
        val1 += DNA[j];
        val2 += DNA[j];
        if(val1 >= mod1) val1 -= mod1;
        if(val2 >= mod2) val2 -= mod2;
        if(j-q == k){
            val1 -= DNA[q]*dp1[k];
            val2 -= DNA[q]*dp2[k];
            if(abs(val1) >= mod1) val1 %= mod1;
            if(abs(val2) >= mod2) val2 %= mod2;
            if(val1 < 0ll) val1 += mod1;
            if(val2 < 0ll) val2 += mod2;
            ++q;
        }
        if(j-i == l){
            if(ids[i] != -1ll){
                --count[ids[i]];
                if(count[ids[i]] == 0){
                    reverse.erase(ids[i]);
                    count.erase(ids[i]);
                }
            }
            ++i;
        }
        if(j-q == k-1){
            ll see1 = val1 << 32;
            ll see2 = val2;
            ll imp = see1 + see2;
            if(!reverse.count(imp)){
                string add = DNA.substr(q,k);
                reverse[imp] = add;
                count[imp] = 1;
            }
            else
                ++count[imp];
            if(count[imp] >= t)
                answer.insert(reverse[imp]);
            ids[q] = imp;
        }
    }
    /*for(auto va:answer)
        cout << va << " ";
    cout << "\n";*/
    cout << answer.size() << "\n";
    return 0;
}
