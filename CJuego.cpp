//
//  CJuego.cpp
//  testAllegro
//
//  Created by Jose de Jesus Palos on 08/11/22.
//  Copyright © 2022 Jose de Jesus Palos. All rights reserved.
//

#include "CJuego.hpp"
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <string.h>
#include<Windows.h>

CJuego::CJuego(void) {
    timer = NULL;
    queue = NULL;
    display = NULL;
    font = NULL;

    posX = 0;

    init();

    done = false;
    redraw = true;
    corazon1 = al_load_bitmap("cartas/1corazon.jpg");
    corazon2 = al_load_bitmap("cartas/2corazon.jpg");
    corazon3 = al_load_bitmap("cartas/3corazon.jpg");
    corazon4 = al_load_bitmap("cartas/4corazon.jpg");
    corazon5 = al_load_bitmap("cartas/5corazon.jpg");
    corazon6 = al_load_bitmap("cartas/6corazon.jpg");
    corazon7 = al_load_bitmap("cartas/7corazon.jpg");
    corazon8 = al_load_bitmap("cartas/8corazon.jpg");
    corazon9 = al_load_bitmap("cartas/9corazon.jpg");
    corazon10 = al_load_bitmap("cartas/10corazon.jpg");
    corazon11 = al_load_bitmap("cartas/11corazon.jpg");
    corazon12 = al_load_bitmap("cartas/12corazon.jpg");
    corazon13 = al_load_bitmap("cartas/13corazon.jpg");

    diamante1 = al_load_bitmap("cartas/1diamante.jpg");
    diamante2 = al_load_bitmap("cartas/2diamante.jpg");
    diamante3 = al_load_bitmap("cartas/3diamante.jpg");
    diamante4 = al_load_bitmap("cartas/4diamante.jpg");
    diamante5 = al_load_bitmap("cartas/5diamante.jpg");
    diamante6 = al_load_bitmap("cartas/6diamante.jpg");
    diamante7 = al_load_bitmap("cartas/7diamante.jpg");
    diamante8 = al_load_bitmap("cartas/8diamante.jpg");
    diamante9 = al_load_bitmap("cartas/9diamante.jpg");
    diamante10 = al_load_bitmap("cartas/10diamante.jpg");
    diamante11 = al_load_bitmap("cartas/11diamante.jpg");
    diamante12 = al_load_bitmap("cartas/12diamante.jpg");
    diamante13 = al_load_bitmap("cartas/13diamante.jpg");
    
    regla = al_load_bitmap("cartas/regla1.png");
    fuente = al_load_font("fuente.ttf", 40, 0);
    if (!fuente) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la fuente", NULL, ALLEGRO_MESSAGEBOX_ERROR);

    }

    if (!corazon1) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 1corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon2) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 2corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon3) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 3corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon4) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 4corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon5) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 5corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon6) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 6corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon7) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 7corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon8) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 8corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon9) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 9corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon10) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 10corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon11) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 11corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon12) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 12corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!corazon13) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 13corazon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    if (!diamante1) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 1diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante2) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 2diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante3) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 3diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante4) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 4diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante5) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 5diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante6) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 6diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante7) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 7diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante8) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 8diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante9) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 9diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante10) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 10diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante11) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 11diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante12) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 12diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    if (!diamante13) {
        al_show_native_message_box(NULL, "Error", "Error", "al cargar la imagen 13diamante ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    tablero = al_load_bitmap("cartas/tablero.jpg");
    carta = al_load_bitmap("cartas/abajo.jpg");
    // cursor= al_load_bitmap("cur");
    corazon13 = al_load_bitmap("cartas/13corazon.jpg");
    al_start_timer(timer);
}

CJuego::~CJuego() {
    deinit();
}

void CJuego::run() {

    while (1)
    {
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (event.timer.source == timer) {//esto hace que el contador se incremente en 1 cada segundo y no cad vuelta del ciclo
                segundos++;
            }
        }
        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // logica del juego.
            redraw = true;
            break;
        case ALLEGRO_EVENT_KEY_CHAR:
        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_KEY_UP:
            logicaTeclado();
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            pintar();
            redraw = false;
        }
    }
}

