#include <stdio.h>
#include "decode.h"
#include <string.h>
#include "types.h"
#include "common.h"

//Validating arguments passed via command line
Status read_and_validate_decode_args(char *argv[],DecodeInfo *decInfo)
{
    if(strcmp(strstr(argv[2],"."),".bmp")==0)
    {
        decInfo->stego_image_fname=argv[2];
    }
    else
    {
        return e_failure;
    }

    if(argv[3]!=NULL)
    {
        //if name is passed use that name
        decInfo->decoded_fname=argv[3];
    }
    else
    {  
        //if name of decoding file is not passed they use decode.txt by default
        decInfo->decoded_fname="decode.txt";
    }
    return e_success;
}

//Reading and writing files
Status open_decoding_files(DecodeInfo *decInfo)
{
    // Stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
    // Do Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

    	return e_failure;
    }

    // Decoded file
    decInfo->fptr_decoded_file = fopen(decInfo->decoded_fname, "w");
    // Do Error handling
    if (decInfo->fptr_decoded_file == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decoded_fname);

    	return e_failure;
    }
    // No failure return e_success
    return e_success;
}

//Function to fetch lsb from 8 bytes and store it to one byte
unsigned char byte8_to_byte1(char *image_buffer)
{
    unsigned char output_bit=0;
    unsigned char result=0;
    unsigned char mask = 0x01;
    
    //lsb fetching and storing to one byte logic
    for(int i=0;i<8;i++){
           output_bit= image_buffer[i] & mask;
           result= result | (output_bit<<(7-i));            
    }
    return result;
}

//Function to fetch 8 bytes from image and returning decoded one byte data 
unsigned char decode_data_from_image(DecodeInfo *decInfo,FILE *fptr_stego)
{
        //fetching 8 bytes from image
        fread(decInfo->image_data,sizeof(char),8,fptr_stego);
        return byte8_to_byte1(decInfo->image_data);    
}

//Function to decode magic string
Status decode_magic_string(DecodeInfo *decInfo)
{ 
    //Making fptr to point to 54 
    fseek(decInfo->fptr_stego_image,DATA_START,SEEK_SET);
    
    //Getting decoded data from 16 bytes and storing it in array
    for(int i=0;i<SIZE_OF_MAGIC_STRING;i++)
    {
        decInfo->magic_string_arr[i] = decode_data_from_image(decInfo,decInfo->fptr_stego_image);
    }
   
   //Magic string validation
   if(decInfo->magic_string_arr[0]=='#' && decInfo->magic_string_arr[1]=='*')
   {
       printf("Can continue with decoding\n");
       return e_success;
   }
   else
   {
        printf("Cannot continue with decoding\n");
        return e_failure;
   }
}



//Status write_decoded_data_to_file();
Status decode_file_size(FILE *fptr_stego_image,DecodeInfo *decInfo)
{
    //union to reverse bytes fetched 
    typedef union Bit{
        unsigned int temp_file_size;
        unsigned char lsb[sizeof(int)];
    }dummy_size;
    
    dummy_size dummy_file_size; //Variable declaration of union
    
    fseek(decInfo->fptr_stego_image,FILE_SIZE_START,SEEK_SET); //Pointing file pointer to file_size starting

    //Calling and Storing each byte of value in a char array
    for(int i=0;i<sizeof(dummy_file_size);i++)
    {
        dummy_file_size.lsb[i] = decode_data_from_image(decInfo,fptr_stego_image);
    }
    //Copy reversed bytes to file_size
    decInfo->file_size=dummy_file_size.temp_file_size;

    return e_success;
}

Status decoding_data(DecodeInfo *decInfo)
{

    char data; //Buffer to store each character fetched
    fseek(decInfo->fptr_decoded_file,0,SEEK_SET); //pointing fptr to starting of the decoded.txt file
    for(int i=0;(i<decInfo->file_size);i++)
    {
        //Storing each byte decoded
        data = decode_data_from_image(decInfo,decInfo->fptr_stego_image);
        fprintf(decInfo->fptr_decoded_file,"%c",data);  //writing data to a file
    }
    return e_success;
}

//function to close files 
void close_files(DecodeInfo *decInfo)
{
    fclose(decInfo->fptr_stego_image);
    fclose(decInfo->fptr_decoded_file);
}

//Decoding starts from here
Status do_decoding(DecodeInfo *decInfo)
{
    //open files 
    if(open_decoding_files(decInfo)== e_success)
    {
        printf("Opened file successfully\n");
        printf("Started Decoding....\n");
        
        if(decode_magic_string(decInfo)==e_success)
        {
            printf("Magic string Decoded successfully\n");
            if(decode_file_size(decInfo->fptr_stego_image,decInfo)==e_success)
            {
                printf("File size decoded\n");
                if(decoding_data(decInfo)==e_success)
                {
                    printf("Decoded data successfully :)\n");
                    
                    close_files(decInfo); //Closing files
                }
                else
                {
                    printf("Decoding data is unsuccessful :(\n");
                }
            }
            else
            {
                printf("File size decoding failed\n");
            }
        }
        else
        {
            printf("Magic string Decoding unsuccessful\n");
        }
    }
    else
    {
        printf("Opening file is unsuccessful\n");
        return e_failure;
    }
    return e_success;
}