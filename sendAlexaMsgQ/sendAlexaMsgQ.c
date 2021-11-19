/*
 * Copyright 2021 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>

#define QUEUE_NAME "/avs_states_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

#define CHECK(x) \
        do { \
                if (!(x)) { \
                        fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
                        perror(#x); \
                        exit(-1); \
                } \
        } while (0) \

int main(int argc, char **argv){
	mqd_t mq;
	char buffer[MAX_SIZE];

	/* open the mail queue */
	mq = mq_open(QUEUE_NAME, O_WRONLY);
	CHECK((mqd_t)-1 != mq);

	printf("Sending %s %d\n", argv[1], strlen(argv[1]));
	memcpy(buffer, argv[1], strlen(argv[1]));

	/* send the message */
	CHECK(0 <= mq_send(mq, buffer, strlen(argv[1]), 0));

	/* cleanup */
	CHECK((mqd_t)-1 != mq_close(mq));

	return 0;
}
