/* Copyright 2021 Daniel Ostertag (Dakes) <dakes@vivaldi.net>
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
#include "keymap_german.h"
#include <string.h>

enum layers
{
    _COLEMAK_DH = 0,
    _NAV_MED,
    _MS,
    _SYM,
    _NUM,
    _FUN
};

enum custom_keycodes {
  MOUSEJIGGLERMACRO
};

bool mouse_jiggle_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * Base Layer: Colemak-DH
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |   Q   |   W   |   F   |   P   |   B   |                                  |   J   |   L   |  U Ü  |   Y   |   ß   |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |  A Ä  | ALT/R | CTR/S | SFT/T | SUP/G |                                  | SUP/M | SFT/N | CTR/E | ALT/I |  O Ö  |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |   Z   |   X   |   C   |   D   |   V   |       |       |  |       |       |   K   |   H   |  , ;  |  . :  |  - _  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |SYM/Spc|NUM/Ent|  |MS/Tab|NAV/Bsp|       |       |       |
    *                         `-----------------------------combo FUN-'  `----combo Del--------------------------'
    */
     [_COLEMAK_DH] = LAYOUT(
       KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B,                                  KC_J, KC_L, KC_U, KC_Y, DE_SS, KC_NO,
       KC_NO, KC_A, LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LGUI_T(KC_G),                                  LGUI_T(KC_M), RSFT_T(KC_N), CTL_T(KC_E), LALT_T(KC_I), KC_O, KC_NO,
       KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_NO, KC_NO,      KC_NO, KC_NO, KC_K, KC_H, KC_COMMA, KC_DOT, KC_MINUS, KC_NO,
                            KC_NO, KC_NO, KC_NO, LT(_SYM,KC_SPACE), LT(_NUM,KC_ENTER),      LT(_MS,KC_TAB), LT(_NAV_MED,KC_BACKSPACE), KC_NO, KC_NO, KC_NO
    ),

    /*
    * NAV_MED Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |  UP   |       |       |                                  |  ESC  |       | PGUP  |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | HOME  | LEFT  | DOWN  | RIGHT |  END  |                                  |  Bsp  |       | PGDN  |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |VOL_PP |VOL_MTE|VOL_DN |VOL_UP |       |       |       |  |       |       |  Del  | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |  CTR  |  SFT  |  |       |   X   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NAV_MED] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO,                                  KC_ESCAPE, KC_NO, KC_PAGE_UP, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                                  KC_BACKSPACE, KC_NO, KC_PAGE_DOWN, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_DELETE, KLCTL(KC_C), LCTL(KC_V), LCTL(KC_X), KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_LCTL, KC_LSFT,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * MS Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       | MS_UP |       |       |                                  |       |MS_W_LF|MS_W_UP|MS_W_RT|       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |MS_LEFT|MS_DOWN|MS_RHT |       |                                  |BRO_BAK|MS_BT_1|MS_W_DN|MS_BT_2|BRO_FWD|       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |   X   |       |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_MS] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_MS_UP, KC_NO, KC_NO,                                  KC_NO, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO,                                  KC_WWW_BACK, KC_MS_BTN1, KC_MS_WH_DOWN, KC_MS_BTN2, KC_WWW_FORWARD, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * SYM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |  ESC  |                                  |  & |  |  [ ]  |   `   |  / \  |  # ~  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |  § °  |   ^   |   %   |   @   |  Bsp  |                                  |  $ €  |  ( )  |  " "  |   =   |   *   |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |  CUT  | PASTE | COPY  |  Del  |       |       |  |       |       |   +   |  { }  |  ' '  |   <   |   >   |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |   X   |       |  |   !   |   ?   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_SYM] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESCAPE,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BACKSPACE,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, LCTL(KC_X), LCTL(KC_V), LCTL(KC_C), KC_DELETE, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * NUM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |   7   |   8   |   9   |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |                                  |       |   4   |   5   |   6   |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |  CUT  | PASTE | COPY  |       |       |       |  |       |       |       |   1   |   2   |   3   |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |   X   |  |       |   0   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NUM] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
       KC_NO, KC_NO, LCTL(KC_X), LCTL(KC_V), LCTL(KC_C), KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_0, KC_NO, KC_NO, KC_NO
    ),

    /*
    * FUN Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  | MENU  |  F7   |  F8   |  F9   |  F10  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |JIGGLE |       |                                  |       |  F4   |  F5   |  F6   |  F11  |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |  F1   |  F2   |  F3   |  F12  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |   X   |   X   |  |       |       |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_FUN] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_MENU, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, MOUSEJIGGLERMACRO, KC_NO,                                  KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _SYM, _NUM, _FUN); // this will switch to layer _FUN, if _SYM & _NUM got pressed
  return state;
}

void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    SEND_STRING(SS_DELAY(10));
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    SEND_STRING(SS_DELAY(30));
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(0,KC_U):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(DE_UDIA); // Intercept hold function to send ü
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_A):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(DE_ADIA); // Intercept hold function to send ä
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_O):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(DE_ODIA); // Intercept hold function to send ö
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_COMMA):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_SEMICOLON); // Intercept hold function to send ;
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_DOT):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_COLON); // Intercept hold function to send :
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_MINUS):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_UNDERSCORE); // Intercept hold function to send _
        return false;
      }
      return true;             // Return true for normal processing of tap keycode
    case MOUSEJIGGLERMACRO:
      if (record->event.pressed) {
        if (mouse_jiggle_mode) {
          SEND_STRING(SS_DELAY(15));
          mouse_jiggle_mode = false;
          SEND_STRING("Deactivated");
        } else {
          SEND_STRING(SS_DELAY(15));
          mouse_jiggle_mode = true;
          SEND_STRING("Activated");
        }
      }
      break;
  }
  return true;
}
