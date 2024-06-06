## TASK ONE
- Create file openssl rand -out random_text.txt 1024
- Encrypt File openssl enc -aes-256-cbc -in random_text.txt -out encrypted_file.bin
- Decrypt file openssl enc -d -aes-256-cbc -in encrypted_file.bin -out decrypted_text.txt

## TASK TWO
- openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:1024 (this command generates private key, using rsa algorithm, outputs private key in private_key.pem file)
- openssl rsa -in private_key.pem -text (displays the key in human readable form)
- openssl rsa -in private_key.pem -out private_key_des3.pem -des3 (encrypts the private key with triple des)
- openssl rsa -in private_key_des3.pem -pubout -out public_key.pem (extracts the public key and write in file)
- openssl rand -out aes_key.bin 32
- openssl base64 -in aes_key.bin -out aes_key_base64.bin (Generates 32 bytes of random data encoded in base64.)
- openssl rsautl -encrypt -inkey public_key.pem -pubin -in aes_key.bin -out encrypted_aes_key.bin (Encrypts data)
- openssl rand -out random_text.txt 1024 (generate file to be encrypted)
- openssl enc -aes-256-cbc -in random_text.txt -out encrypted_file.bin -pass file:aes_key.bin (Encrypts data using  AES-256-CBC encryption algorithm, -in random_text.txt: Specifies the input file to be encrypted. -pass file:aes_key.bin: Uses the contents of aes_key.bin as the password for encryption.)
- openssl rsautl -decrypt -inkey private_key_des3.pem -in encrypted_aes_key.bin -out decrypted_aes_key.bin (Decrypts data, -inkey private_key_des3.pem: Specifies the input encrypted private key file.
-in encrypted_aes_key.bin: Specifies the input file to be decrypted.
-out decrypted_aes_key.bin: Outputs the decrypted data to decrypted_aes_key.bin. )
- openssl enc -d -aes-256-cbc -in encrypted_file.bin -out decrypted_text.txt -pass file:decrypted_aes_key.bin (-in encrypted_file.bin: Specifies the input encrypted file.
-out decrypted_text.txt: Outputs the decrypted data to decrypted_text.txt.
-pass file:decrypted_aes_key.bin: Uses the contents of decrypted_aes_key.bin as the password for decryption.)
Task Three
A digital signature is a cryptographic technique used to validate the authenticity and integrity of a message, software, or digital document. It is the digital equivalent of a handwritten signature or a stamped seal but much more secure. Digital signatures use public key cryptography, also known as asymmetric cryptography.

Authenticity: They confirm that the message or document was created by a known sender (authenticity).
Integrity: They ensure that the content has not been altered since it was signed (integrity).

A digest is a fixed-size numeric representation of the contents of a file, generated using a hash function. Commonly used hash functions include SHA-256 and MD5. The digest (or hash value) is unique to the original content, much like a fingerprint.

A digital signature is created by encrypting the digest value of a message or document with the sender's private key. This signature can then be decrypted by anyone using the sender's public key, thereby verifying the authenticity and integrity of the message.

The recipient then generates a new digest from the received document and compares it to the decrypted digest. If the digests match, the signature is valid, confirming the document's authenticity and integrity.

openssl dgst -sha256 -out digest_value.sha256 random_text.txt
openssl dgst -sha256 -sign private_key_des3.pem -out signature.bin random_text.txt
openssl dgst -sha256 -verify public_key.pem -signature signature.bin random_text.txt
openssl dgst -sha256 random_text.txt

cat digest_value.sha256 
or 
type digest_value.sha256 


Task Four
A certificate, specifically a digital certificate, is like an online ID card that helps prove the identity of a website or server to users. It's used to establish secure, encrypted communications over the internet, typically through HTTPS.

Key Components of a Certificate

1. Public Key: A key that can be shared openly and is used to encrypt data.
2. Information: Details about the entity, such as the domain name e.g., www.example.com and the organization.
3. Digital Signature of the CA: A signature from a Certificate Authority CA that verifies the certificate's authenticity.

1. Website Setup
   The owner of a website e.g., www.example.com wants to ensure that visitors can securely connect to their site.
   The website owner generates a public key and a private key.
   The owner then contacts a Certificate Authority (CA) like Let's Encrypt or DigiCert and requests a certificate.

2. Certificate Issuance:
   The CA verifies the identity of the website owner (e.g., checking that they really own the domain www.example.com).
   Once verified, the CA issues a certificate containing the website's public key, information about the website, and the CA's digital signature.

3. Using the Certificate
   The website owner installs the certificate on their web server.
   When a user visits www.example.com, the server sends the certificate to the user's browser.

4. Verification
   The user's browser receives the certificate and checks the CA's digital signature to ensure it's valid.
   The browser also checks if the certificate is from a trusted CA (most browsers have a list of trusted CAs).
   If the certificate is valid and trusted, the browser establishes a secure, encrypted connection with the website.

Why Certificates Matter

They enable encrypted communication, protecting your data from eavesdroppers.
They verify that the website you’re connecting to is legitimate, preventing phishing attacks.

Self signed certificates
You generate and sign the certificate yourself.
When visitors go to your website, their browsers will show a warning saying the connection is not trusted because the certificate is self-signed.
Good for testing or internal use where you can manually tell the browsers to trust the certificate.


Self-Signed Certificate:

Signed by the entity that owns it.
Not trusted by browsers or operating systems because they haven't been verified by a trusted CA.
Free to create.
Use cases are Testing, development, internal applications.

CA-Signed Certificate:

Signed by a trusted third-party Certificate Authority (CA).
Automatically trusted by browsers and operating systems because CAs are recognized and trusted entities.
Requires payment to the CA.
Use cases are Public websites, online services, and any scenario where establishing trust with users is critical.

How to create self signed certificate

openssl genrsa -des3 -out domain.key 2048
openssl req -key domain.key -new -out domain.csr
openssl x509 -signkey domain.key -in domain.csr -req -days 365 -out domain.crt
openssl req -x509 -sha256 -days 1825 -newkey rsa:2048 -keyout rootCA.key -out rootCA.crt

create file domain.ext and add content

authorityKeyIdentifier=keyid,issuer
basicConstraints=CA:FALSE
subjectAltName = @alt_names
[alt_names]
DNS.1 = domain

openssl x509 -req -CA rootCA.crt -CAkey rootCA.key -in domain.csr -out domain.crt -days 365 -CAcreateserial -extfile domain.ext
openssl x509 -text -noout -in domain.crt
