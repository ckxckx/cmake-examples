#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdint.h>
#include <string.h>


#ifdef WITH_BZIP2
#include <bzlib.h>

int BZip2Encode(const char* buffer, size_t length, char** bzip2text, size_t * dest_length) {
  // Create a buffer to hold the result
  *bzip2text =  (char*)malloc(2*length);
  *dest_length = 2*length;

  return BZ2_bzBuffToBuffCompress(
          *bzip2text,                  // Destination
          (unsigned int *)dest_length, // Maximum length of destination
          (char*)buffer,               // Source
          length,                      // Length of source
          1,                           // Block size x 100k
          0,                           // Verbosity = Silent
          0);                          // Default work factor
}

#endif

#ifdef WITH_ZLIB
#include <zlib.h>

int GZipEncode(const char* buffer, uLongf length, char** gziptext, uLongf * dest_length) {
  // Create a buffer to hold the result
  *gziptext =  (char*)malloc(2*length);
  *dest_length = 2*length;

  return compress(
          (Bytef*)*gziptext, // Destination
          dest_length,       // Maximum length of destination
          (Bytef*)buffer,    // Source
          length);           // Length of source
}

#endif

int Base64Encode(const char* buffer, size_t length, char** b64text) { //Encodes a binary safe base 64 string
	BIO *bio, *b64;
	BUF_MEM *bufferPtr;
 
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);
 
	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
	BIO_write(bio, buffer, length);
	BIO_flush(bio);
	BIO_get_mem_ptr(bio, &bufferPtr);
	BIO_set_close(bio, BIO_NOCLOSE);
	BIO_free_all(bio);
 
	*b64text=(*bufferPtr).data;

	return (0); //success
}

int main(int argc, char ** argv) {
  //Encode To Base64
  char* base64EncodeOutput;
 
  Base64Encode(argv[1], (size_t) strlen(argv[1]), &base64EncodeOutput);
  printf("(base64): %s\n", base64EncodeOutput);

#ifdef WITH_BZIP2
  {
  char* compressed;
  size_t compressed_length;
  char* base64;

  BZip2Encode(argv[1], (size_t) strlen(argv[1]), &compressed, &compressed_length);
  Base64Encode(compressed, compressed_length, &base64);
  printf("(bzip2): %s\n", base64);
  }
#endif

#ifdef WITH_ZLIB
  {
  char* compressed;
  uLongf compressed_length;
  char* base64;

  GZipEncode(argv[1], (uLongf) strlen(argv[1]), &compressed, &compressed_length);
  Base64Encode(compressed, compressed_length, &base64);
  printf("(gzip): %s\n", base64);
  }
#endif
  
  return(0);
}
