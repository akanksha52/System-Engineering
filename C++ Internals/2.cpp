// Pointers
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 42;
    int *p = &i;
    *p = 25; 
    cout<< i;
    int *x = nullptr; 
    int *y = NULL;
    int *z = 0; // Also null
    // int zero = 0;
    // *z = zero;  
    double obj = 3.14, *pd = &obj;
    void *pv = &i; 
    pv = pd;        
    return 0;
}