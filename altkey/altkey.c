/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
	This product includes software developed by the OpenSSL Project for use in the OpenSSL Toolkit (http://www.openssl.org/)
*/
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main(int argc, char *argv[]);
void error(BIO *bOut, const char *src);
EC_GROUP *EC_KEY_get_group_public_point(BIO *bOut, const EC_KEY *p);

int main(int argc, char *argv[])
{
	BIO *bCert, *bKey, *bOut;
	X509 *xCert;
	EVP_PKEY *publicKey;
	EC_KEY *ecPublicKey;
	EC_GROUP *ecGroup;
	char *keyFilename = (argc > 2) ? argv[2] : "ec_new_privatekey.pem";

	if(bOut = BIO_new_fp(stdout, BIO_NOCLOSE))
	{
		if(argc > 1)
		{
			if(bCert = BIO_new(BIO_s_file()))
			{
				if(BIO_read_filename(bCert, argv[1]))
				{
					if(xCert = PEM_read_bio_X509(bCert, NULL, 0, NULL))
					{
						X509_print_ex(bOut, xCert, 0, X509_FLAG_NO_VERSION | X509_FLAG_NO_SIGNAME | X509_FLAG_NO_EXTENSIONS | X509_FLAG_NO_SIGDUMP | X509_FLAG_NO_EXTENSIONS | X509_FLAG_NO_AUX | X509_FLAG_NO_ATTRIBUTES | X509_FLAG_NO_IDS);
						if(publicKey = X509_get0_pubkey(xCert))
						{
							if(EVP_PKEY_id(publicKey) == EVP_PKEY_EC)
							{
								if(ecPublicKey = EVP_PKEY_get0_EC_KEY(publicKey))
								{
									if(ecGroup = EC_KEY_get_group_public_point(bOut, ecPublicKey))
									{
										if(EC_KEY_set_group(ecPublicKey, ecGroup))
										{
											if(EC_KEY_set_private_key(ecPublicKey, BN_value_one()))
											{
												BIO_printf(bOut, "Private-Key set to 1\n");
												EC_KEY_print(bOut, ecPublicKey, 0);
												if(bKey = BIO_new(BIO_s_file()))
												{
													if(BIO_write_filename(bKey, keyFilename))
													{
														if(PEM_write_bio_ECPrivateKey(bKey, ecPublicKey, NULL, NULL, 0, NULL, NULL))
															BIO_printf(bOut, "Private-Key saved to: %s\n", keyFilename);
														else error(bOut, "PEM_write_bio_ECPrivateKey");
													}
													else error(bOut, "BIO_write_filename");
													BIO_free(bKey);
												}
												else error(bOut, "BIO_new(BIO_s_file()) - bKey");
											}
											else error(bOut, "EC_KEY_set_private_key");
										}
										else error(bOut, "EC_KEY_set_group");
										EC_GROUP_free(ecGroup);
									}
								}
								else error(bOut, "EVP_PKEY_get0_EC_KEY");
							}
							else BIO_printf(bOut, "PublicKey is not EC\n");
						}
						else error(bOut, "X509_get0_pubkey");
						X509_free(xCert);
					}
					else error(bOut, "PEM_read_bio_X509");
					BIO_free(bCert);
				}
				else error(bOut, "BIO_read_filename");
			}
			else error(bOut, "BIO_new(BIO_s_file()) - bCert");
		}
		else BIO_printf(bOut, "%s ec_public_certificate.pem [ec_new_privatekey.pem]\n", argv[0]);
		BIO_free(bOut);
	}
	return 0;
}

void error(BIO *bOut, const char *src)
{
	BIO_printf(bOut, "[ERROR - %s]\n", src);
	ERR_print_errors(bOut);
}

EC_GROUP *EC_KEY_get_group_public_point(BIO *bOut, const EC_KEY *p)
{
	EC_GROUP *ecGroup = NULL;
	if(ecGroup = EC_GROUP_dup(EC_KEY_get0_group(p)))
	{
		EC_GROUP_set_asn1_flag(ecGroup, OPENSSL_EC_EXPLICIT_CURVE);
		if(!EC_GROUP_set_generator(ecGroup, EC_KEY_get0_public_key(p), EC_GROUP_get0_order(EC_KEY_get0_group(p)), EC_GROUP_get0_cofactor(EC_KEY_get0_group(p))))
		{
			error(bOut, "EC_GROUP_set_generator");
			EC_GROUP_free(ecGroup);
			ecGroup = NULL;
		}
	}
	else error(bOut, "EC_GROUP_dup");
	return ecGroup;
}