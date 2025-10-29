#include <stdio.h>
#include <string.h>

#define N strlen(poly)

char data[30];
char check_value[30];
char poly[10];
int data_length, i, j;

void XOR() {
    for (j = 1; j < N; j++) {
        check_value[j] = (check_value[j] == poly[j]) ? '0' : '1';
    }
}

void crc() {
    for (i = 0; i < N; i++)
        check_value[i] = data[i];

    do {
        if (check_value[0] == '1')
            XOR();

        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];

        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);
}

void receiver() {
    printf("\nEnter the received data: ");
    scanf("%s", data);
    printf("Data received: %s\n", data);

    crc();

    
    for (i = 0; i < N - 1; i++) {
        if (check_value[i] == '1') {
            printf("Error detected in received data!\n");
            return;
        }
    }

    printf("No error detected.\n");
}

int main() {
    printf("Enter data to be transmitted: ");
    scanf("%s", data);

    printf("Enter the divisor polynomial: ");
    scanf("%s", poly);

    data_length = strlen(data);

    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    data[i] = '\0';

    printf("Data padded with n-1 zeroes: %s\n", data);

    crc();

    printf("CRC value is: ");
    for (i = 0; i < N - 1; i++)
        printf("%c", check_value[i]);


    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];
    data[i] = '\0';

    printf("\nFinal codeword to be sent: %s\n", data);

    receiver();

    return 0;
}
