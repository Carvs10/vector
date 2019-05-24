#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib> //size_t
#include <string>
#include <exception>
#include <algorithm>//std::copy
#include <initializer_list>
#include <bitset>//make shift oparations
#include <stdexcept> //std::out of range

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


			//======================> Capacity methods:
			
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

			//=====================> Modifiers methods:
			
			void clear()
			{	
				//data[]
				SIZE = 0 ;
			}

			void push_back( const T & value )
			{
				// Verificar se tem espaço para receber o novo elemento.
            	if ( SIZE == CAPACITY )
            	{
                	std::cout << "[push_back] : capacity = " << CAPACITY << ", estou dobrando...\n";
                	reserve( ( CAPACITY == 0 ) ? 1 : (2 * CAPACITY) );//FALTA ENTENDER ESSA LINHA DE CODIGO
            	}

            	// Inserir normalmente.
           		 data[SIZE++] = value;
            	//*begin() = value;
			}
			
			void push_front( const T & value )
			{
				// Verificar se tem espaço para receber o novo elemento.
            	if ( SIZE == CAPACITY )
            	{
                	std::cout << "[push_front] : capacity = " << CAPACITY << ", estou dobrando...\n";
                	reserve( ( CAPACITY == 0 ) ? 1 : (2 * CAPACITY) );//FALTA ENTENDER ESSA LINHA DE CODIGO
            	}
            	SIZE++;
            	//transferir um bloco de memoria para o lado

            	for(int i = SIZE; i > 0; i--){

            		data[i] = data[i-1];
            	}

            	data[0] = value;

           		//data[SIZE++] = value;
            	//*begin() = value;
			}
	
			void pop_back()
			{
				SIZE--;
			}
			
			void pop_front()
			{
				SIZE--;

				for(int i = 0; i < SIZE; i++){

            		data[i] = data[i+1];
            	}
			}

			

			const T & back() const//retorna o objeto do final da lista
			{
				return data[SIZE];
			}

			const T & front() const//retorna o objeto do inicio da lista
			{
				return data[0];
			}
			
			void assign ( size_type count, const T & value )//coloca o valor em todos os elementos do vetor antigo  de forma contada //testar
			{
				SIZE = count;

				for(int i = 0; i< SIZE; i++){
					data[i] = value;
				}
			}
			
			T & operator[] ( size_type pos )//libera a operação de incerção por barras
			{
				return data[ pos ];
			}

			T & at ( size_type pos )//retorna o objeto dentro do index dado caso o index seja valido// testar
			{
				if (SIZE < pos){
					//std::out_of_range;
				}
				else{
					return data[ pos ];
				}
			}

			

			

			

			void shrink_to_fit()//iguala a capacidade ao tamanho!
			{
				CAPACITY = SIZE;
			}
			
			
			friend bool operator== ( const vector& lhs, const vector& rhs)//nao ta funcionando direito
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

			friend bool operator!= ( const vector& lhs, const vector& rhs)//não ta funcionando direito
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
		private:
				/// Aumenta a capacidade de armazenamento do vector para o valor `new_cap` fornecido.
        	void reserve( size_t new_cap )
        	{
            	// Se a capacidade nova < capacidade atual, não faço nada.
            	if ( new_cap <= CAPACITY ) return;

            	// Passo 1: alocar nova memória com tamanho solicitado.
            	T * temp = new T[ new_cap ];

            	// Passo 2: copiar os dados da memória antiga para a nova.
            	std::copy( &data[0], &data[SIZE],  temp );
            	//std::copy( begin(), end(), temp );

            	// Passo 3: Liberar a memória antiga.
            	delete[] data;

            	// Passo 4: Redirecionar ponteiro para a nova (maior) memória.
            	data = temp;

            	// Passo 5: Atualizações internas.
            	CAPACITY = new_cap;
        }
	};
}

#endif