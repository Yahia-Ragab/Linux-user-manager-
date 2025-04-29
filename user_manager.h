#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addUser(const char *username, const char *password, const char *adminPass) {
    char com[200];
    
    sprintf(com, "echo '%s' | sudo -S useradd -m -s /bin/bash '%s'", adminPass, username);
    if (system(com) != 0) {
        printf("Error adding user\n");
        return;
    }

    sprintf(com, "echo '%s:%s' | sudo -S chpasswd", username, password);
    if (system(com) != 0) {
        printf("Error setting password\n");
    }
}

void deleteUser(const char *username, const char *adminPass) {
    char com[200];
    sprintf(com, "echo '%s' | sudo -S userdel -r '%s' > /dev/null 2>&1", adminPass, username);
    if (system(com) != 0) {
        printf("Error deleting user\n");
    } else {
        printf("User %s deleted successfully\n", username);
    }
}

void addGroup(const char *groupname, const char *adminPass) {
    char com[100];
    sprintf(com, "echo '%s' | sudo -S groupadd '%s'", adminPass, groupname);
    if (system(com) != 0) {
        printf("Error adding group\n");
    }
}

void deleteGroup(const char *groupname, const char *adminPass) {
    char com[100];
    sprintf(com, "echo '%s' | sudo -S groupdel '%s'", adminPass, groupname);
    if (system(com) != 0) {
        printf("Error deleting group\n");
    }
}

void changeUserInfo(const char *oldUsername, const char *newUsername, const char *adminPass) {
    char com[200];
    sprintf(com, "echo '%s' | sudo -S usermod -l %s %s", adminPass, newUsername, oldUsername);
    if (system(com) != 0) {
        printf("Error changing username from %s to %s.\n", oldUsername, newUsername);
    } else {
        printf("Username changed from %s to %s successfully.\n", oldUsername, newUsername);
    }
}

void changeAccountInfo(const char *username, int days, const char *adminPass) {
    char com[200];
    sprintf(com, "echo '%s' | sudo -S chage -M %d %s", adminPass, days, username);
    if (system(com) != 0) {
        printf("Error changing account info for %s.\n", username);
    } else {
        printf("Account info for %s changed successfully: Password expiration set to %d days.\n", username, days);
    }
}

void assignUserToGroup(const char *username, const char *groupname, const char *adminPass) {
    char com[200];
    sprintf(com, "echo '%s' | sudo -S usermod -a -G %s %s", adminPass, groupname, username);
    
    if (system(com) != 0) {
        printf("Error assigning user %s to group %s\n", username, groupname);
    } else {
        printf("User %s assigned to group %s successfully.\n", username, groupname);
    }
}


void deleteUserFromGroup(const char *username, const char *group, const char *adminPass) {
    char com[200];
    sprintf(com, "echo '%s' | sudo -S gpasswd -d %s %s", adminPass, username, group);
    if (system(com) != 0) {
        printf("Error removing user %s from group %s.\n", username, group);
    } else {
        printf("User %s removed from group %s successfully.\n", username, group);
    }
}


void listUsers() {
    printf("\n=== Users List ===\n");
    system("cut -d: -f1 /etc/passwd");
}

void listGroups() {
    printf("\n=== Groups and Their Members ===\n");
    system("getent group");
}
