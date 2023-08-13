#include <iostream>

class Base {
public:
  Base() = default;
  virtual void doSth() = 0;
  virtual ~Base() {} 
};

class Real : public Base {
public:
  Real() {
    std::cout << "Real Ctor\n";
  } 

  void doSth()  override {
    std::cout << "Doing some thing" << std::endl;
  }

  ~Real() {
    std::cout << "Real Dtor\n";
  }
};

class Proxy : public Base {
public:
  Proxy(Real* real) : real(new Real(*real)) {}
   

  void doSth() override {
    if(this -> checkAcces()) {
      this -> real -> doSth();
    }
  }

 ~Proxy() {
   delete real;
 }
  
private:
  Real* real;
  bool checkAcces() const {
    std::cout << "Checking access" << std::endl;
    return true;
  }
};


int main() {
  Real* real = new Real;
  Proxy* proxy = new Proxy(real);
  proxy -> doSth();
  delete real;
  delete proxy;
  return 0;
}