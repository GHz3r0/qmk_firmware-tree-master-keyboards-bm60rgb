#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
RGB_MATRIX_EFFECT(ALPHAS_MODS)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// alphas = color1, mods = color2

#define _WMAN 0
#define _QW 1
#define _GAME 2
#define _MOUSE 3
#define _FN 4
#define _CAPS 5

uint8_t uLayer;
uint8_t oldLayer;

bool ALPHAS_MODS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = hsv_to_rgb(hsv);
    hsv.h = rgb_matrix_config.speed; // +=
    RGB rgb2 = hsv_to_rgb(hsv);
	
	switch(uLayer){
		case _WMAN:
			hsv.h = 85;
			break;
		case _FN:
			hsv.h = 0;
			break;
	}
	uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
	hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
	RGB rgb3       = hsv_to_rgb(hsv);


    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
		if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            /*switch(uLayer) {
				case _WMAN:
					
					rgb_matrix_set_color(i, rgb3.r, rgb3.g, rgb3.b);
					//rgb_matrix_set_color(i, RGB_GREEN);
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
			}*/
			rgb_matrix_set_color(i, rgb3.r, rgb3.g, rgb3.b);
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

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_ALPHAS_MODS
