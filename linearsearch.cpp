//the search is unsuccessful (key is not found)

/*
Let n represent size of the vector arr
Let T(n) represent the number of operations needed to find key in arr
*/

template <class TYPE>
int linearSearch(const vector<TYPE>& arr, const TYPE& key){
    int rc=-1;									//1
    for(int i=0;i<arr.size()&& rc==-1;i++){		//1  +  4(n) + 1(n) --> =, <.&&==, ++
        if(arr[i]==key){						//1(n)
            rc=i;								//0
        }
    }
    return rc;									//1
}


/*
T(n) = 1 + 1 + 5n + n +1
     = 6n + 3

Therefore T(n) is O(n)
*/

//other options for analysis:
//worst case successful search  (key found at end)
//average case... we have to evaluate the chance that key is found in every spot,
//calculate cost of every position, and get the expected value