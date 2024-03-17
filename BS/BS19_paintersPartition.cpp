#include <bits/stdc++.h>
using namespace std;

// if pages a student can take are more then students will be less
// if pages a student can take are less then students will be more
int countStudents(vector<int> arr, int pages)
{
    int students = 1;
    int studentPages = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(studentPages + arr[i] <=pages) // if pages a student has is less than allowed pages
        {
            studentPages+=arr[i];
        }
        else
        {
            students++;
            studentPages=arr[i];
        }
    }
    return students;
}

int pages(vector<int> arr, int reqStu)
{
    // BS [max -> sum]
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int students = countStudents(arr, mid);
        if(students > reqStu) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

// Same as previous question, only difference is problem statement
int main()
{
    vector<int> arr {10,20,30,40};
    int k = 2;
    cout<<pages(arr, k);
    return 0;
}