#ifndef MAIN_H
#define MAIN_H

ssize_t prompt_user(char **lineptr);
void handle_command(char *buffer, char **envp, char *program_name);
void tokenize_input(char *buffer, char ***args);
void execute_command(char **args, char **envp, char *program_name);

#endif /* MAIN_H */
