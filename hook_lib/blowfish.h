#pragma once
#include <Windows.h>
#include <string>

typedef unsigned char byte;

/* Usage example
#include <iostream>
#include <string.h>
#include "blowfish.h"
using namespace std;
typedef unsigned char byte;
int main()
{
	BLOWFISH bf("FEDCBA9876543210");
	string asdf = "BlowwFIshhhhhhhhhhh!";
	asdf = bf.Encrypt_CBC(asdf);
	cout << "Encrypted: " << asdf << endl;
	asdf = bf.Decrypt_CBC(asdf);
	cout << "Decrypted: " << asdf;
	return 0;
}
*/

//Stop the skids
class BLOWFISH
{
	//STANDARD: 16
	//MAXIMUM: 256
	//**MUST be an EVEN number**

	//Nobody has cracked 16 or above...

#define ROUNDS 16

public:
	BLOWFISH(std::string hexKey);
	BLOWFISH(BYTE* cipherKey, int keylength);

	//TODO: string encryption functions -> base64
	std::string Encrypt_CBC(std::string data);
	BYTE* Encrypt_CBC(BYTE* data, int length, int* newlength);
	BYTE* Encrypt_ECB(BYTE* data, int length, int* newlength);
	void Encrypt_Block(BYTE* block, int offset = 0);

	std::string Decrypt_CBC(std::string data);
	BYTE* Decrypt_CBC(BYTE* data, int length, int* newlength);
	BYTE* Decrypt_ECB(BYTE* data, int length, int* newlength);
	void Decrypt_Block(BYTE* block, int offset = 0);

	void SetRandomIV();
	void SetIV(BYTE* newIV);
	BYTE* GetIV();
	bool IvSet;

protected:
	void SetupKey(BYTE* cipherKey, int length);
	void encipher();
	void decipher();
	unsigned int round(unsigned int a, unsigned int b, unsigned int n);
	void setblock(BYTE* block, int offset);
	void getblock(BYTE* block, int offset);
	static unsigned int p[];
	static unsigned int s0[];
	static unsigned int s1[];
	static unsigned int s2[];
	static unsigned int s3[];

	unsigned int xl_par;
	unsigned int xr_par;

	BYTE IV[8];

	BYTE* Crypt_ECB(BYTE* data, int length, int* newlength, void (BLOWFISH::* CryptBlock)(BYTE*, int offset), bool decrypt);
	BYTE* Crypt_CBC(BYTE* data, int length, int* newlength, void (BLOWFISH::* CryptBlock)(BYTE*, int offset), bool decrypt);
	BYTE* padData(BYTE* data, int length, int* paddedLength, bool decrypt, bool IvSpace);
	int findPaddingEnd(BYTE* data, int length);
	int hex2dec(char hex);
	std::string byteToHex(unsigned char x);
};