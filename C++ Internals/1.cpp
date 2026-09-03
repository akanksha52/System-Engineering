// Reference
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ival = 1024;
    int &refVal = ival;
    cout << ival << " " << refVal<<endl;
    ival = 1000; 
    cout << ival << " " << refVal<<endl;
    refVal = 400;
    cout << ival << " " << refVal<<endl;
    // int &a = 0; 
    // float &a = ival; 
    cout << ( &ival == &refVal);
    return 0;
}