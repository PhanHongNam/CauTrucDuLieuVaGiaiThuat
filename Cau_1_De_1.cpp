#include<iostream>

using namespace std;

//
// a) A(n) = {1 neu n = 0;
//           { 2 * A(n-1) voi cac TH con lai
//


//b
int A(int n)
{
    if ( n == 0)
        return  1;
    return 2 * A(n-1);
}

int main()
{
    //ai muon test thi viet code thu day
    //di thi chi can viet ham de quy la ok, khong can include gi het
    return 0;
}
