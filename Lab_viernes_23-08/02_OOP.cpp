#include <iostream>
#include <cstdlib>

using namespace std;

// Class CVector definition
class CVector
{
    private:
        int *m_pVect,           // Pointer to the buffer
            m_nCount,           // Control how many elements are actually used
            m_nMax,             // Control how many are allocated as maximum
            m_nDelta;           // To control the growing (crecimiento)
        void Init(int delta);   // Init our private variables, etc
        void Resize();          // Resize the vector when occurs an overflow
    public:
        CVector(int delta = 10);    // Constructor
        void Insert(int elem);      // Insert a new element
        int GetSize();              // Get the number of elements used
        int GetCapacity();          // Get the maximum number of elements that can be stored
        // More methods go here
};


CVector::CVector(int delta)
{
    m_nCount = 0;       // No elements are used
    m_nMax = 0;         // No memory is allocated
    m_nDelta = delta;   // Set the delta
    m_pVect = NULL;     // No memory is allocated
}

void CVector::Insert(int elem)
{
    if( m_nCount == m_nMax )    // Verify the overflow
        Resize();               // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize()
{
    int newMax = m_nMax + 5; // Aumentar el tamaño en 5 posiciones de memoria
    int *newVect = (int*)realloc(m_pVect, newMax * sizeof(int)); // Reasignar memoria para el nuevo tamaño
    m_pVect = newVect; // Actualizar el puntero al nuevo buffer
    m_nMax = newMax; // Actualizar el tamaño máximo
}

int CVector::GetSize()
{
    return m_nCount;
}

int CVector::GetCapacity()
{
    return m_nMax;
}

int main()
{
    CVector v(5);
    v.Insert(10);
    v.Insert(20);
    v.Insert(30);
    v.Insert(40);
    v.Insert(50);
    v.Insert(60);

    cout << "Vector size: " << v.GetSize() << endl;
    cout << "Vector capacity: " << v.GetCapacity() << endl;

    v.Insert(70);
    v.Insert(80);
    v.Insert(90);
    v.Insert(100);
    v.Insert(110);
    v.Insert(120);

    cout << "Vector size: " << v.GetSize() << endl;
    cout << "Vector capacity: " << v.GetCapacity() << endl;

    return 0;
}