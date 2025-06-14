#include <dt-bindings/zmk/mouse.h>

// Mouse movement configuration
&mmv {
    acceleration-exponent = <1>;
    time-to-max-speed-ms = <400>;
    delay-ms = <0>;
};

// Mouse scroll configuration  
&msc {
    acceleration-exponent = <0>;
    time-to-max-speed-ms = <400>;
    delay-ms = <10>;
};

#define U_MOUSE_MOVE_MAX 1500
#define U_MOUSE_SCROLL_MAX 10

// Mouse button definitions
#define U_BTN1 &mkp LCLK
#define U_BTN2 &mkp RCLK  
#define U_BTN3 &mkp MCLK
// Mouse movement directions
#define MOVE_UP MOVE_VERT(-U_MOUSE_MOVE_MAX)
#define MOVE_DOWN MOVE_VERT(U_MOUSE_MOVE_MAX)
#define MOVE_LEFT MOVE_HOR(-U_MOUSE_MOVE_MAX)
#define MOVE_RIGHT MOVE_HOR(U_MOUSE_MOVE_MAX)

// Mouse scroll directions
#define SCROLL_UP SCRL_VERT(U_MOUSE_SCROLL_MAX)
#define SCROLL_DOWN SCRL_VERT(-U_MOUSE_SCROLL_MAX)
#define SCROLL_LEFT SCRL_HOR(-U_MOUSE_SCROLL_MAX)
#define SCROLL_RIGHT SCRL_HOR(U_MOUSE_SCROLL_MAX)

// Mouse movement behaviors
#define U_MS_U &mmv MOVE_UP
#define U_MS_D &mmv MOVE_DOWN
#define U_MS_L &mmv MOVE_LEFT
#define U_MS_R &mmv MOVE_RIGHT

// Mouse scroll behaviors
#define U_WH_U &msc SCROLL_UP
#define U_WH_D &msc SCROLL_DOWN
#define U_WH_L &msc SCROLL_LEFT
#define U_WH_R &msc SCROLL_RIGHT

