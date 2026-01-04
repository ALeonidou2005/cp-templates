/*
More Info: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
*/

#include <iostream>
using namespace std;

#define ll long long

//REQUIRED TO USE ORDERED_SET
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

void printOrderedSet(ordered_set st){
	cout<<"Elements in Set: { ";
	for (ordered_set :: iterator it = st.begin(); it != st.end(); it++){
		cout<<*it<<" ";
	}
	cout<<"} "<<endl;
}

int main() { 
	//declare
    ordered_set st; 
  
	//insert elements
    st.insert(5); 
    st.insert(1); 
    st.insert(2); 

    //print set
    printOrderedSet(st);
  
    // Finding the second smallest element in the set
    cout<<"2nd Element: "<<(*(st.find_by_order(1)))<<endl; 
  
    // Finding the number of elements strictly less than 4
    cout<<"Number of Elements less than 4: "<<st.order_of_key(4)<<endl; 
  
    // Finding the count of elements strictly less than 5
    cout<<"Number of Elements less than 5: "<<st.order_of_key(5)<<endl; 
  
    // Deleting 2 from the set
    st.erase(2); 

    //print set
    printOrderedSet(st);
  
    // Finding the number of elements strictly less than 4
    cout<<"Number of Elements less than 4: "<<st.order_of_key(4)<<endl; 
    
    return 0; 
} 

/*
• Ordered Set is a policy based data structure and requires some libraries only the GNU Compiler provides in order to copmiler.
• Ordered Set has all the functions of std::set, while also providing 2 new functions:
	1. find_by_order()
	2. order_of_key()
*/





























