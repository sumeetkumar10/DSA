#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isPalindromRec(char str[],int start,int end){
    if(start==end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }

    if(start<end+1){
        return isPalindromRec(str,start+1,end-1);
    }
    return true;
}

bool isPalindrome(char str[]){
    int n=strlen(str);
    if(n==0){
        return true;
    }
    return isPalindromRec(str,0,n-1);
}

int main(){
    char str[50];
    scanf("%[^\n]%*c",str);

    printf("%s\n",str);

    if(isPalindrome(str)){
        printf("The string is palindrome.");
    }
    else{
        printf("The string is not palindrome.");
    }

    return 0;
}