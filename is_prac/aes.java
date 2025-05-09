import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

class aes{
    public static void main(String[] args) throws Exception {
        String key = "Th1sAESKey16Bit!"; // 16 bit key
        String data = "Hello AES";

        // create AES Key
        SecretKeySpec skeySpec = new SecretKeySpec(key.getBytes(), "AES");

        // create cipher object using AES with ECB mode with PKCS5 padding
        Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");

        // encryption:
        cipher.init(Cipher.ENCRYPT_MODE, skeySpec);
        byte[] encrypted = cipher.doFinal(data.getBytes());
        System.out.println("Encrypted: " + Base64.getEncoder().encodeToString(encrypted));

        // decryption:
        cipher.init(Cipher.DECRYPT_MODE, skeySpec);
        byte [] decrypted = cipher.doFinal(encrypted);
        System.out.println("Decrypted: " + new String(decrypted));
    }
}