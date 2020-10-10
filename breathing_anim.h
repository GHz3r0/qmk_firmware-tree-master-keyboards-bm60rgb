#ifndef DISABLE_RGB_MATRIX_BREATHING
RGB_MATRIX_EFFECT(BREATHING)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define _WMAN 0
#define _QW 1
#define _GAME 2
#define _MOUSE 3
#define _FN 4
#define _CAPS 5

uint8_t uLayer;
uint8_t oldLayer;

bool BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = hsv_to_rgb(hsv);
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
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
		}
	}
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_BREATHING
