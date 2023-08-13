#include <iostream>

class Button {
  public:
    virtual void press() = 0;
};

class MacButton : public Button {
  public:
    void press() {
      std::cout << "Mac button is pressed\n"; 
    }
};

class WinButton : public Button {
  public:
    void press() {
      std::cout << "Windows button is pressed\n"; 
    }
};

class Menu {
  public:
    virtual void openMenu() = 0;
};

class MacMenu : public Menu {
  public:
    void openMenu() {
      std::cout << "Mac Menu is opened\n"; 
    }
};

class WinMenu : public Menu {
  public:
    void openMenu() {
      std::cout << "Windows Menu is opened\n"; 
    }
};

class IFactory {
  public:
    virtual Button* createButton() = 0;
    virtual Menu* createMenu() = 0;
};

class MacFactory : public IFactory {
 public:
  Button* createButton() override {
    return new MacButton();
  }

  Menu* createMenu() override {
    return new MacMenu();
  }
};

class WinFactory : public IFactory{
 public:
  Button* createButton() override {
    return new WinButton();
  }

  Menu* createMenu() override {
    return new WinMenu();
  }
};

int main() {
  IFactory* factory1 = new MacFactory();
  Button* buttonMac = factory1 -> createButton();
  Menu* menuMac = factory1 -> createMenu();
  buttonMac -> press();
  menuMac -> openMenu();

  IFactory* factory2 = new WinFactory();
  Button* buttonWin = factory2 -> createButton();
  Menu* menuWin = factory2 -> createMenu();
  buttonWin -> press();
  menuWin -> openMenu();
  return 0;
}