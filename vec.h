#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib> //size_t
#include <string>
#include<exception>
#include<algorithm>
#include <initializer_list>


namespace sc{


	template < typename T, size_t SIZE>
	class vector{

		public:

			/*class iterator{

				public:
										//procurar entender
				typedef T& reference;
				typedef size_t size_type;
				typedef T* pointer;
				typedef std::ptrdiff_t difference_type;
				typedef std::bidirectinonal_iterator_tag iterator_category;

				private:
					T *ptr;

				public:

					//contructors
					iterator( T* pt = nullptr) : ptr(pt){
					}

			}*/
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


			//=====>construtores:

			vector( size_t count )
			{
				data = new T[ count];
			}

		private:
			T * data;
			size_t size; //!< número de elemnetos no vector
			size_t capacity; //!< Capacidae máxima (atual) do vector
	};
}

#endif