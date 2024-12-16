#ifndef RENDERER_H
#define RENDERER_H

#include "PixelToaster.h"

#include <iostream>

#define WWIDTH 400
#define WHEIGHT 300

namespace pix = PixelToaster;

class Renderer : public pix::Listener {
public:
    Renderer(pix::Display& display);

    void clear(pix::integer8 r, pix::integer8 g, pix::integer8 b);
    void drawRect(float x, float y, float w, float h);

    pix::TrueColorPixel pixels[WWIDTH*WHEIGHT];
private:
    float tx, ty, s;
    virtual void onKeyPressed(pix::DisplayInterface& display, pix::Key key) override;
};


#endif
