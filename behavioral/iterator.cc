#include <iostream>
using namespace std;

// Agregator
class Stack10
{
public:
    class iterator
    {
        const Stack10 &fstack;
        int findex;
    public:
        // Next
        iterator(const Stack10 &s, int idx = 0): fstack(s), findex(idx) {}

        void operator++()
        {
            if(findex == -1)
                return;

            ++findex;

            if(findex >= fstack.fsize)
                findex = -1;
        }

        int operator *()
        {
            return fstack.items[findex];
        }

        bool operator == (const iterator & rhs)
        {
            return &this->fstack == &rhs.fstack && this->findex == rhs.findex;
        }

        // Instead of has next use not equal
        bool operator != (const iterator & rhs)
        {
            return !(*this == rhs);
        }

    };

private:

    int items[10];
    int fsize;
public:
    Stack10(): fsize(0) {}

    void push(int e)
    {
        items[fsize] = e;
        ++fsize;
    }

    int pop()
    {
        --fsize;
        return items[fsize];
    }

    int size() const
    {
        return fsize;
    }

    iterator begin() const
    {
        return iterator(*this);
    }

    iterator end() const
    {
        // dummy way
        return iterator(*this, -1);
    }
};


int main()
{
    Stack10 stack;
    for (int i = 1; i < 9; i++)
        stack.push(i);

    cout << (stack.end() != stack.end()) << endl;
    for(Stack10::iterator i = stack.begin(); i != stack.end(); ++i)
        cout << *i << endl;
}