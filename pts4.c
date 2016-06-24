#if 0
#include <stdio.h>
#include <string.h>
#include <assert.h>
 
int enc_unicode_to_utf8_one(unsigned long unic, unsigned char *pOutput,  
                            int outSize)  
{  
    assert(pOutput != NULL);  
    assert(outSize >= 6);  
  
    if ( unic <= 0x0000007F )  
    {  
        // * U-00000000 - U-0000007F:  0xxxxxxx  
        *pOutput     = (unic & 0x7F);  
        return 1;  
    }  
    else if ( unic >= 0x00000080 && unic <= 0x000007FF )  
    {  
        // * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx  
        *(pOutput+1) = (unic & 0x3F) | 0x80;  
        *pOutput     = ((unic >> 6) & 0x1F) | 0xC0;  
        return 2;  
    }  
    else if ( unic >= 0x00000800 && unic <= 0x0000FFFF )  
    {  
        // * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx  
        *(pOutput+2) = (unic & 0x3F) | 0x80;  
        *(pOutput+1) = ((unic >>  6) & 0x3F) | 0x80;  
        *pOutput     = ((unic >> 12) & 0x0F) | 0xE0;  
        return 3;  
    }  
    else if ( unic >= 0x00010000 && unic <= 0x001FFFFF )  
    {  
        // * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
        *(pOutput+3) = (unic & 0x3F) | 0x80;  
        *(pOutput+2) = ((unic >>  6) & 0x3F) | 0x80;  
        *(pOutput+1) = ((unic >> 12) & 0x3F) | 0x80;  
        *pOutput     = ((unic >> 18) & 0x07) | 0xF0;  
        return 4;  
    }  
    else if ( unic >= 0x00200000 && unic <= 0x03FFFFFF )  
    {  
        // * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
        *(pOutput+4) = (unic & 0x3F) | 0x80;  
        *(pOutput+3) = ((unic >>  6) & 0x3F) | 0x80;  
        *(pOutput+2) = ((unic >> 12) & 0x3F) | 0x80;  
        *(pOutput+1) = ((unic >> 18) & 0x3F) | 0x80;  
        *pOutput     = ((unic >> 24) & 0x03) | 0xF8;  
        return 5;  
    }  
    else if ( unic >= 0x04000000 && unic <= 0x7FFFFFFF )  
    {  
        // * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
        *(pOutput+5) = (unic & 0x3F) | 0x80;  
        *(pOutput+4) = ((unic >>  6) & 0x3F) | 0x80;  
        *(pOutput+3) = ((unic >> 12) & 0x3F) | 0x80;  
        *(pOutput+2) = ((unic >> 18) & 0x3F) | 0x80;  
        *(pOutput+1) = ((unic >> 24) & 0x3F) | 0x80;  
        *pOutput     = ((unic >> 30) & 0x01) | 0xFC;  
        return 6;  
    }  
  
    return 0;  
}  

