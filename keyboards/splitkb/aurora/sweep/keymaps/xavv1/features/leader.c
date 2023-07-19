// Copyright 2023 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include <stdlib.h>

void leader_end_user(void) {
  if (leader_sequence_two_keys(KC_M, KC_S)) {
    SEND_STRING("xavier@malparty.fr");
  } else if (leader_sequence_two_keys(KC_M, KC_L)) {
    SEND_STRING("xavier@nimble.hq");
  } else if (leader_sequence_two_keys(KC_L, KC_N)) {
    SEND_STRING("Malparty");
  } else if (leader_sequence_two_keys(KC_F, KC_N)) {
    SEND_STRING("Xavier");

  } else if (leader_sequence_two_keys(KC_G, KC_T)) {
    SEND_STRING("(){ git switch develop; git fetch --all && git br -D $1; git co $1 }");
  } else if (leader_sequence_two_keys(KC_G, KC_P)) {
    SEND_STRING("git push");
  } else if (leader_sequence_three_keys(KC_G, KC_P, KC_F)) {
    SEND_STRING("git push --force");
  } else if (leader_sequence_three_keys(KC_G, KC_P, KC_U)) {
    SEND_STRING("git pull");

    /* Currency */
  } else if (leader_sequence_three_keys(KC_E, KC_U, KC_R)) {
    tap_code16(US_EURO); // €
  };
}
