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
    _COLEMAK_DH,
    _NEO,
    _QWERTZ = 0,
    _GAMING,
    _LAYER_3,
    _LAYER_4,
    _FUNC
};

uint8_t base_layers[5] = {_COLEMAK_DH, _NEO, _QWERTZ, _GAMING};
uint8_t current_base_layer = _QWERTZ;

/*
// Tap Dance declarations
enum {
    TD_GUI_STRG,
    TD_ALT_SHIFT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GUI_STRG] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LCTRL),
    [TD_ALT_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LSFT),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * Base Layer: Colemak-DH
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Ö  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |SHFT/A|GUI/R | ALT/S|STRG/T| L4/G |                              | L4/M |STRG/N| ALT/E|GUI/I |SHFT/O|Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Z  |   X  |   C  | L3/D  |   V  |L3/ESC|L4/ESC|  |L4/F5 |L3/F5 |   K  | L3/H  | , ;  | . :  |  - _ | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_COLEMAK_DH] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_Q,         KC_W,         KC_F,         KC_P,               KC_B,                                                                 /**/                                             DE_J,               KC_L,               KC_U,         DE_Y,         DE_ODIA,      ALGR_T(DE_UDIA),
            KC_LSFT,              LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T),       LT(_LAYER_4, KC_G),                                                   /**/                                             LT(_LAYER_4, KC_M), LCTL_T(KC_N),       LALT_T(KC_E), LGUI_T(KC_I), RSFT_T(KC_O), RSFT_T(DE_ADIA),
            KC_LCTRL,             DE_Z,         KC_X,         KC_C,         LT(_LAYER_3, KC_D), KC_V,               LT(_LAYER_4, KC_ESCAPE), LT(_LAYER_3, KC_ESCAPE), /**/ LT(_LAYER_4, KC_F5),  LT(_LAYER_3, KC_F5),  KC_K,               LT(_LAYER_3, KC_H), KC_COMM,      KC_DOT,       DE_MINS,      RCTL_T(DE_SS),
                                                              KC_MPLY,      KC_LGUI,            KC_LALT,            LT(_LAYER_3, KC_SPC),    LT(_LAYER_4, KC_ENT),    /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),

    /*
    * Base Layer: Neo
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   X  |   V  |   L  |  C   |   W  |                              |   K  |  H   |   G  |   F  |   Q  |ß/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |SHFT/U|GUI/I | ALT/A|STRG/E| L4/O |                              | L4/S |STRG/N| ALT/R|GUI/T |SHFT/D|Y/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Ü  |   Ö  |   Ä  | L3/P |   Z  |L3/ESC|L4/ESC|  |L4/F5 |L3/F5 |   B  | L3/M | , ;  | . :  |   J  |-_ /RCtl|
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_NEO] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_X,         KC_V,         KC_L,         KC_C,               KC_W,                                                              /**/                                             DE_K,               KC_H,               KC_G,         KC_F,         KC_Q,         ALGR_T(DE_SS),
            KC_LSFT,              LSFT_T(KC_U), LGUI_T(KC_I), LALT_T(KC_A), LCTL_T(KC_E),       LT(_LAYER_4, KC_O),                                                /**/                                             LT(_LAYER_4, KC_S), LCTL_T(KC_N),       LALT_T(KC_R), LGUI_T(KC_T), LSFT_T(KC_D), RSFT_T(DE_Y),
            KC_LCTRL,             DE_UDIA,      DE_ODIA,      DE_ADIA,      LT(_LAYER_3, KC_P), DE_Z,               LT(_LAYER_4, KC_ESCAPE), MO(_LAYER_3),         /**/ LT(_LAYER_4, KC_F5),  LT(_LAYER_3, KC_F5),  KC_B,               LT(_LAYER_3, KC_M), KC_COMM,      KC_DOT,       KC_J,         RCTL_T(DE_MINS),
                                                              KC_MPLY,      KC_LGUI,            KC_LALT,            LT(_LAYER_3, KC_SPC),    LT(_LAYER_4, KC_ENT), /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),

    /*
    * Base Layer: QWERTZ
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   Q  |   W  |   E  |  R   |   T  |                              |   Z  |  U   |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |SHFT/A|GUI/S |ALT/D |STRG/F| L4/G |                              | L4/H |STRG/J| ALT/K| GUI/L|SHFT/Ö|Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Y  |   X  |   C  | L3/V |   B  |L3/ESC|L4/ESC|  |L4/F5 |L3/F5 |   N  | L3/M | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_QWERTZ] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,                                                           /**/                                             DE_Z,               KC_U,               KC_I,         KC_O,         KC_P,            ALGR_T(DE_UDIA),
            KC_LSFT,              LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),       LT(_LAYER_4, KC_G),                                             /**/                                             LT(_LAYER_4, KC_H), LCTL_T(KC_J),       LALT_T(KC_K), LGUI_T(KC_L), RSFT_T(DE_ODIA), RSFT_T(DE_ADIA),
            KC_LCTRL,             DE_Y,         KC_X,         KC_C,         LT(_LAYER_3, KC_V), KC_B,               LT(_LAYER_4, KC_ESC), LT(_LAYER_3, KC_ESC), /**/ LT(_LAYER_4, KC_F5),  LT(_LAYER_3, KC_F5),  KC_N,               LT(_LAYER_3, KC_M), KC_COMM,      KC_DOT,       DE_MINS,         RCTL_T(DE_SS),
                                                              KC_MPLY,      KC_LGUI,            KC_LALT,            LT(_LAYER_3, KC_SPC), LT(_LAYER_4, KC_ENT), /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),

    /*
    * Base Layer: Gaming, Overwatch, Isaac
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |  tab   |   Q  |   A  |   W  |   D  |   E  |                              |   Z  | left |   up | right|   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |    X   |LShift|   A  |   S  |   D  |   R  |                              |   H  | left | down | right|   Ö  |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |    Y   |LCtrl |   X  |   C  |   V  |   F  |  esc | esc  |  | LAY5 | FUNC |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      | SYM  |NAVNUM|  | SYM  |NAVNUM|      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_GAMING] = LAYOUT(
            KC_TAB,   KC_Q,   KC_A,   KC_W,   KC_D,   KC_E,                         /**/                                             DE_Z,     KC_LEFT, KC_UP,   KC_RIGHT, KC_P,    ALGR_T(DE_UDIA),
            KC_X,  KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_R,                         /**/                                             KC_H,     KC_LEFT, KC_DOWN, KC_RIGHT, DE_ODIA, RSFT_T(DE_ADIA),
            KC_Y, KC_LCTRL,   KC_X,   KC_C,   KC_V,   KC_F, KC_ESCAPE, KC_ESCAPE,   /**/ MO(_FUNC),         LT(_LAYER_3, KC_F5),  KC_N,     KC_M,    KC_COMM, KC_DOT,   DE_MINS, RCTL_T(DE_SS),
                                   KC_MPLY, KC_LGUI, KC_LALT, KC_SPC      , KC_ENT, /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,  KC_DEL,  KC_MUTE
    ),

    /*
    * Layer 3 symbols
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |   °  |   _  |   [  |   ]  |   ^  |                              |   !  |   <  |   >  |   =  |   &  |   §    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |   \  |   /  |   {  |   }  |   *  |                              |   ?  |   (  |   )  |   -  |   :  |   @    |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |   #  |   $  |   |  |   ~  |   `  |      |      |  |      |      |   +  |   %  |   "  |   '  |   ;  |   €    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_3] = LAYOUT(
        _______, DE_DEG, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                      DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
        _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                     DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
        _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV , _______, _______, _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, DE_EURO,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
    * Layer 4 Nav and Numpad
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |   esc  | PgUp | Bksp |  up  | del  | PgDn |                              |   *  |   7  |   8  |   9  |   +  |   -    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        | home | left | down | right| end  |                              |   /  |   4  |   5  |   6  |   .  |   ;    | // TODO: Tap Dance ./, -> :/;
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |  esc |  tab |insert|Mouse1|MS up | MS r |      |  |      |      |   :  |   1  |   2  |   3  |   ,  |   =    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |Mouse2| MS l | MS d |      |  |      |   0  |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_4] = LAYOUT(
        KC_ESCAPE, KC_PGUP, KC_BSPC, KC_UP,     KC_DELETE, KC_PGDOWN,                   /**/                   DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS, DE_MINS,
        _______,   KC_HOME, KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_END,                      /**/                   DE_SLSH, KC_4, KC_5, KC_6, KC_DOT,  DE_SCLN,
        _______,   KC_ESC,  KC_TAB,  KC_INSERT, KC_BTN1,   KC_MS_U,   KC_MS_R, _______, /**/ _______, _______, DE_COLN, KC_1, KC_2, KC_3, KC_COMM, DE_EQL,
                                       _______, KC_BTN2,   KC_MS_L,   KC_MS_D, _______, /**/ _______, KC_0,    _______, _______, _______
    ),

    /*
    * Adjust Layer: Function keys, RGB, media
    *
    * ,----------------------------------------------.                              ,-------------------------------------------.
    * |  QWERTZ   |      |      |      |BRI DN|BRI UP|                              |      |  F7  |  F8  |  F9  | F10  |  F11   |
    * |--------+------+------+------+------+-----...-|                              |------+------+------+------+------+--------|
    * |  NEO      | TOG  | SAI  | HUI  | VAI  | MOD  |                              | VolUp|  F4  |  F5  |  F6  | F11  |  F12   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-----------|
    * |  COLEMAK  |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      | VolDn|  F1  |  F2  |  F3  | F12  |        |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+-------------------------'
    *                        |      | Prev | Next |      |      |  |      |      | Prev | Next |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_FUNC] = LAYOUT(
        DF(_QWERTZ)    , XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                   /**/                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        DF(_NEO)       , RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                   /**/                   KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F12,
        DF(_COLEMAK_DH), XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, /**/ _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12, XXXXXXX,
                                           _______, KC_MPRV, KC_MNXT, _______, _______, /**/ _______, _______, KC_MPRV, KC_MNXT, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

};

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if  L3 & L4 got pressed
    state = update_tri_layer_state(state, _LAYER_3, _LAYER_4, _FUNC);

    return state;
}
