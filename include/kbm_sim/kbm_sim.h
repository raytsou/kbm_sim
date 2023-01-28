#include <sstream>
#include <stdio.h>
#include <vector>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

#include <iostream>

class Sim
{
  public:
    Sim();
    ~Sim();
    void move_pointer(const double, const double);
    void press_keys(const std::vector<std::string>);
    void release_keys(const std::vector<std::string>);
    void mouse_click(const std::vector<unsigned int>);
    void mouse_release(const std::vector<unsigned int>);

  private:
    Display* display;
    Window root;
    KeySym prep_key(std::string);
};
