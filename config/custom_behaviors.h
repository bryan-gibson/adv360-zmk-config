// autopair macros
// mbkt: Types matching square brackets [] and positions cursor between them
ZMK_BEHAVIOR(mbkt, macro,
    bindings = <&macro_tap &kp LBKT &kp RBKT &kp LEFT>;
)
// mbrc: Types matching curly braces {} and positions cursor between them
ZMK_BEHAVIOR(mbrc, macro,
    bindings = <&macro_tap &kp LBRC &kp RBRC &kp LEFT>;
)
// mpar: Types matching parentheses () and positions cursor between them
ZMK_BEHAVIOR(mpar, macro,
    bindings = <&macro_tap &kp LPAR &kp RPAR &kp LEFT>;
)
// msqt: Types matching single quotes '' and positions cursor between them
ZMK_BEHAVIOR(msqt, macro,
    bindings = <&macro_tap &kp SQT &kp SQT &kp LEFT>;
)
// mdqt: Types matching double quotes "" and positions cursor between them
ZMK_BEHAVIOR(mdqt, macro,
    bindings = <&macro_tap &kp DQT &kp DQT &kp LEFT>;
)
// tap: '' (single quotes with cursor between) | shift + tap: "" (double quotes with cursor between)
ZMK_BEHAVIOR(msqt_morph, mod_morph,
    bindings = <&msqt>, <&mdqt>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)
// tab navigation macros
// mtabnext: Navigate to next tab (Command+T in macOS browsers and many apps)
ZMK_BEHAVIOR(mtabnext, macro,
    bindings = <&macro_tap &kp G &kp T>;
)
// mtabprev: Navigate to previous tab (Command+Shift+T in macOS browsers and many apps)
ZMK_BEHAVIOR(mtabprev, macro,
    bindings =
        <&macro_tap &kp G &kp LS(T)>;
)

// tap: sticky-shift | shift + tap/ double-tap: caps-word | hold: shift
//ZMK_BEHAVIOR(smart_shft, mod_morph,
//    bindings = <&sk LSHFT>, <&caps_word>;
//    mods = <(MOD_LSFT)>;
//)


// Command+Tab swapper for app switching in macOS
// Press once to activate Command+Tab, press SWAP_PREV for Command+Shift+Tab
ZMK_BEHAVIOR(swapper, tri_state,
    bindings = <&kt LGUI>, <&kp TAB>, <&kt LGUI>;
    ignored-key-positions = <LB2>, <20>; // ignored key should be position of SWAP_PREV
)

// tap: comma (,) | shift + tap: semicolon (;) | ctrl + shift + tap: less than (<)
ZMK_BEHAVIOR(comma_morph, mod_morph,
    mods = <(MOD_LSFT|MOD_RSFT)>;
    bindings = <&kp COMMA>, <&comma_inner_morph>;
)
ZMK_BEHAVIOR(comma_inner_morph, mod_morph,
    bindings = <&kp SEMICOLON>, <&kp LESS_THAN>;
    mods = <(MOD_LCTL|MOD_RCTL)>;
)

// tap: dot (.) | shift + tap: colon (:) | ctrl + shift + tap: greater than (>)
ZMK_BEHAVIOR(dot_morph, mod_morph,
    bindings = <&kp DOT>, <&dot_inner_morph>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)
ZMK_BEHAVIOR(dot_inner_morph, mod_morph,
    bindings = <&kp COLON>, <&kp GREATER_THAN>;
    mods = <(MOD_LCTL|MOD_RCTL)>;
)

// tap: question mark (?) | shift + tap: exclamation mark (!)
ZMK_BEHAVIOR(qexcl, mod_morph,
    bindings = <&kp QMARK>, <&kp EXCL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)


// tap: space | shift + tap: underscore (_) | hold: activate NAV layer
ZMK_BEHAVIOR(lt_spc, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&spund>;
)
ZMK_BEHAVIOR(spund, mod_morph,
  bindings = <&kp SPACE>, <&kp UNDERSCORE>;
  mods = <(MOD_LSFT|MOD_RSFT)>;
)

// tap: backspace | left shift + tap: delete | right shift + tap: shift+delete (permanent delete in macOS) | hold: activate layer
ZMK_BEHAVIOR(lt_del, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&bs_del>;
)
ZMK_BEHAVIOR(bs_del, mod_morph,
    bindings = <&kp BSPC>, <&kp DEL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
    keep-mods = <MOD_RSFT>;
)

