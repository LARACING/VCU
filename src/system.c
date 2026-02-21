/**
 * @file system.c
 * @brief Implementation of core helpers and aggregation moved out of main.c
 */

#include "main.h"

int internal_process(int i) {
    return i;
}

int system_aggregate(int input) {
    /* initialize modules (example no-ops) */
    braking_init();
    connection_init();
    cooling_init();
    emergency_shutdown_init();
    error_init();
    logging_init();
    steering_init();
    validation_init();

    int sum = internal_process(input);
    sum += braking_compute(input);
    sum += connection_compute(input);
    sum += cooling_compute(input);
    sum += emergency_shutdown_compute(input);
    sum += error_compute(input);
    sum += logging_compute(input);
    sum += steering_compute(input);
    sum += validation_compute(input);

    return sum;
}
