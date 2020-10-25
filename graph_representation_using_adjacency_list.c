#include<stdio.h>
#include<stdlib.h>
//a structure to represent an adjacency list node
struct adjacency_list_node
{ int destination;
  struct adjacency_list_node *next;
};
//a structure to represent adjacency list
struct adjacency_list
{ struct adjacency_list_node *head;
};
//a structure to represent the graph.A graph is an array of adjacency list whose size is v(no. of vertex).
struct graph
{ int v;
  struct adjacency_list *array;
};
//a function to create a new adjacency list node
struct adjacency_list_node *new(int d)
{ struct adjacency_list_node *new_node;
  new_node=(struct adjacency_list_node*)malloc(sizeof(struct adjacency_list_node));
  new_node->destination=d;
  new_node->next=NULL;
  return new_node;
}
//a utility function that creates a graph of vertices v
struct graph *create_graph(int v)
{ struct graph *g=(struct graph*)malloc(sizeof(struct graph));
  g->v=v;
  g->array=(struct adjacency_list*)malloc(sizeof(struct adjacency_list));
  int i;
  for(i=0;i<v;++i)
  { g->array[i].head=NULL;
  }
  return g;
}
//adds an edge to undirected graph
void add_edge(struct graph *g,int s,int d)
{   //adding edge from source(s) to destination(d)
    struct adjacency_list_node* newNode = new(d); 
    newNode->next = g->array[s].head; 
    g->array[s].head = newNode; 
    //from destination to source as undirected graph
    newNode = new(s); 
    newNode->next = g->array[d].head; 
    g->array[d].head = newNode; 
}
//for printing the values of graph
void print_graph(struct graph *g)
{ int i;
  for(i=0;i<g->v;++i)
  {     struct adjacency_list_node* p = g->array[i].head; 
        printf("\n Adjacency list of vertex %d\n head ", i); 
        while (p) 
        { 
            printf("-> %d", p->destination); 
            p = p->next; 
        } 
        printf("\n"); 
   }
}
int main()
{  int V = 5; 
    struct graph* g = create_graph(V); 
    add_edge(g, 0, 1); 
    add_edge(g, 0, 4); 
    add_edge(g, 1, 2); 
    add_edge(g, 1, 3); 
    add_edge(g, 1, 4); 
    add_edge(g, 2, 3); 
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}  
  

