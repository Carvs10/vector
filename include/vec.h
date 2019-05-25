/*!
 * \ File vec.h
 * \ Implemetation of class vector
 * \ Authors João Victtor and Pedro Henrique
 */


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream> //cout, endl
#include <cstdlib> //size_t
#include <string>
#include <exception>
#include <algorithm> //std::copy
#include <initializer_list> //ilist
#include <bitset>//make shift oparations
#include <stdexcept> //std::out of range

namespace sc{
	
	//! Class Vector
	/*!
	   Contains the methods
	*/

	template < typename T >
	class vector{

		public:
			//!
			 /*! Public data 
			 */
			
			//!
			 /*! Iterator Class
			 	Used together with vector
			 */

			class iterator
			{
				public:

					typedef T& reference;
					typedef std::size_t size_type;
					typedef T* pointer;
					typedef std::ptrdiff_t difference_type;
					

				//! Private data	
				private:
					T *ptr; /**<Pointer to data. */

				public:

					//==> contructor
					iterator(T* pt)
						:ptr{pt}
					{/*empty*/}

					//=== Destructor
					~iterator()
					{/*empty*/}

					iterator& operator=( const iterator& rhs )
					{

						ptr = rhs.ptr;

						return *this;
					}


					T& operator*(void)
					{

						return *ptr;
					}

					const T& operator*(void) const
					{

						return *ptr;
					}


					/// ++it pré incremento
					iterator operator++(void)
					{
						
						//Returns a new iterator pointing to the next.
						return iterator( ++ptr );
					}


						///it++ pos incremento
					iterator operator++(int)
					{
						iterator temp( ptr );// Creats a temporary iterator
						ptr++;
						return temp;

					}


						/// pré decremento
					iterator operator--(void)
					{
						return iterator (--ptr);
					}


						/// pós decremento
					iterator operator--(int)
					{
						iterator temp( ptr );// Creats a temporary iterator
						ptr--;
						return temp;
					}



						/// Comparsion ==
					bool operator==( const iterator &it) const
					{ return this->ptr == it.ptr; } //Must return same address

						/// Comparsion !=
					bool operator!=( const iterator &it) const
					{ return this->ptr != it.ptr;}

					
				

		};
		
		//! Class Const_iterator

		class c_iterator
			{
				public:

					typedef T& reference;
					typedef std::size_t size_type;
					typedef T* pointer;
					typedef std::ptrdiff_t difference_type;
					

				//! Private data	
				private:
					T *ptr; /**<Pointer to data. */

				public:

					//==> contructor
					c_iterator(T* pt)
						:ptr{pt}
					{/*empty*/}

					//=== Destructor
					~c_iterator()
					{/*empty*/}

					const iterator& operator=( const iterator& rhs )
					{

						ptr = rhs.ptr;

						return *this;
					}


					const T& operator*(void)
					{

						return *ptr;
					}

					const T& operator*(void) const
					{

						return *ptr;
					}


					/// ++it pré incremento
					const iterator operator++(void)
					{
						
						return iterator( ++ptr );
					}


						///it++ pos incremento
					const iterator operator++(int)
					{
						iterator temp( ptr );// Creats a temporary iterator
						ptr++;
						return temp;

					}


						/// pré decremento
					const iterator operator--(void)
					{
						return iterator (--ptr);
					}


						/// pós decremento
					const iterator operator--(int)
					{
						iterator temp( ptr );// Creats a temporary iterator
						ptr--;
						return temp;
					}



						/// Comparsion ==
					const bool operator==( const iterator &it) const
					{ return this->ptr == it.ptr; } //must return same address

						/// Comparsion !=
					const bool operator!=( const iterator &it) const
					{ return this->ptr != it.ptr;}

					
				

		};



			using size_type = unsigned long;
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_reference = const value_type&;
	
		private:
			T * data;
			std::size_t SIZE; //!< Number of elements in vector
			std::size_t CAPACITY; //!< Maximum capacity in vector

		public:
			

