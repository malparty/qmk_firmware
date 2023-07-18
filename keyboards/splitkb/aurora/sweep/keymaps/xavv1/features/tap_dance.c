#include QMK_KEYBOARD_H
#include "keycodes.h"

// TODO:
// - backspace, space, enter can't be pressed quickly enough and can't tap/hold quickly

void dance_tap_hold_layer_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_layer_t *tap_hold = (tap_dance_tap_hold_layer_t *)user_data;

    if (state->pressed) {
        layer_on(tap_hold->layer);
    } else {
        layer_off(tap_hold->layer);

        if (state->count > 0) {
          int i;
          for (i = 0; i < state->count; i++) {
            tap_code16(tap_hold->tap);
          }
        }
    }
}

void tap_dance_tap_hold__layer_reset(tap_dance_state_t *state, void *user_data) {
    layer_clear();
}

#define ACTION_TAP_DANCE_TAP_HOLD_LAYER(tap, layer) \
    { .fn = {NULL, dance_tap_hold_layer_finished, tap_dance_tap_hold__layer_reset}, .user_data = (void *)&((tap_dance_tap_hold_layer_t){tap, layer, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_MOUSE] = ACTION_TAP_DANCE_TAP_HOLD_LAYER(KC_TAB, _MOUSE),
    [TD_SPC_NAV] = ACTION_TAP_DANCE_TAP_HOLD_LAYER(KC_SPC, _NAV),
    [TD_BSP_NUM] = ACTION_TAP_DANCE_TAP_HOLD_LAYER(KC_BSPC, _NUM),
    [TD_ENT_SYM] = ACTION_TAP_DANCE_TAP_HOLD_LAYER(KC_ENTER, _SYM),

    [TD_BROWSER] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LGUI(KC_6)),
    [TD_GITFIGMA] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LGUI(KC_5)),
};
