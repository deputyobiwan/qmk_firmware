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

// Layers
enum layers
{
    _COLEMAK_DH = 0,
    _NAV_MED,
    _MS,
    _SYM,
    _NUM,
    _FUN
};

// Custom keys
#define U_Ü_MACRO LT(0, KC_U)
#define A_Ä_MACRO LT(0, KC_A)
#define O_Ö_MACRO LT(0, KC_O)
#define COMMA_SEMICOLON_MACRO LT(0, KC_COMMA)
#define DOT_COLON_MACRO LT(0, KC_DOT)
#define MINUS_UNDERSCORE_MACRO LT(0, KC_SLSH)

#define TWO_POWER_MACRO LT(_NUM, KC_2)
#define THREE_CUBE_MACRO LT(_NUM, KC_3)

// Custom keys with kc placeholders
// See also https://getreuer.info/posts/keyboards/triggers/index.html
#define DOLLAR_EURO_MACRO LT(_SYM, KC_1)
#define AND_PIPE_MACRO LT(_SYM, KC_2)
#define ACUT_GRAVE_MACRO LT(_SYM, KC_3)
#define SLASH_BACKSLASH_MACRO LT(_SYM, KC_4)
#define HASH_TILD_MACRO LT(_SYM, KC_5)
#define SECT_DEG_MACRO LT(_SYM, KC_6)

#define PARENTHESIS_MACRO LT(_SYM, KC_7)
#define BRACKETS_MACRO LT(_SYM, KC_8)
#define CURLY_BRACKETS_MACRO LT(_SYM, KC_9)

