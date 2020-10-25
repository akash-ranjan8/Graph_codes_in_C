#include<stdio.h>
int main()
{ int n,m;
  printf("enter the no. of vertex\n");
  scanf("%d",&n);
  printf("enter the no. of edges\n");
  scanf("%d",&m);
  int adj[n+1][n+1];
  int a[m][2];
  printf("enter the pairs\n");
  int i,j;
  for(i=0;i<m;++i)
  { for(j=0;j<2;++j)
    { scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<n+1;++i)
  { for(j=0;j<n+1;++j)
    { adj[i][j]=0;
    }
  }
  for(i=0;i<m;++i)
  { int x=a[i][0];
    int y=a[i][1];
    adj[x][y]=1;
    adj[y][x]=1;
  }
  printf("adjacency matrix as follows\n");
  for(i=0;i<n+1;++i)
  { for(j=0;j<n+1;++j)
    { printf("%d\t",adj[i][j]);
    }
    printf("\n");
  }
  return 0;
}
