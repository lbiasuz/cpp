#ifndef DATA
#define DATA

#include <string>

typedef long unsigned int uintptr_t;

class Data {
	public:
		Data(void);
		Data(const Data & old);
		~Data();
		Data& operator=(const Data & old);
		std::string getTeste(void);
		void setTeste(std::string);

	private:
		std::string teste;

};

uintptr_t serialize(Data *ptr);
Data* deserialize(uintptr_t raw);

#endif