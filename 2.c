#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void int64_t_print( int64_t a) { printf("%ld", a); }                
void char_print(char a) { printf("%c" , a); }                       
void double_print(double a) { printf("%lf", a); }                   

#define DEFINE_LIST(type)   \
    struct list_##type {\
    type value;\
    struct list_##type* next;\
    };\
\
    struct list_##type* type##_create(type value){\
        struct list_##type *instance = (struct list_##type*) malloc(sizeof(struct list_##type));\
        if (instance == NULL) return NULL;\
        instance -> value = value;\
        instance -> next = NULL;\
        return instance;\
    }\
\
    void list_##type##_print(struct list_##type* list){\
        struct list_##type* next = list;\
        while (next){\
            type##_print(next -> value);\
            printf(" ");\
            next = next -> next;\
        }\
        printf("\n");\
    }\
\
    void list_##type##_push(struct list_##type* list, type x){\
        struct list_##type* next = type##_create(x);\
        struct list_##type* previous = list;\
        while(previous -> next != NULL){\
            previous = previous -> next;\
        }\
        previous -> next = next;\
    }\
\
    void list_##type##_free(struct list_##type* list){\
        struct list_##type* l = NULL;\
        while(list){\
            l = list;\
            list = list -> next;\
            free(l);\
        }\
    }\

DEFINE_LIST(int64_t)
DEFINE_LIST(char)
DEFINE_LIST(double)

int main(){
    struct list_char *lc = char_create('k');
    list_char_push(lc, 'i');
    list_char_push(lc, 's');
    list_char_push(lc, 'k');
    list_char_push(lc, 'a');
    list_char_print(lc);
    list_char_free(lc);
    
    struct list_int64_t *li = int64_t_create(1);
    list_int64_t_push(li, 3);
    list_int64_t_push(li, 3);
    list_int64_t_push(li, 7);
    list_int64_t_print(li);
    list_int64_t_free(li);
    
    struct list_double *ldouble = double_create(25.723927602375262);
    list_double_push(ldouble, -100.27477806047789);
    list_double_print(ldouble);
    list_double_free(ldouble);
    return 0;
}       
