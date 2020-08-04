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
    //the DNA string
    string DNA;

    //the k-mer size we want to use
    int k;

    cin >> DNA >> k;

    //count array
    vector<int> counter(DNA.size(),0);

    //the maximum amount of times a k-mer appears
    int maximum = 0;

    for(int i = 0; i < (int)DNA.size()-k+1;++i){
        string pattern = DNA.substr(i,k);
        string send = pattern + "$" + DNA;
        counter[i] = patternCount(send,k);
        maximum = max(maximum,counter[i]);
    }
    //set to store the unique answers
    unordered_set<string> answer;

    for(int i = 0; i < counter.size();++i)
        if(counter[i] == maximum)
            answer.insert(DNA.substr(i,k));
    for(auto va:answer)
        cout << va << " ";
    cout << "\n";
    return 0;
}
