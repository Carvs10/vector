
/*

* TAD: Container Sequencial (aka sequencia, lista)
*
*OPERAÇÕES DESEJÁVEIS
* 0) Criar uma lista de qualquer tipo
* 1) Inserir um elemento em uma posição qualquer
*	1.1) Inserir uma sequência de elementos em uma posição específica
* 2) Remover um elemento em uma posição
*	2.1)Remover uma sequência de elementos da lista, indicados por um range
* 3) Sobrescrever/alterar um elemento nem uma psoição específica
* 4) Recuperar o tamanho do container
* 5) Recuperar o 1º e o último elemento
* 6) Preencher a lista/container com um valor específico
*/


#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include <cstdlib> //size_t
#include<exception>
#include<algorithm>
#include <initializer_list>


namespace sc {


	template< typename T, size_t SIZE>
	class array {

	public:
		class iterator
		{
			public:
				typedef T& reference;
				typedef size_t size_type;
				typedef T* pointer;
				typedef std::ptrdiff_t difference_type;
				typedef std::bidirectinonal_iterator_tag iterator_category;

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

				difference_type operator-( const )
				

		};

		class const_iterator
		{

		};

	public:
		typedef T& reference;
		typedef size_t size_type;
		typedef T* pointer;


	private:
		T data[SIZE]; //!< Área de armazenamento dos dados

		//===Private area

	public:

		//==== Membros especiais

		//Construtor default
		array()
		{/*empty */}

		~array()
		{/* empty*/}

		array& operator=(const array& rhs)
		{

			//Determinar o menor tamanho
			auto limit = std::min(rhs.SIZE, SIZE );
			//copiar os dados de rhs para o 
			std::copy( data, data+limit, rhs.data)

			return *this;
		}

		//Construtor cópia
		array( const array& clone )
		{
			//determinar o menor tamanho
			//não gerar segm. fault
			auto limit = std::min( clone.SIZE, SIZE );
			for( auto i(0u); i < limit ; ++i){
				data[i] = clone.data[i];
			}

	
		}

		//constroi um objeto a partir de uma lista de dados;
		array( std::initializer_list<T> ilist)
		{
			auto limit = std::min( ilist.size(), SIZE );

			for( auto i(0u); i < limit; ++i){
				data[i] = ilist[i];
			}
		}


		//Recupera/conculta um elem na posição 'pos'
		T operator[]( int pos )const
		{
			return data[ pos ];
		}

		reference operator[]( size_type pos )
		{
			return data[ pos ];
		}

		///Insere um elemento 'value' na posição 'pos', sem verificar os limites
		void insert( size_t pos, const T &value)
		{
			data[ pos ] = value;
		}

		///Insere um elemento 'value' na posição 'pos', verificando os limites
		/*!
		* @throw gera exceção
		*/
		void at( size_t pos, const T& value)
		{
			if( pos >= SIZE)
				throw std::invalid_argument( "[array::at()] Posição Invalida, além dos limites do array.")
				
			

			data[ pos ] = value;
		}
		//Retorna o yamanho do array(numero de elementos)

		size() const
		{
			return SIZE;
		}

		//Preenche **todo** o array com o valor especificado.

		void fill(const T& value) 
		{
			//Percorre e preencher.

			for ( T& e : data )
				e = value;
			
		}

		//Recupera o valor do array na posição solicitada
		/*! Utilizada do lado esquerdo de uma atribuição
		* x = array.at( pos );
		*/
		T at( size_t pos ) const
		{
			if( pos >= SIZE)
				throw std::invalid_argument( "[array::at()] Posição Invalida, além dos limites do array.")

			return data[ pos ];
			
		}

		T& at( size_t pos )
		{

			if( pos >= SIZE)
				throw std::invalid_argument( "[array::at()] Posição Invalida, além dos limites do array.")
			

			return data[ pos ];
		}

		T front(void) const
		{
			return *begin();
			return data[0];
		}

		T back(void) const
		{
			return *--end();
			return data[SIZE-1];
		}

		iterator begin(void)
		{
			return iterator( &data[0] );
		}
		iterator end(void)
		{
			return iterator( &data[SIZE] );
		}



	};

	template<typename T size_t SIZE >
	std::ostream& operator<<( std::ostream& os, const array&<T, SIZE> A )
	{
		os << "[ ";
		for( auto i(0u); i < SIZE; ++i ){
			os << A[i] << " ";
		}
		os << "]";

		return os;

	}
}



#endif