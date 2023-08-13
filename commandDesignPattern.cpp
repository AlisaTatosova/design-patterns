#include <iostream>
#include <vector>

class Character {
  public:
    Character() : x{0}, y{0}, z{0} {}
    void move(int _x, int _y){
      x = _x;
      y = _y;
    }
    void jump(int height) {
      z = height;
    }
  private:
    int x;
    int y;
    int z;
};

class Command {
  public:
    virtual ~Command(){}
    virtual void execute(Character& c) = 0;
};


class Jump : public Command {
  public:
    void execute(Character& c) override  {
      int height = rand() % 5;
      c.jump(height);
      std::cout << "Character jumped " << std::endl;
    }   
  private:
    int _x;
    int _y;
    int _z;
};


class Move : public Command {
  public:
    void execute(Character& c) override {
      int x = rand() % 5; 
      int y = rand() % 5; 
      c.move(x, y);
      _x = x;
      _y = y;
      std::cout << "Character moved " << _x << ", " << _y << std::endl;
    }
  private:
    int _x;
    int _y;
    int _z;
};

int main(){
  Character c;
  std::vector<Command*> commands;
  Move* m1 = new Move;
  commands.push_back(m1);
  Jump* j1 = new Jump;
  commands.push_back(j1);
  Move* m2 = new Move;
  commands.push_back(m2);

  for (int i = 0; i < commands.size(); i++){
    commands[i] -> execute(c); 
  }

  for(int i = 0; i < commands.size(); i++){
    delete commands[i];
  }

  return 0;
}