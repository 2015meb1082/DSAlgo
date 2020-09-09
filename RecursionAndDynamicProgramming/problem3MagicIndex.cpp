// A magic index in an array[0...n-1] is defined to be an index such that A[i] =i. Given a sorted array 
// of distinct integers, write a method to find a magic index, if one exists in array A.
// Follow up: What if the values are not distinct?

#include<iostream>
#include<algorithm>  // For min and max functions

void Print(int[],int);

//Brute force O(n)
int MagicIndexBrute(int A[],int n){
    for(int i=0;i<n;i++){
        if(A[i]==i){
            return i;
        }
    }
    return -1;
}
// We can do better. Since given array is sorted
// Divide and conquer
// Just like binary search O(logn) -Time , Space -O(n) 
int MagicIndexRecursive(int A[],int low,int high){
    //Base case
    if(low>high){
        return -1;
    }
    //Recursive case
    int mid = low+(high-low)/2;
    if(A[mid]==mid){
        return mid;
    }else if(A[mid]>mid){
        return MagicIndexRecursive(A,low,mid-1);
    }
    return MagicIndexRecursive(A,mid+1,high);
} 

// Follow up - If elements are not distinct
// It is not O(logn) since in the worst case we may have to check both halves
// But definately time complexity less than O(n)
int MagicIndexNotDistinctive(int A[],int low,int high){
    //Base Case
    if(low>high){
        return -1;
    }

    //Recursive case
    int mid = low+(high-low)/2;
    if(A[mid]==mid){
        return mid;
    }

    int leftIndex = std::min(mid-1,A[mid]);
    int left = MagicIndexNotDistinctive(A,low,leftIndex);
    if(left>0){
        return left;
    }

    int rightIndex = std::max(mid+1,A[mid]);
    int right = MagicIndexNotDistinctive(A,rightIndex,high);
    return right;

}


int main(){
    int A[11]={-50,-20,2,2,3,5,12,20,41,53,65};
    Print(A,10);
    int magicIndex = MagicIndexNotDistinctive(A,0,10);
    if(magicIndex!=-1){
        std::cout<<"Magic Index is: "<<magicIndex<<"\n";
    }else{
        std::cout<<"Magic Index doesn't exist\n";
    }
    
    return 0;
}   
void Print(int A[],int n){
    for(int i=0;i<n;i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
    
}