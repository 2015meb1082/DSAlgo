// Implement a paint fill function that one might see on many image editing softwares. That is, given a screen 
//(represented by a 2D array of colors), a point and a new color, fill in the surrounding area until the 
//color changes from original color

#include<iostream>
#include<vector>

using namespace std;
typedef vector<vector<int> > Matrix;

void Print(Matrix colorMatrix){
    for(int i=0;i<colorMatrix.size();i++){
        int count = colorMatrix[i].size();
        for (int j = 0; j <count; j++)
        {
            cout<<colorMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void ModifyMatrix(Matrix &colorMatrix){
    for(int i=1;i<colorMatrix.size()/2;i++){
        for(int j=1;j<colorMatrix.size();j++){
            colorMatrix[i][j] =2;
        }
    }

}
void PaintFill(Matrix &matrix, int r,int c,int oldColor,int newColor){
    //Base case
    if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size()){
        return;
    }
    if(matrix[r][c]==oldColor){
        matrix[r][c] = newColor;
        PaintFill(matrix,r+1,c,oldColor,newColor);
        PaintFill(matrix,r-1,c,oldColor,newColor);
        PaintFill(matrix,r,c+1,oldColor,newColor);
        PaintFill(matrix,r,c-1,oldColor,newColor);
    }
}

void Paint(Matrix &colorMatrix,int r, int c,int newColor){
    int oldColor = colorMatrix[r][c];
    if(oldColor==newColor){
        cout<<"Already colored\n";
        return;
    }
    PaintFill(colorMatrix,r,c,oldColor,newColor);
}
int main(){
    int n;
    cout<<"Enter Size of matrix\n";
    cin>>n;
    Matrix colorMatrix(n,vector<int>(n,0));
    ModifyMatrix(colorMatrix);
    cout<<"\nModified Matrix\n";
    Print(colorMatrix);

    int r,c;
    cout<<"Enter r and c\n";
    cin>>r>>c;
    cout<<"Enter new Color\n";
    int newColor;
    cin>>newColor;
    Paint(colorMatrix,r,c,newColor);
    Print(colorMatrix);
    return 0;
}