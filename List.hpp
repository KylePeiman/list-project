#include <iostream>
#include <initializer_list>

using namespace std;

///////////////////CONST_ITERATOR////////////////////////////

template <typename T>
List<T>::const_iterator::const_iterator( ) : current( nullptr )
{ }

template <typename T>
const T & List<T>::const_iterator::operator*( ) const
{ return retrieve(); }

template <typename T>
typename cop4530::List<T>::const_iterator & List<T>::const_iterator::operator++( )	//prefix
{
	current = current -> next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::const_iterator List<T>::const_iterator::operator++(int) //postfix
{
	const_iterator old = *this;
	++( *this );
	return old;
}

template <typename T>
typename cop4530::List<T>::const_iterator & List<T>::const_iterator::operator--( )
{
	current = current -> prev;
	return *this;
}

template <typename T>
typename cop4530::List<T>::const_iterator List<T>::const_iterator::operator--( int )
{
	const_iterator old = * this;
	--( *this );
	return old;
}

template <typename T>
bool List<T>::const_iterator::operator==( const const_iterator & rhs ) const
{
	return current == rhs.current;
}

template <typename T>
bool List<T>::const_iterator::operator!=( const const_iterator & rhs ) const
{
	return !( *this == rhs );
}

template <typename T>
T & List<T>::const_iterator::retrieve( )const
{
	return current -> data;
}

template <typename T>
List<T>::const_iterator::const_iterator( Node *p) : current{p}
{}

/////////////////////////ITERATOR/////////////////////////////////

template <typename T>
List<T>::iterator::iterator()
{}

template <typename T>
T & List<T>::iterator::operator*( )
{
	return const_iterator::retrieve( );
}

template <typename T>
const T & List<T>::iterator::operator*( ) const
{
	return const_iterator::operator*( );
}

template<typename T>
typename cop4530::List<T>::iterator & List<T>::iterator::operator++( )
{
	this -> current = this -> current -> next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::iterator List<T>::iterator::operator++( int  )
{
	iterator old = *this;
	++( *this );
	return old;
}

template <typename T>
typename cop4530::List<T>::iterator & List<T>::iterator::operator--( )
{
	this -> current = this -> current -> prev;
	return *this;
}

template <typename T>
typename cop4530::List<T>::iterator List<T>::iterator::operator--( int )
{
	iterator old = *this ;
	--( *this );
	return old;
}

template <typename T>
List<T>::iterator::iterator( Node *p ) : const_iterator{ p }
{}

////////////////////////////////LIST//////////////////////
template <typename T>
List<T>::List( )			//Default constuctor
{ init( ); }

template <typename T>			//move constructor
List<T>::List(List && rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
{
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}

template <typename T>			//move assignment operator
typename cop4530::List<T> & List<T>::operator=( List && rhs )
{
	std::swap( theSize, rhs.theSize );
	std::swap( head, rhs.head );
	std::swap( tail, rhs.tail );
}

template <typename T>
List<T>::List( const List & rhs )	//copy constructor
{
	init( );
	for(auto & x : rhs)
		push_back( x );
}

template <typename T>			//explicit constructor
List<T>::List(int num, const T& val)
{
	init( );
	for(int i = 0; i < num; i++)
		push_back(val);
}

template <typename T>
List<T>::List(const_iterator Start, const_iterator end)
{
	init( );
	for(auto i = Start; i != end; i++)
	{
		push_back(*i);
	}
}

template <typename T>
List<T>::List(std::initializer_list<T> iList)
{
	init( );
	for(auto i = iList.begin( ); i != iList.end( ); i++)
	{
		push_back(*i);
	}
}

template <typename T>
List<T>::~List( )			//Destructor
{
	clear( );
	delete head;
	delete tail;
}


template <typename T>
typename cop4530::List<T> & List<T>::operator=( const List & rhs )	//copy assignment
{
	List copy = rhs;
	std:swap(*this, copy);
	return *this;
}

template <typename T>							//initializer list copy
typename cop4530::List<T> & List<T>::operator=( std::initializer_list<T> iList )
{
	List copy = iList;
	std::swap(*this,copy);
	return *this;
}

//ACCESSORS

template <typename T>
int List<T>::size() const
{
	return theSize;
}

template <typename T>
bool List<T>::empty() const
{

	return size( ) == 0;
}

template <typename T>
void List<T>::clear()
{
	while( !empty( ) )
		pop_front( );
}

////////////FRONT & BACK /////////////////////////
template <typename T>
T & cop4530::List<T>::front()
{
	return *begin( );
}

template <typename T>
const T & cop4530::List<T>::front() const
{
	return *begin( );
}

template <typename T>
T & cop4530::List<T>::back( )
{
	return *--end( );
}

template <typename T>
const T & cop4530::List<T>::back( ) const
{
        return *--end( );
}

///////////////////////PUSH/POP FRONT/BACK///////////////////////
template <typename T>
void cop4530::List<T>::push_front( const T & val )
{
	insert( begin( ), val );
}

template <typename T>
void cop4530::List<T>::push_front( T && val )
{
        insert( begin( ), std::move( val ) );
}

template <typename T>
void cop4530::List<T>::push_back( const T & val )
{
        insert( end( ), val );
}

template <typename T>
void cop4530::List<T>::push_back( T && val )
{
        insert( end( ), std::move( val ) );
}

template <typename T>
void cop4530::List<T>::pop_front( )
{
	erase( begin( ) );
}

template <typename T>
void cop4530::List<T>::pop_back( )
{
	erase( --end( ) );
}

template <typename T>
void List<T>::remove(const T&val)
{
	for(auto i = this->begin( ); i != this->end( ); i++)
	{
		if(*i == val)
		{
			erase(i);
		}
	}
}

template <typename T>
template <typename PREDICATE>
void cop4530::List<T>::remove_if(PREDICATE pred)
{
	iterator itr;
	for(auto i = this->begin( ); i != this->end( ); i++)
		if(pred(*i) == true)
		{
			erase(i);
		}

}

template <typename T>
void cop4530::List<T>::print(std::ostream & os, char ofc) const
{
	for(auto i = this->begin( ); i != this->end( ); i++)
		os << *i << ofc;
}
///////////////////////ITERATOR STUFF////////////////////////////

//BEGIN
template <typename T>
typename cop4530::List<T>::iterator List<T>::begin( )
{
	return iterator( head->next );
}

template <typename T>
typename cop4530::List<T>::const_iterator List<T>::begin( )const
{
	return const_iterator( head->next ); 
}



//END
template <typename T>
typename cop4530::List<T>::iterator List<T>::end( )
{
	return iterator( tail );
}

template <typename T>
typename cop4530::List<T>::const_iterator List<T>::end( ) const
{
	return const_iterator( tail );
}

//INSERT
template <typename T>
typename cop4530::List<T>::iterator List<T>::insert(iterator itr, const T & val)
{
	Node *p = itr.current;
	++theSize;
	return iterator(p -> prev = p -> prev -> next = new Node( val, p -> prev, p));
}

template <typename T>
typename cop4530::List<T>::iterator List<T>::insert(iterator itr, T && val)
{
	Node *p = itr.current;
	++theSize;
	return iterator( p -> prev = p -> prev -> next = new Node( std::move( val ), p -> prev, p) );
}

//ERASE
template <typename T>
typename cop4530::List<T>::iterator List<T>::erase(iterator itr)
{
	Node *p = itr.current;
	iterator retVal( p -> next );
	p -> prev -> next = p -> next;
	p -> next -> prev = p -> prev;
	delete p;
	--theSize;
	return retVal;
}

template <typename T>
typename cop4530::List<T>::iterator List<T>::erase(iterator Start, iterator end)
{
	for(iterator itr = Start; itr != end;)
	itr = erase(itr);

	return end;
}

template <typename T>
void cop4530::List<T>::reverse( )
{
	List temp;
	for(auto i = this->begin( ); i != this->end( ); i++)
	{
		temp.push_front(*i);
	}
	this->clear();
	for(auto i = temp.begin( ); i != temp.end( ); i++)
        {
                this->push_back(*i);
        }

}

template <typename T>
void List<T>::deduplicate( )
{
	for(auto i = this->begin( ); i != this->end( ); i++)
	{
		auto test = *i;
		for(auto j = i; j != this->end( ); j++)
		{
			if(*j == test && j != i)
				erase(j);
		}
	}
}


template <typename T>
void List<T>::init( )
{
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail -> prev = head;
}

/////////FRIEND OVERLOADS////////////////
template <typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
	if(lhs.size() != rhs.size())
		return false;

	for(auto i = lhs.begin( ); i != lhs.end( ); i++)
	{
		for(auto j = rhs.begin( ); j != rhs.end( ); i++)
		{
			if( *j == *i)
				break;
			else
				return false;
		}
	}
	return true;
}

template <typename T>
bool operator!=(const List<T> &lhs, const List<T> &rhs)
{
	return !(lhs == rhs);
}
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
	l.print( os );
	return os;
}


