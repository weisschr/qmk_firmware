#include QMK_KEYBOARD_H

//-------------------------------------------------------------------------------

// Modifier defines to simplify mapping and combo references

// BASE

#define KC_LCTRL_F    MT(MOD_LCTL, KC_F)
#define KC_RCTRL_J    MT(MOD_RCTL, KC_J)
#define KC_LALT_V     MT(MOD_LALT, KC_V)
#define KC_RALT_M     MT(MOD_RALT, KC_M)
#define KC_LGUI_T     MT(MOD_LGUI, KC_T)
#define KC_RGUI_Y     MT(MOD_RGUI, KC_Y)

// DUO

#define KC_LSHCTRL_G  MT(MOD_LCTL | MOD_LSFT, KC_G)
#define KC_RSHCTRL_H  MT(MOD_RCTL | MOD_RSFT, KC_H)
#define KC_LSHALT_B   MT(MOD_LALT | MOD_LSFT, KC_B)
#define KC_RSHALT_N   MT(MOD_RALT | MOD_RSFT, KC_N)

#define KC_LCTRLALT_R MT(MOD_LCTL | MOD_LALT, KC_R)
#define KC_RCTRLALT_U MT(MOD_RCTL | MOD_RALT, KC_U)

// MEH

#define KC_LMEH_D     MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_D)
#define KC_RMEH_K     MT(MOD_RCTL | MOD_RALT | MOD_RSFT, KC_K)

// HYPER

#define KC_LHYPR_E    MT(MOD_LCTL | MOD_LALT | MOD_LSFT | MOD_LGUI, KC_E)
#define KC_RHYPR_I    MT(MOD_RCTL | MOD_RALT | MOD_RSFT | MOD_RGUI, KC_I)

//-------------------------------------------------------------------------------

enum layers {
  _ALPHA,
  _NUMBSYM,
  _FUNCTION,
  _MOUSE,
  _APPCONTROL,
  _NAV,
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
  TAB_ALPHA,
  BKSPC_MOUSE,
  CUSTOM_KEYCODE_LENGTH
};

enum combos {
    DOUBLEQ_COMBO,
    SINGLEQ_COMBO,
    LESC_COMBO,
    NAV_COMBO,
    NUMB_COMBO,
    FUNC_COMBO,
    APP_COMBO,
    ONESHOT_SYM_COMBO,
    ONESHOT_FUNC_COMBO,
    ONESHOT_APP_COMBO,
    ONESHOT_NAV_COMBO,
    DEL_COMBO,
    WINCLOSE_COMBO,
    APPCLOSE_COMBO,
    CAPLOCK_COMBO,
    CAPSWORD_COMBO,
    COMBO_LENGTH
};

//-------------------------------------------------------------------------------
// tapdances

tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRACE]     = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRACE]     = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_QUOTE]      = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
  [TD_SEMI]       = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
  [TD_BACKSLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
  [TD_EQUAL]      = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
  [TD_MINUS]      = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
  [TD_GRAVE]      = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
};

// end tapdances
//-------------------------------------------------------------------------------
// Layer 0 combos

// Quotes

const uint16_t PROGMEM doubleq_combo[]    = {KC_LMEH_D, KC_LCTRL_F, COMBO_END};
const uint16_t PROGMEM singleq_combo[]    = {KC_RCTRL_J, KC_RMEH_K, COMBO_END};

//-------------------------------------------------------------------------------
// Layer control combos

const uint16_t PROGMEM nav_combo[]        = {KC_RGUI_Y, KC_RCTRLALT_U,  COMBO_END};
const uint16_t PROGMEM osl_nav_combo[]    = {KC_RGUI_Y, HYPR_T(KC_I), COMBO_END};

const uint16_t PROGMEM numb_combo[]       = {KC_RSHCTRL_H,  KC_RCTRL_J, COMBO_END};
const uint16_t PROGMEM osl_numb_combo[]   = {KC_RSHCTRL_H,  KC_RMEH_K,  COMBO_END};

const uint16_t PROGMEM func_combo[]       = {KC_RSHALT_N,  KC_RALT_M, COMBO_END};
const uint16_t PROGMEM osl_func_combo[]   = {KC_RSHALT_N,  KC_COMM,      COMBO_END};

