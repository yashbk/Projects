/*
 Name : Yashas B K
 Date : 31-031-2021
 Description : Project to encode and decode .bmp image file
 Sample input and output:

 Input for encoding : ./a.out -e beautiful.bmp secret.txt
 Output : 
 Selected Encoding
 Read and validate is success.. :)
 Opened file successfully
 Started Encoding....
 width = 1024
 height = 768
 Can encode the secret data in .bmp
 Copied header successfully
 Encoded magic string successfully
 Encoded secret file extension size success..
 Encoded secret file extension successfully
 Successfully encoded secret file size
 Encoded secret data successfully :)
 Copied remaining bytes success...
 Completed Encoding

 Input for decoding : ./a.out -d stego.bmp
 Output : 
 Selected Decoding
 Read and validate is success.. :)
 Opened file successfully
 Started Decoding....
 Can continue with decoding
 Magic string Decoded successfully
 File size decoded
 Decoded data successfully :)
 Completed Decoding
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc, char *argv[])
{
    uint img_size;
    
    //This works when no argument is passed
    if(argc<2)
    {
        printf("Invalid Option\nUsage:\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\n");
        printf("Decoding: ./a.out -d stego.bmp\n");
    }
    
    
    
    //check operation type
    if(check_operation_type(argv) == e_encode)
    { 
        EncodeInfo encInfo;
        printf("Selected Encoding\n");
        if(read_and_validate_encode_args(argv,&encInfo) == e_success)
        {
            printf("Read and validate is success.. :)\n");
            
            if(do_encoding(&encInfo)==e_success)  
            {
                printf("Completed Encoding\n");
            }
            else
            {
                printf("Failure: Encoding is unsuccessful\n");
            }
        }
        else
        {
            printf("Read and validate is unsuccessful.. :)\n");
        }
    }
    else if(check_operation_type(argv) == e_decode)
    {
        DecodeInfo decInfo;
        printf("Selected Decoding\n");
        if(read_and_validate_decode_args(argv,&decInfo)==e_success)
        {
            printf("Read and validate is success.. :)\n");
            if(do_decoding(&decInfo)==e_success)  
            {
                printf("Completed Decoding\n");
            }
            else
            {
                printf("Failure: Decoding is unsuccessful\n");
            }
            
        }
    }
    
    else
    {
        printf("Invalid Option\nUsage:\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\n");
        printf("Decoding: ./a.out -d stego.bmp\n");
    }
}

OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
        return e_encode;
    else if(strcmp(argv[1],"-d") == 0)
        return e_decode;
    else
        return e_unsupported;
}
