/**
 * @file main.h
 * @brief Internal helper declarations for example functionality.
 * @date 2025-11-09
 * @version 1.0
 */

#ifndef MAIN_H
#define MAIN_H

/**
 * @brief Internal helper that processes a single character.
 *
 * @param i Integer to process.
 * @return Processed integer result.
 */
int internal_process(int i);

/* Module public headers */
#include "braking/main.h"
#include "connection/main.h"
#include "cooling/main.h"
#include "emergency_shutdown/main.h"
#include "error/main.h"
#include "logging/main.h"
#include "steering/main.h"
#include "validation/main.h"

/**
 * @brief Aggregate system call that runs all module computations.
 *
 * @param input Integer input forwarded to all modules.
 * @return Sum of results from all modules and internal processing.
 */
int system_aggregate(int input);

#endif /* MAIN_H */
