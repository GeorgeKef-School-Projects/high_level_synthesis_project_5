#include <iostream>
#include <cstdlib>
#include <ctime>

#include "mc_scverify.h"

//#include "ac_int.h"
//typedef ac_int<1,false> edge;

static const int M = 6;

#pragma hls_design top
void CCS_BLOCK(graph_color)(short adj_g[M][M],short *num_of_cols,short col_of_vertex[M]){
//Set the colors of each vertex to 0; 
//for(int i = 1;i < M;i++){
//  col_of_vertex[i] = 0;
//}
//num_of_cols = 1;
//std::cout << "num_of_cols:" << num_of_cols << std::endl;
      
  short c = 1;
  short c_vertex[M];
      
  //The first loop is to check all the c
  VERT:for(int i = 0;i < M;i++){
    c_vertex[i] = 1;
    CHECK:for(int j = 0;j < M;j++){
      if((j != i) && (adj_g[i][j] == 1) && (c_vertex[i] == c_vertex[j])){
        c_vertex[i]++;  
      }

      if(c_vertex[i] > c){
        c = c_vertex[i];
        //std::cout << "num_of_cols:" << num_of_cols << std::endl;
      }
    }
    col_of_vertex[i] = c_vertex[i];
  }     
  *num_of_cols = c;
}


CCS_MAIN(int argc,char* argv[]) {

//  graph_color G;

  short adj_g[M][M];
  short c; 
  short c_vertex[M];

  std::srand(std::time(NULL));

  for(int i = 0;i < M;i++){
    for(int j = i;j < M;j++){
      if(i == j){
        adj_g[i][j] = 0;
      }else{
	adj_g[i][j] = rand() % 2;
        adj_g[j][i] = adj_g[i][j];
      }
      std::cout << "The number in pos(i,j):" << i << "," << j << " is:" << adj_g[i][j] << std::endl; 
      std::cout << "The number in pos(j,i):" << j << "," << i << " is:" << adj_g[j][i] << std::endl; 
    }
  }

  //Call the function graph_color
  //G.run(adj_g,c,c_vertex);
  graph_color(adj_g,&c,c_vertex);  

  //Print results
  std::cout << "The number of colors that we need:" << c << std::endl;

  for(int i = 0;i < M;i++){
    std::cout << "The color of vertex:" << i << ", is:" << c_vertex[i] << std::endl;
  }

  CCS_RETURN(0);

}
