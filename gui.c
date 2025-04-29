#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user_manager.h"

char adminPass[50];

static void on_submit_add_user(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *username = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    const char *password = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
    addUser(username, password, adminPass);
}
static void on_add_user(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Add User");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Enter password");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
    gtk_box_append(GTK_BOX(box), entry_password);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;
    entries[1] = entry_password;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_add_user), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_submit_delete_user(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *username = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    deleteUser(username, adminPass);
}
static void on_delete_user(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Delete User");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_delete_user), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_submit_add_group(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *groupName = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    addGroup(groupName, adminPass);
}
static void on_add_group(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Add Group");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter group name");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_add_group), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_submit_delete_group(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *groupName = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    deleteGroup(groupName, adminPass);
}
static void on_delete_group(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Delete Group");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter group name");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_delete_group), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}

static void on_submit_change_user_info(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *oldUsername = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    const char *newUsername = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
    changeUserInfo(oldUsername, newUsername, adminPass);
}
static void on_change_user_info(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Change user information");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter old username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Enter new username");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
    gtk_box_append(GTK_BOX(box), entry_password);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;
    entries[1] = entry_password;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_change_user_info), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}

static void on_submit_change_account_info(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *username = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    int days = atoi(gtk_editable_get_text(GTK_EDITABLE(entries[1])));
    changeAccountInfo(username, days, adminPass);
}
static void on_change_account_info(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Change account information");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Enter days until password expiration");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
    gtk_box_append(GTK_BOX(box), entry_password);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;
    entries[1] = entry_password;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_change_user_info), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_submit_assign_user_to_group(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *username = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    const char *groupName = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
    assignUserToGroup(username, groupName, adminPass);
}
static void on_assign_user_to_group(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "assign user to group");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Enter group name");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
    gtk_box_append(GTK_BOX(box), entry_password);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;
    entries[1] = entry_password;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_change_user_info), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_submit_delete_user_from_group(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const char *username = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
    const char *groupName = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
    deleteUserFromGroup(username, groupName, adminPass);
}
static void on_delete_user_from_group(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Delete user from a group");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Enter username");
    gtk_box_append(GTK_BOX(box), entry_username);

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Enter group name");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
    gtk_box_append(GTK_BOX(box), entry_password);

    GtkWidget **entries = g_new(GtkWidget *, 2);
    entries[0] = entry_username;
    entries[1] = entry_password;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_change_user_info), entries);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(window));
}

static void on_list_users(GtkWidget *widget, gpointer data) {
    const char *command = "cut -d: -f1 /etc/passwd";
    char users[2048];
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    memset(users, 0, sizeof(users));

    size_t i = 0;
    while (fgets(users + i, sizeof(users) - i, fp) != NULL) {
        i = strlen(users);
    }

    fclose(fp);

    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Users List");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_NONE);
    gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(text_view), 5);
    gtk_text_view_set_pixels_below_lines(GTK_TEXT_VIEW(text_view), 5);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), text_view);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, users, -1);

    gtk_window_present(GTK_WINDOW(window));
}
static void on_list_groups(GtkWidget *widget, gpointer data) {
    const char *command = "getent group";
    char groups[2048];
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    memset(groups, 0, sizeof(groups));

    size_t i = 0;
    while (fgets(groups + i, sizeof(groups) - i, fp) != NULL) {
        i = strlen(groups);
    }

    fclose(fp);

    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Groups List");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0); // Expand scrolled window

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_NONE);
    gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(text_view), 5);
    gtk_text_view_set_pixels_below_lines(GTK_TEXT_VIEW(text_view), 5);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), text_view);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, groups, -1);

    gtk_window_present(GTK_WINDOW(window));
}


static void on_exit_clicked(GtkWidget *widget, gpointer data) {
    exit(0);
}

static void show_main_window(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Main Menu");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 800);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *btn;

    btn = gtk_button_new_with_label("Add user");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_add_user), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Delete user");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_delete_user), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Add group");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_add_group), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Delete group");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_delete_group), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Change user info");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_change_user_info), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Change account info");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_change_account_info), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Assign user to group");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_assign_user_to_group), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Delete user from group");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_delete_user_from_group), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("List users");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_list_users), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("List groups");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_list_groups), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    btn = gtk_button_new_with_label("Exit");
    g_signal_connect(btn, "clicked", G_CALLBACK(on_exit_clicked), NULL);
    gtk_box_append(GTK_BOX(box), btn);

    gtk_window_present(GTK_WINDOW(window));
}

static void on_submit_admin(GtkWidget *widget, gpointer data) {
    GtkWidget **entry_ptr = (GtkWidget **)data;
    const char *input = gtk_editable_get_text(GTK_EDITABLE(entry_ptr[0]));
    strncpy(adminPass, input, sizeof(adminPass) - 1);
    adminPass[sizeof(adminPass) - 1] = '\0';

    GtkApplication *app = (GtkApplication *)entry_ptr[1];
    GtkWidget *admin_window = gtk_widget_get_ancestor(GTK_WIDGET(entry_ptr[0]), GTK_TYPE_WINDOW);
    gtk_window_destroy(GTK_WINDOW(admin_window));

    show_main_window(app);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *admin_window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(admin_window), "Admin Authentication");
    gtk_window_set_default_size(GTK_WINDOW(admin_window), 300, 100);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(admin_window), box);

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Enter admin password");
    gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);
    gtk_box_append(GTK_BOX(box), entry);

    GtkWidget **data = g_new(GtkWidget *, 2);
    data[0] = entry;
    data[1] = (GtkWidget *)app;

    GtkWidget *submit = gtk_button_new_with_label("Submit");
    g_signal_connect(submit, "clicked", G_CALLBACK(on_submit_admin), data);
    gtk_box_append(GTK_BOX(box), submit);

    gtk_window_present(GTK_WINDOW(admin_window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
