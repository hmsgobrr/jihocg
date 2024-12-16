#include "Renderer.h"

Renderer::Renderer(pix::Display& display) {
    display.listener(this);
    s = 1;
}

void Renderer::clear(pix::integer8 r, pix::integer8 g, pix::integer8 b) {
    for (int i = 0; i < WHEIGHT; i++) {
        for (int j = 0; j < WWIDTH; j++) {
            pixels[i*WWIDTH + j].r = r;
            pixels[i*WWIDTH + j].g = g;
            pixels[i*WWIDTH + j].b = b;
        }
    }
}

void Renderer::drawRect(float x, float y, float w, float h) {
    x += tx;
    y += ty;
    x *= s;
    y *= s;

    for (int i = y; i <= y+h; i++) {
        for (int j = x; j <= x+w; j++) {
            pixels[i*WWIDTH + j].r = 255;
            pixels[i*WWIDTH + j].g = 255;
            pixels[i*WWIDTH + j].b = 255;
        }
    }
}

void Renderer::onKeyPressed(pix::DisplayInterface& display, pix::Key key) {
    if (key == pix::Key::D) tx -= 5;
    else if (key == pix::Key::A) tx += 5;
    else if (key == pix::Key::S) ty -= 5;
    else if (key == pix::Key::W) ty += 5;

    else if (key == pix::Key::E) s += 0.1;
    else if (key == pix::Key::Q) s -= 0.1;
}
