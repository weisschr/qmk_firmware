// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Shortcuts

#define KA_LNKIN HYPR(KC_L)
#define KA_OTLK  HYPR(KC_O)
#define KA_TMS   HYPR(KC_T)
#define KA_FLMGR RGUI(KC_E)
#define KA_PWRPT HYPR(KC_P)
#define KA_WORD  HYPR(KC_W)
#define KA_ONENT HYPR(KC_N)
#define KA_ONEDR HYPR(KC_D)
#define KA_TKMG  RCS(KC_ESC)
#define KA_RUN   RGUI(KC_R)
#define KA_EMJ   LGUI(KC_DOT)
#define KA_EXCEL HYPR(KC_X)
#define KA_SNIP  SGUI(KC_S)
#define KA_CLPB  RGUI(KC_V)
#define KA_NEWT  LCTL(KC_T)
#define KA_NWIC  RCS(KC_N)
#define KA_NEWW  LCTL(KC_N)
#define KA_REOP  RCS(KC_T)
#define KA_BOOK  RCS(KC_O)
#define KA_BKMK  LCTL(KC_D)
#define KA_BKBR  LCTL(KC_B)
#define KA_HOME  LALT(KC_HOME)

// Mod tap

#define KA_LSFP   LSFT_T(KC_SPC)
#define KA_LALEC  LALT_T(KC_ESC)
#define KA_LCLTB  LCTL_T(KC_TAB)
#define KA_RSFEN  RSFT_T(KC_ENT)
#define KA_RCLBP  RCTL_T(KC_BSPC)
#define KA_RALDL  RALT_T(KC_DEL)
#define KA_RCSG   RCS_T(KC_G)
#define KA_RCSH   RCS_T(KC_H)
#define KA_RCSM   RCS_T(KC_M)
#define KA_LGUT   LGUI_T(KC_T)
#define KA_RGUY   RGUI_T(KC_Y)

#define KA_LME5   MEH_T(KC_5)
#define KA_RME6   MEH_T(KC_6)
#define KA_LSUB   HYPR_T(KC_B)
#define KA_RSUN   HYPR_T(KC_N)

const uint16_t lf_keylist[] = {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LBRC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_EQL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_TAB, KC_SPACE};
const uint16_t rt_keylist[] = {KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_ENTER, KC_BSPC, KC_DEL};


const int rt_keylist_size = sizeof(rt_keylist) / sizeof(rt_keylist[0]);
const int lf_keylist_size = sizeof(lf_keylist) / sizeof(lf_keylist[0]);

//-------------------------------------------------------------------------------

enum layers {
     _DEFAULT,
     _MOUSE,
     _APPS,
     _COLEMAKDH
};

enum combos {
    WINCLOSE_COMBO,
    APPCLOSE_COMBO,
    CAPLOCK_COMBO,
    LEFTARROW_COMBO,
    RIGHTARROW_COMBO,
    UPARROW_COMBO,
    DOWNARROW_COMBO,
    PAGEUP_COMBO,
    PAGEDN_COMBO,
    HOME_COMBO,
    END_COMBO,
    COLEMAK_COMBO,
    TEAMS_MUTE,
    TEAMS_VIDTOG,
    CHROME,
    MYCOMPUTER,
    CONTROLPAN,
    EDGE,
    VSCODE,
    NOTEPADPP,
    DEFAULT_COMBO
};

enum custom_keycodes {
    KM_CHROME = SAFE_RANGE,
    KM_MYCOMPUTER,
    KM_CONTROLPAN,
    KM_EDGE,
    KM_VSCODE,
    KM_NOTEPADPP,
    LT_ESC_ALT,
    LT_TAB_CTL,
    LT_SPC_SFT,
    RT_ENT_SFT,
    RT_BSP_CTL,
    RT_DEL_ALT,
};

