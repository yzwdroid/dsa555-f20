#include <iostream>
/*
let n represent the number we are finding the factorial for
let T(n) represent the number of operations it takes to find n!
*/

unsigned int factorial (unsigned int n){
	unsigned int rc = 1;			//1
	if(n > 1){						//1
		rc = n * factorial (n-1);	//3 + T(n-1)
	}									//3 from =,*,- and 
										//T(n-1) for # of ops in factorial of (n-1)
	return rc;						//1
}


/*

T(n) = 1 + 1 + 1 + 3 + T(n-1)      , for  n >= 2
	 = 6 + T(n-1)


T(0) = 3   --> line 8, 9 and 13
T(1) = 3   --> line 8, 9 and 13

T(2) = 6 + T(1)
     = 6 + 3

T(3) = 6 + T(2)
	 = 6 + 6 + 3

T(4) = 6 + T(3)
	 = 6 + 6 + 6 + 3

T(5) = 6 + T(4)
     = 6 + 6 + 6 + 6 + 3

T(n) = 6 + T(n-1)     
	 = 6 + 6 + 6 + ... + 6 + 3  <--- how many 6's on this line? n-1 6's
	 = 6(n-1) + 3
	 = 6n - 6 + 3
	 = 6n - 3

Therefore T(n) is O(n)
*/






int main(void){
	unsigned int x = factorial (4);
	std::cout << x << std::endl;
	return 0;
}