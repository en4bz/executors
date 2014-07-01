#include <chrono>
#include <iostream>

#include <experimental/scheduled_thread_pool>

using namespace std;

void func(int x){
    cout << x << endl;
}

int main(){
    const int n = 10;
    experimental::scheduled_thread_pool ex;
    for(int i = 0; i < n; i++)
        ex.add_after(bind(func,i),chrono::seconds(i));

    return 0;
}
