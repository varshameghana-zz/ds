#include<stdio.h>
#include<stdlib.h>


//usually use recursions and divide and conquer.

//insert function

//representing the bintree in the form of a self referential structure.

struct node{
  
        int data;
        struct node *left;
        struct node *right;
};


void insert(struct node** node,int key){

 // insert function takes in 2 parameters, one is pointer to root(is a double pointer,since root itself is a pointer ) and key element to be inserted.

   if(*node == NULL){

        //inserting at root  
        (*node)=(struct node*)malloc(sizeof(struct node));
        (*node)->data =key;
        (*node)->left=NULL;
        (*node)->right=NULL;
        printf("node data is %d\n",(*node)->data);

   }

    else if((*node)->data > key)

           insert((&(*node)->left),key);
    else

           insert((&(*node)->right),key);
  }

int size(struct node* node){
    
    // total size/no. of nodes (size(leftsubtree) + 1 + size(rightsubtree)
    if(node!=NULL){

              return(size(node->left) +1 + size(node->right));
     }

     else
           return 0;
}    

//function to find maximum height of binary tree
//(1 + max(( maxdepth of leftsubtree),(maxdepthof rightsubtree))

int maxheight(struct node *node){

          if(node == NULL)
               return 0;
           
          else{

             int lh = maxheight(node->left);
             int rh = maxheight(node->right);
 
             if(lh >= rh)
                 return (lh+1);
              
             else
                 return (rh+1);

          }
}

//inorder traversal

void inorder(struct node* node){
  
      if(node){ //ie... if it is not null

            inorder(node->left);
            printf("node data is %d\n",node->data);
            inorder(node->right);
       }
}

//preorder traversal

void preorder(struct node* node){
  
      if(node){ //ie... if it is not null

             printf("node data is %d\n",node->data);

            preorder(node->left);
            preorder(node->right);
           
       }
}


     
                 
//postorder traversal

void postorder(struct node* node){
  
      if(node){ //ie... if it is not null

            postorder(node->left);
            postorder(node->right);
            printf("node data is %d\n",node->data);

       }
}


//finding min element in a binary tree using recursion.. wkt min element is left most child(in recursion we uually use if construct, if it was iteration, we usually use while.

int minvalue(struct node *node){

      if(node!= NULL){ //there is atleast a root

          if(node->left != NULL){
                       
                 return(minvalue(node->left));
          }

         else
                 return node->data;
      }
}
 



//finding max ele in a binary tree using recursion.. wkt max element is rght most child(in recursion we usuallyuse if construct, if it was iteration, we usually use while.

int maxvalue(struct node *node){

      if(node!= NULL){ //there is atleast a root

          if(node->right!= NULL){
                       
                 return(maxvalue(node->right));
          }

         else
                 return node->data;
      }
}
    

//searching an element in the tree,wkt elements to left are smaller then root while those to right are greater.

int search(struct node* node,int key){

         if(node->data == key ){
                return 1;
                
         }

         else if(node->data > key){
 
                 return ( search((node->left),key));
         }
     
         else{

                return(search((node->right),key));
        }
}
 
        
        
        

               
int main(){

   struct node* root = NULL;

   insert(&root,10);
   insert(&root,20);
   insert(&root,5);
   insert(&root,2);

    int s=size(root);
    printf("size:%d\n",s);

    int h=maxheight(root);
    printf("maxheight:%d",h);

    printf("inorder:\n");
    inorder(root);
    printf("preorder:\n");
    preorder(root);
    printf("postordr\n");
    postorder(root);

   int min= minvalue(root);
  int max=maxvalue(root);
   printf("max:%d",max);
   printf("\nmin:%d\n",min);


   int se= search(root,10);

   if(se)

        printf("Element found\n");

    else
     
        printf("element not found\n");

}
    
            

       
