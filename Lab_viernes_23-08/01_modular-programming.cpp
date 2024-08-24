
#include <cstdlib>

void Resize(int *& rpVect, int& rnMax)
{
    const int delta = 10; // Used to increase the vector size
    rpVect = (int*)realloc(rpVect, sizeof(int) * (rnMax + delta));
    rnMax += delta; // The Max has to be increased by delta
}

void Insert(int *& rpVect, int& rnCount, int& rnMax, int elem)
{
    if( rnCount == rnMax ) // Verify the overflow
        Resize(rpVect, rnMax); // Resize the vector before inserting elem
    rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}

struct Vector
{
    int* m_pVect; // Pointer to the buffer
    int m_nCount; // Control how many elements are actually used
    int m_nMax; // Control how many are allocated as maximum
    int m_nDelta; // To control the growing
};

void Insert(Vector *pThis, int elem)
{
    if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
        Resize(pThis->m_pVect, pThis->m_nMax); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector *pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) *(pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}

int main()
{
    Vector *v = new Vector();

    Insert(v, 10);
    Insert(v, 20);
    Insert(v, 30);
    Insert(v, 40);
    Insert(v, 50);
    Insert(v, 60);
    Insert(v, 70);
    Insert(v, 80);
    Insert(v, 90);
    Insert(v, 100);
    Insert(v, 110);
    Insert(v, 120);


    return 0;
}