enum tap_dances {
    TD_MOUSE,
    TD_APPS
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (tap_dance_state_t *state);

//Functions associated with individual tap dances
void ms_finished (tap_dance_state_t *state, void *user_data);
void ms_reset (tap_dance_state_t *state, void *user_data);
void ap_finished (tap_dance_state_t *state, void *user_data);
void ap_reset (tap_dance_state_t *state, void *user_data);

// Functions for bilateral combos
bool is_left(uint16_t keycode);
bool is_right(uint16_t keycode);
bool is_left_mod(uint8_t mod_state);
bool is_right_mod(uint8_t mod_state);

const uint16_t PROGMEM winclose_combo[]   = {KC_R, KA_LGUT, COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_V, KA_LSUB, COMBO_END};
const uint16_t PROGMEM caplock_combo[]    = {KC_Z, KC_X, KC_C,  COMBO_END};
const uint16_t PROGMEM leftarrow_combo[]  = {KC_D, KC_F, KA_RCSG, COMBO_END};
const uint16_t PROGMEM rightarrow_combo[] = {KC_E, KC_R, KA_LGUT, COMBO_END};
const uint16_t PROGMEM uparrow_combo[]    = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM downarrow_combo[]  = {KC_S, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM pageup_combo[]     = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM pagedn_combo[]     = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM home_combo[]       = {KA_RCSG, KA_RCSH, COMBO_END};
const uint16_t PROGMEM end_combo[]        = {KA_LSUB, KA_RSUN, COMBO_END};

const uint16_t PROGMEM teams_mute[]       = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM teams_vidtog[]     = {KA_LGUT, KA_RGUY, COMBO_END};

const uint16_t PROGMEM colemak_combo[]    = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM default_combo[]    = {KC_J, KC_K, KC_L, COMBO_END};

// Macro Combos

const uint16_t PROGMEM chrome_combo[]     = {KC_C, KA_RCSH, COMBO_END};
const uint16_t PROGMEM mycomputer_combo[] = {KC_C, KA_RGUY, COMBO_END};
const uint16_t PROGMEM controlpan_combo[] = {KC_C, KA_RSUN, COMBO_END};
const uint16_t PROGMEM edge_combo[]       = {KC_C, KC_J, COMBO_END};
const uint16_t PROGMEM vscode_combo[]     = {KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM notepadpp_combo[]  = {KC_C, KC_M, COMBO_END};

combo_t key_combos[] = {

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
[COLEMAK_COMBO]      = COMBO(colemak_combo, TG(_COLEMAKDH)),
[CAPLOCK_COMBO]      = COMBO(caplock_combo, KC_CAPS),
[TEAMS_MUTE]         = COMBO(teams_mute, RCS(KC_M)),
[TEAMS_VIDTOG]       = COMBO(teams_vidtog, RCS(KC_O)),
[CHROME]             = COMBO(chrome_combo, KM_CHROME),
[MYCOMPUTER]         = COMBO(mycomputer_combo, KM_MYCOMPUTER),
[CONTROLPAN]         = COMBO(controlpan_combo, KM_CONTROLPAN),
[EDGE]               = COMBO(edge_combo, KM_EDGE),
[VSCODE]             = COMBO(vscode_combo, KM_VSCODE),
[NOTEPADPP]          = COMBO(notepadpp_combo, KM_NOTEPADPP),
[DEFAULT_COMBO]      = COMBO(default_combo, TO(_DEFAULT)),
};

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

bool is_left(uint16_t keycode) {
    for (int i = 0; i < lf_keylist_size; i++) {
        if (keycode == lf_keylist[i]) {
            return true;
        }
    }
    return false;
}

bool is_right(uint16_t keycode) {
    for (int i = 0; i < rt_keylist_size; i++) {
        if (keycode == rt_keylist[i]) {
            return true;
        }
    }
    return false;
}

bool is_left_mod(uint8_t mod_state){
    if ((mod_state & MOD_BIT(KC_LALT)) ||
        (mod_state & MOD_BIT(KC_LSFT)) ||
        (mod_state & MOD_BIT(KC_LCTL)) ||
        (mod_state & MOD_BIT(KC_LGUI))) {
            return true;
        };

    return false;
}

bool is_right_mod(uint8_t mod_state){
    if ((mod_state & MOD_BIT(KC_RALT)) ||
        (mod_state & MOD_BIT(KC_RSFT)) ||
        (mod_state & MOD_BIT(KC_RCTL)) ||
        (mod_state & MOD_BIT(KC_RGUI))) {
            return true;
        };

    return false;
}

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KA_LGUT:
        case KA_RGUY:
        case KA_LME5:
        case KA_RME6:
        case KA_LSUB:
        case KA_RSUN:
            return 500;
        default:
            return TAPPING_TERM;
    }
}

uint8_t mod_state;
bool left_mod;
bool right_mod;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    if (mod_state) {
        if (record->event.pressed) {
            if((is_left(keycode) && is_left_mod(mod_state)) ||
               (is_right(keycode) && is_right_mod(mod_state)))
               {
                    clear_mods();
               }
        }
    }

    switch (keycode) {
        case KM_CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("chrome" SS_TAP(X_ENTER));
            }
            return false;

