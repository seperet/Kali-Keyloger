//kali l

#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    Display *display = XOpenDisplay(nullptr);
    XEvent event;
    Window root = DefaultRootWindow(display);
    char key[32];
    int keycode;
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("a")), AnyModifier, root, True, GrabModeAsync, GrabModeAsync);
    XSelectInput(display, root, KeyPressMask);
    while(true) {
        XNextEvent(display, &event);
        if(event.type == KeyPress) {
            XLookupString(&event.xkey, key, 32, &keycode, nullptr);
            if(key[0] != 0) {
                cout << "Key pressed: " << key[0] << endl;
            }
            
            Window root_return, child_return;
            int root_x, root_y, win_x, win_y;
            unsigned int mask;
            XQueryPointer(display, DefaultRootWindow(display), &root_return, &child_return, &root_x, &root_y, &win_x, &win_y, &mask);
            cout << "Mouse coordinates: (" << root_x << ", " << root_y << ")" << endl;
            
            
        }
    }
    XCloseDisplay(display);
    return 0;
}