const uint16_t PROGMEM apps_combo[]       = {KC_RCTRLALT_U,  HYPR_T(KC_I), COMBO_END};
const uint16_t PROGMEM osl_apps_combo[]   = {KC_RCTRLALT_U,  KC_O,         COMBO_END};

//--------------------------------------------------------------------------------
// Behavioral combos

const uint16_t PROGMEM lesc_combo[]       = {KC_LCTRL_F, RCS_T(KC_G), COMBO_END};
const uint16_t PROGMEM winclose_combo[]   = {KC_LCTRLALT_R, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_LALT_V, KC_LSHALT_B, COMBO_END};

const uint16_t PROGMEM del_combo[]        = {KC_LMEH_D, RCS_T(KC_G), COMBO_END};
const uint16_t PROGMEM ins_combo[]        = {KC_C, KC_LSHALT_B, COMBO_END};

const uint16_t PROGMEM caplock_combo[]    = {KC_C, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM capsword_combo[]   = {KC_X, KC_LALT_V, COMBO_END};

// End layer 0 combo definitions
//--------------------------------------------------------------------------------
// Combo assignments

combo_t key_combos[] = {

[DOUBLEQ_COMBO]      = COMBO(doubleq_combo, KC_DQUO),
[SINGLEQ_COMBO]      = COMBO(singleq_combo, KC_QUOT),

//-------------------------------------------------------------------------------

[NAV_COMBO]          = COMBO(nav_combo, TO(_NAV)),
[NUMB_COMBO]         = COMBO(numb_combo, TO(_NUMBSYM)),
[FUNC_COMBO]         = COMBO(func_combo, TO(_FUNCTION)),
[APP_COMBO]          = COMBO(apps_combo, TO(_APPCONTROL)),
[ONESHOT_SYM_COMBO]  = COMBO(osl_numb_combo, OSL(_NUMBSYM)),
[ONESHOT_FUNC_COMBO] = COMBO(osl_func_combo, OSL(_FUNCTION)),
[ONESHOT_APP_COMBO]  = COMBO(osl_apps_combo, OSL(_APPCONTROL)),
[ONESHOT_NAV_COMBO]  = COMBO(osl_nav_combo, OSL(_NAV)),

//-------------------------------------------------------------------------------

[LESC_COMBO]         = COMBO(lesc_combo, KC_ESC),
[DEL_COMBO]          = COMBO(del_combo, KC_DEL),
[WINCLOSE_COMBO]     = COMBO(winclose_combo, LCTL(KC_F4)),
[APPCLOSE_COMBO]     = COMBO(appclose_combo, LALT(KC_F4)),

//-------------------------------------------------------------------------------

[CAPLOCK_COMBO]      = COMBO(caplock_combo,KC_CAPS),
[CAPSWORD_COMBO]     = COMBO(capsword_combo,CW_TOGG),
};

// end combos
//-------------------------------------------------------------------------------

// Functions

static uint16_t key_timer_default;
static uint16_t key_timer_mouse;

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
        case RSFT_T(KC_ENTER):
            // Immediately select the hold action when another key is pressed.
             return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {

  switch (index) {
        case APP_COMBO:
        case NAV_COMBO:
        case FUNC_COMBO:
        case NUMB_COMBO:
            return 200;
        case ONESHOT_APP_COMBO:
        case ONESHOT_FUNC_COMBO:
        case ONESHOT_NAV_COMBO:
        case ONESHOT_SYM_COMBO:
            return 75;
      default:
        return COMBO_TERM;
    }

}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

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

    // Mod tap modification - BILATERAL MODIFIER KEYS SET
    
    case KC_Q:
    case KC_W:
    case KC_LHYPR_E:
    case KC_LCTRLALT_R:      
    case KC_LGUI_T:
    case KC_A:  
    case KC_S:   
    case KC_LMEH_D:  
    case KC_LCTRL_F:     
    case RCS_T(KC_G):
    case KC_Z:
    case KC_X:
    case KC_C:
    case KC_LALT_V:
    case KC_LSHALT_B:
      if (record->event.pressed) {
        if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI) ) ) {
          clear_mods(); // Remove MODS
          tap_code(keycode); // Send UN-MOD key
          return false; // Skip default processing
          }
      }
      return true;

    case KC_RGUI_Y:
    case KC_RCTRLALT_U:
    case HYPR_T(KC_I):
    case KC_O:  
    case KC_P:   
    case KC_RSHCTRL_H:  
    case KC_RCTRL_J:     
    case KC_RMEH_K:
    case KC_L:
    case KC_SCLN:
    case KC_RSHALT_N:
    case KC_RALT_M:
    case KC_COMM:
    case KC_DOT:
    case KC_SLSH:
      if (record->event.pressed) {
        if (get_mods() & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RGUI) ) ) {
          clear_mods(); // Remove MODS
          tap_code(keycode); // Send UN-MOD key
          return false; // Skip default processing
          }
      }
      return true;

    default:
      return true; // Process all other keycodes normally.
  }
}

