#include <unistd.h>
#include <stdio.h>
#include <string.h>
// 👉 First, build and run the program.
//
// To do this, make sure you're in the `exercises` directory, and then run:
//
// gcc -o app2 2.c && ./app2

int main()
{
    char *header = "HTTP/1.1 200 OK";

    // 👉 Try replacing this `15` with a call to `strlen` (and `#include <string.h>` above!)
    write(1, header, strlen(header));

    // Explanation: \0 (zero-byte) is the termination special character for strings
    //  so strlen what basically does is to look for that character and determine the length until it finds it

    // 👉 After you're using `strlen` above, try adding a `\0` (with the backslash)
    // inside the definition of `header`, e.g.  "HTT\0P/1.1 200 OK" - this inserts
    // a zero byte in the string. Before you run the program, what do you think it will print?

    // 👉 Try changing this `%s` to `%zu` (ignore the compiler warning).
    printf("\n\nThat output was from write(). This is from printf: %zu\n", header);
    // Explanation: Every time we execute this, we get a different address number (zu prints it)
    // However, the OS makes use of a security feature called Address Space Layout Randomization (ASLR), which is integrated into the Linux kernel to mitigate memory corruption vulnerabilities.

    // 👉 Try changing the `%zud` back to `%s` and then replace the printf call's
    // last argument (originally `header`) with this argument instead: `(char*)123456`
    // 👉 Then try it with the number 0 instead of 123456.

    // Explanation: When using (char*)123456, it basically interpret this as a memory address
    //  However, that memory address is reserved by the OS and whe get a "Segmentation Fault" error

    return 0;
}

// Going a bit further regarding ASLR
// It's a technique to prevent the attack known as buffer overflow
// It consists of determining, based on a debugger, the memory positions assigned to a return address
// And instead of returning to the corresponding function, it returns to the code that the attacker defines, having the permissions with which the program is running