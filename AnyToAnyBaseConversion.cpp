/* A C++ program to implement number conversion from any base system to any base system. */  
#include <iostream>
using namespace std;
/* A function to reverse a string */ 
void reverse (char str[], int length) {
    int start = 0;
    int end = length - 1;
  
    while (start < end){
        swap (*(str + start), *(str + end));
        start++;
        end--;
    }
}

// Implementation of converting function()
char *convert (int num, char *str, int base) {
    int i = 0;
    bool isNegative = false;
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */ 
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
}
  
    // Check if number is of base 10 and unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
  
    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    } 
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
  
    str[i] = '\0';		// Append string terminator
  
    // Reverse the string
    reverse (str, i);
  
    return str;
}


// Driver program to test implementation of convert()
int main () 
{
  
    char str[100];

    //Decimal to any base
    cout << "\n ----------Decimal to any base---------- " ;
    cout << "\n Original Decimal No: 1567";
    cout << "\n Base 10 = " << convert (1567, str, 10) << endl;
     
 
    //Binary to any base
    cout << "\n ----------Binary to any base---------- " ;
    cout << "\n Original Binary No: 0b11000011111";
    cout << "\n Base 2 = " << convert (0b11000011111, str, 2) << endl;

    //Octal to any base
    cout << "\n ----------Octal to any base---------- " ;
    cout << "\n Original Octal No: 03037" ;
    cout << "\n Base 8 = " << convert (03037, str, 8) << endl;
    
    //Hex to any Base
    cout << "\n ----------Hexadecimal to any base----------" ;
    cout << "\n Original No: 03037" ;
    cout << "\n Base 16 = " << convert (0x61f, str, 16) << endl;
     
    return 0;

}


/*
*---------------------------------OUTPUT----------------------------------*


 ----------Decimal to any base---------- 

 Original Decimal No: 1567

 Base 10 = 1567



 ----------Binary to any base---------- 

 Original Binary No: 0b11000011111

 Base 2 = 11000011111



 ----------Octal to any base---------- 

 Original Octal No: 03037

 Base 8 = 3037



 ----------Hexadecimal to any base----------

 Original No: 03037

 Base 16 = 61f

*/