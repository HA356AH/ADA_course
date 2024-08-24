#include <iostream>

using namespace std; // Add this line to use the std namespace

template <typename Type>
class CVector
{
private:
    vector<Type> m_pVect; // Use std::vector instead of a raw pointer
    int m_nCount;         // Control how many elements are actually used
    int m_nMax;           // Control the number of allocated elements
    int m_nDelta;         // To control the growing

public:
    CVector(int delta = 10); // Constructor
    void Insert(Type elem);  // Insert a new element
    int GetSize();           // Add this function to get the size of the vector
    Type& operator[](int index); // Add this function to overload the operator[]
};

// Class CVector implementation
template <typename Type>
CVector<Type>::CVector(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect.resize(m_nMax); // Resize the vector to the initial size
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
    {
        m_nMax += m_nDelta; // Increase the maximum size
        m_pVect.resize(m_nMax); // Resize the vector
    }
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

template <typename Type>
int CVector<Type>::GetSize()
{
    return m_nCount; // Return the number of elements used
}

template <typename Type>
Type& CVector<Type>::operator[](int index)
{
    return m_pVect[index]; // Return the element at the specified index
}

int main()
{
    CVector<int> vec; // Create a vector of integers
    vec.Insert(10);  // Insert an element
    vec.Insert(20);  // Insert another element
    vec.Insert(30);  // Insert one more element

    // Print the elements in the vector
    for (int i = 0; i < vec.GetSize(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}


template <typename Type>
class CVector
{
    private:
        Type* m_pVect; // Pointer to the buffer
        int m_nCount; // Control how many elements are actually used
        int m_nMax; // Control the number of allocated elements
        int m_nDelta; // To control the growing
        void Init(int delta); // Init our private variables, etc
        void Resize(); // Resize the vector when occurs an overflow
    public:
        CVector(int delta = 10); // Constructor
        void Insert(Type elem); // Insert a new element
};

// Class CVector implementation
template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

int main()
{
    CVector<int> vec; // Create a vector of integers
    vec.Insert(10); // Insert an element
    vec.Insert(20); // Insert another element
    vec.Insert(30); // Insert one more element

    // Print the elements in the vector
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}



/*



typedef int Type;
class CVector
{
    private:
        Type*m_pVect; // Pointer to the buffer
    public:
        void Insert(Type elem); // Insert a new element
};

template <typename Type> class CVector
{
    private:
        Type*m_pVect; // Pointer to the buffer
        int m_nCount, // Control how many elements are actually used
        m_nMax, // Control the number of allocated elements
        m_nDelta; // To control the growing
        void Init(int delta); // Init our private variables, etc
        void Resize(); // Resize the vector when occurs an overflow
    public: 
        CVector(int delta = 10); // Constructor
        void Insert(Type elem); // Insert a new element
        // ...  
};

// Class CVector implementation
template <typename Type> CVector<Type>::CVector(int delta)
{
    Init(delta);
}


template <typename Type> void CVector<Type>::Insert(Type &elem)
{
    if( m_nCount == m_nMax ) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

*/