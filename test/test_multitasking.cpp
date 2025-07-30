#include <iostream>
#include <thread>

void funtion1(){
    for(int i = 0; i < 100; i++){
        std::cout << "-" ;
    }
}
void funtion2(){
    for(int i = 0; i < 100; i++){
        std::cout << "+" ;
    }
}

int main(){

    std::thread worker1(funtion1);
    std::thread worker2(funtion2);

    worker1.join();
    worker2.join();
    
    return 0;
}