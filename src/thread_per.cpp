#include <set>
#include <vector>
#include <iostream>
#include <experimental/thread_per_task_executor>

using namespace std;

thread::id func(int x){
    return this_thread::get_id();
}

int main(){
    const int n = 100;
    experimental::thread_per_task_executor ex;
    vector<future<thread::id>> results;
    for(int i =0; i < n; i++)
        results.push_back( experimental::add(ex,func,i) );

    set<thread::id> ids;
    for(auto& fut : results)
        ids.insert(fut.get());

    cout << "expected: " << n << endl;
    cout << "got: " << ids.size() << endl;

    return n == ids.size();
}
