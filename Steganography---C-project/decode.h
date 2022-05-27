#ifndef DECODE_H
#define DECODE_H
#define SIZE_OF_MAGIC_STRING 2
#define BYTE8 8
#define FILE_SIZE_START 134
#define DATA_START 54

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

typedef struct _DecodeInfo
{
     /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;
    unsigned char image_data[BYTE8];
    
    /* Decode file info */
    char *decoded_fname;
    FILE *fptr_decoded_file;
    char magic_string_arr[SIZE_OF_MAGIC_STRING];
    int file_size;
    
}DecodeInfo;

/* Decoding function prototype */

/* Check operation type */
//OperationType check_operation_type(char *argv[]);

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

//Start decoding process
Status do_decoding(DecodeInfo *decInfo);

//Opening decoding files
Status open_decoding_files(DecodeInfo *decInfo);

//Getting data from image 
unsigned char decode_data_from_image(DecodeInfo *decInfo,FILE *fptr_stego);

//Decoding 8bytes and returning one byte info
unsigned char byte8_to_byte1(char *image_buffer);

//Decoding magic string
Status decode_magic_string(DecodeInfo *decInfo);

//Decoding file size
Status decode_file_size(FILE *fptr_stego_image,DecodeInfo *decInfo);

//Writing decoded data to decoded.txt
Status write_decoded_data_to_file(int *file_size,FILE *fptr_stego_image,DecodeInfo *decInfo);

//Prints status of decoding
Status decoding_data(DecodeInfo *decInfo);

//Closing files
void close_files(DecodeInfo *decInfo);



#endif