// Custom feature-keys
enum custom_keycodes {
  MOUSEJIGGLERMACRO = SAFE_RANGE,
  GITST,
  GITDF,
  GITCM,
  GITAP,
  GITPL,
  GITPS,
  GITBA,
  GITCH,
  GITRS,
  GITSE,
  GITSH,
  GITSP,
  GITRE,
};
bool mouse_jiggle_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * _COLEMAK_DH base layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |   Q   |   W   |   F   |   P   |   B   |                                  |   J   |   L   |  U Ü  |   Y   |   ß   |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |  A Ä  | ALT/R | CTR/S | SFT/T | SUP/G |                                  | SUP/M | SFT/N | CTR/E | ALT/I |  O Ö  |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |   Z   |   X   |   C   |   D   |   V   |       |       |  |       |       |   K   |   H   |  , ;  |  . :  |  - _  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |NUM/Ent|SYM/Spc|       |  |       |NAV/Bsp|MS/Tab |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_COLEMAK_DH] = LAYOUT(
       KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B,                                                                                                  KC_J, KC_L, U_Ü_MACRO, DE_Y, DE_SS, KC_NO,
       KC_NO, A_Ä_MACRO, LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LGUI_T(KC_G),                                    LGUI_T(KC_M), RSFT_T(KC_N), CTL_T(KC_E), LALT_T(KC_I), O_Ö_MACRO, KC_NO,
       KC_NO, DE_Z, KC_X, KC_C, KC_D, KC_V, KC_NO, KC_NO,                                                             KC_NO, KC_NO, KC_K, KC_H, COMMA_SEMICOLON_MACRO, DOT_COLON_MACRO, MINUS_UNDERSCORE_MACRO, KC_NO,
                          KC_NO, KC_NO, LT(_NUM,KC_ENTER), LT(_SYM,KC_SPACE), KC_NO,      KC_NO, LT(_NAV_MED,KC_BACKSPACE), LT(_MS,KC_TAB), KC_NO, KC_NO
    ),

    /*
    * _NAV_MED Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |  UP   |       |       |                                  |  ESC  |       | PGUP  |       |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | HOME  | LEFT  | DOWN  | RIGHT |  END  |                                  |  Del  |       | PGDN  |       |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |VOL_PP |VOL_MTE|VOL_DN |VOL_UP |       |       |       |  |       |       |  Bsp  | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |  CTR  |  SFT  |       |  |       |   X   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NAV_MED] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO,                                                                                KC_ESCAPE, KC_NO, KC_PAGE_UP, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                                                                 KC_DELETE, KC_NO, KC_PAGE_DOWN, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_BACKSPACE, LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_LCTL, KC_LSFT, KC_NO,                                              KC_NO, KC_TRANSPARENT, KC_NO, KC_NO, KC_NO
    ),

    /*
    * _MS Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       | MS_UP |       |       |                                  |       |MS_W_LF|MS_W_UP|MS_W_RT|       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |MS_LEFT|MS_DOWN|MS_RHT |       |                                  |BRO_BAK|MS_BT_1|MS_W_DN|MS_BT_2|BRO_FWD|       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |       |       |  |       |       |       | COPY  | PASTE |  CUT  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |       |       |       |  |       |       |   X   |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_MS] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_MS_UP, KC_NO, KC_NO,                                                         KC_NO, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO,                                  KC_WWW_BACK, KC_MS_BTN1, KC_MS_WH_DOWN, KC_MS_BTN2, KC_WWW_FORWARD, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                        KC_NO, KC_NO, KC_NO, LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, KC_NO
    ),

    /*
    * _SYM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |  ESC  |                                  |  & |  |  [ ]  |  ´ `  |  / \  |  # ~  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |  § °  |   ^   |   %   |   @   |  Del  |                                  |  $ €  |  ( )  |  " "  |   =   |   *   |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |  CUT  | PASTE | COPY  |  Bsp  |       |       |  |       |       |   +   |  { }  |  ' '  |   <   |   >   |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       | Trans |   X   |       |  |       |   !   |   ?   |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_SYM] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESCAPE,                                                      AND_PIPE_MACRO, BRACKETS_MACRO, ACUT_GRAVE_MACRO, SLASH_BACKSLASH_MACRO, HASH_TILD_MACRO, KC_NO,
       KC_NO, SECT_DEG_MACRO, DE_CIRC, DE_PERC, DE_AT, KC_DELETE,                                                   DOLLAR_EURO_MACRO, PARENTHESIS_MACRO, DE_DQUO, DE_EQL, DE_ASTR, KC_NO,
       KC_NO, KC_NO, LCTL(KC_X), LCTL(KC_V), LCTL(KC_C), KC_BACKSPACE, KC_NO, KC_NO,           KC_NO, KC_NO, DE_PLUS, CURLY_BRACKETS_MACRO, DE_QUOT, DE_LABK, DE_RABK, KC_NO,
                            KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                              KC_NO, DE_EXLM, DE_QUES, KC_NO, KC_NO
    ),

    /*
    * _NUM Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       |       |       |       |       |       |                                  |       |   7   |   8   |   9   |       |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       |       |       |       |       |       |                                  |       |   4   |   5   |   6   |       |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       |       |  CUT  | PASTE | COPY  |       |       |       |  |       |       |       |   1   |  2 ²  |  3 ³  |       |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |   X   | Trans |       |  |       |   0   |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_NUM] = LAYOUT(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                       KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                       KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
       KC_NO, KC_NO, LCTL(KC_X), LCTL(KC_V), LCTL(KC_C), KC_NO, KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO, KC_1, TWO_POWER_MACRO, THREE_CUBE_MACRO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                           KC_NO, KC_0, KC_NO, KC_NO, KC_NO
    ),

    /*
    * _FUN Layer
    *
    * .-----------------------------------------------.                                  .-----------------------------------------------.
    * |       | GITSP | GITRE | GITBA | GITPS |       |                                  | MENU  |  F7   |  F8   |  F9   |  F10  |       |
    * |-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
    * |       | GITAP | GITCM | GITDF | GITST |JIGGLER|                                  |       |  F3   |  F5   |  F6   |  F11  |       |
    * |-------+-------+-------+-------+-------+-------+---------------.  .---------------+-------+-------+-------+-------+-------+-------|
    * |       | GITSH | GITRS | GITCH | GITPL | GITSE |       |       |  |       |       |       |  F1   |  F2   |  F3   |  F12  |       |
    * `-----------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-----------------------'
    *                         |       |       |   X   |   X   |       |  |       |       |       |       |       |
    *                         `---------------------------------------'  `---------------------------------------'
    */
     [_FUN] = LAYOUT(
       KC_NO, GITSP, GITRE, GITBA, GITPS, KC_NO,                                               KC_MENU, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
       KC_NO, GITAP, GITCM, GITDF, GITST, MOUSEJIGGLERMACRO,                                     KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
       KC_NO, GITSH, GITRS, GITCH, GITPL, GITSE, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO,
                            KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
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

// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

// Helper for implementing tap vs. long-press of non-kc keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_no_kc_key(keyrecord_t* record, uint16_t tap_press_keycode, uint16_t long_press_keycode) {
  if (record->tap.count > 0) {    // Key is being tapped.
    if (record->event.pressed) {
      register_code16(tap_press_keycode); // Handle tap press event...
    } else {
      unregister_code16(tap_press_keycode);// Handle tap release event...
    }    
  } else {                        // Key is being held.
    if (record->event.pressed) {
      register_code16(long_press_keycode); // Handle tap press event...
    } else {
      unregister_code16(long_press_keycode);// Handle tap release event...
    }
  }
  return false;  // Skip default handling.
}

