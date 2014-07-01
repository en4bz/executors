#include <iostream>
#include <experimental/thread_pool>
#include <experimental/inline_executor>

using namespace std;

int main(){
    experimental::executor* ex = new experimental::inline_executor();

    for(int i = 0; i < 100; i++){
        ex->add([i](){ cout << i << endl;});
    }
    delete ex;
    return 0;
}