			//! Special Members
			 /* 
			 * 
			 /*!Constructor: build a new vector.//1
			 */
			vector( ) :
				data { new T[ 0] },
				SIZE { 0},
				CAPACITY { 0 }

			{/* Initialize the vector with null values */}

			//!
			 /*! Destructor: delete the vector exiting
			 */
			~vector()
				
			{/* Desturct the data in the vector*/
			delete [] data;
			}

			//!
			 /*! Construc the vector with selectec elements//4
			 */
			vector( std::initializer_list<T> ilist ):
				SIZE{ ilist.size() },
				CAPACITY{ ilist.size() }
			{
				data = new T[ CAPACITY ];
				int i;
				for( const T& e : ilist){

					data[i] = e;
					i++;
				}

			}
			
			//!
			 /*! Constructs the list with count default-inserted instances of T .
			 */
			explicit vector( size_type count )://2
				SIZE{ 0 },
				CAPACITY{ count }
			{
				data = new T[ count ];
				
			}

			//!
			 /*! Constructs the list with the contents of the range [first, last).
			 */
			template < typename InpultIt >
			vector ( InpultIt first, InpultIt last):
			SIZE{ (size_type)(last - first) },
			CAPACITY{ (size_type)(last - first) }
			{
				data = new T[ CAPACITY ];

				for(int i = 0; i < SIZE; i++){
					data[i] = *first ;
					
					first++;
				}
				
				
			}

			//!
			 /*! Copy constructor. 
			 /*! Constructs the list with the deep copy of the contents of other.
			 */
			vector( const vector& other):
				SIZE{ other.SIZE },
				CAPACITY{ other.CAPACITY }
			{	
				
				data = new T[ CAPACITY ];

				std::copy( &other.data[0], &other.data[SIZE], data );

			}
			//!
			 /*! Copy assignment operator.
			 /*! Replaces the contents with a copy of the contents of other.
			 */
			vector& operator=( const vector& other)
				//size{ other.size },
				//capacity{ other.CAPACITY }
			{
				
				data = new T[ other.SIZE ];
				
				std::copy( data, other.SIZE, other.data);

				return *this;	
			}

			//!
			 /*! Replaces the contents with those identified by initializer list ilist
			 */
			vector& operator=( std::initializer_list<T> ilist )
			{
				data = new T[ ilist.SIZE ];
				
				std::copy( data, ilist.SIZE, ilist.data);

				return *this;
			}


			//!Capacity methods:

			

			//!
			 /*! Return the number of elements in the container
			 */
			size_type size() const
			{
				return SIZE;//(size_type)(size);
			}

			//!
			 /*! Returns true if the container contains no elements, and false otherwise
			 */
			bool empty()
			{
				if(SIZE == 0){
					return true;
				}
				else{
					return false;
				}
			}

			//!
			 /*! Return the internal storage capacity of the array
			 */
			size_type capacity() const
			{
				return CAPACITY;
			}

			//! Modifiers methods:
			
			//!
			 /*! Remove (either logically or physically) all elements from the container
			 */
			void clear()
			{	
				//data[]
				SIZE = 0 ;
			}
			
			//!
			 /*! Adds value to the end of the list
			 */
			void push_back( const T & value )
			{
				// Verificar se tem espaço para receber o novo elemento.
            	if ( SIZE == CAPACITY )
            	{
                	reserve( ( CAPACITY == 0 ) ? 1 : (2 * CAPACITY) );
            	}

           		 data[SIZE++] = value;
			}
			//!
			 /*! Adds value to the front of the list
			 */
			void push_front( const T & value )
			{
				// Verificar se tem espaço para receber o novo elemento.
            	if ( SIZE == CAPACITY )
            	{
                	reserve( ( CAPACITY == 0 ) ? 1 : (2 * CAPACITY) );
            	}
            	SIZE++;

            	for(int i = SIZE; i > 0; i--){

            		data[i] = data[i-1];
            	}

            	data[0] = value;

           		//data[SIZE++] = value;
            	//*begin() = value;
			}

			//!
			 /*! Removes the object at the end of the list.
			 */
			void pop_back()
			{
				SIZE--;
			}

