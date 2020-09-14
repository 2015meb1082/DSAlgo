// Find all permutations of a string with distinct character
#include<iostream>
#include<string>
#include<cstdio>

void Swap(char *a,char *b){
    char temp = *a;
    *a=*b;
    *b =temp;
}

void Permutation(std::string &S,int n){
    if(n<1){
        std::cout<<S<<std::endl;
        return;
    }else{
        for(int i=n-1;i>=0;i--){
            Swap(&S[i],&S[n-1]);
            Permutation(S,n-1);
            Swap(&S[n-1],&S[i]);
        }
    }
    
}

int main(){
    std::string S = "abcd";
    //std::cout<<S<<std::endl;
    int n= S.size();
    std::cout<<"Size is: "<<n<<"\n";
    Permutation(S,n);

    return 0;
}