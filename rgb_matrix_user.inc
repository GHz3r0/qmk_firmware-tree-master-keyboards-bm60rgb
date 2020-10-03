RGB_MATRIX_EFFECT(UNDERGLOW_LAYER)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

uint8_t uLayer;
uint8_t oldLayer;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
		case 0:
			uLayer = 1;
			
			break;
		case 1:
			uLayer = 2;
			
			break;
		case 2:
			uLayer = 3;
			
			break;
		case 3:
			uLayer = 2;
			
			break;
		case 4:
			uLayer = 5;
			
			break;
		case 5:
			uLayer = 6;
			
			break;
		case 6: 
			uLayer = 2;
			
			break;
		default:
			uLayer = 1;
			
			break;
	}
	return state;
	return uLayer;
	oldLayer = uLayer;
	return oldLayer;
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock == 1) {
        uLayer = 7;
    } 
	if (led_state.caps_lock == 0) {
		//uLayer = oldLayer;
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
				case 1:
					rgb_matrix_set_color(i, RGB_MAGENTA);
					break;
				case 2:
					rgb_matrix_set_color(i, RGB_RED);
					break;
				case 3:
					rgb_matrix_set_color(i, RGB_PINK);
					break;
				case 4:
					rgb_matrix_set_color(i, RGB_TEAL);
					break;
				case 5:
					rgb_matrix_set_color(i, RGB_GREEN);
					break;
				case 6:
					rgb_matrix_set_color(i, 30, 250, 200);
					break;
				case 7:
					rgb_matrix_set_color(i, RGB_BLUE);
					break;
				default:
					rgb_matrix_set_color(i, RGB_GOLD);
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