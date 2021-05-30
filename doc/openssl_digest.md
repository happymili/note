# dgst
### manual
```
man dgst
```
### openssl dgst -help
```
openssl dgst -help
```
output
```
Usage: dgst [options] [file...]
  file... files to digest (default is stdin)
 -help               Display this summary
 -c                  Print the digest with separating colons
 -r                  Print the digest in coreutils format
 -out outfile        Output to filename rather than stdout
 -passin val         Input file pass phrase source
 -sign val           Sign digest using private key
 -verify val         Verify a signature using public key
 -prverify val       Verify a signature using private key
 -signature infile   File with signature to verify
 -keyform format     Key file format (PEM or ENGINE)
 -hex                Print as hex dump
 -binary             Print in binary form
 -d                  Print debug info
 -debug              Print debug info
 -fips-fingerprint   Compute HMAC with the key used in OpenSSL-FIPS fingerprint
 -hmac val           Create hashed MAC with key
 -mac val            Create MAC (not necessarily HMAC)
 -sigopt val         Signature parameter in n:v form
 -macopt val         MAC algorithm parameters in n:v form or key
 -*                  Any supported digest
 -rand val           Load the file(s) into the random number generator
 -writerand outfile  Write random data to the specified file
 -engine val         Use engine e, possibly a hardware device
 -engine_impl        Also use engine given by -engine for digest operations
```



### example
calculate the sha256 of abcdefg
```
echo -n abcdefg > test.txt
openssl dgst -sha256 test.txt
```
output
```
SHA256(test.txt)= 7d1a54127b222502f5b79b5fb0803061152a44f92b37e23c6527baf665d4da9a
```




# sha256
###  manual
```
man sha256
```
### openssl sha256 -help
```
openssl sha256 -help
```
output
```
Usage: sha256 [options] [file...]
  file... files to digest (default is stdin)
 -help               Display this summary
 -c                  Print the digest with separating colons
 -r                  Print the digest in coreutils format
 -out outfile        Output to filename rather than stdout
 -passin val         Input file pass phrase source
 -sign val           Sign digest using private key
 -verify val         Verify a signature using public key
 -prverify val       Verify a signature using private key
 -signature infile   File with signature to verify
 -keyform format     Key file format (PEM or ENGINE)
 -hex                Print as hex dump
 -binary             Print in binary form
 -d                  Print debug info
 -debug              Print debug info
 -fips-fingerprint   Compute HMAC with the key used in OpenSSL-FIPS fingerprint
 -hmac val           Create hashed MAC with key
 -mac val            Create MAC (not necessarily HMAC)
 -sigopt val         Signature parameter in n:v form
 -macopt val         MAC algorithm parameters in n:v form or key
 -*                  Any supported digest
 -rand val           Load the file(s) into the random number generator
 -writerand outfile  Write random data to the specified file
 -engine val         Use engine e, possibly a hardware device
 -engine_impl        Also use engine given by -engine for digest operations
```


### example
calculate the sha256 of abcdefg
```
echo -n abcdefg > test.txt
openssl sha256 test.txt
```
output
```
SHA256(test.txt)= 7d1a54127b222502f5b79b5fb0803061152a44f92b37e23c6527baf665d4da9a
```
