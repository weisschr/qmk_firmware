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

// APPS Mapping

#define KA_LINKEDIN HYPR(KC_L)
#define KA_OUTLOOK  HYPR(KC_O)
#define KA_TEAMS    HYPR(KC_T)
#define KA_FILEMGR  RGUI(KC_E)
#define KA_POWERPT  HYPR(KC_P)
#define KA_WORD     HYPR(KC_W)
#define KA_TASKMGR  RCS(KC_ESC)
#define KA_RUN      RGUI(KC_R)
#define KA_EMOJIS   LGUI(KC_DOT)
#define KA_EXCEL    HYPR(KC_X)
#define KA_SNIP     SGUI(KC_S)
#define KA_CLIPBRD  RGUI(KC_V)

//-------------------------------------------------------------------------------

enum layers {
  _ALPHA,
  _NUMBSYM,
  _FUNCTION,
  _APPCONTROL,
  _MOUSE,
  LAYER_LENGTH
};

enum combos {
    DOUBLEQ_COMBO,
    SINGLEQ_COMBO,
    LPAR_COMBO,
    RPAR_COMBO,
    LBRACE_COMBO,
    RBRACE_COMBO,
    LCURLY_COMBO,
    RCURLY_COMBO,
    LESC_COMBO,
    DEFAULT_COMBO,
    MOUSE_COMBO,
    NUMB_COMBO,
    FUNC_COMBO,
    APP_COMBO,
    ONESHOT_SYM_COMBO,
    ONESHOT_FUNC_COMBO,
    ONESHOT_APP_COMBO,
    DEL_COMBO,
    WINCLOSE_COMBO,
    APPCLOSE_COMBO,
    CAPLOCK_COMBO,
    CAPSWORD_COMBO,
    LEFTARROW_COMBO,
    RIGHTARROW_COMBO,
    UPARROW_COMBO,
    DOWNARROW_COMBO,
    PAGEUP_COMBO,
    PAGEDN_COMBO,
    HOME_COMBO,
    END_COMBO,
    COMBO_LENGTH
};

enum custom_keycodes {
    BROWSWEROPEN = SAFE_RANGE,
    CONTROLPAN,
    MYCOMPUTER,
};

//-------------------------------------------------------------------------------
// Layer 0 combos

// Characters