			//!
			 /*! Removes the object at the front of the list.
			 */
			void pop_front()
			{
				SIZE--;

				for(int i = 0; i < SIZE; i++){

            		data[i] = data[i+1];
            	}
			}

			
			//!
			 /*! Returns the object at the end of the list
			 */
			const T & back() const
			{
				return data[SIZE];
			}

			//!
			 /*! Returns the object at the front of the list
			 */
			const T & front() const
			{
				return data[0];
			}
			
			//!
			 /*! eplaces the content of the list with count copies of value.
			 */
			void assign ( size_type count, const T & value )
			{
				SIZE = count;

				for(int i = 0; i< SIZE; i++){
					data[i] = value;
				}
			}
			
			//!
			 /*! Returns the object at the index pos in the array,with no bounds-checking
			 */
			T & operator[] ( size_type pos )
			{
				return data[ pos ];
			}

			//!
			 /*! Returns the object at the index pos in the array,with bounds-checking
			 */
			T & at ( size_type pos )
			{
				if (SIZE < pos){
					throw std::out_of_range("ERRO --> posição invalida!!!");
				}
				else{
					return data[ pos ];
				}
			}
			
			//!
			 /*! Requests the removal of unused capacity.
			 /*! It is a non-binding request to reduce capacity() to size().
			 */
			void shrink_to_fit()			
			{
				CAPACITY = SIZE;
			}
			
			//!
			 /*! Return false if the arrays have different elements
			 */
			friend bool operator== ( const vector& lhs, const vector& rhs)
			{
				if(lhs.size() == rhs.size()){

					for(int i = 0; i < lhs.size(); i++){
						if(lhs[i] != rhs[i]){
							return false;
						}
					}
					return true;
				}
				else{
					return false;
				}
			}
			
			//!
			 /*! Return false if the arrays are equal.
			 */
			friend bool operator!= ( const vector& lhs, const vector& rhs)
			{
				if(lhs.size() == rhs.size()){

					for(int i = 0; i < lhs.size(); i++){
						if(lhs[i] != rhs[i]){
							return true;
						}
					}
					return false;
				}
				else{
					return true;
				}
			}
		

			//!Private Data from Vector
		

			//! 
			 /*! Changes capacity to 'new_cap'.
			 */
        	void reserve( size_t new_cap )
        	{
            	
            	if ( new_cap <= CAPACITY ) return;

            	T * temp = new T[ new_cap ];
            	std::copy( &data[0], &data[SIZE],  temp );

            	delete[] data;

            	data = temp;
            	CAPACITY = new_cap;
        	}


        	//! Iterator Methods

			//!Returns an iterator pointing to the first item in the list.
        	iterator begin()
        	{
        		iterator it(&data[0]);

        		return it;
        	}

			//!Returns an iterator pointing to the i.e the position after the last item in the list. 
        	iterator end()
        	{
        		iterator it(&data[SIZE]);
        		
        		return it;
        	}

			//!Returns a const iterator pointing to the first item in the list
        	c_iterator cbegin() const
        	{
        		c_iterator it(&data[0]);

        		return it;
        	}

			//!Returns a const iterator pointing to the i.e positon just after the last item in the list
        	c_iterator cend() const
        	{
        		c_iterator it(&data[0]);

        		return it;
        	}
			
			//!Insert the value before the pos required and return the position
        	iterator insert( iterator pos, const T & value)
        	{

        		if ( SIZE == CAPACITY )
            	{
                	
                	reserve( ( CAPACITY == 0 ) ? 1 : (2 * CAPACITY) );
            	}

            	size_type aux = SIZE - pos;
            	SIZE++;

        		for(int i = SIZE; i > aux; i--){

            		data[i] = data[i-1];
            	}

            	data[0] = value;

        	}

			//!Erase the element at pos required.
        	iterator erase( iterator pos )
			{
				size_type aux = pos - data;

				for( size_type i{aux} ; i < SIZE ; i++ )
				{
					data[i-1] = data[i];
				}

				SIZE--;

				return my_iterator( &data[aux-1] );
			}

	};
}

#endif