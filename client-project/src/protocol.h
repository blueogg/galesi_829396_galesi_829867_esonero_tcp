/*
 * protocol.h
 *
 * Client header file
 * Definitions, constants and function prototypes for the client
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define SERVER_PORT 27015
#define BUFFER_SIZE 512

#define STATUS_OK 0
#define STATUS_CITY_NOT_FOUND 1
#define STATUS_INVALID_REQUEST 2

typedef struct {
    char type;
    char city[64];
} weather_request_t;

typedef struct {
    unsigned int status;
    char type;
    float value;
} weather_response_t;

weather_request_t* requestCreate(const char richiesta[]);
size_t getreqsize(void);
size_t getressize(void);
void printarray(const char a[]);

#endif /* PROTOCOL_H_ */
