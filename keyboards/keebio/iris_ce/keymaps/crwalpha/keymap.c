// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
    COMBO_LENGTH
};

enum custom_keycodes {
    BROWSWEROPEN = SAFE_RANGE,
    CONTROLPAN,
    MYCOMPUTER,
    CUSTOM_LENGTH
};

const uint16_t PROGMEM winclose_combo[]   = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM caplock_combo[]    = {KC_Z, KC_X, KC_C,  COMBO_END};
const uint16_t PROGMEM leftarrow_combo[]  = {KC_D, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM rightarrow_combo[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM uparrow_combo[]    = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM downarrow_combo[]  = {KC_S, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM pageup_combo[]     = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM pagedn_combo[]     = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM home_combo[]       = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM end_combo[]        = {KC_B, KC_N, COMBO_END};

const uint16_t PROGMEM teams_mute[]       = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM teams_vidtog[]     = {KC_T, KC_Y, COMBO_END};


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

//-------------------------------------------------------------------------------

[CAPLOCK_COMBO]      = COMBO(caplock_combo, KC_CAPS),

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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LGUI_T(TG(1)),          LGUI_T(TG(2)),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(KC_ESC), LCTL_T(KC_TAB), LSFT_T(KC_SPC),                    RSFT_T(KC_ENT),  RCTL_T(KC_BSPC), RALT_T(KC_DEL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_BRIU, LCTL(KC_N), KC_NO, KC_NO,  KC_UP,                              KC_HOME, KC_PGUP,  KC_MS_U,  KC_PGDN,  KC_VOLU,   KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,  KC_BRID, KC_BTN1, KC_BTN2, KC_BTN3, KC_DOWN,                             KC_END,   KC_MS_L, KC_MS_D,  KC_MS_R,  KC_VOLD, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,  LCTL(KC_T), RCS(KC_N), KC_LEFT, KC_RGHT,  _______,     _______, KC_WH_L,  KC_WH_U, KC_WH_D,  KC_WH_R, KC_MUTE, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_APPS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT,  KC_NO,  HYPR(KC_L), HYPR(KC_O), HYPR(KC_T), KC_NO,                    KC_NO, RGUI(KC_E), KC_NO, KC_NO, KC_NO, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_RBT, KC_NO,   KC_NO,        HYPR(KC_P), HYPR(KC_W), KC_NO,                    KC_NO,  SGUI(KC_S), RCS(KC_ESC), KC_NO, KC_NO, QK_RBT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_DOT), HYPR(KC_X), _______,          _______, KC_NO, KC_CALC,  RGUI(KC_V), KC_NO, KC_NO, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

[_COLEMAKDH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC,  KC_Q,    KC_W,    KC_F,    KC_B,    KC_V,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    LGUI_T(TG(1)),          LGUI_T(TG(2)),  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(KC_ESC), LCTL_T(KC_TAB), LSFT_T(KC_SPC),                    RSFT_T(KC_ENT),  RCTL_T(KC_BSPC), RALT_T(KC_DEL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


};
