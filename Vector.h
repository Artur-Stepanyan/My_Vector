#include <iostream>

class Vector
{
    public:
        //ctors
        Vector(); //default ctor
        Vector(int cap, int value = 0); //parametrized ctor
        Vector(const Vector& vec); //copy ctor
        Vector& operator=(const Vector& vec); // copy assignment operator
        ~Vector(); // destructor

        //operators
        int& operator[](int index);
        Vector operator+(const Vector& vec);
        Vector& operator+=(const Vector& vec); 
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);


        //member functions
        int Size() const;
        int Capacity() const;
        void push_back(int value);
        void pop();
        void insert(int pos, int value);
        int find_by_value(int) const;
        void remove_by_value(int);

    private:
        int m_capacity;
        int m_size;
        int* m_ptr;
};
