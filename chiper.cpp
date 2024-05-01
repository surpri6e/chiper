#include "chiper.h"

const auto chiperMessage = []() -> void {
	system( "cls" );

	std::string* enteredMessage = new std::string( "" );
	std::string* chiperedMessage = new std::string( "" );

	std::cout << "Enter your message: ";
	getline( std::cin, *enteredMessage );

	const std::size_t* const enteredMessageSize = new std::size_t( enteredMessage->length() );

	for (std::size_t i = 0; i < *enteredMessageSize; i++) {
		int* symbol = new int( (*enteredMessage)[i] );

		*chiperedMessage += std::to_string( *symbol );

		if (!(i == *enteredMessageSize - 1)) chiperedMessage->push_back( '_' );

		delete symbol;
	}

	delete enteredMessageSize;

	std::cout << "Chipered message: " << *chiperedMessage << std::endl;

	delete enteredMessage;
	delete chiperedMessage;

	_getch();
};

const auto unchiperMessage = []() -> void {
	system( "cls" );

	std::string* chiperedMessage = new std::string( "" );
	std::string* unchiperedMessage = new std::string( "" );

	std::cout << "IF YOU DON'T KNOW A CHIPER IT WILL BE A ERROR!!!" << std::endl;
	std::cout << "Enter your chipered message: ";
	getline( std::cin, *chiperedMessage );

	std::string* delimiter = new std::string("_");
	std::size_t* pos = new std::size_t(0);

	std::string* token = new std::string("");

	std::vector<std::string>* symbols = new std::vector<std::string>({});

	while ((*pos = chiperedMessage->find( *delimiter )) != std::string::npos) {
		*token = chiperedMessage->substr( 0, *pos );

		symbols->push_back( *token );

		chiperedMessage->erase( 0, *pos + delimiter->length() );
	}

	symbols->push_back( *chiperedMessage );

	delete delimiter;
	delete pos;
	delete token;

	for (std::size_t i = 0; i < symbols->size(); i++) {
		unchiperedMessage->push_back(static_cast<char>(std::stoi((*symbols)[i])));
	}

	delete symbols;

	std::cout << "Unchipered message: " << *unchiperedMessage << std::endl;

	delete chiperedMessage;
	delete unchiperedMessage;

	_getch();
};


int main() {
	
	std::cout << "[c]hiper or [u]nchiper message: ";
	int* command = new int(_getch());
	
	if (static_cast<char>(*command) == 'c') chiperMessage(); 
	if (static_cast<char>(*command) == 'u') unchiperMessage();
	if (!(static_cast<char>(*command) == 'c') && !(static_cast<char>(*command) == 'u')) exit( 505 );

	delete command;
	
	return 0;
}
