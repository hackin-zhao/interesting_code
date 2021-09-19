/**
 * ymodem.h
 * @author     johnny
 * @date       11.24 2017
 */
#ifndef _YMODEM_H_
#define _YMODEM_H_

#define FILE_NAME_MAX_LENGTH (256)
#define FILE_SIZE_MAX_LENGTH (16)

#define NAK_TIMEOUT (0x100000)
#define MAX_ERRORS (5)

typedef enum {
    PACKET_SIZE = 128,
    PACKET_1K_SIZE = 1024
} package_size;

typedef enum {
    SOH = 0x01, /* start of 128-byte data packet */
    STX = 0x02, /* start of 1024-byte data packet */
    EOT = 0x04, /* end of transmission */
} frame_type_t;

typedef enum {
    ACK = 0x06, /* acknowledge */
    NAK = 0x15, /* negative acknowledge */
    CA = 0x18, /* two of these in succession aborts transfer */
    CRC16 = 0x43 /* 'C' == 0x43, request 16-bit CRC */
} ack_type;

typedef struct
{
    uint8_t frame_type;
    uint8_t seq_num;
    uint8_t comp_seq_num; /* 将包序号取反 */
} ymodem_header;

typedef struct
{
    uint16_t crc;
} ymodem_tail;

typedef struct
{
    ymodem_header header;
    void* data;
    ymodem_tail tail;
} ymodem_package_t;

/* ymodem 第一包数据均被转换为字符串表示，以 00 隔开各个字段 */
typedef struct
{
    char* file_name;
    uint32_t file_size;
} ymodem_first_package;

typedef struct
{
    ymodem_first_package* first_package;
    intptr_t transport_handle;
} ymodem_t;

int8_t ymodem_init(ymodem_t* ymodem_struct);
int8_t ymodem_transmit_package(ymodem_t* ymodem_struct, frame_type_t type, package_size size);
int8_t ymodem_receive_package(ymodem_t* ymodem_struct, frame_type_t type, package_size size);

#endif
