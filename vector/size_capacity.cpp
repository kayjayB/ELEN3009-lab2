// size_capacity.cpp
// Vector size versus capacity

// A vector's size is the number of elements that it contains and the capacity is the maximum number of elements
// the vector can contain before reallocation.
// The capacity grows in this way so that the user does not have to be actively involved in memory reallocation
// and management. This automatic memory reallocation allows for an efficient use of memory (not wasteful).


#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
