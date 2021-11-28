#include <iostream>
#include <vector>
using namespace std;

//n = 3
void subset1(int n, vector<int>& p, const int sz){
    if (n == sz+1){
        for(auto n : p){
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    subset1(n+1,p,sz);
    p.push_back(n);
    subset1(n+1,p,sz);
    p.pop_back();
}

void subset2(int n){
    for(int i = 0; i<(1<<n); ++i){
        for(int j = 0; j<n; ++j){
            if((i & (1<<j)) > 0)cout << (j+1) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> p;
    subset1(1,p,3);
    subset2(3);
    return 0;
}
