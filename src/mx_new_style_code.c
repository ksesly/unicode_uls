#include "../inc/uls.h"

// ls command implementation without flags

void mx_ls(t_list *spisok)                                  {
    
    for (t_list *i = spisok; i != NULL; i = i->next)        {
<<<<<<< HEAD
        if (i->data == NULL)
=======
        if (i->next == NULL)
>>>>>>> 306974fefce8f8989fd1762bdba8794c942ab9e3
            mx_printstr(mx_strcat(i->data, "\n"))           ;
        else 
            mx_printstr(mx_strcat(i->data, "\t"))           ;
                                                            }
    //mx_printchar('\n')                                    ;
                                                            }

void mx_no_flags(t_list *spisok)                            {             
    
    for (t_list *i = spisok; i != NULL; i = i->next)        {
<<<<<<< HEAD
        if (i->data == NULL)
=======
        if (i->next == NULL)
>>>>>>> 306974fefce8f8989fd1762bdba8794c942ab9e3
            mx_printstr(mx_strcat(i->data, "\n"))           ;
        else
            mx_printstr(mx_strcat(i->data, "  "))           ;
                                                            }
                                                            }

