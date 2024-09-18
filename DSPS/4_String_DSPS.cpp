#include <iostream>
#include <string>

using namespace std;

// Initializating Stack
const int stack_size = 100;
char stack[stack_size];
int top = -1;

// String Length
int string_length(const char *s)
{
    int len = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}

// String Reverserd
char *string_rev(const char *s)
{
    int len = string_length(s);
    char *rev = new char;
    for (int i = 0; i < len; i++)
    {
        rev[i] = s[len - i - 1];
    }
    rev[len]='\0';
    return rev;
}

// String Comparision
bool string_compare(const char *s1, const char *s2)
{
    int len1 = string_length(s1);
    int len2 = string_length(s2);
    if (len1 != len2)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            if (s1[i] != s2[i])
            {
                return false;
            }
        }
    }
    return true;
}

// String Upper
void stringUpp(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
}

// String Lower
void stringLow(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
}

// String Concattination
char *string_Con(const char *s1, const char *s2)
{
    int len1 = string_length(s1);
    int len2 = string_length(s2);
    char *result = new char;
    for (int i = 0; i < len1; i++)
    {
        result[i] = s1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        result[i + len1] = s2[i];
    }
    result[len1 + len2] = '\0';
    return result;
}

// String Copy
void string_copy(char *d, const char *s)
{
    while (*s!= '\0')
    {
        *d = *s;
        d++;
        s++;
    }
}

// Remove Duplicate
char *remove_Dupli(const char *s)
{
    bool seen[256] = {false};
    int len = string_length(s);
    int index = 0;
    char *result = new char;

    // Loop through each character of the input string
    for (int i = 0; i < len; i++)
    {
        char currentChar = s[i];

        // If the character hasn't been seen yet, add it to the result
        if (!seen[(unsigned char)currentChar])
        {
            seen[(unsigned char)currentChar] = true; // Mark as seen
            result[index] = currentChar;             // Add to result
            index++;
        }
    }

    // Null-terminate the result string
    result[index] = '\0';
    return result;
}

// Is Pallindrome String
bool is_Pallindrome(const char *s)
{
    int len = string_length(s);
    char *rev = new char;
    rev = string_rev(s);
    return string_compare(s, rev);
}

// ---------------
// Checking Pallindrome or Not Using Stack
// --------------

// Stack Push function (with overflow check)
void push(char s)
{
    if (top < stack_size - 1)
    {
        stack[++top] = s;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}

// Stack Pop function (with underflow check)
void pop()
{
    if (top >= 0)
    {
        top--;
    }
    else
    {
        cout << "Stack underflow" << endl;
    }
}

// Stack-based Palindrome Checking
bool is_Pallindrome_Stack(const char *s)
{
    int len = string_length(s);
    
    // Start comparing stack top with the original string
    for (int i = 0; i < len; i++)
    {
        if(s[i]==" " || s[i]==","){
            continue;
        }

        if (stack[top] != s[i])
        {
            return false;
        }
        pop();
    }
    return true;
}

// Push the string onto the stack and check for palindrome
void print_Pallindrome_Stack(const char *s)
{
    int len = string_length(s);
    top = -1;  // Reset stack
    
    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++)
    {
        if(s[i]==" " || s[i]==","){
            continue;
        }
        push(s[i]);
    }
    
    // Check palindrome using the stack
    if (is_Pallindrome_Stack(s))
    {
        cout << "This string is a palindrome." << endl;
    }
    else
    {
        cout << "This string is not a palindrome." << endl;
    }
}

// Checking Proper Number Time Of Occurence
void charOcc(const char* s, char Target){
    int len = string_length(s);
    int count = 0;
    for(int i=0;i<len;i++){
        if(s[i]==Target){
            count++;
        }
    }
    cout << "Occurs '" << Target << "' :-  " << count <<endl;
}

// Pushing in Occurence
void Occ(const char* s){
    char* unique = new char;
    unique = remove_Dupli(s);
    for(int i =0;unique[i]!='\0';i++){
        charOcc(s,unique[i]);
    }
}

// Cheking Index Of each Element
void checkIndex(const char* s, char Target){
    int len = string_length(s);
    for(int i=0;i<len;i++){
        if(s[i]==Target){
            cout << "Index of '" << Target << "' is :- " << i << endl;
        }
    }
}

// Pushing in Index Function Parameter
void indexPos(const char* s){
    char* unique1 = new char;
    unique1 = remove_Dupli(s);
    for(int i=0;unique1[i]!='\0';i++){
        checkIndex(s,unique1[i]);
    }
}

int main()
{
    int choice=0;
    char* s = new char;
    char* s1 = new char;
    char* s2 = new char;

    while(choice!=13){
        cout << "\nChoose an operation: \n";
        cout << "1. Find string length\n";
        cout << "2. Reverse string\n";
        cout << "3. Compare two strings\n";
        cout << "4. Convert string to uppercase\n";
        cout << "5. Convert string to lowercase\n";
        cout << "6. Concatenate two strings\n";
        cout << "7. Copy string\n";
        cout << "8. Remove duplicates\n";
        cout << "9. Check if string is a palindrome\n";
        cout << "10. Check if string is a palindrome using stack\n";
        cout << "11. Count occurrences of each character\n";
        cout << "12. Find index of each character\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter string: ";
            cin >> s;
            cout << "Length of string: " << string_length(s) << endl;
            break;

        case 2:
            cout << "Enter string: ";
            cin >> s;
            cout << "Reversed string: " << string_rev(s) << endl;
            break;

        case 3:
            cout << "Enter first string: ";
            cin >> s1;
            cout << "Enter second string: ";
            cin >> s2;
            if (string_compare(s1, s2))
            {
                cout << "Strings are equal.\n";
            }
            else
            {
                cout << "Strings are not equal.\n";
            }
            break;

        case 4:
            cout << "Enter string: ";
            cin >> s;
            stringUpp(s);
            cout << "Uppercase string: " << s << endl;
            break;

        case 5:
            cout << "Enter string: ";
            cin >> s;
            stringLow(s);
            cout << "Lowercase string: " << s << endl;
            break;

        case 6:
            cout << "Enter first string: ";
            cin >> s1;
            cout << "Enter second string: ";
            cin >> s2;
            cout << "Concatenated string: " << string_Con(s1, s2) << endl;
            break;

        case 7:
            cout << "Enter first string: ";
            cin >> s1;
            cout << "Enter second string: ";
            cin >> s2;
            string_copy(s1, s2);
            cout << "Copied string: " << s2 << endl;
            break;

        case 8:
            cout << "Enter string: ";
            cin >> s;
            cout << "String after removing duplicates: " << remove_Dupli(s) << endl;
            break;

        case 9:
            cout << "Enter string: ";
            cin >> s;
            if (is_Pallindrome(s))
            {
                cout << "String is a palindrome.\n";
            }
            else
            {
                cout << "String is not a palindrome.\n";
            }
            break;

        case 10:
            cout << "Enter string: ";
            cin >> s;
            print_Pallindrome_Stack(s);
            break;

        case 11:
            cout << "Enter string: ";
            cin >> s;
            Occ(s);
            break;

        case 12:
            cout << "Enter string: ";
            cin >> s;
            indexPos(s);
            break;

        case 13:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
