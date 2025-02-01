/**
 *Exercise: Implement a class using std::unique_ptr

🎯 Objective Create a Manager class that manages a resource with std::unique_ptr.

📌 Constraints:

The resource must not be copyable

Implement a constructor, a destructor, and a use() function

Display the messages Acquiring resource... and Releasing resource...
 *
 *
 * */

#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Acquiring resource...\n"; }
    ~Resource() { std::cout << "Releasing resource...\n"; }
    void use() { std::cout << "Using resource\n"; }
};

class Manager {
private:
    std::unique_ptr<Resource> resource;

public:
    // TODO: Implémenter le constructeur qui initialise resource
    Manager() {
    	resource = std::make_unique<Resource>();
	std::cout<<"Initialising the resource"<<std::endl;
    }

    ~Manager() {
	    std::cout<<"Resource destroyed"<<std::endl;
    }

    void use() {
    	resource->use();
    }
    //Prevent the copy by cpy ctr
    Manager(const Manager&)=delete;
    //Prevent the copy by affectation
    Manager& operator=(const Manager&) = delete;
	    
};

int main() {
    Manager mgr;
    mgr.use();
    //Manager mgr2 = mgr;
    //Manager mgr3(mgr);
    return 0;
}

