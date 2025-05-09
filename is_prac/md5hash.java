import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class md5hash {
    public static String getMD5Hash(String input) {
        try {
            // Create MD5 MessageDigest instance
            MessageDigest md = MessageDigest.getInstance("MD5");

            // Compute hash as byte array
            byte[] messageDigest = md.digest(input.getBytes());

            // Convert byte array into hexadecimal format
            StringBuilder hexString = new StringBuilder();
            for (byte b : messageDigest) {
                hexString.append(String.format("%02x", b));
            }

            return hexString.toString();

        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a text: ");
        String input = sc.nextLine();

        String hash = getMD5Hash(input);
        System.out.println("MD5 Hash: " + hash);
    }
}



/*

Let’s say the input is a message M.

1. Padding the Message
Make the message length a multiple of 512 bits.

Add a single 1 bit, followed by 0s.

Then add the original length of the message as a 64-bit number.

2. Initialize MD5 Variables
Set 4 variables (registers) as 32-bit values:

ini
Copy
Edit
A = 0x67452301  
B = 0xefcdab89  
C = 0x98badcfe  
D = 0x10325476
3. Process Message in 512-bit Blocks
For each block, perform 64 operations divided into 4 rounds of 16 operations:

Use logical functions (AND, OR, NOT, XOR)

Add constants

Use left circular shifts

Each operation changes the values of A, B, C, D.

4. Final Hash Value
After all blocks are processed:

Combine A, B, C, and D → gives the 128-bit MD5 hash.

*/
