#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vector
{
public:
    // Prevent the problem for v(17), raise an compilation error
    // The explicit keyword is used to prevent implicit conversions in C++.
     
    /*
      vecter<int> vec;
      vec == 17; (vec == vector(17,0)), implicite conversion
    */
    
    // vector<int> v(10, 17): Create a vector that hold 10 ints all of which are 17.
    explicit Vector (size_t size, int value = 0)
    {
        theSize = size;
        theCapacity = size;
        data = new int[theCapacity];    // Creating a dynamic array that can hold theCapacity number of int.
        for (size_t i = 0; i < theSize; i++)
        {
            data[i] = value;
        }
    }
    
    // Default Constructor
    Vector ()
    {
        theSize = 0;
        theCapacity = 0;
        data = nullptr;
        // data = new int[0];   // also valid
    }
    
    /*
     * Copy Control (The Big 3)
     */
    
    // Destructor
    ~Vector()
    {
        // Free up the array
        // Adding [] after delete tells the compiler that it is not just a single int that we want to delete, but instead a whole array of them.
        // Since array is a primitive data type, by calling delete on an array, C++ will deal with all the elements in the array. We don't have to loop over to delete them. 
        delete [] data;
    }
    
    // Copy Constructor: Used anytime you are initializing a new thing from another thing with the same type.
    // If no copy constructor were given, the compiler will use the default copy constructor, which makes a shallow copy of each of the private field.
    Vector(const Vector& rhs)
    {
        // For primitive data types, it doesn't matter whether you copy it in the body of the constructor or the initializing list.
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        // deep copy one by one
        for (size_t i = 0; i < theSize; i++)
        {
            data[i] = rhs.data[i];
        }
    }
    
    // Assignment Operator: v1 = v2
    // C++ don't have a default assignment operator if no assignment operator were given.
    Vector& operator=(const Vector& rhs)
    {
        // Check for self assignment by comparing the address.
        if (this != &rhs)
        {
            // Free up resources (space on the heap) from the lhs
            // This step is needed because sometimes we are assigning to a object where it has already been initialized.
            delete [] data;
            
            // Allocate and Copy
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new int[theCapacity];
            for (size_t i = 0; i < theSize; i++)
            {
                data[i] = rhs.data[i];
            }
        }
        // Return Yourself
        return *this;   // dereference of "this" ("this" is a pointer to myself)
    }
    
    void push_back (int val)
    {
        // Make sure you have enough capacity to add val
        // We don't want the capacty to change by a constant number because it will cause a amortize constant runtime.
        if (theSize == theCapacity)
        {
            if (theSize == 0)
            {
                delete [] data;
                theCapacity = 1;
                data = new int[theCapacity];
            }
            else
            {
                int* oldData = data;
                theCapacity *= 2;
                data = new int[theCapacity];
                for (size_t i = 0; i < theSize; i++)
                {
                    data[i] = oldData[i];
                }
                // We don't need to do a deep delete here because we are pointing data[i] to oldData[i], which means we are still using those element. Therefore, we will only need to delete the array(oldData) on the heap.
                delete [] oldData;
            }
        }
        // add the value and bump the size up.
        // data + (theSize * sizeof(int)); // pointer arithmetic
        // address of kth elements in vector = data + k = data[k] -> dereference: *(data+k)
        // only if data is a pointer
        // *(data + theSize) = val; //c++ do the math for you
        data[theSize] = val;    // syntax for dereference of a pointer
        theSize++;
    }
    
    size_t size() const
    {
        return theSize;
    }
    
    void clear()
    {
        theSize = 0;
    }
    
    void pop_back()
    {
        // This is dangerous because if your size is 0, doing minus one will make the size become the largest integer.
        theSize--;
    }

    // Square Brackets Operator (C++ requires us to implement it as a member function)
    // v[i];
    // v.operator[](i);
    // This is for accessing the element in the vector.
    int operator[](size_t index) const
    {
        return data[index];
    }
    
    // Square Brackets Operator
    // v[i] = 100;
    // This is for assigning element to the an index in the vector.
    // This overload the operator[] function, and function were choose during runtime based on if the action is const or not.
    int& operator[](size_t index)
    {
        return data[index];
    }
    
    // The for loop writes: for (size_t i = 0; i < v.size(); i++) = for (int* p = v.begin(); p != v.end(); p++)
    
    int* begin()
    {
        cout << "int* begin();" << endl;
        return data;
    }
    
    int* end()
    {
        return data + theSize;
    }
    
    // The const begin() and end() will be used under for each loop: for (int val : v)
    
    // These two const needs to exist together.
    const int* begin() const
    {
        cout << "const int* begin() const;" << endl;
        return data;    // Same as: return &data[0];
    }
    
    const int* end() const
    {
        // This need to return theSize element of the vector because it makes it "out of loop".
        return &data[theSize];      // Same as: return data + theSize;
    }
    
private:
    size_t theSize;
    size_t theCapacity;
    // This pointer to the data is stored on the heap.
    int* data;      // hold the address of the int (the address of the first element of the dynamic array)
};

void printVector (const Vector& v)
{
    // Accessing each element, using the constant begin() and end() function.
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    for (int val : v)
    {
        cout << val << ' ';
    }
}

int main()
{
    Vector v;   // not templated. Our Vector class can only hold ints.
    v.push_back(17);
    v.push_back(42);
    
    cout << sizeof(v) << endl;
    
    v.push_back(6);
    v.push_back(28);
    
    // A vector object takes up 24 bytes no matter how much the vector grows.
    cout << sizeof(v) << endl;
    
    // v2 is being initialized as a copy of v, which uses the copy constructor.
    Vector v2(v);
    
    // This initialize v4 as the same as v, which uses the copy constructor.
    Vector v4 = v;
    
    // This initialize v3 by calling the default constructor Vector().
    Vector v3;
    
    // This uses the assignment operator.
    v3 = v;
    
    // Don't want this loop because it is long and the variable i has nothing to do with the task that it is trying accomplish. Coder不能一眼看出我到底想要通过这个for loop得到什么.
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }

    // Use for each loop instead
    for (int val : v)
    {
        cout << val << ' ';
    }
    
    v[0] = 100;
    // expect a compilation error but not, returns 17 zeros, the compiler treat it as v = Vector(17)
    // v = 17;      // With the explicit keyword in the constructor, this won't work anymore.
    
    // cout << v.back() << endl;
    // back() returns the reference of the last item in the vector == v[v.size()-1]
    // printVector(v);
    
    for (int& val : v)
    {
        val *= 2;
    }

    for (int* p = v.begin(); p != v.end(); p++)
    {
        int& val = *p;
        val *= 2;
    }
}
