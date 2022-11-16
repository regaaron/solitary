#pragma once
//
//  CJuego.hpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 08/11/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#ifndef CJuego_hpp
#define CJuego_hpp

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class CJuego {

private:

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_FONT* font;
    ALLEGRO_EVENT event;
    ALLEGRO_FONT* fuente;
    bool done;
    bool redraw;
    ALLEGRO_BITMAP* tablero;
    ALLEGRO_BITMAP* carta;
    ALLEGRO_BITMAP* corazon1;
    ALLEGRO_BITMAP* corazon2;
    ALLEGRO_BITMAP* corazon3;
    ALLEGRO_BITMAP* corazon4;
    ALLEGRO_BITMAP* corazon5;
    ALLEGRO_BITMAP* corazon6;
    ALLEGRO_BITMAP* corazon7;
    ALLEGRO_BITMAP* corazon8;
    ALLEGRO_BITMAP* corazon9;
    ALLEGRO_BITMAP* corazon10;
    ALLEGRO_BITMAP* corazon11;
    ALLEGRO_BITMAP* corazon12;
    ALLEGRO_BITMAP* corazon13;

    ALLEGRO_BITMAP* diamante1;
    ALLEGRO_BITMAP* diamante2;
    ALLEGRO_BITMAP* diamante3;
    ALLEGRO_BITMAP* diamante4;
    ALLEGRO_BITMAP* diamante5;
    ALLEGRO_BITMAP* diamante6;
    ALLEGRO_BITMAP* diamante7;
    ALLEGRO_BITMAP* diamante8;
    ALLEGRO_BITMAP* diamante9;
    ALLEGRO_BITMAP* diamante10;
    ALLEGRO_BITMAP* diamante11;
    ALLEGRO_BITMAP* diamante12;
    ALLEGRO_BITMAP* diamante13;
    ALLEGRO_BITMAP* cursor;

    ALLEGRO_BITMAP* regla;
    int posX;
    int segundos = 0;

public:
    //constructor
    CJuego(void);

    //Metodos
    int init();
    void deinit();
    void pintar();
    void logicaTeclado();
    void run();

    //Destructor
    ~CJuego();
};
#endif /* CJuego_hpp */
