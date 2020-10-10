#include <string>
#include <iostream>

/* Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.

 Assumption:
 1. Time complexity: O(|S|), S is the shortest string between the two
 2. Space complexity: O(1)
 3. Cant use any other DS
 4. ASCII string, valid input

 Exmples:
 1. abcdef, fedabc
 2. adchb, dkjhf

 Algorithm:
1. Iterate over both strings simultaneously - If you finished one but not the other, return false
2. As you iterate the string - Fill histogram, in the end, compare both histograms. O(1) since there are 26 ABC chars.
 */

using namespace std;

constexpr int NUM_LETTERS = 26;

bool compareHist(int *a1, int *a2){
    for(int i = 0; i < NUM_LETTERS; i++){
        if(a1[i] != a2[i]) return false;
    }
    return true;
}

void initHist(int *hist){
    for(int i = 0; i < NUM_LETTERS; i++){
        hist[i] = 0;
    }
}

bool checkPerm(string str1, string str2){
    string::iterator it1, it2;
    it1 = str1.begin();
    it2 = str2.begin();
    int hist1[NUM_LETTERS];
    int hist2[NUM_LETTERS];
    initHist(hist1);
    initHist(hist2);
    while(it1 != str1.end() && it2 != str2.end()){
        hist1[(int)(*it1 - 'a')]++;
        hist2[(int)(*it2 - 'a')]++;
        it1++;
        it2++;
    }
    if((it1 != str1.end()) || (it2 != str2.end())){
        return false;
    }
    return compareHist(hist1, hist2);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    if(checkPerm(str1, str2)){
        cout << "Is Permutation!" << endl;
    }
    else cout << "Not a Permutation..." << endl;
    return 0;
}
