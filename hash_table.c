#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// #define TEST

static unsigned int hash_fun(char *s)
{
    unsigned int rtn = 0;
    for(int i=0; i < strlen(s); i++)
    {
        rtn += s[i];
    }
    return rtn; 
}

/**
 * 새로운 해쉬 테이블을 만들고 주소를 반환한다.
 * 실패시 NULL반환
 */
hash_table *hash_table_alloc(void)
{
    hash_table *new_hash = malloc(sizeof(hash_table));
    new_hash -> capacity = 1024;
    new_hash -> body = malloc(sizeof(element) * new_hash -> capacity);

    for (int i = 0; i < 1024; i++) {
        new_hash->body[i].key = NULL;
        new_hash->body[i].val = NULL;
    }
    return new_hash;
}

/**
 * 해쉬 테이블 동적메모리 해제
 */
void hash_table_free(hash_table *this)
{
    free(this -> body -> key);
    free(this -> body -> val);
    free(this -> body);
    free(this);
}

/**
 * 해쉬 테이블에 key: value 삽입
 */
bool hash_table_insert(hash_table *this, char *key, char *val)
{
    int h_key = hash_fun(key) % 1024;
    // printf("%s hashed to integer: %d", key, h_key);
    while(this -> body[h_key].key != NULL)
    {
        h_key++;
    }
    this -> body[h_key].key = strdup(key);
    this -> body[h_key].val = strdup(val);
    return true;
}

/**
 * 해쉬 테이블에서 키를 검색해서 value의 주소를 리턴한다.
 * 찾지 못했을 경우는 NULL 리턴
 */
char *hash_table_get(hash_table *this, char *key)
{
    int h_key = hash_fun(key) % 1024;
    if(this -> body[h_key].key == NULL)
        return NULL;
    while(strcmp(this -> body[h_key].key,key) != 0)
    {
        h_key++;
    }

    return this -> body[h_key].val;
}

/**
 * 해쉬 테이블에서 키를 검색해서 해당 원소 삭제.
 * 실패시 (찾지 못할경우) false리턴
 */
bool hash_table_remove(hash_table *this, char *key)
{
    int h_key = hash_fun(key) % 1024;
    while(strcmp(this -> body[h_key].key,key) != 0)
    {
        h_key++;
    }
    this -> body[h_key].key = NULL;
    this -> body[h_key].val = NULL;
}

#ifdef TEST
#include <stdio.h>

int main() {
    hash_table *t_hash = hash_table_alloc();
    // hash_table_insert(t_hash, "박진우","방배동");
    char *res = hash_table_get(t_hash, "박진우");

    puts(res);

    // printf("%s / %s\n", t_hash->body[hash_fun("박진우")%1024].key, t_hash->body[hash_fun("박진우")%1024].val);
}

#endif /* TEST */