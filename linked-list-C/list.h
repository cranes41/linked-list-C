//
//  list.h
//  AA DM2
//
//  Created by Grabensee Rudi on 05/12/2016.
//  Copyright © 2016 Grabensee Rudi. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stddef.h>

typedef struct element{
    void *p_data;
    struct element *p_next;
}Element_s;

typedef struct list
{
    Element_s *p_start;
    Element_s *p_curElement;
} List_s;




List_s *new_list(void);

void list_insert(List_s * p_list, void *data);

void list_removeNext(List_s *p_list);

void list_removeFirst(List_s *p_list);

void list_next(List_s *p_list);

void *list_data(List_s *p_list);

void list_first(List_s * p_list);

void list_last(List_s * p_list);

size_t list_size(List_s * p_list);

void list_delete(List_s ** p_list);

void *list_dataOn(List_s * p_list, int index);

void list_removeOn(List_s * p_list, int index);

void print_list(List_s * p_list);

void *list_lastData(List_s * p_list);

void *list_firstData(List_s * p_list);

int list_search(List_s * p_list, void *data);

#endif /* list_h */
