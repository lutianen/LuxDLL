/**
 * @file LuxCheck.h
 * @brief
 *
 */

#ifndef LUXCRC_H
#define LUXCRC_H

#include <cstdint>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*************************************************************************************************/
/*                                     Function Declare */
/*************************************************************************************************/

DLLEXPORT uint8_t LuxCRC4_itu(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC5_epc(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC5_usb(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC6_itu(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC7_mmc(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC5_itu(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC8(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC8_itu(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC8_rohc(uint8_t* data, uint16_t length);
DLLEXPORT uint8_t LuxCRC8_maxim(uint8_t* data, uint16_t length);  // DS18B20
DLLEXPORT uint16_t LuxCRC16_ibm(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_maxim(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_usb(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_modbus(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_ccitt(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_ccitt_false(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_x25(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_xmodem(uint8_t* data, uint16_t length);
DLLEXPORT uint16_t LuxCRC16_dnp(uint8_t* data, uint16_t length);
DLLEXPORT uint32_t LuxCRC32(uint8_t* data, uint16_t length);
DLLEXPORT uint32_t LuxCRC32_mpeg_2(uint8_t* data, uint16_t length);

DLLEXPORT uint16_t LuxCalcCheckSum(uint8_t const* p_data, int64_t data_len);

DLLEXPORT uint32_t LuxCalcCheckSum32(uint8_t const* p_data, int64_t data_len);

#ifdef __cplusplus
}
#endif
#endif