void CJuego::pintar() {
    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Pintamos texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
    //Pintamos imagen

    al_draw_bitmap(tablero, 0, 0, 0);
    al_draw_bitmap(carta, 40, 50, 0);
    al_draw_bitmap(diamante10, 700, 50, 0);
    al_draw_bitmap(corazon1, 850, 50, 0);
    al_draw_bitmap(corazon1, 1000, 50, 0);
    al_draw_bitmap(corazon1, 1150, 50, 0);

    //
    al_draw_bitmap(corazon1, 1150, 225, 0);
    al_draw_bitmap(corazon2, 1150, 250, 0);
    al_draw_bitmap(corazon3, 1150, 275, 0);
    al_draw_bitmap(corazon4, 1150, 300, 0);
    al_draw_bitmap(corazon5, 1150, 325, 0);
    al_draw_bitmap(corazon6, 1150, 350, 0);
    al_draw_bitmap(corazon7, 1150, 350, 0);
    al_draw_bitmap(corazon8, 1150, 375, 0);

    //
    al_draw_bitmap(corazon9, 1000, 225, 0);
    al_draw_bitmap(corazon10, 1000, 250, 0);
    al_draw_bitmap(corazon11, 1000, 275, 0);
    al_draw_bitmap(corazon12, 1000, 300, 0);
    al_draw_bitmap(corazon13, 1000, 325, 0);
    al_draw_bitmap(corazon1, 1000, 350, 0);

    //
    al_draw_bitmap(carta, 850, 225, 0);
    al_draw_bitmap(carta, 850, 250, 0);
    al_draw_bitmap(carta, 850, 275, 0);
    al_draw_bitmap(carta, 850, 300, 0);
    al_draw_bitmap(corazon1, 850, 325, 0);


    //
    al_draw_bitmap(carta, 700, 225, 0);
    al_draw_bitmap(carta, 700, 250, 0);
    al_draw_bitmap(carta, 700, 275, 0);
    al_draw_bitmap(corazon1, 700, 300, 0);

    //
    int i = 1;
    al_draw_bitmap(diamante1, 550, 225, 0);
    al_draw_bitmap(diamante2, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante3, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante4, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante5, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante6, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante7, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante8, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante9, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante10, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante11, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante12, 550, 225 + 35 * i++, 0);
    al_draw_bitmap(diamante13, 550, 225 + 35 * i++, 0);

    //
    al_draw_bitmap(carta, 400, 225, 0);
    al_draw_bitmap(corazon1, 400, 250, 0);
    //
    al_draw_bitmap(corazon13, 250, 225, 0);

   // al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 20, 0, "PosX:%i", posX);
    
    al_draw_textf(fuente, al_map_rgb(segundos*100%255, segundos*235%255, segundos*134%255), 300, 10, 0, "contador:%i", this->segundos);

    //al_draw_bitmap(regla, 0, 0, 0);

    /*al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
    al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
    al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
    al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);*/

    //mandamos a pantalla
    al_flip_display();
}


void CJuego::logicaTeclado() {

    if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        posX++;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
        posX--;
    }
}
int CJuego::init() {
    //inicializamos allegro
    if (!al_init())
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }
    

    //Inicializamos teclado
    if (!al_install_keyboard())
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }
    //Inicializamos timer y event_queue para garantizar
    //consistencia en la velocidad
    timer = al_create_timer(1.0 );
    if (!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }

    //Create Keybord queue
    queue = al_create_event_queue();
    if (!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }

    //Inicializamos parntalla de 640x480
    //display = al_create_display(1600, 1200);
    int ancho = GetSystemMetrics(SM_CXSCREEN);
    int alto = GetSystemMetrics(SM_CYSCREEN);

    display = al_create_display(1300, 758);
    al_set_window_title(display, "solitario");
    al_set_window_position(display, ancho / 2 - 1300 / 2, alto / 2 - 758 / 2);
    if (!display)
    {
        printf("couldn't initialize display\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    if (!al_init_font_addon()) {//fuentes
        al_show_native_message_box(NULL, "ERROR", "ERROR", "font addon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);

    }
    if (!al_init_ttf_addon()) {//fuentes
        al_show_native_message_box(NULL, "ERROR", "ERROR", "ttf adoon ", NULL, ALLEGRO_MESSAGEBOX_ERROR);

    }
    //Inicializamos mouse

    al_install_mouse();
    al_hide_mouse_cursor(display);
    /* add other initializations here */

    font = al_create_builtin_font();
    if (!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
        return 1;
    }

    if (!al_init_primitives_addon())
    {
        printf("couldn't initialize primitives\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    return 0;
}

void CJuego::deinit() {

    al_destroy_bitmap(tablero);
    al_destroy_bitmap(carta);
    al_destroy_bitmap(corazon1);
    al_destroy_bitmap(corazon2);
    al_destroy_bitmap(corazon3);
    al_destroy_bitmap(corazon4);
    al_destroy_bitmap(corazon5);
    al_destroy_bitmap(corazon6);
    al_destroy_bitmap(corazon7);
    al_destroy_bitmap(corazon8);
    al_destroy_bitmap(corazon9);
    al_destroy_bitmap(corazon10);
    al_destroy_bitmap(corazon11);
    al_destroy_bitmap(corazon12);
    al_destroy_bitmap(corazon13);

    al_destroy_bitmap(diamante1);
    al_destroy_bitmap(diamante2);
    al_destroy_bitmap(diamante3);
    al_destroy_bitmap(diamante4);
    al_destroy_bitmap(diamante5);
    al_destroy_bitmap(diamante6);
    al_destroy_bitmap(diamante7);
    al_destroy_bitmap(diamante8);
    al_destroy_bitmap(diamante9);
    al_destroy_bitmap(diamante10);
    al_destroy_bitmap(diamante11);
    al_destroy_bitmap(diamante12);
    al_destroy_bitmap(diamante13);

    al_destroy_bitmap(cursor);
    //al_clear_keybuf();
    /* add other deinitializations here */
    al_destroy_font(font);
    al_destroy_font(fuente);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}

