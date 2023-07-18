#include QMK_KEYBOARD_H
#include "keycodes.h"


enum {
    TD_TAB_MOUSE,
    TD_SPC_NAV,
    TD_BSP_NUM,
    TD_ENT_SYM
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(CT_CLN):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
    //|------------------+------------------+------------------+------------------+-----------------|   |------------------+------------------+------------------+------------------+------------------|
             KC_Q        ,       KC_W       ,       KC_F       ,       KC_P       ,      KC_J       ,           KC_J       ,      KC_L        ,       KC_U       ,       KC_Y       ,    KC_QUOTE      ,
    //|------------------+------------------+------------------+------------------+-----------------|   |------------------+------------------+------------------+------------------+------------------|
       MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),      KC_G       ,           KC_M       ,MT(MOD_RSFT, KC_N),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),
    //|------------------+------------------+------------------+------------------+-----------------|   |------------------+------------------+------------------+------------------+------------------|
            US_EACU      ,       KC_X       ,       KC_Q       ,       KC_Y       ,       KC_K      ,           KC_Z       ,      KC_C        ,       KC_G       ,       KC_H       ,      KC_M        ,
    //|------------------+------------------+------------------+------------------+-----------------|   |------------------+------------------+------------------+------------------+------------------|
    //                                           |-------------------------+-------------------------| |-------------------------+-------------------------|
                                                       TD_TAB_MOUSE        ,      TD_SPC_NAV         ,         TD_BSP_NUM        ,      TD_ENT_SYM
    //                                           |-------------------------+-------------------------| |-------------------------+-------------------------|
    ),
	[_MOUSE] = LAYOUT(`
            LT(0,KC_1), LT(0,KC_2), LGUI(KC_1), LOPT(KC_SPC), LGUI(KC_4), RSG(KC_Z), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z),
            KC_LGUI, KC_LOPT, KC_LCTL, KC_LSFT, TG(5), KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
            KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO, KC_BTN3, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,
            KC_TRNS, KC_NO, KC_BTN2, KC_BTN1
        ),
	[_NAV] = LAYOUT(
            LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), RSG(KC_Z), RSG(KC_Z), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z),
            KC_LGUI, KC_LOPT, KC_LCTL, KC_LSFT, LGUI(KC_A), KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
            KC_TRNS, KC_TRNS, KC_BSPC, KC_ENT, KC_ESC, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
            KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
        ),
	[_NUM] = LAYOUT(
            KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,
            KC_0, KC_DOT, KC_TRNS, KC_NO
        ),
	[_SYM] = LAYOUT(
            KC_LCBR, KC_AMPR, KC_ASTR, KC_MINS, KC_RCBR, KC_BRIU, KC_UNDS, KC_NO, KC_NO, KC_TRNS,
            KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_BRID, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
            KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_MPRV, KC_MPLY, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MNXT,
            KC_LPRN, KC_RPRN, KC_NO, KC_TRNS
        ),
	[_RGB] = LAYOUT(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, QK_BOOT,
        RGB_M_P, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO,
        RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        RGB_M_G, RGB_M_X, TO(0), TO(0)
    )
};

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_MOUSE] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, MO(1)),
    [TD_SPC_NAV] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, MO(2)),
    [TD_BSP_NUM] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, MO(3)),
    [TD_ENT_SYM] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, MO(4)),
};
