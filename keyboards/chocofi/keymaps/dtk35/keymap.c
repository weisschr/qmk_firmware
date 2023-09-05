#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/caps_word.h"

enum {
    GNOME_3 = 0,
    GNOME_40,
    OSX,
    WIN_10,

    NUM_SUPPORTED_WMS,
} window_manager = WIN_10;

// Layer declarations
enum {
  COLEMAK = 0,
  MOD_ARR,
  NAVIGAT,
  FUN_NUM,
  SYMBOLS,
  WNDWMGR,
  COMPOSE,

  NUM_LAYERS
};


// Custom keycodes
enum custom_keycodes {
    WM_GNOME_3 = SAFE_RANGE,
    WM_GNOME_40,
    WM_OSX,
    WM_WIN_10,
    WM_EXPOSEE,
    WM_LEFT_DESK,
    WM_RGHT_DESK,
    WM_UPPR_DESK,
    WM_LOWR_DESK,
};

#define ____ KC_TRNS
#define XXXX KC_NO
//   Left
//     Home row mods
#define KC_A_ LALT_T(KC_A)
#define KC_R_ LGUI_T(KC_R)
#define KC_S_ LCTL_T(KC_S)
#define KC_T_ LSFT_T(KC_T)
//     Layer toggles
#define KC_WM   LT(WNDWMGR, WM_EXPOSEE)
#define KC_BSP_ LT(MOD_ARR, KC_BSPC)
#define KC_TAB_ LT(FUN_NUM, KC_TAB)
#define KC_D_   LT(SYMBOLS, KC_D)
#define KC_NAV  LT(NAVIGAT, KC_NO)
//   Right
//     Home-row mods
#define KC_N_ RSFT_T(KC_N)
#define KC_E_ RCTL_T(KC_E)
#define KC_I_ RGUI_T(KC_I)
#define KC_O_ LALT_T(KC_O)
//     Layer toggles
#define KC_ENT_ LT(FUN_NUM, KC_ENT)
#define KC_SPC_ LT(MOD_ARR, KC_SPC)
#define KC_ESC_ LT(COMPOSE, KC_ESC)
#define KC_H_   LT(SYMBOLS, KC_H)
//  Window Manager
#define KC_GNM3 WM_GNOME_3
#define KC_GNM4 WM_GNOME_40
#define KC_OSX WM_OSX
#define KC_WIN WM_WIN_10
#define KC_WM LT(WNDWMGR, WM_EXPOSEE)
#define KC_LFTD WM_LEFT_DESK
#define KC_RGTD WM_RGHT_DESK
#define KC_UPRD WM_UPPR_DESK
#define KC_LWRD WM_LOWR_DESK
//  Compose
#define KC_AE RALT(KC_Q)
#define KC_SZ RALT(KC_S)
#define KC_EE RALT(KC_E)
#define KC_IE RALT(KC_I)
#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Tab│
      *           └───┤Bsp├───┐   ┌───┤   ├───┘
      *               └───┤Esc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A_,   KC_R_,   KC_S_,   KC_T_,   KC_G,                               KC_M,    KC_N_,   KC_E_,   KC_I_,   KC_O_,
        KC_Z,    KC_X,    KC_C,    KC_D_,   KC_V,                               KC_K,    KC_H_,   KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_WM,   KC_BSP_, KC_TAB_,          KC_ENT_, KC_SPC_, KC_ESC_
    ),

    [MOD_ARR] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXX,
        XXXX,    XXXX,    XXXX,    KC_NAV,  XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   XXXX,    KC_DEL,  XXXX,             XXXX,    XXXX,    XXXX
    ),
    [NAVIGAT] = LAYOUT_split_3x5_3(
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                  XXXX,    XXXX,     XXXX,             XXXX,    XXXX,    XXXX
    ),
    [FUN_NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_F4,   KC_F3,   KC_F2,   KC_F1,                              XXXX,    KC_7,    KC_8,    KC_9,    KC_MINS,
        XXXX,    KC_F8,   KC_F7,   KC_F6,   KC_F5,                              KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,
        XXXX,    KC_F12,  KC_F11,  KC_F10,  KC_F9,                              KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,
                                   XXXX,    XXXX,    XXXX,             KC_0,    KC_0,    KC_DOT
    ),
    [SYMBOLS] = LAYOUT_split_3x5_3(
        KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                            KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        KC_EXLM, XXXX,    XXXX,    XXXX,    XXXX,                               KC_DQUO, XXXX,    KC_LBRC, KC_RBRC, KC_PLUS,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               KC_TILD, XXXX,    KC_LCBR, KC_RCBR, KC_PIPE,
                                   XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
    ),
    [COMPOSE] = LAYOUT_split_3x5_3(
       KC_AE,   XXXX,    XXXX,    XXXX,    XXXX,                                XXXX,    XXXX,    XXXX,    KC_UE,   KC_OE,
       XXXX,    XXXX,    KC_SZ,   XXXX,    XXXX,                                XXXX,    XXXX,    KC_EE,   KC_IE,    XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                  XXXX,    XXXX,     XXXX,             XXXX,    XXXX,    XXXX
    ),
    [WNDWMGR] = LAYOUT_split_3x5_3(
       KC_GNM3, KC_GNM4, KC_OSX,  KC_WIN,  XXXX,                                XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                KC_LFTD, KC_LWRD, KC_UPRD, KC_RGTD, XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                                XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                  XXXX,    XXXX,     XXXX,             XXXX,    XXXX,    XXXX
    )
    /*[<TMPL>] = LAYOUT_split_3x5_3(
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *                              XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
     *)
     */
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
        case LT(COMPOSE, KC_ESC):
            return TAPPING_TERM_SFT;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(COMPOSE, KC_ESC):
      return true;
    default:
      return false;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(MOD_ARR, KC_BSPC):
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_caps_word(keycode, record)) { return false; }

  switch (keycode) {
  case WM_GNOME_3:
    if (record->event.pressed) {
        window_manager=GNOME_3;
    }
    return false;
  case WM_GNOME_40:
    if (record->event.pressed) {
        window_manager=GNOME_40;
    }
    return false;
  case WM_OSX:
    if (record->event.pressed) {
        window_manager=OSX;
    }
    return false;
  case WM_WIN_10:
    if (record->event.pressed) {
        window_manager=WIN_10;
    }
    return false;
  case LT(WNDWMGR, WM_EXPOSEE):
    if (record->tap.count && record->event.pressed) {
      switch (window_manager) {
      case GNOME_3 ... GNOME_40:
        tap_code(KC_LGUI);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_UP);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LGUI);
        tap_code(KC_TAB);
        unregister_code(KC_LGUI);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_LEFT_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
      case GNOME_40:
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_LEFT);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_RGHT_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
      case GNOME_40:
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_RGHT);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_RGHT);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_RGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_UPPR_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
        case GNOME_3:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_UP);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_LOWR_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
      case GNOME_3:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_DOWN);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  }
  return true;
}
