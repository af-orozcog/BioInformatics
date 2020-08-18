#include<bits/stdc++.h>
using namespace std;

vector<int> positions(string &text, int size){
    vector<int> kmp(text.size(),0);
    int border = 0;
    vector<int> answer;
    for(int i = 1; i < text.size();++i){
        while(border > 0 && text[i] != text[border])
            border = kmp[border-1];
        if(text[border] == text[i])
            ++border;
        kmp[i] = border;
        if(border == size)
            answer.push_back(i-size-size);
    }
    return answer;
}

int main(){
    string pattern,genome;
    cin >> pattern >> genome;
    string send = pattern + "$" + genome;
    vector<int> answer = positions(send,pattern.size());
    for(auto va:answer)
        cout << va << " ";
    cout << "\n";
    return 0;
}
