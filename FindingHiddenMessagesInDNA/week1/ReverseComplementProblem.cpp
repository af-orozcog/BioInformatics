#include<bits/stdc++.h>
using namespace std;

void reverse(string &ADN){
    int i = 0, j = (int)ADN.size()-1;
    while(i < j){
        swap(ADN[i],ADN[j]);
        ++i,--j;
    }
}

int main(){
    string ADN;
    cin >> ADN;
    map<char,char> rev;
    rev['A'] = 'T'; rev['T'] = 'A';
    rev['G'] = 'C'; rev['C'] = 'G';
    string answer = "";
    for(auto va:ADN)
        answer += rev[va];
    reverse(answer);
    cout << answer << "\n";
    return 0;
}
