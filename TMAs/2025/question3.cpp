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
    std::cout << std::endl;
}

bool sorted(int* numbers) {
    for(int i = 1; i<10;i++) {
        if(numbers[i] < numbers[i-1]) return false;
    }
    return true;
}

bool is_adjacent(int i, int j) {
    return abs(i - j) == 1;
}

int main() {
    int numbers[10];
    int index1, index2;

    generate_numbers(numbers);
    
    while(!sorted(numbers)) {
        display_numbers(numbers);

        // prompt user for index1 and index2
        std::cout << "Enter first index: ";
        std::cin >> index1;
        std::cout << "Enter second index: ";
        std::cin >> index2;

        // check for adjacency
        if(is_adjacent(index1, index2)) {
            // if indices are adjacent, swap the elements at the indices
            int temp = numbers[index1];
            numbers[index1] = numbers[index2];
            numbers[index2] = temp;
            std::cout << "indices " << index1 << " and " << index2 << " are swapped." << std::endl;
        } else 
            // error
            std::cout << "Error: Cannot swap non-adjacent elements" << std::endl;
    }
    return 0;
}