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
  TD_LBRACE,
  TD_RBRACE,
  TD_QUOTE,
  TD_SEMI,
  TD_BACKSLASH,
  TD_EQUAL,
  TD_MINUS,
  TD_COMMA,
  TD_DOT,
  TD_SLASH,
  TD_GRAVE,
  TAPDANCE_LENGTH
};

enum custom_keycodes {
  SPACE_SHIFT,
  ENTER_SHIFT,
  TAB_ALPHA,
  BKSPC_MOUSE,
  CUSTOM_KEYCODE_LENGTH
};

enum combos {
    LARROW_COMBO,
    RARROW_COMBO,
    UARROW_COMBO,
    DARROW_COMBO,
    LESC_COMBO,
    RESC_COMBO,
    DEL_COMBO,
    INS_COMBO,
    WINCLOSE_COMBO,
    APPCLOSE_COMBO,
    CAPLOCK_COMBO,
    CAPSWORD_COMBO,
    ONESHOT_SYM_COMBO,
    ONESHOT_FUNC_COMBO,
    ONESHOT_APP_COMBO,
    COMBO_LENGTH
};

// tapdances
tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRACE]    = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRACE]    = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_QUOTE]     = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
  [TD_SEMI]      = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
  [TD_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
  [TD_EQUAL]     = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
  [TD_MINUS]     = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
  [TD_COMMA]     = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_LT),
  [TD_DOT]       = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_GT),
  [TD_SLASH]     = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUES),
  [TD_GRAVE]     = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
};
// end tapdances

// Layer 0 combos

// Need to test if shift-enter and control-enter still work

