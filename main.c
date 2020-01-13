#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("."); // Open current dir
    if (!dir) {
        perror("diropen");
        return 1;
    };

    while ((entry = readdir(dir)) != NULL) {
#ifdef __APPLE__ 
        printf("%d - %s [%d] %d\n",
            entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
#else
        printf("%d - %s %d\n",
            entry->d_ino, entry->d_name, entry->d_reclen);
#endif            
    };

    closedir(dir);
};