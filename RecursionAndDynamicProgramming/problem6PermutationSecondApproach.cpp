#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Auxiliary functions
// substr(index to start, length to cover)
string InsertCharAt(string S, char c,int pos){
    string before = S.substr(0,pos);
    string after = S.substr(pos);
    return before+c+after;
}
void Print(vector<string> VS){
    for(int i=0;i<VS.size();i++){
        cout<<VS[i]<<"\n";
    }
}

//Main permute function
// n is the length of string
vector<string> Permute(string S){
    vector<string> result;
    int n = S.size();
    //Base case if the string is empty
    if(n==0){
        result.push_back("");
        return result;
    }
    //calculate the remainder string
    string remainderString = S.substr(0,n-1);
    vector<string> tempResult = Permute(remainderString);

    //Loop through the vector of string
    for(int i=0;i<tempResult.size();i++){
        for(int j=0;j<=tempResult[i].size();j++){ // = sign is very important here
             result.push_back(InsertCharAt(tempResult[i],S[n-1],j));
        }
    }
    return result;
}
int main(){
    string S="abc";
    int n= S.size();
    vector<string> result = Permute(S);
    Print(result);
    return 0;
}