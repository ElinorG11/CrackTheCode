/*
 * Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?
Time complexity assumed: O(|S|)
Space complexity assumed: O(|S|)
Cannot modify input, Cannot use additional DS
Characters from abc, input is valid (no need for extra checks), UNIX coding assumed

Examples:
1. abcd
2. aabc
3. abcdefghijklmnopqrstuvqxyza => more than 26 chars cant be unique!

Algorithm:
1. Check if string length exceeds the number of abc characters - if it does the string is not unique O(|S|)
2. Iterate over the string and keep in a histogram every letter you encounter. Before updating the counter in the adequate place in the hist, check if the cell value is 0, if it isn't - the string is not unique. O(1) since the length of str < 26 and we perform constant number of actions for each letter
3. If you finished - string is unique
 */


#include <string>
#include <iostream>

constexpr int NUM_OF_ABC = 26;

void initArray(int *array, int size){
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
}

int toInt(char c){
    return (int)(c - 'a');
}

bool IsUnique(std::string str){
    if(str.size() > NUM_OF_ABC){
        return false;
    }
    int hist[NUM_OF_ABC];
    initArray(hist, NUM_OF_ABC);
    for(std::string::iterator it = str.begin(); it < str.end(); it++){
        int num = toInt(*it);
        if(hist[num] >= 1){
            return false;
        }
        hist[num]++;
    }
    return true;
}

int main() {
    std::string str;
    std::cin >> str;
    if(IsUnique(str)){
        std::cout << "Unique string!" << std::endl;
    }
    else std::cout << "Not Unique..." << std::endl;
    return 0;
}