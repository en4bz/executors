# Executors and Schedulers
### Based on C++ Standards Proposal [N3875](ttp://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3785.pdf)

This is a draft implementation of proposal [N3875](ttp://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3785.pdf) and the current draft proposal from the [concurreny_ts](https://github.com/cplusplus/concurrency_ts).

<b>Note</b>: There may be some slight deviations from these proposal in the form of naming (submit vs. add) and argument order.

It includes the following classes and functions

### Interfaces
    class executor {
    public:
        virtual ~executor() {};
        virtual void add(function<void()>) = 0;
        virtual size_t num_uninitiated_task() = 0;
    };
 
    class scheduled_executor : public executor {
    public:
        virtual void add_at(function<void()>, chrono::steady_clock::time_point) = 0;
        virtual void add_after(function<void()>, chrono::steady_clock::duration) = 0;
    };

### Concrete Classes
 * `thread_pool`
 * `scheduled_thread_pool`
 * `inline_executor`
 * `task_per_thread_executor`
 * `serial_executor`
 * `loop_executor` [<b>in progress</b>]
 
### Static Free Functions

<b>Note</b>: This function has the same signature as std::async from the [concurreny_ts](https://github.com/cplusplus/concurrency_ts) working draft.

    template<typename F,typename... Args>
    future< typename result_of<F(Args...)>::type > add(executor& ex, F&& fn, Args&&... args);
    
    
### Building and Usage

All classes have been implemented in the `std::experimental` namespace as header only files.

These headers all reside in `include/experimental` folder.

In order to use theses classes you can simply compile with 

`g++ --std=c++11 myfile.cpp -I path/to/this/projects/include -pthread`

`clang --std=c++11 myfile.cpp -I path/to/this/projects/include -pthread -lstdc++`

There is a collection of basic examples/tests in the `src` directory. 

#### Tested With

 * <pre>`g++ 4.6`   (Won't work)</pre>
 * <pre>`g++ 4.7`   (Good)</pre>
 * <pre>`g++ 4.8`   (Good)</pre>
 * <pre>`clang 3.4` (Good)</pre>
 
### TODO

 1. Create more rigorous tests.
 2. Abstract all queuing operations into a private sync_queue class.
