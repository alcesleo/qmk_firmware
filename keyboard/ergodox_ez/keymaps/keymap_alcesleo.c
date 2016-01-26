#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define DEFAULT 0 // Default layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |  -   |           |  +   |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |  Q   |  W   |  E   |  R   |  T   | Del  |           |Bkspc |  Y   |  U   |  I   |  O   |  P   |  Tab   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Bkspc  |  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  ;:  | Bkspc  |
 * |--------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+--------|
 * | LShift |  Z   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LEFT |RIGHT |                                       |  UP  | DOWN |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,----------------.   ,----------------.
 *                                       |Ctrl/Esc|Alt/Tab|   |Alt/Tab|Ctrl/Esc|
 *                                ,------|--------|-------|   |-------+--------+------.
 *                                |      |        |  Cmd  |   |  Cmd  |        |      |
 *                                |Enter | Shift  |-------|   |-------| Shift  |Space/|
 *                                |      |+OneShot|       |   |       |+OneShot|~MEDIA|
 *                                `-----------------------'   `-----------------------'
 */
[DEFAULT] = KEYMAP(
        // Left hand
        KC_NO,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5, KC_MINUS,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T, KC_DELETE,
        KC_BSPC,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B, KC_HOME,
        KC_NO,    KC_NO,    KC_NO,   KC_LEFT, KC_RGHT,

                                        CTL_T(KC_ESC), ALT_T(KC_TAB),
                                                             KC_LGUI,
                    KC_ENTER, ACTION_MODS_ONESHOT(MOD_LSFT), KC_NO,

        // Right hand
        KC_PLUS, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_NO,
        KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_TAB,
                 KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_BSPC,
        KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
                          KC_UP,   KC_DOWN, KC_LBRC,  KC_RBRC, KC_NO,

        ALT_T(KC_TAB), CTL_T(KC_ESC),
        KC_RGUI,
        KC_NO, ACTION_MODS_ONESHOT(MOD_LSFT), KC_SPACE
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    // [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
