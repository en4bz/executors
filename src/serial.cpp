#include <iostream>

#include <experimental/thread_pool>
#include <experimental/serial_executor>

using namespace std;

int func(int x){
    cout << x << endl;
    return x*x;
}

int main(){
    const int n = 50;
    experimental::thread_pool ex;
    experimental::serial_executor serial(ex);

    for(int i = 0; i < n; i++)
        serial.add(bind(func,i));

    return 0;
}
