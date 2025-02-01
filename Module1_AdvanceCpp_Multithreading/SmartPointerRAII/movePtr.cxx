#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Acquiring resource...\n"; }
    ~Resource() { std::cout << "Releasing resource...\n"; }
    void use() { std::cout << "Using resource\n"; }
};

int main() {
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>(); 
    std::cout << "ptr1 possède la ressource\n";

    // Transfert de la propriété avec std::move
    std::unique_ptr<Resource> ptr2 = std::move(ptr1);

    if (ptr1==nullptr) {
        std::cout << "ptr1 ne possède plus la ressource\n";
    }
    if (ptr2) {
        std::cout << "ptr2 a pris la propriété de la ressource\n";
        ptr2->use();
    }

    return 0;
}

