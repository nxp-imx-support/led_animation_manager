/*
 * Copyright 2021 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef COMMON_H_
#define COMMON_H_

#define QUEUE_NAME "/avs_states_queue"
#define MAX_SIZE 16
#define MSG_STOP "exit"

#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
            perror(#x); \
            exit(-1); \
        } \
    } while (0) \

#endif /* #ifndef COMMON_H_ */
