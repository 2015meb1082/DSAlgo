//Calculate permutations of a string with distinct characters

// P("abc") = a+ P("bc"), b+P("ac"), c+P("ab") then solve the subproblems

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Print(vector<string> vectorOfStrings){
    int n = vectorOfStrings.size();
    for(int i=0;i<n;i++){
        cout<<vectorOfStrings[i]<<endl;
    }
}


vector<string> Permute(string S){
    vector<string> result;
    int n = S.size();
    //Base case
    if(n==0){
        result.push_back("");
        return result;
    }
    
    for(int i=0;i<n;i++){
        string before = S.substr(0,i);
        string after = S.substr(i+1);
        vector<string> partials = Permute(before+after);

        for(int j=0;j<partials.size();j++){
            result.push_back(S[i]+partials[j]);
        }
    }
    return result;
}

int main(){
    string S;
    cout<<"Enter a string\n";
    getline(cin,S);
    cout<<"The permutations are:\n";
    Print(Permute(S));
    return 0;
}
