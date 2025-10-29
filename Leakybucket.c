#include <stdio.h>

int main() {
    int incoming, outgoing, bucket_size, n, store = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing);

    printf("Enter number of inputs: ");
    scanf("%d", &n);

    while (n != 0) {
        printf("\nEnter the incoming packet size: ");
        scanf("%d", &incoming);

        printf("Incoming packet size: %d\n", incoming);

       
        if (incoming <= (bucket_size - store)) {
            store += incoming;
            printf("Bucket buffer size: %d out of %d\n", store, bucket_size);
        } else {
            int dropped = incoming - (bucket_size - store);
            printf("Bucket overflow! Dropped %d packets.\n", dropped);
            store = bucket_size;
            printf("Bucket buffer size: %d out of %d\n", store, bucket_size);
        }

        // Packets leave the bucket
        store -= outgoing;
        if (store < 0)
            store = 0;

        printf("After outgoing: %d packets left in buffer out of %d\n", store, bucket_size);

        n--;
    }

    return 0;
}
