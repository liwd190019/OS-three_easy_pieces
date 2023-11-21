#include "wish.h"
#include <ctype.h>  // isspace
#include <regex.h>  // regcomp, regexec, regfree
#include <stdio.h>  // fopen, fclose, fileno, getline, feof
#include <stdlib.h> // exit
#include <sys/types.h>
#include <sys/wait.h> // waitpid
#include <string.h>

FILE *in = NULL;
char *paths[BUFF_SIZE] = {"/bin", NULL};
char *line = NULL;

void *parseInput(void *arg){
  char *args[BUFF_SIZE];
  int args_num = 0;
  FILE *output = stdout;
  struct function_args *fun_args = (struct function_args *)args;
  char *commandLine = fun_args->command;

  char *command = strsep(&commandLine, ">");
  if (command == NULL || *command == '\0'){
    printError();
    return NULL;
  }

  command = trim(command);

  if(commandLine != NULL){
    regex_t reg;
    if(regcomp(&reg, "\\S\\s+\\S", REG_CFLAGS) != 0){
      printError();
      regfree(&reg);
      return NULL;
    }
    if (regexec(&reg, commandLine, 0, NULL, 0) == 0 ||
      strstr(commandLine, ">") != NULL){
        printError();
        regfree(&reg);
        return NULL;
      }

      regfree(&reg);

      if(output = fopen(trim(commandLine), "w") == NULL){
        printError();
        return NULL;
      }
  }

  char **ap = args;
  while((*ap = strsep(&command, " \t")) != NULL){
    if (**ap != '\0'){
      *ap = trim(*ap);
      ap++;
      if (++args_num >= BUFF_SIZE)
        break;
    }

    if(args_num > 0){
      executeCommands(args, args_num, output);
    }

    return NULL;
  }
}


int main(int argc, char *argv[]) {
  
  int mode = INTERACTIVE_MODE;
  size_t linecap = 0;
  ssize_t nread;
  
  if(argc > 1){
    mode = BATCH_MODE;
    if(argc > 2 || (stdin = fopen(argv[1], "r")) == NULL){
      printError();
      exit(EXIT_FAILURE);
    }
  }

  while (1)
  {
    if(mode == INTERACTIVE_MODE){
      printf("wish> ");
    }

    if((nread = getline(&line, &linecap, stdin)) > 0){
      char *command;
      int commands_num = 0;
      struct function_args args[BUFF_SIZE];
      // remove new line character
      if(line[nread - 1] == '\n'){
        line[nread - 1] = '\0';
      }

      char *temp = line;

      while((command = strsep(&temp, "&")) != NULL){ // parallelize
        if(command[0] != '\0'){
          args[commands_num++].command = strdup(command);
          if(commands_num >= BUFF_SIZE)
            break;
        }
        for(size_t i = 0; i < commands_num; i++){
          if(pthread_create(&args[i].thread, NULL, &parseInput, &args[i]) != 0){

          }
        }
      }
    }

  }
  
  return 0;

}