/*
  Copyright (c) 2023

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include QMK_KEYBOARD_H
#include "oneday.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_5x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Del  |   A  |S /CTL|D /ALT|F /CMD|   G  |                                  |   H  |J /CMD|K /ALT|L /CTL|   ;  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | Shft |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    / KC_DEL/---------------.    .---------------\KC_BSPC\    |      |      |
   *               |      |      |   /       / Space / Enter /      \ Enter \ Space \       \   |      |      |
   *               '-------------'  '-------/ Shift /       /        \       \ Shift \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /   =   / Home  /            \  End  \   -   \
   *                                     /   +   /       /              \       \   _   \
   *                                    '---------------'                '---------------'
   */
   KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
   KC_DEL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                     XXXXXXX, XXXXXXX,          KC_DEL , KC_SPC, KC_ENT  , KC_ENT , KC_SPC , KC_BSPC,          XXXXXXX, XXXXXXX,
                                                         KC_EQL, KC_HOME , KC_END , KC_MINS
   ),

  [SYMB] = LAYOUT_5x6_5(
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_F11,
     _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_PIPE,                                        _______, KC_7,    KC_8,     KC_9,   _______, KC_F12,
     _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_GRV,                                         _______, KC_4,    KC_5,     KC_6,   _______, _______,
     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                        _______, KC_1,    KC_2,     KC_3,   _______, _______,
                       KC_F7,            _______, _______, _______, _______,    KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,  KC_ENT,
                                                           _______, _______,    KC_VOLD, _______
  ),

  [VIM] = LAYOUT_5x6_5(
     _______, QK_BOOT, _______, _______, _______, _______,                                         _______, _______, _______, _______, QK_BOOT, _______,
     _______, _______, _______, _______, KC_LSFT, _______,                                         _______, _______, _______, _______, _______, _______,
     _______, DLEFT,   DRIGHT,  KC_LCTL, KC_LGUI, _______,                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
                       _______,          _______, _______,_______, _______,     TG(GAME), _______, _______, _______,          _______,
                                                          _______, _______,     _______,  _______
  ),

  [GAME] = LAYOUT_5x6_5(
     KC_ESC, KC_1,    KC_2,    KC_3,  KC_4,    KC_5,                                          KC_6,    KC_7,     KC_8,         KC_9,   KC_0,    KC_MINS,
     KC_T,   KC_TAB,  KC_Q,    KC_W,  KC_E,    KC_R,                                          KC_Y,    KC_U,     KC_I,         KC_O,   KC_P,    KC_BSLS,
     KC_G,   KC_LCTL, KC_A,    KC_S,  KC_D,    KC_F,                                          KC_H,    KC_J,     KC_K,         KC_L,   KC_SCLN, KC_QUOT,
     KC_B,   KC_LSFT, KC_Z,    KC_X,  KC_C,    KC_V,                                          KC_N,    KC_M,     KC_COMM,      KC_DOT, KC_SLSH, KC_RSFT,
                      QK_LOCK,        KC_LALT, KC_SPC, KC_ENT,  KC_GRV,    TG(GAME), _______, _______, _______,                KC_EQL,
                                                       KC_BSPC, KC_F5,     KC_F6,    _______
  ),
};

uint32_t quote_timer;

void keyboard_post_init_user(void) { quote_timer = 0; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_process_keycode(keycode);
    return !try_handle_macro(keycode, record);
}

void render_led_status(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock || led_state.caps_lock || led_state.scroll_lock) {
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    }
}

void render_mods_status(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    bool    ctrl = mods & MOD_MASK_CTRL;
    bool    shft = mods & MOD_MASK_SHIFT;
    bool    alt  = mods & MOD_MASK_ALT;
    bool    gui  = mods & MOD_MASK_GUI;

    oled_write_P(ctrl ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P(shft ? PSTR("SHIFT ") : PSTR("      "), false);
    oled_write_P(alt ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_ln_P(gui ? PSTR("GUI ") : PSTR("    "), false);
}

#define MAX_LINES 8

void write_quote(const char* data, const uint8_t num_lines) {
    uint8_t current_line = 0;
    for (; current_line < (MAX_LINES - num_lines) / 2; current_line++) {
        oled_advance_page(true);
    }

    oled_write_ln_P(data, false);

    for (current_line += num_lines; current_line < MAX_LINES; current_line++)
    {
        oled_advance_page(true);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // On the left, control the volume. On the right, scroll the page
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
