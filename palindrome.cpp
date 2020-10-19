//function returns true if s is a palindrome (written recursively
//returns true if s is a palindrom, false otherwise
// mom, dad, noon, snowman
/*
base cases:

"" - yes ... nothing mirror itself as nothing
"a" - yes 
first char != last char - no

recursive case:

"dad" - yes... "dad" ==> "a" --> yes
"racecar" -> "aceca" --> "cec" --> "e" --> yes  
"husky" --> false
*/

bool isPalindrome(const char* s){
	return isPalindrome(s,0,strlen(s)-1);
}

bool isPalindrome(const char* s, int first, int last)
{
 
    if (last <= first) // Base case, only one letter or empty
        return true;
    else if (s[first] != s[last]) // Base case,only 2 letters or more
        return false;
    else
        return isPalindrome(s, first + 1, last - 1);
 
}

int main() {
    //const char* string = "tot";
    std::vector<const char*> words;
    words.push_back("racecar");
    words.push_back("radar");
    words.push_back("husky");
    words.push_back("saippuakivikauppias");
    words.push_back("turtles");
    
    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << "  ";
        if (isPalindrome(words[i]))
            std::cout << "true";
        else
            std::cout << "false";
        std::cout << std::endl;
    }
    
}


/* Analysis*/

Let n represent the length of the string
Let T(n) represent number of operations it takes for palindrome(s) to find
palindrome of a string with n characters
Let S(n) represent the number operations needed for palindrome(s,f,l) to find the 
palindrome with n characters (l-f+1)


bool isPalindrome(const char* s){
    return isPalindrome(s,0,strlen(s)-1);  //1 + S(n) + n + 1  
}
/* 1 for return
   S(n) for isPalindrome(s,f,l)
   n for strlen()
   1 for -
*/


bool isPalindrome(const char* s, int first, int last)
{
 
    if (last <= first)               //1
        return true;
    else if (s[first] != s[last])    //1 
        return false;
    else
        return isPalindrome(s, first + 1, last - 1); //1 + S(n-2)
 
}

/* 1 for the return, S(n-2) for call to isPalindrome(s,f+1,l-1)*/

T(n) = 1 + S(n) + n + 1

S(n) = 1 + 1 + 1 + S(n-2) for n >= 2

S(0) = 2     //empty strings costs 1 op
S(1) = 2     //strings with one char costs 1 op

S(n) = 3 + S(n-2)                 for n >= 2

S(n-2) = 3 + S((n-2)-2) = 3 + S(n-4)
S(n-2) = 3 + S(n-4)
S(n-4) = 3 + S(n-6)
S(n-6) = 3 + S(n-8)
...
S(3) = 3 + S(1)
     =  3 + 2

S(2) = 3 + S(0)
     = 3 + 2


S(5) = 3 + S(3) = 3 + 3 + 2
S(4) = 3 + 3 +2

S(6) = 3 + S(5) = 3 + 3 + 3 +2
S(7) = 3 + 3 + 3 + 2

S(n) = 3 (n/2) + 2

T(n) = 1 + S(n) + n + 1
     = 1 + 3 (n/2) + 2 + n +1
     = 4 + 5/2 n
     = 2.5 n + 4  <--- 2.5 n is dominating term

Therefore T(n) is O(n) 


/* Solution 2 */


Let n represent the number of characters in a given string
Let T(n) represent the number of operations it takes to determines if s is a Palindrome

bool isPalindrome(const char* s)
{   
    if (strlen(s) <= 1)                          //n       
        return true;                                    
    else if (s[0] != s[strlen(s) - 1])           //n          
        return false;                                                                      
    else {  
        int size = strlen(s) - 2;                //n    
        char* string = new char[size];           //1       
        for (unsigned int i = 1; i < size+1; i++) { //1 + n + n    
            string[i-1] = s[i];                     //2n    
        }       
        string[size] = '\0';                        //1       
        return (isPalindrome(string));              //1+T(n-2) 
    }       
}

T(n) = n + n + n + 1 + 1 + n + n + 2n + 1 + 1 + T(n-2)
     = 7n + 4 + T(n-2)

T(n-2)= 7(n-2) + 4 + T(n-4)  <--sub in n-2 for n in prev.

T(n-4)= 7 (n-4) + 4 + T(n-6)

T(0) = n + 1
T(1) = n + 1

T(3) = 7(3) + 4 + T(1) = 7(3) + 4 + n + 1
T(2) = 7(2) + 4 + T(0)

T(5) = 7(5) + 4 + T(3) = 7(5) + 4 + 7(3) + 4 + n + 1

T(7) = 7(7) + 4 + T(5) = 7(7) + 4 + 7(5) + 7(3) + 4 + 4 + n + 1


T(n) = 7(n + n-2 + n-4 + n-6 + ... + 6 + 4 + 2) + 4(n/2) + n + 1
     = 7(2)(n/2 + (n-2)/2 + (n-4)/2... 6/2 + 4/2 + 2/2) +  3n + 1
     = 7(2)(n/2 + (n/2)-1 + (n/2)-2... 3+2+1) + 3n +1
     = 7(2)*[((n/2)((n/2)+1))/2] +  3n +1  <--[((n/2)((n/2)+1))/2] comes from arithmetic series see math appendix
     = 7/4 n^2 + 7/4 n + 3n + 1 
     = 7/4 n^2 + 19/4 n + 1 <--- dominating term is 7/4 n^2

therefore T(n) is O(n^2)



