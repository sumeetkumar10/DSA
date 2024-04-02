#include<iostream>
#include<vector>
using namespace std;

void markRow(int matrix[][3],int n,int m,int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}

void markCol(int matrix[][3],int n,int m,int j){
    for(int i=0;i<n;i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}

void setMatrixZeros(int matrix[][3],int n,int m){
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         markRow(matrix,n,m,i);

    //         markCol(matrix,n,m,j);
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(matrix[i][j]==-1){
    //             matrix[i][j]=0;
    //         }
    //     }
    // }

    int row[n]={0};
    int col[m]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;

                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

void printMatrix(int matrix[][3],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int matrix[3][3]{{1,1,1},{1,0,1},{1,1,1}};

    printMatrix(matrix,3,3);

    setMatrixZeros(matrix,3,3);

    printMatrix(matrix,3,3);

    return 0;
}