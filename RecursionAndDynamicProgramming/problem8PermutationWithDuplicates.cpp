//Calculate permutations of a string with distinct characters
// P("abc") = a+ P("bc"), b+P("ac"), c+P("ab") then solve the subproblems

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

void Print(vector<string> vectorOfStrings){
    int n = vectorOfStrings.size();
    for(int i=0;i<n;i++){
        cout<<vectorOfStrings[i]<<endl;
    }
}
void PrintHashTable(unordered_map<char,int> map){
    unordered_map<char,int>::iterator it = map.begin();
    while(it != map.end()){
        cout<<it->first<<"---->"<<it->second<<"\n";
        it++;
    } 
}

unordered_map<char, int> BuildFrequencyTable(string S){
    unordered_map<char,int> frequencyTable;
    for (int i = 0; i < S.size(); i++)
    {   char key = S[i];
        frequencyTable[key] +=1;
    }
    return frequencyTable;
}
void Permute(string prefix, unordered_map<char,int> &frequencyTable, string S,vector<string> &result ){
    int n =S.size();
    //Base case
    if(n==0){
        result.push_back(prefix);
        return;
    }
    unordered_map<char,int>::iterator it = frequencyTable.begin();
    while(it!=frequencyTable.end()){
        int count = it->second;
        char key = it->first;
        if(count>0){
            frequencyTable[key]--;
            int j=0;
            while(j<n){
                if(S[j]==key){
                    break;
                }
                j++;
            }
            string before = S.substr(0,j);
            string after = S.substr(j+1);
            string remainder = before+after;
            Permute(prefix+key, frequencyTable,remainder,result);
            //After backtracking hash table should in the initial state
            frequencyTable[key]++;
        }
        it++;
    }
}

vector<string> FindPermutation(string S){
    vector<string> result;
    unordered_map<char,int> frequencyTable = BuildFrequencyTable(S);
    Permute("",frequencyTable,S,result);
    return result;
}

int main(){
    string S;
    cout<<"Enter a string\n";
    getline(cin,S);
    cout<<"The permutations are:\n";
    Print(FindPermutation(S));
    return 0;
}
