#include<bits/stdc++.h>
using namespace std;

int main(){
    string DNA1,DNA2;
    cin >> DNA1 >> DNA2;
    int ans = 0;
    for(int i = 0; i < DNA1.size();++i)
        ans += (DNA1[i] != DNA2[i]);
    cout << ans << "\n";
    return 0;
}
