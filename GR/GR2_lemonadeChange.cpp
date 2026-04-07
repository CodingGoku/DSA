#include <bits/stdc++.h>
using namespace std;

// T: O(N)
// S: O(1)
bool lemonadeChange(vector<int>& customer) {
    int n = customer.size();
    int five = 0, ten = 0;
    // no need to store 20 as we are not going to return 20 to anyone


    for(auto i : customer) {
        if(i == 5) five++; // five
        else if(i == 10) { // ten
            if(five) {
                five--;
                ten++;
            }
            else return false;
        }
        else { // twenty
            if(five && ten) {
                five--;
                ten--;
            }
            else if(five >= 3) five -= 3;
            else return false;
        }
    }
    return true; // all transactions done
}

int main()
{
    vector<int> customer = {5,5,5,10,20};
    cout<<lemonadeChange(customer)<<endl;

    customer = {5,5,10,10,20};
    cout<<lemonadeChange(customer)<<endl;
    return 0;
}