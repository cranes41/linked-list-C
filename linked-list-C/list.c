//
//  list.c
//  AA DM2
//
//  Created by Grabensee Rudi on 05/12/2016.
//  Copyright © 2016 Grabensee Rudi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"




List_s *new_list(void){
    List_s *p_list = malloc(sizeof *p_list);
    
    if(p_list){
        Element_s *p_element = malloc(sizeof(Element_s));
        
        if(p_element){
            p_element->p_data = NULL;
            p_element->p_next = NULL;
            
            p_list->p_start = p_element;
            p_list->p_curElement = NULL;
        }else {
            fprintf(stderr, "Memoire insufisante\n");
            exit(EXIT_FAILURE);
        }
    }else {
        fprintf(stderr, "Memoire insufisante\n");
        exit(EXIT_FAILURE);
    }
    return p_list;
}

void list_insert(List_s * p_list, void *data){
    if(p_list){
        Element_s *p_l = p_list->p_curElement;
        Element_s *p_n = NULL;
        
        p_n = malloc(sizeof(*p_n));
        if(p_n){
            p_n->p_data = data;
            if(p_l == NULL){
                p_list->p_start->p_next = p_n;
                p_n->p_next = NULL;
            }else{
                p_n->p_next = p_l->p_next;
                p_l->p_next = p_n;
            }
            p_list->p_curElement = p_n;
        }else{
            fprintf(stderr, "Memoire insuffisante\n");
            exit(EXIT_FAILURE);
        }
    }
}

void list_removeNext(List_s *p_list)
{
    if(p_list && p_list->p_curElement){
        Element_s *p_l = p_list->p_curElement;
        Element_s *p_n = NULL;
        
        p_n = p_l->p_next;
        p_l->p_next = p_n->p_next;
        free(p_n);
        p_n = NULL;
    }
}

void list_removeFirst(List_s *p_list){
    if(p_list){
        p_list->p_curElement = p_list->p_start;
        list_removeNext(p_list);
    }
}

void list_next(List_s *p_list){
    if(p_list && p_list->p_curElement){
        p_list->p_curElement = p_list->p_curElement->p_next;
    }
}

void *list_data(List_s *p_list){
    return((p_list && p_list->p_curElement) ? p_list->p_curElement->p_data : NULL);
}

void list_first(List_s * p_list){
    if(p_list){
        p_list->p_curElement = p_list->p_start->p_next;
    }
}

void list_last(List_s * p_list){
    if(p_list){
        while(p_list->p_curElement->p_next != NULL){
            list_next(p_list);
        }
    }
}

size_t list_size(List_s * p_list){
    size_t n = 0;
    
    if(p_list){
        list_first(p_list);
        while(p_list->p_curElement != NULL){
            n++;
            list_next(p_list);
        }
    }
    return n;
}

void list_delete(List_s ** p_list){
    if(p_list && *p_list){
        list_first(*p_list);
        while((*p_list)->p_curElement->p_next != NULL)
        {
            list_removeNext(*p_list);
        }
        list_removeFirst(*p_list);
        free((*p_list)->p_curElement);
        (*p_list)->p_curElement = NULL;
        free(*p_list);
        *p_list = NULL;
    }
}

void *list_dataOn(List_s * p_list, int index){
    void *data;
    list_first(p_list);
    for (int i = 0; i<index; i++) {
        list_next(p_list);
    }
    data = list_data(p_list);
    list_first(p_list);
    return data;
}


void list_removeOn(List_s * p_list, int index){
    
    list_first(p_list);
    if (index ==0)
        list_removeNext(p_list);
    else
        for (int i = 0; i<=(index-1); i++) {
            list_next(p_list);
        }
    list_removeNext(p_list);
    list_first(p_list);
    
}

void *list_firstData(List_s * p_list){
    void *temp;
    list_first(p_list);
    temp = list_data(p_list);
    return temp;
}
void *list_lastData(List_s * p_list){
    void *temp;
    list_last(p_list);
    temp = list_data(p_list);
    return temp;
}

int list_search(List_s * p_list, void *data){
    int index = 0;
    int found = 0;
    void *temp_data;
    list_first(p_list);
    while(p_list->p_curElement != NULL && !found){
        temp_data = list_data(p_list);
        if (temp_data == data) {
            found = 1;
            return index;
        }else{
            index++;
            list_next(p_list);
        }
    }
    return -1;
}


void print_list(List_s * p_list){
    int i;
    int size = (int) list_size(p_list);
    void *data;
    list_first(p_list);
    printf("[");
    for (i = 0; i < size; i++){
        if (list_data(p_list) != NULL){
            data = list_data(p_list);
            if (i == (size-1)) {
                printf("%d",data);
            }else{
                printf("%d, ",data);
            }
            
        }
        list_next(p_list);
    }
     printf("]");
    printf ("\n");
}
