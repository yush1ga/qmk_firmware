#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE  0
#define META1 1
#define META2 2

#define IMPORT 0
#define AS 1
#define FROM 2
#define NUMPY 3
#define PANDAS 4
#define SKLEARN 5

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case IMPORT:
        SEND_STRING("import");
        break;
      case AS:
        SEND_STRING("as");
        break;
      case FROM:
        SEND_STRING("from");
        break;
      case NUMPY:
        SEND_STRING("import numpy as np");
        break;
      case PANDAS:
        SEND_STRING("import pandas as pd");
        break;
      case SKLEARN:
        SEND_STRING("pip install scikit-learn");
        break;
    }
  }
  return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   `  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  | -    | =    |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | META2| Tab  |   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  | '    | Bksp |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | META1| LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  UP  | Enter|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | BASE | LCtrl| LAlt | LGUI | META1| META2|Space |   |Space | META2| META1| RGUI | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_ESC,    KC_GRV,  KC_Q,    KC_W,    KC_E,      KC_R,      KC_T,      KC_Y,   KC_U,      KC_I,      KC_O,    KC_P,    KC_MINS, KC_EQL, \
    DF(META2), KC_TAB,  KC_A,    KC_S,    KC_D,      KC_F,      KC_G,      KC_H,   KC_J,      KC_K,      KC_L,    KC_SCLN, KC_QUOT, KC_BSPC, \
    DF(META1), KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,      KC_B,      KC_N,   KC_M,      KC_COMM,   KC_DOT,  KC_SLSH, KC_UP,   KC_ENT, \
    DF(BASE),  KC_LCTL, KC_LALT, KC_LGUI, MO(META1), MO(META2), KC_SPC,    KC_SPC, MO(META2), MO(META1), KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  /* META1
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |   1  |   2  |   3  |   4  |  5   |   |  6   |   7  |   8  |   9  |   0  |   -  |  =   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   | Left | Down |  Up  |Right |      |   `  |  \   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META1] = LAYOUT( \
    _______,   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, \
    DF(META2), _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_GRV,  KC_BSLS, \
    DF(META1), KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    DF(BASE),  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* META2
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META2] = LAYOUT( \
    _______,   _______, _______, _______, _______, _______, M(IMPORT),    M(PANDAS),  _______, _______, _______, _______, _______, _______, \
    DF(META2), _______, _______, _______, _______, _______, M(AS),        M(NUMPY),   _______, _______, _______, _______, _______, _______, \
    DF(META1), _______, _______, _______, _______, _______, M(FROM),      M(SKLEARN), _______, _______, _______, _______, _______, _______, \
    DF(BASE),  _______, _______, _______, _______, _______, _______,      _______,    _______, _______, _______, _______, _______, _______ \
  )

};
