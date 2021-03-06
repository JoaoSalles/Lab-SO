/*
 * RSFS - Really Simple File System
 *
 * Copyright © 2010 Gustavo Maciel Dias Vieira
 * Copyright © 2010 Rodrigo Rocco Barbieri
 *
 * This file is part of RSFS.
 *
 * RSFS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>

#include "disk.h"
#include "fs.h"

#define CLUSTERSIZE 4096

unsigned short fat[65536];
  
typedef struct {
       char used;
       char name[25];
       unsigned short first_block;
       int size;
} dir_entry;

dir_entry dir[128];


int fs_init() {
  printf("Função não implementada: fs_init\n");
  return 1;
}

int fs_format() {
  int i = 0;
  char * buffer;
  for (i = 0; i < 32; i++){ //Reserva os primeiros 32 agrupamento para o FAT
    fat[i] = 3; //O valor que simpoliza fat
  }
  fat[32] = 4; //Valor representando a reserva para o diretorio de arquivo

  for(i = 33; i < 65536; i++){
    fat[i] = 1; //Seta todo o valor restante da FAT para livre
  }

  for(i = 0; i < 128; i++){
    dir[i].used = 0; //Seta todos os arquivos como nao usados
  }
  buffer = (char *) fat;
  for((i = 0; i < 256; i++){ // Escreve nos primeiros 32 agrupamento o FAT- 32 * 8 = 256
    if(!bl_write(i, &buffer[i * 512])) // cada setor tem o tamanho de 512
      return 0;
  }

  buffer = (char *) dir;
  for(i = 0; i < 8; i++){ // Escreve no agrupamento 32 o diretorio
    if(!bl_write(i+256, &aux[i*512])) //O começo do 32 começa logo apos o FAT, entao o setor começa no 256
      return 0;
  }

  return 1;
}

int fs_free() {
  printf("Função não implementada: fs_free\n");
  return 0;
}

int fs_list(char *buffer, int size) {
  printf("Função não implementada: fs_list\n");
  return 0;
}

int fs_create(char* file_name) {
  printf("Função não implementada: fs_create\n");
  return 0;
}

int fs_remove(char *file_name) {
  printf("Função não implementada: fs_remove\n");
  return 0;
}

int fs_open(char *file_name, int mode) {
  printf("Função não implementada: fs_open\n");
  return -1;
}

int fs_close(int file)  {
  printf("Função não implementada: fs_close\n");
  return 0;
}

int fs_write(char *buffer, int size, int file) {
  printf("Função não implementada: fs_write\n");
  return -1;
}

int fs_read(char *buffer, int size, int file) {
  printf("Função não implementada: fs_read\n");
  return -1;
}

