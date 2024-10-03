#include <stdio.h>

int main() {
    int bucket_size, outgoing_rate, incoming, n, store = 0;

    // Input bucket size and outgoing rate
    printf("Enter the bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter the outgoing rate: ");
    scanf("%d", &outgoing_rate);

    printf("Enter the number of incoming packets: ");
    scanf("%d", &n);

    // Iterate over each incoming packet
    for (int i = 1; i <= n; i++) {
        printf("\nEnter the incoming packet size at second %d: ", i);
        scanf("%d", &incoming);

        // Check if incoming data can fit in the bucket
        if (incoming + store > bucket_size) {
            printf("Bucket overflow! Packet of size %d is discarded.\n", incoming);
        } else {
            store += incoming;
            printf("Packet of size %d added to the bucket.\n", incoming);
        }

        // Send out data at the outgoing rate
        if (store < outgoing_rate) {
            printf("Sent out %d packets.\n", store);
            store = 0;
        } else {
            printf("Sent out %d packets.\n", outgoing_rate);
            store -= outgoing_rate;
        }

        // Show current bucket content
        printf("Current bucket size: %d\n", store);
    }

    // Handle remaining data in the bucket
    while (store > 0) {
        if (store < outgoing_rate) {
            printf("\nSent out %d packets. Bucket is now empty.\n", store);
            store = 0;
        } else {
            printf("\nSent out %d packets.\n", outgoing_rate);
            store -= outgoing_rate;
            printf("Remaining in bucket: %d\n", store);
        }
    }

    return 0;
}
