#include<iostream>
#include<string>

using namespace std;

// substr(index to start, length to cover)
string Foo(string S, char c,int pos){
    string before = S.substr(0,pos);
    string after = S.substr(pos);
    return before+c+after;
}

int main(){
    string S = "Abscsde";
    cout<<S.substr(0,0)<<"\n";
    for(int j=0;j<=S.size();j++){
        cout<<Foo(S,'#',j)<<endl;
    }
    return 0;
}