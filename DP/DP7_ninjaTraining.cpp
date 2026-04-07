/*
Ninja is planing this 'N' days-long training schedule. Each day, he can perform any one of these three activities. 
(Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. 
As Ninja has to improve all his skills, he can't do the same activity in two consecutive days. 
Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 'POINTS' with the points corresponding to each day and activity. 
Your task is to calculate the maximum number of merit points that Ninja can earn
*/

#include <bits/stdc++.h>
using namespace std;

//Recursion
int f(int day,int last_task,vector<vector<int>> points)
{
    //base case
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++) // selecting each of the tasks 0,1,2
        {
            if(task!=last_task) // don't select task if it was the last task (we need non-consecutive tasks)
            {
                maxi=max(maxi,points[0][task]); // get the maximum
            }
        }
        return maxi;
    }

    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last_task)
        {
            int point=points[day][task]+f(day-1,task,points); // next day is day-1 and current task becomes the last task
            maxi=max(maxi,point);
        }
    }
    return maxi;
}

int ninjaTraining(int n,vector<vector<int>> &points) // n-> no, of days 
{
    return f(n-1,3,points); // setting last_task =3 (>2) because no task before the nth day's task
                            // task =3 means no task selected (tasks : 0,1,2)
}



//Memoisation
// T: O(N X 4) X 3         we have N X 4 states (0,1,2,3 ninja tasks and N days) and for every state we were running a for loop of size 3
// S: O(N) recursion stack space (at max N days) + O(N X 4) DP 2D-vector
int fMem(int day,int last_task,vector<vector<int>> points,vector<vector<int>> &dp)
{
    //base case
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++) // selecting each of the tasks 0,1,2
        {
            if(task!=last_task) // don't select task if it was the last task (we need non-consecutive tasks)
            {
                maxi=max(maxi,points[0][task]); // get the maximum
            }
        }
        return maxi;
    }

    if(dp[day][last_task]!=-1)
    return dp[day][last_task];

    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last_task)
        {
            int point=points[day][task]+fMem(day-1,task,points, dp); // next day is day-1 and current task becomes the last task
            maxi=max(maxi,point);
        }
    }
    dp[day][last_task]=maxi;
    return dp[day][last_task];
}

int ninjaTrainingMem(int n,vector<vector<int>> &points) // n-> no, of days 
{
    vector<vector<int>> dp(n,vector<int> (4,-1)); // dp vector of size [n][4] with values -1    ,  tasks: 0,1,2,3
    return fMem(n-1,3,points,dp); // setting last_task =3 (>2) because no task before the nth day's task
}



//Tabulation
// T: O(N X 4) X 3         we have N X 4 states (0,1,2,3 ninja tasks and N days) and for every state we were running a for loop of size 3
// S: O(N X 4) DP 2D-vector (eliminated recursion stack space)
int ninjaTrainingTab(int n,vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0)); // dp vector of size [n][4] with values 0
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last_task=0;last_task<4;last_task++)
        {
            dp[day][last_task]=0;

            for(int task=0;task<3;task++)
            {
                if(task!=last_task)
                {
                    int point=points[day][task]+dp[day-1][task]; // next day is day-1 and current task becomes last task
                    dp[day][last_task]=max(dp[day][last_task],point);
                }
            }
        }
    }
    return dp[n-1][3]; // return value in tabulation is the first call in the recursion
                       // as recursion is top-down and tabulation is bottom-up
}



//Space Optimaization
// T: O(N X 4 X 3)
// S: O(4)          using a 4 size 1D vector (tasks 0,1,2,3)
int ninjaTrainingSO(int n,vector<vector<int>> &points)
{
    vector<int> prev(4,0);

    //first row
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][1],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++)
    {
        vector<int> temp(4,0); // temp row of 4 columns
        for(int last_task=0;last_task<4;last_task++)
        {
            temp[last_task]=0;

            for(int task=0;task<3;task++)
            {
                if(task!=last_task)
                {
                    temp[last_task]=max(temp[last_task],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}

int main()
{
vector<vector<int>> points{
                {1,3,6},
                {4,6,2},
                {8,6,2},
                {4,7,3},
                {5,3,1}
            };
    cout<<ninjaTraining(points.size(),points)<<"\n"; // points.size() is n value or no. of rows
    cout<<ninjaTrainingMem(points.size(),points)<<"\n";
    cout<<ninjaTrainingTab(points.size(),points)<<"\n";
    cout<<ninjaTrainingSO(points.size(),points)<<"\n";
    return 0;
}