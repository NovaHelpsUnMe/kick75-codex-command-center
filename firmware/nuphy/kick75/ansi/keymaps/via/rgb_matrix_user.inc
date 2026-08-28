
RGB_MATRIX_EFFECT(game_mode)
RGB_MATRIX_EFFECT(position_mode)
RGB_MATRIX_EFFECT(kitt_scanner)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern rgb_config_t rgb_matrix_config;

static bool game_mode(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if(i<80)
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);       // ESC

    rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);      // W
    rgb_matrix_set_color(45, rgb.r, rgb.g, rgb.b);      // D
    rgb_matrix_set_color(46, rgb.r, rgb.g, rgb.b);      // S
    rgb_matrix_set_color(47, rgb.r, rgb.g, rgb.b);      // A

    rgb_matrix_set_color(70, rgb.r, rgb.g, rgb.b);      // up
    rgb_matrix_set_color(77, rgb.r, rgb.g, rgb.b);      // right
    rgb_matrix_set_color(78, rgb.r, rgb.g, rgb.b);      // down
    rgb_matrix_set_color(79, rgb.r, rgb.g, rgb.b);      // left

    return rgb_matrix_check_finished_leds(led_max);
}

static bool position_mode(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if(i<80)
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);

    rgb_matrix_set_color(48, rgb.r, rgb.g, rgb.b);      // F
    rgb_matrix_set_color(51, rgb.r, rgb.g, rgb.b);      // J
    rgb_matrix_set_color(70, rgb.r, rgb.g, rgb.b);      // UP

    return rgb_matrix_check_finished_leds(led_max);
}

#define KITT_KEY_LED_COUNT 80
#define KITT_MAX_X 153

static uint8_t kitt_scanner_position(void) {
    uint8_t phase    = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16) >> 2);
    uint8_t triangle = (phase & 0x80) ? (uint8_t)((255 - phase) << 1) : (uint8_t)(phase << 1);

    return (uint8_t)(((uint16_t)triangle * KITT_MAX_X) / 254);
}

static uint8_t kitt_scanner_brightness(uint8_t distance) {
    const uint8_t maximum = rgb_matrix_config.hsv.v;

    if (distance <= 3) {
        return maximum;
    }
    if (distance <= 12) {
        return scale8(maximum, 160);
    }
    if (distance <= 22) {
        return scale8(maximum, 72);
    }
    if (distance <= 34) {
        return scale8(maximum, 24);
    }

    return scale8(maximum, 6);
}

static bool kitt_scanner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const uint8_t scanner_x = kitt_scanner_position();

    for (uint8_t i = led_min; i < led_max; i++) {
        if (i >= KITT_KEY_LED_COUNT) {
            continue;
        }

        const uint8_t led_x      = g_led_config.point[i].x;
        const uint8_t distance   = led_x > scanner_x ? led_x - scanner_x : scanner_x - led_x;
        const uint8_t brightness = kitt_scanner_brightness(distance);

        rgb_matrix_set_color(i, brightness, 0, 0);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
