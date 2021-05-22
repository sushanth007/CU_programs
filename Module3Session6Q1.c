//PLEASE DONOT MODIFY FROM LINE 2 TO LINE 67
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Header files ENTRY_H and ARRAYDICT_H 
#ifndef ENTRY_H
#define ENTRY_H

#define NAMESIZE  51
#define DIMENSIONS 3

// Dictionary entry
typedef struct Entry {
  char   key[NAMESIZE];
  double value[DIMENSIONS];
} Entry_t;
#endif

#ifndef ARRAYDICT_H
#define ARRAYDICT_H


// Array implementation of dictionary
typedef struct Dict {
  // A buffer to hold entries
  Entry_t *buf;

  // The maximum size of the buffer
  int bufSize;

  // The current size of the buffer
  // should be in the range [0, bufSize)
  int size;

  // Pointer to a function to compare
  // dictionary entries
  int (*key_cmp)(const Entry_t *, const Entry_t *);
} Dict_t;

// Initial size of buffer
#define INIT_SIZE 1000

// Return an empty dictionary
// (or NULL on failure)
Dict_t *makeDict(int (*)(const Entry_t *, const Entry_t *));

// Free memory allocated to dictionary
void freeDict(Dict_t *);

// Put an entry into the dictionary
// and return the new dictionary (or
// NULL on failure). If an entry with
// this entry's key already exists,
// replace the entry with this entry.
Dict_t *put(Dict_t *, const Entry_t *);

// Find an entry with a given key in
// the dictionary (return 1 if found, 0
// otherwise). Remove the entry if
// remove is non-zero.
int get(Dict_t *, Entry_t *, int remove);

// Return the size of the dictionary
int size(const Dict_t *);

#endif



Dict_t *makeDict(int (*cmp)(const Entry_t *, const Entry_t *)) {
  if (cmp == NULL) { return NULL; }
  Dict_t *dict = (Dict_t *) malloc(sizeof(Dict_t));
  if (dict == NULL) {
    return NULL;
  }
  dict->buf = (Entry_t *) malloc(INIT_SIZE * sizeof(Entry_t));
  if (dict->buf == NULL) {
    free(dict);
    return NULL;
  }
  dict->bufSize = INIT_SIZE;
  dict->size = 0;
  dict->key_cmp = cmp;
  return dict;
}

void freeDict(Dict_t *dict) {
  if (dict != NULL) {
    free(dict->buf);
    free(dict);
  }
}

Dict_t *put(Dict_t *dict, const Entry_t *entry) {
  if (dict == NULL || entry == NULL) {
    return NULL;
  }
  int lo = 0;
  int hi = dict->size-1;
  while (lo <= hi) {
    int mid = lo + (hi-lo)/2;
    int cmp = dict->key_cmp(entry, dict->buf + mid);
    if (cmp == 0) {
      dict->buf[mid] = *entry;
      return dict;
    }
    if (cmp < 0) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  if (dict->size == dict->bufSize) {
    int newsize = 2*dict->size;
    Entry_t *temp = (Entry_t *) realloc(dict->buf, newsize*sizeof(Entry_t));
    if (temp == NULL) {
      return NULL;
    }
    dict->buf = temp;
    dict->bufSize = newsize;
  }
  int insertpos = hi + 1;
  memmove(dict->buf + insertpos + 1,
          dict->buf + insertpos,
          (dict->size - insertpos) * sizeof(Entry_t));
  dict->buf[insertpos] = *entry;
  dict->size++;
  return dict;
}

int get(Dict_t *dict, Entry_t *entry, int remove) {
  if (dict != NULL && entry != NULL) {
    int lo = 0;
    int hi = dict->size-1;
    while (lo <= hi) {
      int mid = lo + (hi-lo)/2;
      int cmp = dict->key_cmp(entry, dict->buf + mid);
      if (cmp == 0) {
        *entry = dict->buf[mid];
        if (remove) {
          memmove(dict->buf + mid, dict->buf + mid + 1, (dict->size - mid - 1) * sizeof(Entry_t));
          dict->size--;
        }
        return 1;
      }
      if (cmp < 0) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
  }
  return 0;
}

int size(const Dict_t *dict) {
  return dict == NULL ? 0 : dict->size;
}

/* 
 * Note: DO NOT MODIFY THIS FILE!
 */



// Function to compare keys
int key_cmp(const Entry_t *a, const Entry_t *b) {
  return strcmp(a->key, b->key);  // compare keys as strings
}

// The main program
int main() {
  // Make a dictionary
  Dict_t *dict = makeDict(key_cmp);

  // Check if it is non-NULL
  if (dict != NULL) {

    // Repeatedly read the input
    while (1) {
      char line[NAMESIZE];
      Entry_t e;
      int remove;

      // Read a line of data
      scanf("%s", line);

      // Examine the first character
      switch (line[0]) {
        // s = size
        case 's':
        printf("Size: %d\n", size(dict));
        break;
        
        // g = get
        case 'g':
        // Read the key to get, and whether to remove
        scanf("%s", e.key);
        scanf("%d", &remove);

        // Check if get was successful
        if (get(dict, &e, remove)) {
          // Successful, so print 3-dimensions of value
          printf("(%lf, %lf, %lf)\n", e.value[0], e.value[1], e.value[2]);
        } else {
          // Unsuccessful, so print message
          printf("No entry with key %s\n", e.key);
        }
        break;
        
        // p = put
        case 'p':
        // Read the key and value to put
        scanf("%s", e.key);
        for (int i = 0; i < DIMENSIONS; ++i) {
          scanf("%lf", &e.value[i]);
        }

        // Attempt to put entry into dict
        Dict_t *temp = put(dict, &e);

        // Check if attempt was successful
        if (temp != NULL) {
          // Successful
          printf("Added entry with key %s\n", e.key);
          dict = temp;  // update dict pointer
        } else {
          // Unsuccessful
          printf("Error\n");
        }
        break;

        // Anything else = quit
        default:
        freeDict(dict);
        return 0;
      }
    }
  }
}
