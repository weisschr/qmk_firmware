// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _NUM,
  _SYM,
  _PAR,
  _NAV,
  _CUS,
  _MSE,
  _FUNC1,
  _FUNC2,
  LAYER_LENGTH
};

enum custom_keycodes {
  LCK_SHIFT,
  OSM_CTRL,
  OSM_GUI,
  OSM_ALT,
  OSM_SHIFT,
  CUSTOM_KEYCODE_LENGTH
};

enum combos {
    B_COMBO,
    C_COMBO,
    D_COMBO,
    F_COMBO,
    G_COMBO,
    H_COMBO,
    J_COMBO,
    K_COMBO,
    L_COMBO,
    ENTER_COMBO,
    APOSTROPHE_COMBO,
    PERIOD_COMBO,
    COMMA_COMBO,
    SLASH_COMBO,
    BANG_COMBO,
    SPACE_COMBO,
    BACKSP_COMBO,
    DEL_COMBO,
    M_COMBO,
    N_COMBO,
    P_COMBO,
    Q_COMBO,
    U_COMBO,
    V_COMBO,
    W_COMBO,
    X_COMBO,
    Z_COMBO,
    ESC_COMBO,
    TAB_COMBO,
    CTRL_COMBO,
    GUI_COMBO,
    ALT_COMBO,
    SHIFT_COMBO,
    SHIFTLCK_COMBO,
    CAPLOCK_COMBO,
    SEVEN_COMBO,
    EIGHT_COMBO,
    NINE_COMBO,
    ZERO_COMBO,

    MOUSE_COMBO,
    NAV_COMBO,

    MSE_UN_COMBO,
    NAV_UN_COMBO,

    FUNC_COMBO,
    FUNC_UN_COMBO,

};

