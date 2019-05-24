#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib> //size_t
#include <string>
#include <exception>
#include <algorithm>
#include <initializer_list>


namespace sc{


	template < typename T >
	class vector{

		

		public:

			
			class iterator
			{
				public:
					typedef T& reference;
					typedef std::size_t size_type;
					typedef T* pointer;
					typedef std::ptrdiff_t difference_type;
					//typedef std::bidirectinonal_iterator_tag iterator_category;

				//== Private data	
				private:
					T *ptr;

				public:
					iterator( T* pt = nullptr ) : ptr (pt)
					{/* empty */}

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
						///Primeiro modo;
						//++ptr;
						//return *this;


						//Retrona um novo iterador que aponta para o próximo endereço
						//Segundo modo
						return iterator( ++ptr );
					}


						///it++ pos incremento
					iterator operator++(int)
					{
						iterator temp( ptr );// Cria um iterator temporário
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
						iterator temp( ptr );// Cria um iterator temporário
						ptr--;
						return temp;
					}



						/// Comparação ==
					bool operator==( const iterator &it) const
					{ return this->ptr == it.ptr; } //devem retornar o mesmo endereço

						/// Comparação !=
					bool operator!=( const iterator &it) const
					{ return this->ptr != it.ptr;}

					
				

		};
			//class const_iterator{
			//};

			using size_type = unsigned long;
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_reference = const value_type&;
			//using iterator = iterator < T >;             //using iterator = MyIterator < T >;
			//using const_iterator = iterator < const T >  //using const_iterator = MyIterator < const T >
	
		private:
			T * data;
			std::size_t size; //!< número de elemnetos no vector
			std::size_t capacity; //!< Capacidade máxima (atual) do vector

		public:
			

			///==> Special Members
			///Constructor: build a new vector.
			vector( ) :
				data { new T[ 0] },
				size { 0},
				capacity { 0 }

			{/* Initialize the vector with null values */std::cout << "contruu 1\n";}

			///Destructor:
			~vector()
				//delete [] data;
			{/* Desturct the data in the vector*/
			delete [] data;	std::cout << "destruiu 1\n";
			}

			//construindo o vetor com elementos ja escolhidos
			vector( std::initializer_list<T> ilist )
			{
				data = new T[ ilist.size()];
				int i;
				for( const T& e : ilist){

					data[i] = e;
					i++;
				}

				
				std::cout << "construiu 4\n";
			}

			explicit vector( size_type count ):
				size{ count },
				capacity{ count }
			{
				data = new T[ count ];
				std::cout << "construiu 2\n";
			}

			template < typename InpultIt >
			vector ( InpultIt first, InpultIt last)
			{
				data = new T[ last - first ];
				//while(first < last){
					//first++;
				//}
				std::cout << "construiu 3\n";
			}

			vector( const vector& other)
			{	
				std::cout << "construiu 5\n";
				data = new T[ other.capacity ];
			}
			
			/*vector& operator=( const vector& other)
			{}

			vector& operator=( std::initializer_list<T> ilist )
			{}
			///===
			size_type size() const
			{}

			void clear()
			{}

			bool empty()
			{}

			void push_front( const T & value )
			{}

			void push_back( const T & value )
			{}

			void pop_front()
			{}

			void pop_back()
			{}

			const T & back() const
			{}

			const T & front() const
			{}

			void assign ( size_type count, const T & value )
			{}

			T & operator[] ( size_type pos );

			T & at ( size_type pos );

			size_type capacity() const;

			void reserve ( size_type new_cap);

			capacity();

			shrink_to_fit();

			bool operator==( const vector& lhs, const vector& rhs);

			bool operator!=( const vector& lhs, const vector& rhs);



		*/
		
	};
}

#endif