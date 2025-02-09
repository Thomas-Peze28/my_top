/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <utmp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

#ifndef MY_
    #define MY_

    #define TASK SYS.tasks
    #define CPU SYS.cpu
    #define MEM SYS.memory

typedef struct mem_info_s {
    double total;
    double free;
    double used;
    double available;
    double swap_total;
    double swap_free;
    double swap_used;
} mem_info_t;

typedef struct cpu_info_s {
    char **cpuusage;
    float us;
    float sy;
    float ni;
    float id;
    float wa;
    float hi;
    float si;
    float st;
} cpu_info_t;

typedef struct task_info_s {
    int total;
    int running;
    int stopped;
    int sleeping;
    int zombie;
} task_info_t;

typedef struct sys_info_s {
    double loadavg1;
    double loadavg2;
    double loadavg3;
    char *hours;
    char *minutes;
    char *seconds;
    int user_count;
    task_info_t tasks;
    mem_info_t memory;
    cpu_info_t cpu;
} sys_info_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array02(char const *str, char separator);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_sort_int_array(int *tab, int size);
int check_lettre(const char *str, int i);
int check_number(const char *str, int i);
int my_getsign(char const *str);
int my_putnbr_base(int nbr, char const *base);
int fs_open_file(char const *filepath);
char *fs_return_open_file(char const *filepath);
int fs_return_file_size(char const *filepath);
char *fs_return_full_open_file(char const *filepath);
void my_getloaddavg(sys_info_t *SYS);
char **my_getmemusage(void);
void my_gettime(void);
int my_show_word_array(char *const *tab);
int count_tasks(char *path);
void my_getcpupercent(sys_info_t *SYS);
void my_get_users_number(sys_info_t *SYS);
char *buildpath_status(char *pid);
char *buildpath_stat(char *pid);
int get_uid(char *filepath);
int read_dir_tasks(char *path, sys_info_t *SYS);
int my_char_isnum(char const letter);
int read_pid(void);
int read_user(void);
int read_priority(void);
int read_virt(void);
void init_mem(sys_info_t *SYS);
int init_swap_total(sys_info_t *SYS);
int init_swap_free(sys_info_t *SYS);
int init_swap_cached(sys_info_t *SYS);
char get_tasktatus(char *filepath);
void init(sys_info_t *SYS);
void print_first_line(sys_info_t SYS);
void print_third_line(sys_info_t SYS);


#endif /* MY_ */