const uint16_t PROGMEM larrow_combo[]      = {LALT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM rarrow_combo[]      = {RCTL_T(KC_J), RALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM darrow_combo[]      = {LGUI_T(KC_S),  LALT_T(KC_D), COMBO_END};
const uint16_t PROGMEM uarrow_combo[]      = {RALT_T(KC_K), RGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM lesc_combo[]       = {LCTL_T(KC_F), RCS_T(KC_G), COMBO_END};
const uint16_t PROGMEM resc_combo[]       = {RCS_T(KC_H), RCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM del_combo[]        = {MEH_T(KC_Y), RSA_T(KC_U), COMBO_END};
const uint16_t PROGMEM ins_combo[]        = {HYPR_T(KC_N), KC_M, COMBO_END};
const uint16_t PROGMEM winclose_combo[]   = {LSA_T(KC_R), MEH_T(KC_T), COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_V, HYPR_T(KC_B), COMBO_END};
const uint16_t PROGMEM caplock_combo[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM osl_sym_combo[]    = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM osl_func_combo[]   = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM osl_aspp_combo[]   = {KC_X, KC_V, COMBO_END};

/*

Add combos for ' " and arrows

*/

// layer 0 combos
combo_t key_combos[] = {  
[LARROW_COMBO] =	  	 COMBO(larrow_combo, KC_LEFT),
[RARROW_COMBO] =       COMBO(rarrow_combo, KC_RIGHT),
[UARROW_COMBO] =	  	 COMBO(uarrow_combo, KC_UP),
[DARROW_COMBO] =       COMBO(darrow_combo, KC_DOWN),
[LESC_COMBO] =         COMBO(lesc_combo, KC_ESC),
[RESC_COMBO] =         COMBO(resc_combo, KC_ESC),
[DEL_COMBO] =          COMBO(del_combo, KC_DEL),
[INS_COMBO] =          COMBO(ins_combo, KC_INS),
[WINCLOSE_COMBO] =     COMBO(winclose_combo, LCTL(KC_F4)),
[APPCLOSE_COMBO] =     COMBO(appclose_combo, LALT(KC_F4)),
[CAPLOCK_COMBO] =      COMBO(caplock_combo,KC_CAPS),
[ONESHOT_SYM_COMBO] =  COMBO(osl_sym_combo, OSL(_NUMBSYM)),
[ONESHOT_FUNC_COMBO] = COMBO(osl_func_combo, OSL(_FUNCTION)),
[ONESHOT_APP_COMBO] =  COMBO(osl_aspp_combo, OSL(_APPCONTROL)),
};
// end combos

static bool space_shift_active = false;
static bool enter_shift_active = false;
static bool space_shift_held = false;
static bool enter_shift_held = false;
static uint16_t key_timer_default;
static uint16_t key_timer_mouse;

void handle_custom_shift(keyrecord_t *record, bool *custom_shift_held, bool *shift_active, uint16_t kc) {
  if (record->event.pressed) {
    *custom_shift_held = true;
  } else {
    *custom_shift_held = false;
    if (*shift_active) {
      unregister_code(KC_LSFT);
      *shift_active = false;
    } else {
      tap_code(kc);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SPACE_SHIFT:
      handle_custom_shift(record, &space_shift_held, &space_shift_active, KC_SPACE);
      return false;

    case ENTER_SHIFT:
      handle_custom_shift(record, &enter_shift_held, &enter_shift_active, KC_ENT);
      return false;

    case TAB_ALPHA:
      if (record->event.pressed) {
        key_timer_default = timer_read(); // Start the timer on key press.
      } else {
        if (timer_elapsed(key_timer_default) < TAPPING_TERM) { // Key was tapped.
          tap_code(KC_TAB);
        } else { // Key was held.
          layer_move(_ALPHA);
        }
      }
      return false;

    case BKSPC_MOUSE:
      if (record->event.pressed) {
        key_timer_mouse = timer_read(); // Start the timer when the key is pressed.
      } else {
        if (timer_elapsed(key_timer_mouse) < TAPPING_TERM) { // The key was tapped.
          tap_code(KC_BSPC);
        } else { // The key was held.
          layer_move(_MOUSE);
        }
      }
      return false;

    default:
      if (record->event.pressed) {
        if (space_shift_held && !space_shift_active) {
          register_code(KC_LSFT);
          space_shift_active = true;
        }
        if (enter_shift_held && !enter_shift_active) {
          register_code(KC_LSFT);
          enter_shift_active = true;
        }
      }

      return true; // Process all other keycodes normally.
  }
}

// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Layer 0 Alpha
*   _____________________________________________________________________     _____________________________________________________________________
*  |      Q      |      W      |      E      | R-shiftalt  | T-MEh       |   |      Y-Meh  | U-shiftalt  |      I      |      O      |      P      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      S-gui  |   D -alt    | F-ctrl      | G-ctrlshift |   | H-ctrlshift |      J-ctrl |      K-alt  |      L-gui  |      ;      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      |      V      | B-Hypr      |   |   N-Hypr    |      M      |      ,      |      .      |      /      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER-1   | SPACE       | TAB         |   | BACKSPACE   | ENTER       | DOWNLAYER-4 |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_3(
    KC_Q,  KC_W,          KC_E,         LSA_T(KC_R),   MEH_T(KC_T),      MEH_T(KC_Y),  RSA_T(KC_U),  KC_I,         KC_O,         KC_P,
    KC_A,  LGUI_T(KC_S),  LALT_T(KC_D), LCTL_T(KC_F),  RCS_T(KC_G),      RCS_T(KC_H),  RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), KC_SCLN,
    KC_Z,  KC_X,          KC_C,         KC_V,          HYPR_T(KC_B),     HYPR_T(KC_N), KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                          TO(_NUMBSYM), SPACE_SHIFT,   TAB_ALPHA,        BKSPC_MOUSE,  ENTER_SHIFT,  TO(_APPCONTROL)
  ),

/*  Layer 1 Symbol

*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      ` ~    |      +      |      =      |      -      |      _      |   |      "      |      '      |      \ |    |      [ {    |     ] }     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_3(
    KC_EXLM,      KC_AT,   KC_HASH,       KC_DLR,    KC_PERC,         KC_CIRC,  KC_AMPR,   KC_ASTR,         KC_LEFT_PAREN,  KC_RIGHT_PAREN,
    KC_1,         KC_2,    KC_3,          KC_4,      KC_5,            KC_6,     KC_7,      KC_8,             KC_9,          KC_0,
    TD(TD_GRAVE), KC_PLUS, KC_EQUAL,      KC_MINUS,  KC_UNDS,         KC_DQUO,  KC_QUOTE,  TD(TD_BACKSLASH), TD(TD_LBRACE), TD(TD_RBRACE),
                           TO(_FUNCTION), KC_TRNS,   KC_TRNS,         KC_TRNS,  KC_TRNS,   TO(_ALPHA)
  ),

/*  Layer 2 Function

--- This needs more thought
*   _____________________________________________________________________     _____________________________________________________________________
*  |  END        |  HOME       | LEFT        | RIGHT       |      F11    |   |      F12    |  UP         | DOWN        |   PGUP      |  PGDN       |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  GUI        | ALT         | CTRL        | SHIFT       |  MEH        |   | HYPER       | SHIFT       | CTRL        | ALT         | GUI  .      |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_3(
    KC_END,  KC_HOME, KC_LEFT,    KC_RIGHT,  KC_F11,      KC_F12,    KC_UP,    KC_DOWN,   KC_PGUP,   KC_PGDN,
    KC_F1,   KC_F2,   KC_F3,      KC_F4,     KC_F5,       KC_F6,     KC_F7,    KC_F8,     KC_F9,   KC_F10,
    KC_LGUI, KC_LALT, KC_LCTL,    KC_LSFT,   KC_MEH,      KC_HYPR,   KC_RSFT,  KC_RCTL,   KC_RALT, KC_RGUI,
                      TO(_MOUSE), KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,  TO(_NUMBSYM)
  ),

/*  Layer 3 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | WWWBACK     | NEW-TAB     | KC_VOLD     | KC_MUTE     | KC_VOLU     |   | HOME-SHIFT  | PGUP        | MOUSE UP    | PGDN        | WWWSEARCH   |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWFWD      | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| UP          |   | END-CTRL    | MOUSE LEFT  | MOUSE DOWN  | MOUSE RIGHT | WWWREFRESH  |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWHOME     | NEW-WIN     | LEFT        | RIGHT       | DOWN        |   | WHEEL LEFT  | WHEEL UP    | WHEEL DOWN  | WHEEL RIGHT | WWWSTOP     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_3(
    KC_WBAK,   C(KC_T),     KC_VOLD,          KC_MUTE,    KC_VOLU,      RSFT_T(KC_HOME), KC_PGUP,     KC_MS_UP,      KC_PGDN,        KC_WSCH,
    KC_WFWD,   KC_MS_BTN1,  KC_MS_BTN3,       KC_MS_BTN2, KC_UP,        RCTL_T(KC_END),  KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_RIGHT,    KC_WREF,
    KC_WHOM,   C(KC_N),     KC_LEFT,          KC_RIGHT,   KC_DOWN,      KC_MS_WH_LEFT,   KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_WSTP,
                            TO(_APPCONTROL),  KC_TRNS,    KC_TRNS,      KC_TRNS,         KC_TRNS,     TO(_FUNCTION)
  ),

/*  Layer 4 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LINKEDIN    | OUTLOOK     | TEAMS       |   | FILEMNGR    | QK_BOOT     | QK_REBOOT   |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             | POWERPOINT  | WORD        |   | KC_CALC     | TASK        | RUN         |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             | EMOJIS      | EXCEL       |   | SNIP        | CLIPBOARD   |             |             |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              | UPLAYER     | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | DOWNLAYER   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_3(
    KC_NO,      KC_NO,   HYPR_T(KC_L), HYPR_T(KC_O),   HYPR_T(KC_T),     RGUI(KC_E),  QK_BOOT,     QK_REBOOT,  KC_NO,     KC_NO,
    KC_NO,      KC_NO,   KC_NO,        HYPR_T(KC_P),   HYPR_T(KC_W),     KC_CALC,     RCS(KC_ESC), RGUI(KC_R), KC_NO,     KC_NO,
    KC_NO,      KC_NO,   KC_NO,        LGUI(KC_DOT),   HYPR_T(KC_X),     SGUI(KC_S),  RGUI(KC_V),  KC_NO,      KC_NO,     KC_NO,
                         TO(_ALPHA),   KC_TRNS,        KC_TRNS,          KC_TRNS,     KC_TRNS,     TO(_MOUSE)
  )
};
