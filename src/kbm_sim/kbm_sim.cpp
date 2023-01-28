#include <kbm_sim/kbm_sim.h>

Sim::Sim(){
    display = XOpenDisplay(0);
}

void Sim::move_pointer(const double x, const double y){
    XWarpPointer(display, None, None, 0, 0, 0, 0, x, y);
    XSync(display, False);
    XFlush(display);
}

KeySym Sim::prep_key(std::string key){
    if (key == "space") return XK_space;
    else if (key == "ctrl") return XK_Control_L;
    else if (key == "shift") return XK_Shift_L;
    else return XStringToKeysym(key.c_str());
}

void Sim::press_keys(const std::vector<std::string> keys){
    for (auto k: keys){
        KeySym keysym = prep_key(k);
        KeyCode modcode = XKeysymToKeycode(display, keysym);
        XTestFakeKeyEvent(display, modcode, True, 0);
        XFlush(display);
    }
}

void Sim::release_keys(const std::vector<std::string> keys){
    for (auto k: keys){        
        KeySym keysym = prep_key(k);
        KeyCode modcode = XKeysymToKeycode(display, keysym);
        XTestFakeKeyEvent(display, modcode, False, 0);
        XFlush(display);
    }
}

void Sim::mouse_click(const std::vector<unsigned int> keys){
    for (auto k: keys){
        if (k > 0 && k < 10){
            XTestFakeButtonEvent(display, k, True, 0);
            XFlush(display);
        }
    }
}

void Sim::mouse_release(const std::vector<unsigned int> keys){
    for (auto k: keys){
        if (k > 0 && k < 10){
            XTestFakeButtonEvent(display, k, False, 0);
            XFlush(display);
        }
    }
}

Sim::~Sim(){
    XCloseDisplay(display);
}