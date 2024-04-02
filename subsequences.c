#include<stdio.h>

int main(){
    int n;

    char a[6]="abcdef";

    for(int i=0;i<n;i++){
        int ians;
        char arr[100]="";
        // arr[ians]=a[i];
        // ians++;

        for(int j=i;j<n;j++){
            arr[ians]=a[j];
            printf("%s",a);
            ians++;
        }
    }

    return 0;
}