//-------------------------------------------------------------------------------
// begin layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Layer 0 Alpha
*   _____________________________________________________________________     _____________________________________________________________________
*  |      Q      |      W      |  E-HYPR     | R-ctrlalt   | T-gui       |   |  Y-gui      | U-ctrltalt  |   I-HYPR    |      O      |      P      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      S      |  D-MEH      | F-ctrl      | G-ctrlshift |   | H-ctrlshift |  J-ctrl     |   K-MEH     |      L      |      ;:     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      | V-alt       | B-SHALT     |   |   N-SHALT   |  M-ALT      |      ,<     |      .>     |      /?     |
*  '-----------------------------------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | SPACE       | TAB         |   | BACKSPACE   | ENTER       |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_2(
    KC_Q,  KC_W,   KC_LHYPR_E, KC_LCTRLALT_R,    KC_LGUI_T,        KC_RGUI_Y,     KC_RCTRLALT_U,    KC_RHYPR_I,   KC_O,    KC_P,
    KC_A,  KC_S,   KC_LMEH_D,  KC_LCTRL_F,       KC_LSHCTRL_G,     KC_RSHCTRL_H,  KC_RCTRL_J,       KC_RMEH_K,    KC_L,    KC_SCLN,
    KC_Z,  KC_X,   KC_C,       KC_LALT_V,        KC_LSHALT_B,      KC_RSHALT_N,   KC_RALT_M,        KC_COMM,      KC_DOT,  KC_SLSH,
                               LSFT_T(KC_SPACE), TAB_ALPHA,        BKSPC_MOUSE,   RSFT_T(KC_ENTER)
  ),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      ` ~    |      +      |      =      |      -      |      _      |   |      "      |      '      |      \ |    |      [ {    |     ] }     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_2(
    KC_EXLM,      KC_AT,   KC_HASH,       KC_DLR,        KC_PERC,         KC_CIRC,  KC_AMPR,      KC_ASTR,          KC_LEFT_PAREN,  KC_RIGHT_PAREN,
    KC_1,         KC_2,    KC_3,          KC_4,          KC_5,            KC_6,     KC_7,         KC_8,             KC_9,          KC_0,
    TD(TD_GRAVE), KC_PLUS, TD(TD_EQUAL),  TD(TD_MINUS),  KC_UNDS,         KC_DQUO,  TD(TD_QUOTE), TD(TD_BACKSLASH), TD(TD_LBRACE), TD(TD_RBRACE),
                                          KC_TRNS,       KC_TRNS,         KC_TRNS,  KC_TRNS
  ),

/*  Layer 2 Function
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             |             |             |      F11    |   |      F12    |             |             |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |   GUI       |    ALT      |  CTRL       |  MEH        |   | HYPER       | CTRL        | ALT         | GUI         |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_2(
    KC_NO,   KC_NO,   KC_NO,      TO(_MOUSE),     KC_F11,      KC_F12,    TO(_NUMBSYM),    KC_NO,     KC_NO,     KC_NO,
    KC_F1,   KC_F2,   KC_F3,      KC_F4,     KC_F5,       KC_F6,     KC_F7,    KC_F8,     KC_F9,     KC_F10,
    KC_NO,   KC_LGUI, KC_LALT,    KC_LCTL,   KC_MEH,      KC_HYPR,   KC_RCTL,  KC_RALT,   KC_RGUI,   KC_NO,
                                  KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS
  ),

/*  Layer 3 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | WWWBACK     | NEW-TAB     | KC_VOLD     | KC_MUTE     | KC_VOLU     |   | HOME-SHIFT  | PGUP        | MOUSE UP    | PGDN        | WWWSEARCH   |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWFWD      | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| UP          |   | END-CTRL    | MOUSE LEFT  | MOUSE DOWN  | MOUSE RIGHT | WWWREFRESH  |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | WWWHOME     | NEW-WIN     | LEFT        | RIGHT       | DOWN        |   | WHEEL LEFT  | WHEEL UP    | WHEEL DOWN  | WHEEL RIGHT | WWWSTOP     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_2(
    KC_WBAK,   C(KC_T),     KC_VOLD,          KC_MUTE,    KC_VOLU,      RSFT_T(KC_HOME), KC_PGUP,     KC_MS_UP,      KC_PGDN,        KC_WSCH,
    KC_WFWD,   KC_MS_BTN1,  KC_MS_BTN3,       KC_MS_BTN2, KC_UP,        RCTL_T(KC_END),  KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_RIGHT,    KC_WREF,
    KC_WHOM,   C(KC_N),     KC_LEFT,          KC_RIGHT,   KC_DOWN,      KC_MS_WH_LEFT,   KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_WSTP,
                                              KC_TRNS,    KC_TRNS,      KC_TRNS,         KC_TRNS
  ),

/*  Layer 4 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LINKEDIN    | OUTLOOK     | TEAMS       |   | FILEMNGR    | QK_BOOT     | QK_REBOOT   |  WAKEUP     |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             | POWERPOINT  | WORD        |   | KC_CALC     | TASK        | RUN         |  POWEROFF   |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             | EMOJIS      | EXCEL       |   | SNIP        | CLIPBOARD   | MYCOMPUTER  |  SLEEP      |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_2(
    KC_NO,      KC_NO,   HYPR_T(KC_L), HYPR_T(KC_O),   HYPR_T(KC_T),     RGUI(KC_E),  QK_BOOT,     QK_REBOOT,  KC_WAKE,    KC_NO,
    KC_NO,      KC_NO,   KC_NO,        HYPR_T(KC_P),   HYPR_T(KC_W),     KC_CALC,     RCS(KC_ESC), RGUI(KC_R), KC_PWR,     KC_NO,
    KC_NO,      KC_NO,   KC_NO,        LGUI(KC_DOT),   HYPR_T(KC_X),     SGUI(KC_S),  RGUI(KC_V),  KC_MYCM,    KC_SLEP,    KC_NO,
                                       KC_TRNS,        KC_TRNS,          KC_TRNS,     KC_TRNS
  ),

/*  Layer 5 Nav
*   _____________________________________________________________________     _____________________________________________________________________
*  | KC_TRNS     | KC_TRNS     | KC_TRNS     | HOME        | KC_TRNS     |   | KC_TRNS     | PGUP        | KC_TRNS     | KC_TRNS     | KC_TRNS     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | KC_TRNS     | KC_TRNS     | LEFT        | RIGHT       | KC_TRNS     |   | KC_TRNS     | UP          | DOWN        | KC_TRNS     | KC_TRNS     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | KC_TRNS     | KC_TRNS     | KC_TRNS     | END         | KC_TRNS     |   | KC_TRNS     | PGDN        | KC_TRNS     | KC_TRNS     | KC_TRNS     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     | MOUSE       |
*                                            |_____________|_____________|   |_____________|_____________|_____________|
*/

 [_NAV] = LAYOUT_split_3x5_2(
    KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_HOME,     KC_TRNS,       KC_TRNS,     KC_PGUP,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,     KC_TRNS,     KC_LEFT,       KC_RIGHT,    KC_TRNS,       KC_TRNS,     KC_UP,       KC_DOWN,     KC_TRNS,     KC_TRNS,
    KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_END,      KC_TRNS,       KC_TRNS,     KC_PGDN,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                                             KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS
  )
};

//-------------------------------------------------------------------------------