// tap: sticky shift (next key press will be shifted) | double-tap: sticky num-layer | hold: num-layer
ZMK_BEHAVIOR(shift_num, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&sticky_num_dance>;
)
ZMK_BEHAVIOR(sticky_num_dance, tap_dance,
    tapping-term-ms = <300>;
    bindings = <&sk LSHFT>, <&sl NUM>;  // reverse this for sticky-num on single tap
)

// tap: caps word (capitalize all words until space/timeout) | double-tap: caps lock (toggle all caps)
ZMK_BEHAVIOR(caps_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&caps_word>, <&kp CAPS>;
)
// Types comma followed by space
ZMK_BEHAVIOR(comma_space, macro,
    bindings = <&macro_tap &kp COMMA &kp SPACE>;
)
// tap: space | double-tap: comma + space | shift + tap: underscore
ZMK_BEHAVIOR(comma_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&spund>, <&comma_space>;
)



// Shortcuts and aliases


/* Apple Globe key - use built-in ZMK definition */
// #define C_KEYBOARD_LAYOUT_SELECT (ZMK_HID_USAGE(HID_USAGE_CONSUMER, 0x029D))
// #define GLOBE C_KEYBOARD_LAYOUT_SELECT
// As per PR 1938 - GLOBE is now defined in ZMK core

// Spectacle window management controls for macOS
#define SPC_UP    &kp LA(LG(UP))         // Move window to upper position (Option+Command+Up)
#define SPC_DOWN  &kp LA(LG(DOWN))       // Move window to lower position (Option+Command+Down)
#define SPC_LEFT  &kp LA(LG(LEFT))       // Move window to left position (Option+Command+Left)
#define SPC_RIGHT &kp LA(LG(RIGHT))      // Move window to right position (Option+Command+Right)
#define SPC_FULL  &kp LA(LG(F))          // Fullscreen window (Option+Command+F)
#define SPC_MVR   &kp LC(LA(LG(RIGHT)))  // Move window to right screen (Control+Option+Command+Right)
#define SPC_MVL   &kp LC(LA(LG(LEFT)))   // Move window to left screen (Control+Option+Command+Left)
#define SPC_UNDO  &kp LC(LA(LG(Z)))      // Undo last window action (Control+Option+Command+Z)

// Mouse Layer command shortcuts
// All keys become tap: command + (key) and long tap: shift + command + (key)
#define Q_F &mt LS(LG(F)) LG(F)  // Tap: Command+F (Find) | Hold: Shift+Command+F (Advanced Find/Find in Files)
#define Q_P &mt LS(LG(P)) LG(P)  // Tap: Command+P (Print) | Hold: Shift+Command+P (Page Setup/Command Palette)
#define Q_B &mt LS(LG(B)) LG(B)  // Tap: Command+B (Bold) | Hold: Shift+Command+B (Advanced formatting/Bookmarks)
#define Q_G &mt LS(LG(G)) LG(G)  // Tap: Command+G (Find Next) | Hold: Shift+Command+G (Find Previous)
#define Q_Z &mt LS(LG(Z)) LG(Z)  // Tap: Command+Z (Undo) | Hold: Shift+Command+Z (Redo)
#define Q_X &mt LS(LG(X)) LG(X)  // Tap: Command+X (Cut) | Hold: Shift+Command+X (Advanced cut/transform)
#define Q_C &mt LS(LG(C)) LG(C)  // Tap: Command+C (Copy) | Hold: Shift+Command+C (Copy format/special)
#define Q_D &mt LS(LG(D)) LG(D)  // Tap: Command+D (Duplicate/Select Word) | Hold: Shift+Command+D (Advanced duplication)
#define Q_V &mt LS(LG(V)) LG(V)  // Tap: Command+V (Paste) | Hold: Shift+Command+V (Paste Special/Paste without formatting)

