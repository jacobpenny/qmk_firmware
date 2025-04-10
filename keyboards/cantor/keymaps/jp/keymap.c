#include QMK_KEYBOARD_H
#include "features/achordion.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_split_3x6_3(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO, KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_NO, KC_NO, KC_Z, KC_X, KC_C, ALL_T(KC_D), KC_V, KC_K, ALL_T(KC_H), KC_COMM, KC_DOT, KC_SLSH, KC_NO, MO(3), LT(1,KC_SPC), KC_TAB, KC_ENT, LT(2,KC_BSPC), KC_DEL),
        [1] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AMPR, KC_PLUS, KC_PERC, KC_MINS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_CIRC, KC_PGDN, KC_PGUP, KC_ASTR, KC_HASH, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
        [2] = LAYOUT_split_3x6_3(KC_NO, KC_GRV, KC_7, KC_8, KC_9, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_4, KC_5, KC_6, KC_BSLS, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_AT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_0, KC_NO, KC_NO, KC_NO),
        [3] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_MSTP, KC_MPLY, KC_NO)
};

const uint16_t PROGMEM combo_paren_open[] = {RSFT_T(KC_N), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_paren_close[] = {RSFT_T(KC_N), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_brace_open[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_brace_close[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_bracket_open[] = {ALL_T(KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_bracket_close[] = {ALL_T(KC_H), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_semi_colon[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_equals[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_exclamation[] = {RSFT_T(KC_N), RGUI_T(KC_O), COMBO_END};

const uint16_t PROGMEM combo_esc[] = {LCTL_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_F, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_paren_open, KC_LPRN),
    COMBO(combo_paren_close, KC_RPRN),
    COMBO(combo_brace_open, KC_LCBR),
    COMBO(combo_brace_close, KC_RCBR),
    COMBO(combo_bracket_open, KC_LBRC),
    COMBO(combo_bracket_close, KC_RBRC),
    COMBO(combo_colon, KC_COLN),
    COMBO(combo_semi_colon, KC_SCLN),
    COMBO(combo_equals, KC_EQUAL),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_exclamation, KC_EXCLAIM),
    COMBO(combo_minus, KC_MINUS),
    COMBO(combo_underscore, KC_UNDERSCORE),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  switch (other_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        other_keycode &= 0xff;  // Get base keycode.
  }

    // Allow same-hand holds with non-alpha keys.
    if (other_keycode > KC_Z) { return true; }

    return achordion_opposite_hands(tap_hold_record, other_record);
}
