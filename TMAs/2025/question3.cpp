#include <iostream>
#include <string>

bool is_unique(int n, int* numbers, int i) {
    for(int j=0; j < i; j++) {
        if(numbers[j] == n) return false;
    }
    return true;
}

void generate_numbers(int* numbers) {
    int i = 0;
    while(i<10) {
        int n = rand() % 10000;
        if(is_unique(n, numbers, i)) {
            numbers[i] = n;
            i++;
        }
    }
}

std::string zeroes(int n) {
    if(n < 10) return "000";
    if(n < 100) return "00";
    if(n < 1000) return "0";
    return "";
}

void display_numbers(int* numbers) {
    for(int i=0; i<10;i++) {
        std::cout << zeroes(numbers[i]) << numbers[i] << " ";        
    }
    std::cout << std::endl;
    for(int i=0; i<10;i++) {
        std::cout << "====" << " ";        
    }

}

int main() {
    int numbers[10];
    generate_numbers(numbers);
    display_numbers(numbers);
    return 0;
}