// Copyright 2023 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "keymap_us_extended.h"

enum custom_layers {
    _BASE,
    _MOUSE,
    _NAV,
    _NUM,
    _SYM,
    _RGB,
};

enum custom_keys {
    /* See auto-shift */
    CS_A_GRAVE,
    CS_E_GRAVE,
    CS_U_GRAVE,

    CS_A_CIRCUMFLEX,
    CS_E_CIRCUMFLEX,
    CS_I_CIRCUMFLEX,
    CS_O_CIRCUMFLEX,
    CS_U_CIRCUMFLEX,

    CS_E_DIAERESIS,
    CS_I_DIAERESIS,
    CS_U_DIAERESIS,
    CS_Y_DIAERESIS,
};

enum tap_dance_keys {
    TD_TAB_MOUSE,
    TD_SPC_NAV,
    TD_BSP_NUM,
    TD_ENT_SYM,

    TD_BROWSER,
    TD_GITFIGMA,
    };

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
    uint16_t held_layer;
} tap_dance_tap_hold_layer_t;
