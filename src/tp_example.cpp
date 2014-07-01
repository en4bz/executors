#include <iostream>
#include <experimental/thread_pool>

using namespace std;

int func(const int x){
    cout << this_thread::get_id() << "|" << x << endl;
    this_thread::sleep_for(chrono::seconds(1));
//    cout << x*x << endl;
    return x*x*x;
}

int main(){
    experimental::thread_pool tp;
    for(int i = 0; i < 10; i++){
        tp.add(std::bind(func,i));
    }
    tp.close();
    return 0;
}
