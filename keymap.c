#include QMK_KEYBOARD_H

#include <stdio.h>

#include "keymap_uk.h"
#include "lily58.h"

// NOTE: This layout is designed for UK keymaps, and as such may not produce the
//       expected symbols on the symbol layer for non-EN_GB layouts.

enum layer_number {
  _QWERTY = 0,
  _SYMBOLS,
  _NAV,
  _MACROS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (default)
 * ,-------------------------------------------.                    ,-------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -     |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =     |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |LCTRL   |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+--------|
 * |LSHIFT/(|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSHIFT/)|
 * `-------------------------------------------/       /    \       \-------------------------------------------'
 *                    | LGUI | LALT |SYMBOLS| / Space /      \ Enter \  |NAV | RALT | BKSPC |
 *                    |      | ([)  |       |/       /        \       \ |    | (])  |       |
 *                    `-----------------------------'          '-------''-------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_GRV,          KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,          KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_LCTL,         KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO,         KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, UK_LCBR,     UK_RCBR,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
                                KC_LGUI, LALT_T(KC_LBRC), TT(1), KC_SPC,  KC_ENT, TT(2), RALT_T(KC_RBRC), KC_BSPC
  ),

/* SYMBOLS/F-KEYS
 * ,-------------------------------------.                    ,-----------------------------------.
 * | ESC   |  F1 |  F2 |  F3 |  F4 |  F5 |                    | F6  | F7  | F8  | F9  | F10 |     |
 * |-------+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
 * |CAPSLCK| F11 | F12 | F13 | F14 | F15 |                    | F16 | F17 | F18 | F19 | F20 |     |
 * |-------+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
 * |LCTRL  |  !  |  @  |  #  |  $  |  %  |-------.    ,-------|  ^  |  &  |  *  |  -  |  +  |     |
 * |-------+-----+-----+-----+-----+-----|   <   |    |   >   |-----+-----+-----+-----+-----+-----|
 * |LSHIFT |     |     |  `  |  ~  |     |-------|    |-------|     |  \  |  |  |  /  |     |     |
 * `-------------------------------------/       /    \       \-----------------------------------'
 *              | LGUI | LALT |SYMBOLS| / Space /      \ Enter \  |NAV | RALT | DEL |
 *              |      | ([)  |       |/       /        \       \ |    | (])  |     |
 *              `-----------------------------'          '-------''-----------------'
 */

  [_SYMBOLS] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
    KC_CAPS,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                     KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,   KC_NO,
    KC_LCTL,  KC_EXLM, UK_AT,   UK_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,  KC_NO,
    KC_LSFT,  KC_NO,   KC_NO,   KC_GRV,  UK_TILD, KC_NO,   KC_LT,   KC_GT,    KC_NO,   UK_BSLS, UK_PIPE, KC_SLSH, KC_NO,    KC_NO,
                          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_DEL
  ),

/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |MOUSEU|      |MOUSE5|                    |SCRLLT|SCRLDN|SCRLUP|SCRLRT|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |MOUSEL|MOUSED|MOUSER|MOUSE4|-------.    ,-------| LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|MOUSE2 |    | MENU  |------+------+------+------+------+------|
 * |LSHIFT|      |ACCEL0|ACCEL1|ACCEL2|MOUSE3|-------|    |-------| HOME | PGDN | PGUP | END  |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                  | LGUI | LALT |SYMBOLS| /MOUSE1 /      \ Enter \  |NAV | RALT | DEL |
 *                  |      | ([)  |       |/       /        \       \ |    | (])  |     |
 *                  `-----------------------------'          '-------''-----------------'
 */

  [_NAV] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_BTN5,                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO,
    KC_LCTL, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
    KC_LSFT, KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN3,  KC_BTN2,  KC_APP,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
                          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_BTN1,  KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL
  ),

/* MACROS/NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |POWER |SLEEP | WAKE |      |      |      |                    |  7   |  8   |  9   |  -   |  *   | VOL+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  4   |  5   |  6   |      |  /   | VOL- |
 * |------+------+------+------+------+------|                    |------+------+------+  +   +------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  1   |  2   |  3   |      |  =   | MUTE |
 * |------+------+------+------+------+------|KB_RST |    |       |------+------+------+------+------+------|
 * | PLAY | PREV | NEXT |      |      |      |-------|    |-------|      0      |  .   |ENTER |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                  | LGUI | LALT |SYMBOLS| / Space /      \ Enter \  |NAV | RALT | BKSPC |
 *                  |      | ([)  |       |/       /        \       \ |    | (])  |       |
 *                  `-----------------------------'          '-------''-------------------'
 */
  [_MACROS] = LAYOUT(
    KC_PWR,   KC_SLEP,   KC_WAKE,   KC_NO,   KC_NO,   KC_NO,                    KC_P7,   KC_P8,   KC_P9,   KC_PMNS,   KC_PAST,   KC_VOLU,
    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,   KC_PSLS,   KC_VOLD,
    KC_NO,    KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,                    KC_P1,   KC_P2,   KC_P3,   KC_PPLS,   KC_EQL,    KC_MUTE,
    KC_MPLY,  KC_MPRV,   KC_MNXT,   KC_NO,   KC_NO,   KC_NO,  RESET,    KC_NO,  KC_P0,   KC_P0,   KC_PDOT, KC_PENT,   KC_NO,     KC_NO,
                            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS
  )
};

/* LAYER TEMPLATE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *                  | LGUI | LALT |SYMBOLS| / Space /      \ Enter \  |NAV | RALT | BKSPC |
 *                  |      | ([)  |       |/       /        \       \ |    | (])  |       |
 *                  `-----------------------------'          '-------''-------------------'
 */
//  [_XXXX] = LAYOUT(
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                             _______, _______, _______, _______, _______,  _______, _______, _______
//  )
//};

// -----------------------------------------------------------------------------
// Custom Functionality
// -----------------------------------------------------------------------------

// Make it so that tapping/holding both layer keys will enable access to the
// macros layer.
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOLS, _NAV, _MACROS);
}

// The functions below update various OLED display features. Make sure to
// set OLED_ENABLE to `yes` in rules.mk if you have an OLED display on your
// Lily.

#ifdef OLED_ENABLE
char layer_state_str[24];

// OLED output to set the layer name. Uses the layer_state_str buffer declared
// declared above
const char *read_layer_state(void) {
  #define LILY58_CBISCUIT_BASE_LAYER_BIT 0
  #define LILY58_CBISCUIT_SYMBOL_LAYER_BIT (1 << 1)
  #define LILY58_CBISCUIT_NAVIGATION_LAYER_BIT (1 << 2)
  #define LILY58_CBISCUIT_MACRO_LAYER_BIT (1 << 3)
  #define LILY58_CBISCUIT_TRI_LAYER_STATE_BITS LILY58_CBISCUIT_MACRO_LAYER_BIT | LILY58_CBISCUIT_NAVIGATION_LAYER_BIT | LILY58_CBISCUIT_SYMBOL_LAYER_BIT

  switch (layer_state)
  {
  case LILY58_CBISCUIT_BASE_LAYER_BIT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ---");
    break;
  case LILY58_CBISCUIT_SYMBOL_LAYER_BIT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SYMBOLS");
    break;
  case LILY58_CBISCUIT_NAVIGATION_LAYER_BIT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: NAVIGATION");
    break;
  case LILY58_CBISCUIT_MACRO_LAYER_BIT:
  case LILY58_CBISCUIT_TRI_LAYER_STATE_BITS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MACROS");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}

//SSD1306 OLED update loop. Adapted from the default configuration.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_host_led_state(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE
