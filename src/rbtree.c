#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  //새로운 트리 생성
  p -> nil = (node_t*)malloc(sizeof(node_t)); //센티넬 노드
  p -> nil -> color = RBTREE_BLACK; //NIL노드의 색은 항상 black
  p -> nil -> parent = p -> nil -> left =  p -> nil -> right = p -> nil; //대입 연산은 항상 우에서 좌 순서로
  //p의 부모노드도, 왼쪽 노드도, 오른쪽 노드도 모두 nil(NULL)
  //root 포인터 초기화
  p -> root = p -> nil; 
  // TODO: initialize struct if needed
  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  node_t *temp = t -> root; //임시값 temp를 root로 설정
  while (temp != t -> nil){ //temp가 nil까지 내려가지 않았다면
    if(temp -> key > key) { //인수 key가 temp보다 클 때
      temp = temp -> left; //temp를 왼쪽으로 한칸 내려서 비교
    } else if (temp -> key < key) { //인수 key가 temp보다 작을 때
      temp = temp -> right; //temp를 오른쪽으로 한칸 내려서 비교
    } else { //찾았으면 return temp
      return temp;
    }
    return NULL; //nil 까지 내려갔어도 못찾았으면 return NULL 
  }

  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
