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


