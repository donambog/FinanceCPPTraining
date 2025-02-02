#include <iostream>
#include <memory>
#include <cstdio>  // Pour FILE*

int main() {
    // Crée un unique_ptr qui gère un fichier
    std::unique_ptr<FILE, decltype(&fclose)> filePtr(fopen("test.txt", "w"), &fclose);

    if (!filePtr) {
        std::cerr << "Erreur lors de l'ouverture du fichier\n";
        return 1;
    }

    std::cout << "Fichier ouvert avec succès\n";
    fprintf(filePtr.get(), "Hello, world!\n");

    return 0; // fclose sera appelé automatiquement ici
}

