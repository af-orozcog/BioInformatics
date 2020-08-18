#include<bits/stdc++.h>
#define ll long long
using namespace std;

int nextError(int lo, int hi,int left,ll dp1[], ll dp2[], ll ar11[], ll ar12[], ll ar21[], ll ar22[], ll mod1, ll mod2){
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        int siz = mid-left+1;
        ll imp11 = ar11[mid];
        ll imp12 = ar12[mid];
        ll imp21 = ar21[mid-left];
        ll imp22 = ar22[mid-left];
        if(lo != 0) imp11 -= ar11[lo-1]*dp1[mid-lo+1] , imp12 -= ar12[lo-1]*dp2[mid-lo+1];
        if(lo - left != 0) imp21 -= ar21[lo-left-1]*dp1[mid-lo+1], imp22 -= ar22[lo-left-1]*dp2[mid-lo+1];
        if(abs(imp11) >= mod1) imp11 %= mod1;
        if(abs(imp12) >= mod2) imp12 %= mod2;
        if(abs(imp21) >= mod1) imp21 %= mod1;
        if(abs(imp22) >= mod2) imp22 %= mod2;
        if(imp11 < 0) imp11 += mod1;
        if(imp12 < 0) imp12 += mod2;
        if(imp21 < 0) imp21 += mod1;
        if(imp22 < 0) imp22 += mod2;
        if(imp11 != imp21 || imp12 != imp22){
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid +1;
    }
    return ans;
}


vector<int> solve(int k, const string &text, const string &pattern) {
    vector<int> ans;
    ll mod1 = 1000000009, mod2 = 1000000007;
    ll dp1[pattern.size()+1];
    ll dp2[pattern.size()+1];
    dp1[0] = dp2[0] = 1;
    for(int i = 1; i < (int)pattern.size()+1;++i){
        dp1[i] = dp1[i-1]*31ll; dp2[i] = dp2[i-1]*31ll;
        if(dp1[i] >= mod1) dp1[i] %= mod1;
        if(dp2[i] >= mod2) dp2[i] %= mod2;
        //cout << dp1[i] << " " << dp2[i] << endl;
    }
    ll ar11[text.size()], ar12[text.size()];
    ll ar21[pattern.size()], ar22[pattern.size()];
    ar11[0] = ar12[0] = text[0];
    for(int i = 1; i < text.size();++i){
        ar11[i] = ar11[i-1]*31ll; ar12[i] = ar12[i-1]*31ll;
        if(ar11[i] >= mod1) ar11[i] %= mod1;
        if(ar12[i] >= mod2) ar12[i] %= mod2;
        ar11[i] += text[i];
        ar12[i] += text[i];
        if(ar11[i] >= mod1) ar11[i] %= mod1;
        if(ar12[i] >= mod2) ar12[i] %= mod2;
    }
    ar21[0] = ar22[0] = pattern[0];
    for(int i = 1; i < pattern.size();++i){
        ar21[i] = ar21[i-1]*31ll; ar22[i] = ar22[i-1]*31ll;
        if(ar21[i] >= mod1) ar21[i] %= mod1;
        if(ar22[i] >= mod2) ar22[i] %= mod2;
        ar21[i] += pattern[i];
        ar22[i] += pattern[i];
        if(ar21[i] >= mod1) ar21[i] %= mod1;
        if(ar22[i] >= mod2) ar22[i] %= mod2;
    }
    for(int i = 0; i <= (int)text.size()-(int)pattern.size();++i){
        int to = i + (int)pattern.size() -1;
        int errors = 0;
        int lo = i;
        while(errors <= k && lo <= to){
             lo = nextError(lo,to,i,dp1,dp2,ar11,ar12,ar21,ar22,mod1,mod2);
             if(lo == -1) break;
             ++errors;
             lo += 1;
        }
        if(errors <= k) ans.push_back(i);
    }
    return ans;
}


vector<string> ans;
int coun;
string text;
char letters[] = {'A','G','T','C'};
int k,d;

void generateStrings(string &temp){
    if((int)temp.size() == k){
        vector<int> see = solve(d,text,temp);
        if((int)see.size() > coun){
            ans.clear();
            ans.push_back(temp);
            coun = see.size();
        }
        else if((int)see.size() == coun)
            ans.push_back(temp);
        return;
    }
    for(int i = 0; i < 4;++i){
        temp += letters[i];
        generateStrings(temp);
        temp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> text;
    cin >> k >> d;
    string temp;
    generateStrings(temp);
    for(auto va:ans)
        cout << va << " ";
    cout << "\n";
    return 0;
}
