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
  TD_CAPS,
  TD_CAPWORD,
  TAPDANCE_LENGTH
};

// tapdances
tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_CAPS),
};
// end tapdances

uint16_t COMBO_LEN = 19;

// Layer 0 combos
const uint16_t PROGMEM lshft_combo[] = {LALT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM rshft_combo[] = {RCTL_T(KC_J), RALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM lesc_combo[] = {LCTL_T(KC_F), RCS_T(KC_G), COMBO_END};
const uint16_t PROGMEM resc_combo[] = {RCS_T(KC_H), RCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM del_combo[] = {MEH_T(KC_Y), RSA_T(KC_U), COMBO_END};
const uint16_t PROGMEM ins_combo[] = {HYPR_T(KC_N), KC_M, COMBO_END};
const uint16_t PROGMEM winclose_combo[] = {LSA_T(KC_R), MEH_T(KC_T), COMBO_END};
const uint16_t PROGMEM appclose_combo[] = {TD(TD_CAPS), HYPR_T(KC_B), COMBO_END};
const uint16_t PROGMEM layernum_combo24[] = {KC_SPACE, KC_ENTER, COMBO_END};
const uint16_t PROGMEM layermouse_combo25[] = {KC_TAB, KC_BSPC, COMBO_END};

// layer 0 combos
combo_t key_combos[] = {  
    COMBO(lshft_combo, KC_LSFT),
    COMBO(rshft_combo, KC_RSFT),
    COMBO(lesc_combo, KC_ESC),
    COMBO(resc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(ins_combo, KC_INS),
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
*  |      Q      |      W      |      E      | R-shiftalt  | T-MEh       |   |      Y-Meh  | U-shiftalt  |      I      |      O      |      P      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      S-gui  |   D -alt    |   F-ctrl    | G-ctrlshift |   | H-ctrlshift |      J-ctrl |      K-alt  |      L-gui  |      ;      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      | V-caplock   |      B-Hypr |   |   N-Hypr    |      M      |      ,      |      .      |      /      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER-1   | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER-4 |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_3(
    KC_Q,        KC_W,            KC_E,         LSA_T(KC_R),  MEH_T(KC_T),      MEH_T(KC_Y),    RSA_T(KC_U),  KC_I,         KC_O,         KC_P,
    KC_A,        LGUI_T(KC_S),    LALT_T(KC_D), LCTL_T(KC_F), RCS_T(KC_G),      RCS_T(KC_H),    RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), KC_SCLN,
    KC_Z,        KC_X,            KC_C,         TD(TD_CAPS),  HYPR_T(KC_B),     HYPR_T(KC_N),   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                  TO(1),        KC_SPACE,     KC_TAB,           KC_BSPC,        KC_ENTER,     TO(4)
  ),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      / ?    |      [ {    |      ] }    |      ; :    |      ' "    |   |      - _    |      = +    |    < ,      |      . >    |      \ |    |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_3(
    KC_EXLM,    KC_AT,           KC_HASH,          KC_DLR,       KC_PERC,       KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LEFT_PAREN, KC_RIGHT_PAREN,
    KC_1,       KC_2,            KC_3,             KC_4,         KC_5,          KC_6,       KC_7,       KC_8,       KC_9,          KC_0,
    KC_SLASH,   KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_SEMICOLON, KC_QUOTE,      KC_MINUS,   KC_EQUAL,   KC_COMMA,   KC_DOT,        KC_BACKSLASH,
                                      TO(2),       KC_TRNS,      KC_TRNS,       KC_TRNS,    KC_TRNS,   TO(0)
  ),

/*  Layer 2 Function
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LEFT        | RIGHT       |      F11    |   |      F12    |  UP         | DOWN        |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  GUI        | ALT         | CTRL        | SHIFT       |  MEH        |   | HYPER       | SHIFT       | CTRL        | ALT         | GUI  .      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_3(
    KC_NO,      KC_NO,     KC_LEFT,    KC_RIGHT,   KC_F11,      KC_F12,    KC_UP,      KC_DOWN,    KC_NO,      KC_NO,
    KC_F1,      KC_F2,     KC_F3,      KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,      KC_F9,      KC_F10,
    KC_LGUI,    KC_LALT,   KC_LCTL,    KC_LSFT,    KC_MEH,      KC_HYPR,   KC_RSFT,  KC_RCTL,   KC_RALT,    KC_RGUI,
                              TO(3),   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   TO(1)
  ),

/*  Layer 3 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | WWWBACK     |             | KC_VOLD     | KC_MUTE     | KC_VOLU     |   |HOME         |PGUP         |MOUSE UP     |PGDN         | WWWSEARCH   |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWFWD      | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| UP          |   |END          |MOUSE LEFT   |MOUSE DOWN   |MOUSE RIGHT  | WWWREFRESH  |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWHOME     |             | LEFT        | RIGHT       | DOWN        |   |WHEEL LEFT   |WHEEL UP     |WHEEL DOWN   |WHEEL RIGHT  | KC_WSTP     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_3(
    KC_WBAK,   KC_NO,      KC_VOLD,     KC_MUTE,    KC_VOLU,       KC_HOME,       KC_PGUP,     KC_MS_UP,      KC_PGDN,        KC_WSCH,
    KC_WFWD,   KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3, KC_UP,         KC_END,        KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_RIGHT,    KC_WREF,
    KC_WHOM,   KC_NO,      KC_LEFT,     KC_RIGHT,   KC_DOWN,       KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO,
                                 TO(4), KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,   TO(2)
  ),

/*  Layer 4 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             |             |             |             |   |             | QK_BOOT     | QK_REBOOT   |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   | KC_CALC     |             |             |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   |             |             |             |             |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_3(
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,      QK_BOOT,    QK_REBOOT,  KC_NO,     KC_NO,
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_CALC,    KC_NO,      KC_NO,      KC_NO,     KC_NO,
    KC_NO,      KC_NO,      KC_NO,       KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,
                                  TO(0), KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,   TO(3)
  )
};
