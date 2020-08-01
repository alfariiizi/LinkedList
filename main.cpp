#include <assert.h>
#include <iostream>

template<typename T>
class LinkedList
{
private:
    class Node
    {
    public:
        Node( T data ) : data( data ), pNext( nullptr ) {}
    public:
        T data;
        Node* pNext;
    };

public:
    LinkedList() : pHead( nullptr ) {}
    ~LinkedList() { ClearStack(); }
    T& operator[]( const size_t i )
    {
        auto pTmp = pHead;
        size_t n = Size() - i - 1;
        assert( n >= 0 );

        while( n > 0 )
        {
            pTmp = pTmp->pNext;
            --n;
        }
        
        return pTmp->data;
    }
    void Push( int data )
    {
        Node* pNode = new Node( data );
        if( IsEmpty() )
            pHead = pNode;
        else
        {
            pNode->pNext = pHead;
            pHead = pNode;
        }
    }
    T Pop()
    {
        assert( !IsEmpty() );
        Node* pTmp = pHead;
        pHead = pHead->pNext;
        int data = pTmp->data;
        delete pTmp;
        
        return data;
    }
    void ClearStack()
    {
        while( !IsEmpty() )
        {
            Pop();
        }
    }
    size_t Size() const
    {
        Node* pTmp = pHead;
        size_t i = 0;
        while( pTmp != nullptr )
        {
            pTmp = pTmp->pNext;
            ++i;
        }

        return i;
    }
    bool IsEmpty() const
    {
        return pHead == nullptr;
    }
private:
    Node* pHead;
};

int main()
{
    LinkedList<int> ll;
    ll.Push( 10 );
    ll.Push( 4 );

    ll[0] = 20;
    std::cout << ll[0] << '\n';
    std::cout << ll.Size() << '\n';
    std::cout << ll.Pop() << '\n';
    std::cout << ll.Pop() << '\n';
    std::cout << ll.Size() << '\n';

    return 0;
}