//test
char *unicode_to_utf8(unsigned int *unic, char *pOutput)                              
{  
    while(*unic)
    {
        if ( (*unic) <= 0x0000007F )  
        {  
            // * U-00000000 - U-0000007F:  0xxxxxxx  
            *(pOutput++)  = ((*unic) & 0x7F);  
        }  
        else if ( ((*unic) >= 0x00000080) && ((*unic) <= 0x000007FF) )  
        {  
            // * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx  
            *(pOutput++) = (((*unic) >> 6) & 0x1F) | 0xC0;  
            *(pOutput++) = ((*unic) & 0x3F) | 0x80;  
        }  
        else if ( ((*unic) >= 0x00000800) && ((*unic) <= 0x0000FFFF) )  
        {  
            // * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx  
            *(pOutput++) = (((*unic) >> 12) & 0x0F) | 0xE0;  
            *(pOutput++) = (((*unic) >>  6) & 0x3F) | 0x80; 
            *(pOutput++) = ((*unic) & 0x3F) | 0x80;  
        }  
        else if ( ((*unic) >= 0x00010000) && ((*unic) <= 0x001FFFFF) )  
        {  
            // * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
            *(pOutput++) = (((*unic) >> 18) & 0x07) | 0xF0; 
            *(pOutput++) = (((*unic) >> 12) & 0x3F) | 0x80; 
            *(pOutput++) = (((*unic) >>  6) & 0x3F) | 0x80;
            *(pOutput++) = ((*unic) & 0x3F) | 0x80;  
        }  
        else if ( ((*unic) >= 0x00200000) && ((*unic) <= 0x03FFFFFF) )  
        {  
            // * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
            *(pOutput++) = (((*unic) >> 24) & 0x03) | 0xF8;
            *(pOutput++) = (((*unic) >> 18) & 0x3F) | 0x80;
            *(pOutput++) = (((*unic) >> 12) & 0x3F) | 0x80;  
            *(pOutput++) = (((*unic) >>  6) & 0x3F) | 0x80;
            *(pOutput++) = ((*unic) & 0x3F) | 0x80;  
        }  
        else if ( ((*unic) >= 0x04000000) && ((*unic) <= 0x7FFFFFFF) )  
        {  
            // * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
            *(pOutput++) = (((*unic) >> 30) & 0x01) | 0xFC;
            *(pOutput++) = (((*unic) >> 24) & 0x3F) | 0x80;
            *(pOutput++) = (((*unic) >> 18) & 0x3F) | 0x80;
            *(pOutput++) = (((*unic) >> 12) & 0x3F) | 0x80;  
            *(pOutput++) = (((*unic) >>  6) & 0x3F) | 0x80;
            *(pOutput++) = ((*unic) & 0x3F) | 0x80;  
        }
        unic++;
    }
    *pOutput = 0x0000;
    return pOutput;  
}  


// #c---end  

//2) 将一个字符的UTF8编码转换成Unicode(UCS-2和UCS-4)编码.
//[cpp] view plaincopy
//<span xmlns="http://www.w3.org/1999/xhtml" style="">// #c---  
/***************************************************************************** 
 * 将一个字符的UTF8编码转换成Unicode(UCS-2和UCS-4)编码. 
 * 
 * 参数: 
 *    pInput      指向输入缓冲区, 以UTF-8编码 
 *    Unic        指向输出缓冲区, 其保存的数据即是Unicode编码值, 
 *                类型为unsigned long . 
 * 
 * 返回值: 
 *    成功则返回该字符的UTF8编码所占用的字节数; 失败则返回0. 
 * 
 * 注意: 
 *     1. UTF8没有字节序问题, 但是Unicode有字节序要求; 
 *        字节序分为大端(Big Endian)和小端(Little Endian)两种; 
 *        在Intel处理器中采用小端法表示, 在此采用小端法表示. (低地址存低位) 
 ****************************************************************************/ 

int enc_get_utf8_size(const char *pInput)
{
    unsigned char c = *((unsigned char *)pInput);
    printf("---c=%c---\n", c);
    if(c< 0x80) return 0;                // 0xxxxxxx 返回0
    if(c>=0x80 && c<0xC0) return -1;     // 10xxxxxx 返回-1 
    if(c>=0xC0 && c<0xE0) return 2;      // 110xxxxx 返回2
    if(c>=0xE0 && c<0xF0) return 3;      // 1110xxxx 返回3
    if(c>=0xF0 && c<0xF8) return 4;      // 11110xxx 返回4
    if(c>=0xF8 && c<0xFC) return 5;      // 111110xx 返回5
    if(c>=0xFC) return 6;                // 1111110x 返回6
}

