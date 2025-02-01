#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void use() { std::cout << "Using resource\n"; }
};

int main() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->use();  // Accès à l’objet

    // res se détruit automatiquement en fin de scope
    return 0;
}

