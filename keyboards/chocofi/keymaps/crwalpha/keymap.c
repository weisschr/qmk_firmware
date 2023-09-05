#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _SYMBOLS 1
#define _MOUSE 2
#define _NAV 3
#define _FUNCTION 4
#define _APPS 5

enum custom_keycodes {
  KC_MY_LAYER = SAFE_RANGE, // Add more custom keycodes here if needed
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

/*

*/

enum {
    TD_LAYER_1=0,
};

void td_layer_1_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(1); // Activate layer 1 (OSL(1))
    } else if (state->count == 2) {
        register_code(KC_TRNS); // Send a temporary keypress of KC_TRNS
        unregister_code(KC_TRNS);
        layer_on(1); // Activate layer 1 (TO(1))
    }
}

// Function called when a Tap Dance key is held
void td_layer_1_reset(tap_dance_state_t *state, void *user_data) {
    if (!state->interrupted) {
        layer_on(1); // Activate layer 1 (MO(1))
    }
}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LAYER_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_layer_1_finished, td_layer_1_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
*  |-----------------------------|
*  |     |     |     |     |     |
*  |-----------------------------|
*  |     |     |     |     |     |
*  |-----------------------------|
*  |     |     |     |     |     |
*  |-----------------------------|
*              |     |     |     |
*               -----------------
*
*/



[_DEFAULT] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T,     					        KC_Y, KC_U, KC_I, KC_O, KC_P, 
                   KC_A, KC_S, KC_D, KC_F, KC_G,     					        KC_H, KC_J, KC_K, KC_L, KC_SCLN, 
				   KC_Z, KC_X, KC_C, KC_V, KC_B,     					        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
				   TD(TD_LAYER_1), KC_TAB, KC_MY_LAYER,            					        KC_ENT, KC_BSPC, TO(5)),
																		        
[_SYMBOLS] = LAYOUT_split_3x5_3(KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_AT,                   KC_HASH, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, 
                   KC_1, KC_2, KC_3, KC_4, KC_5,                                KC_6, KC_7, KC_8, KC_9, KC_0, 
				   KC_GRV, KC_EQL, KC_PLUS, KC_UNDS, KC_MINS,                   KC_DLR, KC_SCLN, KC_COMM, KC_DOT, KC_SLSH, 
				   TO(2), KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, TO(0)),
																		        
[_MOUSE] = LAYOUT_split_3x5_3(CW_TOGG, LCTL(KC_HOME), KC_HOME, KC_PGUP, KC_COPY,           KC_UP, KC_LEFT, KC_MS_U, KC_RGHT, KC_VOLU, 
                   KC_LCAP, KC_BTN1, KC_BTN2, KC_BTN3, KC_PSTE,                 KC_DOWN, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, 
                   KC_UNDO, LCTL(KC_END), KC_END, KC_PGDN, KC_CUT,              KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MUTE, 
                   TO(3), KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, TO(1)),
																		        
[_NAV] = LAYOUT_split_3x5_3(KC_MFFD, KC_MNXT, LSFT(KC_END), LSFT(KC_HOME), KC_COPY,      KC_ESC, KC_LEFT, KC_RGHT, KC_VOLU, KC_BRIU, 
                   KC_MSTP, KC_MPLY, LCTL(KC_HOME), KC_HOME, KC_PSTE,           KC_INS, KC_UP, KC_PGUP, KC_VOLD, KC_BRID, 
				   KC_MRWD, KC_MPRV, LCTL(KC_END), KC_END, KC_CUT,              KC_DEL, KC_DOWN, KC_PGDN, KC_MUTE, KC_NO, 
				   TO(4), KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, TO(2)),
																		        
[_FUNCTION] = LAYOUT_split_3x5_3(KC_NO, KC_NO, KC_NO, RALT(KC_F4), KC_F11,                    KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, 
                   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                           KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
				   KC_NO, KC_NO, KC_NO, RCTL(KC_F4), KC_ESC,                    KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, 
				   TO(5), KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, TO(3)),
																		        
[_APPS] = LAYOUT_split_3x5_3(KC_NO, HYPR(KC_C), HYPR(KC_O), HYPR(KC_T), HYPR(KC_N),       SGUI(KC_S), RGUI(KC_V), RGUI(KC_M), KC_WFWD, KC_WREF, 
                   KC_CALC, LCTL(KC_D), HYPR(KC_P), HYPR(KC_W), HYPR(KC_B),     RCS(KC_ESC), RGUI(KC_L), RGUI(KC_R), KC_WHOM, KC_WSTP, 
				   KC_NO, KC_WFAV, HYPR(KC_L), HYPR(KC_X), HYPR(KC_D),          LGUI(KC_E), LGUI(KC_DOT), RGUI(KC_X), KC_WBAK, KC_WSCH, 
				   TO(0), KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, TO(4)) 																		        
};                  
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
const uint16_t PROGMEM cho_combo20[] = {KC_H, KC_K, COMBO_END};

combo_t key_combos[] = {  // layer 0 combos
    COMBO(cho_combo1, OSM(KC_LSFT)),
    COMBO(cho_combo2, OSM(KC_RSFT)),
    COMBO(cho_combo3, OSM(KC_LCTL)),
    COMBO(cho_combo4, OSM(KC_RCTL)),
    COMBO(cho_combo5, OSM(KC_LALT)),
    COMBO(cho_combo6, OSM(KC_RALT)),
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
};

// Put custom keycodes
/*

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MY_LAYER:
          break;
    // Add more custom keycodes handling here if needed
  }
  return true;
}
*/
