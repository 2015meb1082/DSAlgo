// Given 25cents, 10cents, 5 cents, 1cent denominations, Give an algorithm to count the number of ways 
// to change n cents.

#include<iostream>
#include<vector>

using namespace std;

//Simple Recursion
int CoinChange(int amount, vector<int> denoms,int index){
    if(index>=denoms.size()-1){
        return 1;
    }
    int denomAmount = denoms[index];
    int count=0;
    for(int i=0;i*denomAmount<=amount;i++){
        count+=CoinChange(amount-i*denomAmount,denoms,index+1);
    }
    return count;
}

void PrintMemoTable(vector<vector<int> > memo){
    for(int i=0;i<memo.size();i++){
        for (int j=0;j<memo[0].size();j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//Memoized solution
int CoinChange(int n, vector<vector<int> > memo, vector<int> denoms,int index){
   if(memo[n][index]!=0){
       return memo[n][index];
    }

    if(index>=denoms.size()-1){
        return 1;
    }
    int count=0;
    int denomAmount = denoms[index];
    for(int i=0;i*denomAmount<=n;i++){
        count+=CoinChange(n-i*denomAmount, memo,denoms,index+1);
    }
    memo[n][index] =count;
    return count;
}

int main(){
    vector<int> denominations(4);
    denominations[0]=25;
    denominations[1]= 10;
    denominations[2]=5;
    denominations[3] =1;
    for (int i = 0; i < 4; i++)
    {
        cout<<denominations[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter n: \n";
    int n;
    cin>>n;
    
    //Memo Solution
    cout<<"Memo Solution:\n";
    vector<vector<int> > memo(n+1,vector<int>(4,0));
    cout<<"Number of coin change ways dp way: "<<CoinChange(n,memo,denominations,0)<<"\n";
    cout<<"Number of coin change ways: "<<CoinChange(n,denominations,0)<<"\n";

    return 0;
}