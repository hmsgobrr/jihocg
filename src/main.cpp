#include "Renderer.h"

int main() {
    // const int width  = 320;
    // const int height = 240;

    pix::Display display("jihobombom", WWIDTH, WHEIGHT, pix::Output::Default, pix::Mode::TrueColor);

    Renderer ren(display);

    // pix::vector<pix::TrueColorPixel pixels(width * height);

    while (display.open()) {
        ren.clear(0, 240, 0);

        ren.drawRect(WWIDTH/2 - 25, WHEIGHT/2 - 25, 50, 50);

        display.update(ren.pixels);
    }
}
