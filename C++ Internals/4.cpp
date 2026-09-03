#include <bits/stdc++.h>
using namespace std;
const int a = 5;
int main()
{
    const int max_files = 20;    // max_files is a constant expression
    const int limit = max_files + 1; // limit is a constant expression
    int staff_size = 27;       // staff_size is not a constant expression
    // const int sz = get_size(); // sz is not a constant expression
    constexpr int mf = 20;        // 20 is a constant expression
    constexpr int limit = mf + 1; // mf + 1 is a constant expression
    // constexpr int sz = size();
    //constexpr int *x = &a;    That's not allowed, because it would let you modify a const object
    constexpr const int *x = &a;
    return 0;
}