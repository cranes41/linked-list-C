//
//  main.c
//  List
//
//  Created by Grabensee Rudi on 20/12/2016.
//  Copyright © 2016 Grabensee Rudi. All rights reserved.
//

#include <stdio.h>
#include "list.h"

#define INDEX   0
#define DATA    7

int main(int argc, const char * argv[]) {
    List_s *list = new_list();
    list_insert(list, 2);
    list_insert(list, 4);
    list_insert(list, 26);
    list_insert(list, 8);
    list_insert(list, 3);
    list_insert(list, 4);
    list_insert(list, 7);
    list_insert(list, 9);
    
    print_list(list);

    printf("tête de list : %d\n",list_firstData(list));
    
    printf("Fin de liste : %d\n",list_lastData(list));
    
    printf("Data a l'index %d = %d\n", INDEX,list_dataOn(list, INDEX));
    
    printf("Taille de la liste : %zu\n", list_size(list));
    
    printf("Remove data a l'index 2\n");
    
    list_removeOn(list, 2);
    
    printf("Taille de la liste : %zu\n", list_size(list));
    
    print_list(list);
    
    printf("Search l'element %d : index = %d\n", DATA, list_search(list, DATA));
    
    return 0;
}
