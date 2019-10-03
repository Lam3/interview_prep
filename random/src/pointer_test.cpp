#include <iostream>

void print_int_val(const int *my_val){
    std::cout << "Value is: " << *(my_val) << std::endl;
}

int main(){
    int value = 5;
    print_int_val(&value);
}