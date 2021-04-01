#include <iostream>
#include <cstdlib>
#include <memory>
#include <exception>

class A {
private:
    const char* name;
public:

    A(const char*value) : name(value) {
        std::cout << name << std::endl;
        std::cout << "I'm alive!" << std::endl;
    };

    virtual ~A() {
        std::cout << "I'm die: " << name << std::endl;
    }
};

int foofoofoo(){
    std::cout << "foofoofoo()" << std::endl;
    throw std::exception();
}

void foo(std::shared_ptr<A>,int){
  std::cout << "foo()" << std::endl;  
}

void foo(int,std::shared_ptr<A>){
  std::cout << "foo()" << std::endl;  
}

int main(int argc, char** argv) {

    try{
        
    //*

    //auto ptr= new A("A");
    //foo(std::shared_ptr<A>(ptr),foofoofoo());
    //foo(foofoofoo(),std::shared_ptr<A>(ptr));

    //foo(foofoofoo(),std::shared_ptr<A>(new A("A")));    
    foo(std::shared_ptr<A>(new A("B")),foofoofoo());
    
    //*/
    
    }catch(...){
        std::cout<< "Catch" << std::endl;
    }
    
    return 0;
}

