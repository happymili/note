# enc
### manual
```
man enc
```
### openssl enc -help
```
openssl enc -help
```
output
```
Usage: enc [options]
Valid options are:
 -help               Display this summary
 -ciphers            List ciphers
 -in infile          Input file
 -out outfile        Output file
 -pass val           Passphrase source
 -e                  Encrypt
 -d                  Decrypt
 -p                  Print the iv/key
 -P                  Print the iv/key and exit
 -v                  Verbose output
 -nopad              Disable standard block padding
 -salt               Use salt in the KDF (default)
 -nosalt             Do not use salt in the KDF
 -debug              Print debug info
 -a                  Base64 encode/decode, depending on encryption flag
 -base64             Same as option -a
 -A                  Used with -[base64|a] to specify base64 buffer as a single line
 -bufsize val        Buffer size
 -k val              Passphrase
 -kfile infile       Read passphrase from file
 -K val              Raw key, in hex
 -S val              Salt, in hex
 -iv val             IV in hex
 -md val             Use specified digest to create a key from the passphrase
 -iter +int          Specify the iteration count and force use of PBKDF2
 -pbkdf2             Use password-based key derivation function 2
 -none               Don't encrypt
 -*                  Any supported cipher
 -rand val           Load the file(s) into the random number generator
 -writerand outfile  Write random data to the specified file
 -engine val         Use engine, possibly a hardware device
```



### example
* encryption
```
echo -n abcdefg > test.txt
openssl enc -aes-128-cbc -e -pbkdf2 -in test.txt -out test.txt.aes
```
input the encryption password for two times, output
```
enter aes-128-cbc encryption password:
Verifying - enter aes-128-cbc encryption password:
```
* decryption
```
openssl enc -aes-128-cbc -d -pbkdf2 -in test.txt.aes -out test2.txt
```
input the decrpytion password, output
```
enter aes-128-cbc decryption password:
```





# aes-128-cbc 
### manual
```
man aes-128-cbc
```
### openssl aes-128-cbc -help
```
openssl aes-128-cbc -help
```
output
```
Usage: aes-128-cbc [options]
Valid options are:
 -help               Display this summary
 -ciphers            List ciphers
 -in infile          Input file
 -out outfile        Output file
 -pass val           Passphrase source
 -e                  Encrypt
 -d                  Decrypt
 -p                  Print the iv/key
 -P                  Print the iv/key and exit
 -v                  Verbose output
 -nopad              Disable standard block padding
 -salt               Use salt in the KDF (default)
 -nosalt             Do not use salt in the KDF
 -debug              Print debug info
 -a                  Base64 encode/decode, depending on encryption flag
 -base64             Same as option -a
 -A                  Used with -[base64|a] to specify base64 buffer as a single line
 -bufsize val        Buffer size
 -k val              Passphrase
 -kfile infile       Read passphrase from file
 -K val              Raw key, in hex
 -S val              Salt, in hex
 -iv val             IV in hex
 -md val             Use specified digest to create a key from the passphrase
 -iter +int          Specify the iteration count and force use of PBKDF2
 -pbkdf2             Use password-based key derivation function 2
 -none               Don't encrypt
 -*                  Any supported cipher
 -rand val           Load the file(s) into the random number generator
 -writerand outfile  Write random data to the specified file
 -engine val         Use engine, possibly a hardware device
```







### example: use password encryption
* encryption
```
echo -n abcdefg > test.txt
openssl aes-128-cbc -e -pbkdf2 -in test.txt -out test.txt.aes
```
input the encryption password for two times, output
```
enter aes-128-cbc encryption password:
Verifying - enter aes-128-cbc encryption password:
```
* decryption
```
openssl aes-128-cbc -d -pbkdf2 -in test.txt.aes -out test2.txt
```
input the decrpytion password, output
```
enter aes-128-cbc decryption password:
```




### example: use raw key&iv encryption
Use the raw Key and IV to encryption the file
* encryption
```
echo -n Hello world! I am openssl! I am the most popular TLS stack in the world! > plain.txt
openssl aes-128-cbc -e -K 11111111111111111111111111111111 -iv 22222222222222222222222222222222 -in plain.txt -out plain.txt.aes
```
check the hex file plain.text.aes
```
hexdump -C plain.txt.aes 
```
output
```
00000000  42 b3 d7 f7 6e a2 cf e0  78 04 4b 3e 37 ba a0 fc  |B...n...x.K>7...|
00000010  1f 34 4f 28 e8 11 6d c8  6f 78 de 01 d8 e4 68 ce  |.4O(..m.ox....h.|
00000020  a4 6c fa ab ed 44 f2 a7  b2 95 06 57 ca 29 43 9c  |.l...D.....W.)C.|
00000030  f9 3e 84 6d f0 52 47 af  56 12 78 f9 82 19 97 0e  |.>.m.RG.V.x.....|
00000040  8a 97 27 7d 5f a5 22 04  90 44 31 0b 48 65 8a 62  |..'}_."..D1.He.b|
00000050
```
* decrpytion
```
openssl aes-128-cbc -d -K 11111111111111111111111111111111 -iv 22222222222222222222222222222222 -in plain.txt.aes -out plain2.txt
```
check the plain2.txt
```
cat plain2.txt 
```
output
```
Hello world! I am openssl! I am the most popular TLS stack in the world!
```