#if 1
int enc_utf8_to_unicode_one(const char* pInput, unsigned long *Unic)  
{  
    assert(pInput != NULL && Unic != NULL);  
  
    // b1 表示UTF-8编码的pInput中的高字节, b2 表示次高字节, ...  
    char b1, b2, b3, b4, b5, b6;  
  
    *Unic = 0x0; // 把 *Unic 初始化为全零  
    int utfbytes = enc_get_utf8_size(pInput);  
    unsigned char *pOutput = (unsigned char *) Unic;  
    printf("----utfbytes=%d\n", utfbytes);
    switch ( utfbytes )  
    {  
        case 0:  
            *pOutput     = *pInput;  
            utfbytes    += 1;  
            break;
            
        case 2:  
            b1 = *pInput;  
            b2 = *(pInput + 1);  
            if ( (b2 & 0xE0) != 0x80 )  
                return 0;  
            *pOutput     = (b1 << 6) + (b2 & 0x3F);  
            *(pOutput+1) = (b1 >> 2) & 0x07;  
            break;
            
        case 3:  
            b1 = *pInput;  
            b2 = *(pInput + 1);  
            b3 = *(pInput + 2);  
            if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80) )  
                return 0;  
            *pOutput     = (b2 << 6) + (b3 & 0x3F);  
            *(pOutput+1) = (b1 << 4) + ((b2 >> 2) & 0x0F);  
            break; 
            
        case 4:  
            b1 = *pInput;  
            b2 = *(pInput + 1);  
            b3 = *(pInput + 2);  
            b4 = *(pInput + 3);  
            if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)  
                    || ((b4 & 0xC0) != 0x80) )  
                return 0;  
            *pOutput     = (b3 << 6) + (b4 & 0x3F);  
            *(pOutput+1) = (b2 << 4) + ((b3 >> 2) & 0x0F);  
            *(pOutput+2) = ((b1 << 2) & 0x1C)  + ((b2 >> 4) & 0x03);  
            break; 
            
        case 5:  
            b1 = *pInput;  
            b2 = *(pInput + 1);  
            b3 = *(pInput + 2);  
            b4 = *(pInput + 3);  
            b5 = *(pInput + 4);  
            if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)  
                    || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80) )  
                return 0;  
            *pOutput     = (b4 << 6) + (b5 & 0x3F);  
            *(pOutput+1) = (b3 << 4) + ((b4 >> 2) & 0x0F);  
            *(pOutput+2) = (b2 << 2) + ((b3 >> 4) & 0x03);  
            *(pOutput+3) = (b1 << 6);  
            break; 
            
        case 6:  
            b1 = *pInput;  
            b2 = *(pInput + 1);  
            b3 = *(pInput + 2);  
            b4 = *(pInput + 3);  
            b5 = *(pInput + 4);  
            b6 = *(pInput + 5);  
            if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)  
                    || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80)  
                    || ((b6 & 0xC0) != 0x80) )  
                return 0;  
            *pOutput     = (b5 << 6) + (b6 & 0x3F);  
            *(pOutput+1) = (b5 << 4) + ((b6 >> 2) & 0x0F);  
            *(pOutput+2) = (b3 << 2) + ((b4 >> 4) & 0x03);  
            *(pOutput+3) = ((b1 << 6) & 0x40) + (b2 & 0x3F);  
            break; 
            
        default:  
            return 0;  
            break;  
    }  
  
    return utfbytes;  
}  
// #c---end  
//</span>  
#endif

