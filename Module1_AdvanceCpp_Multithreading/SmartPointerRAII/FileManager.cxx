#include <iostream>
#include <memory>
#include <cstdio>  // Pour FILE*


/**
 * Create a FileManager class that to manag a file using unique ptr
 * */

class FileManager {
	private : 
		std::unique_ptr<FILE, decltype(&fclose)> filePtr;
	public :
		FileManager(const char* f_name):filePtr(fopen(f_name, "w"), &fclose)
		{
		if (!filePtr) {
        		std::cerr << "Erreur lors de l'ouverture du fichier\n";
    		}	

	}
	~FileManager () {
		std::cout<<"Destruction !!"<<std::endl;
	}
	void write(const char* str) {
		fprintf(filePtr.get(),"%s",str);
	}
};

int main() {
    // Crée un unique_ptr qui gère un fichier
    FileManager fm("French.txt");
    fm.write("Bonjour \n");

    return 0; // fclose sera appelé automatiquement ici
}

