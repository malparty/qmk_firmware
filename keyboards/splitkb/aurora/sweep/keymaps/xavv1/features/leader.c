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
  } else if (leader_sequence_two_keys(KC_F, KC_L)) {
    SEND_STRING("malparty");

  } else if (leader_sequence_three_keys(KC_Q, KC_M, KC_C)) {
    SEND_STRING("qmk compile && qmk flash");

  } else if (leader_sequence_three_keys(KC_T, KC_E, KC_S)) {
    SEND_STRING("test01234");
  } else if (leader_sequence_three_keys(KC_A, KC_D, KC_M)) {
    SEND_STRING("admin01234");

    /* Currency */
  } else if (leader_sequence_three_keys(KC_E, KC_U, KC_R)) {
    tap_code16(US_EURO); // €

    /* Icons */
  } else if (leader_sequence_three_keys(KC_L, KC_O, KC_V)) {
    send_unicode_string("♥");
  } else if (leader_sequence_three_keys(KC_S, KC_T, KC_A)) {
    send_unicode_string("✶");
  } else if (leader_sequence_three_keys(KC_B, KC_U, KC_L)) {
    send_unicode_string("💡");
  } else if (leader_sequence_four_keys(KC_I, KC_N, KC_F, KC_O)) {
    send_unicode_string("ℹ️");

  } else if (leader_sequence_two_keys(KC_V, KC_V)) {
    send_unicode_string("✅");

  } else if (leader_sequence_one_key(KC_X)) {
    send_unicode_string("✗");
  } else if (leader_sequence_two_keys(KC_X, KC_B)) {
    send_unicode_string("✘");

  } else if (leader_sequence_one_key(KC_EXCLAIM)) {
    send_unicode_string("❗");
  } else if (leader_sequence_one_key(KC_QUESTION)) {
    send_unicode_string("❓");
  };
}
