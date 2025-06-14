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
// Mouse movement behaviors - using ZMK built-in movement constants
#define U_MS_U &mmv MOVE_UP
#define U_MS_D &mmv MOVE_DOWN
#define U_MS_L &mmv MOVE_LEFT
#define U_MS_R &mmv MOVE_RIGHT

// Mouse scroll behaviors - using ZMK built-in scroll constants
#define U_WH_U &msc SCRL_UP
#define U_WH_D &msc SCRL_DOWN
#define U_WH_L &msc SCRL_LEFT
#define U_WH_R &msc SCRL_RIGHT

