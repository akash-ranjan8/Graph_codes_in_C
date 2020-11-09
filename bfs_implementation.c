//BFS implementation in C
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
# define max 5
struct vertex
{ char label;
  bool visited;
};
//defining queue variables
int queue[max];
int front=0;
int rear=-1;
int count=0;
//graph variables
//array of vertex
struct vertex* a[max];
//adjacency matrix
int adjmatrix[max][max];
//vertex count
int vcount=0;
//queue function
void insert(int data)
{ queue[++rear]=data;
  vcount++;
}
int remove_data()
{ vcount--;
  return queue[front++];
}
bool is_queue_empty()
{ return vcount==0;
}
//graph function
//adding vertex function
void add_vertex(char label)
{ struct vertex *v=(struct vertex*)malloc(sizeof(struct vertex));
  v->label=label;
  v->visited=false;
  a[vcount++]=v;
}
//adding edge to edge of the array
void add_edge(int s,int e)
{ adjmatrix[s][e]=1;
  adjmatrix[e][s]=1;
}
//displaying the vertex
void display(int index)
{ printf("%c ",a[index]->label);
}
//get the unvisited vertex of the graph
int get_unvisited_vertex(int index)
{ int i;
  for(i=0;i<vcount;++i)
  { if(adjmatrix[index][i]==1 && a[i]->visited==false)
    { return i;
    }
  }
  return -1;
}
//BFS function
void bfs()
{ int i;
  //mark first vertex as visited
  a[0]->visited=true;
  //display the vertex
  display(0);
  //insert vertex into queue
  insert(0);
  int unvisited;
  while(is_queue_empty())
  { //get the unvisited vertex present in front
    int temp=remove_data();
    //no adjacent vertex found
    while((unvisited=get_unvisited_vertex(temp))!=-1)
    { a[unvisited]->visited=true;
      display(unvisited);
      insert(unvisited);
    }
  }
  //reseting the flag
  for(i=0;i<vcount;++i)
  { a[i]->visited=false;
  }
}
int main()
{ int i,j;
  for(i=0;i<max;++i)
  { for(j=0;j<max;++j)
    { adjmatrix[i][j]=0;
    }
  }
  add_vertex('S');
  add_vertex('A');
  add_vertex('B');
  add_vertex('C');
  add_vertex('D');
  
  add_edge(0,1);
  add_edge(0,2);
  add_edge(0,3);
  add_edge(1,4);
  add_edge(2,4);
  add_edge(3,4);
  printf("BFS is as follows:\n");
  bfs();
  return 0;
}
