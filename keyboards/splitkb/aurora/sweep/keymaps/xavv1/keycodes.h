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
    _SENDSTR,
    _RGB,
};

enum custom_keys {
    UNICODE = QK_KB_0, // Replace SAFE_RANGE, see pr #19909

    SS_CHEC,
    SS_PRAY,
    SS_BULB,
    SS_STAR,
    SS_STST,
    SS_HARO,
    SS_TEAR,
    SS_CROS,
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

*char send_string_actions[][16] = {
    [SS_CHEC] = ":check_:",
    [SS_PRAY] = ":pray_:",
    [SS_BULB] = ":bulb_:",
    [SS_STAR] = ":star_:",
    [SS_STST] = ":starstruck_:",
    [SS_HARO] = ":harold:",
    [SS_TEAR] = ":tearsmile_:",
    [SS_CROS] = ":cross_:",
};
