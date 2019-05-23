#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib> //size_t
#include <string>
#include<exception>
#include<algorithm>
#include <initializer_list>


namespace sc{


	template < typename T>
	class vector{

		public:

			
			class iterator
			{
				public:
					typedef T& reference;
					typedef size_t size_type;
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

					//difference_type operator-( const )
				

		};
			//class const_iterator{
			//};

			///==> Special Members
			///Constructor:
			vector()
			{/*empty */
			std::cout << "contruiu 1\n";}

			///Destructor:
			~vector()
			{/* empty*/	std::cout << "destruiu 1\n";}

			vector( std::initializer_list<T> ilist )
			{
				//data = new T[ count];
				std::cout << "to aqui 1\n";
			}

			vector( size_t count )
			{
				data = new T[ count ];
				std::cout << "to aqui 1\n";
			}

			/*explicit vector( size_type count)
			{}

			template < typename InpultIt >
			vector ( InpultIt first, InputIt last)
			{}

			vector( const vector& other)
			{}
			
			vector& operator=( const vector& other)
			{}

			vector& operator=( std::initializer_list<T> ilist )
			{}

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

		*/
		private:
			T * data;
			size_t size; //!< número de elemnetos no vector
			size_t capacity; //!< Capacidade máxima (atual) do vector
	};
}

#endif