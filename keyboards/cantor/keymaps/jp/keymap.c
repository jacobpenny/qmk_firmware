// todo
// next/previous tab in firefox (cmd + left)
// screenshots / videos
// min/max wezterm pane combo (shft+ctl+z)
// qmk info.json vs keyboard.json output wrong
#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum custom_keycodes {
    C_INTERPOLATE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO, KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_NO, KC_NO, KC_Z, KC_X, KC_C, ALL_T(KC_D), KC_V, KC_K, ALL_T(KC_H), KC_COMM, KC_DOT, KC_SLSH, KC_NO, MO(3), LT(1,KC_SPC), KC_TAB, KC_ENT, LT(2,KC_BSPC), KC_DEL),
    [1] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AMPR, KC_PLUS, KC_PERC, KC_MINS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_CIRC, KC_PGDN, KC_PGUP, KC_ASTR, KC_HASH, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_split_3x6_3(KC_NO, KC_GRV, KC_7, KC_8, KC_9, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_4, KC_5, KC_6, KC_BSLS, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_AT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_0, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DT_PRNT, DT_DOWN, DT_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_MSTP, KC_MPLY, KC_NO)
};

// Left side combos
const uint16_t PROGMEM combo_esc[] = {LCTL_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {LALT_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_grv[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_interpolate[] = {LALT_T(KC_R), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_cmdtab[] = {KC_X, KC_C, COMBO_END};
// Right side combos
const uint16_t PROGMEM combo_paren_open[] = {RSFT_T(KC_N), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_paren_close[] = {RSFT_T(KC_N), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_brace_open[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_brace_close[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_bracket_open[] = {ALL_T(KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_bracket_close[] = {ALL_T(KC_H), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_semi_colon[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_equals[] = {KC_COMM, KC_DOT, COMBO_END};
// Both side combos
const uint16_t PROGMEM combo_hyperx[] = {KC_Q, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_capsword[] = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_shiftctrlz[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM combo_hypers[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM combo_hyperv[] = {KC_B, KC_J, COMBO_END};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(2,KC_BSPC), KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
};

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
    COMBO(combo_minus, KC_MINUS),
    COMBO(combo_underscore, KC_UNDERSCORE),
    COMBO(combo_grv, KC_GRV),
    COMBO(combo_capsword, QK_CAPS_WORD_TOGGLE),
    COMBO(combo_interpolate, C_INTERPOLATE),
    COMBO(combo_cmdtab, LGUI(KC_TAB)),
    COMBO(combo_hyperx, HYPR(KC_X)),
    COMBO(combo_hypers, HYPR(KC_S)),
    COMBO(combo_hyperv, HYPR(KC_V)),
    COMBO(combo_shiftctrlz, LSFT(LCTL(KC_Z)))
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }


  switch (keycode) {
    case C_INTERPOLATE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("${}"SS_TAP(X_LEFT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }

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

