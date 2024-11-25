#include <iostream>
#include <cstring>

using namespace std;

/*
    Ensure you include sufficient comments to explain your solutions. This can
    come in the form of a multi-line comment before the solution, or inline
    comments left within the solution itself.
*/

/*
    Calculates the length of a null-terminated string. 
    The function takes a pointer to a character array (string) as input 
    and iterates through the characters until it encounters the null terminator
    The function counts the number of characters and returns count
*/
unsigned int length(const char* str){
    unsigned int count = 0;//Initialize count
    while(str[count] != '\0'){
        count++;
    }
    return count;//Return length of string
}

/*
    Copies a null-terminated string from the source to the destination. 
    Takes each character up until the null terminator and copies onto the
    string dest, dest is then null-terminated and returned
*/

char* copy(char* dest, const char* src){
    unsigned int i = 0;//Initialize index
    while (src[i] != '\0') { //Loop until null terminator
        dest[i] = src[i];//Copying
        i++;
    }
    dest[i] = '\0'; // dest is null-terminated
    return dest;
}

/*
    Finds the index of the first occurrence of a specified character in a string
    The function takes a character to search for and a pointer to the string 
    in which to search, it returns the index of the character or -1 if the character is not found in the string
*/

int indexOf(char c, const char* str){
    for (int i = 0; str[i] != '\0'; i++) {//Loop through each char in string
        if (str[i] == c) { //Check if it matches 
            return i;//Returns index
        }
    }
    return -1;//Return -1 if not found
}

/*
    Creates a substring from a specified start index to an end index 
    The function accepts the starting and ending indices as well as the original string, 
    it validates the indices to ensure they are within bounds.
    It then transfers the character the bounds of those indices to a substring and
    returns the substring.
*/

char* substring(int i, int j, const char* str) {
    int len = length(str);//Get length of string
    
    // Check if indices are valid
    if (i < 0 || j > len || i >= j) {
        return nullptr; // Return null if indices are out of range or invalid
    }
    
    char* sub = new char[j - i + 1]; // Allocate size of substring (+1 for null terminator)
    int k = 0;//Initialize index for substring
    
    // Copy the characters from str
    for (int idx = i; idx < j; idx++) { // Copy up to but not including j
        sub[k++] = str[idx];//Copy each char to substring
    }
    
    sub[k] = '\0'; // Null-terminate the substring
    return sub;
}

/*
    Replaces all occurrences of a specified character in a string with a new character
    The function takes three parameters: the character to be replaced, 
    the new character to replace it with, and the original string 
    It creates a new modified string and iterates through the original string, 
    replacing occurrences of the specified character.
    The function returns the new modified string.
*/

char* replace(char c, char p, const char* str){
    int len = length(str);//Get length
    char* newStr = new char[len + 1]; // Allocate size for modified string
    for (int i = 0; i < len; i++) { //Loop through original string
        if (str[i] == c) { // If it matches c replace with p
            newStr[i] = p;
        } else {
            newStr[i] = str[i];
        }
    }
    newStr[len] = '\0'; // Null-terminate the modified string
    return newStr;//Return modified string
}

/*
    - Try to include your test cases below this multi-line comment -

    Ensure your test cases use the following format:

    [function]_name_test_case_[k](){
        test_input = example_value;
        expected_output = example_value;

        result = [function](test_input)
        if(result == output){
            cout << "[function]_name_test_case_[k] PASSED" << endl;
        }
        else{
            cout << "[function]_name_test_case_[k] FAILED" << endl;
        }
    }

    [function] - The name of the function being tested
    [k] - The index of the test
*/

/*
    Compares two null-terminated strings for equality. 
    The functions takes two strings and checks to see if they equal.
    YThis function is used for the test cases that involves checking if strings match.
*/

bool areStringsEqual(const char* str1, const char* str2) {
    int i = 0;//Initialize index
    // Compare characters one by one until a mismatch or the null terminator is found
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) { //If do not match
            return false;//Strings dont match
        }
        i++;
    }
    // Check if both strings ended at the same length
    return str1[i] == '\0' && str2[i] == '\0';
}


void length_test_case_1() {
    const char* test_input = "string";//Test string
    unsigned int expected_output = 6;//Expected length
    unsigned int result = length(test_input); //Call function
    if (result == expected_output) { //Check if they match
        cout << "length_test_case_1 PASSED" << endl;
    } else {
        cout << "length_test_case_1 FAILED" << endl;
    }
}

void length_test_case_2() {
    const char* test_input = "Hello"; //Test string
    unsigned int expected_output = 5;//Expected length
    unsigned int result = length(test_input);// Call function
    if (result == expected_output) { //Check if they match
        cout << "length_test_case_2 PASSED" << endl;
    } else {
        cout << "length_test_case_2 FAILED" << endl;
    }
}

void length_test_case_3() {
    const char* test_input = "resulted";//Test string
    unsigned int expected_output = 8;//Expected length
    unsigned int result = length(test_input);//Call function
    if (result == expected_output) { // Check if they match
        cout << "length_test_case_3 PASSED" << endl;
    } else {
        cout << "length_test_case_3 FAILED" << endl;
    }
}