#define LOCK_SCRN   &kp LC(LG(Q))        // Lock screen (Control+Command+Q)
#define CANCEL      &kp K_CANCEL         // Cancel caps-word, num-word and smart-mouse
#define LHYP        LS(LC(LA(LGUI)))     // Left Hyper key (Shift+Control+Option+Command)
#define RHYP        RS(RC(RA(RGUI)))     // Right Hyper key (Shift+Control+Option+Command)
#define COPY_CUT    &mt LG(X) LG(C)      // Tap: Command+C (Copy) | Hold: Command+X (Cut)
#define CMD_PASTE   &kp LG(V)            // Command+V (Paste)
#define CMD_UNDO    &kp LG(Z)            // Command+Z (Undo)
#define CMD_REDO    &kp LS(LG(Z))        // Shift+Command+Z (Redo)
#define PREV_WINDOW &kp LS(LG(GRAVE))    // Shift+Command+` (Previous window in same application)
#define NEXT_WINDOW &kp LG(GRAVE)        // Command+` (Next window in same application)
#define NEXT_TAB    &mtabnext            // Next tab in vim or browser (Command+T)
#define PREV_TAB    &mtabprev            // Previous tab in vim or browser (Command+Shift+T)
#define DSK_PREV    &kp LC(LEFT)         // Control+Left (Previous desktop in macOS)
#define DSK_NEXT    &kp LC(RIGHT)        // Control+Right (Next desktop in macOS)
#define SWAPPER     &swapper             // Command+Tab app switcher
#define SWAP_PREV   &kp LS(TAB)          // Shift+Tab (Move backward in app switcher)

// Thumb keys with special behaviors
#define SPC_NAV     &lt_spc NAV 0        // Tap: space | Shift+tap: underscore | Hold: NAV layer
#define RET_HYP     &mt RHYP ENTER       // Tap: Enter | Hold: Hyper key (Shift+Control+Option+Command)
#define BSPC_SYM    &lt_del SYM 0        // Tap: Backspace | Left-shift+tap: Delete | Right-shift+tap: Shift+Delete | Hold: SYM layer
#define SHFT_NUM    &shift_num NUM 0     // Tap: Sticky shift | Double-tap: Sticky NUM layer | Hold: NUM layer

/* #define MAKE_LONG_HOLD(NAME, HOLD) \ */
/*     ZMK_BEHAVIOR(NAME, hold_tap, \ */
/*         flavor = "tap-preferred"; \ */
/*         tapping-term-ms = <300>; \ */
/*         quick-tap-ms = <QUICK_TAP_MS>; \ */
/*         bindings = <HOLD, &none>; \ */
/*     ) */
/* MAKE_LONG_HOLD(hbt, &bt) */
// TODO: figure out how to get these things wrapped in a hold tap so that accidental taps don't change the bluetooth profile
#define BT_0 &bt BT_SEL 0  // Select Bluetooth profile 0
#define BT_1 &bt BT_SEL 1  // Select Bluetooth profile 1
#define BT_2 &bt BT_SEL 2  // Select Bluetooth profile 2
#define BT_3 &bt BT_SEL 3  // Select Bluetooth profile 3
#define BT_4 &bt BT_SEL 4  // Select Bluetooth profile 4

// Custom behavior to toggle between DEFAULT and QWERTY layers when held for 1 second
// Simplified version - toggle to DEFAULT layer
ZMK_BEHAVIOR(layer_toggle_hold, hold_tap,
    flavor = "tap-preferred";
    tapping-term-ms = <1000>;  // 1 second hold time
    quick-tap-ms = <0>;        // Disable quick tap
    bindings = <&tog>, <&none>; // Toggle DEFAULT layer on hold, no action on tap
)

// Define a shorthand for our new behavior
#define TOGGLE_LAYER &layer_toggle_hold DEFAULT 0

// Cross-platform system shortcuts
// Windows shortcuts (for potential dual-OS users)
#define WIN_CUT     &kp LC(X)        // Ctrl+X (Cut)
#define WIN_COPY    &kp LC(C)        // Ctrl+C (Copy)
#define WIN_PASTE   &kp LC(V)        // Ctrl+V (Paste)
#define WIN_UNDO    &kp LC(Z)        // Ctrl+Z (Undo)
#define WIN_REDO    &kp LC(Y)        // Ctrl+Y (Redo)
#define WIN_SELALL  &kp LC(A)        // Ctrl+A (Select All)
#define WIN_LOCK    &kp LG(L)        // Win+L (Lock PC)
#define WIN_DESKTOP &kp LG(D)        // Win+D (Show Desktop)
#define WIN_SNIP    &kp LS(LG(S))    // Shift+Win+S (Snipping Tool)

// Additional useful macros
ZMK_BEHAVIOR(macro_kinesis, macro,
    bindings = <&macro_tap &kp K &kp I &kp N &kp E &kp S &kp I &kp S>;
)

// Double-click macro for mouse functionality
ZMK_BEHAVIOR(double_click, macro,
    bindings = <&macro_tap &mkp LCLK &mkp LCLK>;
)

#define KINESIS     &macro_kinesis       // Types "KINESIS"
#define DBL_CLICK   &double_click        // Double mouse click
