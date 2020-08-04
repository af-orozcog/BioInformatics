#include<bits/stdc++.h>
using namespace std;

int patternCount(string &text, int size){
    vector<int> kmp(text.size(),0);
    int border = 0;
    int ans = 0;
    for(int i = 1; i < text.size();++i){
        while(border > 0 && text[i] != text[border])
            border = kmp[border-1];
        if(text[border] == text[i])
            ++border;
        kmp[i] = border;
        if(border == size)
            ++ans;
    }
    return ans;
}


int main(){
    string text,pattern;
    cin >> text >> pattern;
    string send = pattern + "$" + text;
    cout << patternCount(send,pattern.size()) << "\n";
    return 0;
}
