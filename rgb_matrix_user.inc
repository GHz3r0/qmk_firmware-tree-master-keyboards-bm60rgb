RGB_MATRIX_EFFECT(UNDERGLOW_LAYER)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define _WMAN 0
#define _QW 1
#define _GAME 2
#define _MOUSE 3
#define _FN 4
#define _CAPS 5

uint8_t uLayer;
uint8_t oldLayer;

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

bool UNDERGLOW_LAYER(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);
	HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = hsv_to_rgb(hsv);
    hsv.h += rgb_matrix_config.speed;
    RGB rgb2 = hsv_to_rgb(hsv);
	
	for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            switch(uLayer) {
				case _WMAN:
					rgb_matrix_set_color(i, RGB_GREEN);
					break;
				case _FN:
					rgb_matrix_set_color(i, RGB_RED);
					break;
				case _QW:
					rgb_matrix_set_color(i, RGB_MAGENTA);
					break;
				case _GAME:
					rgb_matrix_set_color(i, RGB_GOLD);
					break;
				case _MOUSE:
					rgb_matrix_set_color(i, RGB_CYAN);
					break;
				case _CAPS:
					rgb_matrix_set_color(i, RGB_BLUE);
					break;
				default:
					rgb_matrix_set_color(i, RGB_PINK);
					break;
			}
        } else {
			if(HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
				rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
            } else {
				rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
			}
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS