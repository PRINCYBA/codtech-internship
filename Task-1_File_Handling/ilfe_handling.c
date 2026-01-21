#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    // Write to file
    fp = fopen("data.txt", "w");
    fprintf(fp, "CODTECH Internship File Handling\n");
    fclose(fp);

    // Append to file
    fp = fopen("data.txt", "a");
    fprintf(fp, "Task 1 completed successfully\n");
    fclose(fp);

    // Read from file
    fp = fopen("data.txt", "r");
    printf("File Content:\n");
    while (fgets(data, sizeof(data), fp)) {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}
