#ifndef UTILS_H
#define UTILS_H

#include "rgb_matrix_map.h"

int COUNTER_MIN    = 0;
int COUNTER_MAX    = 50;
int BRIGHTNESS_MIN = 0;
int BRIGHTNESS_MAX = 255;
int NUMBER_OF_INDICATORS_FOR_VOLUME_MINIMUM = 0;
size_t NUMBER_OF_INDICATORS_FOR_VOLUME_MAXIMUM = sizeof(LED_SIDE_LEFT)/sizeof(LED_SIDE_LEFT[0]);

int map_input_between_ranges(int input, int input_min, int input_max, int output_min, int output_max) {
    return output_min + ((double)(output_max - output_min) / (input_max - input_min)) * (input - input_min);
}
int counter_value_to_brightness(int value) { return map_input_between_ranges(value, COUNTER_MIN, COUNTER_MAX, BRIGHTNESS_MIN, BRIGHTNESS_MAX); }
int counter_value_to_number_of_indicators(int value) { return map_input_between_ranges(value, COUNTER_MIN, COUNTER_MAX, NUMBER_OF_INDICATORS_FOR_VOLUME_MINIMUM, NUMBER_OF_INDICATORS_FOR_VOLUME_MAXIMUM); }

#endif