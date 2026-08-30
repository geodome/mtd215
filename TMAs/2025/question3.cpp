#include <iostream>
#include <string>

// Due to array decay, when passing an array as a function parameter, always include the array size so as to ensure memory safety.
void generate_numbers(int numbers[], int size);
void display_numbers(int numbers[], int size);
std::string zeroes(int n);
bool is_sorted(int numbers[], int size);
bool is_adjacent(int index1, int index2);
bool is_unique(int n, int numbers[], int i);

int main(int argc, char* argv[]) {
    int num[10];
    int index1, index2;
    generate_numbers(num, 10);
    while(!is_sorted(num, 10)) {
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

    return 0;
}

/*
This generates an array of 10 numbers, each from 0 to 9999.
*/
void generate_numbers(int numbers[], int size) {
    int i = 0;
    while(i < size) {
        int n = rand() % 10000; // n is 0 to 9999
        if(is_unique(n, numbers, i)) {
            numbers[i] = n;
            i++;
        }
    }
}

/*
This checks that the subarray numbers[0..i-1] doesn't contain n
*/
bool is_unique(int n, int numbers[], int i) {
    for(int j = 0; j < i; j++) {
        if(numbers[j] == n) return false;
    }
    return true;
}

/*
This produces the following output:
+------+------+------+------+------+------+------+------+------+------+
| 6807 + 5249 + 0073 + 3658 + 8930 + 1272 + 7544 + 0878 + 7923 + 7709 |
+------+------+------+------+------+------+------+------+------+------+
*/
void display_numbers(int numbers[], int size) {
    std::cout << std::endl << "+";
    for(int i=0; i < size; i++) {
        std::cout << "------+";
    }
    std::cout << std::endl;
    std::cout << "|";
    for(int i=0; i < size; i++) {
        std::cout << " " << zeroes(numbers[i]) << numbers[i] << " |";
    }
    std::cout << std::endl << "+";
    for(int i=0; i < size; i++) {
        std::cout << "------+";
    }
    std::cout << std::endl;

}

/*
Returns string of zeros to pad n to a width of 4 characters. Assumes n is a number between 0 and 9999.
*/
std::string zeroes(int n) {
    if(n < 10) return "000";
    if(n < 100) return "00";
    if(n < 1000) return "0";
    return "";
}

/*
Checks if the array numbers[] is sorted in ascending order.
*/
bool is_sorted(int numbers[], int size) {
    for(int i=1; i<size; i++) {
        if(numbers[i] < numbers[i-1]) return false;
    }
    return true;
}

/*
Checks if index1 and index2 represent adjacent elements.
*/
bool is_adjacent(int index1, int index2) {
    int d = index1 - index2;
    return d == 1 || d == -1;
}
