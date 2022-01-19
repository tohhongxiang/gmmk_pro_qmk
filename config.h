#pragma once

#define USB_POLLING_INTERVAL_MS 1
#define PRIMARY_COLOR 72, 89, 218
#define SECONDARY_COLOR 175, 175, 175

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Sets the default mode, if none has been set
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
    #define RGB_DISABLE_TIMEOUT 900000     // 15 minutes (15 * 60 * 1000ms)
    // Effects
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // Heatmap, Rain
    #define RGB_MATRIX_KEYPRESSES           // REACTIVE, SPLASH modes

    #define RGBLIGHT_DEFAULT_HUE 220
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL RGBLIGHT_LIMIT_VAL
#endif // RGB_MATRIX_ENABLE
