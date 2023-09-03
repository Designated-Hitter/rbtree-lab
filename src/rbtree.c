#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  //새로운 트리 생성
  p -> nil = (node_t*)malloc(sizeof(node_t)); //센티넬 노드
  p -> nil -> color = RBTREE_BLACK; //NIL노드의 색은 항상 black
  p -> nil -> parent = p -> nil -> left =  p -> nil -> right = p -> nil; //대입 연산은 항상 우에서 좌 순서로
  //p의 부모노드도, 왼쪽 노드도, 오른쪽 노드도 모두 nil(NULL)
  
  p -> root = p -> nil; 
  //root 포인터도 nil로 초기화
  return p;
}

void delete_node(rbtree *t, node_t*x) {

  if (x -> left != t -> nil) { //임의의 노드 x의 왼쪽 자녀가 존재한다면
    delete_node(t, x -> left); //왼쪽 자녀 노드에 delete_node 재귀
  }

  if (x -> right != t -> nil) { //임의의 노드 x의 오른쪽 자녀가 존재한다면
    delete_node(t, x -> right); //오른쪽 자녀 노드에 delete_node 재귀
  }

  free(x); // x가 동적으로 점유하던 메모리 반환 (후위순회 방식 왼쪽 -> 오른쪽 -> 루트)
  x = NULL;
}

void delete_rbtree(rbtree *t) { 

  if (t -> root != t -> nil) { //root노드에 대해서 delete_node 실행
    delete_node(t, t->root);
  }

  free(t -> nil); //nil에 동적으로 할당하던 메모리 반환
  free(t); //rbtree 자체도 반환
}

void right_rotation(rbtree *t, node_t *x) {
  node_t *y;
  //1. target의 left로 y를 선언
  y = x -> left;
  //2. y의 오른쪽 서브트리를 target의 왼쪽 서브트리로 옮김
  x -> left = y -> right;
  //3. y의 오른쪽 노드가 NIL이 아니라면, y의 오른쪽 노드의 부모를 target으로 변경
  if (y -> right != t -> nil) {
    y -> right -> parent = x;
  }
  //4. y의 부모 노드를 target의 부모 노드로 설정
  y -> parent = x -> parent;
  //5. target의 부모 노드가 NIL 이라면 (target이 root인 경우) t 구조체의 root를 y로 설정 (target의 자리를 y가 차지)
  if (x -> parent == t -> nil) {
    t -> root = y;
  //6. target이 target 부모 노드의 왼쪽이면, target 부모의 왼쪽을 y로 설정 (target의 자리를 y가 차지)
  } else if (x == x -> parent -> left) {
    x -> parent -> left = y;
  //7. target이 target 부모 노드의 오른쪽이면, target 부모의 오른쪽을 y로 설정 (target의 자리를 y가 차지)  
  } else {
    x -> parent -> right =y;
  }
  //8. target을 y의 오른쪽으로 설정
  y -> right = x;
  //9. target의 부모를 y로 설정
  x -> parent = y;
}

void left_rotation(rbtree *t, node_t *x) {
  node_t *y;
  y = x->right;
  x->right = y->left;
      
  if (y->left != t->nil) {
    y->left->parent = x;
  }     
      
  y->parent = x->parent;
      
  if (x->parent == t->nil) {
    t->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  } 

  y->left = x;
  x->parent = y;
}

void rbtree_insert_fixup(rbtree *t, node_t *z) {
  node_t *y;
  //삽입된 노드의 부모가 black일 경우 아무 문제 없다.
  while (z -> parent ->color ==RBTREE_RED) {
    //z의 부모가 조부모의 왼쪽 서브트리인 경우
    if (z -> parent == z -> parent -> parent -> left) {
      //y는 z의 uncle 노드
      y = z -> parent -> parent -> right;

      //case.1 삽입된 노드 z의 삼촌 y가 red 인 경우 (parent 도 red, uncle도 red)
      if (y -> color == RBTREE_RED) {
        z -> parent -> color = RBTREE_BLACK; //부모의 색을 black으로
        y -> color = RBTREE_BLACK; //uncle의 색도 black으로
        z -> parent -> parent -> color = RBTREE_RED; //조부모의 색을 red로 변경
        z = z -> parent -> parent;
      }

      //case.2 삽입된 노드 z의 삼촌 y가 black이며 z가 오른쪽 자식인 경우 (triangle 모양)
      else {
        if 
      }
    }
  }
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  node_t *temp = t -> root; //임시값 temp를 root로 설정

  while (temp != t -> nil) { //temp가 nil까지 내려가지 않았다면
    
    if(temp -> key > key) { //인수 key가 temp보다 클 때
      temp = temp -> left; //temp를 왼쪽으로 한칸 내려서 비교
    } else if (temp -> key < key) { //인수 key가 temp보다 작을 때
      temp = temp -> right; //temp를 오른쪽으로 한칸 내려서 비교
    } else { //찾았으면 return temp
      return temp;
    }

    return NULL; //nil 까지 내려갔어도 못찾았으면 return NULL 
  }
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
