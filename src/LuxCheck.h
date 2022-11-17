/**
 * @file LuxCheck.h
 * @brief 
 * 
 * @version 1.0
 * @author Tianen Lu (tianenlu957@gmail.com)
 * @date 2022-11
 */

#ifndef LUXCRC_H
#define LUXCRC_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
/*************************************************************************************************/
/*                                     Function Declare                                          */
/*************************************************************************************************/

__declspec(dllexport) 
uint8_t 
LuxCRC4_itu(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC5_epc(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC5_usb(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC6_itu(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC7_mmc(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC5_itu(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC8(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC8_itu(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC8_rohc(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint8_t 
LuxCRC8_maxim(uint8_t* data, uint16_t length);//DS18B20
__declspec(dllexport) 
uint16_t
LuxCRC16_ibm(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_maxim(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_usb(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_modbus(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_ccitt(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_ccitt_false(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_x25(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_xmodem(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint16_t
LuxCRC16_dnp(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint32_t
LuxCRC32(uint8_t* data, uint16_t length);
__declspec(dllexport) 
uint32_t
LuxCRC32_mpeg_2(uint8_t* data, uint16_t length);

__declspec(dllexport)
uint16_t
LuxCalcCheckSum(uint8_t const *p_data, int64_t data_len);


__declspec(dllexport)
uint32_t
LuxCalcCheckSum32(uint8_t const *p_data, int64_t data_len);

#ifdef __cplusplus
}
#endif
#endif

