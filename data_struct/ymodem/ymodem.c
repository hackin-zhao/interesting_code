/**
 * ymodem.c
 * @author     johnny
 * @date       11.24 2017
 */
#include "ymodem.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static void send_package(intptr_t handle, uint8_t* data, uint16_t length);
static void receive_package(uint8_t* data, uint16_t length);
static void file_write_to(FILE* fp, uint16_t length);
static void file_read_from(FILE* fp, uint16_t length);

typedef struct
{
    uint8_t cmd;
    fptr_receive cb;
} command_cb;

command_cb command_receive_callback = {
    { ACK, ack_receive },
    { NAK, nak_receive },
    { CA, NULL },
    { CRC16, crc16_receive }
};

void process_cmd(command_cb* cb, fptr_receive fun)
{
}

/**
  * @brief  Update CRC16 for input byte
  * @param  CRC input value
  * @param  input byte
  * @retval Updated CRC value
  */
static uint16_t UpdateCRC16(uint16_t crcIn, uint8_t byte)
{
    uint32_t crc = crcIn;
    uint32_t in = byte | 0x100;

    do {
        crc <<= 1;
        in <<= 1;

        if (in & 0x100) {
            ++crc;
        }

        if (crc & 0x10000) {
            crc ^= 0x1021;
        }
    } while (!(in & 0x10000));

    return (crc & 0xffffu);
}

/**
  * @brief  Cal CRC16 for YModem Packet
  * @param  data
  * @param  length
  * @retval CRC value
  */
static uint16_t Cal_CRC16(uint8_t* data, uint32_t size)
{
#if 1
    uint32_t crc = 0;
    const uint8_t* dataEnd = data + size;

    while (data < dataEnd) {
        crc = UpdateCRC16(crc, *data++);
    }
    crc = UpdateCRC16(crc, 0);
    crc = UpdateCRC16(crc, 0);

    return (crc & 0xffffu);
#else
    return crc16_ibm(data, (int32_t)size);
#endif
}

/**
  * @brief  Convert an Integer to a string
  * @param  str: The string
  * @param  intnum: The intger to be converted
  * @retval None
  */
static void Int2Str(uint8_t* str, int32_t intnum)
{
    uint32_t i, Div = 1000000000, j = 0, Status = 0;

    for (i = 0; i < 10; i++) {
        str[j++] = (intnum / Div) + 48;

        intnum = intnum % Div;
        Div /= 10;
        if ((str[j - 1] == '0') & (Status == 0)) {
            j = 0;
        } else {
            Status++;
        }
    }
}

/**
  * @brief  Prepare the first block
  * @param  timeout
  * @retval None
  */
static struct ymodem_package_t Ymodem_PrepareIntialPacket(ymodem_t* ymodem_struct)
{
    ymodem_package ret;
    uint8_t data[PACKET_SIZE] = { 0 };
    uint8_t i, j;
    uint8_t file_ptr[FILE_SIZE_MAX_LENGTH];

    if (!ymodem_struct) {
        return NULL;
    }

    /* Make first three packet */
    ret.header.frame_type = SOH;
    ret.header.seq_num = 0x00;
    ret.header.comp_seq_num = 0xff;

    /* Filename packet has valid data */
    for (i = 0; (ymodem_struct->ymodem_first_package->fileName[i] != '\0') && (i < FILE_NAME_MAX_LENGTH); i++) {
        data[i] = fileName[i];
    }

    data[i] = 0x00;

    Int2Str(file_ptr, ymodem_struct->ymodem_first_package->file_size);
    for (j = 0, i = i + 1; file_ptr[j] != '\0';) {
        data[i++] = file_ptr[j++];
    }

    ret.data = data;

    ret.tail.crc = crc16_ibm(data, (int32_t)PACKET_SIZE);

    return ret;
}

/**
 * [Ymodem_PreparePacket description]
 * @param  ymodem_struct [description]
 * @return               [description]
 */
static struct ymodem_package_t Ymodem_PreparePacket(ymodem_t* ymodem_struct)
{
    uint16_t i, size, packetSize;
    FILE* file_ptr = ymodem_struct->fp;
    ymodem_package ret;
    uint8_t* data;
    static uint32_t size_left = ymodem_struct->ymodem_first_package->file_size;
    static uint8_t package_num = 0x01;

    if (!ymodem_struct) {
        return NULL;
    }

    /* Make first three packet */
    packetSize = size_left >= PACKET_1K_SIZE ? PACKET_1K_SIZE : PACKET_SIZE;
    data = (uint8_t*)malloc(packetSize);
    if (!data) {
        return NULL;
    }
    size = size_left < packetSize ? size_left : packetSize;
    if (packetSize == PACKET_1K_SIZE) {
        ret.header.frame_type = STX;
    } else {
        ret.header.frame_type = SOH;
    }
    ret.header.seq_num = package_num;
    ret.header.comp_seq_num = (~package_num);

    if (fread(data, sizeof(uint8_t), packetSize, file_ptr) > 0) {
        size_left -= packetSize;
        package_num++;
    }

    if (size <= packetSize) {
        for (i = size; i < packetSize; i++) {
            data[i] = 0x1A; /* EOF (0x1A) or 0x00 */
        }
    }
    return ret;
}

int8_t ymodem_receive(ymodem_t* ymodem_struct)
{
}

int8_t ymodem_transmit(ymodem_t* ymodem_struct)
{
}
