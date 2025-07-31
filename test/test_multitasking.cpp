#include <iostream>
#include <thread>

void func1(){
    for(int i = 0; i < 1000; i++){
        std::cout << "-";
    }
}
void func2(){
    for(int i = 0; i < 1000; i++){
        std::cout << "+";
    }
}

int main(){

    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}
