// Problem:- A child is running up a staircase with n steps and can either take 1 step, 2 steps, 3 steps.
// Implement a method to count how many possible ways the child can run up the stairs.
// in case n>36 then the integer will overflow

#include<iostream>
#include<cstring>

//Auxiliary Functions for initialization and Printing - O(n) Time complexity-  both
void initialize(int A[],int n){
    for(int i=0;i<n;i++){
        A[i] =-1;
    }
}

void Print(int A[],int n){
    for(int i=0;i<n;i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}
//Simple recursion. Time complexity O(3^n) because each recursive node is subdivided into 3
int CountWays(int n){
    //Base case. You could choose base case a little different here. You may output 1 on n=0 instead of 0.
    if(n<=0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else if(n==3){
        return 4;
    }
    // Recursive case
    return CountWays(n-1)+CountWays(n-2)+CountWays(n-3);
}
//Memoized Code of Above recursive code. Because there were a lot of overlapping subproblems i.e repeated
//function calls for subproblems, we have cached the solution of subproblems.
// Time complexity- O(n), Space complexity- O(n) tree depth n, because n functions calls are in the stack
//space simultaneously

int DPCountWays(int n,int memo[]){
    //Base case. You could choose base case a little different here. You may output 1 on n=0 instead of 0.
    if(n<=0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else if(n==3){
        return 4;
    }

    if(memo[n]>-1){
        return memo[n];
    }
    return memo[n] = DPCountWays(n-1,memo)+DPCountWays(n-2,memo)+DPCountWays(n-3,memo);
}


int main(){
    int n;
    std::cout<<"Enter the number of steps:\n";
    std::cin>>n;
    //Heap allocated dynamic array
    int *memo = new int[n+1];
    initialize(memo,n+1);
    Print(memo,n);
    std::cout<<"Number of ways: "<<DPCountWays(n,memo)<<"\n";    
    Print(memo,n);
    //Deallocation of array memory
    delete[] memo;
    return 0;

}