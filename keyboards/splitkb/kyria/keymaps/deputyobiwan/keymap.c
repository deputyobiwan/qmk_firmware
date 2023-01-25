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
    * |       |   Q   |   W   |   F   |   P   |   B   |                                  |   J   |   L   |   U   |   Y   |   Ö   |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/A | ALT/R | CTR/S | SFT/T |   G   |                                  |   M   | SFT/N | CTR/E | ALT/I | SUP/O |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |   Z   |   X   |   C   |   D   |   V   |       |       |  |       |       |   K   |   H   |  , ;  |  . :  |  - _  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |SYM/Spc|NUM/Tab|  |MSE/Ent|NAV/Bsp|       |       |       |
    *                         `-----------------------------combo FUN-'  `----combo Del--------------------------------'
    */
     [_COLEMAK_DH] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * NAV_MED Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |  UP   |       |       |                                  |       |       | PGUP  |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | HOME  | LEFT  | DOWN  | RIGHT |  END  |                                  |       |       | PGDN  |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |VOL_PP |VOL_MTE|VOL_DN |VOL_UP |       |       |       |  |       |       |       | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |  CTR  |  SFT  |  |       |   X   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NAV_MED] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * MS Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       | MS_UP |       |       |                                  |       |MS_W_LF|MS_W_UP|MS_W_RT|       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |MS_LEFT|MS_DOWN|MS_RHT |       |                                  |MS_BT_3|MS_BT_1|MS_W_DN|MS_BT_2|MS_BT_4|       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |   X   |       |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_MS] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * SYM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |  & |  |  [ ]  |   `   |  / \  |  # ~  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |  § °  |   ^   |   %   |   @   |       |                                  |  $ €  |  ( )  |  " "  |   =   |   *   |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |  CUT  | PASTE | COPY  |       |       |       |  |       |       |   +   |  { }  |  ' '  |   <   |   >   |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |   X   |       |  |   !   |   ?   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_SYM] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * FUN Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  | MENU  |  F7   |  F8   |  F9   |  F10  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |                                  |       |  F4   |  F5   |  F6   |  F11  |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |  F1   |  F2   |  F3   |  F12  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |   X   |   X   |  |       |       |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_FUN] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if L3 & L4 got pressed
    state = update_tri_layer_state(state, _LAYER_3, _LAYER_4, _FUNC);

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
