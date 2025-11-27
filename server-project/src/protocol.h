/*
 * protocol.h
 *
 * Server header file
 * Definitions, constants and function prototypes for the server
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define SERVER_PORT 27015
#define BUFFER_SIZE 512
#define QUEUE_SIZE 5


typedef struct {
    char type;
    char city[64];
} weather_request_t;


typedef struct {
    unsigned int status;
    char type;
    float value;
} weather_response_t;

size_t getreqsize(void);
size_t getressize(void);
weather_response_t processReq(weather_request_t* req, struct sockaddr_in client);

float get_temperature(void);
float get_humidity(void);
float get_wind(void);
float get_pressure(void);

#endif /* PROTOCOL_H_ */
