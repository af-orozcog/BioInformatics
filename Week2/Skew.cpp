#include<bits/stdc++.h>
using namespace std;

int main(){
    string DNA;
    cin >> DNA;
    int ans[(int)DNA.size()+1];
    ans[0] = 0;
    for(int i = 1; i <= (int)DNA.size();++i){
        ans[i] = ans[i-1];
        if(DNA[i-1] == 'C')
            --ans[i];
        else if(DNA[i-1] == 'G')
            ++ans[i];
    }
    for(int i = 0; i <= (int)DNA.size();++i)
        cout << ans[i] << " ";
    cout <<  "\n";
    return 0;
}
