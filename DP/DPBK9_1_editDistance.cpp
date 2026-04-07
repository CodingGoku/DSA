#include <bits/stdc++.h>
using namespace std;

//Edit distance between 2 string is defined as the minimum number of character operations
// (update, delete, insert) required to convert one string into another.


// min. changes in str1 to make it str2

// TIME COMPLEXITY : O(N^3) EXPONENTIAL
int editDistance(char* str1,char* str2) // use char* not string to use pointers
{
    //if str1 is empty
    if(str1==NULL || *str1=='\0') return strlen(str2); // complete str2 needs to be inserted in str1

    //if str2 is empty
    if(str2==NULL || *str2=='\0') return strlen(str1); // complete str1 needs to be deleted to match str2

    //value at str1 equal to value at str2
    if(*str1==*str2) return editDistance(str1+1,str2+1); // increment both the pointers

    //IF VALUE AT STR1 DOES NOT MATCH VALUE AT STR2 THEN WE EITHER DELETE, UPDATE OR INSERT

    //delete
    int d=editDistance(str1+1,str2); //increemnt str1 pointer
    //update
    int u=editDistance(str1+1,str2+1); //increment both str1 and str2 pointers
    //insert
    int i=editDistance(str1,str2+1); //increemnt str2

    return min(d,min(u,i))+1;
}

int main()
{
    char s1[]="Twilight";
    char s2[]="Alright";
    char* str1=s1;
    char* str2=s2;
    cout<<editDistance(str1,str2);
    return 0;
}