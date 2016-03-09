/*
    CIRCLE 5
    Written by Amarillion (amarillion@yahoo.com)

    This example shows how you can make an object (a point in this case)
    move around in a circle. You could use this to simulate the orbit
    of a planet for example.
*/

#include <allegro.h>

void orbit ()
{
    int x = 0, y = 0;

    fixed angle = itofix (0);
    fixed angle_stepsize = itofix (1);

    // These determine the radius of the orbit.
    // See what happens if you change length_x to 100 :)
    int length_x = 50;
    int length_y = 50;

    // repeat this until a key is pressed
    while (!keypressed())
    {
        // erase the point from the old position
        putpixel (screen,
            fixtoi(x) + SCREEN_W / 2, fixtoi(y) + SCREEN_H / 2,
            makecol (0, 0, 0));

        // calculate the new position
        x = length_x * fcos (angle);
        y = length_y * fsin (angle);

        // draw the point in the new position
        putpixel (screen,
            fixtoi(x) + SCREEN_W / 2, fixtoi(y) + SCREEN_H / 2,
            makecol (255, 255, 255));

        // increment the angle so that the point moves around in circles
        angle += angle_stepsize;

        // make sure angle is in range
        angle &= 0xFFFFFF;

        // wait 10 milliseconds, or else it'd go too fast
        rest (10);
    }
}

int main ()
{
    // initialize Allegro
    if (allegro_init () < 0)
    {
        allegro_message ("Error: Could not initialize Allegro");
        return -1;
    }
    // initialize gfx mode
    if (set_gfx_mode (GFX_AUTODETECT, 320, 200, 0, 0) < 0)
    {
        allegro_message ("Error: Could not set graphics mode");
        return -1;
    }
    // initialize keyboard
    install_keyboard ();
    clear_keybuf ();

    // initialize timer for the rest() function
    install_timer ();

    // call the example function
    orbit ();

    // exit Allegro
    allegro_exit ();

    return 0;

} END_OF_MAIN ();
