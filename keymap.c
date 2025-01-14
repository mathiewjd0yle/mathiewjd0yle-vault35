/* Copyright 2021 projectcain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
enum layers{
  BASE,
  NUM,
  SYM,
  META
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_4space(

    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_A,    KC_S,    MT(MOD_LSFT, KC_D),    MT(MOD_LCTL, KC_F),    KC_G,    KC_H,    MT(MOD_LCTL, KC_J),    MT(MOD_LSFT, KC_K),    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
         KC_LSFT,      KC_LCTL, LT(NUM,KC_ENTER),  LT(NUM,KC_SPACE),   KC_LALT, KC_LEFT_GUI
  ),

  [NUM] = LAYOUT_split_4space(

      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_CAPS_LOCK,
      KC_GRAVE,    KC_MINUS,    KC_QUOTE,    KC_EQUAL,    KC_BSLS,    KC_LEFT,    KC_UP,    KC_DOWN,    KC_RIGHT,    QK_BOOT,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LBRC,    KC_RBRC,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
           KC_NO,            KC_NO,  KC_LSFT,      KC_LSFT,         KC_NO, KC_NO
  ),

  [SYM] = LAYOUT_split_4space(

         S(KC_GRV),    KC_GRV,    KC_BSLS,    S(KC_BSLS),    KC_TRNS,    KC_TRNS,    S(KC_MINS),    KC_EQL,    KC_TRNS,    C(KC_W),    C(KC_T),
     S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    KC_SCLN,    S(KC_SCLN),
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
            KC_TRNS,           KC_TRNS,   KC_TRNS,      KC_TRNS,        KC_NUM,    KC_TRNS
  ),

};


enum combos { 
  QW_COMBO, 
  AS_COMBO, 
  ZX_COMBO, 
  XC_COMBO, 
  CV_COMBO, 
  LS_COMBO, 
  DS_COMBO
};

const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};  // Q + W = ESC
const uint16_t PROGMEM combo_as[] = {KC_A, KC_S, COMBO_END};  // A + S = TAB
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};  // Z + X = CUT
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};  // X + C = COPY
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};  // C + V = PASTE
const uint16_t PROGMEM combo_ls[] = {KC_L, KC_SCLN, COMBO_END};  // L + ; = ENTER
const uint16_t PROGMEM combo_ds[] = {KC_DOT, KC_SLSH, COMBO_END};  // . + / = DELETE

combo_t key_combos[] = {
  [QW_COMBO] = COMBO(combo_qw, KC_ESC),       // Q + W = ESC
  [AS_COMBO] = COMBO(combo_as, KC_TAB),       // A + S = TAB
  [ZX_COMBO] = COMBO(combo_zx, LCTL(KC_X)),       // Z + X = CUT
  [XC_COMBO] = COMBO(combo_xc, LCTL(KC_C)),      // X + C = COPY
  [CV_COMBO] = COMBO(combo_cv, LCTL(KC_V)),     // C + V = PASTE
  [LS_COMBO] = COMBO(combo_ls, KC_ENTER),     // L + ; = ENTER
  [DS_COMBO] = COMBO(combo_ds, KC_DELETE),    // . + / = DELETE
  
};

void keyboard_post_init_user(void) {
    rgblight_enable(); 
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD); 
    rgblight_sethsv(RGBLIGHT_MODE_RAINBOW_MOOD); 
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
      [NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
      [SYM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif


