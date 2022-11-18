/**
 * @file LuxDLL.h
 * @brief 
 * 
 * @version 1.0
 * @author Tianen Lu (tianenlu957@gmail.com)
 * @date 2022-11
 */

#ifndef LUXTW2_H
#define LUXTW2_H


#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <cstdint>


#ifdef __cplusplus
extern "C" {
#endif

#define DLLEXPORT __declspec(dllexport)

enum class ImageFileType
{
    UnknowType = -1,
    raw = 0,
    tiff
};

/**
 * C Type                   ctypes Type
 * ---------------------------------------
 * char                     c_char
 * wchar_r                  c_wchar
 * char                     c_byte
 * char                     c_ubyte
 * short                    c_short
 * unsigned short           c_ushort
 * int                      c_int
 * unsigned int             c_uint
 * long                     c_long
 * unsigned long            c_ulong
 * long long                c_longlong
 * unsigned long long       c_ulonglong
 * float                    c_float
 * double                   c_double
 * char* (NULL terminated)  c_char_p
 * wchar* (NULL terminated) c_wchar_p
 * void*                    c_void_p
 */

/*************************************************************************************************/
/*                                     Function Declare                                          */
/*************************************************************************************************/

void
LuxEndianSwap(char *pData,
                uint64_t startIndex,
                uint64_t length);

DLLEXPORT
int
LuxEndianRevert(unsigned char *input,
                int length,
                int bpp,
                unsigned char *output,
                bool isBig2Little);

DLLEXPORT
void
LuxFlushStdOut();

inline unsigned long long
LuxParseImage(unsigned char *orgiImg,
                int length,
                int bpp,
                bool highZero,
                unsigned char *outputImg);


inline unsigned long long
LuxParseImageExtendTo16(unsigned char *orgiImg,
              int length,
              int bpp,
              bool highZero,
              uint16_t *outputImg);


inline unsigned long long 
LuxParseImageStretchTo16(unsigned char *orgiImg,
            int length, int bpp,
            bool highZero,
            uint16_t *outputImg);

inline 
decltype(CV_8UC1)
LuxGetImageType(int dataFormat,
                int bpp,
                int channels);

long long
LuxWriteImageIntoFile(unsigned char *imgData,
                      const char *outFileName,
                      ImageFileType fileFormat,
                      unsigned long long length,
                      int width,
                      int height,
                      int type);


DLLEXPORT
long long
LuxLoadImageData(unsigned char *imgData,
                 unsigned long long length,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int channels,
                 unsigned char *outData,
                 bool isBigEndian,
                 bool highZero,
                 int code = CV_BayerRG2RGB);


DLLEXPORT
long long
LuxLoadImageDataFromFile(const char *inputFileName,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int channels,
                 const char *outputRawFileName,
                 const char *outputTiffFileName,
                 bool isBigEndian,
                 bool highZero,
                 bool saveTiff,
                 int code = CV_BayerRG2RGB);

DLLEXPORT
long long
LuxLoadImageDataStretchTo16(unsigned char *imgData,
                 unsigned long long length,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int inChannels,
                 int outChannels,
                 uint16_t *outData,
                 bool isBigEndian,
                 bool highZero,
                 int code);


DLLEXPORT
long long
LuxLoadImageDataFromFileStretchTo16(const char *inputFileName,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int inChannels,
                 int outChannels,
                 const char *outputRawFileName,
                 const char *outputTiffFileName,
                 bool isBigEndian,
                 bool highZero,
                 bool saveTiff,
                 int code = CV_BayerRG2RGB);


DLLEXPORT
int
LuxAdjustBrightness(unsigned char *src,
                    long long length,
                    int width,
                    int height,
                    int channel,
                    int beta,
                    unsigned char *dst);

DLLEXPORT
int
LuxAdjustContrast(unsigned char *src,
                  long long length,
                  int width,
                  int height,
                  int channel,
                  int alpha, unsigned char *dst);

DLLEXPORT
long long int
LuxDrawHist(const char* inputFileName_, 
            int width,
            int height,
            int imReadType, 
            int histImgWidth, 
            int histImgHeight, 
            const char* outFileName);


DLLEXPORT
long long
LuxSaveImgDatExtTo16(unsigned char *imgData,
                 unsigned long long length,
                 int width,
                 int height,
                 int bpp,
                 int inChannels,
                 const char* outRawFileName,
                 bool isBigEndian,
                 bool highZero);


inline long long
LuxParseImageEnhanced(unsigned char *orgiImg,
                int bytes,
                int bpp,
                bool highZero,
                unsigned char *outputImg,
                int mode = 0);


DLLEXPORT
long long
LuxLoadImageDataEnhanced(unsigned char *imgData,
                 unsigned long long length,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int inChannels,
                 unsigned char *outData,
                 bool isBigEndian,
                 bool highZero,
                 int mode,
                 int code = CV_BayerRG2RGB);


DLLEXPORT
long long
LuxLoadImageDataFromFileEnhanced(const char *inputFileName,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int channels,
                 const char *outputRawFileName,
                 const char *outputTiffFileName,
                 bool isBigEndian,
                 bool highZero,
                 bool saveTiff,
                 int mode,
                 int code = CV_BayerRG2RGB);

DLLEXPORT
int
LuxGetBayerRawChanenls(unsigned char* src, 
                    int width,
                    int height,
                    int bayerMode,
                    unsigned char* RDst,
                    unsigned char* G1Dst,
                    unsigned char* G2Dst,
                    unsigned char* BDst);

DLLEXPORT
long long
LuxSetChannelFactors(unsigned char* src,
                    int width,
                    int height,
                    int mode,
                    float r,
                    float g,
                    float b);


DLLEXPORT
long long
LuxLoadImageDataFromFileEnhanced2(const char *inputFileName,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int channels,
                 const char *outputRawFileName,
                 const char *outputTiffFileName,
                 bool isBigEndian,
                 bool highZero,
                 bool saveTiff,
                 int mode,
                 int code,
                 bool eaf,
                 int bayerType,
                 float r,
                 float g,
                 float b);

DLLEXPORT
long long
LuxLoadImageDataEnhanced2(unsigned char *imgData,
                 unsigned long long length,
                 int dataFormat,
                 int width,
                 int height,
                 int bpp,
                 int inChannels,
                 unsigned char *outData,
                 bool isBigEndian,
                 bool highZero,
                 int mode,
                 int code,
                 bool eaf,
                 int bayerType,
                 float r,
                 float g,
                 float b);

#ifdef __cplusplus
}
#endif /// __cplusplus
#endif