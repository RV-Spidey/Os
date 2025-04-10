#include <stdio.h>

void main() {
    int i, j = 0, n, rs[50], frame[10], nf, k, found, pagefault = 0, pagehit = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++)
        frame[i] = -1;

    printf("Ref string\tPage frames\t\tPage Fault/Page Hit\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (k = 0; k < nf; k++) {
            if (frame[k] == rs[i]) {
                found = 1;
                break;
            }
        }

        printf("%d\t\t", rs[i]);

        if (found) {
            pagehit++;
            for (k = 0; k < nf; k++)
                printf("%d\t", frame[k]);
            printf("Page Hit\n");
        } else {
            frame[j] = rs[i];
            j = (j + 1) % nf;
            pagefault++;
            for (k = 0; k < nf; k++)
                printf("%d\t", frame[k]);
            printf("Page Fault\n");
        }
    }

    printf("\nTotal Page Faults: %d", pagefault);
    printf("\nTotal Page Hits: %d\n", pagehit);
}
