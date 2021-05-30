# repo page

[ARMmbed/mbedtls](https://github.com/ARMmbed/mbedtls)

# use cmake to build the source code

### build and test

In order to build the source using CMake in a separate directory (recommended), just enter at the command line:
```
mkdir /path/to/build_dir && cd /path/to/build_dir
cmake /path/to/mbedtls_source
make
```

In order to run the tests, enter:
```
make test
```

### build libraries
To configure CMake for building shared libraries, use:
```
cmake -DUSE_SHARED_MBEDTLS_LIBRARY=On /path/to/mbedtls_source
make
sudo make install
sudo ldconfig
```

* The default library installation directory is /usr/local/lib
* The default tool installation directory is /usr/local/bin

installation log
```
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libmbedtls.a
-- Installing: /usr/local/lib/libmbedx509.a
-- Installing: /usr/local/lib/libmbedcrypto.a
-- Installing: /usr/local/lib/libmbedtls.so.2.16.3
-- Up-to-date: /usr/local/lib/libmbedtls.so.12
-- Set runtime path of "/usr/local/lib/libmbedtls.so.2.16.3" to ""
-- Up-to-date: /usr/local/lib/libmbedtls.so
-- Installing: /usr/local/lib/libmbedx509.so.2.16.3
-- Up-to-date: /usr/local/lib/libmbedx509.so.0
-- Set runtime path of "/usr/local/lib/libmbedx509.so.2.16.3" to ""
-- Up-to-date: /usr/local/lib/libmbedx509.so
-- Installing: /usr/local/lib/libmbedcrypto.so.2.16.3
-- Up-to-date: /usr/local/lib/libmbedcrypto.so.3
-- Up-to-date: /usr/local/lib/libmbedcrypto.so
-- Up-to-date: /usr/local/include/mbedtls/aes.h
-- Up-to-date: /usr/local/include/mbedtls/aesni.h
-- Up-to-date: /usr/local/include/mbedtls/arc4.h
-- Up-to-date: /usr/local/include/mbedtls/aria.h
-- Up-to-date: /usr/local/include/mbedtls/asn1.h
-- Up-to-date: /usr/local/include/mbedtls/asn1write.h
-- Up-to-date: /usr/local/include/mbedtls/base64.h
-- Up-to-date: /usr/local/include/mbedtls/bignum.h
-- Up-to-date: /usr/local/include/mbedtls/blowfish.h
-- Up-to-date: /usr/local/include/mbedtls/bn_mul.h
-- Up-to-date: /usr/local/include/mbedtls/camellia.h
-- Up-to-date: /usr/local/include/mbedtls/ccm.h
-- Up-to-date: /usr/local/include/mbedtls/certs.h
-- Up-to-date: /usr/local/include/mbedtls/chacha20.h
-- Up-to-date: /usr/local/include/mbedtls/chachapoly.h
-- Up-to-date: /usr/local/include/mbedtls/check_config.h
-- Up-to-date: /usr/local/include/mbedtls/cipher.h
-- Up-to-date: /usr/local/include/mbedtls/cipher_internal.h
-- Up-to-date: /usr/local/include/mbedtls/cmac.h
-- Up-to-date: /usr/local/include/mbedtls/compat-1.3.h
-- Up-to-date: /usr/local/include/mbedtls/config.h
-- Up-to-date: /usr/local/include/mbedtls/ctr_drbg.h
-- Up-to-date: /usr/local/include/mbedtls/debug.h
-- Up-to-date: /usr/local/include/mbedtls/des.h
-- Up-to-date: /usr/local/include/mbedtls/dhm.h
-- Up-to-date: /usr/local/include/mbedtls/ecdh.h
-- Up-to-date: /usr/local/include/mbedtls/ecdsa.h
-- Up-to-date: /usr/local/include/mbedtls/ecjpake.h
-- Up-to-date: /usr/local/include/mbedtls/ecp.h
-- Up-to-date: /usr/local/include/mbedtls/ecp_internal.h
-- Up-to-date: /usr/local/include/mbedtls/entropy.h
-- Up-to-date: /usr/local/include/mbedtls/entropy_poll.h
-- Up-to-date: /usr/local/include/mbedtls/error.h
-- Up-to-date: /usr/local/include/mbedtls/gcm.h
-- Up-to-date: /usr/local/include/mbedtls/havege.h
-- Up-to-date: /usr/local/include/mbedtls/hkdf.h
-- Up-to-date: /usr/local/include/mbedtls/hmac_drbg.h
-- Up-to-date: /usr/local/include/mbedtls/md.h
-- Up-to-date: /usr/local/include/mbedtls/md2.h
-- Up-to-date: /usr/local/include/mbedtls/md4.h
-- Up-to-date: /usr/local/include/mbedtls/md5.h
-- Up-to-date: /usr/local/include/mbedtls/md_internal.h
-- Up-to-date: /usr/local/include/mbedtls/memory_buffer_alloc.h
-- Up-to-date: /usr/local/include/mbedtls/net.h
-- Up-to-date: /usr/local/include/mbedtls/net_sockets.h
-- Up-to-date: /usr/local/include/mbedtls/nist_kw.h
-- Up-to-date: /usr/local/include/mbedtls/oid.h
-- Up-to-date: /usr/local/include/mbedtls/padlock.h
-- Up-to-date: /usr/local/include/mbedtls/pem.h
-- Up-to-date: /usr/local/include/mbedtls/pk.h
-- Up-to-date: /usr/local/include/mbedtls/pk_internal.h
-- Up-to-date: /usr/local/include/mbedtls/pkcs11.h
-- Up-to-date: /usr/local/include/mbedtls/pkcs12.h
-- Up-to-date: /usr/local/include/mbedtls/pkcs5.h
-- Up-to-date: /usr/local/include/mbedtls/platform.h
-- Up-to-date: /usr/local/include/mbedtls/platform_time.h
-- Up-to-date: /usr/local/include/mbedtls/platform_util.h
-- Up-to-date: /usr/local/include/mbedtls/poly1305.h
-- Up-to-date: /usr/local/include/mbedtls/ripemd160.h
-- Up-to-date: /usr/local/include/mbedtls/rsa.h
-- Up-to-date: /usr/local/include/mbedtls/rsa_internal.h
-- Up-to-date: /usr/local/include/mbedtls/sha1.h
-- Up-to-date: /usr/local/include/mbedtls/sha256.h
-- Up-to-date: /usr/local/include/mbedtls/sha512.h
-- Up-to-date: /usr/local/include/mbedtls/ssl.h
-- Up-to-date: /usr/local/include/mbedtls/ssl_cache.h
-- Up-to-date: /usr/local/include/mbedtls/ssl_ciphersuites.h
-- Up-to-date: /usr/local/include/mbedtls/ssl_cookie.h
-- Up-to-date: /usr/local/include/mbedtls/ssl_internal.h
-- Up-to-date: /usr/local/include/mbedtls/ssl_ticket.h
-- Up-to-date: /usr/local/include/mbedtls/threading.h
-- Up-to-date: /usr/local/include/mbedtls/timing.h
-- Up-to-date: /usr/local/include/mbedtls/version.h
-- Up-to-date: /usr/local/include/mbedtls/x509.h
-- Up-to-date: /usr/local/include/mbedtls/x509_crl.h
-- Up-to-date: /usr/local/include/mbedtls/x509_crt.h
-- Up-to-date: /usr/local/include/mbedtls/x509_csr.h
-- Up-to-date: /usr/local/include/mbedtls/xtea.h
-- Installing: /usr/local/bin/aescrypt2
-- Set runtime path of "/usr/local/bin/aescrypt2" to ""
-- Installing: /usr/local/bin/crypt_and_hash
-- Set runtime path of "/usr/local/bin/crypt_and_hash" to ""
-- Installing: /usr/local/bin/hello
-- Set runtime path of "/usr/local/bin/hello" to ""
-- Installing: /usr/local/bin/generic_sum
-- Set runtime path of "/usr/local/bin/generic_sum" to ""
-- Installing: /usr/local/bin/dh_client
-- Set runtime path of "/usr/local/bin/dh_client" to ""
-- Installing: /usr/local/bin/dh_genprime
-- Set runtime path of "/usr/local/bin/dh_genprime" to ""
-- Installing: /usr/local/bin/dh_server
-- Set runtime path of "/usr/local/bin/dh_server" to ""
-- Installing: /usr/local/bin/key_app
-- Set runtime path of "/usr/local/bin/key_app" to ""
-- Installing: /usr/local/bin/mpi_demo
-- Set runtime path of "/usr/local/bin/mpi_demo" to ""
-- Installing: /usr/local/bin/rsa_genkey
-- Set runtime path of "/usr/local/bin/rsa_genkey" to ""
-- Installing: /usr/local/bin/rsa_sign
-- Set runtime path of "/usr/local/bin/rsa_sign" to ""
-- Installing: /usr/local/bin/rsa_verify
-- Set runtime path of "/usr/local/bin/rsa_verify" to ""
-- Installing: /usr/local/bin/rsa_encrypt
-- Set runtime path of "/usr/local/bin/rsa_encrypt" to ""
-- Installing: /usr/local/bin/rsa_decrypt
-- Set runtime path of "/usr/local/bin/rsa_decrypt" to ""
-- Installing: /usr/local/bin/pk_encrypt
-- Set runtime path of "/usr/local/bin/pk_encrypt" to ""
-- Installing: /usr/local/bin/pk_decrypt
-- Set runtime path of "/usr/local/bin/pk_decrypt" to ""
-- Installing: /usr/local/bin/pk_sign
-- Set runtime path of "/usr/local/bin/pk_sign" to ""
-- Installing: /usr/local/bin/pk_verify
-- Set runtime path of "/usr/local/bin/pk_verify" to ""
-- Installing: /usr/local/bin/gen_key
-- Set runtime path of "/usr/local/bin/gen_key" to ""
-- Installing: /usr/local/bin/gen_random_havege
-- Set runtime path of "/usr/local/bin/gen_random_havege" to ""
-- Installing: /usr/local/bin/gen_random_ctr_drbg
-- Set runtime path of "/usr/local/bin/gen_random_ctr_drbg" to ""
-- Installing: /usr/local/bin/gen_entropy
-- Set runtime path of "/usr/local/bin/gen_entropy" to ""
-- Installing: /usr/local/bin/dtls_client
-- Set runtime path of "/usr/local/bin/dtls_client" to ""
-- Installing: /usr/local/bin/dtls_server
-- Set runtime path of "/usr/local/bin/dtls_server" to ""
-- Installing: /usr/local/bin/ssl_client1
-- Set runtime path of "/usr/local/bin/ssl_client1" to ""
-- Installing: /usr/local/bin/ssl_client2
-- Set runtime path of "/usr/local/bin/ssl_client2" to ""
-- Installing: /usr/local/bin/ssl_server
-- Set runtime path of "/usr/local/bin/ssl_server" to ""
-- Installing: /usr/local/bin/ssl_fork_server
-- Set runtime path of "/usr/local/bin/ssl_fork_server" to ""
-- Installing: /usr/local/bin/ssl_mail_client
-- Set runtime path of "/usr/local/bin/ssl_mail_client" to ""
-- Installing: /usr/local/bin/mini_client
-- Set runtime path of "/usr/local/bin/mini_client" to ""
-- Installing: /usr/local/bin/ssl_pthread_server
-- Set runtime path of "/usr/local/bin/ssl_pthread_server" to ""
-- Installing: /usr/local/bin/selftest
-- Set runtime path of "/usr/local/bin/selftest" to ""
-- Installing: /usr/local/bin/benchmark
-- Set runtime path of "/usr/local/bin/benchmark" to ""
-- Installing: /usr/local/bin/udp_proxy
-- Set runtime path of "/usr/local/bin/udp_proxy" to ""
-- Installing: /usr/local/bin/query_compile_time_config
-- Set runtime path of "/usr/local/bin/query_compile_time_config" to ""
-- Installing: /usr/local/bin/cert_app
-- Set runtime path of "/usr/local/bin/cert_app" to ""
-- Installing: /usr/local/bin/crl_app
-- Set runtime path of "/usr/local/bin/crl_app" to ""
-- Installing: /usr/local/bin/req_app
-- Set runtime path of "/usr/local/bin/req_app" to ""
-- Installing: /usr/local/bin/cert_req
-- Set runtime path of "/usr/local/bin/cert_req" to ""
-- Installing: /usr/local/bin/cert_write
-- Set runtime path of "/usr/local/bin/cert_write" to ""
-- Installing: /usr/local/bin/strerror
-- Set runtime path of "/usr/local/bin/strerror" to ""
-- Installing: /usr/local/bin/pem2der
-- Set runtime path of "/usr/local/bin/pem2der" to ""
```

### test example
hello is a tool of mbedtls, input this command to calculate the 'Hello, world!' md5:
```
hello
```
output
```

  MD5('Hello, world!') = 6cd3556deb0da54bca060b4c39479839

```
