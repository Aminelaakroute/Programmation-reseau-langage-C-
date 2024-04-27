**Here are summaries for each exercise with the filename and execution method:**


1. **protocole_info.c**:
   - Role: This code displays information about network protocols based on their name or port number.
   It uses the functions `getprotobyname()` and `getprotobynumber()` to retrieve information about each protocol.

2. **list_protocols.c**:
   - Role: This code lists network protocols listed in the `/etc/protocols` file.
   It uses the functions `getprotoent()` and `getservbyport()` to obtain information about each protocol.

3. **hex_to_bytes.c**:
   - Role: This code takes a hexadecimal value from the command line and displays its byte-by-byte representation.

4. **service_info**:
   - Role: This code allows users to retrieve and display information about network services based on their names or port numbers.
   It achieves this by iterating over command-line arguments, calling the affiche_service function for each argument
   with both "tcp" and "udp" protocols. The affiche_service function attempts to retrieve service information
   using either the service name or port number, and if found, it prints details such as the service name,
   aliases, and port number. If no information is found, it prints a message indicating that the service is unknown.
   based on their name or port number.

5. **list_services-secure.c**:
   - Role: This code lists network services listed in the `/etc/services` file securely using `getservent_r()`.

6. **ip_conversion.c**:
   - Role: This code takes an IP address in dotted decimal notation from the command line and converts it to
   hexadecimal and signed decimal representation.

7. **ip_network_host.c**:
   - Role: This code takes an IP address in dotted decimal notation from the command line and separates it
   into its network and host portions.

8. **ip_network_local_V1.c**:
   - Role: This code takes an IP address in dotted decimal notation from the command line and separates it
   into its network and local portions using Method 1.
     
9. **ip_network_local_V2.c**:
   - Role: This code takes an IP address in dotted decimal notation from the command line and separates it
   into its network and local portions using Method 2.
    
10. **ip_network_local_V3.c**:
   - Role: This code takes an IP address in dotted decimal notation from the command line and separates it
   into its network and local portions using Method 3.

Each code accomplishes a specific task related to handling IP addresses, 
looking up network protocols or services, and converting between different IP address formats or data representations.


**To compile and execute a C program, you can use the following commands in a terminal:**


**Compilation**:

   Use the `gcc` (GNU Compiler Collection) command to compile your C program.
   For example, if your file is named `my_program.c`, you can compile it with the following command:

   ```
   gcc -o my_program my_program.c
   ```

   This command will generate an executable file named `my_program`.

**Execution**:

   After compiling your program, you can execute it by simply using its name.
   For example, to execute the program `my_program`, type the following command:

   ```
   ./my_program [arguments]
   ```

   Replace `[arguments]` with any necessary arguments needed to execute your program, if any.

**Make sure you are in the directory where your source file (`.c`) is located when running these commands.**
