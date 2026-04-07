#include <bits/stdc++.h>
using namespace std;

bool stringInterleaving(char str1[], char str2[],char str3[], char* p1,char* p2)
{
    //base case
    if(strlen(str3)!=(strlen(str1)+strlen(str2))) return 0; //string 1+2 should be equal to string 3 in size
    char* p=str3;
    while(*p1!='\0')
    {
        
    }
}

int main()
{
    char str1[]="xyz";
    char str2[]="abc";
    char* p1=str1;
    char* p2=str2;
    return 0;
}