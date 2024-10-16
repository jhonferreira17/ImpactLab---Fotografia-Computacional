#include<iostream>
#include<thread>
#include<mutex>

std::mutex cadeado;
int amount = 0;

void foo(int tid)
{
    std::cout << " Thread" << tid << " starting" << std::endl;

    for (int i = 0; i < 20; ++i) {
        cadeado.lock(); 
        std::cout << " hello from thread " << tid << " i=" << i << std::endl;
        cadeado.unlock();
    };

std::cout<< " thread " << tid << " ending" << std::endl;
}

int main(){
std::cout << std::thread::hardware_concurrency() << " concurrent threads supported." << std::endl;


std::thread t0(foo, 0);
std::thread t1(foo, 1);

t0.join();
t1.join();

std::cout << " main() Exiting" << std::endl;

return 0;
}
