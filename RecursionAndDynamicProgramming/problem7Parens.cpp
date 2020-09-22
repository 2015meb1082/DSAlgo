// Implement an algorithm to print all valid(e.g. properly opened and closed) combinations of n pair of
// Parenthesis
//e.g if n =3
// output = ((())), (()()), (())(), ()(()), ()()()

#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

void PrintSet(unordered_set<string> stringSet){
    unordered_set<string>::iterator it = stringSet.begin();  
    while(it!=stringSet.end()){
        cout<<*it<<"\n";
        it++;
    }
    cout<<endl;
}
// Less efficient solution
unordered_set<string> PrintValidParens(int n){
    unordered_set<string> result;

    //Base case
    if(n==0){
        result.insert("");
        return result;
    }
    unordered_set<string> tempResult = PrintValidParens(n-1);
    unordered_set<string>:: iterator itr = tempResult.begin();
    while(itr!=tempResult.end()){
        for(int i=0;i<3;i++){
            string tempString="";    
            switch (i)
            {
                case 0:
                    tempString="("+*itr+")";
                    break;
                case 1:
                    tempString="()"+*itr;
                    break;
                default:
                    tempString=*itr+"()";
                    break;
            }

            if(result.find(tempString)==result.end()){
                //not found in the set. Then insert it in the set
                result.insert(tempString);
            }
        }
        
        itr++;
    }

    return result;
}

int main(){
    int n;
    cout<<"Enter n\n";
    cin>>n;
    PrintSet(PrintValidParens(n));
    return 0;
}