void copy_test_case_1() {
    const char* src = "string"; //Test string
    char dest[10];
    const char* expected_output = "string"; //Expected string
    char* result = copy(dest, src); //Call function
    if (areStringsEqual(result, expected_output)) { //Check if they match
    cout << "copy_test_case_1 PASSED" << endl;
    } else {
    cout << "copy_test_case_1 FAILED" << endl;
    }
}

void copy_test_case_2() {
    const char* src = "Hello"; //Test string
    char dest[10];
    const char* expected_output = "Hello";//Expected string
    char* result = copy(dest, src); // Call function
    if (areStringsEqual(result, expected_output)) { //Check if they match
    cout << "copy_test_case_2 PASSED" << endl;
    } else {
    cout << "copy_test_case_2 FAILED" << endl;
    }
}

void copy_test_case_3() {
    const char* src = "fail"; //Test string
    char dest[10];
    const char* expected_output = "fail"; //Expected String
    char* result = copy(dest, src); // Call function
    if (areStringsEqual(result, expected_output)) { // Check if they match 
    cout << "copy_test_case_3 PASSED" << endl;
    } else {
    cout << "copy_test_case_3 FAILED" << endl;
    }
}

void indexOf_test_case_1() {
    const char* str = "string"; //Test string
    char test_input = 'i'; // Input
    int expected_output = 3; // Output
    int result = indexOf(test_input, str); //Call function
    if (result == expected_output) { // check if they match
        cout << "indexOf_test_case_1 PASSED" << endl;
    } else {
        cout << "indexOf_test_case_1 FAILED" << endl;
    }
}

void indexOf_test_case_2() {
    const char* str = "string"; // Test string
    char test_input = 'a'; //Input
    int expected_output = -1; //Output
    int result = indexOf(test_input, str);//Call function
    if (result == expected_output) { // Check if they match
        cout << "indexOf_test_case_2 PASSED" << endl;
    } else {
        cout << "indexOf_test_case_2 FAILED" << endl;
    }
}

void indexOf_test_case_3() { 
    const char* str = "string";//Test string
    char test_input = 'n';//Input
    int expected_output = 4;//Output
    int result = indexOf(test_input, str);//Call function
    if (result == expected_output) { // Check if they match
        cout << "indexOf_test_case_3 PASSED" << endl;
    } else {
        cout << "indexOf_test_case_3 FAILED" << endl;
    }
}

void substring_test_case_1() {
    const char* str = "string"; //String
    int start = 0, end = 3; //Indices
    const char* expected_output = "str";//Ouput
    char* result = substring(start, end, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "substring_test_case_1 PASSED" << endl;
    } else {
        cout << "substring_test_case_1 FAILED" << endl;
    }
}

void substring_test_case_2() {
    const char* str = "failed";//String
    int start = 0, end = 4;//Indices
    const char* expected_output = "fail";//Output
    char* result = substring(start, end, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "substring_test_case_2 PASSED" << endl;
    } else {
        cout << "substring_test_case_2 FAILED" << endl;
    }
}

void substring_test_case_3() {
    const char* str = "string";//String
    int start = 3, end = 6;//Indices
    const char* expected_output = "ing";//Output
    char* result = substring(start, end, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "substring_test_case_3 PASSED" << endl;
    } else {
        cout << "substring_test_case_3 FAILED" << endl;
    }
}

void replace_test_case_1() {
    const char* str = "string";//String
    char old_char = 'i';//Letter to replace
    char new_char = 'x';//Replaced letter
    const char* expected_output = "strxng";//Output
    char* result = replace(old_char, new_char, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "replace_test_case_1 PASSED" << endl;
    } else {
        cout << "replace_test_case_1 FAILED" << endl;
    }
}

void replace_test_case_2() {
    const char* str = "fail";//String
    char old_char = 'a';//Letter to replace
    char new_char = 'i';//Replaced letter
    const char* expected_output = "fiil";//Output
    char* result = replace(old_char, new_char, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "replace_test_case_2 PASSED" << endl;
    } else {
        cout << "replace_test_case_2 FAILED" << endl;
    }
}

void replace_test_case_3() {
    const char* str = "Hello";//String
    char old_char = 'o';//Letter to replace
    char new_char = 'a';//Replaced letter
    const char* expected_output = "Hella";//Output
    char* result = replace(old_char, new_char, str);

    if (result && areStringsEqual(result, expected_output)) {
        cout << "replace_test_case_3 PASSED" << endl;
    } else {
        cout << "replace_test_case_3 FAILED" << endl;
    }
}

// Call your test functions in the main function below
int main(){
   //Question 4.1
    length_test_case_1();
    length_test_case_2();
    length_test_case_3();
    //Question 4.2
    copy_test_case_1();
    copy_test_case_2();
    copy_test_case_3();

    //Question 4.3
    indexOf_test_case_1();
    indexOf_test_case_2();
    indexOf_test_case_3();

    //Question 4.4
    substring_test_case_1();
    substring_test_case_2();
    substring_test_case_3();

    //Question 4.5
    replace_test_case_1();
    replace_test_case_2();
    replace_test_case_3();

    return 0;
}