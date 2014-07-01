#include <vector>
#include <iostream>
#include <experimental/inline_executor>
#include <experimental/thread_pool>

using namespace std;

int func(int x){
//    cout << x << endl;
    return x*x;
}

int main() {
    const int n = 100;
    //experimental::inline_executor ex;
    experimental::thread_pool ex;

    vector<future<int>> results;
    for(int i = 1; i <= n; i++)
        results.push_back( experimental::add(ex,func,i) );

    int sum = 0;
    for(auto& fut : results)
        sum += fut.get();

    cout << "expected: " << (n*(n+1)*(2*n+1)/6) << endl;
    cout << "got: " << sum << std::endl;

    return 0;
}
