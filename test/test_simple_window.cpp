#include <mingl/mingl.h>

int main() {
    Window window;
    window.setTitle("title");
    window.addHandler(MessageHandler(Message::onPaint(), [](Window *w, Message) {
        HWND h = w->getWindowHandle();
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(h, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
        EndPaint(h, &ps);
    }));
    window.addHandler(Message::onClose(), [](Window *w, Message) {
        HWND h = w->getWindowHandle();
        if (MessageBox(h, "Really quit?", "My application", MB_OKCANCEL) == IDOK) DestroyWindow(h);
    });
    Button btn(1, "hello", 50, 50, 100, 100);
    window.addButton(&btn);
    if (!window.create()) return 1;
    window.show();
    return 0;
}