char *Unicode2Ascii(char *asc, unsigned int *uni)
{
    while (*uni)
    {
        if (*uni <= 0x80)  //0-128
        {
            *(asc++) = *uni;
            //*(asc++) = (*uni) & 0x7f;
        }
        else if (*uni < 0x800) //129-2048
        {
            /*
            * Two-byte UTF-8...
            */

            //*(asc++)  = 0xc0 | ((*uni) >> 6);
            //*(asc++) = 0x80 | ((*uni) & 0x3f);
            *(asc++)  = 0xc0 | (((*uni) >> 6) & 0x1f);
            *(asc++) = 0x80 | ((*uni) & 0x3f);
        }
        else if (*uni < 0x10000)
        {
            /*
            * Three-byte UTF-8...
            */

            *(asc++) = 0xe0 | ((*uni) >> 12);
            *(asc++) = 0x80 | (((*uni) >> 6) & 0x3f);
            *(asc++) = 0x80 | ((*uni) & 0x3f);
            //*(asc++) = 0x80 | ((*uni) & 0x3f);
            //*(asc++) = 0x80 | (((*uni) >> 6) & 0x3f);
            //*(asc++) = 0xe0 | (((*uni) >> 12) & 0x0f);
        }
        else
        {
            /*
            * Four-byte UTF-8...
            */

            *(asc++) = 0xf0 | ((*uni) >> 18);
            *(asc++) = 0x80 | (((*uni) >> 12) & 0x3f);
            *(asc++) = 0x80 | (((*uni) >> 6) & 0x3f);
            *(asc++) = 0x80 | ((*uni) & 0x3f);
            //*(asc++) = 0x80 | ((*uni) & 0x3f);
            //*(asc++) = 0x80 | (((*uni) >> 6) & 0x3f);
            //*(asc++) = 0x80 | (((*uni) >> 12) & 0x3f);
            //*(asc++) = 0xf0 | (((*uni) >> 18) & 0x07);
        }
        uni++;
    }
    *asc = 0x00;
    return asc;
}

unsigned int *Ascii2Unicode(unsigned int *uni, char *asc)
{
    while (*asc)
    {
        if ((*asc & 0x80) == 0)
        {
            *uni = *asc;
        }
        else if ((*asc & 0xE0) == 0xB0)
        {
            *uni = (*asc & 0x1F) << 6;
            asc++;
            *uni |= (*asc & 0x3F);
        }
        else if ((*asc & 0xF0) == 0xE0)
        {
            *uni = (*asc & 0x0F) << 12;
            asc++;
            *uni |= ((*asc & 0x3F) << 6);
            asc++;
            *uni |= (*asc & 0x3F);
        }
        else if ((*asc & 0xF8) == 0xF0)
        {
            *uni = (*asc & 0x07) << 18;
            asc++;
            *uni |= ((*asc & 0x3F) << 12);
            asc++;
            *uni |= ((*asc & 0x3F) << 6);
            asc++;
            *uni |= (*asc & 0x3F);
        }
        uni++;
        asc++;
    }
    *uni = 0x0000;
    return uni;
}


/***********************************************************************************
函数名:wstrlen()
描  述:
***********************************************************************************/
unsigned int  wstrlen(const unsigned int *str)
{
    const unsigned int *eos = str;

    if (eos == NULL) return 0;

    while (*eos++) ;

    return((unsigned int)(eos - str - 1));
}

int main()
{
    int i = 0;
    //char pOutput[] = "è";
    //unsigned long uni = 0;

    //enc_utf8_to_unicode_one(pOutput, &uni);  
    //for (i = 0; i < 1;i++)
        //printf("------uni[%d]=0x%0x---\n",i, uni);  

 
    char temp[4] = "3hц";
    unsigned int temp2[4] = {0}; 
    Ascii2Unicode(temp2, temp);
    for (i = 0; i<3;i++)
        printf("--%s##%d##--temp2= 0x%x\n", __FILE__,__LINE__, temp2[i]);
    //printf("--%s##%d##--clen=%d\n", __FILE__,__LINE__, strlen(temp));
    
    //unicode_to_utf8(temp2, temp);
    //for (i = 0; i < 1;i++)
        //printf("---len2=%d---pOutput2=%s\n", strlen(temp), temp);  
/*
    //Unicode2Ascii(pOutput, temp2);
    //for (i = 0; i < 1;i++)
        //printf("---str=%s\n", pOutput);  
*/
    return 0;
}
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char text[] = "123456789";

    printf("%s\n", (text + 9-5));

    return 0;
}