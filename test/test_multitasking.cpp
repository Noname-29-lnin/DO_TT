#include <iostream>
int main(int argc, char** argv) {
    std::cout << "argc = " << argc << "\n";
    for(int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << "\n";
    }
    for(int i = 0; i < 10; i++){
        std::cout << " 1 ";
    }
    return 0;
}
