#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUMBSYM,
  _FUNCTION,
  _MOUSE,
  _APPCONTROL,
  LAYER_LENGTH
};

enum tapdances {
  TD_SBKT,
  TD_CBKT,
  TD_PARN,
  TD_LTGT,
  TD_CAPS,
  TD_CAPWORD,
  TAPDANCE_LENGTH
};

enum my_keycodes {
  KC_UP_LAYER,
  KC_DOWN_LAYER,
  MY_KEYCODES_LENGTH
};

// begin tapdances
#define KC_SBKT     TD(TD_SBKT)
#define KC_CBKT     TD(TD_CBKT)
#define KC_PARN     TD(TD_PARN)
#define KC_LTGT     TD(TD_LTGT)

// Custom key codes

#define KC_GUIX     LGUI_T(KC_X)
#define KC_ALTC     LALT_T(KC_C)

// oneshots
#define KC_OSFT   OSM(MOD_LSFT)
#define KC_OALT   OSM(MOD_LALT)

// layer changing
#define KC_ONUM   LT(_FUNCTION, KC_BSPC)

// tapdances
tap_dance_action_t tap_dance_actions[] = {
    [TD_SBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_CBKT]   = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PARN]   = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_LTGT]   = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_CAPS),

};
// end tapdances

uint16_t COMBO_LEN = 19;

