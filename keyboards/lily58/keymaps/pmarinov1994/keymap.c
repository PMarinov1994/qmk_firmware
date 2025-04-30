#include <stdint.h>
#include "action_layer.h"
#include "config.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "oled_driver.h"
#include "quantum_keycodes.h"
#include "screen_art.h"
#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _L1,
  _L2,
  _GAMING,
};

// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  KC_LAYER_UP = QK_USER,
  KC_LAYER_DOWN,
  KC_GT_BASE_LAYER,
  KC_TG_LAYER_GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LCtrl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2, KC_3,    KC_4,    KC_5,                             KC_6,       KC_7,         KC_8,        KC_9,         KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W, KC_E,    KC_R,    KC_T,                             KC_Y,       KC_U,         KC_I,        KC_O,         KC_P,    KC_MINS,
  KC_ESC,   KC_A,   KC_S, SFT_T(KC_D), CTL_T(KC_F), KC_G,                     KC_H,       CTL_T(KC_J),  SFT_T(KC_K), ALT_T(KC_L),  GUI_T(KC_SCLN), KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,              KC_RBRC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                       KC_LGUI, KC_LALT, MO(_L1), KC_SPC,                    KC_ENT, MO(_L2), KC_BSPC, KC_RGUI
),


/* ############################################################################################################################################# */
/* ############################################################################################################################################# */
/* ############################################################################################################################################# */


/* _L1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/SF|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCtrl |   ?  |      |   ~  |   /  |  =   |-------|    |-------|   \  |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_L1] = LAYOUT(
  _______,       _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  SFT_T(KC_ESC), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______,       KC_QUES, _______, KC_TILD, KC_SLSH, KC_EQL,  _______, _______, KC_BSLS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                   _______, _______, XXXXXXX, _______, _______, KC_BSPC, KC_APP,  _______
),


/* ############################################################################################################################################# */
/* ############################################################################################################################################# */
/* ############################################################################################################################################# */


/* _L2
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * | PSCR |      |      |      |      |      |                    |      |      |      |      |      |TG_LAYER|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |ESC/SF|CTRL+C|CTRL+V| END  | HOME | DEL  |-------.    ,-------| Left | Down |  Up  |Right |      |        |
 * |------+------+------+------+------+------|Ctrl+Z |    |Ctrl+Y |------+------+------+------+------+--------|
 * |LCtrl |C+S+C |C+S+V | PGDN | PGUP |      |-------|    |-------|   +  |   -  |   ,  |   .  |   =  |   /    |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_L2] = LAYOUT(
  KC_PSCR, _______,    _______,    _______,        _______,       _______,                     _______, _______,        _______,      _______, _______, KC_TG_LAYER_GAMING,
  KC_TAB,  KC_1,       KC_2,       KC_3,           KC_4,          KC_5,                        KC_6,    KC_7,           KC_8,         KC_9,    KC_0,    XXXXXXX,
  _______, LCTL(KC_C), LCTL(KC_V), SFT_T(KC_HOME), CTL_T(KC_END), KC_DEL,                      KC_LEFT, CTL_T(KC_DOWN), SFT_T(KC_UP), KC_RGHT, KC_RGUI, XXXXXXX,
  _______, RCS(KC_C),  RCS(KC_V),  KC_PGDN,        KC_PGUP,       XXXXXXX, LCTL(KC_Z),    LCTL(KC_Y), KC_PLUS, KC_MINS,        KC_COMMA,     KC_DOT,    KC_EQL,  KC_SLASH,
                                                   _______, _______, KC_BSPC, _______,    _______,    XXXXXXX, _______, _______
),


/* ############################################################################################################################################# */
/* ############################################################################################################################################# */
/* ############################################################################################################################################# */


/* GAMING UNUSED FOR NOW
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TG_LAYER|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |------+------+------+------+------+------|   P   |    |    ]  |------+------+------+------+------+--------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | LCtrl  |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *                   |xxxxx |LShift| LAlt | /Space  /       \Enter \  |xxxxx |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAMING] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,        KC_8,        KC_9,    KC_0,    KC_TG_LAYER_GAMING,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,        KC_I,        KC_O,    KC_P,    KC_MINS,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    CTL_T(KC_J), SFT_T(KC_K), KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_P,            KC_RBRC,   KC_N,    KC_M,        KC_COMM,     KC_DOT,  KC_SLSH,  KC_RCTL,
                          KC_LSFT, KC_LSFT, KC_LALT, KC_SPC,          KC_ENT, KC_BSPC, KC_BSPC, KC_RGUI
  )
};


/* ############################################################################################################################################# */
/* ############################################################################################################################################# */
/* ############################################################################################################################################# */


// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _L1, _L2, _L3);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}


// When you add source files to SRC in rules.mk, you can use functions.
char layer_state_str[24];
const char *read_layer_state(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  switch (current_layer) {
    case _QWERTY:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base");
      break;
    case _L1:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: _L1");
      break;
    case _L2:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: _L2");
      break;
    case _GAMING:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: _GAMING");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Unknown");
      break;
  }

  return layer_state_str;
}

const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

const unsigned char *get_layer_art(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  switch (current_layer) {
    case _QWERTY:
      return img_layer_one;
    case _L1:
      return img_layer_two;
    case _L2:
      return img_layer_three;
    case _GAMING:
      return img_layer_four;
    default:
      return img_empty;
  }
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    // oled_write_ln(read_layer_state(), false);
    oled_set_cursor(0, 0);

    const unsigned char *img = get_layer_art();
    oled_write_raw_P((const char *) img, IMG_BUFF_SIZE);

    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_L1, KC_NO):
      {
        // This will handle all cased
        // Return false on tap to stop the chain
        // and return true on other cases to continue the defaut chain
        if (record->tap.count && record->event.pressed) {
          layer_invert(_L2);
          return false;
        }

        return true;
      }

    case KC_LAYER_UP:
      {
        // Our logic will happen on presses, nothing is done on releases
        if (!record->event.pressed)
          // We've already handled the keycode (doing nothing), let QK know so no further code is run unnecessarily
          return false;

        uint8_t current_layer = get_highest_layer(layer_state);

        // If we are on last layer, do nothing
        if (IS_LAYER_ON(_L2))
          return false;

        layer_on(current_layer + 1);

        return false;
      }

    case KC_LAYER_DOWN:
      {
        // Our logic will happen on presses, nothing is done on releases
        if (!record->event.pressed)
          // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
          return false;

        uint8_t current_layer = get_highest_layer(layer_state);

        // If we are on first layer, do nothing
        if (IS_LAYER_OFF(_L1))
          return false;

        layer_off(current_layer);

        return false;
      }
    case KC_TG_LAYER_GAMING:
      {
        // Our logic will happen on presses, nothing is done on releases
        if (!record->event.pressed)
          // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
          return false;

        if (IS_LAYER_OFF(_GAMING))
          layer_move(_GAMING);
        else {
          layer_move(_QWERTY);
          // layer_on(_L2);
        }

        return false;
      }
  }

  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
