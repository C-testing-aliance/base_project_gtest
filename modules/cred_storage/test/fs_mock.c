/**
 * @file
 * @brief Implementation of the filesystem API
 * @ingroup fs
 * @details
 * @{
 */

/* Include -------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs.h"

/* Configuration -------------------------------------------------------------*/
/* Macro ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Constant ------------------------------------------------------------------*/
/* Variable ------------------------------------------------------------------*/
static char *g_data = NULL;
/* Function Declaration ------------------------------------------------------*/

fs_ret_values fs_write_string(const char *path, const char *data)
{
  if(g_data)
  {
    free(g_data);
  }
  g_data = malloc(strlen(data) + 1);
  strcpy(g_data, data);
  return FS_RET_OK;
}

int fs_read(const char* path, char* data, unsigned short data_size)
{
  if(g_data)
  {
    strcpy(data, g_data);
    return strlen(data);
  }
  else
  {
    return EOF;
  }
}

/** @} */
