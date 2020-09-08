// Imagine a robot sitting on the upper left corner of a grid with r rows and c columns. The robot can only
// move in two directions, right and down, but certain cells are "offlimits" such that the robot cannot step
// on them. Design an algorithm to find a path for the robot from top left to the bottom right.


//For testing and imput purpose, I am taking a 4x4 grid but the code will work for rxc grid.

#include<iostream>
#include<vector>
#include<unordered_map>


//Point class for storing the x and y
class Point{
    
    public:
        int x,y;    
        Point(int x,int y){
            this->x=x;
            this->y =y;
        }

        /*
        //Custom equal operator for unordered_map container
        bool operator==(const Point &p) const{
            return x==p.x && y==p.y;
        }
        */
};
//Custom hash function for user defined point class
/*
struct hash_fn{
    std::size_t operator()(const Point &p) const{
        std::size_t h1 = std::hash<int>()(p.x);
        std::size_t h2 = std::hash<int>()(p.y);
        return h1^h2;
    }
};
*/
//Type defination
typedef std::vector<std::vector<bool> > Matrix;
typedef std::unordered_map<Point*, bool> HashMap;
//Auxiliary Function Definations for later implementation
void Print(Matrix);
void Print(std::vector<Point*>);

//Simple recursive solution - Time complexity O(2^(r+c)) , Space complexity O(max(r,c)) 
// This function is working as expected

bool GetPath(Matrix matrix,int r,int c, std::vector<Point*> &pathArray){
    if(r<0 || c<0 || matrix[r][c]==0){
        return false;
    }
    bool isOrigin = (r==0 && c==0);
    Point *point = new Point(r,c);
    if(isOrigin || GetPath(matrix,r-1,c,pathArray) || GetPath(matrix,r,c-1,pathArray)){
        pathArray.push_back(point);
        return true;
    }
    return false;
}

// Caching the result of already found path
//This will not work right now because of the hash table. Since we are using user defined data datastructure as
//a key,  we need to define our own hash function and operator == 
// I am not capable of that right now. Will see later
bool GetPathWithDP(Matrix matrix,int r,int c, std::vector<Point*> &pathArray, HashMap &cacheMap){
    std::cout<<"1 $ ";
    if(r<0 || c<0 || matrix[r][c]==0){
        std::cout<<"2 $ ";
        return false;
    }
    

    bool isOrigin = (r==0 && c==0),foundPath=false;
    Point *point = new Point(r,c);
    std::cout<<"3 $ ";
//--------------------------------------------------------------------
    //If the map contains the point key then return its value directly 
    if(cacheMap.find(point)==cacheMap.end()){
        
    }else{
        std::cout<<"4 $ ";
        return cacheMap[point];
    }
//----------------------------------------------------
    //Recursive case
    if(isOrigin || GetPathWithDP(matrix,r-1,c,pathArray,cacheMap) || GetPathWithDP(matrix,r,c-1,pathArray,cacheMap)){
        std::cout<<"5 $ ";
        pathArray.push_back(point);
        foundPath=true;
    }
    std::cout<<"6 $ ";
    foundPath=false;
    //cache the calculated result
    cacheMap[point] =foundPath;
    return foundPath;
}

void FindPath(Matrix matrix,int r,int c){
    std::vector<Point*> pathArray;
    HashMap cacheMap;
    //If we have found the path then Print it
    if(GetPath(matrix,r,c,pathArray)){
        std::cout<<"Path exists: true\n";
        std::cout<<"Path points are: \n";
        Print(pathArray);
    }else{
        std::cout<<"No Path found\n";
    }

}


int main(){
    int r=4,c=4;
    Matrix matrix(r,std::vector<bool>(c,1));
    // Put the off limits blocks in the matrix. if matrix[i][j] ==0 then it's off limit
    matrix[0][1]=0;
    matrix[1][3] =0;
    matrix[2][1]=0;
    matrix[3][0]=0;
    
    //Try uncommenting below line to find the case where there is no path that exist between origin and destination.
    //matrix[2][2]=0;
    Print(matrix);
    FindPath(matrix,r-1,c-1);
    return 0;
}

//Auxiliary function to print the matrix-- Time Complexity - O(r*c) , since we are iterating over the complete matrix
void Print(Matrix matrix){
    int r =matrix.size();
    int c = matrix[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void Print(std::vector<Point*> pathArray){
    int n = pathArray.size();
    for(int i=0;i<n;i++){
        std::cout<<"("<<pathArray[i]->x<<","<<pathArray[i]->y<<"), ";
    }
    std::cout<<"\n";
}
