//
// Created by leandro on 22/03/2021.
//

#ifndef ACTION_GAME_FRAMERATE_H
#define ACTION_GAME_FRAMERATE_H


class FrameRate {

public:
    Uint32 getFrameRate();
    void calculate();
    void initialize();

private:
    Uint32 frameRate = 0;
    Uint32 delta = 0;
    Uint32 lastTime = 0;
    Uint32 fps = 60;

};


#endif //ACTION_GAME_FRAMERATE_H
