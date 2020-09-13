// Write a program to print all the subsets of a set

#include<iostream>
#include<vector>

std::vector<std::vector<int> > PowerSet(std::vector<int> inputSet,int n){

    std::vector<std::vector<int> > allSubsets;
    if(n==0){
        //return an empty list of list
        std::vector<std::vector<int> > emptySet(1,std::vector<int>(1,-1));
        std::cout<<"Empty Set Size: "<<emptySet.size()<<"\n";
        return emptySet;
    }
    std::vector<std::vector<int> > result = PowerSet(inputSet,n-1);
    for(int i=0;i<result.size();i++){
        allSubsets.push_back(result[i]);
        result[i].push_back(inputSet[n-1]);
        allSubsets.push_back(result[i]);
    }
    return allSubsets;
}

int main(){
    int n;
    std::cout<<"Enter n\n";
    std::cin>>n;
    
    if(n>=0){
        std::vector<int> inputSet;
        for(int i=0;i<n;i++){
            inputSet.push_back(i+1);
        }

        std::cout<<"-1 represent empty\n";
        std::cout<<std::endl;
        std::vector<std::vector<int> > result = PowerSet(inputSet,n);
        std::cout<<"{";
        for(int i=0;i<result.size();i++){
            int n =result[i].size();
            std::cout<<"{ ";
            for(int j=0;j<n;j++){
                std::cout<<result[i][j]<<",";
            }
            
            std::cout<<"},";
        }
        std::cout<<"}\n";
    }else{
        std::cout<<"Bad input\n";
    }
    

    return 0;
}