const uint16_t PROGMEM b_combo[]    = {LT(_PAR,KC_E), LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM c_combo[]    = {LT(_PAR,KC_E), KC_Y, COMBO_END};
const uint16_t PROGMEM d_combo[]    = {LT(_SYM,KC_A), KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM f_combo[]    = {LT(_SYM,KC_A), KC_R, COMBO_END};
const uint16_t PROGMEM g_combo[]    = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM h_combo[]    = {LT(_PAR,KC_E), KC_I, COMBO_END};
const uint16_t PROGMEM j_combo[]    = {KC_T, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM k_combo[]    = {KC_Y, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM l_combo[]    = {LT(_PAR,KC_E), KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM enter_combo[]    = {LT(_SYM,KC_A), LT(_PAR,KC_E), COMBO_END};
const uint16_t PROGMEM apostrophe_combo[]    = {LT(_SYM,KC_A), KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM period_combo[]    = {LT(_SYM,KC_A), KC_Y, COMBO_END};
const uint16_t PROGMEM comma_combo[]    = {LT(_SYM,KC_A), KC_I, COMBO_END};
const uint16_t PROGMEM slash_combo[]    = {LT(_SYM,KC_A), LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM bang_combo[]    = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM space_combo[]    = {LT(_PAR,KC_E), KC_Y, KC_I, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM backsp_combo[]    = {KC_R, LT(_PAR,KC_E), COMBO_END};
const uint16_t PROGMEM del_combo[]    = {KC_R, KC_I, COMBO_END};

const uint16_t PROGMEM m_combo[]    = {KC_Y, KC_I, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM n_combo[]    = {KC_I, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM p_combo[]    = {LT(_PAR,KC_E), KC_I, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM q_combo[]    = {LT(_SYM,KC_A), KC_T, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM u_combo[]    = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM v_combo[]    = {KC_R, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM w_combo[]    = {LT(_SYM,KC_A), LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM x_combo[]    = {KC_R, KC_T, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM z_combo[]    = {LT(_SYM,KC_A), KC_R, KC_T, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM esc_combo[]       = {LT(_SYM,KC_A), KC_R, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM tab_combo[]       = {LT(_SYM,KC_A), KC_R, KC_T, LT(_CUS,KC_O), COMBO_END};
const uint16_t PROGMEM ctrl_combo[]      = {LT(_NUM,KC_S), LT(_PAR,KC_E), COMBO_END};
const uint16_t PROGMEM gui_combo[]       = {KC_Y, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM alt_combo[]       = {KC_I, LT(_NUM,KC_S), COMBO_END};
const uint16_t PROGMEM shift_combo[]     = {KC_R, KC_T, LT(_NUM,KC_S), LT(_PAR,KC_E), COMBO_END};
const uint16_t PROGMEM shiftlock_combo[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM caplock_combo[]   = {LT(_SYM,KC_A), KC_Y, KC_I, LT(_CUS,KC_O), COMBO_END};

const uint16_t PROGMEM seven_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM eight_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM nine_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM zero_combo[] = {KC_5, KC_6, COMBO_END};

const uint16_t PROGMEM mouse_combo[] = {LT(_SYM,KC_A), KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM nav_combo[]   = {KC_R, LT(_PAR,KC_E), KC_I, COMBO_END};

const uint16_t PROGMEM mse_un_combo[] = {KC_BTN1, KC_BTN2, KC_MS_DOWN, COMBO_END};
const uint16_t PROGMEM nav_un_combo[] = {KC_LEFT, KC_UP, KC_RIGHT, COMBO_END};

const uint16_t PROGMEM func_combo[] = {KC_R, KC_T, KC_Y, KC_I,  COMBO_END};
const uint16_t PROGMEM func_un_combo[] = {KC_F2, KC_F3, KC_F6, KC_F7, COMBO_END};
 

combo_t key_combos[] = {  
[B_COMBO]               = COMBO(b_combo, KC_B),
[C_COMBO]               = COMBO(c_combo, KC_C),
[D_COMBO]               = COMBO(d_combo, KC_D),
[F_COMBO]               = COMBO(f_combo, KC_F),
[G_COMBO]               = COMBO(g_combo, KC_G),
[H_COMBO]               = COMBO(h_combo, KC_H),
[J_COMBO]               = COMBO(j_combo, KC_J),
[K_COMBO]               = COMBO(k_combo, KC_K),
[L_COMBO]               = COMBO(l_combo, KC_L),
[ENTER_COMBO]           = COMBO(enter_combo, KC_ENTER),
[APOSTROPHE_COMBO]      = COMBO(apostrophe_combo, KC_QUOTE),
[PERIOD_COMBO]          = COMBO(period_combo, KC_DOT),
[COMMA_COMBO]           = COMBO(comma_combo, KC_COMM),
[SLASH_COMBO]           = COMBO(slash_combo, KC_SLSH),
[BANG_COMBO]            = COMBO(bang_combo, KC_EXLM),
[SPACE_COMBO]           = COMBO(space_combo, KC_SPACE),
[BACKSP_COMBO]          = COMBO(backsp_combo, KC_BSPC),
[DEL_COMBO]             = COMBO(del_combo, KC_DEL),

[M_COMBO]               = COMBO(m_combo, KC_M),
[N_COMBO]               = COMBO(n_combo, KC_N),
[P_COMBO]               = COMBO(p_combo, KC_P),
[Q_COMBO]               = COMBO(q_combo, KC_Q),
[U_COMBO]               = COMBO(u_combo, KC_U),
[V_COMBO]               = COMBO(v_combo, KC_V),
[W_COMBO]               = COMBO(w_combo, KC_W),
[X_COMBO]               = COMBO(x_combo, KC_X),
[Z_COMBO]               = COMBO(z_combo, KC_Z),
[ESC_COMBO]             = COMBO(esc_combo, KC_ESC),
[TAB_COMBO]             = COMBO(tab_combo, KC_TAB),
[CTRL_COMBO]            = COMBO(ctrl_combo, OSM_CTRL),
[GUI_COMBO]             = COMBO(gui_combo, OSM_GUI),
[ALT_COMBO]             = COMBO(alt_combo, OSM_ALT),
[SHIFT_COMBO]           = COMBO(shift_combo, OSM_SHIFT),
[SHIFTLCK_COMBO]        = COMBO(shiftlock_combo, LCK_SHIFT),
[CAPLOCK_COMBO]         = COMBO(caplock_combo, KC_CAPS),
[SEVEN_COMBO]           = COMBO(seven_combo, KC_7),
[EIGHT_COMBO]           = COMBO(eight_combo, KC_8),
[NINE_COMBO]            = COMBO(nine_combo, KC_9),
[ZERO_COMBO]            = COMBO(zero_combo, KC_0),

[MOUSE_COMBO]           = COMBO(mouse_combo, TO(_MSE)),
[NAV_COMBO]             = COMBO(nav_combo, TO(_NAV)),

[MSE_UN_COMBO]          = COMBO(mse_un_combo, TO(_BASE)),
[NAV_UN_COMBO]          = COMBO(nav_un_combo, TO(_BASE)),

[FUNC_COMBO]            = COMBO(func_combo,TO(_FUNC1)),
[FUNC_UN_COMBO]         = COMBO(func_un_combo,TO(_BASE)),

};

///////////


//////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCK_SHIFT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                }
                else {
                    register_mods(MOD_BIT(KC_LSFT));
                }
            }
            return false;
            break;
        case OSM_CTRL:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LCTL));
            }
            break;
        case OSM_GUI:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case OSM_ALT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LALT));
            }
            break;
        case OSM_SHIFT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        default:
            break;
    }
    return true;
}

/////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    LT(_SYM,KC_A), KC_R, KC_T, LT(_NUM,KC_S),
    LT(_PAR,KC_E), KC_Y, KC_I, LT(_CUS,KC_O)
),

[_NUM] = LAYOUT(
    KC_1, KC_2, KC_3, KC_TRNS,
    KC_4, KC_5, KC_6, KC_NO
),

[_SYM] = LAYOUT(
    KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, 
    KC_NO, KC_LBRC, KC_RBRC, KC_RCBR
),

[_NAV] = LAYOUT(
    KC_HOME, KC_UP, KC_END, KC_PGUP,
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN
),

[_PAR] = LAYOUT(
    KC_EXLM, KC_BSLS, KC_SCLN, KC_GRV,
    KC_TRNS, KC_QUES, KC_MINS, KC_EQL
),

[_CUS] = LAYOUT(
    KC_MUTE, KC_INS, KC_VOLU, KC_NO,
    KC_RSFT, KC_PSCR, KC_VOLD, KC_TRNS
),

[_MSE] = LAYOUT(
    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_UP,
    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN
),

[_FUNC1] = LAYOUT(
   LT(_FUNC2,KC_F1), KC_F2, KC_F3, KC_F4,
   KC_F5, KC_F6, KC_F7, KC_F8,

),

[_FUNC2] = LAYOUT(
   KC_TRNS, KC_F9, KC_F10, KC_F11,
   KC_F12, LCTL(KC_F4), LALT(KC_F4), KC_NO

)

};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_270;
}

bool oled_task_user()
{
    oled_set_cursor(0, 1);
    led_t led_state = host_keyboard_led_state();
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write("MAIN   ",false);
            break;
        case _CUS:
            oled_write("CUSTOM ",false);
            break;
        case _MSE:
            oled_write("MOUSE  ",false);
            break;
        case _NAV:
            oled_write("NAV    ",false);
            break;
        case _NUM:
            oled_write("NUMBERS",false);
            break;
        case _PAR:
            oled_write("PUNC   ",false);
            break;
        case _SYM:
            oled_write("SYMBOL ",false);
            break;
        default:
            oled_write("Unknown",false);
            break;
    }

    oled_set_cursor(32,1);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ON  ") : PSTR("caps off"),false);
    return false;
}

#endif
