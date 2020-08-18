#include<bits/stdc++.h>
using namespace std;

int main(){
    string DNA;
    cin >> DNA;
    int skew[(int)DNA.size()+1];
    skew[0] = 0;
    int mi = INT_MAX;
    vector<int> answer;
    for(int i = 1; i <= (int)DNA.size();++i){
        skew[i] = skew[i-1];
        if(DNA[i-1] == 'C')
            --skew[i];
        if(DNA[i-1] == 'G')
            ++skew[i];
        if(skew[i] < mi){
            answer.clear();
            mi = skew[i];
            answer.push_back(i);
        }
        else if(skew[i] == mi)
            answer.push_back(i);
    }
    for(auto va:answer)
        cout << va << " ";
    cout << "\n";
    return 0;
}
