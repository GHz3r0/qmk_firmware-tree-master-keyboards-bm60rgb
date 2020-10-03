#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(1, KC_CAPS),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		OSM(MOD_LSFT),            KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  OSM(MOD_RSFT), KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT, OSL(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        TO(2),     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, BL_INC, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST, KC_PSLS,
        KC_TRNS,       RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, GUI_ON, GUI_OFF, NK_ON, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS,
        KC_TRNS,            RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_P1, KC_P2, KC_P3, KC_P0,        KC_VOLU, KC_MPLY,
        KC_TRNS,   TO(4),   KC_TRNS,                      KC_TRNS,                              KC_PDOT, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    ),
	[2] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,            KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,
        KC_LCTL,   KC_EQL,   KC_LALT,                       KC_SPC,                              KC_RALT, MO(3),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[3] = LAYOUT(
		KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        TO(2),     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, BL_INC, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST, KC_PSLS,
        KC_TRNS,       RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, NK_ON, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS,
        KC_TRNS,            RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_P1, KC_P2, KC_P3, KC_P0,        KC_VOLU, KC_MPLY,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                      KC_TRNS,                              KC_PDOT, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    ),
	[4] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
        TO(5),     KC_COPY, KC_MS_U, KC_PSTE, KC_FIND, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,       KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_BTN2,            KC_TRNS, KC_TRNS, KC_WSCH, KC_WBAK, KC_WFWD, KC_WREF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_WH_U, KC_MPLY,
        KC_TRNS,   TO(0),   KC_BTN1,                      KC_BTN1,                              KC_BTN1, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_R
    ),
	[5] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(1, KC_CAPS),       KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT,
		OSM(MOD_LSFT),            KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  OSM(MOD_RSFT), KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT, OSL(6),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[6] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        TO(0),     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, BL_INC, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST, KC_PSLS,
        KC_TRNS,       RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, GUI_ON, GUI_OFF, NK_ON, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS,
        KC_TRNS,            RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_P1, KC_P2, KC_P3, KC_P0,        KC_VOLU, KC_MPLY,
        KC_TRNS,   TO(4),   KC_TRNS,                      KC_TRNS,                              KC_PDOT, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    ),
	
};
