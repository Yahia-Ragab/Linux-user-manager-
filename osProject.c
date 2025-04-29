#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_manager.h"


int main() {
    int choice;
    char adminPass[50];
    
    printf("Enter your admin password: ");
    fgets(adminPass, sizeof(adminPass), stdin);
    adminPass[strcspn(adminPass, "\n")] = 0;

    while (1) {
        printf("\n==== User Manager ====\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Add Group\n");
        printf("4. Delete Group\n");
        printf("5. Change User Info\n");
        printf("6. Change Account Info\n");
        printf("7. Assign User to Group\n");
        printf("8. Delete user from a Group\n");
        printf("9. List Users\n");
        printf("10. List Groups\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        
        switch (choice) {
            case 1: {
                char username[50], password[50];
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;
                addUser(username, password, adminPass);
                break;
            }


            case 2: {
                char username[50];
                printf("Enter username to delete: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                deleteUser(username, adminPass);
                break;
            }


            case 3: {
                char groupname[50];
                printf("Enter group name to add: ");
                fgets(groupname, sizeof(groupname), stdin);
                groupname[strcspn(groupname, "\n")] = 0;
                addGroup(groupname, adminPass);
                break;
            }


            case 4: {
                char groupname[50];
                printf("Enter group name to delete: ");
                fgets(groupname, sizeof(groupname), stdin);
                groupname[strcspn(groupname, "\n")] = 0;
                deleteGroup(groupname, adminPass);
                break;
            }


            case 5: {
                char oldUsername[50], newUsername[50];
                printf("Enter the old username: ");
                fgets(oldUsername, sizeof(oldUsername), stdin);
                oldUsername[strcspn(oldUsername, "\n")] = '\0';
                printf("Enter the new username: ");
                fgets(newUsername, sizeof(newUsername), stdin);
                newUsername[strcspn(newUsername, "\n")] = '\0';
                changeUserInfo(oldUsername, newUsername, adminPass);
                break;
            }


            case 6: {
                char username[50];
                printf("Enter username to change account info: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                int days;
                printf("Enter password expiration (in days): ");
                scanf("%d", &days); 
                getchar(); 
                changeAccountInfo(username, days, adminPass);

                break;
            }


            case 7: {
                char username[50], groupname[50];
                printf("Enter username to assign to group: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                printf("Enter group name: ");
                fgets(groupname, sizeof(groupname), stdin);
                groupname[strcspn(groupname, "\n")] = 0;
                assignUserToGroup(username, groupname, adminPass);
                break;
            }

            case 8:{
                char username[50], group[50];
                printf("Enter the username to remove from group: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';
                
                printf("Enter the group name: ");
                fgets(group, sizeof(group), stdin);
                group[strcspn(group, "\n")] = '\0';
                
                deleteUserFromGroup(username, group, adminPass);
                break;}
            case 9: listUsers(); break;
            case 10: listGroups(); break;
            case 11: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
