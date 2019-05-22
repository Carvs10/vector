#include <iostream>
#include <string>

//aula de matheus
template << typename

class sala{
	
	public:
		sala( int num_pessoas=0, std::string professor="sem_nome"){
		
		this->num_pessoas= num_pessoas;
		this->professor = professor;
		std::cout<< "construtor\n";
		}

		~sala(){
		std::cout<<"entrei no destrutor\n"
		}

		int pegarnumpessoas();

	private:
		int num_pessoas;
		std::string  professor;
};
int main(){
	sala a212;
	sala a305(10, "ivan");

	std::cout << a305.pegarnumpessoas() << std::endl;
}

int sala::pegarnumpessoas(){
	AFAFASFAFASFA
}


//projeto preferencias
using size_type = unsigned long

//oparators
//metodos