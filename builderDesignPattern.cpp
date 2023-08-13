#include <iostream>
#include <string>

class Engine {
  public:
    std::string engineName;
};

class Wing {
  public:
   int length;
};

class Airplane {
  public:
    Engine* engine;
    Wing* wings[2];
    
    void display() {
      std::cout << "Engine name: " << engine -> engineName << std::endl;
      std::cout << "Wings lemgth: " << wings[0] -> length << std::endl;
    }
};

class Builder {
  public:
    virtual Wing* getWing() = 0;
    virtual Engine* getEngine() = 0;
};

class BoeingBuilder : public Builder {
  public:
    Wing* getWing() {
      Wing* wing = new Wing();
      wing -> length = 1500;
      return wing;
    }
    
    Engine* getEngine() {
      Engine* engine = new Engine();
      engine -> engineName = "GE";
      return engine;
    }

};

class MiGBuilder : public Builder {
  public:
    Wing* getWing() {
      Wing* wing = new Wing();
      wing -> length = 1000;
      return wing;
    }

    Engine* getEngine() {
      Engine* engine = new Engine();
      engine -> engineName = "R-11";
      return engine;
    }
};

class Director {
  public:
    void setBuilder(Builder* builder) {
      _builder = builder;
    }

    Airplane* getAirplane() {
      Airplane* airplane = new Airplane();
      airplane -> engine = _builder -> getEngine();
      airplane -> wings[0] = _builder -> getWing();
      airplane -> wings[1] = _builder -> getWing();

      return airplane;
    }
  private:
    Builder* _builder;
};


int main() {
  Airplane* airplane; 
  Director director;
  BoeingBuilder boeingBuilder;
  MiGBuilder migBuilder;
  
  std::cout << "Boeing" << std::endl;
  director.setBuilder(&boeingBuilder);
  airplane = director.getAirplane();
  airplane -> display();
  
  std::cout << "MiG" << std::endl;
  director.setBuilder(&migBuilder); 
  airplane = director.getAirplane();
  airplane -> display();

  delete airplane;
  return 0;
}