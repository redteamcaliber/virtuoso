/**
   Header (API) for Very Simple Linear Hash Table (VSLHT).
 */

#ifndef __VSLHT_H__
#define __VSLHT_H__

#include <stdint.h>

/**
   Type for the VSLHT.                                                          
   The table is little more than a pair of arrays: keys and values. 
*/
typedef struct vslht {
  uint32_t size;   // num slots in table
  uint32_t occ;    // number of actual key/value pairs 
  char **key;      // array of strings that are keys
  uint64_t *val;   // array of ints that are values
  char *del;   // lazy deletion
} vslht;

/// API Functions
vslht *vslht_new (void);
void vslht_clear (vslht *h);
void vslht_free (vslht *h);
void vslht_add (vslht *h, char *k, uint64_t v);
void vslht_remove (vslht *h, char *k);
uint32_t vslht_mem(vslht *h, char *k);
uint64_t vslht_find (vslht *h, char *k);
void vslht_copy (vslht *src, vslht *dest);
char **vslht_key_set (vslht *h);
uint32_t vslht_size(vslht *h);
uint32_t vslht_occ(vslht *h);

#endif // __VSLHT_H__

