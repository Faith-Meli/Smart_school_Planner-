#include <stdio.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_MSGS 10
#define MSG_LEN 100

typedef struct {
    char subject[30];
    char time[20];
    char location[30];
    char status[20]; // e.g., Scheduled, Cancelled, In Progress
} Class;

typedef struct {
    char from[20];
    char to[20];
    char message[MSG_LEN];
} Message;

Class timetable[MAX_CLASSES];
Message messages[MAX_MSGS];
int class_count = 0;
int msg_count = 0;

// Function to add a class
void add_class() {
    if (class_count >= MAX_CLASSES) {
        printf("Timetable full!\n");
        return;
    }
    printf("\nEnter Subject: ");
    scanf(" %[^\n]", timetable[class_count].subject);
    printf("Enter Time (e.g., 10:00AM): ");
    scanf(" %[^\n]", timetable[class_count].time);
    printf("Enter Location: ");
    scanf(" %[^\n]", timetable[class_count].location);
    strcpy(timetable[class_count].status, "Scheduled");
    class_count++;
    printf("Class added successfully!\n");
}

// Function to view timetable
void view_timetable() {
    printf("\n--- Timetable ---\n");
    for (int i = 0; i < class_count; i++) {
        printf("Subject: %s | Time: %s | Location: %s | Status: %s\n",
            timetable[i].subject, timetable[i].time,
            timetable[i].location, timetable[i].status);
    }
}

// Update class status
void update_class_status() {
    char subject[30];
    printf("Enter subject to update: ");
    scanf(" %[^\n]", subject);
    for (int i = 0; i < class_count; i++) {
        if (strcmp(subject, timetable[i].subject) == 0) {
            printf("Enter new status (Scheduled/Cancelled/In Progress): ");
            scanf(" %[^\n]", timetable[i].status);
            printf("Status updated.\n");
            return;
        }
    }
    printf("Class not found.\n");
}

// Messaging system
void send_message() {
    if (msg_count >= MAX_MSGS) {
        printf("Message storage full!\n");
        return;
    }
    printf("From: ");
    scanf(" %[^\n]", messages[msg_count].from);
    printf("To: ");
    scanf(" %[^\n]", messages[msg_count].to);
    printf("Message: ");
    scanf(" %[^\n]", messages[msg_count].message);
    msg_count++;
    printf("Message sent.\n");
}

void view_messages() {
    printf("\n--- Messages ---\n");
    for (int i = 0; i < msg_count; i++) {
        printf("From: %s | To: %s\nMessage: %s\n", messages[i].from, messages[i].to, messages[i].message);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n==== Smart School Planner ====\n");
        printf("1. Add Class\n");
        printf("2. View Timetable\n");
        printf("3. Update Class Status\n");
        printf("4. Send Message\n");
        printf("5. View Messages\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_class(); break;
            case 2: view_timetable(); break;
            case 3: update_class_status(); break;
            case 4: send_message(); break;
            case 5: view_messages(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}