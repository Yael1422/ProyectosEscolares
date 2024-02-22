/*Copyright (C) 
 * 2018 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

/**
 * @file List.h
 * @brief TDU para una lista doblemente enlazada (versión reducida)
 * @author eda1 dot fiunam at yahoo dot com dot mx
 * @version 1.0
 * @date 12/09/19
 */

/*
 * A double linked list implementation to be used with Hashing
 */

#ifndef  LIST_INC
#define  LIST_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "Entry.h"

typedef struct Node
{
	Entry entry;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct 
{
	Node*  first;
	Node*  last;
	Node*  cursor;
	size_t len;
} List;


List*  List_New();
void   List_Delete(      List* this );
bool   List_InsertBack(  List* this, Entry* value );
bool   List_RemoveFront( List* this, Entry* value );
bool   List_Peek(        List* this, Entry* value );
bool   List_IsEmpty (    List* this);
void   List_Purge(       List* this );
size_t List_Len(         List* this );

bool   List_InsertFront( List* this, Entry* value );
bool   List_RemoveBack(  List* this, Entry* value );
bool   List_Find(        List* this, size_t key, float* value );

#endif   /* ----- #ifndef List_INC  ----- */
