
#-------------------------------------------------------------------------------
# Configure variable
#-------------------------------------------------------------------------------
TOP_DIR:=${TOP_DIR}
MAKEFILE_PATH :=$(subst $(strip \),/,$(abspath $(lastword $(MAKEFILE_LIST))))


#-------------------------------------------------------------------------------
# Configure source code files
#-------------------------------------------------------------------------------
SRC_FILES+= \
  platform_util.c \
  md2.c \
  md.c \
  padlock.c \
  x509_csr.c \
  rsa_internal.c \
  ssl_cache.c \
  pkparse.c \
  ecdh.c \
  version_features.c \
  sha256.c \
  chacha20.c \
  poly1305.c \
  entropy.c \
  ripemd160.c \
  cmac.c \
  pkcs5.c \
  ecdsa.c \
  x509write_csr.c \
  ccm.c \
  ctr_drbg.c \
  rsa.c \
  pkcs11.c \
  ecp_curves.c \
  ssl_srv.c \
  threading.c \
  hmac_drbg.c \
  md5.c \
  x509.c \
  ssl_cli.c \
  asn1write.c \
  camellia.c \
  ssl_cookie.c \
  hkdf.c \
  x509_create.c \
  asn1parse.c \
  timing.c \
  nist_kw.c \
  ssl_tls.c \
  ssl_ticket.c \
  pk_wrap.c \
  aesni.c \
  base64.c \
  memory_buffer_alloc.c \
  pem.c \
  ecp.c \
  oid.c \
  dhm.c \
  aes.c \
  cipher.c \
  x509write_crt.c \
  blowfish.c \
  x509_crl.c \
  net_sockets.c \
  chachapoly.c \
  pkwrite.c \
  md4.c \
  cipher_wrap.c \
  bignum.c \
  gcm.c \
  error.c \
  entropy_poll.c \
  sha1.c \
  sha512.c \
  debug.c \
  ecjpake.c \
  pk.c \
  xtea.c \
  pkcs12.c \
  md_wrap.c \
  havege.c \
  des.c \
  platform.c \
  x509_crt.c \
  arc4.c \
  version.c \
  ssl_ciphersuites.c \
  aria.c \


#-------------------------------------------------------------------------------
# the include directories
#-------------------------------------------------------------------------------
INC_DIRS+= \
  -I${TOP_DIR}\ \
  -I${TOP_DIR}\common\include \


#-------------------------------------------------------------------------------
# Configure compile flag for C
#-------------------------------------------------------------------------------
U_FLAGS+= \

#-------------------------------------------------------------------------------
# Configure compile flag for C++
#-------------------------------------------------------------------------------
U_CPPFLAGS+=

#-------------------------------------------------------------------------------
# Configure default macro define
#-------------------------------------------------------------------------------
DFLAGS+= \
  -D"NO_APLP=0" \
  -DGPC_NO_CHANNEL_PROTECTION \
  -DENV_MANITOBA \
  -D"GPRS_MULTISLOT_CLASS=12" \
  -DMSL_ICAT_TRACE \
  -D"EGPRS_MULTISLOT_CLASS=12" \


#-------------------------------------------------------------------------------
# Configure link library
#-------------------------------------------------------------------------------
U_LIBS:=

#-------------------------------------------------------------------------------
# include mk file
#-------------------------------------------------------------------------------
include ${TOP_DIR}\config\common\makefile.mk
