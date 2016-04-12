#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

bool is_git_dir() {
  struct stat gitdir;
  if (stat(".git", &gitdir)) {
    perror("stat()");
    return false;
  }
  return S_ISDIR(gitdir.st_mtime);
}

int main(int argc, char **argv) { return is_git_dir(); }
