#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib> //size_t
#include <string>
#include <exception>
#include <algorithm>//std::copy
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
			std::size_t SIZE; //!< número de elemnetos no vector
			std::size_t CAPACITY; //!< Capacidade máxima (atual) do vector

		public:
			

			///==> Special Members
			///Constructor: build a new vector.//1
			vector( ) :
				data { new T[ 0] },
				SIZE { 0},
				CAPACITY { 0 }

			{/* Initialize the vector with null values */std::cout << "contruu 1\n";}

			///Destructor:
			~vector()
				//delete [] data;
			{/* Desturct the data in the vector*/
			delete [] data;	std::cout << "destruiu 1\n";
			}

			//construindo o vetor com elementos ja escolhidos//4
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

				
				std::cout << "construiu 4\n";
			}

			explicit vector( size_type count )://2
				SIZE{ 0 },
				CAPACITY{ count }
			{
				data = new T[ count ];
				std::cout << "construiu 2\n";
			}

			template < typename InpultIt >
			vector ( InpultIt first, InpultIt last)://pego o range e faço um casting do last - first para pegar o size
			SIZE{ (size_type)(last - first) },
			CAPACITY{ (size_type)(last - first) }
			{
				data = new T[ CAPACITY ];

				for(int i = 0; i < SIZE; i++){
					data[i] = *first ;
					//std::cout << first;
					first++;
				}
				//while(first < last){
				//	data[]
					//first++;
				//}
				std::cout << "construiu 3\n";
			}

			vector( const vector& other)://copia o conteudo de um vector para outro
				SIZE{ other.SIZE },
				CAPACITY{ other.CAPACITY }
			{	
				std::cout << "construiu 5\n";
				data = new T[ CAPACITY ];

				std::copy( &other.data[0], &other.data[SIZE], data );

			}
			
			vector& operator=( const vector& other)//===================> PRECISO ENTENDER AINDA!!! AINDA NAO ESTA FUNCCIONANDO
				//size{ other.size },
				//capacity{ other.CAPACITY }
			{
				//Determinar o menor tamanho
				//auto limit = std::min(other.size, size );
				//copiar os dados de rhs para o 
				data = new T[ other.SIZE ];
				std::cout << "construiu 6\n";
				std::copy( data, other.SIZE, other.data);

				return *this;	
			}

			vector& operator=( std::initializer_list<T> ilist )//===================> PRECISO ENTENDER AINDA!!! AINDA NAO ESTA FUNCCIONANDO
			{
				data = new T[ ilist.SIZE ];
				std::cout << "construiu 6\n";
				std::copy( data, ilist.SIZE, ilist.data);

				return *this;
			}


			//=============>Capacity methods
			
			size_type size() const
			{
				return SIZE;//(size_type)(size);
			}

			bool empty()
			{
				if(SIZE == 0){
					return true;
				}
				else{
					return false;
				}
			}

			size_type capacity() const
			{
				return CAPACITY;
			}
			/*
			void clear()
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
			{}*/
			
			T & operator[] ( size_type pos )
			{
				return data[ pos ];
			}

			/*T & at ( size_type pos );

			

			void reserve ( size_type new_cap);

			capacity();

			shrink_to_fit();

			bool operator==( const vector& lhs, const vector& rhs);

			bool operator!=( const vector& lhs, const vector& rhs);



		*/
		
	};
}

#endif