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
    _QWERTZ,
    _NAV,
    _MSE,
    _MED,
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
    *                         |       |       |       |NAV/Spc|MSE/Tab|  |SYM/Ent|NUM/Bsp|       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_COLEMAK_DH] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * Base Layer: QWERTZ
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |   Q   |   W   |   E   |   R   |   T   |                                  |   Z   |   U   |   I   |   O   |   P   |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/A | ALT/S | CTR/D | SFT/F |   G   |                                  |   H   | SFT/J | CTR/K | ALT/L | SUP/Ö |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |   Y   |   X   |   C   |   V   |   B   |       |       |  |       |       |   N   |   M   |  , ;  |  . :  |  - _  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |NAV/Spc|MSE/Tab|  |SYM/Ent|NUM/Bsp|       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_QWERTZ] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

     /*
    * NAV Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NAV] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * MSE Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_MSE] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * MED Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_MED] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    /*
    * SYM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
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
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
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
    * |       |       |       |       |       |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | SUP/  | ALT/  | CTR/  | SFT/  |       |                                  |       |       |       |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       |       |       |       |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |SYM/Ent|NUM/Bsp|       |       |       |
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
