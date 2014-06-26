#include <iostream>
#include <experimental/thread_pool>

using namespace std;

int main(){
    experimental::thread_pool tp;
    for(int i = 0; i < 100; i++){
        tp.add( [i](){cout << i << endl;} );
    }
//    tp.close();
    return 0;
}
