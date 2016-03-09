/*
    CIRCLE 1
    Written by Amarillion (amarillion@yahoo.com)
    Ported to Allegro5 by Makhtar Diouf

    This program demonstrates the use of sin and cos with floats.
    All it does is draw a circle on the screen.

 gcc circ1.c -o circ1 -lallegro_color -lallegro_dialog -lallegro -lallegro_main -lm

*/
#include <math.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

ALLEGRO_BITMAP *screen;
  ALLEGRO_DISPLAY *display = NULL;

const int SCREEN_W = 640;
const int SCREEN_H = 480;

void draw_circle ()
{
    int x, y;
    int length = 50;
    float angle = 0.0;
    float angle_stepsize = 0.1;

    screen = al_create_bitmap(SCREEN_W, SCREEN_H);
    al_set_target_bitmap(screen);
    al_set_target_bitmap(al_get_backbuffer(display));

    ALLEGRO_FONT *font;// = al_load_ttf_font("pirulen.ttf",72,0 );
    
    // go through all angles from 0 to 2 * M_PI radians
    while (angle < 2 * M_PI)
    {
        // calculate x, y from a vector with known length and angle
        x = length * cos (angle);
        y = length * sin (angle);

	/*    putpixel (screen,
            x + SCREEN_W / 2, y + SCREEN_H / 2,
            makecol (255, 255, 255));
	*/
	al_draw_text(font, al_map_rgb(255,255,255), x, y,ALLEGRO_ALIGN_CENTRE, ".");

	al_flip_display();
        angle += angle_stepsize;
    }
}

int main ()
{

  if(!al_init()) {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }

  display = al_create_display(640, 480);
  if(!display) {
    fprintf(stderr, "failed to create display!\n");
    return -1;
  }

  al_clear_to_color(al_map_rgb(0,0,0));

    // initialize keyboard
    al_install_keyboard ();
    //    clear_keybuf ();

    // call the example function
    draw_circle ();

    // wait for a user key-press
    // readkey ();

    al_destroy_bitmap(screen);
    al_destroy_display(display);
    
    // exit Allegro
    //al_exit ();

    return 0;

}
//END_OF_MAIN ();
