#include QMK_KEYBOARD_H

#define _WMAN 0
#define _QW 1
#define _GAME 2
#define _MOUSE 3
#define _FN 4
#define _CAPS 5

uint8_t uLayer;
uint8_t oldLayer;

enum {
	TD_LRTG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_WMAN] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_BSPC,       KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT, KC_ENT,
		LT(4, KC_CAPS),            KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  OSM(MOD_RSFT), KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                  MT(MOD_LSFT, KC_SPC),                KC_RALT, TD(TD_LRTG),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QW] = LAYOUT(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_BSPC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		LT(4, KC_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  OSM(MOD_RSFT), KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                   MT(MOD_LSFT, KC_SPC),            KC_RALT,  TD(TD_LRTG),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[_GAME] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                      KC_SPC,                         KC_RALT, TD(TD_LRTG), KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[_MOUSE] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
        TO(0),     KC_COPY, KC_MS_U, KC_PSTE, KC_FIND, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS,       KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_BTN2,            KC_NO, KC_NO, KC_WSCH, KC_WBAK, KC_WFWD, KC_WREF, KC_NO, KC_NO, KC_NO, KC_BTN1,        KC_WH_U, KC_BTN2,
        KC_TRNS,   KC_LGUI,   KC_BTN1,                      KC_BTN1,                         KC_RALT,  TD(TD_LRTG), KC_WH_L, KC_WH_D, KC_WH_R
    ),
	[_FN] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_TRNS,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, KC_ASTG, GUI_OFF, GUI_ON, KC_P7, KC_P8, KC_P9, UC(0x00E4), UC(0x00F6), UC(0x00FC),
        KC_TRNS,       RGB_VAI, RGB_SPI, NK_ON, KC_ASUP, KC_ASDN, KC_ASRP, KC_NO, KC_P4, KC_P5, KC_P6, UC(0x00DF), KC_TRNS,
        KC_TRNS,            RGB_M_P, RGB_M_A, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, KC_P1, KC_P2, KC_P3, KC_P0,        KC_PGUP, KC_MPLY,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                      KC_TRNS,                              KC_PDOT, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    ),
}; 

layer_state_t layer_state_set_user(layer_state_t state) { 
    switch (get_highest_layer(state)) {
		case _WMAN:
			uLayer = _WMAN;
			oldLayer = uLayer;
			autoshift_enable();
			break;
		case _QW:
			uLayer = _QW;
			oldLayer = uLayer;
			autoshift_enable();
			break;
		case _GAME:
			uLayer = _GAME;
			oldLayer = uLayer;
			autoshift_disable();
			break;
		case _MOUSE:
			uLayer = _MOUSE;
			oldLayer = uLayer;
			autoshift_disable();
			break;
		case _FN:
			uLayer = _FN;
			oldLayer = uLayer;
			break;
		default:
			uLayer = _WMAN;
			oldLayer = uLayer;
			autoshift_enable();
			break;
	}
	return state;
	return uLayer;
	return oldLayer;
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock == 1) {
        uLayer = _CAPS;
    } 
	if (led_state.caps_lock == 0) {
		uLayer = oldLayer;
	}
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case RGB_M_A:
			if (record->event.pressed) {
				rgb_matrix_mode(RGB_MATRIX_CUSTOM_UNDERGLOW_LAYER);
			}
			return false;
		default:
			return true;
	}
	return true;
};

bool fn_held;
void dance_layers(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->pressed)
  {
	layer_on(_FN);
    fn_held = true;
  }
  switch (state->count)
  {
  case 1: //off all layers, just base on
	if(!state->pressed){
		layer_on(_WMAN);
		layer_off(_FN);
		layer_off(_QW);
		layer_off(_GAME);
		layer_off(_MOUSE);
		fn_held = false;
	}
	break;
  case 2: 
		layer_off(_WMAN);
		layer_off(_FN);
		layer_on(_QW);
		layer_off(_GAME);
		layer_off(_MOUSE);
    break;
  case 3:
		layer_off(_WMAN);
		layer_off(_FN);
		layer_off(_QW);
		layer_on(_GAME);
		layer_off(_MOUSE);
    break;
	case 4:
		layer_off(_WMAN);
		layer_off(_FN);
		layer_off(_QW);
		layer_off(_GAME);
		layer_on(_MOUSE);
  }
}
void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (fn_held)
  {
    layer_off(_FN);
    fn_held = false;
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_LRTG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_finish)
};

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}