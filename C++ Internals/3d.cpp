// Const References
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double dval = 3.14;
    const int &ri = dval;
    cout << ri << endl;
    const double pi = 3.14;
    //double *ptr = &pi;        error: ptr is a plain pointer
    const double *cptr = &pi; // ok: cptr may point to a double that is const
    // *cptr = 42;              error: cannot assign to *cptr
    int errNumb = 0;
    int *const curErr = &errNumb;  // curErr will always point to errNumb
    *curErr = 7;
    const double pj = 3.14159;
    const double *const pip = &pj;
    return 0;
}