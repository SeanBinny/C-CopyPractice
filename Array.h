#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

template < class T >
class Array
{
public :
    explicit Array( int arraySize = 1 );
    Array ( const Array &a );
    ~Array();
    size_t getSize() const;

    const Array &operator = ( const Array & );
    bool operator == ( const Array & ) const;

    bool operator != ( const Array &right ) const
    {
        return ! ( *this == right );
    }

    T &operator[] ( int );
    T operator[] ( int ) const;

    friend ostream &operator <<( ostream & output, const Array< T > &a );
    friend istream &operator >>( istream & input, const Array< T > &a );
private :
    size_t size;
    T *ptr;
};

template < class T >
Array< T > ::Array( int arraySize  )
    :size( arraySize > 0 ? arraySize : throw invalid_argument("Array must be greater than 0") ),
     ptr ( new T [size] )
{
    for ( size_t i = 0; i < size; ++i )
        ptr [i] = 0;
}
template < class T >
Array< T >::Array ( const Array &arrayToCopy )
    :size( arrayToCopy.size ),
     ptr ( new T [this->size])
{
    for ( size_t i = 0; i < size; ++i )
    ptr [i] = arrayToCopy.ptr[i];
}

template < class T >
Array< T >::~Array()
{
    delete [] ptr;
}

template < class T >
size_t Array< T >::getSize() const
{
    return size;
}

template < class T >


const Array <T>& Array< T >:: operator = ( const Array & right)
{
    if( &right != this )
    {
        if( size != right.size )
        {
            delete [] ptr;
            size = right.size;
            ptr = new T [size];
        }
    for( size_t i = 0; i < size; ++i )
        this->ptr[i] =  right.ptr[i];
    }
    return * this;
}

template < class T >
bool Array < T >::operator ==( const Array &right ) const
{
    if( size != right.size )
        return false;

    for( size_t i = 0; i < size; i++ )
        if( ptr[i] != right.ptr[i] )
            return false;

    return true;
}


template < class T >
T &Array< T > ::operator []( int subcript )
{
    if( subcript < 0 || subcript >= size )
        throw out_of_range( "Subscript out of range" );

    return ptr[ subcript ];
}


template < class T >
T Array< T > ::operator []( int subcript ) const
{
    if( subcript < 0 || subcript >= size )
        throw out_of_range( "Subscript out of range" );

    return ptr[ subcript ];
}

template < class T >
istream &operator >>( istream & input, const Array< T > &a )
{
    for ( size_t i = 0; i < a.size; i++ )
        input >> a.ptr[i];

    return input;
}

template < class T >
ostream &operator <<( ostream & output, const Array< T > &a )
{
    for( size_t i = 0; i< a.size; i++ )
    {
        output << setw(12) << a.ptr[i];

        if( (i+1) % 4 == 0 )
            output << endl;
    }

    if( a.size % 4 != 0 )
        output << endl;
    return output;
}


#endif // ARRAY_H