const uint16_t PROGMEM doubleq_combo[]  = {KC_LMEH_D, KC_LCTRL_F, COMBO_END};
const uint16_t PROGMEM singleq_combo[]  = {KC_RCTRL_J, KC_RMEH_K, COMBO_END};
const uint16_t PROGMEM lpar_combo[]     = {KC_C, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rpar_combo[]     = {KC_RALT_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM lbrace_combo[]   = {KC_X, KC_C, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rbrace_combo[]   = {KC_RALT_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM lcurly_combo[]   = {KC_X, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rcurly_combo[]   = {KC_RALT_M, KC_DOT, COMBO_END};

//-------------------------------------------------------------------------------
// Layer control combos

const uint16_t PROGMEM apps_combo[]     = {KC_RGUI_Y, KC_RCTRLALT_U, KC_RHYPR_I, COMBO_END};
const uint16_t PROGMEM osl_apps_combo[] = {KC_RGUI_Y, KC_RHYPR_I, COMBO_END};

const uint16_t PROGMEM numb_combo[]     = {KC_RSHCTRL_H, KC_RCTRL_J, KC_RMEH_K, COMBO_END};
const uint16_t PROGMEM osl_numb_combo[] = {KC_RSHCTRL_H, KC_RMEH_K, COMBO_END};

const uint16_t PROGMEM func_combo[]     = {KC_RSHALT_N, KC_RALT_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM osl_func_combo[] = {KC_RSHALT_N, KC_COMM, COMBO_END};

const uint16_t PROGMEM default_combo[]     = {KC_RCTRL_J, KC_RMEH_K, KC_L, COMBO_END};

const uint16_t PROGMEM mouse_combo[]       = {KC_W, KC_LHYPR_E,  KC_LCTRLALT_R, KC_LGUI_T, COMBO_END};


//--------------------------------------------------------------------------------
// Behavioral combos

const uint16_t PROGMEM lesc_combo[]       = {KC_LCTRL_F, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM winclose_combo[]   = {KC_LCTRLALT_R, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_LALT_V, KC_LSHALT_B, COMBO_END};

const uint16_t PROGMEM del_combo[]        = {KC_LMEH_D, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM ins_combo[]        = {KC_LHYPR_E, KC_LGUI_T, COMBO_END};

const uint16_t PROGMEM caplock_combo[]    = {KC_Z, KC_X, KC_C,  COMBO_END};
const uint16_t PROGMEM capsword_combo[]   = {KC_C, KC_LSHALT_B, COMBO_END};

const uint16_t PROGMEM leftarrow_combo[]  = {KC_LMEH_D, KC_LCTRL_F, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM rightarrow_combo[] = {KC_LHYPR_E, KC_LCTRLALT_R, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM uparrow_combo[]    = {KC_W, KC_LHYPR_E, KC_LCTRLALT_R, COMBO_END};
const uint16_t PROGMEM downarrow_combo[]  = {KC_S, KC_LMEH_D, KC_LCTRL_F, COMBO_END};

const uint16_t PROGMEM pageup_combo[]     = {KC_LCTRL_F, KC_RCTRL_J, COMBO_END};
const uint16_t PROGMEM pagedn_combo[]     = {KC_LALT_V, KC_RALT_M, COMBO_END};
const uint16_t PROGMEM home_combo[]       = {KC_LSHCTRL_G, KC_RSHCTRL_H, COMBO_END};
const uint16_t PROGMEM end_combo[]        = {KC_LSHALT_B, KC_RSHALT_N, COMBO_END};

const uint16_t PROGMEM teams_mute[]       = {KC_LCTRLALT_R, KC_RCTRLALT_U, COMBO_END};
const uint16_t PROGMEM teams_vidtog[]     = {KC_LGUI_T, KC_RGUI_Y, COMBO_END};

// End layer 0 combo definitions
//--------------------------------------------------------------------------------
// Combo assignments

combo_t key_combos[] = {

[DOUBLEQ_COMBO]      = COMBO(doubleq_combo, KC_DQUO),
[SINGLEQ_COMBO]      = COMBO(singleq_combo, KC_QUOT),
[LPAR_COMBO]         = COMBO(lpar_combo, KC_LPRN),
[RPAR_COMBO]         = COMBO(rpar_combo, KC_RPRN),
[LBRACE_COMBO]       = COMBO(lbrace_combo, KC_LBRC),
[RBRACE_COMBO]       = COMBO(rbrace_combo, KC_RBRC),
[LCURLY_COMBO]       = COMBO(lcurly_combo, KC_LCBR),
[RCURLY_COMBO]       = COMBO(rcurly_combo, KC_RCBR),

//-------------------------------------------------------------------------------

[APP_COMBO]          = COMBO(apps_combo, TG(_APPCONTROL)),
[NUMB_COMBO]         = COMBO(numb_combo, TG(_NUMBSYM)),
[FUNC_COMBO]         = COMBO(func_combo, TG(_FUNCTION)),
[ONESHOT_SYM_COMBO]  = COMBO(osl_numb_combo, OSL(_NUMBSYM)),
[ONESHOT_FUNC_COMBO] = COMBO(osl_func_combo, OSL(_FUNCTION)),
[ONESHOT_APP_COMBO]  = COMBO(osl_apps_combo, OSL(_APPCONTROL)),
[DEFAULT_COMBO]      = COMBO(default_combo, TO(_ALPHA)),
[MOUSE_COMBO]        = COMBO(mouse_combo, TG(_MOUSE)),

//-------------------------------------------------------------------------------

[LESC_COMBO]         = COMBO(lesc_combo, KC_ESC),
[DEL_COMBO]          = COMBO(del_combo, KC_DEL),
[WINCLOSE_COMBO]     = COMBO(winclose_combo, LCTL(KC_F4)),
[APPCLOSE_COMBO]     = COMBO(appclose_combo, LALT(KC_F4)),
[LEFTARROW_COMBO]    = COMBO(leftarrow_combo,KC_LEFT),
[RIGHTARROW_COMBO]   = COMBO(rightarrow_combo,KC_RIGHT),
[UPARROW_COMBO]      = COMBO(uparrow_combo, KC_UP),
[DOWNARROW_COMBO]    = COMBO(downarrow_combo, KC_DOWN),
[PAGEUP_COMBO]       = COMBO(pageup_combo, KC_PGUP),
[PAGEDN_COMBO]       = COMBO(pagedn_combo, KC_PGDN),
[HOME_COMBO]         = COMBO(home_combo, KC_HOME),
[END_COMBO]          = COMBO(end_combo, KC_END),

//-------------------------------------------------------------------------------

[CAPLOCK_COMBO]      = COMBO(caplock_combo, KC_CAPS),
[CAPSWORD_COMBO]     = COMBO(capsword_combo, CW_TOGG),
};

// end combos
//-------------------------------------------------------------------------------

// Functions

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
      case FUNC_COMBO:
      case NUMB_COMBO:
      case ONESHOT_APP_COMBO:
      case ONESHOT_FUNC_COMBO:
      case ONESHOT_SYM_COMBO:
      case MOUSE_COMBO:
        return 400;
      case WINCLOSE_COMBO:
      case APPCLOSE_COMBO:
        return 300;
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RALT_M:
        case KC_LALT_V:
            return 500;
        case KC_LHYPR_E:
        case KC_LMEH_D:
        case KC_LGUI_T:
            return 600;
        case KC_RHYPR_I:
        case KC_RMEH_K:
        case KC_RGUI_Y:
            return 750;
        default:
            return TAPPING_TERM;
    }
}

bool check_left_mods(uint16_t keycode, keyrecord_t *record){
  static uint8_t mod_state;
  if(layer_state_is(_APPCONTROL)) {
    return false;
  }
  mod_state = get_mods();
  if (record->event.pressed) {
    if ((mod_state == MOD_BIT(KC_LSFT)) || (mod_state == MOD_BIT(KC_LCTL)) || (mod_state == MOD_BIT(KC_LALT)) || (mod_state == MOD_BIT(KC_LGUI) )
       || (mod_state == (MOD_LCTL | MOD_LSFT ))
       || (mod_state == (MOD_LCTL | MOD_LALT ))
       || (mod_state == (MOD_LALT | MOD_LSFT ))
       || (mod_state == (MOD_LCTL | MOD_LALT | MOD_LSFT | MOD_LGUI))
       || (mod_state == (MOD_LCTL | MOD_LALT | MOD_LSFT))) {
      clear_mods();
      tap_code(keycode);
      return false;
    }
  }
  return true;
}

bool check_right_mods(uint16_t keycode, keyrecord_t *record){
  static uint8_t r_mod_state;
  if(layer_state_is(_APPCONTROL)) {
    return false;
  }
  r_mod_state = get_mods();
  if (record->event.pressed) {
    if ((r_mod_state == MOD_BIT(KC_RSFT)) || (r_mod_state == MOD_BIT(KC_RCTL)) || (r_mod_state == MOD_BIT(KC_RALT)) || (r_mod_state == MOD_BIT(KC_RGUI) )
       || (r_mod_state == (MOD_RCTL | MOD_RALT ))
       || (r_mod_state == (MOD_RCTL | MOD_RSFT ))
       || (r_mod_state == (MOD_RALT | MOD_RSFT ))
       || (r_mod_state == (MOD_RCTL | MOD_RALT | MOD_RSFT | MOD_RGUI))
       || (r_mod_state == (MOD_RCTL | MOD_RALT | MOD_RSFT))) {
      clear_mods();
      tap_code(keycode);
      return false;
    }
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Mod tap modification - BILATERAL MODIFIER KEYS SET

    case LSFT_T(KC_SPACE):
    case KC_Q:
    case KC_W:
    case KC_LHYPR_E:
    case KC_LCTRLALT_R:
    case KC_LGUI_T:
    case KC_A:
    case KC_S:
    case KC_LMEH_D:
    case KC_LCTRL_F:
    case KC_LSHCTRL_G:
    case KC_Z:
    case KC_X:
    case KC_C:
    case KC_LALT_V:
    case KC_LSHALT_B:
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_0:
      return check_left_mods(keycode, record);

    case RSFT_T(KC_ENTER):
    case KC_RGUI_Y:
    case KC_RCTRLALT_U:
    case KC_RHYPR_I:
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
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
      return check_right_mods(keycode, record);
    case BROWSWEROPEN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_R));
            SEND_STRING(SS_UP(X_LGUI));
            SEND_STRING("CHROME\n");
        }
        break;
    case CONTROLPAN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_R));
            SEND_STRING(SS_UP(X_LGUI));
            SEND_STRING("CONTROL\n");
        }
        break;
    case MYCOMPUTER:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_R));
            SEND_STRING(SS_UP(X_LGUI));
            SEND_STRING("SHELL:MyComputerFolder\n");
        }
        break;
    default:
      return true; // Process all other keycodes normally.
  }
  return true;
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
*                                            | TAB         |  SPACE      |   | ENTER       | BACKSPACE   |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_2(
    KC_Q,  KC_W,   KC_LHYPR_E, KC_LCTRLALT_R, KC_LGUI_T,        /*-*/ KC_RGUI_Y,          KC_RCTRLALT_U,    KC_RHYPR_I,   KC_O,    KC_P,
    KC_A,  KC_S,   KC_LMEH_D,  KC_LCTRL_F,    KC_LSHCTRL_G,     /*-*/ KC_RSHCTRL_H,       KC_RCTRL_J,       KC_RMEH_K,    KC_L,    KC_SCLN,
    KC_Z,  KC_X,   KC_C,       KC_LALT_V,     KC_LSHALT_B,      /*-*/ KC_RSHALT_N,        KC_RALT_M,        KC_COMM,      KC_DOT,  KC_SLSH,
                               KC_TAB,        LSFT_T(KC_SPACE), /*-*/ RSFT_T(KC_ENTER),   KC_BSPC
  ),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      ` ~    |      \ |    |      =+     |      -      |      _      |   |     ' "     |     ;:      |      , <    |      . >    |     / ?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_2(
    KC_EXLM,      KC_AT,            KC_HASH,       KC_DLR,        KC_PERC, /*-*/ KC_CIRC,      KC_AMPR,      KC_ASTR,   KC_LPRN,        KC_RPRN,
    KC_1,         KC_2,             KC_3,          KC_4,          KC_5,    /*-*/ KC_6,         KC_7,         KC_8,      KC_9,           KC_0,
    KC_GRV,       KC_BSLS,          KC_EQL,        KC_MINS,       KC_UNDS, /*-*/ KC_QUOT,      KC_SCLN,      KC_TRNS,   KC_TRNS,        KC_TRNS,
                                                   KC_TRNS,       KC_TRNS, /*-*/ KC_TRNS,      KC_TRNS
  ),

/*  Layer 2 Function
*   _____________________________________________________________________     _____________________________________________________________________
*  |  Play/pause |  Stop       |  Next       | Previous    |      F11    |   |      F12    |  Mute       | Vol Up      | Vol Dn      |  Lock       |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |ctrl-alt-del |      GUI    |      ALT    |      CTRL   |      MEH    |   |      HYPER  |      CTRL   |      ALT    |      GUI    |ctrl-alt-del |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            |   KC_TRNS   |   KC_TRNS   |   |   KC_TRNS   |   KC_TRNS   |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_2(
    KC_MPLY,      KC_MSTP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_F11,  /*-*/  KC_F12,    KC_KB_MUTE, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, RGUI(KC_L),
    KC_F1,        KC_F2,   KC_F3,               KC_F4,               KC_F5,   /*-*/  KC_F6,     KC_F7,      KC_F8,           KC_F9,             KC_F10,
    C(A(KC_DEL)), KC_LGUI, KC_LALT,             KC_LCTL,             KC_MEH,  /*-*/  KC_HYPR,   KC_RCTL,    KC_RALT,         KC_RGUI,           C(A(KC_DEL)),
                                                KC_TRNS,             KC_TRNS, /*-*/  KC_TRNS,   KC_TRNS
  ),

/*  Layer 3 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LINKEDIN    | OUTLOOK     | TEAMS       |   | FILEMNGR    | bright up   | bright dn   |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  QK_BOOT    |             | Controlpanel| POWERPOINT  | WORD        |   | KC_CALC     | TASK        | RUN         |             |  QK_BOOT    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  QK_REBOOT  |             | Browser     | EMOJIS      | EXCEL       |   | SNIP        | CLIPBOARD   | MYCOMPUTER  |             |  QK_REBOOT  |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-----------------------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_2(
    KC_NO,     KC_NO,  KA_LINKEDIN,  KA_OUTLOOK, KA_TEAMS, /*-*/ KA_FILEMGR,  KC_BRIU,     KC_BRID,    KC_NO,   KC_NO,
    QK_BOOT,   KC_NO,  CONTROLPAN,   KA_POWERPT, KA_WORD,  /*-*/ KC_CALC,     KA_TASKMGR,  KA_RUN,     KC_NO,   QK_BOOT,
    QK_REBOOT, KC_NO,  BROWSWEROPEN, KA_EMOJIS,  KA_EXCEL, /*-*/ KA_SNIP,     KA_CLIPBRD,  MYCOMPUTER, KC_NO,   QK_REBOOT,
                                     KC_TRNS,    KC_TRNS,  /*-*/ KC_TRNS,     KC_TRNS
  ),


  /*  Layer 4 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | KC_TRNS     | NEW-TAB     | KC_TRNS     | KC_TRNS     | UP          |   | PGUP        | WHEEL LEFT  | MOUSE UP    | WHEEL RIGHT | KC_TRNS     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | KC_TRNS     | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| DOWN        |   | PGDN        | MOUSE LEFT  | MOUSE DOWN  | MOUSE RIGHT | KC_TRNS     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | KC_TRNS     | NEW-WIN     | INCOG       | LEFT        | RIGHT       |   | HOME        | WHEEL UP    | WHEEL DOWN  | END         | KC_TRNS     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-----------------------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_2(
    KC_TRNS,   C(KC_T),     KC_TRNS,     KC_TRNS,    KC_UP,     /*-*/ KC_PGUP ,  KC_MS_WH_LEFT,  KC_MS_UP,      KC_MS_WH_RIGHT ,   KC_TRNS,
    KC_TRNS,   KC_MS_BTN1,  KC_MS_BTN3,  KC_MS_BTN2, KC_DOWN,   /*-*/ KC_PGDN,   KC_MS_LEFT,     KC_MS_DOWN,    KC_MS_RIGHT,       KC_TRNS,
    KC_TRNS,   C(KC_N),     RCS(KC_N),   KC_LEFT,    KC_RIGHT,  /*-*/ KC_HOME ,  KC_MS_WH_UP,    KC_MS_WH_DOWN, KC_END,            KC_TRNS,
                                         KC_TRNS,    KC_TRNS,   /*-*/ KC_TRNS,   KC_TRNS
  )
};

//-------------------------------------------------------------------------------
