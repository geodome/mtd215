#include <iostream>
#include <string>

void generate_numbers(int numbers[], int size);
void display_numbers(int numbers[], int size);
bool sorted(int numbers[], int size);
bool is_adjacent(int index1, int index2);
bool is_unique(int n, int numbers[], int i);

// ask name and score for 12 players
int main(int argc, char* argv[]) {
    int num[10];
    int index1, index2;
    generate_numbers(num, 10);
    while(!sorted(num, 10)) {
        display_numbers(num, 10);
        std::cout << "Enter index 1: ";
        std::cin >> index1;
        std::cout << "Enter index 2: ";
        std::cin >> index2;
        if(is_adjacent(index1, index2)) {
            // swap the adjacent elements
            int temp = num[index1];
            num[index1] = num[index2];
            num[index2] = temp;
            std::cout << "The elements are swapped" << std::endl;
        } else
            // error. don't swap non-adjacent elements.
            std::cout << "Error: Non-adjacent indices" << std::endl;
    }
    // congrat user for sorting the number
    display_numbers(num,10);
    std::cout << "congrats" << std::endl;
}

void generate_numbers(int numbers[], int size) {
    int i = 0;
    while(i < size) {
        int n = rand() % 10000;
        if(is_unique(n, numbers, i)) {
            numbers[i] = n;
            i++;
        }
    }
}

bool is_unique(int n, int numbers[], int i) {
    for(int j = 0; j < i; j++) {
        if(numbers[j] == n) return false;
    }
    return true;
}

void display_numbers(int numbers[], int size) {
    for(int i=0; i < size; i++) {
        std::cout << numbers[i] << "  ";
    }
    std::cout << std::endl;
}

bool sorted(int numbers[], int size) {
    for(int i=1; i<size; i++) {
        if(numbers[i] < numbers[i-1]) return false;
    }
    return true;
}

bool is_adjacent(int index1, int index2) {
    int d = index1 - index2;
    return d == 1 || d == -1;
}
