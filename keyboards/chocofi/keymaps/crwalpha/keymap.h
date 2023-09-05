#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_MY_LAYER = SAFE_RANGE, // Add more custom keycodes here if needed
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;


enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);