/* Currently not in use
// Helper for implementing wrapper-symbols, e.g. printing "(" as first_string_keycode, then ")" as second_string_keycode and
// then moving in between those strings with KC_LEFT.
static bool process_tap_press_string_wrapper_key(keyrecord_t* record, uint16_t first_string_keycode, uint16_t second_string_keycode) {
  if (record->tap.count && record->event.pressed) {
    tap_code16(first_string_keycode);
    tap_code16(second_string_keycode);
    tap_code16(KC_LEFT);
  }
  return false;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Base Macros
    case U_Ü_MACRO:
      return process_tap_or_long_press_key(record, DE_UDIA);

    case A_Ä_MACRO:
      return process_tap_or_long_press_key(record, DE_ADIA);

    case O_Ö_MACRO:
      return process_tap_or_long_press_key(record, DE_ODIA);

    case COMMA_SEMICOLON_MACRO:
      return process_tap_or_long_press_key(record, DE_SCLN);

    case DOT_COLON_MACRO:
      return process_tap_or_long_press_key(record, DE_COLN);

    case MINUS_UNDERSCORE_MACRO:
      return process_tap_or_long_press_key(record, DE_UNDS);

    // _SYM Macros
    case PARENTHESIS_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_LPRN, DE_RPRN);

    case BRACKETS_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_LBRC, DE_RBRC);

    case CURLY_BRACKETS_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_LCBR, DE_RCBR);

    case DOLLAR_EURO_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_DLR, DE_EURO);

    case AND_PIPE_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_AMPR, DE_PIPE);

    case ACUT_GRAVE_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_ACUT, DE_GRV);

    case SLASH_BACKSLASH_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_SLSH, DE_BSLS);

    case HASH_TILD_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_HASH, DE_TILD);

    case SECT_DEG_MACRO:
      return process_tap_or_long_press_no_kc_key(record, DE_SECT, DE_DEG);

    // _NUM Macros
    case TWO_POWER_MACRO:
      return process_tap_or_long_press_key(record, DE_SUP2);

    case THREE_CUBE_MACRO:
      return process_tap_or_long_press_key(record, DE_SUP3);

    // _FUN Macros
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

    case GITST:
      if (record->event.pressed) {
        SEND_STRING("git status");
        tap_code16(KC_ENTER);
      }
      break;

    case GITDF:
      if (record->event.pressed) {
        SEND_STRING("git diff");
        tap_code16(KC_ENTER);
      }
      break;

    case GITCM:
      if (record->event.pressed) {
        SEND_STRING("git commit /am "); // This needs to be "/", so it converts to "-"
        tap_code16(LSFT(DE_2));
        tap_code16(LSFT(DE_2));
        tap_code16(KC_LEFT);
      }
      break;

    case GITAP:
      if (record->event.pressed) {
        SEND_STRING("git add /p ."); // This needs to be "/", so it converts to "-"
        tap_code16(KC_ENTER);
      }
      break;

    case GITPL:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        tap_code16(KC_ENTER);
      }
      break;

    case GITPS:
      if (record->event.pressed) {
        SEND_STRING("git push");
      }
      break;

    case GITBA:
      if (record->event.pressed) {
        SEND_STRING("git branch /avv"); // This needs to be "/", so it converts to "-"
        tap_code16(KC_ENTER);
      }
      break;

    case GITCH:
      if (record->event.pressed) {
        SEND_STRING("git checkout ");
      }
      break;

    case GITRS:
      if (record->event.pressed) {
        SEND_STRING("git restore .");
      }
      break;

    case GITSE:
      if (record->event.pressed) {
        SEND_STRING("git checkout master; git pull; git remote prune origin; git branch /avv");
        tap_code16(KC_ENTER);
      }
      break;

    case GITSH:
      if (record->event.pressed) {
        SEND_STRING("git stash");
        tap_code16(KC_ENTER);
      }
      break;

    case GITSP:
      if (record->event.pressed) {
        SEND_STRING("git stash pop");
        tap_code16(KC_ENTER);
      }
      break;

    case GITRE:
      if (record->event.pressed) {
        SEND_STRING("git reset HEAD");
        tap_code16(DE_TILD);
        SEND_STRING("1");
      }
      break;
  }
  return true;
}