// Layer 0 combos
const uint16_t PROGMEM cho_combo1[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cho_combo2[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cho_combo3[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cho_combo4[]= {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cho_combo5[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM cho_combo6[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cho_combo7[] = {KC_S,KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cho_combo8[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cho_combo9[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM cho_combo10[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cho_combo11[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cho_combo12[] = {KC_J, KC_K, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cho_combo13[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cho_combo14[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cho_combo15[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cho_combo16[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cho_combo17[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cho_combo18[] = {KC_M, KC_COMM, KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM cho_combo19[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cho_combo20[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cho_combo21[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM cho_combo22[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cho_combo23[] = {TD(TD_CAPS), KC_B, COMBO_END};
const uint16_t PROGMEM cho_combo24[] = {KC_SPACE, KC_ENTER, COMBO_END};
const uint16_t PROGMEM cho_combo25[] = {KC_TAB, KC_BSPC, COMBO_END};

// layer 0 combos
combo_t key_combos[] = {  
    COMBO(cho_combo1, KC_LSFT),
    COMBO(cho_combo2, KC_RSFT),
    COMBO(cho_combo3, KC_LCTL),
    COMBO(cho_combo4, KC_RCTL),
    COMBO(cho_combo5, KC_LALT),
    COMBO(cho_combo6, KC_RALT),
    COMBO(cho_combo7, LSFT(KC_LCTL)),
    COMBO(cho_combo8, RSFT(KC_RCTL)),
    COMBO(cho_combo9, LSFT(KC_LALT)),
    COMBO(cho_combo10, RSFT(KC_RALT)),
    COMBO(cho_combo11, KC_MEH),
    COMBO(cho_combo12, KC_MEH),
    COMBO(cho_combo13, KC_LGUI),
    COMBO(cho_combo14, KC_RGUI),
    COMBO(cho_combo15, LSFT(KC_LGUI)),
    COMBO(cho_combo16, RSFT(KC_RGUI)),
    COMBO(cho_combo17, KC_HYPR),
    COMBO(cho_combo18, KC_HYPR),
    COMBO(cho_combo19, KC_ESC),
    COMBO(cho_combo20, KC_ESC),
    COMBO(cho_combo21, KC_DEL),
    COMBO(cho_combo22, LCTL(KC_F4)),
    COMBO(cho_combo23, LALT(KC_F4)),
    COMBO(cho_combo24, TO(0)),
    COMBO(cho_combo25, TO(3))
};
// end combos

// Special behavior code
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Layer 0 Alpha
*   _____________________________________________________________________     _____________________________________________________________________
*  |      Q      |      W      |      E      |      R      |      T      |   |      Y      |      U      |      I      |      O      |      P      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      S      |      D      |      F      |      G      |   |      H      |      J      |      K      |      L      |      ;      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      |      V      |      B      |   |      N      |      M      |      ,      |      .      |      /      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,  KC_E,    KC_R,         KC_T,             KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,
    KC_A,    KC_S,  KC_D,    KC_F,         KC_G,             KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN,
    KC_Z,    KC_X,  KC_C,    TD(TD_CAPS),  KC_B,             KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,
                        TO(1), KC_SPACE,   KC_TAB,           KC_BSPC, KC_ENTER, TO(4)
  ),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      / ?    |      [ {    |      ] }    |      ; :    |      ' "    |   |      - _    |      = +    |    < ,      |      . >    |      \ |    |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_3(
    KC_EXLM,    KC_AT,           KC_HASH,          KC_DLR,       KC_PERC,       KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LEFT_PAREN, KC_RIGHT_PAREN,
    KC_1,       KC_2,            KC_3,             KC_4,         KC_5,          KC_6,       KC_7,       KC_8,       KC_9,          KC_0,
    KC_SLASH,   KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_SEMICOLON, KC_QUOTE,      KC_MINUS,   KC_EQUAL,   KC_COMMA,   KC_DOT,        KC_BACKSLASH,
                                      TO(2),      KC_SPACE,      KC_TAB,        KC_BSPC,    KC_ENTER,   TO(0)
  ),

/*  Layer 2 Function
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LEFT        | RIGHT       |      F11    |   |      F12    |  UP         | DOWN        |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  GUI        | ALT         | CTRL        | SHIFT       |  MEH        |   | HYPER       | SHIFT       | CTRL        | ALT         | GUI  .      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_3(
    KC_NO,      KC_NO,     KC_LEFT,    KC_RIGHT,   KC_F11,        KC_F12,    KC_UP,      KC_DOWN,    KC_NO,      KC_NO,
    KC_F1,      KC_F2,     KC_F3,      KC_F4,      KC_F5,         KC_F6,     KC_F7,      KC_F8,      KC_F9,      KC_F10,
    KC_LGUI,    KC_LALT,   KC_LCTL,    KC_LSFT,    KC_MEH,        KC_HYPR,   KC_RSFT,  KC_RCTL,   KC_RALT,    KC_RGUI,
                            TO(3), KC_SPACE,   KC_TAB,            KC_BSPC,   KC_ENTER,   TO(1)
  ),

/*  Layer 3 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | WWWBACK     |             | KC_VOLD     | KC_MUTE     | KC_VOLU     |   |HOME         |PGUP         |MOUSE UP     |PGDN         | WWWSEARCH   |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWFWD      | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| UP          |   |END          |MOUSE LEFT   |MOUSE DOWN   |MOUSE RIGHT  | WWWREFRESH  |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWHOME     |             | LEFT        | RIGHT       | DOWN        |   |WHEEL LEFT   |WHEEL UP     |WHEEL DOWN   |WHEEL RIGHT  | KC_WSTP     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_3(
    KC_WBAK,   KC_NO,      KC_VOLD,     KC_MUTE,    KC_VOLU,       KC_HOME,       KC_PGUP,     KC_MS_UP,      KC_PGDN,        KC_WSCH,
    KC_WFWD,   KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3, KC_UP,         KC_END,        KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_RIGHT,    KC_WREF,
    KC_WHOM,   KC_NO,      KC_LEFT,     KC_RIGHT,   KC_DOWN,       KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO,
                                 TO(4), KC_SPACE,   KC_TAB,        KC_BSPC,   KC_ENTER,    TO(2)
  ),

/*  Layer 4 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             |             |             |             |   |             | QK_BOOT     | QK_REBOOT   |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   | KC_CALC     |             |             |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   |             |             |             |             |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_3(
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,      QK_BOOT,    QK_REBOOT,  KC_NO,     KC_NO,
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_CALC,    KC_NO,      KC_NO,      KC_NO,     KC_NO,
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,
                                  TO(0), KC_SPACE,   KC_TAB,         KC_BSPC,    KC_ENTER,   TO(3)
  )
};
