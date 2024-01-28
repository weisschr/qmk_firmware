// Copyright 2022 Synth and Keys (@Synth-and-Keys)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _NAV,
  _APP,
  LAYER_LENGTH
};

enum combos {
    NAV_COMBO,
    APP_COMBO,
    COMBO_LENGTH
};

const uint16_t PROGMEM nav_combo[]  = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM app_combo[]  = {KC_4, KC_6, COMBO_END};

combo_t key_combos[] = {
[NAV_COMBO] = COMBO(nav_combo, TG(_NAV)),
[APP_COMBO] = COMBO(app_combo, TG(_APP))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * -------------
     * | 1 | 2 | 3 |
     * -------------
     * | 4 | 5 | 6 |
     * -----------------
     * | 7 | 8 | 9 | 0 |
     * -----------------

     */
    [_BASE] = LAYOUT(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9,   KC_0
    ),
    [_NAV] = LAYOUT(
        KC_PGDN,  KC_UP,   KC_PGUP,
        KC_LEFT,  KC_NO,   KC_RIGHT,
        KC_HOME,  KC_DOWN, KC_END ,   KC_TAB
    ),
    [_APP] = LAYOUT(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   QK_REBOOT,   QK_BOOT
    )
};
