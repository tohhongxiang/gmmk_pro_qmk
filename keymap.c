#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "utils.h"
#include <stdint.h>
#include <math.h>
#include <print.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Delete
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

int counter = 0;

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        if (counter < COUNTER_MAX) {
            counter++;
        }

        tap_code(KC_VOLU);
    } else {
        if (counter > COUNTER_MIN) {
            counter--;
        }

        tap_code(KC_VOLD);
    }
    return true;
}
#endif  // ENCODER_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
    int currentLayer = biton32(state);

    switch (currentLayer) {
        case 1:
            rgblight_sethsv_noeeprom(PRIMARY_COLOR);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            break;
        default:
            rgblight_sethsv(PRIMARY_COLOR);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            break;
    }
    return state;
}

#ifdef RGB_MATRIX_ENABLE
// Capslock, Scroll lock and Numlock indicator on Left side lights.
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) { // on if Scroll lock is ON
    //     rgb_matrix_set_color(LED_L1, RGB_GREEN);
    //     rgb_matrix_set_color(LED_L2, RGB_GREEN);
    // }

    // if (!IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
    //     rgb_matrix_set_color(LED_L3, RGB_PURPLE);
    //     rgb_matrix_set_color(LED_L4, RGB_PURPLE);
    // }

    // Volume control
    for (uint8_t i = 0; i < counter_value_to_number_of_indicators(counter); i++) {
        HSV hsv = {SECONDARY_COLOR};
        hsv.v   = counter_value_to_brightness(counter);
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(LED_SIDE_LEFT[i], rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_SIDE_RIGHT[i], rgb.r, rgb.g, rgb.b);
    }

    // Caps lock enabled
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for (uint8_t i = 0; i < 8; i++) {
            rgb_matrix_set_color(LED_SIDE_LEFT[i], RGB_GREEN);
            rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_GREEN);
        }
    }

    if (keymap_config.no_gui) {
        rgb_matrix_set_color(LED_LWIN, RGB_RED);  // light up Win key when disabled
    }
}

void suspend_power_down_user(void) { rgb_matrix_set_suspend_state(true); }
void suspend_wakeup_init_user(void) { rgb_matrix_set_suspend_state(false); }

#endif

void matrix_init_user(void) {
    rgblight_sethsv(PRIMARY_COLOR);
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}

void keyboard_post_init_user(void) {
    //   Customise these values to desired behaviour
    // debug_enable   = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}