        case KM_MYCOMPUTER:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("Shell:MyComputerFolder" SS_TAP(X_ENTER));
            }
            return false;

        case KM_CONTROLPAN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("Control" SS_TAP(X_ENTER));
            }
            return false;

        case KM_EDGE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("microsoft-edge:" SS_TAP(X_ENTER));
            }
            return false;

        case KM_VSCODE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("code" SS_TAP(X_ENTER));
            }
        return false;

        case KM_NOTEPADPP:
            if (record->event.pressed) {
              SEND_STRING(SS_LGUI("r"));
                wait_ms(500);
                SEND_STRING("notepad++" SS_TAP(X_ENTER));
            }
            return false;

        default:
            return true; // Process all other keycodes normally.
  }
  return true;
}

//-------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KA_LME5,                            KA_RME6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KA_LGUT,                            KA_RGUY,  KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KA_RCSG,                            KA_RCSH,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KA_LSUB, TD(TD_MOUSE),     TD(TD_APPS), KA_RSUN, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KA_LALEC, KA_LCLTB, KA_LSFP,                 KA_RSFEN, KA_RCLBP, KA_RALDL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BRIU, KA_BOOK, KA_NEWW, KA_REOP,  KA_HOME,   KC_UP,                            KC_HOME, KC_PGUP,  KC_MS_U, KC_PGDN, KC_VOLU, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BRID, KA_BKMK, KC_BTN1, KC_BTN2, KC_BTN3, KC_DOWN,                            KC_END,  KC_MS_L, KC_MS_D,  KC_MS_R,  KC_VOLD, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KA_BKBR, KA_NEWT, KA_NWIC, KC_LEFT, KC_RGHT,  _______,         _______, KC_WH_L,  KC_WH_U, KC_WH_D,  KC_WH_R, KC_MUTE, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_APPS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_M_P,  RGB_M_B, RGB_M_R,RGB_M_SW,RGB_M_SN,                            RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_MOD, RGB_TOG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, RGB_HUI, KA_LNKIN, KA_OTLK, KA_TMS, KC_NO,                              KA_FLMGR, KC_NO, KC_NO,   KC_NO,  RGB_HUD, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_RBT,  RGB_SAI, KA_ONENT, KA_PWRPT, KA_WORD, KC_NO,                            KC_CALC,  KA_TKMG, KA_RUN,  KC_NO,  RGB_SAD,   QK_RBT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SPI, RGB_VAI, KA_ONEDR,  KA_EMJ, KA_EXCEL, KC_NO, _______,          _______, KA_SNIP, KA_CLPB, KC_MYCM,  KC_NO, RGB_VAD, RGB_SPD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

[_COLEMAKDH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_A,    KC_R,    KC_S,    KC_T,    KA_RCSG,                            KA_RCSM,   KC_N,   KC_E,   KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,          _______,  KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

//Determine the current tap dance state
int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 8;
}

//Initialize tap structure
static tap ms_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap ap_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control tap dance behavior

void ms_finished (tap_dance_state_t *state, void *user_data) {
  ms_tap_state.state = cur_dance(state);
  switch (ms_tap_state.state) {
    case SINGLE_TAP:
        // Return to default if any other layer active
        if (!layer_state_is(_DEFAULT)) {
            layer_clear();
        } else {
            // One shot layer key otherwise
            set_oneshot_layer(_MOUSE, ONESHOT_OTHER_KEY_PRESSED);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
      break;
    case SINGLE_HOLD:
      layer_on(_MOUSE);
      break;
    case DOUBLE_TAP:
      //check to see if the layer is default
      if (!layer_state_is(_DEFAULT)) {
            layer_clear();
      } else {
        //if not set, then switch the layer on
        layer_on(_MOUSE);
      }
      break;
  }
}

void ms_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ms_tap_state.state==SINGLE_HOLD) {
    layer_off(_MOUSE);
  }
  ms_tap_state.state = 0;
}

void ap_finished (tap_dance_state_t *state, void *user_data) {
  ap_tap_state.state = cur_dance(state);
  switch (ap_tap_state.state) {
    case SINGLE_TAP:
        if (!layer_state_is(_DEFAULT)) {
            layer_clear();
        } else {
            set_oneshot_layer(_APPS, ONESHOT_OTHER_KEY_PRESSED);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
      break;
    case SINGLE_HOLD:
      layer_on(_APPS);
      break;
    case DOUBLE_TAP:
      //check to see if the layer is already set
     if (!layer_state_is(_DEFAULT)) {
            layer_clear();
      } else {
        //if not already set, then switch the layer on
        layer_on(_APPS);
      }
      break;
  }
}

void ap_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ap_tap_state.state==SINGLE_HOLD) {
    layer_off(_APPS);
  }
  ap_tap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ms_finished, ms_reset),
  [TD_APPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ap_finished, ap_reset)
};
